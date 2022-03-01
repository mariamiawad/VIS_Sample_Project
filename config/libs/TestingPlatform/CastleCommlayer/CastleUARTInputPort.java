package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mnagah
 * @version 1.0
 * @created 15-Feb-2018 1:53:45 PM
 */ 
public class CastleUARTInputPort implements ICastlePort{
	boolean InToOutDelay_paused = false;
	boolean LastOutput = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	final public static String NoDataReceived  	= "NoDataReceived";

	
	public CastleUARTInputPort (ETS executionUnit)
	{
		exu = executionUnit;
	}

	@Override
	public Object[] apply(Object...args){
		String value =String.valueOf(args[0]) ;
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		LastOutput = (boolean) args[4];
		
		if(InToOutDelay_paused == false){
			exu.comment("Init UART port");
			exu.modTS().objuart().afcInit();
			
			exu.comment("Start receiving on the UART port");
			exu.modTS().objuart().afcStartReceiveData();
			
			exu.comment("Wait for Input to Output Delay of %s mSec", registerTime);
			exu.pause(registerTime);
			
			exu.comment("Stop receiving on the UART port after validation time equal to %s", String.valueOf(registerTime));
			exu.modTS().objuart().afcStopReceiveData();
		
			InToOutDelay_paused = true;
		}
		
		if(value != ""){
			if(value == NoDataReceived)
			{
				exu.comment("Verify that No Data Received on the UART port ");
				exu.modTS().objuart().afcIsNoDataReceived();
			}
			else
			{
				exu.comment("UART Value on the UART port equals to %s within time %s",value ,String.valueOf(registerTime));
				exu.modTS().objuart().afcAssertSequence(value);
			}
		}
		
		if(LastOutput == true){
			exu.comment("Reset UART port");
			exu.modTS().objuart().afcResetBuffers();
			
			exu.comment("Deinit UART port");
			exu.modTS().objuart().afcDeInit();
			
			LastOutput = false;
		}
		
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		returnObj[0] = InToOutDelay_paused;
		return returnObj;
	}
}
