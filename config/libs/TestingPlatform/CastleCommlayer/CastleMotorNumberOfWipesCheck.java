package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfMotor.EnmDirPolarity;

/**
 * @author mmegahed
 * @version 1.0
 * @created 08-MAY-2019 11:12:00 AM
 * @updated 08-MAY-2019 11:12:00 AM
 * @updated 
 */  
public class CastleMotorNumberOfWipesCheck implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	int wTolerance = 0;
	ETS exu;
	
	/**
 	*	@param number of wipes tolerance
 	*	@param executionUnit
 	*/
	public CastleMotorNumberOfWipesCheck(int wipeTolerance, ETS executionUnit) {
	
		wTolerance = wipeTolerance;
		exu  = executionUnit;
	}

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
		int nWipes = ((Double)args[0]).intValue();
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		exu.comment("Check that number of wipes = %d ",nWipes);
		exu.modTS().objMotorSim().afcCheck_Number_Of_Motor_Wipes(nWipes-wTolerance, nWipes+wTolerance);
	
		return ReturnObj();
	}
	
	private void Request_pauseInToOutDelay(double IntoOutDelay){
		if(InToOutDelay_paused == false){
			exu.comment("Wait for Input to Output Delay of %s mSec", IntoOutDelay);
			exu.pause(IntoOutDelay);
			InToOutDelay_paused = true;
		}
	}
	
	private Object[] ReturnObj(){
		returnObj[0] = InToOutDelay_paused;
		return returnObj;
	}
}
