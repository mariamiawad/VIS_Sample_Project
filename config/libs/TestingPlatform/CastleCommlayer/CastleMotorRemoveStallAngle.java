package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mmegahed
 * @version 1.0
 * @created 14-MAY-2019 11:12:00 AM
 * @updated 14-MAY-2019 11:12:00 AM
 * @updated 
 */  
public class CastleMotorRemoveStallAngle implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	
	/**
	 * @param executionUnit
	 */
	public CastleMotorRemoveStallAngle(ETS executionUnit){
		exu = executionUnit;
	}
	

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
	
		int stallCount =  ((Double) args[0]).intValue();
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		switch (stallCount) {
		case 1:
			exu.comment("Remove stall angle 1 ");
			exu.modTS().objMotorSim().afcSet_Stall_Angle_1(false, 100f, 0.1f,0);
			break;
		case 2:
			exu.comment("Remove stall angle 2 ");
			exu.modTS().objMotorSim().afcSet_Stall_Angle_2(false, 100f, 0.1f,0);
			break;
		case 3:
			exu.comment("Remove stall angle 3 ");
			exu.modTS().objMotorSim().afcSet_Stall_Angle_3(false, 100f, 0.1f,0);
			break;
		case 4:
			exu.comment("Remove stall angle 4 ");
			exu.modTS().objMotorSim().afcSet_Stall_Angle_4(false, 100f, 0.1f,0);
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
