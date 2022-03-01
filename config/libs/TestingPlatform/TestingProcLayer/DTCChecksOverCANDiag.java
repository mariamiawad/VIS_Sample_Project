package libs.TestingPlatform.TestingProcLayer;

import config.ETS;

/**
 * @author mnagah
 * @version 1.0
 * @created 15-Feb-2018 12:38:41 PM
 */
public class DTCChecksOverCANDiag {
	
	/**
	 * Clear all DTCs over CAN Diag
	 * @param executionUnit
	 */
	public void ClearAllDTCs(ETS executionUnit){
		libs.TestingPlatform.TestingTechLayer.UDS.DTCs.ClearDTCs(executionUnit);		
	}
	
	/**
	 * Check No Stored DTCs over CAN Diag
	 * @param executionUnit
	 */
	public void CheckNoDTCStored(ETS executionUnit){
		libs.TestingPlatform.TestingTechLayer.UDS.DTCs.CheckNoDTCStored(executionUnit);
	}
	
	/**
	 * Read all Stored DTCs over CAN Diag
	 * @param DTCs
	 * @param executionUnit
	 */
	public void ReadStoredDTCs(String[] DTCs, ETS executionUnit){
		libs.TestingPlatform.TestingTechLayer.UDS.DTCs.ReadStoredDTCs(DTCs, executionUnit);
	}
	
	/**
	 * Read a certain Stored DTC over CAN Diag
	 * @param DTCs
	 * @param executionUnit
	 */
	public void ReadStoredDTC(String DTCs, ETS executionUnit){
		libs.TestingPlatform.TestingTechLayer.UDS.DTCs.ReadStoredDTCs(DTCs, executionUnit);
	}
	
	/**
	 * Validate many Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public void ValidateDTCsAfterApplyingDefect(String[] DTCs, ETS executionUnit){
		  libs.TestingPlatform.TestingTechLayer.UDS.DTCs.ValidateDTCsAfterApplyingDefect(DTCs, executionUnit);
	}
	
	/**
	 * Validate a certain Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public void ValidateDTCAfterApplyingDefect(String DTCs, ETS executionUnit){
		  libs.TestingPlatform.TestingTechLayer.UDS.DTCs.ValidateDTCAfterApplyingDefect(DTCs, executionUnit);
	}
	
	/**
	 * DeValidate many Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public void DeValidateDTCsAfterRemovingDefect(String[] DTCs, ETS executionUnit){
		 libs.TestingPlatform.TestingTechLayer.UDS.DTCs.DeValidateDTCsAfterApplyingDefect(DTCs, executionUnit);
	}
	
	/**
	 * DeValidate a certain Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public void DeValidateDTCAfterRemovingDefect(String DTCs, ETS executionUnit){
		 libs.TestingPlatform.TestingTechLayer.UDS.DTCs.DeValidateDTCAfterApplyingDefect(DTCs, executionUnit);
	}

}