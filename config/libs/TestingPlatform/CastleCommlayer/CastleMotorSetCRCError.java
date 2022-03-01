package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mmegahed
 * @version 1.0
 * @created 14-MAY-2019 11:12:00 AM
 * @updated 14-MAY-2019 11:12:00 AM
 * @updated 
 */  
public class CastleMotorSetCRCError implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	String error;
	ETS exu;
	
	/**
	 * @param errorApplied 
	 * @param executionUnit
	 */
	public CastleMotorSetCRCError(String errorApplied,ETS executionUnit){
		
		error = errorApplied;
		exu = executionUnit;
	}
	

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object... args){
	
		String error = args[0].toString();
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		if(error=="true"){
		
			exu.comment("Apply angle sensor CRC error");
			exu.modTS().objMotorSim().afcSet_MLX_CRC(false);
		
		}
		else if (error == "false"){
		
			exu.comment("Remove angle sensor CRC error");
			exu.modTS().objMotorSim().afcSet_MLX_CRC(true);
		
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
