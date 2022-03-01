package libs.TestingPlatform.TestingProcLayer.FBDexternalLib;

import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;

/**
 * @author mteama
 * @version 1.0
 * @created 16-Jan-2018
 */

public class PowerDerating {
	
	/*Constant Definition */
	public final static double ZeroCurrent=-3;
	final  public static double RESET = -2.0;
	public  final static double NO_VAL = -1.0;
	public  final static double TBD = 0 ;
	public  final static double ON = 5;
	public  final static double OFF = 0;
	
	
	/**
	 * Calculate the max allowable output current from power derating function(curve)(saturation like curve)
	 * @param InputVoltage (e.g. Output Current (unit) mAmp)
	 * @param BINCurrent	 (e.g. Output Current (unit) mAmp)
	 * @param TimeStep		(unit) mSec
	 * @param Derating Step	(e.g. Output Current (unit) mAmp)	
	 * @author mteama
	 */
	public static double PwrCalcFn (double InputVoltage, double BINCurrent,double V1,double V2,double I1,double I2)
	{
		double IApply=BINCurrent;
		double slope=(I2-I1)/(V2-V1);
		
		if(InputVoltage>=V2)
		{
			IApply=Math.min(BINCurrent, I2);
		}
		if(InputVoltage<=V1)
		{
			IApply=I1;
		}
		if((InputVoltage>V1)&&(InputVoltage<V2))
		{
			IApply=Math.min(BINCurrent,I1+slope*(InputVoltage-V1));
		}
		
		return(IApply);
	}
	
