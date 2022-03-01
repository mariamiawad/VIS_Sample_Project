package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
public class CastleUDSCanReadPort implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	public static ETS exu;

	final private static String ReadSID = "22";
	
	UDSSessionType fSessionType;
	String fDID;
	int fResponseOffset;
	String fResponseMask;
	
	/**
	 * double Value;
	 * 
	 * @param sessionType
	 * @param DID
	 * @param ResponseOffset
	 * @param ResponseMask
	 */
	public CastleUDSCanReadPort(UDSSessionType sessionType, String DID, int ResponseOffset, String ResponseMask, ETS executionUnit){
		fSessionType = sessionType;
		fDID = DID;
		fResponseOffset = ResponseOffset;
		fResponseMask = ResponseMask;
		exu = executionUnit;
	}
	
	// Switch Sessions function.
	private void SwitchSessions(UDSSessionType sessionType) {
		IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();
		switch(sessionType)
		{
		case DefaultSession:			
			exu.modTS().objCanDiag().afcSend("10 01");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, "50 01");
			break;
		case SupplierSession:
			exu.modTS().objCanDiag().afcSend("10 60");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, "50 60");
			break;
		case ProgrammingSession:
			exu.modTS().objCanDiag().afcSend("10 02");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, "50 02");
			break;
		case ExtendedSession:
			exu.modTS().objCanDiag().afcSend("10 03");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, "50 03");
			break;
		}
	}
	
	// Read and Check function.
	private void ReadandCheckResponse(String DIDNumber, int ResponseOffset, String ResponseMask, String ExpectedResponseData) {
		IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();
		exu.modTS().objCanDiag().afcSend(ReadSID + " " + DIDNumber);
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		if (ResponseMask == "") {
			exu.comment("Check Response to be Succeeded and to return  %s ", ExpectedResponseData);
			exu.modTS().objCanDiag().afcTestByteSequence(ResponseOffset, ExpectedResponseData);
		} else {
			exu.comment("Check Response to be Succeeded and to return  %s ", ExpectedResponseData);
			exu.modTS().objCanDiag().afcTestByteSequenceWithMask(ResponseOffset, ResponseMask,
					ExpectedResponseData);
		}
	}
	
	
	@Override
	public Object[] apply(Object ... args){
		String value = String.valueOf(args[0]);
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		if(value != "")
		{
			exu.comment("Switch Session to be  %s ", fSessionType.toString());
			SwitchSessions(fSessionType);
			exu.comment("Read DID Command : %s ", fDID + " " + value);
			ReadandCheckResponse(fDID, fResponseOffset, fResponseMask, value);
		}
		return ReturnObj();
	}
	
	private void Request_pauseInToOutDelay(double IntoOutDelay){
		if(InToOutDelay_paused == false){
			exu.comment("Wait for Input to Output Delay of %s mSec", IntoOutDelay);
			exu.pause(IntoOutDelay);
			InToOutDelay_paused = true;
		}
	}
	
	private Object[] ReturnObj(){
		returnObj[0] = InToOutDelay_paused;
		return returnObj;
	}
}
