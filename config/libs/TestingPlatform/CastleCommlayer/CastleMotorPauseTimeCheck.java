package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mmegahed
 * @version 1.0
 * @created 07-MAY-2019 11:12:00 AM
 * @updated 07-MAY-2019 11:12:00 AM
 * @updated 
 */  
public class CastleMotorPauseTimeCheck implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	int tTolerance;
	ETS exu;
	
	/**
	 * @param tTolerance
	 * @param executionUnit
	 */
	public CastleMotorPauseTimeCheck(int tolerance , ETS executionUnit) {
	
		tTolerance = tolerance;
		exu  = executionUnit;
	}

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
		int pauseTime = ((Double) args[0]).intValue();
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		exu.comment("Check that last INT. time is %d s", pauseTime);
		exu.modTS().objMotorSim().afcCheck_Last_Intermitent_Pause_Millis(pauseTime-tTolerance	,pauseTime+tTolerance);
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
