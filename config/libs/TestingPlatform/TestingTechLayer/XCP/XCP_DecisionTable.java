package libs.TestingPlatform.TestingTechLayer.XCP;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.ICastlePort;

public class XCP_DecisionTable
{

	private static final double No_Val = -1.0;
	public ICastlePort columnsMap[];
	public XCP_EntryValues XCP_TableData[];
	public ETS exu;
	
	
	/**
	 * this method	used to	run	only inputs	in specific	Entry	in the table
	 * 
	 * @param rowIndex
	 */
	private void runEntryInputs(int rowIndex)
	{
		if(XCP_TableData[rowIndex].fInputValue != null)
		{
			for	(int colIndex	=	0; colIndex < XCP_TableData[rowIndex].fInputValue.length ;	colIndex++)
			{
				if(XCP_TableData[rowIndex].fInputValue[colIndex]	!=	No_Val)
				{
						columnsMap[colIndex].apply(XCP_TableData[rowIndex].fInputValue[colIndex]);					
								
				}	
			}
		}
	}
	
	private void runEntryOutputs(int rowIndex)
	{
		if(XCP_TableData[rowIndex].fOutputValue_XCP  != null)
		{
			for	(int colIndex	=	0; colIndex < XCP_TableData[rowIndex].fOutputValue_XCP.length ;	colIndex++)
			{
				if(XCP_TableData[rowIndex].fOutputValue_XCP[colIndex]	!=	null)
				{
					columnsMap[colIndex+ XCP_TableData[rowIndex].fInputValue.length].apply(XCP_TableData[rowIndex].fOutputValue_XCP[colIndex],	
												XCP_TableData[rowIndex].fInToOutDelay,
												XCP_TableData[rowIndex].fInToOutDelayTolerance);				
				}
			}
		}
																
	}
	
	public void runTable()
	{
		exu.comment("******************Start running entry Inputs and outputs *************");

		for	(int rowIndex	=	0; rowIndex	< XCP_TableData.length ; rowIndex++)
		{
			exu.comment("%s",XCP_TableData[rowIndex].fdescription);
			
			runEntryInputs(rowIndex);	
			
			if(XCP_TableData[rowIndex].fInToOutEvent != null)
			{
				exu.comment("********************************Pause Until The Synchronization start************************");
				exu.pauseUntilEvent(XCP_TableData[rowIndex].fInToOutEvent, 10000);
				
			}
			
			runEntryOutputs(rowIndex);
			
			if(XCP_TableData[rowIndex].fInterspaceDelay >=0)
			{
				exu.comment("Pause (%d ms) then excute the next row",(int)XCP_TableData[rowIndex].fInterspaceDelay );
				exu.pause(XCP_TableData[rowIndex].fInterspaceDelay);
				
			}
		}

	}
	
	public void finalize() throws Throwable 
	{

	}

}
