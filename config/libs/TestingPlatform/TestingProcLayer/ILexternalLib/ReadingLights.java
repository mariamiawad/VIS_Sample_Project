package libs.TestingPlatform.TestingProcLayer.ILexternalLib;

public class ReadingLights {

	/**************************************************************************
	 * ********************** Private variables ********************************
	 *************************************************************************/
	private static boolean bOVDefectStatus = false;
	private static boolean bUVDefectStatus = false;

	private static boolean bSCDefectStatus = false;
	private static boolean bOCDefectStatus = false;

	private static boolean bOTDefectStatus = false;

	private static boolean bLBFaultStatus = false;

	private static double dDCderatingR = 100;
	private static double dDCderatingL = 100;

	private static int aiRawCommandPoints[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	private static int aiDimmedCommandPoints[] = { 0, 1, 3, 6, 9, 14, 22, 34, 50, 72, 100 };

	private static int ThermDerHighThreshold = 60;
	private static int ThermDerLowThreshold = 55;
	private static int ThermShutdownHighThreshold = 80;
	private static int ThermDerStep = 10;

	private static double TempFiltered = 25;

	private static double VltFiltered = 12;

	public static double DcRRDLPcmd = 0;
	public static double DcLRDLPcmd = 0;
	
	private static double RawCommandRight=0,RawPreCommandRight=0,RampStepRight;
	private static double RawCommandLeft=0,RawPreCommandLeft=0,RampStepLeft;
	
	private static int RampStatusFlag=0;
	
	private static double RRDLPRampCmd =0;
	private static double LRDLPRampCmd =0;
	
	/** If push button is indicated as pressed Time in ms */
	private static int RampUpTimePubu = 4000;
	private static int RampDownTimePubu = 4000;
	/** If push button is indicated as not pressed Time in ms */
	private static int RampUpTimeSoft = 4000;
	private static int RampDownTimeSoft = 4000;
	
	/** Time in ms */
	private static int RampUpdatePeriod = 5;
	/**
	 * End of Private variables
	 *************************************************************************/

	/**************************************************************************
	 * ********************** Public Functions ********************************
	 *************************************************************************/
	/**
	 * Initialization: Initialize all defects as false, DCderating=100%,
	 * Temperature value by 25, Input voltage = 12, Output PWM by 0.
	 * 
	 */
	public static void vidRLInit() {

		bOVDefectStatus = false;
		bUVDefectStatus = false;

		bSCDefectStatus = false;
		bOCDefectStatus = false;

		bOTDefectStatus = false;

		bLBFaultStatus = false;

		dDCderatingR = 100;
		dDCderatingL = 100;

		TempFiltered = 25;

		VltFiltered = 12;

		DcRRDLPcmd = 0;
		DcLRDLPcmd = 0;
	}

	/**
	 * End of Initialization Function
	 ***********************************************************************/
	/**
	 * vidRLSetTemp: - Input: Temperature value. This function used to manually
	 * set temperature value.
	 */
	public static void vidRLSetTemp(double temp) {
		if(temp != -1){
			TempFiltered = temp;
		}
		else{
			/**Do Nothing*/
		}
		
	}

	/**
	 * End of vidRLSetTemp Function
	 ***********************************************************************/
	/**
	 * vidRLSetVolt: - Input: Input voltage value. This function used to
	 * manually set voltage value.
	 */
	public static void vidRLSetVolt(double volt) {
		if(volt != -1){
			VltFiltered = volt;
		}
		else{
			/**Do Nothing*/
		}
	}
	/**
	 * End of vidRLSetTemp Function
	 ***********************************************************************/
	/**
	 * vidRLSetRampPuBu: This function used to set Ramp time in case of the switch 
	 * is pressed.
	 */
	public static void vidRLSetRampPuBu(int RampUp,int RampDown) {
		if(RampUp != -1){
			RampUpTimePubu = RampUp;
		}
		else{
			/** Do Nothing*/
		}
		if(RampDown != -1){
			RampDownTimePubu = RampDown;
		}
		else{
			/** Do Nothing*/
		}
	}

	/**
	 * End of vidRLSetRampPuBu Function
	 ***********************************************************************/
	/**
	 * vidRLSetRamp: This function used to set Ramp time in case of the switch 
	 * is pressed.
	 */
	public static void vidRLSetRampSoft(int RampUp,int RampDown) {
		if(RampUp != -1){
			RampUpTimeSoft = RampUp;
		}
		else{
			/** Do Nothing*/
		}
		if(RampDown != -1){
			RampDownTimeSoft = RampDown;
		}
		else{
			/** Do Nothing*/
		}
	}

	/**
	 * End of vidRLSetRamp Function
	 ***********************************************************************/
	/**
	 * vidRLOV_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate an over voltage defect
	 */
	public static void vidRLOV_Defect(boolean status) {
		bOVDefectStatus = status;
	}

	/**
	 * End of vidRLOV_Defect Function
	 ***********************************************************************/
	/**
	 * vidRLUV_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate an under voltage defect
	 */
	public static void vidRLUV_Defect(boolean status) {
		bUVDefectStatus = status;
	}

	/**
	 * End of vidRLUV_Defect Function
	 ***********************************************************************/
	/**
	 * vidRLSC_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate short circuit defect
	 */
	public static void vidRLSC_Defect(boolean status) {
		bSCDefectStatus = status;
	}

	/**
	 * End of vidRLSC_Defect Function
	 ***********************************************************************/
	/**
	 * vidRLOC_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate open circuit defect
	 */
	public static void vidRLOC_Defect(boolean status) {
		bOCDefectStatus = status;
	}

	/**
	 * End of vidRLOC_Defect Function
	 ***********************************************************************/
	/**
	 * vidRLOT_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate over temperature defect
	 */
	public static void vidRLOT_Defect(boolean status) {
		bOTDefectStatus = status;
	}

	/**
	 * End of vidRLOT_Defect Function
	 ***********************************************************************/
	/**
	 * vidRLLB_Fault: - Input: Validate or invalidate. This function used to
	 * manually generate LIN bus fault.
	 */
	public static void vidRLLB_Fault(boolean status) {
		bLBFaultStatus = status;
	}

	/**
	 * End of vidRLLB_Fault Function
	 ***********************************************************************/
	/**
	 * dRRLGetPWM: This function used to calculate the O/P PWM for the right reading
	 * light.
	 * */
	public static double dRRLGetPWM(int command,int PreviousCommand,int SwitchStatus,int RampStatus, int RampIter) {
		double dAlpha,RawcommandPre,dRRLcmd;
		double RampUpTime=0 , RampDownTime=0;
		/** RampIter = RampIter / 5*/
		RampIter = RampIter / 5;
		/** Check if the inputs aren't changing*/
		if((command == -1) && (SwitchStatus == -1) && (RampStatus == -1)){
			/**Do nothing*/
		}
		else{
			/** Map the input command from 0-255 to 0-100%*/
			dRRLcmd  = dLightCommand(command);
			RawcommandPre  = dLightCommand(PreviousCommand);
			/** Check if Valid value */
			/*** True: update DcRRDLPcmd value */
			if(dRRLcmd != -1){
				RawCommandRight = dRRLcmd;
			}
			/*** False: do nothing*/
			else{
				/** Do nothing */
			}
			/*** True: update RawPreCommandRight value */
			if(RawcommandPre != -1){
				RawPreCommandRight = RawcommandPre;
			}
			/*** False: do nothing*/
			else{
				/** Do nothing */
			}
			/**Update the ramp status flag*/
			RampStatusFlag = RampStatus;
			/** Check switch status*/
			if(SwitchStatus == 1){
				RampUpTime = RampUpTimePubu;
				RampDownTime = RampDownTimePubu;
			}
			else{
				RampUpTime = RampUpTimeSoft;
				RampDownTime = RampDownTimeSoft;
			}
		}
		/** Check if a ramp is requested*/
		if(RampStatusFlag == 1){
			/** Check if the new command is bigger than the previous command*/
			if(RawCommandRight > RawPreCommandRight){
				RampStepRight = (RawCommandRight - RawPreCommandRight) / (RampUpTime / RampUpdatePeriod);
				RRDLPRampCmd = RawPreCommandRight + RampStepRight*RampIter;
			}
			else if(RawCommandRight < RawPreCommandRight){
				RampStepRight = (RawPreCommandRight - RawCommandRight) / (RampDownTime / RampUpdatePeriod);
				RRDLPRampCmd = RawPreCommandRight - RampStepRight*RampIter;
			}
			else{
				/** Do nothing*/
			}
		}
		else{
			/** Do nothing*/
		}
		/** Apply the output to Dimming conversion function */
		DcRRDLPcmd  = dDimmingConversion(RRDLPRampCmd);
		/** Update the DC_Derating value*/
		vidThermalDeratingRight();
		/** Get Alpha value*/
		dAlpha = dGetAlphaValue();
		/** PWM = DcGreencmd * DCderating * alpha */
		DcRRDLPcmd = ( (DcRRDLPcmd * dDCderatingR) / 100 ) * dAlpha;
		/** Check if the output bigger than 100% saturate it to 100%*/
		if(DcRRDLPcmd >= 100){
			DcRRDLPcmd = 100;
		}
		/** Check if any defect existing */
		if(bSCDefectStatus == true){
			DcRRDLPcmd=0;
		}
		if(bOCDefectStatus == true){
			DcRRDLPcmd=0;
		}
		if(bOVDefectStatus == true){
			DcRRDLPcmd=0;
		}
		if(bUVDefectStatus == true){
			DcRRDLPcmd=0;
		}
		if(bOTDefectStatus == true){
			DcRRDLPcmd=0;
		}
		if(bLBFaultStatus == true){
			DcRRDLPcmd=0;
		}
		return DcRRDLPcmd;
	}
	/**
	 * End of dRRLGetPWM function
	 * ************************************************************************/
	/**
	 * dLRLGetPWM: This function used to calculate the O/P PWM for the left reading
	 * light.
	 * */
	public static double dLRLGetPWM(int command,int PreviousCommand,int SwitchStatus,int RampStatus, int RampIter) {
		double dAlpha,RawcommandPre,dLRLcmd;
		double RampUpTime=0 , RampDownTime=0;
		/** RampIter = RampIter / 5*/
		RampIter = RampIter / 5;
		/** Check if the inputs aren't changing*/
		if((command == -1) && (SwitchStatus == -1) && (RampStatus == -1)){
			/** Do nothing */
		}
		else{
			/** Map the input command from 0-255 to 0-100%*/
			dLRLcmd  = dLightCommand(command);
			RawcommandPre  = dLightCommand(PreviousCommand);
			/** Check if Valid value */
			/*** True: update DcLRDLPcmd value */
			if(dLRLcmd != -1){
				RawCommandLeft = dLRLcmd;
			}
			/*** False: do nothing*/
			else{
				/** Do nothing */
			}
			/*** True: update RawPreCommandLeft value */
			if(RawcommandPre != -1){
				RawPreCommandLeft = RawcommandPre;
			}
			/*** False: do nothing*/
			else{
				/** Do nothing */
			}
			/**Update the ramp status flag*/
			RampStatusFlag = RampStatus;
			/** Check switch status*/
			if(SwitchStatus == 1){
				RampUpTime = RampUpTimePubu;
				RampDownTime = RampDownTimePubu;
			}
			else{
				RampUpTime = RampUpTimeSoft;
				RampDownTime = RampDownTimeSoft;
			}
		}
		/** Check if a ramp is requested*/
		if(RampStatusFlag == 1){
			/** Check if the new command is bigger than the previous command*/
			if(RawCommandLeft>RawPreCommandLeft){
				RampStepLeft = (RawCommandLeft - RawPreCommandLeft) / (RampUpTime / RampUpdatePeriod);
				LRDLPRampCmd = RawPreCommandLeft + RampStepLeft*RampIter;
			}
			else if(RawCommandLeft<RawPreCommandLeft){
				RampStepLeft = (RawPreCommandLeft - RawCommandLeft) / (RampDownTime / RampUpdatePeriod);
				LRDLPRampCmd = RawPreCommandLeft - RampStepLeft*RampIter;
			}
			else{
				/** Do nothing*/
			}
		}
		else{
			/** Do nothing*/
		}
		/** Apply the output to Dimming conversion function */
		DcLRDLPcmd  = dDimmingConversion(LRDLPRampCmd);
		/** Update the DC_Derating value*/
		vidThermalDeratingLeft();
		/** Get Alpha value*/
		dAlpha = dGetAlphaValue();
		/** PWM = DcGreencmd * DCderating * alpha */
		DcLRDLPcmd = ( (DcLRDLPcmd * dDCderatingL) / 100 ) * dAlpha;
		/** Check if the output bigger than 100% saturate it to 100%*/
		if(DcLRDLPcmd >= 100){
			DcLRDLPcmd = 100;
		}
		/** Check if any defect existing */
		if(bSCDefectStatus == true){
			DcLRDLPcmd=0;
		}
		if(bOCDefectStatus == true){
			DcLRDLPcmd=0;
		}
		if(bOVDefectStatus == true){
			DcLRDLPcmd=0;
		}
		if(bUVDefectStatus == true){
			DcLRDLPcmd=0;
		}
		if(bOTDefectStatus == true){
			DcLRDLPcmd=0;
		}
		if(bLBFaultStatus == true){
			DcLRDLPcmd=0;
		}
		return DcLRDLPcmd;
	}
	/**
	 * End of dRRLGetPWM function
	 * ************************************************************************/
	/**
	 * padInteriorLightcommand: This function used to check if the interior command/2 
	 * is bigger than the reading lights command.
	 * */
	public static double[] padInteriorLightcommand(double command){
		double DCRDLPcmd[]= {DcRRDLPcmd,DcLRDLPcmd};
		double dAlpha=0;
		/** Check if command/2 is bigger*/
		if ( (command/2) > RRDLPRampCmd ){
			/** Apply the output to Dimming conversion function */
			DcRRDLPcmd  = dDimmingConversion( command/2 );
			/** Update the DC_Derating value*/
			vidThermalDeratingRight();
			/** Get Alpha value*/
			dAlpha = dGetAlphaValue();
			/** PWM = DcGreencmd * DCderating * alpha */
			DcRRDLPcmd = ( (DcRRDLPcmd * dDCderatingR) / 100 ) * dAlpha;
			/** Check if the output bigger than 100% saturate it to 100%*/
			if(DcRRDLPcmd >= 100){
				DcRRDLPcmd = 100;
			}
			/** Check if any defect existing */
			if(bSCDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bOCDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bOVDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bUVDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bOTDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bLBFaultStatus == true){
				DcRRDLPcmd=0;
			}
			DCRDLPcmd[0] = DcRRDLPcmd;
		}
		else{
			/** Do nothing*/
		}
		
		if ( (command/2) > LRDLPRampCmd ){
			/** Apply the output to Dimming conversion function */
			DcLRDLPcmd  = dDimmingConversion( command/2 );
			/** Update the DC_Derating value*/
			vidThermalDeratingLeft();
			/** Get Alpha value*/
			dAlpha = dGetAlphaValue();
			/** PWM = DcGreencmd * DCderating * alpha */
			DcLRDLPcmd = ( (DcLRDLPcmd * dDCderatingL) / 100 ) * dAlpha;
			/** Check if the output bigger than 100% saturate it to 100%*/
			if(DcLRDLPcmd >= 100){
				DcLRDLPcmd = 100;
			}
			/** Check if any defect existing */
			if(bSCDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bOCDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bOVDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bUVDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bOTDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bLBFaultStatus == true){
				DcLRDLPcmd=0;
			}
			DCRDLPcmd[1] = DcLRDLPcmd;
		}
		else{
			/** Do nothing*/
		}
		
		return DCRDLPcmd;
	}
	/**
	 * End of dRRLGetPWM function
	 * ************************************************************************/
	/**
	 * padWelcomecommand: This function used to check if the welcome command 
	 * is bigger than the reading lights command.
	 * */
	public static double[] padWelcomecommand(double command){
		double DCRDLPcmd[]= {DcRRDLPcmd,DcLRDLPcmd};
		double dAlpha=0;
		/** Check if command/2 is bigger*/
		if ( (command) > RRDLPRampCmd ){
			/** Apply the output to Dimming conversion function */
			DcRRDLPcmd  = dDimmingConversion( command );
			/** Update the DC_Derating value*/
			vidThermalDeratingRight();
			/** Get Alpha value*/
			dAlpha = dGetAlphaValue();
			/** PWM = DcGreencmd * DCderating * alpha */
			DcRRDLPcmd = ( (DcRRDLPcmd * dDCderatingR) / 100 ) * dAlpha;
			/** Check if the output bigger than 100% saturate it to 100%*/
			if(DcRRDLPcmd >= 100){
				DcRRDLPcmd = 100;
			}
			/** Check if any defect existing */
			if(bSCDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bOCDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bOVDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bUVDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bOTDefectStatus == true){
				DcRRDLPcmd=0;
			}
			if(bLBFaultStatus == true){
				DcRRDLPcmd=0;
			}
			DCRDLPcmd[0] = DcRRDLPcmd;
		}
		else{
			/** Do nothing*/
		}
		
		if ( (command) > LRDLPRampCmd ){
			/** Apply the output to Dimming conversion function */
			DcLRDLPcmd  = dDimmingConversion( command );
			/** Update the DC_Derating value*/
			vidThermalDeratingLeft();
			/** Get Alpha value*/
			dAlpha = dGetAlphaValue();
			/** PWM = DcGreencmd * DCderating * alpha */
			DcLRDLPcmd = ( (DcLRDLPcmd * dDCderatingL) / 100 ) * dAlpha;
			/** Check if the output bigger than 100% saturate it to 100%*/
			if(DcLRDLPcmd >= 100){
				DcLRDLPcmd = 100;
			}
			/** Check if any defect existing */
			if(bSCDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bOCDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bOVDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bUVDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bOTDefectStatus == true){
				DcLRDLPcmd=0;
			}
			if(bLBFaultStatus == true){
				DcLRDLPcmd=0;
			}
			DCRDLPcmd[1] = DcLRDLPcmd;
		}
		else{
			/** Do nothing*/
		}
		
		return DCRDLPcmd;
	}
	/**
	 * End of dRRLGetPWM function
	 * ************************************************************************/
	
	/**************************************************************************
	 * ********************** Private Functions ********************************
	 *************************************************************************/
	/**
	 * dLightCommand: 
	 * if input command ( 0 - 64 )h mapped to ( 0 - 100 )%
	 * if input command ( 64 - FE )h mapped to 100%
	 * if input command FFh mapped to invalid value.
	 * */
	private static double dLightCommand(int command){
		double TargetPWMValue = 0;
		/**if input command ( 0 - 64 )h mapped to ( 0 - 100 )% */
		if(command>=0 && command<=100){
			TargetPWMValue = command;
		}
		/** if input command ( 64 - FE )h mapped to 100% */
		else if (command>100 && command<=254){
			TargetPWMValue = 100;
		}
		/** if input command FFh mapped to invalid value. */
		else if (command == 255){
			TargetPWMValue = -1;
		}
		else{
			/** Do nothing*/
		}
		
		return TargetPWMValue;
	}
	/**
	 * End of LightCommand Function
	 ***********************************************************************/
	/**
	 * dDimmingConversion: 
	 * */
	private static double dDimmingConversion(double command){
		double TargetPWMValue=0;
		
		if(command>=aiRawCommandPoints[0] && command<aiRawCommandPoints[1]){
			TargetPWMValue = dLinearInterpol(0,1,command);
		}
		else if(command>=aiRawCommandPoints[1] && command<aiRawCommandPoints[2]){
			TargetPWMValue = dLinearInterpol(1,2,command);
		}
		else if(command>=aiRawCommandPoints[2] && command<aiRawCommandPoints[3]){
			TargetPWMValue = dLinearInterpol(2,3,command);
		}
		else if(command>=aiRawCommandPoints[3] && command<aiRawCommandPoints[4]){
			TargetPWMValue = dLinearInterpol(3,4,command);
		}
		else if(command>=aiRawCommandPoints[4] && command<aiRawCommandPoints[5]){
			TargetPWMValue = dLinearInterpol(4,5,command);
		}
		else if(command>=aiRawCommandPoints[5] && command<aiRawCommandPoints[6]){
			TargetPWMValue = dLinearInterpol(5,6,command);
		}
		else if(command>=aiRawCommandPoints[6] && command<aiRawCommandPoints[7]){
			TargetPWMValue = dLinearInterpol(6,7,command);
		}
		else if(command>=aiRawCommandPoints[7] && command<aiRawCommandPoints[8]){
			TargetPWMValue = dLinearInterpol(7,8,command);
		}
		else if(command>=aiRawCommandPoints[8] && command<aiRawCommandPoints[9]){
			TargetPWMValue = dLinearInterpol(8,9,command);
		}
		else if(command>=aiRawCommandPoints[9] && command<=aiRawCommandPoints[10]){
			TargetPWMValue = dLinearInterpol(9,10,command);
		}
		else{
			// Do nothing
		}
		return TargetPWMValue;
		
	}
	/**
	 * End of dDimmingConversion Function
	 ***********************************************************************/
	/**
	 * dLinearInterpol: 
	 * */
	private static double dLinearInterpol(int index1,int index2,double command){
		double TargetPWMValue;
		
		TargetPWMValue = 
				( ( (double)(aiDimmedCommandPoints[index2]-aiDimmedCommandPoints[index1]) / 
				   (aiRawCommandPoints[index2]-aiRawCommandPoints[index1]) ) *
				 (command-aiRawCommandPoints[index1]) ) + aiDimmedCommandPoints[index1]; 
		
		return TargetPWMValue;
	}
	/**
	 * End of dLinearInterpol Function
	 **************************************************************************/
	/**
	 * vidThermalDerating:	- Output: dDCderating range from 0 to 100
	 * */
	private static void vidThermalDeratingRight(){
		
		if( TempFiltered >= ThermShutdownHighThreshold ){
			dDCderatingR = 0;
		}
		
		if( TempFiltered > ThermDerHighThreshold && TempFiltered < ThermShutdownHighThreshold ){
			dDCderatingR -= ThermDerStep;
			
			if( dDCderatingR <= 0){
				dDCderatingR = 0;
			}
		}
		
		if( TempFiltered < ThermDerLowThreshold ){
			dDCderatingR += ThermDerStep;

			if( dDCderatingR >= 100){
				dDCderatingR = 100;
			}
		}
	}
	
	private static void vidThermalDeratingLeft(){
		
		if( TempFiltered >= ThermShutdownHighThreshold ){
			dDCderatingL = 0;
		}
		
		if( TempFiltered > ThermDerHighThreshold && TempFiltered < ThermShutdownHighThreshold ){
			dDCderatingL -= ThermDerStep;
			
			if( dDCderatingL <= 0){
				dDCderatingL = 0;
			}
		}
		
		if( TempFiltered < ThermDerLowThreshold ){
			dDCderatingL += ThermDerStep;

			if( dDCderatingL >= 100){
				dDCderatingL = 100;
			}
		}
	}
	/**
	 * End of vidThermalDerating Function
	 **************************************************************************/
	/**
	 * dGetAlphaValue:	- Output: alpha 
	 * */
	private static double dGetAlphaValue(){
		double alpha;
		
		alpha = 1.0828;
		
		return alpha;
	}
	/**
	 * End of vidThermalDerating Function
	 *  * *********************************************************************/
	
	 /**
	  *  End of private functions
	  * ***********************************************************************/
}
