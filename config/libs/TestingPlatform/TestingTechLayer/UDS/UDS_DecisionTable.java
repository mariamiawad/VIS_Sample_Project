package libs.TestingPlatform.TestingTechLayer.UDS;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.ICastlePort;

public class UDS_DecisionTable
{

	private static double No_Val =-1.0;
	public ICastlePort columnsMap[];
	public UDS_EntryValues UDS_decisionTableData[];
	public ETS exu;

	/**
	 * this method	used to	run	only inputs	in specific	Entry	in the table
	 * 
	 * @param rowIndex
	 */
	private void runEntryInputs(int rowIndex){
		if(UDS_decisionTableData[rowIndex].fInputValue != null)
		{
			for	(int colIndex	=	0; colIndex < UDS_decisionTableData[rowIndex].fInputValue.length ;	colIndex++)
			{
				if(UDS_decisionTableData[rowIndex].fInputValue[colIndex]	!=	"No_Val"){
					columnsMap[colIndex].apply(UDS_decisionTableData[rowIndex].fInputValue[colIndex]);	
				}			
			}
		}
		return;
	}

	/**
	 * this method	used to	run	only inputs	in specific	Entry	in the table
	 * 
	 * @param rowIndex
	 */
	private void runEntryOutputs(int rowIndex){
		if(UDS_decisionTableData[rowIndex].fSOutputValue != null)
		{
			for	(int colIndex	=	0;	colIndex < UDS_decisionTableData[rowIndex].fSOutputValue.length; colIndex++)	{
				if(UDS_decisionTableData[rowIndex].fSOutputValue[colIndex] != "No_Val" ){
				columnsMap[colIndex+ UDS_decisionTableData[rowIndex].fInputValue.length ] .apply( UDS_decisionTableData[rowIndex].fSOutputValue[colIndex],
				UDS_decisionTableData[rowIndex].fInToOutDelay,
				UDS_decisionTableData[rowIndex].fInToOutDelayTolerance);
				}
			}
		}
		if(UDS_decisionTableData[rowIndex].fOutputValue != null)
		{
			for	(int colIndex	=	0;	colIndex < UDS_decisionTableData[rowIndex].fOutputValue.length; colIndex++)	{
				if(UDS_decisionTableData[rowIndex].fOutputValue[colIndex] != No_Val ){
				columnsMap[colIndex+ UDS_decisionTableData[rowIndex].fInputValue.length ] .apply( UDS_decisionTableData[rowIndex].fOutputValue[colIndex],
				UDS_decisionTableData[rowIndex].fInToOutDelay,
				UDS_decisionTableData[rowIndex].fInToOutDelayTolerance);
				}
			}
		}
	}

	public void runTable(){
		exu.comment("******************Start running entry Inputs and outputs *************");

		for	(int rowIndex	=	0; rowIndex	< UDS_decisionTableData.length ; rowIndex++)
		{
			exu.comment("%s",UDS_decisionTableData[rowIndex].fdescription);
			runEntryInputs(rowIndex);	
			if(UDS_decisionTableData[rowIndex].fInToOutEvent != null){
				exu.comment("********************************Pause Until The Synchronization start************************");
				exu.pauseUntilEvent(UDS_decisionTableData[rowIndex].fInToOutEvent, 10000);
				
			}
			runEntryOutputs(rowIndex);
			if(UDS_decisionTableData[rowIndex].fInterspaceDelay >=0){
				exu.pause(UDS_decisionTableData[rowIndex].fInterspaceDelay);
				exu.comment("Pause (%d ms) then excute the next row",(int)UDS_decisionTableData[rowIndex].fInterspaceDelay );
			}
		}
	}

}
