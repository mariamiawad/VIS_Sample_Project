package libs.TestingPlatform.TestingTechLayer;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.ICastlePort;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 * @Updated 05-OCT-2020 ahamisa
 */
public class DecisionTable {

	final public static double No_Val = -1.0;
	public ICastlePort columnsMap[];
	public DecisonTableEntryValue decisionTableData[];
	public DecisonTableEntryValueWithReqID  decisionTableDataWithReqID[];
	private Object[] ReturnedObj;
	private boolean InToOutDelay_paused = false;
	private boolean LastOutput = false;
	public ETS exu;

	/**
	 * this method	used to	run	only inputs	in specific	Entry	in the table
	 * 
	 * @param rowIndex
	 */
	private void runEntryInputs(int rowIndex){
		if(decisionTableData[rowIndex].fInputValue != null)
		{
			for	(int colIndex	=	0; colIndex < decisionTableData[rowIndex].fInputValue.length ;	colIndex++)
			{
				if(decisionTableData[rowIndex].fInputValue[colIndex]	!=	No_Val){
					columnsMap[colIndex].apply(decisionTableData[rowIndex].fInputValue[colIndex]);	
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
		InToOutDelay_paused = false;
		if(decisionTableData[rowIndex].fSOutputValue != null)
		{
			for	(int colIndex	=	0;	colIndex < decisionTableData[rowIndex].fSOutputValue.length; colIndex++)	{
				if(decisionTableData[rowIndex].fSOutputValue[colIndex] != "No_Val" ){
				if(colIndex+1 == decisionTableData[rowIndex].fSOutputValue.length){
					LastOutput = true;
				}
				else{
					LastOutput = false;
				}
				ReturnedObj = 
				columnsMap[colIndex+ decisionTableData[rowIndex].fInputValue.length ] .apply( decisionTableData[rowIndex].fSOutputValue[colIndex],
				decisionTableData[rowIndex].fInToOutDelay,
				decisionTableData[rowIndex].fInToOutDelayTolerance,
				InToOutDelay_paused,
				LastOutput);
				InToOutDelay_paused = (boolean)ReturnedObj[0];
				}
			}
		}
		if(decisionTableData[rowIndex].fOutputValue != null)
		{
			for	(int colIndex	=	0;	colIndex < decisionTableData[rowIndex].fOutputValue.length; colIndex++)	{
				if(decisionTableData[rowIndex].fOutputValue[colIndex] != No_Val ){
				ReturnedObj = 
				columnsMap[colIndex+ decisionTableData[rowIndex].fInputValue.length ] .apply( decisionTableData[rowIndex].fOutputValue[colIndex],
				decisionTableData[rowIndex].fInToOutDelay,
				decisionTableData[rowIndex].fInToOutDelayTolerance,
				InToOutDelay_paused);
				InToOutDelay_paused = (boolean)ReturnedObj[0];
				}
			}
		}
		if(decisionTableData[rowIndex].fIOutputValue != null)
		{
			if(decisionTableData[rowIndex].fIOutputValue[0] != (int)No_Val){
				ReturnedObj = 
				columnsMap[decisionTableData[rowIndex].fInputValue.length ] .apply( decisionTableData[rowIndex].fIOutputValue,
				decisionTableData[rowIndex].fInToOutDelay,
				decisionTableData[rowIndex].fInToOutDelayTolerance,
				InToOutDelay_paused);
				InToOutDelay_paused = (boolean)ReturnedObj[0];
			}
		}
	}

   public void runTable(){
		exu.comment("****************** Start Executing the Decision Table entry Inputs and outputs ******************");

		for	(int rowIndex	=	0; rowIndex	< decisionTableData.length ; rowIndex++)
		{
			exu.comment("%s",decisionTableData[rowIndex].fdescription);
			runEntryInputs(rowIndex);	
			if(decisionTableData[rowIndex].fInToOutEvent != null){
				exu.comment("********************************Pause Until The Synchronization start************************");
				exu.pauseUntilEvent(decisionTableData[rowIndex].fInToOutEvent, 10000);
				
			}
			runEntryOutputs(rowIndex);
			if(decisionTableData[rowIndex].fInterspaceDelay >=0){
				exu.comment("Pause (%d ms) then excute the next row",(int)decisionTableData[rowIndex].fInterspaceDelay );
				exu.pause(decisionTableData[rowIndex].fInterspaceDelay);
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

   private void runEntryInputsWithReqID(int rowIndex){
		if(decisionTableDataWithReqID[rowIndex].fInputValue != null)
		{
			for	(int colIndex	=	0; colIndex < decisionTableDataWithReqID[rowIndex].fInputValue.length ;	colIndex++)
			{
				if(decisionTableDataWithReqID[rowIndex].fInputValue[colIndex]	!=	No_Val){
					columnsMap[colIndex].apply(decisionTableDataWithReqID[rowIndex].fInputValue[colIndex]);	
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
	private void runEntryOutputsWithReqID(int rowIndex){
		InToOutDelay_paused = false;
		if(decisionTableDataWithReqID[rowIndex].fSOutputValue != null)
		{
			for	(int colIndex	=	0;	colIndex < decisionTableDataWithReqID[rowIndex].fSOutputValue.length; colIndex++)	{
				if(decisionTableDataWithReqID[rowIndex].fSOutputValue[colIndex] != "No_Val" ){
				if(colIndex+1 == decisionTableDataWithReqID[rowIndex].fSOutputValue.length){
					LastOutput = true;
				}
				else{
					LastOutput = false;
				}
				ReturnedObj = 
				columnsMap[colIndex+ decisionTableDataWithReqID[rowIndex].fInputValue.length ] .apply( decisionTableDataWithReqID[rowIndex].fSOutputValue[colIndex],
				decisionTableDataWithReqID[rowIndex].fInToOutDelay,
				decisionTableDataWithReqID[rowIndex].fInToOutDelayTolerance,
				InToOutDelay_paused,
				LastOutput);
				InToOutDelay_paused = (boolean)ReturnedObj[0];
				}
			}
		}
		if(decisionTableDataWithReqID[rowIndex].fOutputValue != null)
		{
			for	(int colIndex	=	0;	colIndex < decisionTableDataWithReqID[rowIndex].fOutputValue.length; colIndex++)	{
				if(decisionTableDataWithReqID[rowIndex].fOutputValue[colIndex] != No_Val ){
				ReturnedObj = 
				columnsMap[colIndex+ decisionTableDataWithReqID[rowIndex].fInputValue.length ] .apply( decisionTableDataWithReqID[rowIndex].fOutputValue[colIndex],
				decisionTableDataWithReqID[rowIndex].fInToOutDelay,
				decisionTableDataWithReqID[rowIndex].fInToOutDelayTolerance,
				InToOutDelay_paused);
				InToOutDelay_paused = (boolean)ReturnedObj[0];
				}
			}
		}
		if(decisionTableDataWithReqID[rowIndex].fIOutputValue != null)
		{
			if(decisionTableDataWithReqID[rowIndex].fIOutputValue[0] != (int)No_Val){
				ReturnedObj = 
				columnsMap[decisionTableDataWithReqID[rowIndex].fInputValue.length ] .apply( decisionTableDataWithReqID[rowIndex].fIOutputValue,
				decisionTableDataWithReqID[rowIndex].fInToOutDelay,
				decisionTableDataWithReqID[rowIndex].fInToOutDelayTolerance,
				InToOutDelay_paused);
				InToOutDelay_paused = (boolean)ReturnedObj[0];
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	public void runTableWithReqID(){
		exu.comment("****************** Start Executing the Decision Table entry Inputs and outputs ******************");

		for	(int rowIndex	=	0; rowIndex	< decisionTableDataWithReqID.length ; rowIndex++)
		{
			exu.comment("%s",decisionTableDataWithReqID[rowIndex].fdescription);
			if(decisionTableDataWithReqID[rowIndex].fRequirement=="")
    		{
			/* do nothing */
			}
			else
			{
			//exu.addRequirement(decisionTableDataWithReqID[rowIndex].fRequirement);
			}
			runEntryInputsWithReqID(rowIndex);	
			if(decisionTableDataWithReqID[rowIndex].fInToOutEvent != null){
				exu.comment("********************************Pause Until The Synchronization start************************");
				exu.pauseUntilEvent(decisionTableDataWithReqID[rowIndex].fInToOutEvent, 10000);
				
			}
			runEntryOutputsWithReqID(rowIndex);
			if(decisionTableDataWithReqID[rowIndex].fInterspaceDelay >=0){
				exu.comment("Pause (%d ms) then excute the next row",(int)decisionTableDataWithReqID[rowIndex].fInterspaceDelay );
				exu.pause(decisionTableDataWithReqID[rowIndex].fInterspaceDelay);
			}
		}
	}

	public void finalize() throws Throwable {

	}
}