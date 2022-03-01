/**
 * 
 */
package libs.TestingPlatform.TestingProcLayer.StandardLibs;

/**
 * Power Derating Standard Library.
 * @author Mostafa ABOELKHAIR
 * @version 1.1
 * @created 08-Jan-2019
 * @updated 30-May-2019
 */
public class PowerDerating {

	public enum EfficiencyType{
		Multiplied,
		Divided,
		Neutral
	}
	
	public  static EfficiencyType 	PwrAvailCalcEfficiencyType;
	public  static EfficiencyType 	PwrNeedCalcEfficiencyType;
	public  static EfficiencyType 	PwrMaxCalcEfficiencyType;
	public  static EfficiencyType 	CurDerCalcEfficiencyType;

	public  static int 				PwrErrorLog_Length;
	public  static int				MaxNumOfIterations;
	public  static long				RoundFactor;
	
	public  static double[] 		VoltFiltInputMainIn_arr				= {};

	public  static double[]			PwrAvailCurSteady_arr 				= {};
	
	public  static double[][]		PwrAvailEfficiencyValTable_arr		= {};

	public  static double[][]		PwrAvailEfficiencyVoltTable_arr		= {};

	public  static double[]			PwrNeedEfficiencyVal_arr			= {};

	public  static double[]			PwrMaxEfficiencyVal_arr				= {};

	public  static double[]			CurDerEfficiencyVal_arr				= {};

	public  static double[]			PwrNeedVoltVal_arr					= {};

	public  static double[]			PwrMaxVoltVal_arr					= {};

	public  static double			Config_CoeffPropn;

	public  static double			Config_PwrDefaultValn;

	public  static double[]			Config_PwrMinVal_arr 				= {};

	public  static int[]			CurBinNbrVal_arr					= {};

	public  static double[][]		CurBinTable_arr						= {};

	public  static double[]			Config_SharingCoeff_arr   			= {};

	public  static boolean[]		BoolPwrNeedsActivationStatus_arr	= {};

	private static boolean[]		BoolTransition_arr					= {};
	private static boolean[]		BoolTransitionFalse_arr				= {};

	public  static double[] 		PwrAvailEfficiencyVal_arr			= {};
	public  static double[]			PwrAvailVal_arr						= {};
	public  static double[]			PwrNeedVal_arr						= {};

	public  static double 			PwrNeedsTot;
	public  static double 			PwrAvailTot;

	public  static double 			PwrError;

	public  static double[] 		PwrMaxVal_arr						= {};

	public  static double[] 		PwrApplyVal_arr						= {};

	private static double[] 		PwrApplyVal_Prev_arr				= {};

	public  static double[] 		PwrProtecVal_arr					= {};

	public  static double[] 		CurBinVal_arr						= {};

	public  static double[] 		CurRefTargetVal_arr					= {};

	public  static double[] 		CurPwrDeratVal_arr					= {};

	public  static double[] 		PwrErrorShareVal_arr				= {};

	public  static double 			PerSharingTot;

	public  static double[]			PerSharingPercent_arr				= {};


	/**
	 * Main Function Only for Debugging to Test Power Derating Library with project custom configurations
	 */
	public static void main(String[] args) {
		
//		PowerDerating_Cfg.Init_PowerDeratingLib(PowerDerating_Cfg.TestsCfg.Default);
//		
//		for(int j = 0; j < PowerDerating_Cfg.Default_VoltFiltInputMainIn_Table_arr.length; j++){
//			System.out.printf("********************************************** \n");
//			System.out.printf("=============== InputPower# %s =============== \n",j+1);
//			System.out.printf("********************************************** \n");
//			PowerDerating.RunPowerDeratingAlgorithm(PowerDerating_Cfg.Default_VoltFiltInputMainIn_Table_arr[j]);
//		}
//		
//		System.out.printf("********************************************** \n");
//		System.out.printf("Calculations Accuracy = 1/%s \n", RoundFactor);
//		System.out.printf("********************************************** \n");
		
	}

	public static void RunPowerDeratingAlgorithm(double[] VoltFiltInputMainIn) { //
		
		Init_DefaultValues();

		Apply_PwrDerating(VoltFiltInputMainIn);
		
	}

