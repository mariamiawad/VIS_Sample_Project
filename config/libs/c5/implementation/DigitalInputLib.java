package libs.c5.implementation;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import castle.testenv.base.config.IEvent;
import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import config.ETS;
import config.ItfDI;
import config.ItfDI.EnmDigitalInputChannelID;
import libs.c5.interfaces.C5.DigitalInput;
import libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels;
import libs.c5.interfaces.C5.Util.EventType;
import libs.c5.interfaces.C5.Util.SignalFactor;

/**
 * This class is implementation of standard library APIs to be used in
 * controlling digital input pins.
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class DigitalInputLib implements ILib {

	ETS exu;
	/** digital input object to be used as for direct FW APIs access */
	ItfDI DIObj;

	List<IEvent> digitalInputEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> digitalInputEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> digitalInputEventValueReached = new ArrayList<IEvent>();

	/**
	 * Class Constructors
	 **/
	public DigitalInputLib() {
		this.exu = (ETS) exu;
		this.DIObj = this.exu.modTS().objDInput();		
		int lastChannelIndx = EnmDigitalInputChannelID.DInput_Ch_24.ordinal();
		
		for (int channelIndx = 0; channelIndx <= lastChannelIndx; channelIndx++) {
			digitalInputEventValueUpdated.add(DIObj.objDigitalInput(channelIndx)
					.evtUpdate());
			digitalInputEventValueChanged.add(DIObj.objDigitalInput(channelIndx)
					.evtValueChange());
			digitalInputEventValueReached.add(DIObj.objDigitalInput(channelIndx)
					.evtValueReached());
		}
	}

	public DigitalInputLib(IExu exu) {
		this.exu = (ETS) exu;
		this.DIObj = this.exu.modTS().objDInput();
		int lastChannelIndx = EnmDigitalInputChannelID.DInput_Ch_24.ordinal();
		
		for (int channelIndx = 0; channelIndx <= lastChannelIndx; channelIndx++) {
			digitalInputEventValueUpdated.add(DIObj.objDigitalInput(channelIndx)
					.evtUpdate());
			digitalInputEventValueChanged.add(DIObj.objDigitalInput(channelIndx)
					.evtValueChange());
			digitalInputEventValueReached.add(DIObj.objDigitalInput(channelIndx)
					.evtValueReached());
		}
	}

	/**
	 * Set the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @param exu
	 *            instance of execution unit
	 */
	public void setExu(IExu exu) {
		this.exu = (ETS) exu;
	}

	/**
	 * Get the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @return used execution unit instance for current object
	 */
	public ETS exu() {
		return exu;
	}

	private ItfDI getObj() {
		return this.DIObj;
	}

	/**
	 * Set one digital output port to the desired value.
	 * 
	 * 
	 * @param port
	 *            ID of port to set its output.
	 * @param digValue
	 *            Digital output value.
	 * @category Firmware Action
	 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels
	 *      Ports Enum}
	 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue
	 *      Digital output values Enum}
	 */
	public void assertDigitalInputPin(DigitalInputChannels port,
			DigitalInput.DigitalInputValue digValue) {

		EnmDigitalInputChannelID channel = getDigitalInputChannel(port);
		Boolean state = false;

		if (digValue == DigitalInput.DigitalInputValue.High) {
			state = true;
		}

		this.getObj().afcAssertDigitalInputValue(state, channel);
	}

	/**
	 * Starts the digital inputs capture task. It is a periodic task with
	 * periodicity 1msec. After the task start the digital input signals values
	 * are updated periodically.
	 * 
	 */
	public void startDigitalInputAcquisition(DigitalInputChannels port) {
		EnmDigitalInputChannelID channel = getDigitalInputChannel(port);
		this.getObj().afcstartDigitalInputTask(channel);
	}

	/**
	 * Stop the digital inputs capture task. It is a periodic task with
	 * periodicity 1msec. After the task start the digital input signals values
	 * are updated periodically.
	 * 
	 */
	public void stopDigitalInputAcquisition(DigitalInputChannels port) {
		EnmDigitalInputChannelID channel = getDigitalInputChannel(port);
		this.getObj().afcstopDigitalInputTask(channel);
	}

	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void registerValueReachedEvent(DigitalInputChannels port,int Value,int evTime,int evTolerance) {
		EnmDigitalInputChannelID channel = getDigitalInputChannel(port);
		int channelIndx = channel.ordinal();
		IEvent ev = digitalInputEventValueReached.get(channelIndx);
    	this.getObj().objDigitalInput(channelIndx).afcSetTriggerValue(Value, 0);
    	this.getObj().objDigitalInput(channelIndx).afcCheckForEvent(ev.getModEventId(), evTime,evTolerance);
	}


	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void checkEventBasedSignals(DigitalInputChannels port,EventType Type,double Value,double evTime,double evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		EnmDigitalInputChannelID channel = getDigitalInputChannel(port);
		int channelIndx = channel.ordinal();
		IEvent ev = digitalInputEventValueReached.get(channelIndx);
		
		this.getObj().objDigitalInput(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value, 0, evTime, evTolerance,SignalFactor.DIGITAL_IN_Signal_Factor.ordinal());
	}

	
	/**
	 * Read now, without waiting for the task time, the DI registers and update
	 * the signals. task start the digital input signals values are updated
	 * periodically.
	 * 
	 */
	public void readDigitalInputValue() {
		this.getObj().afcReadNow();
	}

	/**
	 * Get Digital Input channel.
	 * 
	 * @param digitalInputChannel
	 *            Selected Input Digital Channel
	 * 
	 * @category Preprocessor
	 */
	private EnmDigitalInputChannelID getDigitalInputChannel(
			DigitalInputChannels digitalInputChannel) {

		int index = Arrays.asList(DigitalInputChannels.values()).indexOf(
				digitalInputChannel);

		return EnmDigitalInputChannelID.values()[index];
	}

}
