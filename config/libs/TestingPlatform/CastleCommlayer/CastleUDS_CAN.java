package libs.TestingPlatform.CastleCommlayer;

import java.util.Arrays;

import castle.testenv.base.config.IEvent;
import config.ETS;

/**
 * @author mnagah
 * @version 3.0
 * @created 15-Apr-2018 1:53:45 PM
 */ 
public class CastleUDS_CAN {

	public static ETS exu;

	final private static String ReadSID = "22";
	final private static String WriteSID = "2E";
	final private static String WriteResponseSID = "6E ";
	final private static String ReadResponseSID = "62 ";
	final private static String NegativeResponseSID = "7F ";		
	private static String currentSession = "";

	public static void Init(ETS executionUnit) {
		CastleUDS_CAN.exu = executionUnit;
	}
	
	public static void HardReset() {
		IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();
		exu.modTS().objCanDiag().afcSend("11 01"); // HardReset
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		exu.modTS().objCanDiag().afcTestByteSequence(0, "51 01");
		exu.pause(3000);
	}
	
	// Switch Sessions function.
	public static void SwitchSessions(UDSSessionType sessionType) {
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
	
	// Read and Check Response function.
	public static void ReadandCheckResponse(String DIDNumber, int ResponseOffset, String ResponseMask, String ExpectedResponseData) {
		IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();

		exu.modTS().objCanDiag().afcSend(ReadSID + " " + DIDNumber);
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		if (ResponseMask == "") {
			exu.modTS().objCanDiag().afcTestByteSequence(ResponseOffset, ExpectedResponseData);
		} else {
			exu.modTS().objCanDiag().afcTestByteSequenceWithMask(ResponseOffset, ResponseMask,
					ExpectedResponseData);
		}
	}
	
	// Read and Check success Response function.
		public static void ReadandCheckSuccessResponse(String DIDNumber) {
			IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();

			exu.modTS().objCanDiag().afcSend(ReadSID + " " + DIDNumber);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", ReadResponseSID + DIDNumber);
		}
		
		// Read and Check success Response function.
		public static void ReadandCheckSuccessResponse(String DIDNumber, int Datalength) {
			IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();

			exu.modTS().objCanDiag().afcSend(ReadSID + " " + DIDNumber);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", ReadResponseSID + DIDNumber);
			exu.modTS().objCanDiag().afcTestResponse(Datalength+3, Datalength+3);
		}
		
		// Read and Check success Response function.
		public static void ReadandCheckSuccessResponse(String DIDNumber, int Datalength, String[] SupportedSessions) {
			IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();

			exu.modTS().objCanDiag().afcSend(ReadSID + " " + DIDNumber);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			if(Arrays.asList(SupportedSessions).contains(currentSession))
			{
				exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", ReadResponseSID + DIDNumber);
				exu.modTS().objCanDiag().afcTestResponse(Datalength+3, Datalength+3);
			}
			else
			{
				switch (currentSession)
				{
					case "01":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + ReadSID + " " + "31");
					break;
					
					case "02":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + ReadSID + " " + "11");
					break;
					
					case "03":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + ReadSID + " " + "31");					
					break;
					
					case "60":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + ReadSID + " " + "31");					
					break;
					
					default:
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + ReadSID + " " + "31");					
					break;
					
				}
			}
		}
	// Write and Check Response function.
	public static void WriteAndCheckResponse(String DIDNumber, String commandData) {
		IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();
		exu.comment("Write DID Command : %s ", WriteSID + " " + DIDNumber + " " + commandData);
		exu.modTS().objCanDiag().afcSend(WriteSID + " " + DIDNumber + " " + commandData);
		exu.pauseUntilEvent(EventResponseReceived, 1000);
		exu.comment("Check Response to be Succeeded and to return  %s ", WriteResponseSID + DIDNumber);
		exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", WriteResponseSID + DIDNumber);
		exu.pause(5000); // Time Needed to Save DID in EEPROM
		
	}
	
	// Write and Check Response function.
		public static void WriteAndCheckResponse(String DIDNumber, String commandData, int length) {
			IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();
			exu.comment("Write DID Command : %s ", WriteSID + DIDNumber + " " + commandData);
			exu.modTS().objCanDiag().afcSend(WriteSID + DIDNumber + " " + commandData);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.comment("Check Response to be Succeeded and to return  %s ", WriteResponseSID + DIDNumber);
			exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", WriteResponseSID + DIDNumber);
			exu.pause(5000); // Time Needed to Save DID in EEPROM
			
			exu.modTS().objCanDiag().afcSend(ReadSID + " " + DIDNumber);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			exu.modTS().objCanDiag().afcTestByteSequence(0, ReadSID + " " + DIDNumber + " " + commandData);
		}
		
		// Write and Check Response function.
		public static void WriteAndCheckResponse(String DIDNumber, String commandData,String[] SupportedSessions, int length) {
			IEvent EventResponseReceived = exu.modTS().objCanDiag().evtResponseReceived();
			exu.comment("Write DID Command : %s ", WriteSID+ " " + DIDNumber + " " + commandData);
			exu.modTS().objCanDiag().afcSend(WriteSID +" " + DIDNumber + " " + commandData);
			exu.pauseUntilEvent(EventResponseReceived, 1000);
			if(Arrays.asList(SupportedSessions).contains(currentSession))
			{
				exu.comment("Check Response to be Succeeded and to return  %s ", WriteResponseSID + DIDNumber);
				exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", WriteResponseSID + DIDNumber);
				exu.pause(5000); // Time Needed to Save DID in EEPROM
				
				exu.modTS().objCanDiag().afcSend(ReadSID + " " + DIDNumber);
				exu.pauseUntilEvent(EventResponseReceived, 1000);
				exu.modTS().objCanDiag().afcTestByteSequence(0,ReadResponseSID + DIDNumber + " " + commandData);
			}
			else
			{	
				switch (currentSession)
				{
					case "01":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + WriteSID + " " + "7F");
					break;
					
					case "02":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + WriteSID + " " + "11");
					break;
					
					case "03":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + WriteSID + " " + "31");					
					break;
					
					case "60":
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + WriteSID + " " + "31");					
					break;
					
					default:
					exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0, "FF FF FF", NegativeResponseSID + WriteSID + " " + "31");					
					break;
					
				}
			
			}
		}
}
