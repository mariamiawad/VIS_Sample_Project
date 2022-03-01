package libs.TestingPlatform.TestingProcLayer.ILexternalLib;

public class InteriorLighting {

	/**************************************************************************
	 * ********************** Private variables ********************************
	 *************************************************************************/
	private static boolean bOVDefectStatus = false;
	private static boolean bUVDefectStatus = false;

	private static boolean bSCDefectStatus = false;
	private static boolean bOCDefectStatus = false;

	private static boolean bOTDefectStatus = false;

	private static boolean bLBFaultStatus = false;

	private static double dDCderating = 100;

	private static int aiRawCommandPoints[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	private static int aiDimmedCommandPoints[] = { 0, 1, 3, 6, 9, 14, 22, 34, 50, 72, 100 };

	private static int ThermDerHighThreshold = 60;
	private static int ThermDerLowThreshold = 55;
	private static int ThermShutdownHighThreshold = 80;
	private static int ThermDerStep = 10;

	private static double TempFiltered = 25;

	private static double VltFiltered = 12;

	public static double DcAMBcmd = 0;
	
	private static double AmbRampCmd =0;
	
	private static double RawCommand=0,RawPreCommand=0,RampStep;
	
	private static int RampStatusFlag=0;
	
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
	public static void vidAMBInit() {

		bOVDefectStatus = false;
		bUVDefectStatus = false;

		bSCDefectStatus = false;
		bOCDefectStatus = false;

		bOTDefectStatus = false;

		bLBFaultStatus = false;

		dDCderating = 100;

		TempFiltered = 25;

		VltFiltered = 12;

		DcAMBcmd = 0;
	}
	/**
	 * End of Initialization Function
	 ***********************************************************************/
	/**
	 * vidAMBSetTemp: - Input: Temperature value. This function used to manually
	 * set temperature value.
	 */
	public static void vidAMBSetTemp(double temp) {
		TempFiltered = temp;
	}

	/**
	 * End of vidAMBSetTemp Function
	 ***********************************************************************/
	/**
	 * vidAMBSetVolt: - Input: Input voltage value. This function used to
	 * manually set voltage value.
	 */
	public static void vidAMBSetVolt(double volt) {
		VltFiltered = volt;
	}
	/**
	 * End of vidAMBSetVolt Function
	 ***********************************************************************/
	/**
	 * vidRLSetRampPuBu: This function used to set Ramp time in case of the switch 
	 * is pressed.
	 */
	public static void vidAMBSetRampPuBu(int RampUp,int RampDown) {
		RampUpTimePubu = RampUp;
		RampDownTimePubu = RampDown;
	}

	/**
	 * End of vidRLSetRampPuBu Function
	 ***********************************************************************/
	/**
	 * vidRLSetRamp: This function used to set Ramp time in case of the switch 
	 * is pressed.
	 */
	public static void vidAMBSetRamp(int RampUp,int RampDown) {
		RampUpTimeSoft = RampUp;
		RampDownTimeSoft = RampDown;
	}
	/**
	 * vidAMBOV_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate an over voltage defect
	 */
	public static void vidAMBOV_Defect(boolean status) {
		bOVDefectStatus = status;
	}

	/**
	 * End of vidAMBOV_Defect Function
	 ***********************************************************************/
	/**
	 * vidAMBUV_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate an under voltage defect
	 */
	public static void vidAMBUV_Defect(boolean status) {
		bUVDefectStatus = status;
	}

	/**
	 * End of vidAMBUV_Defect Function
	 ***********************************************************************/
	/**
	 * vidAMBSC_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate short circuit defect
	 */
	public static void vidAMBSC_Defect(boolean status) {
		bSCDefectStatus = status;
	}

	/**
	 * End of vidAMBSC_Defect Function
	 ***********************************************************************/
	/**
	 * vidAMBOC_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate open circuit defect
	 */
	public static void vidAMBOC_Defect(boolean status) {
		bOCDefectStatus = status;
	}

	/**
	 * End of vidAMBOC_Defect Function
	 ***********************************************************************/
	/**
	 * vidAMBOT_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate over temperature defect
	 */
	public static void vidAMBOT_Defect(boolean status) {
		bOTDefectStatus = status;
	}

	/**
	 * End of vidAMBOT_Defect Function
	 ***********************************************************************/
	/**
	 * vidAMBLB_Fault: - Input: Validate or invalidate. This function used to
	 * manually generate LIN bus fault.
	 */
	public static void vidAMBLB_Fault(boolean status) {
		bLBFaultStatus = status;
	}

	/**
	 * End of vidAMBLB_Fault Function
	 ***********************************************************************/
	/**
	 * dAMBGetPWM: This function used to calculate the O/P PWM for the Interior 
	 * light.
	 * */
	public static double[] padAMBGetPWM(int command,int PreviousCommand,int SwitchStatus,int RampStatus, int RampIter) {
		double dAlpha,PreCommand,dAMBcmd;
		double RampUpTime=0 , RampDownTime=0;
		double DCcmds[] = new double[3];
		double DCRLcmds[] = new double[2];
		/** RampIter = RampIter / 5*/
		RampIter = RampIter / 5;
		/** Check if the inputs aren't changing*/
		if((command == -1) && (SwitchStatus == -1) && (RampStatus == -1)){
			/** Do nothing*/
		}
		else{
			/** Map the input command from 0-255 to 0-100%*/
			dAMBcmd  = dLightCommand(command);
			PreCommand  = dLightCommand(PreviousCommand);
			/** Check if Valid value */
			/*** True: update DcAMBcmd value */
			if(dAMBcmd != -1){
				RawCommand = dAMBcmd;
			}
			/*** False: do nothing*/
			else{
				/** Do nothing*/
			}
			/*** True: update RawPreCommand value */
			if(PreCommand != -1){
				RawPreCommand = PreCommand;
			}
			/*** False: do nothing*/
			else{
				/** Do nothing*/
			}
			/** Update RAmp status flag*/
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
			if(RawCommand>RawPreCommand){
				RampStep = (RawCommand - RawPreCommand) / (RampUpTime / RampUpdatePeriod);
				AmbRampCmd = RawPreCommand + RampStep*RampIter;
			}
			else if(RawCommand<RawPreCommand){
				RampStep = (RawPreCommand - RawCommand) / (RampDownTime / RampUpdatePeriod);
				AmbRampCmd = RawPreCommand - RampStep*RampIter;
			}
			else{
				/** Do nothing*/
			}
		}
		else{
			/** Do nothing*/
		}
		/** Check the reading lights ramp commands*/
		DCRLcmds = ReadingLights.padInteriorLightcommand(AmbRampCmd);
		/** Apply the output to Dimming conversion function */
		DcAMBcmd  = dDimmingConversion(DcAMBcmd);
		/** Update the DC_Derating value*/
		vidThermalDerating();
		/** Get Alpha value*/
		dAlpha = dGetAlphaValue();
		/** PWM = DcGreencmd * DCderating * alpha */
		DcAMBcmd = ( (DcAMBcmd * dDCderating) / 100 ) * dAlpha;
		/** Check if the output bigger than 100% saturate it to 100%*/
		if(DcAMBcmd >= 100){
			DcAMBcmd = 100;
		}
		/** Check if any defect existing */
		if(bSCDefectStatus == true){
			DcAMBcmd=0;
		}
		if(bOCDefectStatus == true){
			DcAMBcmd=0;
		}
		if(bOVDefectStatus == true){
			DcAMBcmd=0;
		}
		if(bUVDefectStatus == true){
			DcAMBcmd=0;
		}
		if(bOTDefectStatus == true){
			DcAMBcmd=0;
		}
		if(bLBFaultStatus == true){
			DcAMBcmd=0;
		}
		/** Update the commands values in the array*/
		DCcmds[0]=DcAMBcmd;
		DCcmds[1]=DCRLcmds[0];
		DCcmds[2]=DCRLcmds[1];
		
		return DCcmds;
	}
	/**
	 * End of dAMBGetPWM function
	 * ************************************************************************/
	/**
	 * padWelcomecommand: This function used to check if the welcome command 
	 * is bigger than the interior command.
	 * */
	public static double padWelcomecommand(double command){
		double dAlpha=0;
		/** Check if command/2 is bigger*/
		if ( (command) > AmbRampCmd ){
			/** Apply the output to Dimming conversion function */
			DcAMBcmd  = dDimmingConversion( command );
			/** Update the DC_Derating value*/
			vidThermalDerating();
			/** Get Alpha value*/
			dAlpha = dGetAlphaValue();
			/** PWM = DcGreencmd * DCderating * alpha */
			DcAMBcmd = ( (DcAMBcmd * dDCderating) / 100 ) * dAlpha;
			/** Check if the output bigger than 100% saturate it to 100%*/
			if(DcAMBcmd >= 100){
				DcAMBcmd = 100;
			}
			/** Check if any defect existing */
			if(bSCDefectStatus == true){
				DcAMBcmd=0;
			}
			if(bOCDefectStatus == true){
				DcAMBcmd=0;
			}
			if(bOVDefectStatus == true){
				DcAMBcmd=0;
			}
			if(bUVDefectStatus == true){
				DcAMBcmd=0;
			}
			if(bOTDefectStatus == true){
				DcAMBcmd=0;
			}
			if(bLBFaultStatus == true){
				DcAMBcmd=0;
			}
		}
		else{
			/** Do nothing*/
		}
		
		return DcAMBcmd;
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
	private static void vidThermalDerating(){
		
		if( TempFiltered >= ThermShutdownHighThreshold ){
			dDCderating = 0;
		}
		
		if( TempFiltered > ThermDerHighThreshold && TempFiltered < ThermShutdownHighThreshold ){
			dDCderating -= ThermDerStep;
			
			if( dDCderating <= 0){
				dDCderating = 0;
			}
		}
		
		if( TempFiltered < ThermDerLowThreshold ){
			dDCderating += ThermDerStep;
			
			if( dDCderating >= 100){
				dDCderating = 100;
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
