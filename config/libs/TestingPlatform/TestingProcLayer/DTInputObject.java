package libs.TestingPlatform.TestingProcLayer;

import config.ETS;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;


/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 */

public class DTInputObject {

	public DecisonTableEntryValue DTdate;
	public CastlePortingMap PortingArr[];
	public ETS executionUnitObj;
	
	public void finalize() throws Throwable {

	}
}