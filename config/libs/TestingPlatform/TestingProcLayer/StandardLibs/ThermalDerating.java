package libs.TestingPlatform.TestingProcLayer.StandardLibs;

import config.ETS;
import libs.TestingPlatform.TestingProcLayer.SimpleInputOutput;
import libs.TestingPlatform.TestingProcLayer.SimpleInputOutput.ExternalLib;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;
/**
 * @author mteama
 * @version 1.0
 * @created 30-Aug-2017
 */

public class ThermalDerating {
	
	/*Constant Definition */
	public final static double ZeroCurrent=-3;
	final  public static double RESET = -2.0;
	public  final static double NO_VAL = -1.0;
	public  final static double TBD = 0 ;
	public  final static double ON = 5;
	public  final static double OFF = 0;
	public static PortType fPortType = PortType.Eventbased;
	
	
	/**
	* PortType (Timebased or Eventbased).
	*/
	public enum PortType {
		/**
		 * Timebased porting
		 */
		Timebased,
		/**
		* Eventbased porting
		 */
		Eventbased
	}
	
	/**
	 * Calculate the output for each derated step (i.e. Derating)
	 * @param Initial Output (e.g. Output Current (unit) mAmp)
	 * @param Final Output	 (e.g. Output Current (unit) mAmp)
	 * @param TimeStep		(unit) mSec
	 * @param Derating Step	(e.g. Output Current (unit) mAmp)	
	 * @author mteama
	 */
	public static double[] thermalDeratingPositive (double I_init, double I_final,double TimeStep,double DeratingStep)
	{
		int StepsNumber=(int) (Math.ceil(Math.abs((I_final-I_init))/DeratingStep));
		double I_steps[]=new double[StepsNumber];
		int index;
		for (index=0 ;index<(int)StepsNumber;index++)
		{
			I_steps[index]=I_init-((index+1)*DeratingStep);
		}
		return(I_steps);
	}
	/**
	 * Calculate the output for each time step which will be the same (i.e. NO Derating)
	 * @param Initial Output (e.g. Output Current (unit) mAmp)
	 * @param Final Output	 (e.g. Output Current (unit) mAmp)
	 * @param TimeStep		(unit) mSec
	 * @param Derating Step	(e.g. Output Current (unit) mAmp)	
	 * @author mteama
	 */
	public static double[] thermalDeratingNegative (double I_init, double I_final,double TimeStep,double DeratingStep)
	{
		int StepsNumber=(int) (Math.ceil(Math.abs((I_final-I_init))/DeratingStep));
		double I_steps[]=new double[StepsNumber];
		int index;
		for (index=0 ;index<(int)StepsNumber;index++)
		{
			I_steps[index]=I_init;
		}
		return(I_steps);
	}
	/**
	 * Calculate the output for each Underated step (i.e. UnDerating)
	 * @param Initial Output (e.g. Output Current (unit) mAmp)
	 * @param Final Output	 (e.g. Output Current (unit) mAmp)
	 * @param TimeStep		(unit) mSec
	 * @param Derating Step	(e.g. Output Current (unit) mAmp)
	 * @author mteama	
	 */
	public static double[] thermalUnDeratingPositive (double I_init, double I_final,double TimeStep,double DeratingStep)
	{
		int StepsNumber=(int) (Math.abs((I_final-I_init))/DeratingStep);
		double I_steps[]=new double[StepsNumber];
		int index;
		for (index=0 ;index<(int)StepsNumber;index++)
		{
			I_steps[index]=I_init+((index+1)*DeratingStep);
		}
		return(I_steps);
	}
	/**
	 * Calculate the output for each Time Step which will be the same (i.e. NO UnDerating)
	 * @param Initial Output (e.g. Output Current (unit) mAmp)
	 * @param Final Output	 (e.g. Output Current (unit) mAmp)
	 * @param TimeStep		(unit) mSec
	 * @param Derating Step	(e.g. Output Current (unit) mAmp)	
	 * @author mteama
	 */
	public static double[] thermalUnDeratingNegative (double I_init, double I_final,double TimeStep,double DeratingStep)
	{
		int StepsNumber=(int) (Math.abs((I_final-I_init))/DeratingStep);
		double I_steps[]=new double[StepsNumber];
		int index;
		for (index=0 ;index<(int)StepsNumber;index++)
		{
			I_steps[index]=I_init;
		}
		return(I_steps);
	}

