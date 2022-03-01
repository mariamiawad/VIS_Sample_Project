package libs.TestingPlatform.CastleCommlayer;

import libs.c5.interfaces.C5;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
 
public class CastleCanInputPort implements ICastlePort{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	String fsignal;

	
	public CastleCanInputPort (String signal)
	{
		fsignal = signal;
	}

	@Override
	public Object[] apply(Object...args){
		
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		//it depends on CAN Message Names generated from dbc
		
/*		switch (fsignal){
		case "SIG_ADB_request":
			CAN.Rx_ADB_STATE_R.SIG_ADB_state_right.check(args[0]); 
			break;
		case "SHL_li1_BRL_zusatz_kompl_def":	
			CAN.Rx_ADB_STATE_R.SIG_ADB_state_right.check(args[0]);
			break;
		case "SHL_li1_RFL_def":	
			CAN.Rx_ADB_STATE_R.SIG_ADB_state_right.check(args[0]);
			break;
		}*/
		return ReturnObj();
	}
	
	private void Request_pauseInToOutDelay(double IntoOutDelay){
		if(InToOutDelay_paused == false){
			if(IntoOutDelay > 0){
				C5.Util.comment("Wait for Input to Output Delay of %s mSec", IntoOutDelay);
				C5.pause(IntoOutDelay);
				InToOutDelay_paused = true;
			}
		}
	}
	
	private Object[] ReturnObj(){
		returnObj[0] = InToOutDelay_paused;
		return returnObj;
	}
}
