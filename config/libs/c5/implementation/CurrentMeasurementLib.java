package libs.c5.implementation;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import castle.testenv.base.config.IEvent;
import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import castle.util.Assert;
import config.ETS;
import config.ItfCurrentSense;
import config.ItfCurrentSense.Enmchannel;
import config.Itf_SignalValue;
import libs.c5.interfaces.C5.CurrentSense.CurrentChnl;
import libs.c5.interfaces.C5.CurrentSense.CurrentUnit;
import libs.c5.interfaces.C5.Util.EventType;
import libs.c5.interfaces.C5.Util.SignalFactor;

/**
 * This class is standard library APIs to be used in measuring current.
 *
 * <p>
 * C5 EPIP V1 has 16 current channel that can be used to measure current. This
 * library provides APIs for measuring instantaneous current, filtered current,
 * average current and PWM current signals.
 *
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class CurrentMeasurementLib implements ILib {

	/** Execution Unit corresponding to this library instance */
	ETS exu;

	/** digital input object to be used as for direct FW APIs access */
	ItfCurrentSense CurrentObj;

	List<IEvent> currentMaxEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> currentMaxEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> currentMaxEventValueReached = new ArrayList<IEvent>();

	List<IEvent> currentAverageEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> currentAverageEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> currentAverageEventValueReached = new ArrayList<IEvent>();

	List<IEvent> currentInstantenousEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> currentInstantenousEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> currentInstantenousEventValueReached = new ArrayList<IEvent>();

	List<IEvent> currentDutyCycleEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> currentDutyCycleEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> currentDutyCycleEventValueReached = new ArrayList<IEvent>();

	/**
	 * Class Constructors
	 **/
	public CurrentMeasurementLib() {
	
	}

	public CurrentMeasurementLib(IExu exu) {
		this.exu = (ETS) exu;
		this.CurrentObj = this.exu.modTS().objCurrentSense();	
		int lastChannelIndx = Enmchannel.ch6.ordinal();

		for (int channelIndx = 0; channelIndx <= lastChannelIndx; channelIndx++) {

			currentMaxEventValueUpdated.add(CurrentObj.objMaxCurrent(channelIndx).evtUpdate());
			currentMaxEventValueChanged.add(CurrentObj.objMaxCurrent(channelIndx).evtValueChange());
			currentMaxEventValueReached.add(CurrentObj.objMaxCurrent(channelIndx).evtValueReached());

			currentAverageEventValueUpdated.add(CurrentObj.objAverageCurrent(channelIndx).evtUpdate());
			currentAverageEventValueChanged.add(CurrentObj.objAverageCurrent(channelIndx).evtValueChange());
			currentAverageEventValueReached.add(CurrentObj.objAverageCurrent(channelIndx).evtValueReached());

			currentInstantenousEventValueUpdated.add(CurrentObj.objInstantenousCurrent(channelIndx).evtUpdate());
			currentInstantenousEventValueChanged.add(CurrentObj.objInstantenousCurrent(channelIndx).evtValueChange());
			currentInstantenousEventValueReached.add(CurrentObj.objInstantenousCurrent(channelIndx).evtValueReached());

			currentDutyCycleEventValueUpdated.add(CurrentObj.objDutyCycle(channelIndx).evtUpdate());
			currentDutyCycleEventValueChanged.add(CurrentObj.objDutyCycle(channelIndx).evtValueChange());
			currentDutyCycleEventValueReached.add(CurrentObj.objDutyCycle(channelIndx).evtValueReached());
			
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

	/**
	 * Measure a filtered current value for one channel. This API manages the
	 * start and the stop of the ADC channel.
	 * <p>
	 * Get filtered current value on a channel by averaging all the readings
	 * done during the assigned duration. This API manages the start and the
	 * stop of the ADC channel, the tester doesn't need to worry about starting
	 * or stopping the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The used current channel is turned off after calling this API.<br/>
	 * 2-The API returns after the filtering duration.<br/>
	 * 3-The current acquisition mode can't be set to automatic before calling.
	 * this API.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param current
	 *            current value e.g. 1800 mA
	 * @param currentUnit
	 *            unit of current passed (mA, A, uA)
	 * @param tolerancePercent
	 *            tolerance in measured current in percentage e.g. 3%
	 **/
	public void assertFilteredCurrent(CurrentChnl chnl, float current,
			CurrentUnit unit, float tolerancePercent) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int mACurrent = getCurrentmA(current, unit);
		int tolerancemA = getTolerancemA(mACurrent, tolerancePercent);

		this.getObj().afcassertCurrentAverage(currentChnl, mACurrent,
				tolerancemA);
	}

	/**
	 * Measure the frequency current value for one channel. This API manages
	 * the start and the stop of the ADC channel.
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param frequency
	 *            Frequency values in Hz
	 * @param tolerancePercent
	 *            tolerance in measured current in percentage e.g. 3%
	 **/
	public void assertFrequencyCurrent(CurrentChnl chnl, float frequency, float tolerancePercent) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		float frequencyTolerance = getToleranceHz(frequency, tolerancePercent);

		this.getObj().afcassertCurrentFrequency(currentChnl, frequency, frequencyTolerance);

	}

	/**
	 * Measure a instantaneous current value for one channel. This API manages
	 * the start and the stop of the ADC channel.
	 * <p>
	 * Get instantaneous current value on a channel by averaging all the
	 * readings done during the assigned duration. This API manages the start
	 * and the stop of the ADC channel, the tester doesn't need to worry about
	 * starting or stopping the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The used current channel is turned off after calling this API. <br/>
	 * 2-The current acquisition mode can't be set to automatic before calling
	 * this API.<br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param current
	 *            current value e.g. 1800 mA
	 * @param currentUnit
	 *            unit of current passed (mA, A, uA)
	 * @param tolerancePercent
	 *            tolerance in measured current in percentage e.g. 3%
	 **/
	public void assertInstantaneousCurrent(CurrentChnl chnl, float current,
			CurrentUnit unit, float tolerancePercent) {

		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int mACurrent = getCurrentmA(current, unit);
		int tolerancemA = getTolerancemA(mACurrent, tolerancePercent);

		this.getObj().afcassertCurrentInstantenous(currentChnl, mACurrent, tolerancemA);

	}

	/**
	 * Measure the maximum current value for one channel during desired
	 * duration. This API manages the start and the stop of the ADC channel.
	 * <p>
	 * Get maximum current value on a channel during the assigned duration. This
	 * API manages the start and the stop of the ADC channel, the tester doesn't
	 * need to worry about starting or stopping the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-All previous channel measurement data is reset when calling this API. <br/>
	 * 2-The used current channel is turned off after calling this API.<br/>
	 * 3-The API returns after the filtering duration.<br/>
	 * 4-The current acquisition mode can't be set to automatic before calling.
	 * this API.<br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param current
	 *            current value 1800 mA
	 * @param currentUnit
	 *            unit of current passed (mA, A, uA)
	 * @param tolerancePercent
	 *            tolerance in measured current in percentage e.g. 3%
	 **/
	public void assertMaximumCurrent(CurrentChnl chnl, float current,
			CurrentUnit unit, float tolerancePercent) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int mACurrent = getCurrentmA(current, unit);
		int tolerancemA = getTolerancemA(mACurrent, tolerancePercent);

		this.getObj().afcassertCurrentMax(currentChnl, mACurrent,
				tolerancemA);
	}


	/**
	 * Assert instantaneously on the value of the duty cycle of the applied
	 * current signal.</br>	
	 * The Dutycycle passed shall be multiplied by 1000 e.g. if you want
	 * to assert on duyt cycle of 32.51% then you shall pass 32510.</br>						     
	 * This API will not wait till the next sampling window and it will get the
	 * reading directly from the FPGA module.</br>
	 * Warning: The channel must be activated using the API startCurrentacquistion 
	 * before invoking this API.</br>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param currentDutyCycle
	 *            Current Duty Cylce Value ex.[32.3%]
	 * @param tolerancePercent
	 *            Tolernace in Percentage ex.[5%]
	 **/

	public void assertCurrentDutyCycle(CurrentChnl chnl, float currentDutyCycle,
			float tolerancePercent) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int requestedDuty = (int) (currentDutyCycle * 100);

		int toleranceDuty = (int) Math.round((currentDutyCycle) * (tolerancePercent / 100.0));

		this.getObj().afcassertCurrentDutyCycle(currentChnl, requestedDuty, toleranceDuty);
	}

	/**
	 * Start measuring current on a channel. This API shall be used when the tester
	 * wants to control the ADC channels manually.
	 * <p>
	 * After calling this API, the instantaneous, average, maximum and minimum
	 * current values can be acquired at at any time.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The API must be called prior to measuring any current value at a channel
	 * (unless using the APIs checkInstCUrrentAuto or checkFilteredCurrentAuto).
	 * <br/>
	 * 2-Always stop the current channel when not using it so that other channels
	 * work as fast as possible. <br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to start updating its value.
	 **/
	public void startCurrentChannelAcquision(CurrentChnl chnl) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);
		this.getObj().afcstartCurrentacquisition(currentChnl);
	}

	/**
	 * stop measuring current on a channel. This API shall be used when the tester
	 * wants to control the ADC channels manually.
	 * <p>
	 * After calling this API, the instantaneous, average, maximum and minimum
	 * current values will not be updated.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-Always stop the current channel when not using it so that other channels
	 * work as fast as possible. 2-When stopping ADC channel, all previous readings
	 * are reset.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to stop updating its value.
	 **/
	public void stopCurrentChannelAcquisition(CurrentChnl chnl) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);
		this.getObj().afcstopCurrentacquisition(currentChnl);

	}

	/**
	 * Get access to the instantaneous current signal. </br>
	 * <p>
	 * This API is intended for advanced testers. </br>
	 * This API doesn't manage the ADC channel, the tester must manage the
	 * start,stop and data reset on his own.
	 * 
	 * @category Preprocessor
	 * @param chnl
	 *            Current channel to get its signal.
	 **/
	public Itf_SignalValue getInstCurrentSignal(CurrentChnl chnl) {

		int index = getIndexChnl(chnl);
		return this.getObj().objInstantenousCurrent(index);
	}

	/**
	 * Get access to the average current signal. </br>
	 * <p>
	 * This API is intended for advanced testers. </br>
	 * This API doesn't manage the ADC channel, the tester must manage the
	 * start,stop and data reset on his own.
	 * 
	 * @category Preprocessor
	 * @param chnl
	 *            Current channel to get its signal.
	 **/
	public Itf_SignalValue getAverageCurrentSignal(CurrentChnl chnl) {

		int index = getIndexChnl(chnl);
		return this.getObj().objAverageCurrent(index);
	}

	/**
	 * Reset all stored data for all channel.
	 * 
	 * @category Firmware Action
	 **/
	public void resetMeasuremnents() {
		this.getObj().afcresetMeaurments();

	}

	/**
	 * Convert from library enum to index.
	 */
	private int getIndexChnl(CurrentChnl chnl) {

		int index = Arrays.asList(CurrentChnl.values()).indexOf(chnl);

		if (index > 6 || index < 0) {
			Assert.fail("getIndexChnl:Invalid Current channel index used !!");
		}

		return index;

	}

	/**
	 * Convert from library enum to firmware enum.
	 */
	private Enmchannel getCurrentChnlEnm(CurrentChnl chnl) {

		int index = Arrays.asList(CurrentChnl.values()).indexOf(chnl);

		if (index > 6 || index < 0) {
			Assert.fail("getIndexChnl:Invalid ADC channel index used !!");
		}

		return Enmchannel.values()[index];

	}

	private int getCurrentmA(float current, CurrentUnit unit) {
		double scale = 1;

		if (unit == CurrentUnit.mA) {
			scale = 1.0;
		} else if (unit == CurrentUnit.A) {
			scale = 1000.0;
		} else if (unit == CurrentUnit.uA) {
			scale = 1 / 1000.0;
		}

		double currentMilli = current * scale;
		int currentMilliInt = (int) Math.round(currentMilli);

		return currentMilliInt;
	}

	private int getTolerancemA(int mACurrent, float tolerance) {

		int mATolerance = (int) Math.round((mACurrent) * (tolerance / 100.0));

		if (mACurrent != 0 && mATolerance == 0) {
			mATolerance = (int) tolerance;
		}

		return mATolerance;
	}

	private float getToleranceHz(float frequency, float tolerance) {

		float fTolerance = (int) Math.round((frequency) * (tolerance / 100.0));

		if (frequency != 0 && fTolerance == 0) {
			fTolerance = (int) tolerance;
		}

		return fTolerance;
	}

	private ItfCurrentSense getObj() {
		return exu.modTS().objCurrentSense();
	}

	//
	/**
	 * Measure a filtered current value for one channel. This API manages the start
	 * and the stop of the ADC channel.
	 * <p>
	 * Get filtered current value on a channel by averaging all the readings done
	 * during the assigned duration. This API manages the start and the stop of the
	 * ADC channel, the tester doesn't need to worry about starting or stopping the
	 * ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The used current channel is turned off after calling this API.<br/>
	 * 2-The API returns after the filtering duration.<br/>
	 * 3-The current acquisition mode can't be set to automatic before calling. this
	 * API.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param current
	 *            current value e.g. 1800 mA
	 * @param currentUnit
	 *            unit of current passed (mA, A, uA)
	 * @param toleranceAbsolute
	 *            tolerance in measured current in mA
	 **/
	public void assertFilteredCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit, float toleranceAbsolute) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int mACurrent = getCurrentmA(current, unit);
		int tolerancemA = (int) toleranceAbsolute;

		this.getObj().afcassertCurrentAverage(currentChnl, mACurrent, tolerancemA);
	}

	/**
	 * Measure the frequency current value for one channel. This API manages the
	 * start and the stop of the ADC channel.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param frequency
	 *            Frequency values in Hz
	 * @param toleranceAbsolute
	 *            tolerance in measured current in Hz
	 **/
	public void assertFrequencyCurrentAbs(CurrentChnl chnl, float frequency, float toleranceAbsolute) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		float frequencyTolerance = toleranceAbsolute;

		this.getObj().afcassertCurrentFrequency(currentChnl, frequency, frequencyTolerance);

	}

	/**
	 * Measure a instantaneous current value for one channel. This API manages the
	 * start and the stop of the ADC channel.
	 * <p>
	 * Get instantaneous current value on a channel by averaging all the readings
	 * done during the assigned duration. This API manages the start and the stop of
	 * the ADC channel, the tester doesn't need to worry about starting or stopping
	 * the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The used current channel is turned off after calling this API. <br/>
	 * 2-The current acquisition mode can't be set to automatic before calling this
	 * API.<br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param current
	 *            current value e.g. 1800 mA
	 * @param currentUnit
	 *            unit of current passed (mA, A, uA)
	 * @param toleranceAbsolute
	 *            tolerance in measured current in mA
	 **/
	public void assertInstantaneousCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit,
			float toleranceAbsolute) {

		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int mACurrent = getCurrentmA(current, unit);
		int tolerancemA = (int) toleranceAbsolute;

		this.getObj().afcassertCurrentInstantenous(currentChnl, mACurrent, tolerancemA);

	}

	/**
	 * Measure the maximum current value for one channel during desired duration.
	 * This API manages the start and the stop of the ADC channel.
	 * <p>
	 * Get maximum current value on a channel during the assigned duration. This API
	 * manages the start and the stop of the ADC channel, the tester doesn't need to
	 * worry about starting or stopping the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-All previous channel measurement data is reset when calling this API. <br/>
	 * 2-The used current channel is turned off after calling this API.<br/>
	 * 3-The API returns after the filtering duration.<br/>
	 * 4-The current acquisition mode can't be set to automatic before calling. this
	 * API.<br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param current
	 *            current value 1800 mA
	 * @param currentUnit
	 *            unit of current passed (mA, A, uA)
	 * @param toleranceAbsolute
	 *            tolerance in measured current in mA
	 **/
	public void assertMaximumCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit, float toleranceAbsolute) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int mACurrent = getCurrentmA(current, unit);
		int tolerancemA = (int) toleranceAbsolute;

		this.getObj().afcassertCurrentMax(currentChnl, mACurrent, tolerancemA);
	}

	/**
	 * Assert instantaneously on the value of the duty cycle of the applied current
	 * signal.</br>
	 * The Dutycycle passed shall be multiplied by 1000 e.g. if you want to assert
	 * on duyt cycle of 32.51% then you shall pass 32510.</br>
	 * This API will not wait till the next sampling window and it will get the
	 * reading directly from the FPGA module.</br>
	 * Warning: The channel must be activated using the API startCurrentacquistion
	 * before invoking this API.</br>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Current channel to read its value.
	 * @param currentDutyCycle
	 *            Current Duty Cylce Value ex.[32.3%]
	 * @param toleranceAbsolute
	 *            Tolernace in Percentage ex.[5%] if CurrentDuty = 50 and Tolerance
	 *            = 5 Check window will be from 45 to 55 %
	 **/

	public void assertCurrentDutyCycleAbs(CurrentChnl chnl, float currentDutyCycle, float toleranceAbsolute) {
		Enmchannel currentChnl = getCurrentChnlEnm(chnl);

		int requestedDuty = (int) (currentDutyCycle * 100);

		int toleranceDuty = (int) (toleranceAbsolute);

		this.getObj().afcassertCurrentDutyCycle(currentChnl, requestedDuty, toleranceDuty);
	}

	/**
	 * register event on value reached, The event will be triggered if the timeout
	 * reached or the value reached.
	 */
	public void checkEventBasedSignalsOnMaxCurrent(CurrentChnl port, EventType Type, int Value, int evTime,
			int evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		Enmchannel channel = getCurrentChnlEnm(port);
		int channelIndx = channel.ordinal();
		IEvent ev = currentMaxEventValueReached.get(channelIndx);

		this.getObj().objMaxCurrent(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value,
				0, evTime, evTolerance, SignalFactor.CURRENT_Signal_Factor.ordinal());
	}

	/**
	 * register event on value reached, The event will be triggered if the timeout
	 * reached or the value reached.
	 */
	public void checkEventBasedSignalsOnAverageCurrent(CurrentChnl port, EventType Type, int Value, int evTime,
			int evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		Enmchannel channel = getCurrentChnlEnm(port);
		int channelIndx = channel.ordinal();
		IEvent ev = currentAverageEventValueReached.get(channelIndx);

		this.getObj().objAverageCurrent(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger,
				Value, 0, evTime, evTolerance, SignalFactor.CURRENT_Signal_Factor.ordinal());
	}

	/**
	 * register event on value reached, The event will be triggered if the timeout
	 * reached or the value reached.
	 */
	public void checkEventBasedSignalsOnInstantenousCurrent(CurrentChnl port, EventType Type, int Value, int evTime,
			int evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		Enmchannel channel = getCurrentChnlEnm(port);
		int channelIndx = channel.ordinal();
		IEvent ev = currentInstantenousEventValueReached.get(channelIndx);

		this.getObj().objInstantenousCurrent(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(),
				eventTypeInteger, Value, 0, evTime, evTolerance, SignalFactor.CURRENT_Signal_Factor.ordinal());
	}

	/**
	 * register event on value reached, The event will be triggered if the timeout
	 * reached or the value reached.
	 */
	public void checkEventBasedSignalsOnDutyCycleCurrent(CurrentChnl port, EventType Type, int Value, int evTime,
			int evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		Enmchannel channel = getCurrentChnlEnm(port);
		int channelIndx = channel.ordinal();
		IEvent ev = currentDutyCycleEventValueReached.get(channelIndx);

		this.getObj().objDutyCycle(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value,
				0, evTime, evTolerance, SignalFactor.CURRENT_Signal_Factor.ordinal());
	}
}
