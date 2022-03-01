package libs.TestingPlatform.TestingTechLayer;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager;
import libs.TestingPlatform.TestingTechLayer.UDS.UDS_DecisionTable;
import libs.TestingPlatform.TestingTechLayer.UDS.UDS_EntryValues;
import libs.TestingPlatform.TestingTechLayer.XCP.XCP_DecisionTable;
import libs.TestingPlatform.TestingTechLayer.XCP.XCP_EntryValues;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 * @Updated 04-OCT-2020 ahamisa
 */	
public class TestingTechManager {

	public CastleCommManager castleCommManagerObj = new CastleCommManager();
	public DecisonTableEntryValue DTEntryDataArr[];
	public DecisonTableEntryValueWithReqID DTEntryDataArrWithReqID[];
	public StateMachineEntryValues STEntryDataArr[];
	public CastlePortingMap ICastlePortArr[];
	public ETS executionUnit;
	private DecisionTable DTObj = new DecisionTable();
	private StateMachine SMObj = new StateMachine();
	private XCP_DecisionTable XCPObj = new XCP_DecisionTable();
	private UDS_DecisionTable UDSObj = new UDS_DecisionTable();

	public void RunDT(DecisonTableEntryValue DTarray[], CastlePortingMap castlePortArr,ETS exeunit){
		
		// Fill all Decision Table Objects.
		DTObj.decisionTableData = DTarray;
		DTObj.columnsMap = castlePortArr.castlePortingArr;
		DTObj.exu = exeunit;	
		
		// Call RunTable to execute all rows in DT
		DTObj.runTable();
	}
/////////////////////////////////////////////////////////////////////////////////////////////////

public void RunDTWithReqID(DecisonTableEntryValueWithReqID DTarrayWithReqID[], CastlePortingMap castlePortArr,ETS exeunit){
		
	    // Fill all Decision Table Objects.
		DTObj.decisionTableDataWithReqID = DTarrayWithReqID;
		DTObj.columnsMap = castlePortArr.castlePortingArr;
		DTObj.exu = exeunit;	
		
		// Call RunTableWithReqID to execute all rows in DT
		DTObj.runTableWithReqID();
	}


	public void RunSM(StateMachineEntryValues SMarray[], CastlePortingMap castlePortArr,ETS exeunit){
		// Fill all Decision Table Objects.
		SMObj.stateMachineTableData = SMarray;
		SMObj.columnsMap = castlePortArr.castlePortingArr;
		SMObj.exu = exeunit;
				
		// Call RunTable to execute all rows in DT
		SMObj.runTable();
	}
	
	public void RunXCP(XCP_EntryValues XCP_Table[], CastlePortingMap castlePortArr,ETS exeunit){
		// Fill all Decision Table Objects.
		XCPObj.XCP_TableData = XCP_Table;
		XCPObj.columnsMap = castlePortArr.castlePortingArr;
		XCPObj.exu = exeunit;
				
		// Call RunTable to execute all rows in DT
		XCPObj.runTable();
	}
	
	public void RunUDS(UDS_EntryValues[ ] UDS_Table, CastlePortingMap castlePortArr,ETS exeunit){
		// Fill all Decision Table Objects.
		UDSObj.UDS_decisionTableData = UDS_Table;
		UDSObj.columnsMap = castlePortArr.castlePortingArr;
		UDSObj.exu = exeunit;
				
		// Call RunTable to execute all rows in DT
		UDSObj.runTable();
	}
	
	
	public void finalize() throws Throwable {

	}

}