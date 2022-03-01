package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfDefectCell.EnmCellState;
import config.ItfDefectCell.EnmDefectCellChannel;
import config.ItfDefectCell.EnmSupply;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
public class CastleDefectCellPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	EnmDefectCellChannel fCellId;
	EnmCellState fDefectType;
	EnmSupply fDefectBattSource;
	ETS exu;
	
	/**
	 * Defect Cell
	 * @param cellId
	 * @param defectType
	 * @param battSupplySource
	 * @param executionUnit
	 */
	public CastleDefectCellPort(EnmDefectCellChannel cellId, EnmCellState defectType, EnmSupply battSupplySource, ETS executionUnit){
		fDefectBattSource = battSupplySource;
		fCellId = cellId;
		fDefectType = defectType;
		exu = executionUnit;
		
	}
	
	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args){
	switch(fDefectType)
		{
			case OC_ECUA_LoadA:
				if((double)args[0] > 0){
				
						exu.comment("Apply %s defect on defect cells %s",
								fDefectType.toString(), fCellId.toString());
						exu.modTS().objDefectCell().afcSetDefectCell(fCellId, fDefectType);
						
				}
				else{
				exu.comment("Remove %s defect from defect cells %s",
								fDefectType.toString(), fCellId.toString());
					exu.modTS().objDefectCell().afcSetDefectCell(fCellId, EnmCellState.No_Defect);	
				}
			break;
			
			
			
			case SC_LoadA_LoadB:
			if((double)args[0] > 0){
				
						exu.comment("Apply %s defect on defect cells %s",
								fDefectType.toString(), fCellId.toString());
						exu.modTS().objDefectCell().afcSetDefectCell(fCellId, fDefectType);
						
				}
				else{
				exu.comment("Remove %s defect from defect cells %s",
								fDefectType.toString(), fCellId.toString());
					exu.modTS().objDefectCell().afcSetDefectCell(fCellId, EnmCellState.No_Defect);	
				}
			break;
			
		
	default:
		break;
		}
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}

	public void finalize() throws Throwable {

	}
}