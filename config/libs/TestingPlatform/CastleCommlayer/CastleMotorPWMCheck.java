package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mmegahed
 * @version 1.0
 * @created 07-MAY-2019 11:12:00 AM
 * @updated 07-MAY-2019 11:12:00 AM
 * @updated 
 */  
public class CastleMotorPWMCheck implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	double fTolerance=0;
	ETS exu;
	
	/**
	 * 
	 * @param tolerance
	 * @param executionUnit
	 */
	public CastleMotorPWMCheck(double tolerance , ETS executionUnit){
		fTolerance = tolerance;
		exu = executionUnit;
	}
	

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
		double PWM =(double) args[0];
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		exu.comment("Check that motor PWM is in range %f",(PWM-fTolerance)," , %f",(PWM+fTolerance) );
		exu.modTS().objMotorSim().afcCheck_PWM(PWM-fTolerance, PWM+fTolerance);
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
