package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfMotor.EnmIWOW_Check;

/**
 * @author mmegahed
 * @version 1.0
 * @created 07-MAY-2019 11:12:00 AM
 * @updated 07-MAY-2019 11:12:00 AM
 * @updated 
 */  
public class CastleMotorSpeedCheck implements ICastlePort {

	/**
	 *	speed tolerance
	 *	angle tolerance
	 */
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	int sTolerance = 2;
	int aTolerance = 3;
	float OW_angle = (float) 150.0;
	float IW_angle = (float) 23.0;
	ETS exu;
	
	
	/**
	 *	@param Speed tolerance
	 *	@param Angle tolerance
	 *	@param IW angle
	 *	@param OW angle
	 *	@param executionUnit
	 */
	public CastleMotorSpeedCheck(int tolerance1,int tolerance2,float IW,float OW,ETS executionUnit) {
		
		sTolerance = tolerance1;
		aTolerance = tolerance2;
		OW_angle = OW;
		IW_angle = IW;
		exu = executionUnit ;
	}

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
		int speed = ((Double)args[0]).intValue();
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		float HC_time = 60.0f/(2.0f*speed);
		float HC_tol  = (2.0f*sTolerance)/60.0f;
		
		Request_pauseInToOutDelay(registerTime);
		
		exu.comment("Check that motor speed is %d between %f and %f",speed,IW_angle,OW_angle);
		exu.modTS().objMotorSim().afcCheck_Motor_Cycle_Time(HC_time, HC_tol, EnmIWOW_Check.BOTH, IW_angle, OW_angle, aTolerance);
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
