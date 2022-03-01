package libs.TestingPlatform.TestingTechLayer.UDS;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager;
import libs.TestingPlatform.CastleCommlayer.UDSSessionType;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 */
public class UDS {
	
	private static CastleCommManager commMGR = new CastleCommManager();
	
	/**
	 * Test all Read DIDs over CAN
	 * @param DIDs
	 */
	public static void CAN_TestReadDIDs(String[] DIDs, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_SwitchSessions(UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.ExtendedSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.ProgrammingSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.SupplierSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], executionUnit);
		}
	}
	
	/**
	 * Test all Read DIDs over CAN
	 * @param DIDs
	 */
	public static void CAN_TestReadDIDs(String[] DIDs, int[] Datalength, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_SwitchSessions(UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], Datalength[index],executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.ExtendedSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], Datalength[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.ProgrammingSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index],Datalength[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.SupplierSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], Datalength[index], executionUnit);
		}
	}
	
	/**
	 * Test all Read DIDs over CAN with supported Sessions only
	 * @param DIDs
	 */
	public static void CAN_TestReadDIDs(String[] DIDs, int[] Datalength, String[] SupportedSessions, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_SwitchSessions(UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_TestReadDID(DIDs[index], Datalength[index], SupportedSessions, executionUnit);
			commMGR.UDS_HardReset(executionUnit);
		}
	}
	
	/**
	 * Test all Write DIDs over CAN
	 * @param DIDs
	 * @param Commands
	 * @param commandlength
	 */
	public static void CAN_TestWriteDIDs(String[] DIDs, String[] Commands, int[] commandlength, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_SwitchSessions(UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_WriteDiag(DIDs[index], Commands[index], commandlength[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.ExtendedSession, executionUnit);
			commMGR.UDS_WriteDiag(DIDs[index], Commands[index], commandlength[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.ProgrammingSession, executionUnit);
			commMGR.UDS_WriteDiag(DIDs[index], Commands[index], commandlength[index], executionUnit);
			commMGR.UDS_HardReset(executionUnit);
			commMGR.UDS_SwitchSessions(UDSSessionType.SupplierSession, executionUnit);
			commMGR.UDS_WriteDiag(DIDs[index], Commands[index], commandlength[index], executionUnit);
		}
	}
	
	/**
	 * Test all Write DIDs over CAN
	 * @param DIDs
	 * @param Commands
	 * @param commandlength
	 */
	public static void CAN_TestWriteDIDs(String[] DIDs, String[] Commands, int[] commandlength,String[] SupportedSessions, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_SwitchSessions(UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_WriteDiag(DIDs[index], Commands[index], commandlength[index], SupportedSessions, executionUnit);
			commMGR.UDS_HardReset(executionUnit);
		}
	}
	
	/**
	 * Switch Sessions over CAN
	 * @param sessionType
	 */
	public static void CAN_SwitchSessions(UDSSessionType sessionType, ETS executionUnit)
	{
		commMGR.UDS_SwitchSessions(sessionType, executionUnit);
	}
	
	/**
	 * Read Diag over CAN with changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public static void CAN_ReadDiagWithSessionChange(UDSSessionType sessionType, String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit)
	{
		commMGR.UDS_SwitchSessions(sessionType, executionUnit);
		commMGR.UDS_ReadDiag(DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData,executionUnit);
	}
	
	/**
	 * Write Diag over CAN with changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 */
	public static void CAN_WriteDiagWithSessionChange(UDSSessionType sessionType, String DIDNumber, String commandData, ETS executionUnit)
	{
		commMGR.UDS_SwitchSessions(sessionType, executionUnit);
		commMGR.UDS_WriteDiag(DIDNumber, commandData, executionUnit);
	}
	
	/**
	 * Read Diag over CAN without changing Session
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public static void CAN_ReadDiagWithoutSessionChange(String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit)
	{
		commMGR.UDS_ReadDiag(DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData, executionUnit);
	}
	
	/**
	 * Write Diag over CAN without changing Session
	 * @param DIDNumber
	 * @param commandData
	 */
	public static void CAN_WriteDiagWithoutSessionChange(String DIDNumber, String commandData, ETS executionUnit)
	{
		commMGR.UDS_WriteDiag(DIDNumber, commandData, executionUnit);
	}
	
	
	/**
	 * Test all Read DIDs over LIN
	 * @param DIDs
	 */
	public static void LIN_TestReadDIDs(int NADAddress, String[] DIDs, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.ExtendedSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.ProgrammingSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.SupplierSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index], executionUnit);
		}
	}
	
	/**
	 * Test all Read DIDs over CAN
	 * @param DIDs
	 */
	public static void LIN_TestReadDIDs(int NADAddress, String[] DIDs, int[] Datalength, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index], Datalength[index],executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.ExtendedSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index], Datalength[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.ProgrammingSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index],Datalength[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.SupplierSession, executionUnit);
			commMGR.UDS_LIN_TestReadDID(NADAddress,DIDs[index], Datalength[index], executionUnit);
		}
	}
	
	/**
	 * Test all Write DIDs over LIN
	 * @param DIDwithComands
	 */
	public static void LIN_TestWriteDIDs(int NADAddress, String[] DIDs, String[] Commands, int[] commandlength, ETS executionUnit)
	{
		for(int index = 0; index < DIDs.length ; index++)
		{
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.DefaultSession, executionUnit);
			commMGR.UDS_LIN_WriteDiag(NADAddress,DIDs[index], Commands[index], commandlength[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.ExtendedSession, executionUnit);
			commMGR.UDS_LIN_WriteDiag(NADAddress,DIDs[index], Commands[index], commandlength[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.ProgrammingSession, executionUnit);
			commMGR.UDS_LIN_WriteDiag(NADAddress,DIDs[index], Commands[index], commandlength[index], executionUnit);
			commMGR.UDS_LIN_HardReset(NADAddress,executionUnit);
			commMGR.UDS_LIN_SwitchSessions(NADAddress,UDSSessionType.SupplierSession, executionUnit);
			commMGR.UDS_LIN_WriteDiag(NADAddress,DIDs[index], Commands[index], commandlength[index], executionUnit);
		}
	}
	
	/**
	 * Switch Sessions over LIN
	 * @param sessionType
	 */
	public static void LIN_SwitchSessions(int NADAddress, UDSSessionType sessionType, ETS executionUnit)
	{
		commMGR.UDS_LIN_SwitchSessions(NADAddress, sessionType, executionUnit);
	}
	
	/**
	 * Read Diag over LIN with changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public static void LIN_ReadDiagWithSessionChange(int NADAddress, UDSSessionType sessionType, String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit)
	{
		commMGR.UDS_LIN_SwitchSessions(NADAddress, sessionType, executionUnit);
		commMGR.UDS_LIN_ReadDiag(NADAddress,DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData, executionUnit);
	}
	
	/**
	 * Write Diag over LIN with changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 */
	public static void LIN_WriteDiagWithSessionChange(int NADAddress, UDSSessionType sessionType, String DIDNumber, String commandData, ETS executionUnit)
	{
		commMGR.UDS_LIN_SwitchSessions(NADAddress,sessionType, executionUnit);
		commMGR.UDS_LIN_WriteDiag(NADAddress,DIDNumber, commandData, executionUnit);
	}
	
	/**
	 * Read Diag over LIN without changing Session
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public static void LIN_ReadDiagWithoutSessionChange(int NADAddress, String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit)
	{
		commMGR.UDS_LIN_ReadDiag(NADAddress,DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData, executionUnit);
	}
	
	/**
	 * Write Diag over LIN without changing Session
	 * @param DIDNumber
	 * @param commandData
	 */
	public static void LIN_WriteDiagWithoutSessionChange(int NADAddress, String DIDNumber, String commandData, ETS executionUnit)
	{
		commMGR.UDS_LIN_WriteDiag(NADAddress, DIDNumber, commandData, executionUnit);
	}
	
	public void finalize() throws Throwable {

	}

}