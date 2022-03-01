package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfElmos.EnmDataBits;
import config.ItfElmos.EnmParity;
import config.ItfElmos.EnmStopBits;

/**
 * @author maboelkh
 * @version 1.0
 * @created 22-Jul-2019
 */ 
public class CastleElmosInputPort implements ICastlePort{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	
	public static EnmDataBits 	fDataBits 	= EnmDataBits._8_Data_Bits;
	public static EnmStopBits 	fStopBits 	= EnmStopBits._1_Stop_Bit;
	public static EnmParity 	fParity		= EnmParity._Even_Parity;
	
	ETS exu;
	int fElmosId;
	int fMemoryAddress;
	Elmos_PortType fElmos_PortType;
	int fTolerance;
	
	/**
	 * Elmos Port Type.
	 */
	public enum Elmos_PortType {
		/**
		 * Data Log
		 */
		DataLog,
		/**
		 * Data Sequence
		 */
		DataSequence,
		/**
		 * Data Response
		 */
		DataResponse,
	}

	public CastleElmosInputPort(int ElmosId, int MemoryAddress, Elmos_PortType PortType, int Tolerance, ETS executionUnit)
	{
		exu = executionUnit;
		fElmos_PortType = PortType;
		fElmosId = ElmosId;
		fMemoryAddress = MemoryAddress;
		fTolerance = Tolerance;
	}

	@Override
	public Object[] apply(Object...args){
		int[] value =(int[])args[0] ;
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		
			exu.comment("Reset Elmos Data Log");
			exu.modTS().objElmos().afcResetDataLog();
		
			exu.comment("Start Elmos Data Aquisition");
			exu.modTS().objElmos().afcStartSimulation();
		
			exu.comment("Wait for Input to Output Delay of %s mSec", registerTime);
			exu.pause(registerTime);
			InToOutDelay_paused = true;
			
			exu.comment("Stop Elmos Data Aquisition");
			exu.modTS().objElmos().afcStopSimulation();

		switch(fElmos_PortType){
		case DataLog:
			exu.comment("Assert on Elmos Data Log");
			exu.modTS().objElmos().afcAssertDataLog(fElmosId, fMemoryAddress, value, fTolerance);
		break;
		case DataSequence:
			exu.comment("Assert on Elmos Data Sequence");
			exu.modTS().objElmos().afcAssertSequence(fElmosId, fMemoryAddress, value, fTolerance);
		break;
		case DataResponse:
			exu.comment("Verify Elmos Data Responses");
			exu.modTS().objElmos().afcCheckDataResponse();
		break;
		default:
		break;
		}
		
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		returnObj[0] = InToOutDelay_paused;
		return returnObj;
	}
}
