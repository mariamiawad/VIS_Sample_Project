package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mnagah
 * @version 1.0
 * @created 15-Feb-2018 1:53:45 PM
 */ 
public class CastleSPIInputPort implements ICastlePort{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	int fBufferSize;
	ETS exu;
	String fMask;

	
	public CastleSPIInputPort (int bufferSize, String Mask, ETS executionUnit)
	{
		exu = executionUnit;
		fBufferSize = bufferSize;
		fMask = Mask;
	}

	@Override
	public Object[] apply(Object...args){
		String value =String.valueOf(args[0]) ;
		double registerTime = (double) args[1];
		
		String[] sData = value.toString().split(" ");
		int[] data= new int[sData.length];
		for(int index = 0; index < sData.length; index++)
		{
		   data[index] = Integer.parseInt(sData[index]);
		}
		
		String[] sMask = fMask.toString().split(" ");
		int[] mask= new int[sMask.length];
		for(int index = 0; index < sMask.length; index++)
		{
		   mask[index] = Integer.parseInt(sMask[index]);
		}
		exu.comment("Init SPI port");
		exu.modTS().objspiSlave16bit().afcInit();
		
		exu.comment("Set SPI Buffer Size to %s ", String.valueOf(fBufferSize));
		exu.modTS().objspiSlave16bit().afcSetBufferSize(fBufferSize);
		
		exu.pause(registerTime);
		
		exu.comment("Start receiving on the SPI port");
		exu.modTS().objspiSlave16bit().afcStartReceiveData();
	
		exu.comment("Stop receiving on the SPI port");
		exu.modTS().objspiSlave16bit().afcStopReceiveData();
       
		exu.pause(50);
       
		exu.comment("SPI Value on the SPI port equals to %s within time %s",value ,String.valueOf(registerTime));
		exu.modTS().objspiSlave16bit().afcAssertRXBuffer(data, mask);
       
		exu.comment("Reset SPI port");
		exu.modTS().objspiSlave16bit().afcResetBuffers();
       
		exu.comment("Deinit SPI port");
		exu.modTS().objspiSlave16bit().afcDeInit();
	
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		returnObj[0] = true;
		return returnObj;
	}
}
