package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mmegahed
 * @version 1.0
 * @created 14-MAY-2019 11:12:00 AM
 * @updated 14-MAY-2019 11:12:00 AM
 * @updated 
 */  
public class CastleMotorSetStallAngle implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	int stallCount = 1;
	ETS exu;
	
	/**
	 * @param stallAngleCount
	 * @param executionUnit
	 */
	public CastleMotorSetStallAngle(int stallAngleCount,ETS executionUnit){
		stallCount = stallAngleCount;
		exu = executionUnit;
	}
	

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
	
		float stallAngle = (float)args[0];
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		switch (stallCount) {
		case 1:
			exu.comment("Set stall angle 1 to %f",stallAngle);
			exu.modTS().objMotorSim().afcSet_Stall_Angle_1(true, stallAngle, 0.1f,0);
			break;
		case 2:
			exu.comment("Set stall angle 2 to %f",stallAngle);
			exu.modTS().objMotorSim().afcSet_Stall_Angle_2(true, stallAngle, 0.1f,0);
			break;
		case 3:
			exu.comment("Set stall angle 3 to %f",stallAngle);
			exu.modTS().objMotorSim().afcSet_Stall_Angle_3(true, stallAngle, 0.1f,0);
			break;
		case 4:
			exu.comment("Set stall angle 4 to %f",stallAngle);
			exu.modTS().objMotorSim().afcSet_Stall_Angle_4(true, stallAngle, 0.1f,0);
			break;
		default:
			break;
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
