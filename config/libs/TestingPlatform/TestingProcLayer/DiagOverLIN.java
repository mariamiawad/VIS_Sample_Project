package libs.TestingPlatform.TestingProcLayer;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.UDSSessionType;
import libs.TestingPlatform.TestingTechLayer.UDS.UDS;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 12:38:41 PM
 */
public class DiagOverLIN {

	/**
	 * Test all Read DIDs over LIN
	 * @param DIDs
	 */
	public void TestReadDIDs(int NADAddress, String[] DIDs, ETS executionUnit){
		UDS.LIN_TestReadDIDs(NADAddress, DIDs, executionUnit);
	}
	
	/**
	 * Test all Read DIDs over LIN
	 * @param DIDs
	 */
	public void TestReadDIDs(int NADAddress, String[] DIDs, int[] Datalength, ETS executionUnit){
		UDS.LIN_TestReadDIDs(NADAddress, DIDs, Datalength, executionUnit);
	}
	
	/**
	 * Test all Write DIDs over LIN
	 * @param DIDwithComands
	 */
	public void TestWriteDIDs(int NADAddress, String[] DIDs, String[]Commands, int[] CommandLength, ETS executionUnit){
		UDS.CAN_TestWriteDIDs(DIDs, Commands, CommandLength, executionUnit);
	}
	
	/**
	 * Switch Sessions
	 * @param sessionType
	 */
	public void SwitchSessions(int NADAddress, UDSSessionType sessionType, ETS executionUnit){
		UDS.LIN_SwitchSessions(NADAddress, sessionType, executionUnit);
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
	public void ReadDiag(int NADAddress, UDSSessionType sessionType, String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit){
		UDS.LIN_ReadDiagWithSessionChange(NADAddress, sessionType, DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData, executionUnit);
	}
	
	/**
	 * Write Diag over LIN with changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 */
	public void WriteDiag(int NADAddress, UDSSessionType sessionType, String DIDNumber, String commandData, ETS executionUnit){
		UDS.LIN_WriteDiagWithSessionChange(NADAddress, sessionType, DIDNumber, commandData, executionUnit);
	}
	
	/**
	 * Read Diag over LIN without changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public void ReadDiag(int NADAddress, String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit){
		UDS.LIN_ReadDiagWithoutSessionChange(NADAddress, DIDNumber, commandData, ResponseOffset, ResponseMask, ExpectedResponseData, executionUnit);
	}
	
	/**
	 * Write Diag over LIN without changing Session
	 * @param sessionType
	 * @param DIDNumber
	 * @param commandData
	 */
	public void WriteDiag(int NADAddress, String DIDNumber, String commandData, ETS executionUnit){
		UDS.LIN_WriteDiagWithoutSessionChange(NADAddress, DIDNumber, commandData, executionUnit);
	}
	public void finalize() throws Throwable {

	}

}