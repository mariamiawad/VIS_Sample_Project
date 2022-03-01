package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import libs.TestingPlatform.CastleCommlayer.CastleXCP_CAN.RLConfiguration;

/**
 * @author Hosam-Eldin Mostafa
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 * @updated maboelkh: 14-Feb-2019 -> V2.0
 */
public class CastleXCP_CanSetPort implements ICastlePort
{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	int 			fAddress;
	String 			fNumberOfBytes;
	RLConfiguration fSide;
	ETS 			exu;
	final public static String Connect  	= "Connect";
	final public static String Disconnect 	= "Disconnect";

	CastleXCP_CAN xcp = new CastleXCP_CAN();

	public CastleXCP_CanSetPort(int Address, String NumberOfBytes, RLConfiguration Side , ETS executionUnit) 
	{
		fAddress 		= Address;
		fNumberOfBytes 	= NumberOfBytes;
		fSide 			= Side;
		exu 			= executionUnit;
	}

	@Override
	public Object[] apply(Object... args) 
	{
		String fSData = (String) args[0];
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		if(fSData != "")
		{
			if(fSData == Connect)
			{
				xcp.XCP_Connect(fSide, exu);
			}
			else if(fSData == Disconnect)
			{
				xcp.XCP_Disconnect(fSide, exu);
			}
			else
			{
				exu.comment("Set ( %s ) Bytes Data: %s to Slave on Address: %s , and Check", fNumberOfBytes, fSData, fAddress);  
				xcp.XCP_Set_data_to_Slave(fAddress, fNumberOfBytes, fSData, fSide, exu);
			}
		
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
