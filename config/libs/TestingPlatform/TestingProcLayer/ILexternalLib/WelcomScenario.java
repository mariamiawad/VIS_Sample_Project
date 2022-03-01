package libs.TestingPlatform.TestingProcLayer.ILexternalLib;

public class WelcomScenario {

	/**************************************************************************
	 * ********************** Private variables ********************************
	 *************************************************************************/
	/** Time in ms */
	private static int WelcomeRampTime = 4000;
	
	/** Time in ms */
	private static int WelcomeUpdatePeriod = 5;
	
	private static double WelcomeTarget = 0;
	
	private static double Welcmd=0;
	
	private static int WelStatusFlag=0;
	
	/**
	 * End of Private variables
	 *************************************************************************/
	/**
	 * vidWelSetRamp: This function used to set Ramp time 
	 */
	public static void vidWelSetRamp(int RampTime){
		WelcomeRampTime = RampTime;
	}
	/**
	 * End of vidWelSetRamp Function
	 ***********************************************************************/
	/**
	 * padWelGetPWM: This function used to calculate the O/P PWM for the welcome 
	 * scenario.
	 * */
	public static double[] padWelGetPWM(int command,int WelStatus, int RampIter) {
		double RampStep;
		double DcWelcmd[] = new double[3];
		double DCRLcmds[] = new double[2];
		/** RampIter = RampIter / 5*/
		RampIter = RampIter / 5;
		/** Check if the inputs aren't changing*/
		if((command == -1) && (WelStatus == -1)){
			/**Do nothing*/
		}
		else{
			/** Map the input command from 0-255 to 0-100%*/
			WelcomeTarget = dLightCommand(command);
			/**Update WelStatusFlag*/
			WelStatusFlag = WelStatus;
		}
		/** Check if Valid value */
		/** True: update DcBLcmd value */
		if(WelcomeTarget != -1){
		/** Check if that going from inactive to active state*/
		if(WelStatusFlag == 1){
			RampStep = WelcomeTarget  / (WelcomeRampTime / WelcomeUpdatePeriod);
			Welcmd += (RampStep*RampIter);
		}
		else if ((WelStatusFlag == 0)&&(Welcmd > 0)){
			RampStep = (double)command  / (WelcomeRampTime / WelcomeUpdatePeriod);
			Welcmd -= (RampStep*RampIter);
		}
		else{
			/**Do Nothing*/
		}
		/** Check the reading lights and  Interior commands */
		DCRLcmds = ReadingLights.padWelcomecommand(Welcmd);
		DcWelcmd[0]= InteriorLighting.padWelcomecommand(Welcmd);
		/** Update the commands values in the array*/
		DcWelcmd[1]=DCRLcmds[0];
		DcWelcmd[2]=DCRLcmds[1];
		}
		/** False: Out the interior and reading light commands as it is*/
		else{
			DcWelcmd[0] = InteriorLighting.DcAMBcmd;
			DcWelcmd[1]	= ReadingLights.DcRRDLPcmd;
			DcWelcmd[2] = ReadingLights.DcLRDLPcmd;
		}
		
		return DcWelcmd;
	}
	/**
	 * End of dAMBGetPWM function
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
			TargetPWMValue = -1;
		}
		
		return TargetPWMValue;
	}
	/**
	 * End of LightCommand Function
	 ***********************************************************************/
}
