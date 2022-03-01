package libs.TestingPlatform.TestingProcLayer.FBDexternalLib;

import config.ETS;
import libs.TestingPlatform.TestingProcLayer.SimpleInputOutput;
import libs.TestingPlatform.TestingProcLayer.SimpleInputOutput.ExternalLib;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;
/**
 * @author mteama
 * @version 2.0
 * @created 28-Aug-2017
 */

public class NTCDefects {
	public final static double ZeroCurrent=-3;
	final  public static double RESET = -2.0;
	public  final static double NO_VAL = -1.0;
	public  final static double TBD = 0 ;
	public  final static double ON = 5;
	public  final static double OFF = 0;
	
	/** 
	 * NTCDefectIrReversible
	 * check NTC Defect (OC or SC) SW behavior
	 * in case of NTC Defect the SW will derate the corresponding function
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCDefectVoltage	(unit) mVolt (e.g. 2 mvolt = SC & 4999 mVolt = OC)
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param MinDeratingPer	(unit) % of the nominal output
	 * @param DeratingStep		(e.g. Output Current (unit) mAmp)
	 * @param TimeStep			(unit) mSec
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	
	public static void NTCDefectIrReversible (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCDefectVoltage,double NominalOutputCurrent, double MinDeratingCurrentPer, double CurrentStep, double TimeStep,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*1st set LB NTC to OC voltage (Create NTC Defect) to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	1000, 1 , new double[]{ NominalOutputCurrent	},	500),
				new DecisonTableEntryValue("set LB NTC to Defect voltage (Create NTC Defect) to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCDefectVoltage	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
		};
		
		
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( NominalOutputCurrent,MinDeratingCurrentPer*(NominalOutputCurrent),TimeStep,CurrentStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step untill complet derating";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		for(int indexx = 0; indexx < (currentArrayDeratingPositive.length) ; indexx++)
		{
			thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	1000, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
		}		
		
		/*3rd settle Down current*/
		String settleDownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown3 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingCurrentPer*(NominalOutputCurrent)	},	1000),
		};
		
		/*4th Set LB NTC to normal temperature voltage (Remove Defect) But the Current shouldn't Underate as the NTC Defect is irreversible */
		DecisonTableEntryValue[] stimulateUnDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage (Remove NTC Defect) But the Current shouldn't Underate as the NTC Defect is irreversible", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL	},	5),
		};
		
		/*5nd thermalUnDeratingNegative*/
		/*A create the array*/
		double currentArrayUnDeratingNegative[] = ThermalDerating.thermalUnDeratingNegative(MinDeratingCurrentPer*(NominalOutputCurrent), NominalOutputCurrent,TimeStep,CurrentStep);
		/*B fill the table*/
		String thermalDeratingNegativeComment="Assert on the output current for each step and the output current shouldn't Underate and stay at the same level";
		DecisonTableEntryValue[] thermalUnDeratingNegative5 = new DecisonTableEntryValue[currentArrayUnDeratingNegative.length];
		for(int indexx = 0; indexx < (currentArrayUnDeratingNegative.length) ; indexx++)
		{
			thermalUnDeratingNegative5[indexx]= new DecisonTableEntryValue(thermalDeratingNegativeComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	1000, 0 , new double[]{ currentArrayUnDeratingNegative[indexx]	},	0);			
		}	
		
		/*6th settle Down current*/
		//String settledownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingCurrentPer*(NominalOutputCurrent)	},	1000),
		};
		
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  fBDTools.joinArray(stimulateDerating1,thermalDeratingPositive2,settleDown3,stimulateUnDerating4,thermalUnDeratingNegative5,settleDown6);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput NTCDefect=new SimpleInputOutput();
		NTCDefect.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
		
	}
	/** 
	 * NTCDefectIrReversible
	 * this API is initially set the NTC to defect before powering on the ECU then check the behaviour of the SW i.e. derating and reversibility of the tests
	 *  in case of NTC Defect the SW will derate the corresponding function
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCDefectVoltage	(unit) mVolt (e.g. 2 mvolt = SC & 4999 mVolt = OC)
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param MinDeratingPer	(unit) % of the nominal output
	 * @param DeratingStep		(e.g. Output Current (unit) mAmp)
	 * @param TimeStep			(unit) mSec
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	
	public static void InitNTCDefectIrReversible (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCDefectVoltage,double NominalOutputCurrent, double MinDeratingCurrentPer, double CurrentStep, double TimeStep,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*1st set LB NTC to OC voltage (Create NTC Defect) to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set LB NTC to Defect voltage (Create NTC Defect) to force thermal derating before starting the ECU set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	1000, 1 , new double[]{ NominalOutputCurrent	},	2000),
				new DecisonTableEntryValue("Pwr on the ECU by setting the PS volatge to Nominal voltage ", 	new double[]{PSNominalVoltage, ONSignal,	NO_VAL	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
		};
		
		
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( NominalOutputCurrent,MinDeratingCurrentPer*(NominalOutputCurrent),TimeStep,CurrentStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step untill complet derating";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		for(int indexx = 0; indexx < (currentArrayDeratingPositive.length) ; indexx++)
		{
			thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	1000, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
		}		
		
		/*3rd settle Down current*/
		String settleDownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown3 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingCurrentPer*(NominalOutputCurrent)	},	1000),
		};
		
		/*4th Set LB NTC to normal temperature voltage (Remove Defect) But the Current shouldn't Underate as the NTC Defect is irreversible */
		DecisonTableEntryValue[] stimulateUnDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage (Remove NTC Defect) But the Current shouldn't Underate as the NTC Defect is irreversible", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL	},	5),
		};
		
		/*5nd thermalUnDeratingNegative*/
		/*A create the array*/
		double currentArrayUnDeratingNegative[] = ThermalDerating.thermalUnDeratingNegative(MinDeratingCurrentPer*(NominalOutputCurrent), NominalOutputCurrent,TimeStep,CurrentStep);
		/*B fill the table*/
		String thermalDeratingNegativeComment="Assert on the output current for each step and the output current shouldn't Underate and stay at the same level";
		DecisonTableEntryValue[] thermalUnDeratingNegative5 = new DecisonTableEntryValue[currentArrayUnDeratingNegative.length];
		for(int indexx = 0; indexx < (currentArrayUnDeratingNegative.length) ; indexx++)
		{
			thermalUnDeratingNegative5[indexx]= new DecisonTableEntryValue(thermalDeratingNegativeComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	1000, 0 , new double[]{ currentArrayUnDeratingNegative[indexx]	},	0);			
		}	
		
		/*6th settle Down current*/
		//String settledownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingCurrentPer*(NominalOutputCurrent)	},	1000),
		};
		
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  fBDTools.joinArray(stimulateDerating1,thermalDeratingPositive2,settleDown3,stimulateUnDerating4,thermalUnDeratingNegative5,settleDown6);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput NTCDefect=new SimpleInputOutput();
		NTCDefect.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
		
	}
	/** 
	 * NTCDefectIrReversible
	 * check NTC Defect (OC or SC) SW behavior
	 * in case of NTC Defect the SW will Shutdown the corresponding function
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCDefectVoltage	(unit) mVolt (e.g. 2 mvolt = SC & 4999 mVolt = OC)
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param Validation time	(unit) msec (the time needed to shutdown the output current after detecting the NTC defect)
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	
	public static void NTCDefectIrReversibleShutdown (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCDefectVoltage,double NominalOutputCurrent,double ValidationTime ,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*1st set LB NTC to OC voltage (Create NTC Defect) to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	1000, 1 , new double[]{ NominalOutputCurrent	},	500),
				new DecisonTableEntryValue("set LB NTC to Defect voltage (Create NTC Defect) to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCDefectVoltage	},null,	0, 0 , new double[]{ NO_VAL	},	0),	
		};
		
		/*2nd Shutdown the current*/
		String ShutDownComment="wait for a shutdown validation time then assert on the current to reach zero current";
		DecisonTableEntryValue[] ShutDown2 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(ShutDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{ZeroCurrent	},	1000),
		};
			
		
		/*3rd settle Down current*/
		String settleDownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown3 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{ZeroCurrent	},	1000),
		};
		
		/*4th Set LB NTC to normal temperature voltage (Remove Defect) But the Current shouldn't Underate as the NTC Defect is irreversible */
		DecisonTableEntryValue[] stimulateUnDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage (Remove NTC Defect) But the Current shouldn't Underate as the NTC Defect is irreversible", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL	},	5),
		};
		/*5th Make sure that the current is still zero as the defect is irreversable*/
