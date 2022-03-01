package libs.TestingPlatform.TestingProcLayer.ILexternalLib;

public class Backlighting {
	
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
	
	private static int aiRawCommandPoints[]= {0,10,20,30,40,50,60,70,80,90,100};
	private static int aiDimmedCommandPoints[]= {0,1,3,6,9,14,22,34,50,72,100};
	
	private static int ThermDerHighThreshold = 60;
	private static int ThermDerLowThreshold = 55;
	private static int ThermShutdownHighThreshold = 80;
	private static int ThermDerStep = 10;
	
	private static double TempFiltered = 25;
	
	private static double VltFiltered = 12;
	
	private static double DcBLcmd = 0;

	private static double RawCommand=0;

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
	public static void vidBLInit() {

		bOVDefectStatus = false;
		bUVDefectStatus = false;

		bSCDefectStatus = false;
		bOCDefectStatus = false;

		bOTDefectStatus = false;

		bLBFaultStatus = false;
		
		dDCderating = 100;
		
		TempFiltered = 25;
		
		VltFiltered = 12;
		
		DcBLcmd = 0;
	}

	/**
	 * End of Initialization Function
	 ***********************************************************************/
	/**
	 * vidBLSetTemp: - Input: Temperature value. This function
	 * used to manually set temperature value.
	 */
	public static void vidBLSetTemp(double temp){
		if(temp != -1){
			TempFiltered = temp;
		}
		else{
			/**Do Nothing*/
		}
	}
	/**
	 * End of vidBLSetTemp Function
	 ***********************************************************************/
	/**
	 * vidBLSetVolt: - Input: Input voltage value. This function
	 * used to manually set voltage value.
	 */
	public static void vidBLSetVolt(double volt){
		if(volt != -1){
			VltFiltered = volt;
		}
		else{
			/**Do Nothing*/
		}
	}
	/**
	 * End of vidBLSetTemp Function
	 ***********************************************************************/
	/**
	 * vidBLOV_Defect: - Input: Validate or invalidate. This function
	 * used to manually generate an over voltage defect
	 */
	public static void vidBLOV_Defect(boolean status) {
		bOVDefectStatus = status;
	}

	/**
	 * End of vidBLOV_Defect Function
	 ***********************************************************************/
	/**
	 * vidBLUV_Defect: - Input: Validate or invalidate. This function
	 * used to manually generate an under voltage defect
	 */
	public static void vidBLUV_Defect(boolean status) {
		bUVDefectStatus = status;
	}

	/**
	 * End of vidBLUV_Defect Function
	 ***********************************************************************/
	/**
	 * vidBLSC_Defect: - Input: Validate or invalidate. This function
	 * used to manually generate short circuit defect
	 */
	public static void vidBLSC_Defect(boolean status) {
		bSCDefectStatus = status;
	}

	/**
	 * End of vidBLSC_Defect Function
	 ***********************************************************************/
	/**
	 * vidBLOC_Defect: - Input: Validate or invalidate. This function
	 * used to manually generate open circuit defect
	 */
	public static void vidBLOC_Defect(boolean status) {
		bOCDefectStatus = status;
	}

	/**
	 * End of vidBLOC_Defect Function
	 ***********************************************************************/
	/**
	 * vidBLOT_Defect: - Input: Validate or invalidate. This function
	 * used to manually generate over temperature defect
	 */
	public static void vidBLOT_Defect(boolean status) {
		bOTDefectStatus = status;
	}

	/**
	 * End of vidBLOT_Defect Function
	 ***********************************************************************/
	/**
	 * vidBLLB_Fault: - Input: Validate or invalidate. This function
	 * used to manually generate LIN bus fault.
	 */
	public static void vidBLLB_Fault(boolean status) {
		bLBFaultStatus = status;
	}
	/**
	 * End of vidBLLB_Fault Function
	 ***********************************************************************/
	/**
	 * dBLGetPWM: This function get the light command then return the
	 * PWM which will be applied to the orange led.
	 */
	public static double dBLGetPWM(int command){
		double dBLcmd;
		double dAlpha;
		/** Map the input command from 0-255 to 0-100%*/
		dBLcmd  = dLightCommand(command);
		/** Check if Valid value */
		/** True: update DcBLcmd value */
		if(dBLcmd != -1){
			RawCommand = dBLcmd;
		}
		/** False: do nothing*/
		else{
			/**Do Nothing*/
		}
		/** Apply the output to Dimming conversion function */
		DcBLcmd  = dDimmingConversion(RawCommand);
		/** Update the DC_Derating value*/
		vidThermalDerating();
		/** Get Alpha value*/
		dAlpha = dGetAlphaValue();
		/** PWM = DcGreencmd * DCderating * alpha */
		DcBLcmd = ( (DcBLcmd * dDCderating) / 100 ) * dAlpha;
		/** Check if the output bigger than 100% saturate it to 100%*/
		if(DcBLcmd >= 100){
			DcBLcmd = 100;
		}
		/** Check if any defect existing */
		if(bSCDefectStatus == true){
			DcBLcmd=0;
		}
		if(bOCDefectStatus == true){
			DcBLcmd=0;
		}
		if(bOVDefectStatus == true){
			DcBLcmd=0;
		}
		if(bUVDefectStatus == true){
			DcBLcmd=0;
		}
		if(bOTDefectStatus == true){
			DcBLcmd=0;
		}
		if(bLBFaultStatus == true){
			DcBLcmd=0;
		}
		
		return DcBLcmd;
	}
	/**
	 * End of dBLGetPWM Function
	 * ***********************************************************************
	 * End of public functions
	 *************************************************************************/
	
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
	 * dGetAlphaValue:	- Output: alpha range from 0 to 1
	 * */
	private static double dGetAlphaValue(){
		double alpha;
		
		alpha = 5.6175 / (VltFiltered - 5.7);
		if(alpha >= 1){
			alpha = 1;
		}
		else if(alpha <= 0){
			alpha = 0;
		}
		else{
			/** Do nothing*/
		}
		
		return alpha;
	}
	/**
	 * End of vidThermalDerating Function
	 *  * *********************************************************************
	 * End of private functions
	 * ************************************************************************/
}
