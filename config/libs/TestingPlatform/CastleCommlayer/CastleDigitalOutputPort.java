package libs.TestingPlatform.CastleCommlayer;

import java.util.Arrays;

import config.ETS;
import config.ItfDO.EnmBank;
import config.ItfDO.EnmDigitalOutChannels;
import config.ItfDO.EnmVolt;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
public class CastleDigitalOutputPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	EnmDigitalOutChannels fChannelId;
	HighLogicVoltage fHighLogicVoltage;
	ETS exu;

	/**
		 * Digital output logic values.
		 * <P>
		 * Note that PIP V1 supports changing the high logic to 3.3 or 12 volt
		 * but the value is output logic value is set to 5 volt by default. The
		 * tester shall not change the
		 */
		public enum DigitalOutputVal {
			/**
			 * <p>
			 * Logic Low
			 */
			Low,
			/**
			 * <p>
			 * Logic High
			 */
			High
		}

		/**
		 * Digital output Banks.
		 * <P>
		 * Note that PIP V2 supports changing the high logic to 3.3 or 5 volt
		 * but the value is output logic value is configured for the whole Port,
		 * So you configure the high logic for the two ports
		 */
		public enum DigitalOutBanks {
			/**
			 * <p>
			 * Bank One Product Digital Outputs channels [1 - 6]
			 */
			Bank1,
			/**
			 * <p>
			 * Bank Two Product Digital Outputs channels [7 - 12]
			 */
			Bank2,
		}

		/**
		 * Digital output logic values.
		 * <P>
		 * Note that PIP V2 supports changing the high logic to 3.3 or 5 volt
		 * but the value is output logic value is set to 5 volt by default.
		 */
		public enum HighLogicVoltage {
			/**
			 * <p>
			 * High logic is 3 Volt
			 */
			HighLogic_3Volt,
			/**
			 * <p>
			 * High logic is 5 Volt
			 */
			HighLogic_5Volt
		}

     private boolean getDigitalOutState(DigitalOutputVal digValue)
    {
		int logicOut = Arrays.asList(DigitalOutputVal.values()).indexOf(digValue);
    	boolean out;
    	
		if(logicOut ==0)
		{
			out=false;
		}
		else
		{
			out=true;
		}
		return out;
    }
    
    private void setPortVolt(DigitalOutBanks BankID, HighLogicVoltage HighLogicVolt)
    {
    	int index = Arrays.asList(DigitalOutBanks.values()).indexOf(BankID);
    	EnmBank portId = EnmBank.values()[index];
    	
       	index = Arrays.asList(HighLogicVoltage.values()).indexOf(HighLogicVolt);
    	EnmVolt logicVoltage = EnmVolt.values()[index];
    	
    	exu.modTS().objDOutput().afcsetBankVolt(portId, logicVoltage);
    }
	/**
	 * Digital Output
	 * @param channelId
	 * @param highLogicVoltage
	 * @param executionUnit
	 */
	public CastleDigitalOutputPort(EnmDigitalOutChannels channelId, HighLogicVoltage highVoltage, ETS executionUnit){
		fChannelId = channelId;
		fHighLogicVoltage = highVoltage;
		exu = executionUnit;
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args){
		int value = (int)((double)args[0]);
		DigitalOutputVal digValue = DigitalOutputVal.Low;
		if(value > 0)
			digValue = DigitalOutputVal.High;
		else
			digValue = DigitalOutputVal.Low;
			
		switch(fHighLogicVoltage)
		{
			case HighLogic_3Volt:
				exu.comment("Set %s digital output port to %s on %s .", fChannelId.toString(),
						digValue.toString(), fHighLogicVoltage.toString());
				if(fChannelId.toInt() <= 6)
				{
					setPortVolt(DigitalOutBanks.Bank1, HighLogicVoltage.HighLogic_3Volt);
				}
				else if( (fChannelId.toInt() > 6) && (fChannelId.toInt() <= 12))
				{
					setPortVolt(DigitalOutBanks.Bank2, HighLogicVoltage.HighLogic_3Volt);
				}
				else if( (fChannelId.toInt() > 12) && (fChannelId.toInt() <= 18))
				{
					// Do nothing. channels voltage fixed at 3.3 V
				}
				else if( (fChannelId.toInt() > 18) && (fChannelId.toInt() <= 24))
				{
					// Do nothing. channels voltage fixed at 5.0 V
					exu.comment("channels voltage fixed at 5.0 V");
				}
				boolean state = getDigitalOutState(digValue);		
				exu.modTS().objDOutput().afcSetPortOutput(state, fChannelId);
				
			break;
			case HighLogic_5Volt:
				exu.comment("Set %s digital output port to %s on %s .", fChannelId.toString(),
						digValue.toString(), fHighLogicVoltage.toString());
						
				if(fChannelId.toInt() <= 6)
				{
					setPortVolt(DigitalOutBanks.Bank1, HighLogicVoltage.HighLogic_5Volt);
				}
				else if( (fChannelId.toInt() > 6) && (fChannelId.toInt() <= 12))
				{
					setPortVolt(DigitalOutBanks.Bank2, HighLogicVoltage.HighLogic_5Volt);
				}
				else if( (fChannelId.toInt() > 12) && (fChannelId.toInt() <= 18))
				{
					// Do nothing. channels voltage fixed at 3.3 V
					exu.comment("channels voltage fixed at 3.3 V");
				}
				else if( (fChannelId.toInt() > 18) && (fChannelId.toInt() <= 24))
				{
					// Do nothing. channels voltage fixed at 5.0 V
				}
				boolean status = getDigitalOutState(digValue);		
				exu.modTS().objDOutput().afcSetPortOutput(status, fChannelId);
			break;
		}
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}

	public void finalize() throws Throwable {

	}
}