package libs.TestingPlatform.TestingProcLayer;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.UDSSessionType;
import libs.TestingPlatform.TestingTechLayer.UDS.UDS;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 12:38:41 PM
 */
public class DiagOverCAN {

	/**
	 * Test all Read DIDs over CAN
	 * @param DIDs
	 */
	public void TestReadDIDs(String[] DIDs, ETS executionUnit){
		UDS.CAN_TestReadDIDs(DIDs, executionUnit);
	}
	
	/**
	 * Test all Read DIDs over CAN
	 * @param DIDs
	 * @param Datalength
	 */
	public void TestReadDIDs(String[] DIDs, int[] Datalength, ETS executionUnit){
		UDS.CAN_TestReadDIDs(DIDs, Datalength, executionUnit);
	}
	
	/**
	 * Test all Read DIDs over CAN with supported Sessions only
	 * @param DIDs
	 * @param Datalength
	 */
	public void TestReadDIDs(String[] DIDs, int[] Datalength, String[] SupportedSessions, ETS executionUnit){
		UDS.CAN_TestReadDIDs(DIDs, Datalength, SupportedSessions, executionUnit);
	}
	
	/**
	 * Test all Write DIDs over CAN with supported Sessions only
	 * @param DIDwithComands
	 */
	public void TestWriteDIDs(String[] DIDs, String[]Commands, int[] CommandLength, String[] SupportedSessions , ETS executionUnit){
		UDS.CAN_TestWriteDIDs(DIDs, Commands, CommandLength, SupportedSessions, executionUnit);
	}
	
	/**
	 * Test all Write DIDs over CAN
	 * @param DIDwithComands
	 */
	public void TestWriteDIDs(String[] DIDs, String[]Commands, int[] CommandLength, ETS executionUnit){
		UDS.CAN_TestWriteDIDs(DIDs, Commands, CommandLength, executionUnit);
	}
	
	/**
	 * Switch Sessions
	 * @param sessionType
	 */
	public void SwitchSessions(UDSSessionType sessionType, ETS executionUnit){
		UDS.CAN_SwitchSessions(sessionType, executionUnit);
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
	public void ReadDiag(UDSSessionType sessionType, String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit){
		UDS.CAN_ReadDiagWithSessionChange(sessionType, DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData, executionUnit);
	}
	
	/**
	 * Write Diag over CAN with changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 */
	public void WriteDiag(UDSSessionType sessionType, String DIDNumber, String commandData, ETS executionUnit){
		UDS.CAN_WriteDiagWithSessionChange(sessionType, DIDNumber, commandData, executionUnit);
	}
	
	/**
	 * Read Diag over CAN without changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public void ReadDiag(String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit){
		UDS.CAN_ReadDiagWithoutSessionChange(DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData, executionUnit);
	}
	
	/**
	 * Write Diag over CAN without changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 */
	public void WriteDiag(String DIDNumber, String commandData, ETS executionUnit){
		UDS.CAN_WriteDiagWithoutSessionChange(DIDNumber, commandData, executionUnit);
	}
	public void finalize() throws Throwable {

	}

}