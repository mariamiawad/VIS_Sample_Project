package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
public class CastleDTC_CAN {

	ETS exu;
	String readDTCInfo ="19";
	String reportNumberOfDTCbyStatusMask = "01";
	String reportDTCbyStatusMask = "02";
	String reportDTCSnapshotRecordbyDTCNumber = "04"; 
	String reportExtendedDataRecordbyDTCNumber = "06"; 
    String reportSupportedDTC = "0A"; 
	String readDTCInfoPosRes ="59";
	
	String clearDiagInfo = "14 FF FF FF";
	String clearPostiveRes = "54";
	
	
	public CastleDTC_CAN(ETS executionUnit){
		exu = executionUnit;
	}
	
	public void ClearDTCs(){
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();
		exu.comment("Clear All DTCs");
		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		
		exu.comment("Send Clear Command %s", clearDiagInfo);
		exu.modTS().objCanDiag().afcSend(clearDiagInfo);
		exu.pauseUntilEvent(event,1000);
		exu.comment("Check all DTCs cleared successfully with response %s", clearPostiveRes);
		exu.modTS().objCanDiag().afcTestByteSequence(0,clearPostiveRes);
		exu.pause(100);
		
		exu.comment("Read all DTCs to check that there is no stored DTCs using %s", readDTCInfo + reportDTCbyStatusMask);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportDTCbyStatusMask+" "+"09");
		exu.pauseUntilEvent(event,1000);
		exu.comment("Check all DTCs cleared successfully with response %s", readDTCInfoPosRes + reportDTCbyStatusMask +" "+"09");
		exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0,"FF FF"+" "+"09",readDTCInfoPosRes + reportDTCbyStatusMask+" "+"09");  
	}
	
	public void CheckNoDTCStored(){
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();
		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		
		exu.comment("Read all DTCs to check that there is no stored DTCs using %s", readDTCInfo + reportDTCbyStatusMask);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportDTCbyStatusMask+" "+"09");
		exu.pauseUntilEvent(event,1000);
		exu.comment("Check all DTCs cleared successfully with response %s", readDTCInfoPosRes + reportDTCbyStatusMask+" "+"09");
		exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0,"FF FF"+" "+"09",readDTCInfoPosRes + reportDTCbyStatusMask+" "+"09");
	}
	
	public void ReadStoredDTCs(String DTC){
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();
		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		
		exu.comment("Read all DTCs to check that %s is stored using %s", DTC,readDTCInfo + reportDTCbyStatusMask);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportDTCbyStatusMask+" "+"08");
		exu.pauseUntilEvent(event,1000);
		exu.comment("Check all DTCs cleared successfully with response %s", readDTCInfoPosRes + reportDTCbyStatusMask+" "+"08");
		exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0,"FF FF"+" "+"08"+" "+"FF FF FF"+" "+"08",readDTCInfoPosRes + reportDTCbyStatusMask+" "+DTC+" "+"08");  
	}
	
	public void ValidateDTCAfterApplyingDefect(String DTC){
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();
		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		
		exu.comment("Read all DTCs to check that there is no stored DTCs using %s", readDTCInfo + reportDTCbyStatusMask);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportDTCbyStatusMask+" "+"09");
		exu.pauseUntilEvent(event,1000);
		exu.comment("Check all DTCs cleared successfully with response %s", readDTCInfoPosRes + reportDTCbyStatusMask+" "+"09");
		exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0,"FF FF"+" "+"09"+" "+"FF FF FF"+" "+"09",readDTCInfoPosRes + reportDTCbyStatusMask+" "+DTC+" "+"09");  
	}
	
	public void DeValidateDTCAfterRemovingDefect(String DTC){
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();
		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		
		exu.comment("Read all DTCs to check that there is no stored DTCs using %s", readDTCInfo + reportDTCbyStatusMask);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportDTCbyStatusMask+" "+"08");
		exu.pauseUntilEvent(event,1000);
		exu.comment("Check all DTCs cleared successfully with response %s", readDTCInfoPosRes + reportDTCbyStatusMask+" "+"08");
		exu.modTS().objCanDiag().afcTestByteSequenceWithMask(0,"FF FF"+" "+"08"+" "+"FF FF FF"+" "+"08",readDTCInfoPosRes + reportDTCbyStatusMask+" "+DTC+" "+"08");  
	}
	
	public void DTC_CheckReporting_19_0A(String AvailabilityMask,ETS exu)
	{
	//TODO : to be modified according to project
		String Supported_DTCs[]={"96 30 55 00","96 30 86 00","96 30 16 00","96 30 17 00","96 30	88 00","E1 4F 87 00","E1 5B 87 00","E2 6B 87 00","E1 54 87 00","E1 76 87 00","E1 43 87 00","E1 41 87 00","E1 48	87 00","C0 75 00 00","C0 78 00 00","96 32 13 00","96 32 98 00","96 32 01 00","96 34	13 00","96 34 98 00","96 34	01 00","96 36 55 00","96 36 96 00","96 36 88 00","96 38	55 00","96 38 96 00","96 38 88 00","96 40 01 00","96 41 01 00","96 42 01 00","96 43 01 00","96 44 01 00","96 45 01 00"};
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();

		//Read supported DTCs
		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		
		exu.comment("Read all supported DTCs using %s", readDTCInfo + reportSupportedDTC);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportSupportedDTC);
		exu.pauseUntilEvent(event, 1000);
		exu.modTS().objCanDiag().afcTestByteSequence(0,readDTCInfoPosRes+ reportSupportedDTC +AvailabilityMask+Supported_DTCs[0]+ " "+Supported_DTCs[1]+" "+Supported_DTCs[2]+ " "+Supported_DTCs[3]+ " "+Supported_DTCs[4]+ " "+Supported_DTCs[5]+ " "+Supported_DTCs[6]+ " "+Supported_DTCs[7]+ " "+Supported_DTCs[8]+ " "+Supported_DTCs[9]+ " "+Supported_DTCs[10]+ " "+Supported_DTCs[11]+ " "+Supported_DTCs[12]+ " "+Supported_DTCs[13]+ " "+Supported_DTCs[14]+ " "+Supported_DTCs[15]+ " "+Supported_DTCs[16]+ " "+Supported_DTCs[17]+ " "+Supported_DTCs[18]+ " "+Supported_DTCs[19]+ " "+Supported_DTCs[20]+ " "+Supported_DTCs[21]+ " "+Supported_DTCs[22]+ " "+Supported_DTCs[23]+ " "+Supported_DTCs[24]+ " "+Supported_DTCs[25]+ " "+Supported_DTCs[26]+ " "+Supported_DTCs[27]+ " "+Supported_DTCs[28]+ " "+Supported_DTCs[29]+ " "+Supported_DTCs[30]+ " "+Supported_DTCs[31]+ " "+Supported_DTCs[32]+ " "+Supported_DTCs[33]+ " ");
	}
	
	public void DTC_CheckReporting_19_01(String[] DefectName,String AvailabilityMask, String StatusMask,String[] DTC_ReturnedDTCCounterByte,ETS exu)
	{
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();
		
		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		

		exu.comment("Read Number Of DTCs by StatusMask  using %s", readDTCInfo + reportNumberOfDTCbyStatusMask);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportNumberOfDTCbyStatusMask + StatusMask);
		exu.pauseUntilEvent(event, 1000);
		exu.modTS().objCanDiag().afcTestByteSequence(0,readDTCInfoPosRes + reportNumberOfDTCbyStatusMask+AvailabilityMask+"01"+DTC_ReturnedDTCCounterByte[0]);

	}
	
	public void DTC_CheckReporting_19_04(String[] DefectName,String DTC_code,String[] DTCReturnedStatusByte,String[]DTCSnapshotRecordNumber,String[] DTCSnapshotRecordNumberOfIdentifiers,long Mileage,int DTCOccurenceCounter,String[] DTCSnapshotRecord,ETS exu)
	{
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();

		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);

		exu.comment("Read DTC Snapshot Record by DTC Number using %s", readDTCInfo + reportDTCSnapshotRecordbyDTCNumber);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportDTCSnapshotRecordbyDTCNumber + DTC_code + DTCSnapshotRecordNumber[0]);
		exu.pauseUntilEvent(event, 1000);
		exu.modTS().objCanDiag().afcTestByteSequence(0,readDTCInfoPosRes + reportDTCSnapshotRecordbyDTCNumber +DTC_code+DTCReturnedStatusByte[1]+DTCSnapshotRecordNumber[0]+DTCSnapshotRecordNumberOfIdentifiers[0]+DTCSnapshotRecord[0]);//user will enter DTCSnapshotRecord expected depending on data entere
	}	
	
	
	public void DTC_CheckReporting_19_06(String[] DefectName , String[] DTC_code,String AvailabilityMask, String RecordNumber,String[]StatusByte ,
			double pre_ValidationTime, double ValidationTime, double De_ValidationTime, ETS exu)
	{
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();

		exu.comment("Enter Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);
		
		exu.comment("Read DTC Snapshot Record by DTC Number using %s" , readDTCInfo + reportExtendedDataRecordbyDTCNumber);
		exu.modTS().objCanDiag().afcSend(readDTCInfo + reportExtendedDataRecordbyDTCNumber +DTC_code+" "+RecordNumber);
		exu.pauseUntilEvent(event, 1000);
		exu.modTS().objCanDiag().afcTestByteSequence(0,readDTCInfoPosRes + reportExtendedDataRecordbyDTCNumber +DTC_code+" "+StatusByte[0]);

		
	}
	
	
	
	
	
	
	
	
}
