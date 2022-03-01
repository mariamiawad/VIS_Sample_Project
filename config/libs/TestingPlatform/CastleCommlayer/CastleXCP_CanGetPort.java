package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.Itf_SignalValue.EnmToleranceType;
import libs.TestingPlatform.CastleCommlayer.CastleXCP_CAN.RLConfiguration;
import libs.TestingPlatform.TestingTechLayer.DecisionTable;

/**
 * @author Hosam-Eldin Mostafa
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 * @updated maboelkh: 14-Feb-2019 -> V2.0
 */
public class CastleXCP_CanGetPort implements ICastlePort
{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	int 			 fAddress;
	String 			 fNumberOfBytes;
	String 			 fMask;
	long 			 fToleranceValue;
	EnmToleranceType fToleranceType;
	RLConfiguration  fSide;
	XCP_PortType 	 fXCP_PortType;
	ETS 			 exu;
	final public static String Connect  	= "Connect";
	final public static String Disconnect 	= "Disconnect";
	final public static double RESET		= -2.0;

	CastleXCP_CAN xcp = new CastleXCP_CAN();

	/**
	 * XCP CAN Get Port Type.
	 */
	public enum XCP_PortType {
		/**
		 * Equals Check
		 */
		EqualsCheck,
		/**
		 * Masked Equals Check
		 */
		MaskedEqualsCheck,
		/**
		 * In Range Check
		 */
		InRangeCheck,
	}

	public CastleXCP_CanGetPort(int Address, String NumberOfBytes, String Mask, long ToleranceValue, EnmToleranceType ToleranceType, RLConfiguration Side , XCP_PortType XCP_portType, ETS executionUnit)
	{
		fAddress 		= Address;
		fNumberOfBytes 	= NumberOfBytes;
		fMask 			= Mask;
		fToleranceValue = ToleranceValue;
		fToleranceType 	= ToleranceType;
		fSide 			= Side;
		fXCP_PortType	= XCP_portType;
		exu 			= executionUnit;
	}

	@Override
	public Object[] apply(Object... args) 
	{
		String fSData;
		double fData;
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		Request_pauseInToOutDelay(registerTime);
		
		switch(fXCP_PortType)
		{
			case EqualsCheck:
				fSData = (String) args[0];
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
						exu.comment("Get ( %s ) Bytes Data from Slave on Address: %s , and Check", fNumberOfBytes, fAddress);  
						xcp.XCP_Get_data_from_Slave_And_Check(fAddress, fNumberOfBytes, fSData, fSide, exu);
					}
				}
			break;
			case MaskedEqualsCheck:
				fSData = (String) args[0];
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
						exu.comment("Get ( %s ) Bytes Data from Slave on Address: %s , and Check", fNumberOfBytes, fAddress);  
						xcp.XCP_Get_data_from_Slave_And_Check(fAddress, fNumberOfBytes, fMask, fSData, fSide, exu);
					}
				}
			break;
			case InRangeCheck:
				fData = (double) args[0];
				if(fData == RESET)
				{
					xcp.XCP_Connect(fSide, exu);
				}
				else
				{
					exu.comment("Get ( %s ) Bytes Data from Slave on Address: %s , and Check", fNumberOfBytes, fAddress);  
					xcp.XCP_Get_DataInRange_from_Slave_And_Check(fAddress, fNumberOfBytes, fData, fToleranceValue, fToleranceType, fSide, exu);
				}
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