	public static void Init_DefaultValues() {
	
		int Index;
				
		BoolTransition_arr					= new boolean[BoolPwrNeedsActivationStatus_arr.length];
		BoolTransitionFalse_arr				= new boolean[BoolPwrNeedsActivationStatus_arr.length];
		
		PwrAvailEfficiencyVal_arr			= new double[PwrAvailCurSteady_arr.length];
		PwrAvailVal_arr						= new double[PwrAvailCurSteady_arr.length];
	
		PwrNeedVal_arr						= new double[PwrNeedVoltVal_arr.length];
			
		PwrMaxVal_arr						= new double[PwrNeedVoltVal_arr.length];
	
		PwrApplyVal_arr						= new double[PwrNeedVoltVal_arr.length];
	
		PwrApplyVal_Prev_arr				= new double[PwrNeedVoltVal_arr.length];
	
		PwrProtecVal_arr					= new double[PwrNeedVoltVal_arr.length];
	
		CurBinVal_arr						= new double[PwrNeedVoltVal_arr.length];
	
		CurRefTargetVal_arr					= new double[PwrNeedVoltVal_arr.length];
	
		CurPwrDeratVal_arr					= new double[PwrNeedVoltVal_arr.length];
	
		PwrErrorShareVal_arr				= new double[PwrNeedVoltVal_arr.length];
	
		PerSharingPercent_arr				= new double[PwrNeedVoltVal_arr.length];
		
		Calc_PwrMaxVal();
		Calc_PerSharingPercent();
		
		for(Index = 0; Index < CurBinNbrVal_arr.length; Index++){
			CurRefTargetVal_arr[Index] 		= CurBinVal_arr[Index];
			CurPwrDeratVal_arr[Index] 		= Config_PwrDefaultValn;
			PwrProtecVal_arr[Index]			= Config_PwrDefaultValn;
		}
		
		for(Index = 0; Index < PwrAvailCurSteady_arr.length; Index++){
			PwrAvailVal_arr[Index] 			= Config_PwrDefaultValn;
		}
		
		for(Index = 0; Index < PwrNeedVoltVal_arr.length; Index++){
			PwrNeedVal_arr[Index] 			= Config_PwrDefaultValn;
			PwrMaxVal_arr[Index] 			= Config_PwrDefaultValn;
			PwrApplyVal_arr[Index] 			= Config_PwrDefaultValn;
			PwrApplyVal_Prev_arr[Index] 	= Config_PwrDefaultValn;
			PwrErrorShareVal_arr[Index] 	= Config_PwrDefaultValn;
			BoolTransition_arr[Index]		= BoolPwrNeedsActivationStatus_arr[Index];
			BoolTransitionFalse_arr[Index]	= false;
		}
		
		PwrAvailTot 						= Config_PwrDefaultValn;
		PwrNeedsTot 						= Config_PwrDefaultValn;
		PwrError 							= Config_PwrDefaultValn;
	
	}

	public static void Apply_PwrDerating(double[] VoltFiltInputMainIn)
	{
		double 	PwrError_Log[]	= new double[PwrErrorLog_Length];					// Watt
		int Iteration_index = 0;
		int Log_index = 0;
		boolean Stop_Flag = false;
		
		VoltFiltInputMainIn_arr = new double[VoltFiltInputMainIn.length];
		
		for(int Index = 0; Index < PwrErrorLog_Length; Index++){
			PwrError_Log[Index] = 0;
		}
		
		System.out.printf("========== Iteration: ( %s ) ========== \n", Iteration_index);
		for(int Index = 0; Index < VoltFiltInputMainIn_arr.length; Index++){
			VoltFiltInputMainIn_arr[Index] 			= VoltFiltInputMainIn[Index];
			System.out.printf("VoltFiltInputMainIn_arr[%s] = %s\n", Index, VoltFiltInputMainIn_arr[Index]);
		}
		System.out.printf("PwrAvailTot = %s\n", PwrAvailTot);
		System.out.printf("PwrNeedsTot = %s\n", PwrNeedsTot);

		Calc_CurPwrDeratVal(BoolTransition_arr);

		while(Stop_Flag == false){
			
			Iteration_index++;
			
			System.out.printf("========== Iteration: ( %s ) ========== \n", Iteration_index);
			for(int Index = 0; Index < VoltFiltInputMainIn_arr.length; Index++){
				System.out.printf("VoltFiltInputMainIn_arr[%s] = %s\n", Index, VoltFiltInputMainIn_arr[Index]);
			}
			
			Calc_PwrAvailTot();
			Calc_PwrNeedsTot();
			
			Calc_CurPwrDeratVal(BoolTransitionFalse_arr);
			
			Calc_CurRefTargetVal();
			
			PwrError_Log[Log_index] = PwrError;
			Log_index++;
			if(Log_index >= PwrErrorLog_Length){
				Log_index = 0;
			}
			
			if(Iteration_index >= MaxNumOfIterations){
				System.out.printf("################################################## \n");
				System.out.printf("# Maximum Number of Iterations ( %s ) reached ! # \n", MaxNumOfIterations);
				System.out.printf("################################################## \n");
				Stop_Flag = true;
			}
			else if((Iteration_index-1) >= PwrErrorLog_Length){
				int Temp_counter = 0;
				while(PwrError_Log[Temp_counter] == PwrError_Log[Temp_counter+1]){
					Temp_counter++;
					if((Temp_counter+1) >= PwrErrorLog_Length){
						Temp_counter = 0;
						Stop_Flag = true;
						break;
					}
				}
			}
			else{
				Stop_Flag = false;
			}
		}
	}

