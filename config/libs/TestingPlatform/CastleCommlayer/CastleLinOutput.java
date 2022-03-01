package libs.TestingPlatform.CastleCommlayer;

import config.ETS;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
public class CastleLinOutput implements ICastlePort{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	LinOutType fLinOutType;
	public final double RESET = -2.0;
	ETS exu;
	String fsignalFrame;
	
	public enum LinOutType {
			/**
			 * LinOutType
			 * <p>
			 * Signal Value to be sent through LIN
			 */
			SignalValue,
			/**
			 * LinOutType
			 * <p>
			 * Frame Value to be sent through LIN
			 */
			FrameValue,
		}

	public CastleLinOutput (LinOutType linOutType, String signalFrame, ETS executionUnit)
	{
		exu = executionUnit;
		fsignalFrame = signalFrame;
		fLinOutType = linOutType;
	}

	@Override
	public Object[] apply(Object...args){
		switch(fLinOutType)
		{
			case SignalValue:
					int signalValue = (int)((double)args[0]);
		
					if(signalValue == RESET)
					{
						signalValue = 0;
			
					}
			// it depends on LIN Messages names generated from LPF
				/*
				switch (fsignalFrame){
					case "Sig_NIVEAU_INTENSITE_ARS":
						exu.comment();
						LIN_Network3.Tx_CDE_FEU_AR.Sig_NIVEAU_INTENSITE_ARS.set(signalValue);
					break;
						
					case "Sig_INTERD_MEMO_DEF":
						LIN_Network3.Tx_CDE_FEU_AR.Sig_INTERD_MEMO_DEF.set(signalValue);
					break;
				}	*/
			break;
			
			case FrameValue:
				String frameValue = args[0].toString();
			// it depends on LIN Messages names generated from LPF
				
				switch (fsignalFrame){
				/*	case "Tx_CDE_FEU_AR":
						exu.comment();
						LIN_Network3.Tx_CDE_FEU_AR.set(frameValue);
					break;
						*/
				}	
			break;
		}
		
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}


}
