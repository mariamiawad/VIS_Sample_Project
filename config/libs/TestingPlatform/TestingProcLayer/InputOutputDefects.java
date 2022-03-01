package libs.TestingPlatform.TestingProcLayer;

import config.ETS;
import config.ItfDefectCell.EnmCellState;
import config.ItfDefectCell.EnmDefectCellChannel;
import config.ItfDefectCell.EnmSupply;
import config.ItfPowerControl.EnmPowerInputChannel;
import config.ItfPowerControl.EnmPowerSource;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager;
import libs.TestingPlatform.CastleCommlayer.CastlePowerOutputPort.PowerSupplyID;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;
import libs.TestingPlatform.TestingTechLayer.TestingTechManager;
/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 12:38:39 PM
 */
public class InputOutputDefects {
	
	private static double NO_VAL =-1.0; 
	private TestingTechManager testingTechMGR = new TestingTechManager();
	private double[] outputArrays = {0.0};

	/**
	 * Run OverVoltage Defect Detection (Validation and Devalidation).
	 * @param oV_Threshold
	 * @param oV_Hysteresis
	 * @param validationTime
	 * @param deValidationTime
	 * @param castlePorting
	 * @param executionUnit
	 * @param expectedOutputs_After_threshold
	 * @param expectedOutputs_Normal
	 */
	public void OverVoltageValidation_Devalidation(double oV_Threshold, double oV_Hysteresis, double validationTime, double deValidationTime, CastlePortingMap castlePorting, ETS executionUnit, double[] expectedOutputs_After_threshold, double[] expectedOutputs_Normal)
	{
		String[] OV_ValidationDevalidation_Description = new String[] {
				"1-Set Input Voltage to the nominal value and expect ECU to be On",
				"2-Set Input Voltage to the hysterisis value and expect the ECU to be On",
				"3-Set Input Voltage to less than Threshold value and expect the ECU to be On",
				"4-Set Input Voltage to greater than Threshold value and expect the ECU to be Off",
				"5-Set Input Voltage to less than Threshold value and expect the ECU to be Off",
				"6-Set Input Voltage to less than hysterisis value and expect the ECU to be On",
				"7-Set Input Voltage to the nominal value and expect ECU to be On",
				};
			DecisonTableEntryValue[] OV_ValidationDevalidationDT = new DecisonTableEntryValue[] {
				/***************************************************************nominal***********************************/			
				new DecisonTableEntryValue(OV_ValidationDevalidation_Description[0],new double[]{	13.5 					},null,	validationTime,    10.0 ,	expectedOutputs_Normal, 5000.0),
				/***************************************************************Validation********************************/			
				new DecisonTableEntryValue(OV_ValidationDevalidation_Description[1],new double[]{oV_Hysteresis     			},null,	validationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
				new DecisonTableEntryValue(OV_ValidationDevalidation_Description[2],new double[]{oV_Threshold - 0.5			},null,	validationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
				new DecisonTableEntryValue(OV_ValidationDevalidation_Description[3],new double[]{oV_Threshold + 0.5			},null,	validationTime,    10.0,	expectedOutputs_After_threshold,	5000.0),
				/************************************************************Devalidation**********************************/
				new DecisonTableEntryValue(OV_ValidationDevalidation_Description[4],new double[]{oV_Threshold - 0.5			},null,	deValidationTime,    10.0 ,	expectedOutputs_After_threshold,	5000.0),
				new DecisonTableEntryValue(OV_ValidationDevalidation_Description[5],new double[]{oV_Hysteresis- 0.5			},null,	deValidationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
				new DecisonTableEntryValue(OV_ValidationDevalidation_Description[6],new double[]{13.5						},null,	deValidationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
					};
			
			testingTechMGR.RunDT(OV_ValidationDevalidationDT, castlePorting, executionUnit);
	}
	
	
	/**
	 * Run UnderVoltage Defect Detection (Validation and Devalidation).
	 * @param oV_Threshold
	 * @param oV_Hysteresis
	 * @param validationTime
	 * @param deValidationTime
	 * @param castlePorting
	 * @param executionUnit
	 * @param expectedOutputs_Before_threshold
	 * @param expectedOutputs_Normal
	 */
	public void UnderVoltageValidation_Devalidation(double uV_Threshold, double uV_Hysteresis, double validationTime, double deValidationTime, CastlePortingMap castlePorting, ETS executionUnit, double[] expectedOutputs_After_threshold, double[] expectedOutputs_Normal)
	{
		String [] UV_ValidationDevalidation_Description = new String[] {
				"1-Set Input Voltage to the nominal value and expect ECU to be On",
				"2-Set Input Voltage to the hysterisis value and expect the ECU to be On",
				"3-Set Input Voltage to greater than Threshold value and expect the ECU to be On",
				"4-Set Input Voltage to less than Threshold value and expect the ECU to be Off",
				"5-Set Input Voltage to greater than Threshold value and expect the ECU to be Off",
				"6-Set Input Voltage to greater than hysterisis value and expect the ECU to be On",
				"7-Set Input Voltage to the nominal value and expect ECU to be On",
				};
			DecisonTableEntryValue[] UV_ValidationDevalidationDT = new DecisonTableEntryValue[] {
					/***************************************************************nominal***********************************/			
					new DecisonTableEntryValue(UV_ValidationDevalidation_Description[0],new double[]{	13.5 					},null,	validationTime,    10.0 ,	expectedOutputs_Normal, 5000.0),
					/***************************************************************Validation********************************/			
					new DecisonTableEntryValue(UV_ValidationDevalidation_Description[1],new double[]{uV_Hysteresis     			},null,	validationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
					new DecisonTableEntryValue(UV_ValidationDevalidation_Description[2],new double[]{uV_Threshold + 0.5			},null,	validationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
					new DecisonTableEntryValue(UV_ValidationDevalidation_Description[3],new double[]{uV_Threshold - 0.5			},null,	validationTime,    10.0 ,	expectedOutputs_After_threshold,	5000.0),
					/************************************************************Devalidation**********************************/
					new DecisonTableEntryValue(UV_ValidationDevalidation_Description[4],new double[]{uV_Threshold + 0.5			},null,	deValidationTime,    10.0 ,	expectedOutputs_After_threshold,	5000.0),
					new DecisonTableEntryValue(UV_ValidationDevalidation_Description[5],new double[]{uV_Hysteresis+ 0.5			},null,	deValidationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
					new DecisonTableEntryValue(UV_ValidationDevalidation_Description[6],new double[]{13.5						},null,	deValidationTime,    10.0 ,	expectedOutputs_Normal,	5000.0),
						};
			testingTechMGR.RunDT(UV_ValidationDevalidationDT, castlePorting, executionUnit);
	}
	
	/**
	 * Run Open Circuit Defect Detection (Reversable).
	 * @param uV_Threshold
	 * @param oV_Threshold
	 * @param powerChnl
	 * @param powerCurrentLimit
	 * @param defectChnl
	 * @param validationTime
	 * @param outputCastlePorting
	 * @param executionUnit
	 * @param expectedOpenCircuitOutputs
	 * @param expectedNormalOutput
	 */
	public void OC_Defect_Validation_Reversable(double uV_Threshold, double oV_Threshold, Object powerChnl, double powerCurrentLimit, Object defectChnl, double validationTime, CastlePortingMap outputCastlePorting, ETS executionUnit, double[] expectedOpenCircuitOutputs, double[] expectedNormalOutput)
	{
		CastlePortingMap PORTMAP = new CastlePortingMap();
		CastlePortingMap PORTMAP_DT = new CastlePortingMap();
		CastleCommManager commMgr = new CastleCommManager();
		PORTMAP.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[]{
				commMgr.getPort((EnmPowerInputChannel)powerChnl, PowerSupplyID.S1, EnmPowerSource.PowerSupply1_DC, powerCurrentLimit, executionUnit),
				commMgr.getPort((EnmDefectCellChannel)defectChnl,EnmCellState.OC_ECUA_LoadA, EnmSupply.S1, executionUnit)
		};
		PORTMAP_DT.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[PORTMAP.castlePortingArr.length + outputCastlePorting.castlePortingArr.length];
		System.arraycopy(PORTMAP.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, 0, PORTMAP.castlePortingArr.length);
		System.arraycopy(outputCastlePorting.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, PORTMAP.castlePortingArr.length, outputCastlePorting.castlePortingArr.length);
		
		for(int outputIndex = 0; outputIndex < expectedNormalOutput.length; outputIndex++)
			outputArrays[outputIndex] = 0.0;
		
		String [] OC_Validation_Description = new String[] {
				"1-Set Input Voltage to the nominal values and expect ECU to be On",
				"2-Apply Open Circuit voltage and expect the corresponding output is Off with Normal Voltage",
				"3-Expect the Open Circuit output after certain time",
				"4-Remove Open Circuit Defect and expect All outputs are OFF with over voltage",
				"5-Apply Open Circuit voltage and expect All outputs are OFF with over voltage",
				"6-Expect the outputs are Off after certain time",
				"7-Apply Nominal voltage and expect All outputs are On",
				"8-Expect the Normal output after certain time",
				"9-Apply Normal voltage and expect All outputs are OFF with under voltage",
				"10-Apply Open Circuit voltage and expect All outputs are OFF with under voltage",
				"11-Expect the outputs are Off after certain time",
				"12-Return to apply Nominal voltage and expect All outputs are On"
				};
			DecisonTableEntryValue[] OC_ValidationDevalidationDT = new DecisonTableEntryValue[] {
					/***************************************************************nominal******************************************************/			
					new DecisonTableEntryValue(OC_Validation_Description[0],new double[]{13.5, 					0	},null,	1000,     10.0,	expectedNormalOutput, 1000.0),
					new DecisonTableEntryValue(OC_Validation_Description[1],new double[]{13.5,					1	},null,	validationTime,	    0.2*validationTime,	expectedOpenCircuitOutputs,	2000),
					new DecisonTableEntryValue(OC_Validation_Description[2],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	1000),
					/***************************************************************OpenCircuit with Over Voltage********************************/			
					new DecisonTableEntryValue(OC_Validation_Description[3],new double[]{oV_Threshold + 0.5,	0	},null,	validationTime,		10.0,	outputArrays,	2000), 	
					new DecisonTableEntryValue(OC_Validation_Description[4],new double[]{oV_Threshold + 0.5,	1	},null,	validationTime,		10.0,	outputArrays,	1000),
					new DecisonTableEntryValue(OC_Validation_Description[5],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	outputArrays,	2000),	
					new DecisonTableEntryValue(OC_Validation_Description[6],new double[]{13.50,					0	},null,	validationTime,		10.0,	expectedNormalOutput,	3000),
					/***************************************************************OpenCircuit with Under Voltage********************************/
					new DecisonTableEntryValue(OC_Validation_Description[7],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedNormalOutput,	1000),
					new DecisonTableEntryValue(OC_Validation_Description[8],new double[]{uV_Threshold - 0.5,	0	},null,	validationTime,		10.0,	outputArrays,	2000), 	
					new DecisonTableEntryValue(OC_Validation_Description[9],new double[]{uV_Threshold - 0.5,	1	},null,	validationTime,		10.0,	outputArrays,	1000),
					new DecisonTableEntryValue(OC_Validation_Description[10],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	outputArrays,	2000),	
					new DecisonTableEntryValue(OC_Validation_Description[11],new double[]{13.50,				0	},null,	validationTime,		10.0,	expectedNormalOutput,	3000)
						};
			testingTechMGR.RunDT(OC_ValidationDevalidationDT, PORTMAP_DT, executionUnit);
	}
	
	/**
	 * Run Open Circuit Defect Detection (IrReversable).
	 * @param uV_Threshold
	 * @param oV_Threshold
	 * @param powerChnl
	 * @param powerCurrentLimit
	 * @param defectChnl
	 * @param validationTime
	 * @param outputCastlePorting
	 * @param executionUnit
	 * @param expectedOpenCircuitOutputs
	 * @param expectedNormalOutput
	 */
	public void OC_Defect_Validation_IrReversable(double uV_Threshold, double oV_Threshold, Object powerChnl, double powerCurrentLimit, Object defectChnl, double validationTime, CastlePortingMap outputCastlePorting, ETS executionUnit, double[] expectedOpenCircuitOutputs, double[] expectedNormalOutput)
	{
		CastlePortingMap PORTMAP = new CastlePortingMap();
		CastlePortingMap PORTMAP_DT = new CastlePortingMap();
		CastleCommManager commMgr = new CastleCommManager();
		PORTMAP.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[]{
				commMgr.getPort((EnmPowerInputChannel)powerChnl, PowerSupplyID.S1, EnmPowerSource.PowerSupply1_DC, powerCurrentLimit, executionUnit),
				commMgr.getPort((EnmDefectCellChannel)defectChnl,EnmCellState.OC_ECUA_LoadA, EnmSupply.S1, executionUnit)
		};
		PORTMAP_DT.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[PORTMAP.castlePortingArr.length + outputCastlePorting.castlePortingArr.length];
		System.arraycopy(PORTMAP.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, 0, PORTMAP.castlePortingArr.length);
		System.arraycopy(outputCastlePorting.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, PORTMAP.castlePortingArr.length, outputCastlePorting.castlePortingArr.length);
		
		String [] OC_Validation_Description = new String[] {
				"1-Set Input Voltage to the nominal values and expect ECU to be On",
				"2-Apply Open Circuit voltage and expect the corresponding output is Off with Normal Voltage",
				"3-Expect the Open Circuit output after certain time",
				"4-Remove Open Circuit Defect and expect All outputs are OFF with over voltage",
				"5-Apply Open Circuit voltage and expect All outputs are OFF with over voltage",
				"6-Expect the outputs are Off after certain time",
				"7-Apply Nominal voltage and expect All outputs are still Off as it's irrevesable defect",
				"8-Expect the Normal output after certain time",
				"9-Apply Normal voltage and expect All outputs are OFF with under voltage",
				"10-Apply Open Circuit voltage and expect All outputs are OFF with under voltage",
				"11-Expect the outputs are Off after certain time",
				"12-Return to apply Nominal voltage and expect All outputs are still Off as it's irrevesable defect"
				};
			DecisonTableEntryValue[] OC_ValidationDevalidationDT = new DecisonTableEntryValue[] {
					/***************************************************************nominal******************************************************/			
					new DecisonTableEntryValue(OC_Validation_Description[0],new double[]{13.5, 					0	},null,	1000,     10.0,	expectedNormalOutput, 1000.0),
					new DecisonTableEntryValue(OC_Validation_Description[1],new double[]{13.5,					1	},null,	validationTime,	    0.2*validationTime,	expectedOpenCircuitOutputs,	2000),
					new DecisonTableEntryValue(OC_Validation_Description[2],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	1000),
					/***************************************************************OpenCircuit with Over Voltage********************************/			
					new DecisonTableEntryValue(OC_Validation_Description[3],new double[]{oV_Threshold + 0.5,	0	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	2000), 	
					new DecisonTableEntryValue(OC_Validation_Description[4],new double[]{oV_Threshold + 0.5,	1	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	1000),
					new DecisonTableEntryValue(OC_Validation_Description[5],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	2000),	
					new DecisonTableEntryValue(OC_Validation_Description[6],new double[]{13.50,					0	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	3000),
					/***************************************************************OpenCircuit with Under Voltage********************************/
					new DecisonTableEntryValue(OC_Validation_Description[7],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	1000),
					new DecisonTableEntryValue(OC_Validation_Description[8],new double[]{uV_Threshold - 0.5,	0	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	2000), 	
					new DecisonTableEntryValue(OC_Validation_Description[9],new double[]{uV_Threshold - 0.5,	1	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	1000),
					new DecisonTableEntryValue(OC_Validation_Description[10],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	2000),	
					new DecisonTableEntryValue(OC_Validation_Description[11],new double[]{13.50,				0	},null,	validationTime,		10.0,	expectedOpenCircuitOutputs,	3000)
						};
			testingTechMGR.RunDT(OC_ValidationDevalidationDT, PORTMAP_DT, executionUnit);
	}
	
	/**
	 * Run Short Circuit Defect Detection (Reversable).
	 * @param uV_Threshold
	 * @param oV_Threshold
	 * @param powerChnl
	 * @param powerCurrentLimit
	 * @param defectChnl
	 * @param validationTime
	 * @param outputCastlePorting
	 * @param executionUnit
	 * @param expectedShortCircuitOutputs
	 * @param expectedNormalOutput
	 */
	public void SC_Defect_Validation_Reversable(double uV_Threshold, double oV_Threshold, Object powerChnl, double powerCurrentLimit, Object defectChnl, double validationTime, CastlePortingMap outputCastlePorting, ETS executionUnit, double[] expectedShortCircuitOutputs, double[] expectedNormalOutput)
	{	
		CastlePortingMap PORTMAP = new CastlePortingMap();
		CastlePortingMap PORTMAP_DT = new CastlePortingMap();
		CastleCommManager commMgr = new CastleCommManager();
		PORTMAP.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[]{
				commMgr.getPort((EnmPowerInputChannel)powerChnl, PowerSupplyID.S1, EnmPowerSource.PowerSupply1_DC, powerCurrentLimit, executionUnit),
		};
		PORTMAP_DT.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[PORTMAP.castlePortingArr.length + outputCastlePorting.castlePortingArr.length];
		System.arraycopy(PORTMAP.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, 0, PORTMAP.castlePortingArr.length);
		System.arraycopy(outputCastlePorting.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, PORTMAP.castlePortingArr.length, outputCastlePorting.castlePortingArr.length);
		
		for(int outputIndex = 0; outputIndex < expectedNormalOutput.length; outputIndex++)
			outputArrays[outputIndex] = 0.0;
		
		String [] SC_Validation_Description = new String[] {
				"1-Set Input Voltage to the nominal values and expect ECU to be On",
				"2-Apply Short Circuit voltage and expect the corresponding output is Off with Normal Voltage",
				"3-Expect the Short Circuit output after certain time",
				"4-Apply Normal voltage and expect All outputs are OFF with over voltage",
				"5-Apply Short Circuit voltage and expect All outputs are OFF with over voltage",
				"6-Expect the outputs are Off after certain time",
				"7-Return to apply Nominal voltage and expect All outputs are On",
				"8-Expect the Normal output after certain tim",
				"9-Apply Normal voltage and expect All outputs are OFF with under voltage",
				"10-Apply Short Circuit voltage and expect All outputs are OFF with under voltage",
				"11-Expect the outputs are Off after certain time",
				"12-Return to apply Nominal voltage and expect All outputs are On"
				};
			DecisonTableEntryValue[] SC_ValidationDevalidationDT = new DecisonTableEntryValue[] {		
					/***************************************************************nominal******************************************************/			
					new DecisonTableEntryValue(SC_Validation_Description[0],new double[]{13.5, 					0	},null,	1000,     10.0,	expectedNormalOutput, 1000.0),
					new DecisonTableEntryValue(SC_Validation_Description[1],new double[]{13.5,					1	},null,	validationTime,	    0.2*validationTime,	expectedShortCircuitOutputs,	2000),
					new DecisonTableEntryValue(SC_Validation_Description[2],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	1000),
					/***************************************************************OpenCircuit with Over Voltage********************************/			
					new DecisonTableEntryValue(SC_Validation_Description[3],new double[]{oV_Threshold + 0.5,	0	},null,	validationTime,		10.0,	outputArrays,	2000), 	
					new DecisonTableEntryValue(SC_Validation_Description[4],new double[]{oV_Threshold + 0.5,	1	},null,	validationTime,		10.0,	outputArrays,	1000),
					new DecisonTableEntryValue(SC_Validation_Description[5],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	outputArrays,	2000),	
					new DecisonTableEntryValue(SC_Validation_Description[6],new double[]{13.50,					0	},null,	validationTime,		10.0,	expectedNormalOutput,	3000),
					/***************************************************************OpenCircuit with Under Voltage********************************/
					new DecisonTableEntryValue(SC_Validation_Description[7],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedNormalOutput,	1000),
					new DecisonTableEntryValue(SC_Validation_Description[8],new double[]{uV_Threshold - 0.5,	0	},null,	validationTime,		10.0,	outputArrays,	2000), 	
					new DecisonTableEntryValue(SC_Validation_Description[9],new double[]{uV_Threshold - 0.5,	1	},null,	validationTime,		10.0,	outputArrays,	1000),
					new DecisonTableEntryValue(SC_Validation_Description[10],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	outputArrays,	2000),	
					new DecisonTableEntryValue(SC_Validation_Description[11],new double[]{13.50,				0	},null,	validationTime,		10.0,	expectedNormalOutput,	3000)
						};
			testingTechMGR.RunDT(SC_ValidationDevalidationDT, PORTMAP_DT, executionUnit);
	}
	
	/**
	 * Run Short Circuit Defect Detection (IrReversable).
	 * @param uV_Threshold
	 * @param oV_Threshold
	 * @param powerChnl
	 * @param powerCurrentLimit
	 * @param defectChnl
	 * @param validationTime
	 * @param outputCastlePorting
	 * @param executionUnit
	 * @param expectedShortCircuitOutputs
	 * @param expectedNormalOutput
	 */
	public void SC_Defect_Validation_IrReversable(double uV_Threshold, double oV_Threshold, Object powerChnl, double powerCurrentLimit, Object defectChnl, double validationTime, CastlePortingMap outputCastlePorting, ETS executionUnit, double[] expectedShortCircuitOutputs, double[] expectedNormalOutput)
	{	
		CastlePortingMap PORTMAP = new CastlePortingMap();
		CastlePortingMap PORTMAP_DT = new CastlePortingMap();
		CastleCommManager commMgr = new CastleCommManager();
		PORTMAP.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[]{
				commMgr.getPort((EnmPowerInputChannel)powerChnl, PowerSupplyID.S1, EnmPowerSource.PowerSupply1_DC, powerCurrentLimit, executionUnit),
		};
		PORTMAP_DT.castlePortingArr = new libs.TestingPlatform.CastleCommlayer.ICastlePort[PORTMAP.castlePortingArr.length + outputCastlePorting.castlePortingArr.length];
		System.arraycopy(PORTMAP.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, 0, PORTMAP.castlePortingArr.length);
		System.arraycopy(outputCastlePorting.castlePortingArr, 0, PORTMAP_DT.castlePortingArr, PORTMAP.castlePortingArr.length, outputCastlePorting.castlePortingArr.length);
		
		String [] SC_Validation_Description = new String[] {
				"1-Set Input Voltage to the nominal values and expect ECU to be On",
				"2-Apply Short Circuit voltage and expect the corresponding output is Off with Normal Voltage",
				"3-Expect the Short Circuit output after certain time",
				"4-Apply Normal voltage and expect All outputs are OFF with over voltage",
				"5-Apply Short Circuit voltage and expect All outputs are OFF with over voltage",
				"6-Expect the outputs are Off after certain time",
				"7-Return to apply Nominal voltage and expect All outputs are On",
				"8-Expect the Normal output after certain tim",
				"9-Apply Normal voltage and expect All outputs are OFF with under voltage",
				"10-Apply Short Circuit voltage and expect All outputs are OFF with under voltage",
				"11-Expect the outputs are Off after certain time",
				"12-Return to apply Nominal voltage and expect All outputs are On"
				};
			DecisonTableEntryValue[] SC_ValidationDevalidationDT = new DecisonTableEntryValue[] {		
					/***************************************************************nominal******************************************************/			
					new DecisonTableEntryValue(SC_Validation_Description[0],new double[]{13.5, 					0	},null,	1000,     10.0,	expectedNormalOutput, 1000.0),
					new DecisonTableEntryValue(SC_Validation_Description[1],new double[]{13.5,					1	},null,	validationTime,	    0.2*validationTime,	expectedShortCircuitOutputs,	2000),
					new DecisonTableEntryValue(SC_Validation_Description[2],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	1000),
					/***************************************************************OpenCircuit with Over Voltage********************************/			
					new DecisonTableEntryValue(SC_Validation_Description[3],new double[]{oV_Threshold + 0.5,	0	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	2000), 	
					new DecisonTableEntryValue(SC_Validation_Description[4],new double[]{oV_Threshold + 0.5,	1	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	1000),
					new DecisonTableEntryValue(SC_Validation_Description[5],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	2000),	
					new DecisonTableEntryValue(SC_Validation_Description[6],new double[]{13.50,					0	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	3000),
					/***************************************************************OpenCircuit with Under Voltage********************************/
					new DecisonTableEntryValue(SC_Validation_Description[7],new double[]{NO_VAL,			NO_VAL	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	1000),
					new DecisonTableEntryValue(SC_Validation_Description[8],new double[]{uV_Threshold - 0.5,	0	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	2000), 	
					new DecisonTableEntryValue(SC_Validation_Description[9],new double[]{uV_Threshold - 0.5,	1	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	1000),
					new DecisonTableEntryValue(SC_Validation_Description[10],new double[]{NO_VAL,				0	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	2000),	
					new DecisonTableEntryValue(SC_Validation_Description[11],new double[]{13.50,				0	},null,	validationTime,		10.0,	expectedShortCircuitOutputs,	3000)
						};
			testingTechMGR.RunDT(SC_ValidationDevalidationDT, PORTMAP_DT, executionUnit);
	}
	
	public void finalize() throws Throwable {

	}

}