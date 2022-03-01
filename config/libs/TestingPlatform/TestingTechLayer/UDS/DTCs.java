package libs.TestingPlatform.TestingTechLayer.UDS;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 */
public class DTCs {
	
	private static CastleCommManager commMGR = new CastleCommManager();
	
	/**
	 * Clear all DTCs over CAN Diag
	 * @param executionUnit
	 */
	public static void ClearDTCs(ETS executionUnit)
	{
		commMGR.ClearDTCs(executionUnit);
	}
	
	/**
	 * Check No Stored DTCs over CAN Diag
	 * @param executionUnit
	 */
	public static void CheckNoDTCStored(ETS executionUnit)
	{
		commMGR.CheckNoDTCStored(executionUnit);
	}
	
	/**
	 * Read all Stored DTCs over CAN Diag
	 * @param DTCs
	 * @param executionUnit
	 */
	public static void ReadStoredDTCs(String[] DTCs, ETS executionUnit)
	{
		for(int index = 0; index < DTCs.length ; index++)
		{
			commMGR.ReadStoredDTCs(DTCs[index], executionUnit);
		}
	}
	
	/**
	 * Read a certain Stored DTC over CAN Diag
	 * @param DTCs
	 * @param executionUnit
	 */
	public static void ReadStoredDTCs(String DTC, ETS executionUnit)
	{
		commMGR.ReadStoredDTCs(DTC, executionUnit);

	}
	
	/**
	 * Validate a certain Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public static void ValidateDTCAfterApplyingDefect(String DTC, ETS executionUnit)
	{
		commMGR.ValidateDTCAfterApplyingDefect(DTC, executionUnit);

	}
	
	/**
	 * Validate many Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public static void ValidateDTCsAfterApplyingDefect(String[] DTCs, ETS executionUnit)
	{
		for(int index = 0; index < DTCs.length ; index++)
		{
			commMGR.ValidateDTCAfterApplyingDefect(DTCs[index], executionUnit);
		}

	}
	
	/**
	 * DeValidate a certain Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public static void DeValidateDTCAfterApplyingDefect(String DTC, ETS executionUnit)
	{
		commMGR.DeValidateDTCAfterApplyingDefect(DTC, executionUnit);

	}
	
	/**
	 * DeValidate many Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public static void DeValidateDTCsAfterApplyingDefect(String[] DTCs, ETS executionUnit)
	{
		for(int index = 0; index < DTCs.length ; index++)
		{
			commMGR.DeValidateDTCAfterApplyingDefect(DTCs[index], executionUnit);
		}

	}
	
	public void finalize() throws Throwable {

	}

}