	/**
	 * Stimulate Derating State and calculating the expected current for each step then assert on those steps
	 * ,Finally, Return the decision table to be run
	 * @param InputVoltage													(unit) Volt
	 * @param ONSignl														(e.g. input volt (unit) Volt)
	 * @param Initial_Output (initial output at which derating will start)	(e.g. Output Current (unit) mAmp)
	 * @param DeratingStep													((unit) mAmp)
	 * @param TimeStep														(unit) mSec
	 * @param BINCurrent													(unit) mAmp
	 * @param V1															(unit) Volt :Min. volt on curve before saturation(PwrCurveDefiningPoints)
	 * @param V2															(unit) Volt :Max. volt on curve before saturation(PwrCurveDefiningPoints)
	 * @param I1															(unit) mAmp :Current Corresponding to V1 "Most properly Min. HW Current "(PwrCurveDefiningPoints)
	 * @param I2															(unit) mAmp :Current Corresponding to V2 "Most properly Max. HW Current "(PwrCurveDefiningPoints)
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] PwrDeratingState (double InputVoltage, double ONSignal,double Initial_Output, double DeratingStep, double TimeStep, double BINCurrent,double V1,double V2,double I1,double I2)
	{		/*Calculating Final_Output*/
		double Final_Output=PwrCalcFn (InputVoltage,BINCurrent,V1,V2,I1,I2);
		/*1st set the Volt to a derating value to force Power derating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("*************set the Volt to"+InputVoltage+" Volt to a derating value to force Power derating form current"+Initial_Output+"mAmp to current"+Final_Output+"mAmp*************", 	new double[]{InputVoltage, NO_VAL	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
		};
		

		
		/*2nd PowerDeratingPositive*/
		/*A create the array*/
		double currentArrayDeratingPositive[] = ThermalDerating.thermalDeratingPositive( Initial_Output,Final_Output,TimeStep,DeratingStep);
		/*B fill the table*/
		String thermalDeratingPositiveComment="Assert on the output current for each step";
		DecisonTableEntryValue[] DeratingPositive2 = new DecisonTableEntryValue[currentArrayDeratingPositive.length];
		for(int indexx = 0; indexx < (currentArrayDeratingPositive.length) ; indexx++)
		{
			DeratingPositive2[indexx]= new DecisonTableEntryValue(thermalDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL	},null,	TimeStep, 0 , new double[]{ currentArrayDeratingPositive[indexx]	},	0);			
		}	
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  fBDTools.joinArray(stimulateDerating1,DeratingPositive2);
		////////////////////////////////////////////////////////////////////////
		return inputOutputArray;
	}
	/**
	 * Stimulate UnDerating State and calculating the expected current for each step then assert on those steps
	 * ,Finally, Return the decision table to be run	
	 * @param InputVoltage													(unit) Volt
	 * @param ONSignl														(e.g. input volt (unit) Volt)
	 * @param Initial_Output (initial output at which derating will start)	(e.g. Output Current (unit) mAmp)
	 * @param DeratingStep													((unit) mAmp)
	 * @param TimeStep														(unit) mSec
	 * @param BINCurrent													(unit) mAmp
	 * @param V1															(unit) Volt :Min. volt on curve before saturation(PwrCurveDefiningPoints)
	 * @param V2															(unit) Volt :Max. volt on curve before saturation(PwrCurveDefiningPoints)
	 * @param I1															(unit) mAmp :Current Corresponding to V1 "Most properly Min. HW Current "(PwrCurveDefiningPoints)
	 * @param I2															(unit) mAmp :Current Corresponding to V2 "Most properly Max. HW Current "(PwrCurveDefiningPoints)
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] PwrUnDeratingState (double InputVoltage, double ONSignal,double Initial_Output, double DeratingStep, double TimeStep, double BINCurrent,double V1,double V2,double I1,double I2)
	{
		/*Calculating Final_Output*/
		double Final_Output=PwrCalcFn (InputVoltage,BINCurrent,V1,V2,I1,I2);
		/*1st set the Volt to a derating value to force Power Underating*/
		DecisonTableEntryValue[] stimulateDerating1 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("*************set the Volt to"+InputVoltage+" Volt to a UnDerating value to force Power UnDerating form current"+Initial_Output+"mAmp to current"+Final_Output+"mAmp*************" , 	new double[]{InputVoltage, NO_VAL	},null,	5, 1 , new double[]{ NO_VAL	},	5),	
		};
		

		
		/*2nd UnDeratingPositive*/
		/*A create the array*/
		double currentArrayUnDeratingPositive[] = ThermalDerating.thermalUnDeratingPositive( Initial_Output,Final_Output,TimeStep,DeratingStep);
		/*B fill the table*/
		String UnDeratingPositiveComment="Assert on the output current for each step";
		DecisonTableEntryValue[] UnDeratingPositive5 = new DecisonTableEntryValue[ currentArrayUnDeratingPositive.length];
		for(int indexx = 0; indexx < ( currentArrayUnDeratingPositive.length) ; indexx++)
		{
			UnDeratingPositive5[indexx]= new DecisonTableEntryValue(UnDeratingPositiveComment, 	new double[]{NO_VAL, NO_VAL	},null,	TimeStep, 0 , new double[]{  currentArrayUnDeratingPositive[indexx]	},	0);			
		}	
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  fBDTools.joinArray(stimulateDerating1,UnDeratingPositive5);
		////////////////////////////////////////////////////////////////////////
		return inputOutputArray;
	}
	
	/**
	 * Stimulate Hyst State by injecting volt in the hyst. zone then wait for sufficient time to make sure that current is settle
	 * ,Finally, Return the decision table to be run	
	 * @param InputVoltage													(unit) Volt
	 * @param ONSignl																(e.g. input power (unit) Volt)
	 * @param Hyst_Output (settled output at which current will held)				(e.g. Output Current (unit) mAmp)
	 * @param wait_time																(unit) mSec
	 * @author mteama
	 */
	public static DecisonTableEntryValue[] PwrHystState (double InputVoltage, double ONSignal,double Hyst_Output, double wait_Time)
	{
		/*3rd But NTC Temp. in hyst value*/
		DecisonTableEntryValue[] stimulateHyst3 = new DecisonTableEntryValue[] {
				new DecisonTableEntryValue("*************set the Volt to Maintain same Current then wait for suffient time to make sure that output is settled*************", 	new double[]{InputVoltage, NO_VAL	},null,	wait_Time, 1 , new double[]{ Hyst_Output	},	5),	
		};
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutputArray =  fBDTools.joinArray(stimulateHyst3);
		////////////////////////////////////////////////////////////////////////
		return inputOutputArray;
	}
	
	

}
