package libs.TestingPlatform.TestingTechLayer;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.ICastlePort;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 */
public class StateMachine {

	private static double No_Val =-1.0;
	public ICastlePort columnsMap[];
	public StateMachineEntryValues stateMachineTableData[];
	public ETS exu;

	/**
	 * this method	used to	run	only inputs	in specific	Entry to let the system moves from State to another State
	 * 
	 * @param rowIndex
	 */
	private void runEntryInputs(int rowIndex){
		if(stateMachineTableData[rowIndex].fFinalState != stateMachineTableData[rowIndex].fInitialState){
			if(stateMachineTableData[rowIndex].fInputValue != null)
			{
				for	(int colIndex	=	0; colIndex < stateMachineTableData[rowIndex].fInputValue.length ;	colIndex++)
				{
					if(stateMachineTableData[rowIndex].fInputValue[colIndex]	!=	No_Val){
						columnsMap[colIndex].apply(stateMachineTableData[rowIndex].fInputValue[colIndex]);	
					}			
				}
			}
			if(stateMachineTableData[rowIndex].fSInputValue != null)
			{
				for	(int colIndex	=	0; colIndex < stateMachineTableData[rowIndex].fSInputValue.length ;	colIndex++)
				{
					if(stateMachineTableData[rowIndex].fSInputValue[colIndex]	!=	""){
						columnsMap[colIndex].apply(stateMachineTableData[rowIndex].fSInputValue[colIndex]);	
					}			
				}
			}			
		}
		return;
	}

	public void runTable(){
		exu.comment("******************Start running entry Inputs to move to the next State *************");

		for	(int rowIndex	=	0; rowIndex	< stateMachineTableData.length ; rowIndex++)
		{
			exu.comment("%s",stateMachineTableData[rowIndex].fdescription);
			runEntryInputs(rowIndex);	
			if(stateMachineTableData[rowIndex].fStateEvent != null){
				exu.comment("********************************Pause Until The Synchronization start************************");
				exu.pauseUntilEvent(stateMachineTableData[rowIndex].fStateEvent, 10000);
				
			}

			if(stateMachineTableData[rowIndex].fTimetoFinalStateDelay >=0){
				exu.pause(stateMachineTableData[rowIndex].fTimetoFinalStateDelay);
				exu.comment("Pause (%d ms) to check moving to the next State",(int)stateMachineTableData[rowIndex].fTimetoFinalStateDelay );
			}
		}
	}

	public void finalize() throws Throwable {

	}

}