	public static void Calc_PwrNeed()
	{
		int Index;
		
		for(Index = 0; Index < PwrNeedVal_arr.length; Index++){
			if(BoolPwrNeedsActivationStatus_arr[Index] == true){
				switch(PwrNeedCalcEfficiencyType){
					case Multiplied:
						PwrNeedVal_arr[Index] = CurRefTargetVal_arr[Index] * PwrNeedVoltVal_arr[Index] * PwrNeedEfficiencyVal_arr[Index] / 100;			//Watt
					break;
					case Divided:
						PwrNeedVal_arr[Index] = CurRefTargetVal_arr[Index] * PwrNeedVoltVal_arr[Index] * 100 / PwrNeedEfficiencyVal_arr[Index];			//Watt
					break;
					case Neutral:
						PwrNeedVal_arr[Index] = CurRefTargetVal_arr[Index] * PwrNeedVoltVal_arr[Index];			//Watt
					break;
					default:
					break;
				}
			}
			else{
				PwrNeedVal_arr[Index] = 0;
			}
			/* ***** Rounding double according to RoundFactor **** */
			PwrNeedVal_arr[Index] = ((double)Math.round(PwrNeedVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			System.out.printf("PwrNeedVal_arr[%s] = %s\n", Index, PwrNeedVal_arr[Index]);
		}
	}

	public static void Calc_PwrAvail()
	{
		int Index;
		
		for(int j = 0; j < VoltFiltInputMainIn_arr.length; j++){
			for(int i = 0; i < PwrAvailEfficiencyValTable_arr[j].length; i++){
				if((VoltFiltInputMainIn_arr[j] >= PwrAvailEfficiencyVoltTable_arr[j][i])){
					PwrAvailEfficiencyVal_arr[j] = PwrAvailEfficiencyValTable_arr[j][i];
				}
			}
		}
		for(Index = 0; Index < PwrAvailCurSteady_arr.length; Index++){
			switch(PwrAvailCalcEfficiencyType){
				case Multiplied:
					PwrAvailVal_arr[Index] = PwrAvailCurSteady_arr[Index] * VoltFiltInputMainIn_arr[Index] * PwrAvailEfficiencyVal_arr[Index] / 100;			//Watt
				break;
				case Divided:
					PwrAvailVal_arr[Index] = PwrAvailCurSteady_arr[Index] * VoltFiltInputMainIn_arr[Index] * 100 / PwrAvailEfficiencyVal_arr[Index];			//Watt
				break;
				case Neutral:
					PwrAvailVal_arr[Index] = PwrAvailCurSteady_arr[Index] * VoltFiltInputMainIn_arr[Index];			//Watt
				break;
				default:
				break;
			}
			/* ***** Rounding double according to RoundFactor **** */
			PwrAvailVal_arr[Index] = ((double)Math.round(PwrAvailVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			System.out.printf("PwrAvailVal_arr[%s] = %s\n", Index, PwrAvailVal_arr[Index]);
		}
	}

	public static void Calc_PwrNeedsTot()
	{
		int Index;
		PwrNeedsTot = 0;
		
		Calc_PwrNeed();
		
		for(Index = 0; Index < PwrNeedVal_arr.length; Index++){
			PwrNeedsTot = PwrNeedsTot + PwrNeedVal_arr[Index];
		}
		/* ***** Rounding double according to RoundFactor **** */
		PwrNeedsTot = ((double)Math.round(PwrNeedsTot * RoundFactor)) / RoundFactor;
		/* *************************************************** */
		System.out.printf("PwrNeedsTot = %s\n", PwrNeedsTot);
	}

	public static void Calc_PwrAvailTot()
	{
		int Index;
		PwrAvailTot = 0;
		
		Calc_PwrAvail();
		
		for(Index = 0; Index < PwrAvailVal_arr.length; Index++){
			PwrAvailTot = PwrAvailTot + PwrAvailVal_arr[Index];
		}
		/* ***** Rounding double according to RoundFactor **** */
		PwrAvailTot = ((double)Math.round(PwrAvailTot * RoundFactor)) / RoundFactor;
		/* *************************************************** */
		System.out.printf("PwrAvailTot = %s\n", PwrAvailTot);
	}
	
	public static void Calc_PerSharingPercent() {
		int Index;
		PerSharingTot = 0;
		
		for(Index = 0; Index < Config_SharingCoeff_arr.length; Index++){
			if(BoolPwrNeedsActivationStatus_arr[Index] == true){
				PerSharingTot = PerSharingTot + Config_SharingCoeff_arr[Index];
			}
		}
		/* ***** Rounding double according to RoundFactor **** */
		PerSharingTot = ((double)Math.round(PerSharingTot * RoundFactor)) / RoundFactor;
		/* *************************************************** */

		for(Index = 0; Index < Config_SharingCoeff_arr.length; Index++){
			if(BoolPwrNeedsActivationStatus_arr[Index] == true){
				PerSharingPercent_arr[Index] = Config_SharingCoeff_arr[Index] / PerSharingTot;
			}
			else{
				PerSharingPercent_arr[Index] = 0;
			}
			/* ***** Rounding double according to RoundFactor **** */
			PerSharingPercent_arr[Index] = ((double)Math.round(PerSharingPercent_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
		}
	}
	
	public static void Calc_PwrError()
	{
		int Index;
		
		PwrError = Config_CoeffPropn * (PwrAvailTot - PwrNeedsTot);
		/* ***** Rounding double according to RoundFactor **** */
		PwrError = ((double)Math.round(PwrError * RoundFactor)) / RoundFactor;
		/* *************************************************** */
		System.out.printf("PwrError = %s\n", PwrError);
		for(Index = 0; Index < PwrErrorShareVal_arr.length; Index++){
			PwrErrorShareVal_arr[Index] = PwrError * PerSharingPercent_arr[Index];
			/* ***** Rounding double according to RoundFactor **** */
			PwrErrorShareVal_arr[Index] = ((double)Math.round(PwrErrorShareVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			System.out.printf("PwrErrorShareVal_arr[%s] = %s\n", Index, PwrErrorShareVal_arr[Index]);
		}
	}

	public static void Calc_CurBinVal()
	{
		int Index;
		
		for(Index = 0; Index < CurBinNbrVal_arr.length; Index++){
			CurBinVal_arr[Index] = CurBinTable_arr[Index][CurBinNbrVal_arr[Index]-1];
			/* ***** Rounding double according to RoundFactor **** */
			CurBinVal_arr[Index] = ((double)Math.round(CurBinVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
		}
	}

	public static void Calc_PwrMaxVal()
	{
		int Index;

		Calc_CurBinVal();

		for(Index = 0; Index < PwrMaxVoltVal_arr.length; Index++){
			switch(PwrMaxCalcEfficiencyType){
				case Multiplied:
					PwrMaxVal_arr[Index] = CurBinVal_arr[Index] * PwrMaxVoltVal_arr[Index] * PwrMaxEfficiencyVal_arr[Index] / 100;			//Watt
				break;
				case Divided:
					PwrMaxVal_arr[Index] = CurBinVal_arr[Index] * PwrMaxVoltVal_arr[Index] * 100 / PwrMaxEfficiencyVal_arr[Index];			//Watt
				break;
				case Neutral:
					PwrMaxVal_arr[Index] = CurBinVal_arr[Index] * PwrMaxVoltVal_arr[Index];			//Watt
				break;
				default:
				break;
			}
			/* ***** Rounding double according to RoundFactor **** */
			PwrMaxVal_arr[Index] = ((double)Math.round(PwrMaxVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			System.out.printf("PwrMaxVal_arr[%s] = %s\n", Index, PwrMaxVal_arr[Index]);
		}


	}

	public static void Calc_PwrApplyVal(boolean BoolTransition_arr[])
	{
		int Index;
		
		Calc_PwrMaxVal();
		Calc_PwrError();
		
		for(Index = 0; Index < PwrNeedVoltVal_arr.length; Index++){
			if(BoolPwrNeedsActivationStatus_arr[Index] == false){
				PwrApplyVal_arr[Index] = 0;
			}
			else{
				if(BoolTransition_arr[Index] == true){
					PwrApplyVal_arr[Index] = PwrMaxVal_arr[Index];
				}
				else{
					PwrApplyVal_arr[Index] = PwrApplyVal_Prev_arr[Index] + PwrErrorShareVal_arr[Index];
				}
			}
			if(PwrApplyVal_arr[Index] > PwrMaxVal_arr[Index]){
				PwrApplyVal_arr[Index] = PwrMaxVal_arr[Index];
			}
			else if(PwrApplyVal_arr[Index] < Config_PwrMinVal_arr[Index]){
				PwrApplyVal_arr[Index] = Config_PwrMinVal_arr[Index];
			}
			/* ***** Rounding double according to RoundFactor **** */
			PwrApplyVal_arr[Index] = ((double)Math.round(PwrApplyVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			PwrApplyVal_Prev_arr[Index] = PwrApplyVal_arr[Index];
			/* ***** Rounding double according to RoundFactor **** */
			PwrApplyVal_Prev_arr[Index] = ((double)Math.round(PwrApplyVal_Prev_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			System.out.printf("PwrApplyVal_arr[%s] = %s\n", Index, PwrApplyVal_arr[Index]);
		}

	}

	public static void Calc_PwrProtecVal(boolean BoolTransition_arr[])
	{
		int Index;

		Calc_PwrApplyVal(BoolTransition_arr);

		for(Index = 0; Index < PwrApplyVal_arr.length; Index++){
			PwrProtecVal_arr[Index] = PwrApplyVal_arr[Index];
			/* ***** Rounding double according to RoundFactor **** */
			PwrProtecVal_arr[Index] = ((double)Math.round(PwrProtecVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			System.out.printf("PwrProtecVal_arr[%s] = %s\n", Index, PwrProtecVal_arr[Index]);
		}
	}

	public static void Calc_CurPwrDeratVal(boolean BoolTransition_arr[])
	{
		int Index;
		Calc_PwrProtecVal(BoolTransition_arr);
		for(Index = 0; Index < PwrProtecVal_arr.length; Index++){
			if(BoolPwrNeedsActivationStatus_arr[Index] == true){
				switch(CurDerCalcEfficiencyType){
					case Multiplied:
						CurPwrDeratVal_arr[Index] = (PwrProtecVal_arr[Index] / PwrNeedVoltVal_arr[Index]) * CurDerEfficiencyVal_arr[Index] / 100;
					break;
					case Divided:
						CurPwrDeratVal_arr[Index] = (PwrProtecVal_arr[Index] / PwrNeedVoltVal_arr[Index]) * 100 / CurDerEfficiencyVal_arr[Index];
					break;
					case Neutral:
						CurPwrDeratVal_arr[Index] = (PwrProtecVal_arr[Index] / PwrNeedVoltVal_arr[Index]);
					break;
					default:
					break;
				}
				
			}
			else{
				CurPwrDeratVal_arr[Index] = 0;
			}
			/* ***** Rounding double according to RoundFactor **** */
			CurPwrDeratVal_arr[Index] = ((double)Math.round(CurPwrDeratVal_arr[Index] * RoundFactor)) / RoundFactor;
			/* *************************************************** */
			System.out.printf("CurPwrDeratVal_arr[%s] = %s\n", Index, CurPwrDeratVal_arr[Index]);
		}
	}

	public static void Calc_CurRefTargetVal()
	{
		int Index;
		
		for(Index = 0; Index < CurRefTargetVal_arr.length; Index++){
				if(CurPwrDeratVal_arr[Index] > CurBinVal_arr[Index]){
					CurRefTargetVal_arr[Index] = CurBinVal_arr[Index];
				}
				else{
					CurRefTargetVal_arr[Index] = CurPwrDeratVal_arr[Index];
				}
				/* ***** Rounding double according to RoundFactor **** */
				CurRefTargetVal_arr[Index] = ((double)Math.round(CurRefTargetVal_arr[Index] * RoundFactor)) / RoundFactor;
				/* *************************************************** */
				System.out.printf("CurRefTargetVal_arr[%s] = %s\n", Index, CurRefTargetVal_arr[Index]);
		}
	}
	
}
