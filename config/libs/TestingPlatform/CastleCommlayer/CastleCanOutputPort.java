package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
public class CastleCanOutputPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	String fCanFrame;
	double fPeriodicity;
	ETS exu;
	/**
	 * 
	 * @param canFrame
	 */
	public CastleCanOutputPort(String canSignal, double periodicity, ETS executionUnit){
		this.fCanFrame = canSignal;
		this.fPeriodicity = periodicity;
		exu = executionUnit;
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object... args) {

/*		switch(fCanFrame) {
		case "SIG_ADB_request":
			exu.comment("Set Value of %s canFrame to %f ", fCanFrame ,(double) args[0]);
			CAN.Tx_LCU_STATE.SIG_ADB_request.set((double) args[0]);
			exu.comment("Set canFrame Periodicity to %f ", fPeriodicity);
			CAN.Tx_LCU_STATE.getFrameObject().afcSendPerTimer(fPeriodicity);
			break;
		}*/
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}

	public void finalize() throws Throwable {

	}
}