	/**
	 * Check Thermal Derating Alg. in all zones with hyst. zone using BVA technique
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCHighTemp		(unit) mVolt
	 * @param NTCHystTemp		(unit) mVolt
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param MinDeratingPer	(unit) Ratio of the nominal output
	 * @param HystDeratingPer	(unit) Ratio of the nominal output that hyst temp will be asserted at
	 * @param DeratingStep		(e.g. Output Current (unit) mAmp)
	 * @param TimeStep			(unit) mSec
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	public static void ThermalDeratingBVA (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCHighTemp,double NTCHystTemp,double NominalOutput, double MinDeratingPer, double HystDeratingPer,double DeratingStep, double TimeStep,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*set LB NTC to High Temp voltage to force thermal derating*/
		/*Loop and assert*/
		/*in the loop*/
		/*loop until n steps i.e. (int)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1] * ( 1- MinDeratingPer)) / DeratingStep*/
		/*Assert on the current*/
		/*C5.CurrentSense.assertInstantaneousCurrent(HwConnection.LB_OUT,(float)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1]-(i * DeratingStep)), CurrentUnit.mA, (float)ProjectParams.currentMeasureTolerance,"step %d",i);*/
		/*pause for periodicity C5.pause(TimeStep);*/
		
		/*1st set LB NTC to High Temp voltage to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	1000, 1 , new double[]{ NominalOutput	},	500),
				new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCHighTemp	},null,	5, 1 , new double[]{ NominalOutput	},	5),	
		};
		
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingToHyst[] = ThermalDerating.thermalDeratingPositive( NominalOutput,HystDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingToHystCurrentComment="Assert on the output current for each step ";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingToHyst.length];
		for(int indexx = 0; indexx < (currentArrayDeratingToHyst.length) ; indexx++)
		{
			thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingToHystCurrentComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingToHyst[indexx]	},	0);			
		}	
		
		/*3rd But NTC Temp. in hyst value*/
		DecisonTableEntryValue[] stimulateHyst3 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to hysteresis Temp voltage to force current to stop derating then wait for suffient time to make sure that output is settled (e.g. 5 seconds)", 	new double[]{NO_VAL, NO_VAL,	NTCHystTemp	},null,	5000, 1 , new double[]{ NominalOutput*HystDeratingPer	},	5),	
		};
		
		/*4rd But NTC Temp. in high temp value*/
		DecisonTableEntryValue[] stimulateDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCHighTemp	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
		};
		
		/*5th thermalDerating From Hyst Current to min Current*/
		/*A create the array*/
		double currentArrayDeratingToMin[] = ThermalDerating.thermalDeratingPositive( HystDeratingPer*(NominalOutput),MinDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingToMinCurrentComment="Assert on the output current for each step untill complet derating";
		DecisonTableEntryValue[] thermalDeratingPositive5 = new DecisonTableEntryValue[currentArrayDeratingToMin.length];
		for(int indexx = 0; indexx < (currentArrayDeratingToMin.length) ; indexx++)
		{
			thermalDeratingPositive5[indexx]= new DecisonTableEntryValue(thermalDeratingToMinCurrentComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingToMin[indexx]	},	0);			
		}
		
		/*6th settle down current*/
		String settledownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settledownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingPer*(NominalOutput)	},	1000),
		};
		
		/*7th Set LB NTC to normal temperature voltage to force underating*/
		DecisonTableEntryValue[] stimulateUnDerating7 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage to force underating", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL},	5),
		};
		
		/*8nd thermalUnDeratingTo Hyst*/
		/*A create the array*/
		double currentArrayUnDeratingToHyst[] = ThermalDerating.thermalUnDeratingPositive( MinDeratingPer*(NominalOutput),HystDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalUnDeratingToHystComment="Assert on the output current for each step";
		DecisonTableEntryValue[] thermalUnDeratingPositive8 = new DecisonTableEntryValue[ currentArrayUnDeratingToHyst.length];
		for(int indexx = 0; indexx < ( currentArrayUnDeratingToHyst.length) ; indexx++)
		{
			thermalUnDeratingPositive8[indexx]= new DecisonTableEntryValue(thermalUnDeratingToHystComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingToHyst[indexx]	},	0);			
		}	
		
		/*9th But NTC Temp. in hyst value*/
		DecisonTableEntryValue[] stimulateHyst9 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to hysteresis Temp voltage to force current to stop Underating then wait for suffient time to make sure that output is settled (e.g. 5 seconds)", 	new double[]{NO_VAL, NO_VAL,	NTCHystTemp	},null,	5000, 1 , new double[]{ NominalOutput*HystDeratingPer	},	5),	
		};
		
		/*10th Set LB NTC to normal temperature voltage to force underating*/
		DecisonTableEntryValue[] stimulateUnDerating10 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage to force underating", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL},	5),
		};
		
		/*11th thermalUnDeratingTo Nominal*/
		/*A create the array*/
		double currentArrayUnDeratingToNom[] = ThermalDerating.thermalUnDeratingPositive( MinDeratingPer*(NominalOutput),NominalOutput,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalUnDeratingToNomComment="Assert on the output current for each step Untill complet underating";
		DecisonTableEntryValue[] thermalUnDeratingPositive11 = new DecisonTableEntryValue[ currentArrayUnDeratingToNom.length];
		for(int indexx = 0; indexx < ( currentArrayUnDeratingToNom.length) ; indexx++)
		{
			thermalUnDeratingPositive11[indexx]= new DecisonTableEntryValue(thermalUnDeratingToNomComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingToNom[indexx]	},	0);			
		}	
		
		
		/*12th settle Up current*/
		String settleUpComment="wait for a sufficent period of time (e.g. 5 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to nominal current";
		DecisonTableEntryValue[] settleUp12 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleUpComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												5000,	10 ,		new double[]{NominalOutput	},	1000),
		};
		
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateDerating1,thermalDeratingPositive2,stimulateHyst3,stimulateDerating4,thermalDeratingPositive5,settleDown6,stimulateUnDerating7,thermalUnDeratingPositive8,stimulateHyst9,stimulateUnDerating10,thermalUnDeratingPositive11,settleUp12);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput thermalDerating1=new SimpleInputOutput();
		thermalDerating1.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
	}
	
	/**
	 * Check Thermal Derating Alg. in all zones with hyst. zone using BVA technique
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCHighTemp		(unit) mVolt
	 * @param NTCHystTemp		(unit) mVolt
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param MinDeratingPer	(unit) Ratio of the nominal output
	 * @param HystDeratingPer	(unit) Ratio of the nominal output that hyst temp will be asserted at
	 * @param DeratingStep		(e.g. Output Current (unit) mAmp)
	 * @param TimeStep			(unit) mSec
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	public static void ThermalDeratingBVAStates (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCHighTemp,double NTCHystTemp,double NominalOutput, double MinDeratingPer, double HystDeratingPer,double DeratingStep, double TimeStep,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*set LB NTC to High Temp voltage to force thermal derating*/
		/*Loop and assert*/
		/*in the loop*/
		/*loop until n steps i.e. (int)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1] * ( 1- MinDeratingPer)) / DeratingStep*/
		/*Assert on the current*/
		/*C5.CurrentSense.assertInstantaneousCurrent(HwConnection.LB_OUT,(float)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1]-(i * DeratingStep)), CurrentUnit.mA, (float)ProjectParams.currentMeasureTolerance,"step %d",i);*/
		/*pause for periodicity C5.pause(TimeStep);*/
		
		/*1st set LB NTC to High Temp voltage to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	1000, 1 , new double[]{ NominalOutput	},	500),
				new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCHighTemp	},null,	5, 1 , new double[]{ NominalOutput	},	5),	
		};
		
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingToHyst[] = ThermalDerating.thermalDeratingPositive( NominalOutput,HystDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingToHystCurrentComment="Assert on the output current for each step ";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingToHyst.length];
		for(int indexx = 0; indexx < (currentArrayDeratingToHyst.length) ; indexx++)
		{
			thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingToHystCurrentComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingToHyst[indexx]	},	0);			
		}	
		
		/*3rd But NTC Temp. in hyst value*/
		DecisonTableEntryValue[] stimulateHyst3 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to hysteresis Temp voltage to force current to stop derating then expect that derating will complete and not affected", 	new double[]{NO_VAL, NO_VAL,	NTCHystTemp	},null,	0, 0 , new double[]{ NominalOutput*HystDeratingPer	},	0),	
		};
			
		/*5th thermalDerating From Hyst Current to min Current*/
		/*A create the array*/
		double currentArrayDeratingToMin[] = ThermalDerating.thermalDeratingPositive( HystDeratingPer*(NominalOutput),MinDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingToMinCurrentComment="Assert on the output current for each step untill complet derating";
		DecisonTableEntryValue[] thermalDeratingPositive5 = new DecisonTableEntryValue[currentArrayDeratingToMin.length];
		for(int indexx = 0; indexx < (currentArrayDeratingToMin.length) ; indexx++)
		{
			thermalDeratingPositive5[indexx]= new DecisonTableEntryValue(thermalDeratingToMinCurrentComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingToMin[indexx]	},	0);			
		}
		
		/*6th settle down current*/
		String settledownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settledownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingPer*(NominalOutput)	},	1000),
		};
		
		/*7th Set LB NTC to normal temperature voltage to force underating*/
		DecisonTableEntryValue[] stimulateUnDerating7 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage to force underating", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL},	5),
		};
		
		/*8nd thermalUnDeratingTo Hyst*/
		/*A create the array*/
		double currentArrayUnDeratingToHyst[] = ThermalDerating.thermalUnDeratingPositive( MinDeratingPer*(NominalOutput),HystDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalUnDeratingToHystComment="Assert on the output current for each step";
		DecisonTableEntryValue[] thermalUnDeratingPositive8 = new DecisonTableEntryValue[ currentArrayUnDeratingToHyst.length];
		for(int indexx = 0; indexx < ( currentArrayUnDeratingToHyst.length) ; indexx++)
		{
			thermalUnDeratingPositive8[indexx]= new DecisonTableEntryValue(thermalUnDeratingToHystComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingToHyst[indexx]	},	0);			
		}	
		
		/*9th But NTC Temp. in hyst value*/
		DecisonTableEntryValue[] stimulateHyst9 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to hysteresis Temp voltage to force current to stop Underating then expect that Underating will complete and not affected", 	new double[]{NO_VAL, NO_VAL,	NTCHystTemp	},null,	0, 0 , new double[]{ NominalOutput*HystDeratingPer	},	0),	
		};
		
		
		/*11th thermalUnDeratingTo Nominal*/
		/*A create the array*/
		double currentArrayUnDeratingToNom[] = ThermalDerating.thermalUnDeratingPositive( MinDeratingPer*(NominalOutput),NominalOutput,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalUnDeratingToNomComment="Assert on the output current for each step Untill complet underating";
		DecisonTableEntryValue[] thermalUnDeratingPositive11 = new DecisonTableEntryValue[ currentArrayUnDeratingToNom.length];
		for(int indexx = 0; indexx < ( currentArrayUnDeratingToNom.length) ; indexx++)
		{
			thermalUnDeratingPositive11[indexx]= new DecisonTableEntryValue(thermalUnDeratingToNomComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingToNom[indexx]	},	0);			
		}	
		
		
		/*12th settle Up current*/
		String settleUpComment="wait for a sufficent period of time (e.g. 5 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to nominal current";
		DecisonTableEntryValue[] settleUp12 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleUpComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												5000,	10 ,		new double[]{NominalOutput	},	1000),
		};
		/*13th set LB NTC to High Temp voltage to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating13 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	1000, 1 , new double[]{ NominalOutput	},	500),
				new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCHighTemp	},null,	5, 1 , new double[]{ NominalOutput	},	5),	
		};
		
		/*14th thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( NominalOutput,MinDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step untill complet derating";
		DecisonTableEntryValue[] thermalDeratingPositive13 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		for(int indexx = 0; indexx < (currentArrayDeratingPositive.length) ; indexx++)
		{
			thermalDeratingPositive13[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
		}	
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateDerating1,thermalDeratingPositive2,stimulateHyst3,thermalDeratingPositive5,settleDown6,stimulateUnDerating7,thermalUnDeratingPositive8,stimulateHyst9,thermalUnDeratingPositive11,settleUp12,stimulateDerating13,thermalDeratingPositive13);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput thermalDerating1=new SimpleInputOutput();
		thermalDerating1.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
	}
	
	
	
	/**
	 * Run Thermal Derating Algorithm when the High Temp is applied before starting on the ECU
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCHighTemp		(unit) mVolt
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param MinDeratingPer	(unit) % of the nominal output
	 * @param DeratingStep		(e.g. Output Current (unit) mAmp)
	 * @param TimeStep			(unit) mSec
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	public static void InitThermalDeratingReversible (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCHighTemp,double NominalOutput, double MinDeratingPer, double DeratingStep, double TimeStep,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*set LB NTC to High Temp voltage to force thermal derating*/
		/*Loop and assert*/
		/*in the loop*/
		/*loop until n steps i.e. (int)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1] * ( 1- MinDeratingPer)) / DeratingStep*/
		/*Assert on the current*/
		/*C5.CurrentSense.assertInstantaneousCurrent(HwConnection.LB_OUT,(float)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1]-(i * DeratingStep)), CurrentUnit.mA, (float)ProjectParams.currentMeasureTolerance,"step %d",i);*/
		/*pause for periodicity C5.pause(TimeStep);*/
		
		/*1st set LB NTC to High Temp voltage to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating ", 	new double[]{0.0, 0.0,	NTCHighTemp	},null,	TimeStep, 1 , new double[]{ NominalOutput	},	2000),
				new DecisonTableEntryValue("set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NO_VAL	},null,	5, 1 , new double[]{ NominalOutput	},	5),	
		};
		
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( NominalOutput,MinDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step untill complet derating";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		for(int indexx = 0; indexx < (currentArrayDeratingPositive.length) ; indexx++)
		{
			thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
		}	
		
		/*3rd settle down current*/
		String settledownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown3 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settledownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingPer*(NominalOutput)	},	1000),
		};
		
		/*4th Set LB NTC to normal temperature voltage to force underating*/
		DecisonTableEntryValue[] stimulateUnDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage to force underating", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL},	5),
		};
		
		/*5nd thermalUnDeratingPositive*/
		/*A create the array*/
		double currentArrayUnDeratingPositive[] = ThermalDerating.thermalUnDeratingPositive( MinDeratingPer*(NominalOutput),NominalOutput,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalUnDeratingPositiveComment="Assert on the output current for each step untill complet Underating";
		DecisonTableEntryValue[] thermalUnDeratingPositive5 = new DecisonTableEntryValue[ currentArrayUnDeratingPositive.length];
		for(int indexx = 0; indexx < ( currentArrayUnDeratingPositive.length) ; indexx++)
		{
			thermalUnDeratingPositive5[indexx]= new DecisonTableEntryValue(thermalUnDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingPositive[indexx]	},	0);			
		}	
		
		/*6th settle Up current*/
		String settleUpComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to nominal current";
		DecisonTableEntryValue[] settleUp6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleUpComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{NominalOutput	},	1000),
		};
		
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateDerating1,thermalDeratingPositive2,settleDown3,stimulateUnDerating4,thermalUnDeratingPositive5,settleUp6);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput thermalDerating1=new SimpleInputOutput();
		thermalDerating1.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
	}
	/**
	 * Run Thermal Derating Algorithm and check this alg. with EP technique 
	 * @param PSNominalVoltage	(unit) Volt
	 * @param ONSignl			(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp	(unit) mVolt
	 * @param NTCHighTemp		(unit) mVolt
	 * @param NominalOutput		(e.g. Output Current (unit) mAmp)
	 * @param MinDeratingPer	(unit) % of the nominal output
	 * @param DeratingStep		(e.g. Output Current (unit) mAmp)
	 * @param TimeStep			(unit) mSec
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	public static void ThermalDeratingReversible (double PSNominalVoltage, double ONSignal, double NTCNominalTemp,double NTCHighTemp,double NominalOutput, double MinDeratingPer, double DeratingStep, double TimeStep,CastlePortingMap castlePorting, ETS executionUnit)
	{
		/*set LB NTC to High Temp voltage to force thermal derating*/
		/*Loop and assert*/
		/*in the loop*/
		/*loop until n steps i.e. (int)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1] * ( 1- MinDeratingPer)) / DeratingStep*/
		/*Assert on the current*/
		/*C5.CurrentSense.assertInstantaneousCurrent(HwConnection.LB_OUT,(float)(ProjectParams.LBCurrentBin[(int) ProjectParams.BIN1]-(i * DeratingStep)), CurrentUnit.mA, (float)ProjectParams.currentMeasureTolerance,"step %d",i);*/
		/*pause for periodicity C5.pause(TimeStep);*/
		
		/*1st set LB NTC to High Temp voltage to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set voltage to nominal voltage and set temp to normal temp then assert on nominal current", 	new double[]{PSNominalVoltage, ONSignal,	NTCNominalTemp	},null,	TimeStep, 1 , new double[]{ NominalOutput	},	500),
				new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCHighTemp	},null,	5, 1 , new double[]{ NominalOutput	},	5),	
		};
		
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( NominalOutput,MinDeratingPer*(NominalOutput),TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step untill complet derating";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		for(int indexx = 0; indexx < (currentArrayDeratingPositive.length) ; indexx++)
		{
			thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
		}	
		
		/*3rd settle down current*/
		String settledownComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown3 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settledownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{MinDeratingPer*(NominalOutput)	},	1000),
		};
		
		/*4th Set LB NTC to normal temperature voltage to force underating*/
		DecisonTableEntryValue[] stimulateUnDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage to force underating", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL},	5),
		};
		
		/*5nd thermalUnDeratingPositive*/
		/*A create the array*/
		double currentArrayUnDeratingPositive[] = ThermalDerating.thermalUnDeratingPositive( MinDeratingPer*(NominalOutput),NominalOutput,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalUnDeratingPositiveComment="Assert on the output current for each step untill complet Underating";
		DecisonTableEntryValue[] thermalUnDeratingPositive5 = new DecisonTableEntryValue[ currentArrayUnDeratingPositive.length];
		for(int indexx = 0; indexx < ( currentArrayUnDeratingPositive.length) ; indexx++)
		{
			thermalUnDeratingPositive5[indexx]= new DecisonTableEntryValue(thermalUnDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingPositive[indexx]	},	0);			
		}	
		
		/*6th settle Up current*/
		String settleUpComment="wait for a sufficent period of time (e.g. 10 sec) so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to nominal current";
		DecisonTableEntryValue[] settleUp6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleUpComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												10000,	10 ,		new double[]{NominalOutput	},	1000),
		};
		
		
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateDerating1,thermalDeratingPositive2,settleDown3,stimulateUnDerating4,thermalUnDeratingPositive5,settleUp6);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput thermalDerating1=new SimpleInputOutput();
		thermalDerating1.RunDecisionTable(inputOutputArray, castlePorting, executionUnit,ExternalLib.WithoutExLib);
	}
	
	/**
	 * Stimulate Derating State and calculating the expected current for each step then assert on those steps
	 * ,Finally, Return the decision table to be run
	 * @param PSNominalVoltage												(unit) Volt
	 * @param ONSignl														(e.g. input power (unit) Volt)
	 * @param NTCHighTemp(High Temperature to stimulate derating state)		(unit) mVolt
	 * @param Initial_Output (initial output at which derating will start)	(e.g. Output Current (unit) mAmp)
	 * @param Final_Output	
	 * @param DeratingStep													((unit) mAmp)
	 * @param TimeStep														(unit) mSec
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] TherDeratingState (double PSNominalVoltage, double ONSignal,double NTCHighTemp,double Initial_Output, double Final_Output, double DeratingStep, double TimeStep)
	{	
		/*1st set LB NTC to High Temp voltage to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
			new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	NTCHighTemp	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
					};
					
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( Initial_Output,Final_Output,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		
		switch(fPortType)
			 {
			 	case Eventbased:				
					for(int indexx = 0; indexx < (currentArrayDeratingPositive.length - 1) ; indexx++)
					{
						thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep*(indexx+1), 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
					}
					thermalDeratingPositive2[currentArrayDeratingPositive.length - 1] = new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep*(currentArrayDeratingPositive.length), 0 , new double[]{ currentArrayDeratingPositive[currentArrayDeratingPositive.length - 1]	},	(TimeStep*(currentArrayDeratingPositive.length)) + 500);				
					break;
					
				case Timebased:	
					for(int indexx = 0; indexx < currentArrayDeratingPositive.length ; indexx++)
					{
						thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
					}
					break;
			 }
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateDerating1,thermalDeratingPositive2);
		
		return inputOutputArray;
	}
	
	/**
	 * Stimulate Derating State and calculating the expected current for each step then assert on those steps
	 * ,Finally, Return the decision table to be run
	 * @param PSNominalVoltage												(unit) Volt
	 * @param ONSignl														(e.g. input power (unit) Volt)
	 * @param DefectStatus(Exist of Defect to stimulate derating state)		(unit) 1 or 0
	 * @param Initial_Output (initial output at which derating will start)	(e.g. Output Current (unit) mAmp)
	 * @param Final_Output	
	 * @param DeratingStep													((unit) mAmp)
	 * @param TimeStep														(unit) mSec
	 * @author mnagah
	 */
	public static DecisonTableEntryValue[] TherDeratingStateAfterDefect (double PSNominalVoltage, double ONSignal, double DefectStatus ,double Initial_Output, double Final_Output, double DeratingStep, double TimeStep)
	{
		/*1st set LB NTC to High Temp voltage to force thermal derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to High Temp voltage to force thermal derating", 	new double[]{NO_VAL, NO_VAL,	DefectStatus	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
		};
		
		/*2nd thermalDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( Initial_Output,Final_Output,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step";
		DecisonTableEntryValue[] thermalDeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		switch(fPortType)
			 {
			 	case Eventbased:
					for(int indexx = 0; indexx < (currentArrayDeratingPositive.length - 1) ; indexx++)
					{
						thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep*(indexx+1), 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
					}
					thermalDeratingPositive2[currentArrayDeratingPositive.length - 1] = new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep*(currentArrayDeratingPositive.length), 0 , new double[]{ currentArrayDeratingPositive[currentArrayDeratingPositive.length - 1]	},	(TimeStep*(currentArrayDeratingPositive.length)) + 500);	
				break;
				
				case Timebased:	
				    for(int indexx = 0; indexx < currentArrayDeratingPositive.length  ; indexx++)
					{
						thermalDeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
					}
				break;	
			 }
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateDerating1,thermalDeratingPositive2);
		
		return inputOutputArray;
	}
	
	/**
	 * Stimulate UnDerating State and calculating the expected current for each step then assert on those steps
	 * ,Finally, Return the decision table to be run	
	 * @param PSNominalVoltage														(unit) Volt
	 * @param ONSignl																(e.g. input power (unit) Volt)
	 * @param NTCNominalTemp(Nominal Temperature to stimulate Underating state)		(unit) mVolt
	 * @param Initial_Output (initial output at which Underating will start)		(e.g. Output Current (unit) mAmp)
	 * @param Final_Output	
	 * @param DeratingStep															((unit) mAmp)
	 * @param TimeStep																(unit) mSec
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] TherUnDeratingState (double PSNominalVoltage, double ONSignal,double NTCNominalTemp,double Initial_Output, double Final_Output, double DeratingStep, double TimeStep)
	{
		/*4th Set LB NTC to normal temperature voltage to force underating*/
		DecisonTableEntryValue[] stimulateUnDerating4 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("Set LB NTC to normal temperature voltage to force underating", 	new double[]{NO_VAL, NO_VAL,	NTCNominalTemp	},null,	5, 1 , new double[]{ NO_VAL},	5),
		};
		
		/*5nd thermalUnDeratingPositive*/
		/*A create the array*/
		double currentArrayUnDeratingPositive[] = ThermalDerating.thermalUnDeratingPositive( Initial_Output,Final_Output,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalUnDeratingPositiveComment="Assert on the output current for each step";
		DecisonTableEntryValue[] thermalUnDeratingPositive5 = new DecisonTableEntryValue[ currentArrayUnDeratingPositive.length];
		switch(fPortType)
			 {
			 	case Eventbased:
					for(int indexx = 0; indexx < ( currentArrayUnDeratingPositive.length - 1) ; indexx++)
					{
						thermalUnDeratingPositive5[indexx]= new DecisonTableEntryValue(thermalUnDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep*(indexx+1), 0 , new double[]{  currentArrayUnDeratingPositive[indexx]	},	0);			
					}	
					thermalUnDeratingPositive5[currentArrayUnDeratingPositive.length - 1] = new DecisonTableEntryValue(thermalUnDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep*(currentArrayUnDeratingPositive.length), 0 , new double[]{ currentArrayUnDeratingPositive[currentArrayUnDeratingPositive.length - 1]	},	(TimeStep*(currentArrayUnDeratingPositive.length)) + 500);	
				break;
				
				case Timebased:
					for(int indexx = 0; indexx < ( currentArrayUnDeratingPositive.length - 1) ; indexx++)
					{
						thermalUnDeratingPositive5[indexx]= new DecisonTableEntryValue(thermalUnDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL,	NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingPositive[indexx]	},	0);			
					}	
				}
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateUnDerating4,thermalUnDeratingPositive5);
		
		return inputOutputArray;
	}
	
	/**
	 * Stimulate Hyst State by injecting temperature in the hyst. zone then wait for sufficient time to make sure that current is settle
	 * ,Finally, Return the decision table to be run	
	 * @param PSNominalVoltage														(unit) Volt
	 * @param ONSignl																(e.g. input power (unit) Volt)
	 * @param NTCHystTemp(Hyst Temperature to stimulate Hyst state)					(unit) mVolt
	 * @param Hyst_Output (settled output at which current will held)				(e.g. Output Current (unit) mAmp)
	 * @param wait_time																(unit) mSec
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] TherHystState (double PSNominalVoltage, double ONSignal,double NTCHystTemp,double Hyst_Output, double wait_Time)
	{
		/*3rd But NTC Temp. in hyst value*/
		DecisonTableEntryValue[] stimulateHyst3 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("set the NTC to hysteresis Temp voltage to force current to stop derating then wait for suffient time to make sure that output is settled", 	new double[]{NO_VAL, NO_VAL,	NTCHystTemp	},null,	wait_Time, 1 , new double[]{ Hyst_Output	},	5),	
		};
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(stimulateHyst3);
		////////////////////////////////////////////////////////////////////////
		return inputOutputArray;
	}
	
	/**
	 * Test Settle Up State by waiting for sufficient time to make sure that current is settled
	 * ,Finally, Return the decision table to be run	
	 * @param PSNominalVoltage														(unit) Volt
	 * @param ONSignl																(e.g. input power (unit) Volt)
	 * @param Hyst_Output (settled output at which current will held)				(e.g. Output Current (unit) mAmp)
	 * @param wait_time																(unit) mSec
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] SettleUpState (double PSNominalVoltage, double ONSignal,double SettleUp_Output, double wait_Time)
	{
		/*6th settle Up current*/
		String settleUpComment="wait for a sufficent period of time  so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to nominal current";
		DecisonTableEntryValue[] settleUp6 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settleUpComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												wait_Time,	10 ,		new double[]{SettleUp_Output	},	5),
		};
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(settleUp6);
		////////////////////////////////////////////////////////////////////////
		return inputOutputArray;
	}
	
	/**
	 * Test Settle Down State by waiting for sufficient time to make sure that current is settled
	 * ,Finally, Return the decision table to be run	
	 * @param PSNominalVoltage														(unit) Volt
	 * @param ONSignl																(e.g. input power (unit) Volt)
	 * @param Hyst_Output (settled output at which current will held)				(e.g. Output Current (unit) mAmp)
	 * @param wait_time																(unit) mSec
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] SettleDownState (double PSNominalVoltage, double ONSignal,double SettleDown_Output, double wait_Time)
	{
		/*3rd settle down current*/
		String settledownComment="wait for a sufficent period of time  so that the current reach steady state level then Read the output current to make sure that derating is stopped and current settled to min. current";
		DecisonTableEntryValue[] settleDown3 = new DecisonTableEntryValue[]{
			new DecisonTableEntryValue(settledownComment, 									new double[]{NO_VAL, NO_VAL,		NO_VAL	},null,												wait_Time,	10 ,		new double[]{SettleDown_Output	},	5),
		};
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  Tools.joinArray(settleDown3);
		////////////////////////////////////////////////////////////////////////
		return inputOutputArray;
	}
	
	
	
}
