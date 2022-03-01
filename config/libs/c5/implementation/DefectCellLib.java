package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import config.ETS;
import config.ItfDefectCell.EnmCellState;
import config.ItfDefectCell.EnmDefectCellChannel;
import config.ItfDefectCell.EnmSupply;
import libs.c5.interfaces.C5.Defect.DefectCell;
import libs.c5.interfaces.C5.Defect.DefectType;
import libs.c5.interfaces.C5.Defect.ScToBattSrc;


public class DefectCellLib {
	
	/** Execution Unit corresponding to this library instance */
	ETS exu;

	/**
	 * Class Constructors
	 **/
	public DefectCellLib() {
	}

	public DefectCellLib(IExu exu) {
		this.exu = (ETS) exu;
	}

	/**
	 * Set the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @param exu
	 *            instance of execution unit
	 */
	public void setExu(IExu exu) {
		this.exu = (ETS) exu;
	}

	/**
	 * Get the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @return used execution unit instance for current object
	 */
	public ETS exu() {
		return exu;
	}

	/**
	 * Remove all the applied defects.
	 * 
	 * @category Firmware Action
	 */
	public void removeAllDefects()
	{
		exu.modTS().objDefectCell().afcRemoveAllDefects();
	}

	/**
	 * Configure the source for the short circuit to battery
	 * 
	 * @category Firmware Action
	 * @param defectSrc
	 *            Index of the power supply channel
	 *            
	 * @See {@link libs.c5.interfaces.C5.Defect.ScToBattSrc Source of S.C to Battery}
	 *      Channels Enum}
	 */
	public void setSourceOfShortCircuitToBattery(ScToBattSrc defectSrc) {

		EnmSupply scToBattDefectsource  = getScToSuppSrc(defectSrc);
		exu.modTS().objDefectCell().afcSetDefectSupply(scToBattDefectsource );
	}
	
	/**
	 * Configure the defect cell to one of the pre-configured defects
	 * 
	 * @category Firmware Action
	 * @param defectCellIndx
	 *            Index of the defect cell
	 *            
	 * @param defectType
	 *            The type of the defect that will be requested on this cell
	 *            
	 * @See {@link libs.c5.interfaces.C5.Defect.DefectCell Cell Index}
	 * @See {@link libs.c5.interfaces.C5.Defect.DefectType Defect Type}
	 *   
	 */
	public void setDefectCellDefectType(DefectCell defectCellIndx ,DefectType defectType) {

		setDefect( defectCellIndx , defectType);
	}
	
	
	private void setDefect(DefectCell defectCellIndx ,DefectType defectType) {

		EnmDefectCellChannel cellCh = getDefectCellChnl(defectCellIndx);
		EnmCellState cellDefectType = getDefectCellState(defectType);
		
		exu.modTS().objDefectCell().afcSetDefectCell(cellCh, cellDefectType);
	}
	
	private EnmDefectCellChannel getDefectCellChnl(DefectCell defectCellIndx) {

		int index = Arrays.asList(DefectCell.values()).indexOf(defectCellIndx);

		return EnmDefectCellChannel.values()[index];
	}
	
	private EnmCellState getDefectCellState(DefectType defectType) {

		int index = Arrays.asList(DefectType.values()).indexOf(defectType);

		return EnmCellState.values()[index];
	}
	
	private EnmSupply getScToSuppSrc(ScToBattSrc defectSrc) {

		int index = Arrays.asList(ScToBattSrc.values()).indexOf(defectSrc);

		return EnmSupply.values()[index];
	}

}
