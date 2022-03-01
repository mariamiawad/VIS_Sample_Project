package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;
import config.ItfDI.EnmDigitalInputChannelID;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager.PortType;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */
public class CastleDigitalInputPort implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	public final double RESET = -2.0;
	int EDGE = 0;
	int LEVEL = 1;
	ETS exu;
	EnmDigitalInputChannelID fChannelId;
	double fprevVal = RESET;
	public static PortType fPortType = PortType.Eventbased;
	
	/**
	 * 
	 * @param channelId
	 * @param name
	 */
	public CastleDigitalInputPort(EnmDigitalInputChannelID channelId, ETS executionUnit){
		fChannelId = channelId;
		exu = executionUnit;
		
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args){
		double value =(double) args[0];
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		switch(fPortType)
			{
				case Eventbased:
					IEvent evDigReached = exu.modTS().objDInput().objDigitalInput(fChannelId.ordinal()).evtValueReached();
			
					if(value == RESET)
					{
						fprevVal =RESET;
						return ReturnObj();
					}
					if(fprevVal == RESET)
					{
						fprevVal = value;
						if (value == 0)
						{    
						    Request_pauseInToOutDelay(registerTime);
							exu.comment("Start the digital inputs capture task on channel %s ", fChannelId.toString());
							exu.modTS().objDInput().afcstartDigitalInputTask(fChannelId);
							exu.comment("assert Digital value from channel %s ",fChannelId.toString());
							exu.modTS().objDInput().afcAssertDigitalInputValue(false, fChannelId);
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start the digital inputs capture task on channel %s ", fChannelId.toString());
							exu.modTS().objDInput().afcstartDigitalInputTask(fChannelId);
							exu.comment("assert Digital value from channel %s ",fChannelId.toString());
							exu.modTS().objDInput().afcAssertDigitalInputValue(true, fChannelId);
						}
					}
					else if( value != fprevVal )
					{	
						exu.comment("Start the digital inputs capture task on channel %s ", fChannelId.toString());
						exu.modTS().objDInput().afcstartDigitalInputTask(fChannelId);
						exu.comment("Digital input Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),(int)value,(int) registerTime);
						exu.modTS().objDInput().objDigitalInput(fChannelId.ordinal()).afcCheckEventBasedSignals(
								evDigReached.getModEventId(),
								EDGE,
								(int)value,
								0,
								registerTime,
								registerTimeTolerance
								,1
								);
						fprevVal = value;
					}
					else if(value == fprevVal) 
					{
						exu.comment("Start the digital inputs capture task on channel %s ", fChannelId.toString());
						exu.modTS().objDInput().afcstartDigitalInputTask(fChannelId);
						exu.comment("Digital input Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),(int)value,(int) registerTime);
						exu.modTS().objDInput().objDigitalInput(fChannelId.ordinal()).afcCheckEventBasedSignals(
								evDigReached.getModEventId(),
								LEVEL,
								(int)value,
								0,
								registerTime,
								registerTimeTolerance
								,1
								);	
						fprevVal = value;
					}
				break;
				case Timebased:
					if(value == RESET)
					{
						return ReturnObj();
					}
					else 
					{	
						if (value == 0)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start the digital inputs capture task on channel %s ", fChannelId.toString());
							exu.modTS().objDInput().afcstartDigitalInputTask(fChannelId);
							exu.comment("assert Digital value from channel %s ",fChannelId.toString());
							exu.modTS().objDInput().afcAssertDigitalInputValue(false, fChannelId);
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start the digital inputs capture task on channel %s ", fChannelId.toString());
							exu.modTS().objDInput().afcstartDigitalInputTask(fChannelId);
							exu.comment("assert Digital value from channel %s ",fChannelId.toString());
							exu.modTS().objDInput().afcAssertDigitalInputValue(true, fChannelId);
						}
					}
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

	public void finalize() throws Throwable {

	}
}