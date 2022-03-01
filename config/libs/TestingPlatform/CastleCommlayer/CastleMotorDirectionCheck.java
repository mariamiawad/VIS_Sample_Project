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
public class CastleMotorDirectionCheck implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	
	/**
	 * @param executionUnit
	 */
	public CastleMotorDirectionCheck( ETS executionUnit) {
	
	
		exu  = executionUnit;
	}

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
		String direction =  args[0].toString();
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		if (direction == "IW")
		{
			// IW Direction
			exu.comment("Check that motor direction is IW");
			exu.modTS().objMotorSim().afcCheck_Motor_Direction(EnmDirPolarity.IW);
		}
		else if (direction == "OW")
		{
			// OW Direction
			exu.comment("Check that motor direction is OW");
			exu.modTS().objMotorSim().afcCheck_Motor_Direction(EnmDirPolarity.OW);
		
		}
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
