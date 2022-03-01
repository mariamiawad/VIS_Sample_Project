package libs.TestingPlatform.CastleCommlayer;
import config.ETS;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.DTCInput;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
 
public class CastleCanDTCManagementInput implements ICastlePort{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	String space = " ";

	
	public CastleCanDTCManagementInput (ETS executionUnit,DTCInput Input)
	{
		exu = executionUnit;
	}
	
	@Override
	public Object[] apply(Object...args)
	{
	    String value = args[0].toString();
		final String reportNumberOfDTCbyStatusMask = "01";
		final String reportDTCbyStatusMask = "02";
		final String reportDTCSnapshotRecordbyDTCNumber = "04"; 
		final String reportExtendedDataRecordbyDTCNumber = "06"; 
	    final String reportSupportedDTC = "0A"; 
		String[] tokens = value.split(" ");
		
		exu.comment("Enter Supplier Diag Session");
		CastleUDS_CAN.Init(exu);
		CastleUDS_CAN.SwitchSessions(UDSSessionType.SupplierSession);

		switch(tokens [1])
		{
			/*   19 01    */
			case reportNumberOfDTCbyStatusMask:
			exu.comment("Read Number Of DTCs by StatusMask");
			exu.modTS().objCanDiag().afcSend(value);
			break;
			
			/*   19 02    */
			case reportDTCbyStatusMask:
			exu.comment("Read DTC by Status Mask");
			exu.modTS().objCanDiag().afcSend(value);
			break;
			
			/*   19 04    */
			case reportDTCSnapshotRecordbyDTCNumber:
			exu.comment("Read DTC Snapshot Record by DTC Number");
			exu.modTS().objCanDiag().afcSend(value);
			break;
			
			/*   19 06    */
			case reportExtendedDataRecordbyDTCNumber:
			exu.comment("Read DTC Extended Record by DTC Number");
			exu.modTS().objCanDiag().afcSend(value);
			break;
			
			/*   19 0A    */
			case reportSupportedDTC:
			exu.comment("Read all supported DTCs");
			exu.modTS().objCanDiag().afcSend(value);		
			break;		
		}
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}
}
