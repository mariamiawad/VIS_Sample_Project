package libs.TestingPlatform.CastleCommlayer;
import castle.testenv.base.config.IEvent;
import config.ETS;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.DTCOutput;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
 
public class CastleCanDTCManagementOutput implements ICastlePort{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
    ETS exu;
	String space = " ";
	
	public CastleCanDTCManagementOutput (ETS executionUnit, DTCOutput Output
										)
	{
		exu = executionUnit;
	}
	

	@Override
	public Object[] apply(Object...args)
	{
		IEvent event = exu.modTS().objCanDiag().evtResponseReceived();
		String value = args[0].toString();
		String GroupOfDTC= "";
		double time = (double)args[1];
		double timeTolerance = (double)args[2];
	    final String reportNumberOfDTCbyStatusMask = "01";
		final String reportDTCbyStatusMask = "02";
		final String reportDTCSnapshotRecordbyDTCNumber = "04"; 
		final String reportExtendedDataRecordbyDTCNumber = "06"; 
	    final String reportSupportedDTC = "0A";
	

	
		String[] tokens = value.split(" ");
		if(tokens[0].contentEquals("59"))
		{
			exu.comment("Positive Response obtained");
			switch(tokens[1])
			{
				/*   59 01    */
				case reportNumberOfDTCbyStatusMask:
				exu.pauseUntilEvent(event, time + timeTolerance);
				exu.comment("Expect Number Of DTCs equal to [%s]", tokens[4]);
				exu.modTS().objCanDiag().afcTestByteSequence(0,tokens[0] + space + tokens[1] + space + tokens[2] + space + tokens[3] + space + tokens[4] );

				break;
				
				/*   59 02    */
				case reportDTCbyStatusMask:
				exu.pauseUntilEvent(event, time + timeTolerance);
				exu.comment("Expect DTC [%s] Status Mask [%s]", tokens[3] + space + tokens[4] + space + tokens[5] + space , tokens[6]);
				exu.modTS().objCanDiag().afcTestByteSequence(0,tokens[0] + space + tokens[1] + space +tokens[2] + space + tokens[3] + space + tokens[4] + space + tokens[5] + space + tokens[6]);
				break;
				
				/*   59 04    */
				case reportDTCSnapshotRecordbyDTCNumber:
				exu.pauseUntilEvent(event, time + timeTolerance);				
				exu.comment("Expect DTC Snapshot Record [%s]", tokens[6] + space + tokens[7] + space + tokens[8] + space 
				+ tokens[9] + space + tokens[10] + space + tokens[11] + space + tokens[12] + space + tokens[13] + space 
				+ tokens[14] + space + tokens[15] + space + tokens[16] + space + tokens[17] + space + tokens[18] + space 
				+ tokens[19] + space + tokens[20] + space + tokens[21] + space + tokens[22] + space + tokens[23] + space 
				+ tokens[24] + space + tokens[25] + space + tokens[26] + space + tokens[27]);
				exu.modTS().objCanDiag().afcTestByteSequence(0,tokens[0] + space + tokens[1] + space + tokens[2] + space + tokens[3] + space + tokens[4] + space 
				+ tokens[5] + space + tokens[6] + space + tokens[7] + space + tokens[8] + space 
				+ tokens[9] + space + tokens[10] + space + tokens[11] + space + tokens[12] + space + tokens[13] + space 
				+ tokens[14] + space + tokens[15] + space + tokens[16] + space + tokens[17] + space + tokens[18] + space 
				+ tokens[19] + space + tokens[20] + space + tokens[21] + space + tokens[22] + space + tokens[23] + space 
				+ tokens[24] + space + tokens[25] + space + tokens[26] + space + tokens[27]);
				break;
				
				/*   59 06    */
				case reportExtendedDataRecordbyDTCNumber:
				exu.pauseUntilEvent(event, time + timeTolerance);
				exu.comment("Expect Pos Response + DTC Extended Record by DTC Number [%s]" , tokens[6] + space + tokens[7] + space + tokens[8]);
				exu.modTS().objCanDiag().afcTestByteSequence(0,tokens[0] + space + tokens[1] + space + tokens[2] + space + tokens[3] + space + tokens[4] + space + tokens[5] + space + tokens[6] + space + tokens[7] + space + tokens[8]);
				break;
				
				/*   59 0A    */
				case reportSupportedDTC:
				for(int i = 3 ; i < tokens.length ; i++)
				{
					GroupOfDTC = GroupOfDTC.concat(tokens[i]);
					if(i != (tokens.length - 1))
						GroupOfDTC = GroupOfDTC.concat(space);

				}
				exu.comment("%s", GroupOfDTC);
	            exu.pauseUntilEvent(event, time + timeTolerance);
				exu.comment("Expect Pos Response + all supported DTCs [%s]", tokens[0] + space + tokens[1] + space + tokens[2] + space + GroupOfDTC);
		   	    exu.modTS().objCanDiag().afcTestByteSequence(0, tokens[0] + space + tokens[1] + space + tokens[2] + space + GroupOfDTC);

				break;
			}
		}
		else if (tokens[0].contentEquals("7F"))
		{
			if(tokens[1].contentEquals("19"))
			{
				if(tokens[2].contentEquals("12"))
				{
					exu.comment("Negative Response obtained, subfunction not supported");	
				}
				else if (tokens[2].contentEquals("13"))
				{
					exu.comment("Negative Response obtained, incorrect message length");	
				}
				else
				{
					exu.comment("Negative Response obtained, unknown reason");	
				}
			}
			else
			{
				exu.comment("Negative Response obtained, Service is incorrect");	
			}	
		}
		else
		{
			exu.comment("Negative Response obtained, Service is incorrect");
		}
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}
}
