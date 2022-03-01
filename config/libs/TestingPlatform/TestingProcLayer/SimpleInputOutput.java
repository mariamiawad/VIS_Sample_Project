package libs.TestingPlatform.TestingProcLayer;

import config.ETS;
import libs.TestingPlatform.TestingProcLayer.ILexternalLib.Backlighting;
import libs.TestingPlatform.TestingProcLayer.ILexternalLib.InteriorLighting;
import libs.TestingPlatform.TestingProcLayer.ILexternalLib.OfflightOrange;
import libs.TestingPlatform.TestingProcLayer.ILexternalLib.OfflightRGB;
import libs.TestingPlatform.TestingProcLayer.ILexternalLib.ReadingLights;
import libs.TestingPlatform.TestingProcLayer.ILexternalLib.WelcomScenario;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValueWithReqID;
import libs.TestingPlatform.TestingTechLayer.StateMachineEntryValues;
import libs.TestingPlatform.TestingTechLayer.TestingTechManager;
import libs.TestingPlatform.TestingTechLayer.UDS.UDS_EntryValues;
import libs.TestingPlatform.TestingTechLayer.XCP.XCP_EntryValues;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 12:38:41 PM
 * @updated 04-OCT-2020 ahamisa
 */
public class SimpleInputOutput {

	private TestingTechManager techMGR = new TestingTechManager();
	
	public enum ExternalLib {
		WithoutExLib, 
		IL_BacklightingLib, 
		IL_InteriorLightingLib, 
		IL_OfflightOrangeLib, 
		IL_OfflightRGBLib, 
		IL_ReadingLightsLib, 
		IL_WelcomScenarioLib
	};

	/**
	 * Run Decision Table with the Steps of Test.
	 * @param DTEntryWithReqID
	 * @param CastleMapping
	 * @param executionunit
	 * @param ExternalLib
	 */
	