//		String turnONComment="wait for a shutdown validation time then assert on the current to reach zero current";
//		DecisonTableEntryValue[] TurnOn2 = new DecisonTableEntryValue[]{
//			new DecisonTableEntryValue(ShutDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{ZeroCurrent	},	1000),
//		};
		
		/*6th settle Down current*/
		//String settledownComment="wait for a sufficent period of time (e.g. 5 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												50000,	10 ,		new double[]{ZeroCurrent	},	1000),
		};
		
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  fBDTools.joinArray(stimulateDerating1, ShutDown2,settleDown3,stimulateUnDerating4,settleDown6);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput NTCDefect=new SimpleInputOutput();
		NTCDefect.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
		
	}
	/** 
	 * NTCDefectIrReversible
	 * this API is initially set the NTC to defect before powering on the ECU then check the behaviour of the SW i.e. derating and reversibility of the tests
	 * in case of NTC Defect the SW will Shutdown the corresponding function
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCDefectVoltage	(unit) mVolt (e.g. 2 mvolt = SC & 4999 mVolt = OC)
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param Validation time	(unit) msec (the time needed to shutdown the output current after detecting the NTC defect)
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	
	public static void InitNTCDefectIrReversibleShutdown (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCDefectVoltage,double NominalOutputCurrent,double ValidationTime ,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*1st set LB NTC to OC voltage (Create NTC Defect) to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set LB NTC to Defect voltage (Create NTC Defect) to force thermal derating before starting the ECU set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	1000, 1 , new double[]{ NominalOutputCurrent	},	2000),
				new DecisonTableEntryValue("Pwr on the ECU by setting the PS volatge to Nominal voltage ", 	new double[]{PSNominalVoltage, ONSignal,	NO_VAL	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
		};
		
		/*2nd Shutdown the current*/
		String ShutDownComment="wait for a shutdown validation time then assert on the current to reach zero current";
		DecisonTableEntryValue[] ShutDown2 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(ShutDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{ZeroCurrent	},	1000),
		};
			
		
		/*3rd settle Down current*/
		String settleDownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown3 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{ZeroCurrent	},	1000),
		};
		
		/*4th Set LB NTC to normal temperature voltage (Remove Defect) But the Current shouldn't Underate as the NTC Defect is irreversible */
		DecisonTableEntryValue[] stimulateUnDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage (Remove NTC Defect) But the Current shouldn't Underate as the NTC Defect is irreversible", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL	},	5),
		};
		/*5th Make sure that the current is still zero as the defect is irreversable*/
//		String turnONComment="wait for a shutdown validation time then assert on the current to reach zero current";
//		DecisonTableEntryValue[] TurnOn2 = new DecisonTableEntryValue[]{
//			new DecisonTableEntryValue(ShutDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{ZeroCurrent	},	1000),
//		};
		
		/*6th settle Down current*/
		//String settledownComment="wait for a sufficent period of time (e.g. 5 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleDownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												50000,	10 ,		new double[]{ZeroCurrent	},	1000),
		};
		
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  fBDTools.joinArray(stimulateDerating1, ShutDown2,settleDown3,stimulateUnDerating4,settleDown6);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput NTCDefect=new SimpleInputOutput();
		NTCDefect.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
		
	}
}

