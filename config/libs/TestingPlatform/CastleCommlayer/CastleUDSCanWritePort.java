package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
 
enum WriteSessionType{
	DefaultSession,
	SupplierSession,
	ProgrammingSession,
	ExtendedSession
};

public class CastleUDSCanWritePort implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	public static ETS exu;

	final private static String WriteSID = "2E";
	final private static String WriteResponseSID = "6E ";
	
	UDSSessionType fSessionType;
	String fDID;
	int fResponseOffset;
	String fResponseMask;

	/**
	 * double Value;
	 * 
	 * @param sessionType
	 * @param DID
	 */
	public CastleUDSCanWritePort(UDSSessionType sessionType, String DID, ETS executionUnit){
		fSessionType = sessionType;
		fDID = DID;
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
		
		case SupplierSession:
			exu.modTS().objCanDiag().afcSend("10 60");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, "50 60");
		
		case ProgrammingSession:
			exu.modTS().objCanDiag().afcSend("10 02");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, "50 02");
		
		case ExtendedSession:
			exu.modTS().objCanDiag().afcSend("10 03");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, "50 03");
		}
	}
	
	// Write and Check function.
	private void WriteCommand(String DIDNumber, String commandData) {
		IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();
		exu.comment("Write DID Command : %s ", WriteSID + " " + DIDNumber + " " + commandData);
		exu.modTS().objCanDiag().afcSend(WriteSID + " " + DIDNumber + " " + commandData);
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		exu.comment("Check Response to be Succeeded and to return  %s ", WriteResponseSID + DIDNumber);
		exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", WriteResponseSID + DIDNumber);
		exu.pause(5000); // Time Needed to Save DID in EEPROM
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
			exu.comment("Switch Session to be %s ", fSessionType.toString());
			SwitchSessions(fSessionType);
			
			WriteCommand(fDID, value);
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
