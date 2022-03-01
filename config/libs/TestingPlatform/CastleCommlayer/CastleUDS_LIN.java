package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
public class CastleUDS_LIN {

	static ETS exu;

	static String ReadSID = "22";
	static String WriteSID = "2E";
	static String WriteResponseSID = "6E ";
	static String ReadResponseSID = "62 ";

	public static void Init(int NADAddress, ETS executionUnit) {
		exu = executionUnit;
		executionUnit.modTS().objLinDiag().afcConfigureNextSend_NAD(NADAddress);
	}
	
	public static void HardReset() {
		IEvent EventResponseReceived = exu.modTS().objLinDiag().evtResponseReceived();
		exu.modTS().objLinDiag().afcSend("11 01"); // HardReset
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		exu.modTS().objLinDiag().afcTestByteSequence(0, "51 01");
		exu.pause(3000);
	}
	
	// Switch Sessions function.
	public static void SwitchSessions(UDSSessionType sessionType) {
		IEvent EventResponseReceived = exu.modTS().objLinDiag().evtResponseReceived();
		switch(sessionType)
		{
		case DefaultSession:			
			exu.modTS().objLinDiag().afcSend("10 01");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objLinDiag().afcTestByteSequence(0, "50 01");
			break;
		case SupplierSession:
			exu.modTS().objLinDiag().afcSend("10 60");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objLinDiag().afcTestByteSequence(0, "50 60");
			break;
		case ProgrammingSession:
			exu.modTS().objLinDiag().afcSend("10 02");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objLinDiag().afcTestByteSequence(0, "50 02");
			break;
		case ExtendedSession:
			exu.modTS().objLinDiag().afcSend("10 03");
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objLinDiag().afcTestByteSequence(0, "50 03");
			break;
		}
	}
	
	// Read and Check Response function.
	public static void ReadandCheckResponse(String DIDNumber, int ResponseOffset, String ResponseMask, String ExpectedResponseData) {
		IEvent EventResponseReceived = exu.modTS().objLinDiag().evtResponseReceived();

		exu.modTS().objLinDiag().afcSend(ReadSID + " " + DIDNumber);
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		if (ResponseMask == "") {
			exu.modTS().objLinDiag().afcTestByteSequence(ResponseOffset, ExpectedResponseData);
		} else {
			exu.modTS().objLinDiag().afcTestByteSequenceWithMask(ResponseOffset, ResponseMask,
					ExpectedResponseData);
		}
	}
	
	// Read and Check success Response function.
		public static void ReadandCheckSuccessResponse(String DIDNumber) {
			IEvent EventResponseReceived = exu.modTS().objLinDiag().evtResponseReceived();

			exu.modTS().objLinDiag().afcSend(ReadSID + " " + DIDNumber);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objLinDiag().sfcTestByteSequenceWithMask(0, "FF FF FF", ReadResponseSID + DIDNumber);
		}
		
		// Read and Check success Response function.
		public static void ReadandCheckSuccessResponse(String DIDNumber, int Datalength) {
			IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();

			exu.modTS().objLinDiag().afcSend(ReadSID + " " + DIDNumber);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objLinDiag().afcTestByteSequenceWithMask(0, "FF FF FF", ReadResponseSID + DIDNumber);
			exu.modTS().objLinDiag().afcTestResponse(Datalength+3, Datalength+3);
		}
	
	// Write and Check Response function.
	public static void WriteAndCheckResponse(String DIDNumber, String commandData) {
		IEvent EventResponseReceived = exu.modTS().objLinDiag().evtResponseReceived();
		exu.comment("Write DID Command : %s ", WriteSID + " " + DIDNumber + " " + commandData);
		exu.modTS().objLinDiag().afcSend(WriteSID + " " + DIDNumber + " " + commandData);
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		exu.comment("Check Response to be Succeeded and to return  %s ", WriteResponseSID + DIDNumber);
		exu.modTS().objLinDiag().afcTestByteSequenceWithMask(0, "FF FF FF", WriteResponseSID + DIDNumber);
		exu.pause(5000); // Time Needed to Save DID in EEPROM
	}
	
	// Write and Check Response function.
		public static void WriteAndCheckResponse(String DIDwithData) {
			IEvent EventResponseReceived = exu.modTS().objLinDiag().evtResponseReceived();
			exu.comment("Write DID Command : %s ", WriteSID + " " + DIDwithData);
			exu.modTS().objLinDiag().afcSend(WriteSID + " " + DIDwithData);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.comment("Check Response to be Succeeded and to return  %s ", WriteResponseSID + DIDwithData.substring(3, 7));
			exu.modTS().objLinDiag().afcTestByteSequenceWithMask(0, "FF FF FF", WriteResponseSID + DIDwithData.substring(3, 7));
			exu.pause(5000); // Time Needed to Save DID in EEPROM
		}
		
		// Write and Check Response function.
		public static void WriteAndCheckResponse(String DIDNumber, String commandData, int length) {
			IEvent EventResponseReceived = exu.modTS().objLinDiag().evtResponseReceived();
			exu.comment("Write DID Command : %d ", WriteSID + DIDNumber + " " + commandData);
			exu.modTS().objLinDiag().afcSend(WriteSID + DIDNumber + " " + commandData);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.comment("Check Response %s to be Succeeded and to return  %d ", WriteResponseSID + DIDNumber);
			exu.modTS().objLinDiag().afcTestByteSequenceWithMask(0, "FF FF FF", WriteResponseSID + DIDNumber);
			exu.pause(5000); // Time Needed to Save DID in EEPROM
			
			exu.modTS().objLinDiag().afcSend(ReadSID + " " + DIDNumber);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objLinDiag().afcTestByteSequence(0, ReadSID + " " + DIDNumber + " " + commandData);
		}
}