	public void RunDecisionTableWithReqID(DecisonTableEntryValueWithReqID[] DTEntryWithReqID, CastlePortingMap CastleMapping, ETS executionunit,
			ExternalLib Type)	
         {

			 {

		int DTindex=0;
		
		switch(Type) {
		case WithoutExLib:
			techMGR.RunDTWithReqID(DTEntryWithReqID, CastleMapping, executionunit);
			break;
		/**********************************************************************
		 * **********************Interior Team Libraries***********************
		 *********************************************************************/
			
		/************************ BackLighting library ************************/
		case IL_BacklightingLib:
			/**************************Constants*******************************/
			final int LIN_BL_COMMAND 	= 0;
			final int BL_INPUTVOLTAGE 	= 1;
			final int BL_INPUTTEMP 		= 2;
			
			final int BL_PWMOUTPUT = 0;
			/******************************************************************/
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntryWithReqID.length ; DTindex++){
				/** Update the input voltage value.*/
				Backlighting.vidBLSetVolt( DTEntryWithReqID[DTindex].fInputValue[BL_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				Backlighting.vidBLSetTemp( DTEntryWithReqID[DTindex].fInputValue[BL_INPUTTEMP] );
				/** Update the PWM output value.*/
				DTEntryWithReqID[DTindex].fOutputValue[BL_PWMOUTPUT] = Backlighting.dBLGetPWM((int)DTEntryWithReqID[DTindex].fInputValue[LIN_BL_COMMAND]);
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDTWithReqID(DTEntryWithReqID, CastleMapping, executionunit);
			break;
		/******************** End OF BackLighting library *********************/
			
		/******************** InteriorLighting library ************************/
		case IL_InteriorLightingLib:
			/**************************Constants*******************************/
			final int LIN_AMB_COMMAND 		= 0;
			final int AMB_INPUTVOLTAGE 		= 1;
			final int AMB_INPUTTEMP 		= 2;
			final int AMB_RAMPUPTIME_PUbU 	= 3;
			final int AMB_RAMPDOWNTIME_PUbU = 4;
			final int AMB_RAMPUPTIME_SOFT 	= 5;
			final int AMB_RAMPDOWNTIME_SOFT = 6;
			final int AMB_SWITCHSTATUS 		= 7;
			final int AMB_RAMPSTATUS		= 8;
			
			final int AMP_PWMOUTPUT 	= 0;
			final int AMB_RL_RIGHTPWMOUTPUT = 1;
			final int AMB_RL_LEFTPWMOUTPUT	= 2;
			/******************************************************************/
			double AMBoutput[] = new double[3];
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntryWithReqID.length ; DTindex++){
				/** Update the input voltage value.*/
				InteriorLighting.vidAMBSetVolt( DTEntryWithReqID[DTindex].fInputValue[AMB_INPUTVOLTAGE] );
				ReadingLights.vidRLSetVolt( DTEntryWithReqID[DTindex].fInputValue[AMB_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				InteriorLighting.vidAMBSetTemp( DTEntryWithReqID[DTindex].fInputValue[AMB_INPUTTEMP] );
				ReadingLights.vidRLSetTemp( DTEntryWithReqID[DTindex].fInputValue[AMB_INPUTTEMP] );
				/**Check if the switch is pressed.*/
				if(DTEntryWithReqID[DTindex].fInputValue[AMB_SWITCHSTATUS] == 1){
					/** Update the RampUpTimePubu and RampdownTimePubu values*/
					ReadingLights.vidRLSetRampPuBu(	(int)DTEntryWithReqID[DTindex].fInputValue[AMB_RAMPUPTIME_PUbU],
													(int)DTEntryWithReqID[DTindex].fInputValue[AMB_RAMPDOWNTIME_PUbU]);
				}
				else if(DTEntryWithReqID[DTindex].fInputValue[AMB_SWITCHSTATUS] == 0){
					/** Update the RampUpTimeSoft and RampdownTimeSoft values*/
					ReadingLights.vidRLSetRampSoft(	(int)DTEntryWithReqID[DTindex].fInputValue[AMB_RAMPUPTIME_SOFT],
													(int)DTEntryWithReqID[DTindex].fInputValue[AMB_RAMPDOWNTIME_SOFT]);
				}
				else{
					/** Do Nothing */
				}
				/** Check if this isn't the first raw*/
				if(DTindex != 0){
					/** Update the AMB,RL_Right, and RL_Left PWM output*/
					AMBoutput = InteriorLighting.padAMBGetPWM(	(int)DTEntryWithReqID[DTindex].fInputValue[LIN_AMB_COMMAND],
																(int)DTEntryWithReqID[DTindex-1].fInputValue[LIN_AMB_COMMAND],
																(int)DTEntryWithReqID[DTindex].fInputValue[AMB_SWITCHSTATUS],
																(int)DTEntryWithReqID[DTindex].fInputValue[AMB_RAMPSTATUS],
																(int)DTEntryWithReqID[DTindex].fInToOutDelay);
					
					DTEntryWithReqID[DTindex].fOutputValue[AMP_PWMOUTPUT] = AMBoutput[AMP_PWMOUTPUT];
					DTEntryWithReqID[DTindex].fOutputValue[AMB_RL_RIGHTPWMOUTPUT] = AMBoutput[AMB_RL_RIGHTPWMOUTPUT];
					DTEntryWithReqID[DTindex].fOutputValue[AMB_RL_LEFTPWMOUTPUT] = AMBoutput[AMB_RL_LEFTPWMOUTPUT];
					
				}
				else{
					/** Update the AMB,RL_Right, and RL_Left PWM output
					 * previous command set by 0.
					 * */
					AMBoutput = InteriorLighting.padAMBGetPWM(	(int)DTEntryWithReqID[DTindex].fInputValue[LIN_AMB_COMMAND],
																0,
																(int)DTEntryWithReqID[DTindex].fInputValue[AMB_SWITCHSTATUS],
																(int)DTEntryWithReqID[DTindex].fInputValue[AMB_RAMPSTATUS],
																(int)DTEntryWithReqID[DTindex].fInToOutDelay);
					
					DTEntryWithReqID[DTindex].fOutputValue[AMP_PWMOUTPUT] = AMBoutput[AMP_PWMOUTPUT];
					DTEntryWithReqID[DTindex].fOutputValue[AMB_RL_RIGHTPWMOUTPUT] = AMBoutput[AMB_RL_RIGHTPWMOUTPUT];
					DTEntryWithReqID[DTindex].fOutputValue[AMB_RL_LEFTPWMOUTPUT] = AMBoutput[AMB_RL_LEFTPWMOUTPUT];
				}
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDTWithReqID(DTEntryWithReqID, CastleMapping, executionunit);
			break;
		/***************** End OF InteriorLighting library ********************/
			
		/********************* OfflightOrange library *************************/
		case IL_OfflightOrangeLib:
			/**************************Constants*******************************/
			final int LIN_AUF_COMMAND 	= 0;
			final int AUF_INPUTVOLTAGE 	= 1;
			final int AUF_INPUTTEMP 	= 2;
			
			final int AUF_PWMOUTPUT = 0;
			/******************************************************************/
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntryWithReqID.length ; DTindex++){
				/** Update the input voltage value.*/
				OfflightOrange.vidOffLigOranSetVolt( DTEntryWithReqID[DTindex].fInputValue[AUF_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				OfflightOrange.vidOffLigOranSetTemp( DTEntryWithReqID[DTindex].fInputValue[AUF_INPUTTEMP] );
				/** Update the PWM output value.*/
				DTEntryWithReqID[DTindex].fOutputValue[AUF_PWMOUTPUT] = OfflightOrange.dOffLighOranGetPWM((int)DTEntryWithReqID[DTindex].fInputValue[LIN_AUF_COMMAND]);
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDTWithReqID(DTEntryWithReqID, CastleMapping, executionunit);
			break;
		/********************* End Of OfflightOrange library*******************/
			
		/************************ OfflightRGB library *************************/
		case IL_OfflightRGBLib:
			/**************************Constants*******************************/
			final int LIN_RGBRED_COMMAND 	= 0;
			final int LIN_RGBGREEN_COMMAND 	= 1;
			final int LIN_RGBBLUE_COMMAND 	= 2;
			final int RGB_INPUTVOLTAGE 		= 3;
			final int RGB_INPUTTEMP 		= 4;
			
			final int RGBRED_PWMOUTPUT 		= 0;
			final int RGBGREEN_PWMOUTPUT 	= 1;
			final int RGBBLUE_PWMOUTPUT 	= 2;
			/******************************************************************/
			double RGBoutput[] = new double[3];
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntryWithReqID.length ; DTindex++){
				/** Update the input voltage value.*/
				OfflightRGB.vidRGBSetVolt( DTEntryWithReqID[DTindex].fInputValue[RGB_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				OfflightRGB.vidRGBSetTemp( DTEntryWithReqID[DTindex].fInputValue[RGB_INPUTTEMP] );
				/** Update the PWM output value.*/
				RGBoutput = OfflightRGB.dRGBGetPWM( (int)DTEntryWithReqID[DTindex].fInputValue[LIN_RGBRED_COMMAND], 
													(int)DTEntryWithReqID[DTindex].fInputValue[LIN_RGBGREEN_COMMAND], 
													(int)DTEntryWithReqID[DTindex].fInputValue[LIN_RGBBLUE_COMMAND]);
				DTEntryWithReqID[DTindex].fOutputValue[RGBRED_PWMOUTPUT] = RGBoutput[RGBRED_PWMOUTPUT];
				DTEntryWithReqID[DTindex].fOutputValue[RGBGREEN_PWMOUTPUT] = RGBoutput[RGBGREEN_PWMOUTPUT];
				DTEntryWithReqID[DTindex].fOutputValue[RGBBLUE_PWMOUTPUT] = RGBoutput[RGBBLUE_PWMOUTPUT];
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDTWithReqID(DTEntryWithReqID, CastleMapping, executionunit);
			break;
		/********************** End Of OfflightRGB library ********************/
			
		/********************** ReadingLights library *************************/
		case IL_ReadingLightsLib:
			/**************************Constants*******************************/
			final int LIN_RL_COMMANDRight 	= 0;
			final int LIN_RL_COMMANDLEFT 	= 1;
			final int RL_INPUTVOLTAGE 		= 2;
			final int RL_INPUTTEMP 			= 3;
			final int RL_RAMPUPTIME_PUbU 	= 4;
			final int RL_RAMPDOWNTIME_PUbU 	= 5;
			final int RL_RAMPUPTIME_SOFT 	= 6;
			final int RL_RAMPDOWNTIME_SOFT 	= 7;
			final int RL_SWITCHSTATUS 		= 8;
			final int RL_RAMPSTATUS			= 9;
			
			final int RL_RIGHTPWMOUTPUT = 0;
			final int RL_LEFTPWMOUTPUT	= 1;
			/******************************************************************/
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntryWithReqID.length ; DTindex++){
				/** Update the input voltage value.*/
				ReadingLights.vidRLSetVolt( DTEntryWithReqID[DTindex].fInputValue[RL_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				ReadingLights.vidRLSetTemp( DTEntryWithReqID[DTindex].fInputValue[RL_INPUTTEMP] );
				/**Check if the switch is pressed.*/
				if(DTEntryWithReqID[DTindex].fInputValue[RL_SWITCHSTATUS] == 1){
					/** Update the RampUpTimePubu and RampdownTimePubu values*/
					ReadingLights.vidRLSetRampPuBu(	(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPUPTIME_PUbU],
													(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPDOWNTIME_PUbU]);
				}
				else if(DTEntryWithReqID[DTindex].fInputValue[RL_SWITCHSTATUS] == 0){
					/** Update the RampUpTimeSoft and RampdownTimeSoft values*/
					ReadingLights.vidRLSetRampSoft(	(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPUPTIME_SOFT],
													(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPDOWNTIME_SOFT]);
				}
				else{
					/** Do Nothing */
				}
				/** Check if this isn't the first raw*/
				if(DTindex != 0){
					/** Update the PWM output value.*/
					DTEntryWithReqID[DTindex].fOutputValue[RL_RIGHTPWMOUTPUT] = ReadingLights.dRRLGetPWM((int)DTEntryWithReqID[DTindex].fInputValue[LIN_RL_COMMANDRight],
																								(int)DTEntryWithReqID[DTindex-1].fInputValue[LIN_RL_COMMANDRight],
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInToOutDelay);
				
					DTEntryWithReqID[DTindex].fOutputValue[RL_LEFTPWMOUTPUT] = ReadingLights.dLRLGetPWM((int)DTEntryWithReqID[DTindex].fInputValue[LIN_RL_COMMANDLEFT],
																								(int)DTEntryWithReqID[DTindex-1].fInputValue[LIN_RL_COMMANDLEFT],
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInToOutDelay);
				}
				else{
					/** Update the PWM output value.
					 * previous command = 0
					 * */
					DTEntryWithReqID[DTindex].fOutputValue[RL_RIGHTPWMOUTPUT] = ReadingLights.dRRLGetPWM((int)DTEntryWithReqID[DTindex].fInputValue[LIN_RL_COMMANDRight],
																								0,
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInToOutDelay);

					DTEntryWithReqID[DTindex].fOutputValue[RL_LEFTPWMOUTPUT] = ReadingLights.dLRLGetPWM((int)DTEntryWithReqID[DTindex].fInputValue[LIN_RL_COMMANDLEFT],
																								0,
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntryWithReqID[DTindex].fInToOutDelay);
				}
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDTWithReqID(DTEntryWithReqID, CastleMapping, executionunit);
			break;
		/******************** End Of ReadingLights library ********************/
			
		/******************** WelcomScenarioL library *************************/
		case IL_WelcomScenarioLib:
			/**************************Constants*******************************/
			final int LIN_WEL_COMMAND 	= 0;
			final int WEL_INPUTVOLTAGE 	= 1;
			final int WEL_INPUTTEMP 	= 2;
			final int WEL_WELSTATUS 	= 3;
			final int WEL_RAMPTIME		= 4;
			
			final int WEL_AMP_PWMOUTPUT 	= 0;
			final int WEL_RL_RIGHTPWMOUTPUT = 1;
			final int WEL_RL_LEFTPWMOUTPUT	= 2;
			/******************************************************************/
			double Weloutput[] = new double[3];
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntryWithReqID.length ; DTindex++){
				/** Update the input voltage value.*/
				ReadingLights.vidRLSetVolt( DTEntryWithReqID[DTindex].fInputValue[WEL_INPUTVOLTAGE] );
				InteriorLighting.vidAMBSetVolt( DTEntryWithReqID[DTindex].fInputValue[WEL_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				ReadingLights.vidRLSetTemp( DTEntryWithReqID[DTindex].fInputValue[WEL_INPUTTEMP] );
				InteriorLighting.vidAMBSetTemp( DTEntryWithReqID[DTindex].fInputValue[WEL_INPUTTEMP] );
				/** Update Welcome Ramp Time*/
				WelcomScenario.vidWelSetRamp((int)DTEntryWithReqID[DTindex].fInputValue[WEL_RAMPTIME]);
				/** Update the PWM output value.*/
				Weloutput = WelcomScenario.padWelGetPWM((int)DTEntryWithReqID[DTindex].fInputValue[LIN_WEL_COMMAND],
														(int)DTEntryWithReqID[DTindex].fInputValue[WEL_WELSTATUS],
														(int)DTEntryWithReqID[DTindex].fInToOutDelay);
				
				DTEntryWithReqID[DTindex].fOutputValue[WEL_AMP_PWMOUTPUT] = Weloutput[WEL_AMP_PWMOUTPUT];
				DTEntryWithReqID[DTindex].fOutputValue[WEL_RL_RIGHTPWMOUTPUT] = Weloutput[WEL_RL_RIGHTPWMOUTPUT];
				DTEntryWithReqID[DTindex].fOutputValue[WEL_RL_LEFTPWMOUTPUT] = Weloutput[WEL_RL_LEFTPWMOUTPUT];
				
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDTWithReqID(DTEntryWithReqID, CastleMapping, executionunit);
			break;
		/****************** End Of WelcomScenarioL library ********************/
		/**
		 * End of Interior Team Libraries
		 * ********************************************************************/
		
		default:	break;
		}

	}

         }
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	public void RunDecisionTable(DecisonTableEntryValue[] DTEntry, CastlePortingMap CastleMapping, ETS executionunit,
			ExternalLib Type)
	
			
			 {

		int DTindex=0;
		
		switch(Type) {
		case WithoutExLib:
			techMGR.RunDT(DTEntry, CastleMapping, executionunit);
			break;
		/**********************************************************************
		 * **********************Interior Team Libraries***********************
		 *********************************************************************/
			
		/************************ BackLighting library ************************/
		case IL_BacklightingLib:
			/**************************Constants*******************************/
			final int LIN_BL_COMMAND 	= 0;
			final int BL_INPUTVOLTAGE 	= 1;
			final int BL_INPUTTEMP 		= 2;
			
			final int BL_PWMOUTPUT = 0;
			/******************************************************************/
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntry.length ; DTindex++){
				/** Update the input voltage value.*/
				Backlighting.vidBLSetVolt( DTEntry[DTindex].fInputValue[BL_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				Backlighting.vidBLSetTemp( DTEntry[DTindex].fInputValue[BL_INPUTTEMP] );
				/** Update the PWM output value.*/
				DTEntry[DTindex].fOutputValue[BL_PWMOUTPUT] = Backlighting.dBLGetPWM((int)DTEntry[DTindex].fInputValue[LIN_BL_COMMAND]);
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDT(DTEntry, CastleMapping, executionunit);
			break;
		/******************** End OF BackLighting library *********************/
			
		/******************** InteriorLighting library ************************/
		case IL_InteriorLightingLib:
			/**************************Constants*******************************/
			final int LIN_AMB_COMMAND 		= 0;
			final int AMB_INPUTVOLTAGE 		= 1;
			final int AMB_INPUTTEMP 		= 2;
			final int AMB_RAMPUPTIME_PUbU 	= 3;
			final int AMB_RAMPDOWNTIME_PUbU = 4;
			final int AMB_RAMPUPTIME_SOFT 	= 5;
			final int AMB_RAMPDOWNTIME_SOFT = 6;
			final int AMB_SWITCHSTATUS 		= 7;
			final int AMB_RAMPSTATUS		= 8;
			
			final int AMP_PWMOUTPUT 	= 0;
			final int AMB_RL_RIGHTPWMOUTPUT = 1;
			final int AMB_RL_LEFTPWMOUTPUT	= 2;
			/******************************************************************/
			double AMBoutput[] = new double[3];
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntry.length ; DTindex++){
				/** Update the input voltage value.*/
				InteriorLighting.vidAMBSetVolt( DTEntry[DTindex].fInputValue[AMB_INPUTVOLTAGE] );
				ReadingLights.vidRLSetVolt( DTEntry[DTindex].fInputValue[AMB_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				InteriorLighting.vidAMBSetTemp( DTEntry[DTindex].fInputValue[AMB_INPUTTEMP] );
				ReadingLights.vidRLSetTemp( DTEntry[DTindex].fInputValue[AMB_INPUTTEMP] );
				/**Check if the switch is pressed.*/
				if(DTEntry[DTindex].fInputValue[AMB_SWITCHSTATUS] == 1){
					/** Update the RampUpTimePubu and RampdownTimePubu values*/
					ReadingLights.vidRLSetRampPuBu(	(int)DTEntry[DTindex].fInputValue[AMB_RAMPUPTIME_PUbU],
													(int)DTEntry[DTindex].fInputValue[AMB_RAMPDOWNTIME_PUbU]);
				}
				else if(DTEntry[DTindex].fInputValue[AMB_SWITCHSTATUS] == 0){
					/** Update the RampUpTimeSoft and RampdownTimeSoft values*/
					ReadingLights.vidRLSetRampSoft(	(int)DTEntry[DTindex].fInputValue[AMB_RAMPUPTIME_SOFT],
													(int)DTEntry[DTindex].fInputValue[AMB_RAMPDOWNTIME_SOFT]);
				}
				else{
					/** Do Nothing */
				}
				/** Check if this isn't the first raw*/
				if(DTindex != 0){
					/** Update the AMB,RL_Right, and RL_Left PWM output*/
					AMBoutput = InteriorLighting.padAMBGetPWM(	(int)DTEntry[DTindex].fInputValue[LIN_AMB_COMMAND],
																(int)DTEntry[DTindex-1].fInputValue[LIN_AMB_COMMAND],
																(int)DTEntry[DTindex].fInputValue[AMB_SWITCHSTATUS],
																(int)DTEntry[DTindex].fInputValue[AMB_RAMPSTATUS],
																(int)DTEntry[DTindex].fInToOutDelay);
					
					DTEntry[DTindex].fOutputValue[AMP_PWMOUTPUT] = AMBoutput[AMP_PWMOUTPUT];
					DTEntry[DTindex].fOutputValue[AMB_RL_RIGHTPWMOUTPUT] = AMBoutput[AMB_RL_RIGHTPWMOUTPUT];
					DTEntry[DTindex].fOutputValue[AMB_RL_LEFTPWMOUTPUT] = AMBoutput[AMB_RL_LEFTPWMOUTPUT];
					
				}
				else{
					/** Update the AMB,RL_Right, and RL_Left PWM output
					 * previous command set by 0.
					 * */
					AMBoutput = InteriorLighting.padAMBGetPWM(	(int)DTEntry[DTindex].fInputValue[LIN_AMB_COMMAND],
																0,
																(int)DTEntry[DTindex].fInputValue[AMB_SWITCHSTATUS],
																(int)DTEntry[DTindex].fInputValue[AMB_RAMPSTATUS],
																(int)DTEntry[DTindex].fInToOutDelay);
					
					DTEntry[DTindex].fOutputValue[AMP_PWMOUTPUT] = AMBoutput[AMP_PWMOUTPUT];
					DTEntry[DTindex].fOutputValue[AMB_RL_RIGHTPWMOUTPUT] = AMBoutput[AMB_RL_RIGHTPWMOUTPUT];
					DTEntry[DTindex].fOutputValue[AMB_RL_LEFTPWMOUTPUT] = AMBoutput[AMB_RL_LEFTPWMOUTPUT];
				}
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDT(DTEntry, CastleMapping, executionunit);
			break;
		/***************** End OF InteriorLighting library ********************/
			
		/********************* OfflightOrange library *************************/
		case IL_OfflightOrangeLib:
			/**************************Constants*******************************/
			final int LIN_AUF_COMMAND 	= 0;
			final int AUF_INPUTVOLTAGE 	= 1;
			final int AUF_INPUTTEMP 	= 2;
			
			final int AUF_PWMOUTPUT = 0;
			/******************************************************************/
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntry.length ; DTindex++){
				/** Update the input voltage value.*/
				OfflightOrange.vidOffLigOranSetVolt( DTEntry[DTindex].fInputValue[AUF_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				OfflightOrange.vidOffLigOranSetTemp( DTEntry[DTindex].fInputValue[AUF_INPUTTEMP] );
				/** Update the PWM output value.*/
				DTEntry[DTindex].fOutputValue[AUF_PWMOUTPUT] = OfflightOrange.dOffLighOranGetPWM((int)DTEntry[DTindex].fInputValue[LIN_AUF_COMMAND]);
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDT(DTEntry, CastleMapping, executionunit);
			break;
		/********************* End Of OfflightOrange library*******************/
			
		/************************ OfflightRGB library *************************/
		case IL_OfflightRGBLib:
			/**************************Constants*******************************/
			final int LIN_RGBRED_COMMAND 	= 0;
			final int LIN_RGBGREEN_COMMAND 	= 1;
			final int LIN_RGBBLUE_COMMAND 	= 2;
			final int RGB_INPUTVOLTAGE 		= 3;
			final int RGB_INPUTTEMP 		= 4;
			
			final int RGBRED_PWMOUTPUT 		= 0;
			final int RGBGREEN_PWMOUTPUT 	= 1;
			final int RGBBLUE_PWMOUTPUT 	= 2;
			/******************************************************************/
			double RGBoutput[] = new double[3];
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntry.length ; DTindex++){
				/** Update the input voltage value.*/
				OfflightRGB.vidRGBSetVolt( DTEntry[DTindex].fInputValue[RGB_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				OfflightRGB.vidRGBSetTemp( DTEntry[DTindex].fInputValue[RGB_INPUTTEMP] );
				/** Update the PWM output value.*/
				RGBoutput = OfflightRGB.dRGBGetPWM( (int)DTEntry[DTindex].fInputValue[LIN_RGBRED_COMMAND], 
													(int)DTEntry[DTindex].fInputValue[LIN_RGBGREEN_COMMAND], 
													(int)DTEntry[DTindex].fInputValue[LIN_RGBBLUE_COMMAND]);
				DTEntry[DTindex].fOutputValue[RGBRED_PWMOUTPUT] = RGBoutput[RGBRED_PWMOUTPUT];
				DTEntry[DTindex].fOutputValue[RGBGREEN_PWMOUTPUT] = RGBoutput[RGBGREEN_PWMOUTPUT];
				DTEntry[DTindex].fOutputValue[RGBBLUE_PWMOUTPUT] = RGBoutput[RGBBLUE_PWMOUTPUT];
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDT(DTEntry, CastleMapping, executionunit);
			break;
		/********************** End Of OfflightRGB library ********************/
			
		/********************** ReadingLights library *************************/
		case IL_ReadingLightsLib:
			/**************************Constants*******************************/
			final int LIN_RL_COMMANDRight 	= 0;
			final int LIN_RL_COMMANDLEFT 	= 1;
			final int RL_INPUTVOLTAGE 		= 2;
			final int RL_INPUTTEMP 			= 3;
			final int RL_RAMPUPTIME_PUbU 	= 4;
			final int RL_RAMPDOWNTIME_PUbU 	= 5;
			final int RL_RAMPUPTIME_SOFT 	= 6;
			final int RL_RAMPDOWNTIME_SOFT 	= 7;
			final int RL_SWITCHSTATUS 		= 8;
			final int RL_RAMPSTATUS			= 9;
			
			final int RL_RIGHTPWMOUTPUT = 0;
			final int RL_LEFTPWMOUTPUT	= 1;
			/******************************************************************/
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntry.length ; DTindex++){
				/** Update the input voltage value.*/
				ReadingLights.vidRLSetVolt( DTEntry[DTindex].fInputValue[RL_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				ReadingLights.vidRLSetTemp( DTEntry[DTindex].fInputValue[RL_INPUTTEMP] );
				/**Check if the switch is pressed.*/
				if(DTEntry[DTindex].fInputValue[RL_SWITCHSTATUS] == 1){
					/** Update the RampUpTimePubu and RampdownTimePubu values*/
					ReadingLights.vidRLSetRampPuBu(	(int)DTEntry[DTindex].fInputValue[RL_RAMPUPTIME_PUbU],
													(int)DTEntry[DTindex].fInputValue[RL_RAMPDOWNTIME_PUbU]);
				}
				else if(DTEntry[DTindex].fInputValue[RL_SWITCHSTATUS] == 0){
					/** Update the RampUpTimeSoft and RampdownTimeSoft values*/
					ReadingLights.vidRLSetRampSoft(	(int)DTEntry[DTindex].fInputValue[RL_RAMPUPTIME_SOFT],
													(int)DTEntry[DTindex].fInputValue[RL_RAMPDOWNTIME_SOFT]);
				}
				else{
					/** Do Nothing */
				}
				/** Check if this isn't the first raw*/
				if(DTindex != 0){
					/** Update the PWM output value.*/
					DTEntry[DTindex].fOutputValue[RL_RIGHTPWMOUTPUT] = ReadingLights.dRRLGetPWM((int)DTEntry[DTindex].fInputValue[LIN_RL_COMMANDRight],
																								(int)DTEntry[DTindex-1].fInputValue[LIN_RL_COMMANDRight],
																								(int)DTEntry[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntry[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntry[DTindex].fInToOutDelay);
				
					DTEntry[DTindex].fOutputValue[RL_LEFTPWMOUTPUT] = ReadingLights.dLRLGetPWM((int)DTEntry[DTindex].fInputValue[LIN_RL_COMMANDLEFT],
																								(int)DTEntry[DTindex-1].fInputValue[LIN_RL_COMMANDLEFT],
																								(int)DTEntry[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntry[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntry[DTindex].fInToOutDelay);
				}
				else{
					/** Update the PWM output value.
					 * previous command = 0
					 * */
					DTEntry[DTindex].fOutputValue[RL_RIGHTPWMOUTPUT] = ReadingLights.dRRLGetPWM((int)DTEntry[DTindex].fInputValue[LIN_RL_COMMANDRight],
																								0,
																								(int)DTEntry[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntry[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntry[DTindex].fInToOutDelay);

					DTEntry[DTindex].fOutputValue[RL_LEFTPWMOUTPUT] = ReadingLights.dLRLGetPWM((int)DTEntry[DTindex].fInputValue[LIN_RL_COMMANDLEFT],
																								0,
																								(int)DTEntry[DTindex].fInputValue[RL_SWITCHSTATUS],
																								(int)DTEntry[DTindex].fInputValue[RL_RAMPSTATUS],
																								(int)DTEntry[DTindex].fInToOutDelay);
				}
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDT(DTEntry, CastleMapping, executionunit);
			break;
		/******************** End Of ReadingLights library ********************/
			
		/******************** WelcomScenarioL library *************************/
		case IL_WelcomScenarioLib:
			/**************************Constants*******************************/
			final int LIN_WEL_COMMAND 	= 0;
			final int WEL_INPUTVOLTAGE 	= 1;
			final int WEL_INPUTTEMP 	= 2;
			final int WEL_WELSTATUS 	= 3;
			final int WEL_RAMPTIME		= 4;
			
			final int WEL_AMP_PWMOUTPUT 	= 0;
			final int WEL_RL_RIGHTPWMOUTPUT = 1;
			final int WEL_RL_LEFTPWMOUTPUT	= 2;
			/******************************************************************/
			double Weloutput[] = new double[3];
			/** Update the DT output by using the LIB.*/
			for(DTindex=0; DTindex < DTEntry.length ; DTindex++){
				/** Update the input voltage value.*/
				ReadingLights.vidRLSetVolt( DTEntry[DTindex].fInputValue[WEL_INPUTVOLTAGE] );
				InteriorLighting.vidAMBSetVolt( DTEntry[DTindex].fInputValue[WEL_INPUTVOLTAGE] );
				/** Update the temperature value.*/
				ReadingLights.vidRLSetTemp( DTEntry[DTindex].fInputValue[WEL_INPUTTEMP] );
				InteriorLighting.vidAMBSetTemp( DTEntry[DTindex].fInputValue[WEL_INPUTTEMP] );
				/** Update Welcome Ramp Time*/
				WelcomScenario.vidWelSetRamp((int)DTEntry[DTindex].fInputValue[WEL_RAMPTIME]);
				/** Update the PWM output value.*/
				Weloutput = WelcomScenario.padWelGetPWM((int)DTEntry[DTindex].fInputValue[LIN_WEL_COMMAND],
														(int)DTEntry[DTindex].fInputValue[WEL_WELSTATUS],
														(int)DTEntry[DTindex].fInToOutDelay);
				
				DTEntry[DTindex].fOutputValue[WEL_AMP_PWMOUTPUT] = Weloutput[WEL_AMP_PWMOUTPUT];
				DTEntry[DTindex].fOutputValue[WEL_RL_RIGHTPWMOUTPUT] = Weloutput[WEL_RL_RIGHTPWMOUTPUT];
				DTEntry[DTindex].fOutputValue[WEL_RL_LEFTPWMOUTPUT] = Weloutput[WEL_RL_LEFTPWMOUTPUT];
				
			}
			/** Call RunDT function to apply the test case.*/
			techMGR.RunDT(DTEntry, CastleMapping, executionunit);
			break;
		/****************** End Of WelcomScenarioL library ********************/
		/**
		 * End of Interior Team Libraries
		 * ********************************************************************/
		
		default:	break;
		}

	}

	/**
	 * Run State Machine Table to Move between different States.
	 * @param SMEntry
	 * @param CastleMapping
	 * @param executionunit
	 */
	public void RunStateMachineTable(StateMachineEntryValues[] SMEntry, CastlePortingMap CastleMapping, ETS executionunit) {
		/** Call RunDT function to apply the test case.*/
		techMGR.RunSM(SMEntry, CastleMapping, executionunit);
	}
	
	/**
	 * Run State Machine with Invoking Decision Table to Verify that you are on the correct State.
	 * @param SMEntry
	 * @param stateMachineCastleMapping
	 * @param DTEntry
	 * @param DTCastleMapping
	 * @param executionunit
	 */
	public void RunStateMachineTable_InvokingDecisionTable(StateMachineEntryValues SMEntry, CastlePortingMap stateMachineCastleMapping, DecisonTableEntryValue[] DTEntry, CastlePortingMap DTCastleMapping, ETS executionunit) {
		StateMachineEntryValues[] stateToRun = {};
		stateToRun[0] = SMEntry;
		
		/** Call RunSM function to apply the State Machine.*/
		techMGR.RunSM(stateToRun, stateMachineCastleMapping, executionunit);
		
		// Invoking Decision Table with each State
		techMGR.RunDT(DTEntry, DTCastleMapping, executionunit);	

	}
	
	/**
	 * Run XCP Decision Table with the Steps of Test (XCP Steps only).
	 * @param XCP_Entry
	 * @param CastleMapping
	 * @param executionunit
	 */
	public void RunXCP_Table(XCP_EntryValues[] XCP_Entry, CastlePortingMap CastleMapping, ETS executionunit) {
		/** Call RunDT function to apply the test case.*/
		techMGR.RunXCP(XCP_Entry, CastleMapping, executionunit);
	}
	
	/**
	 * Run UDS Decision Table with the Steps of Test (UDS Steps only).
	 * @param UDS_Entry
	 * @param CastleMapping
	 * @param executionunit
	 */
	public void RunUDS_Table(UDS_EntryValues[] UDS_Entry, CastlePortingMap CastleMapping, ETS executionunit) {
		/** Call RunDT function to apply the test case.*/
		techMGR.RunUDS(UDS_Entry, CastleMapping, executionunit);
	}

	public void finalize() throws Throwable {

	}

}