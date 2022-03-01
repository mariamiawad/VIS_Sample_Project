package libs.c5.implementation;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import castle.testenv.base.config.IEvent;
import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import castle.util.Assert;
import config.ETS;
import config.ItfVoltageSense;
import config.ItfVoltageSense.Enmchannel;
import config.Itf_SignalValue;
import libs.c5.interfaces.C5.Util.EventType;
import libs.c5.interfaces.C5.Util.SignalFactor;
import libs.c5.interfaces.C5.VoltageMeasurement.VoltageChnl;
import libs.c5.interfaces.C5.VoltageMeasurement.VoltageUnit;

/**
 * This class is standard library APIs to be used in measuring Voltage.
 *
 * <p>
 * C5 EPIP V2 has 2 voltage channel that can be used to measure voltage. This
 * library provides APIs for measuring instantaneous voltage, filtered voltage,
 * average voltage.
 *
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class VoltageMeasurementLib implements ILib {

	/** Execution Unit corresponding to this library instance */
	ETS exu;

	/** digital input object to be used as for direct FW APIs access */
	ItfVoltageSense volatgeObj;
	
	List<IEvent> volatgeMaxEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> volatgeMaxEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> volatgeMaxEventValueReached = new ArrayList<IEvent>();

	List<IEvent> volatgeAverageEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> volatgeAverageEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> volatgeAverageEventValueReached = new ArrayList<IEvent>();

	List<IEvent> volatgeInstantenousEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> volatgeInstantenousEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> volatgeInstantenousEventValueReached = new ArrayList<IEvent>();
	
	/**
	 * Class Constructors
	 **/
	public VoltageMeasurementLib() {
	}

	public VoltageMeasurementLib(IExu exu) {
		this.exu = (ETS) exu;
		
		this.volatgeObj = this.exu.modTS().objVoltageSense();
				
		int lastChannelIndx = Enmchannel.ch2.ordinal();

		for (int channelIndx = 0; channelIndx <= lastChannelIndx; channelIndx++) {

			volatgeMaxEventValueUpdated.add(volatgeObj.objMaxVoltage(channelIndx).evtUpdate());
			volatgeMaxEventValueChanged.add(volatgeObj.objMaxVoltage(channelIndx).evtValueChange());
			volatgeMaxEventValueReached.add(volatgeObj.objMaxVoltage(channelIndx).evtValueReached());

			volatgeAverageEventValueUpdated.add(volatgeObj.objAverageVoltage(channelIndx).evtUpdate());
			volatgeAverageEventValueChanged.add(volatgeObj.objAverageVoltage(channelIndx).evtValueChange());
			volatgeAverageEventValueReached.add(volatgeObj.objAverageVoltage(channelIndx).evtValueReached());

			volatgeInstantenousEventValueUpdated.add(volatgeObj.objInstantenousVoltage(channelIndx).evtUpdate());
			volatgeInstantenousEventValueChanged.add(volatgeObj.objInstantenousVoltage(channelIndx).evtValueChange());
			volatgeInstantenousEventValueReached.add(volatgeObj.objInstantenousVoltage(channelIndx).evtValueReached());
			
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
	 * @return used execution unit instance for voltage object
	 */
	public ETS exu() {
		return exu;
	}

	/**
	 * Measure a filtered voltage value for one channel. This API manages the
	 * start and the stop of the ADC channel.
	 * <p>
	 * Get filtered voltage value on a channel by averaging all the readings
	 * done during the assigned duration. This API manages the start and the
	 * stop of the ADC channel, the tester doesn't need to worry about starting
	 * or stopping the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The used voltage channel is turned off after calling this API.<br/>
	 * 2-The API returns after the filtering duration.<br/>
	 * 3-The voltage acquisition mode can't be set to automatic before calling.
	 * this API.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            voltage channel to read its value.
	 * @param voltage
	 *            voltage value e.g. 1800 mA
	 * @param voltageUnit
	 *            unit of voltage passed (mA, A, uA)
	 * @param tolerancePercent
	 *            tolerance in measured voltage in percentage e.g. 3%
	 **/
	public void assertFilteredvoltage(VoltageChnl chnl, float voltage,
			VoltageUnit unit, float tolerancePercent) {
		
		Enmchannel voltageChnl = getVoltageChnlEnm(chnl);

		int mVvoltage = getVoltagemV(voltage, unit);
		int tolerancemV = getTolerancemV(mVvoltage, tolerancePercent);

		this.getObj().afcassertVoltageAverage(voltageChnl,mVvoltage, tolerancemV);
	}

	/**
	 * Measure a instantaneous Voltage value for one channel. This API manages
	 * the start and the stop of the ADC channel.
	 * <p>
	 * Get instantaneous Voltage value on a channel by averaging all the
	 * readings done during the assigned duration. This API manages the start
	 * and the stop of the ADC channel, the tester doesn't need to worry about
	 * starting or stopping the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The used voltage channel is turned off after calling this API. <br/>
	 * 2-The voltage acquisition mode can't be set to automatic before calling
	 * this API.<br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            voltage channel to read its value.
	 * @param voltage
	 *            voltage value e.g. 1800 mA
	 * @param voltageUnit
	 *            unit of voltage passed (mA, A, uA)
	 * @param tolerancePercent
	 *            tolerance in measured voltage in percentage e.g. 3%
	 **/
	public void assertVoltageInstantenous(VoltageChnl chnl, float voltage,
			VoltageUnit unit, float tolerancePercent) {

		Enmchannel voltageChnl = getVoltageChnlEnm(chnl);

		int mVvoltage = getVoltagemV(voltage, unit);
		int tolerancemV = getTolerancemV(mVvoltage, tolerancePercent);

		this.getObj().afcassertVoltageInstantenous(voltageChnl, mVvoltage, tolerancemV);

	}

	/**
	 * Measure the maximum voltage value for one channel during desired
	 * duration. This API manages the start and the stop of the ADC channel.
	 * <p>
	 * Get maximum voltage value on a channel during the assigned duration. This
	 * API manages the start and the stop of the ADC channel, the tester doesn't
	 * need to worry about starting or stopping the ADC channel.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-All previous channel measurement data is reset when calling this API. <br/>
	 * 2-The used voltage channel is turned off after calling this API.<br/>
	 * 3-The API returns after the filtering duration.<br/>
	 * 4-The voltage acquisition mode can't be set to automatic before calling.
	 * this API.<br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            voltage channel to read its value.
	 * @param voltage
	 *            voltage value 1800 mA
	 * @param voltageUnit
	 *            unit of voltage passed (mA, A, uA)
	 * @param tolerancePercent
	 *            tolerance in measured voltage in percentage e.g. 3%
	 **/
	public void assertVoltageMax(VoltageChnl chnl, float voltage,
			VoltageUnit unit, float tolerancePercent) {

			Enmchannel voltageChnl = getVoltageChnlEnm(chnl);
			
			int mVvoltage = getVoltagemV(voltage, unit);
			int tolerancemV = getTolerancemV(mVvoltage, tolerancePercent);
			
			this.getObj().afcassertVoltageMax(voltageChnl, mVvoltage, tolerancemV);

	}

	

	/**
	 * Start measuring Voltage on a channel. This API shall be used when the
	 * tester wants to control the ADC channels manually.
	 * <p>
	 * After calling this API, the instantaneous, average, maximum and minimum
	 * voltage values can be acquired at at any time.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-The API must be called prior to measuring any Voltage value at a
	 * channel (unless using the APIs checkInstvoltageAuto or
	 * checkFilteredVoltaget). <br/>
	 * 2-Always stop the Voltage channel when not using it so that other
	 * channels work as fast as possible. <br/>
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            Voltage channel to start updating its value.
	 **/
	public void startVoltageChannelAcquision(VoltageChnl chnl) {
		Enmchannel voltageChnl = getVoltageChnlEnm(chnl);
		this.getObj().afcstartVoltageAcquistion(voltageChnl);
	}

	/**
	 * stop measuring voltage on a channel. This API shall be used when the
	 * tester wants to control the ADC channels manually.
	 * <p>
	 * After calling this API, the instantaneous, average, maximum and minimum
	 * voltage values will not be updated.
	 * <p>
	 * Warnings:
	 * <p>
	 * 1-Always stop the voltage channel when not using it so that other
	 * channels work as fast as possible. 2-When stopping ADC channel, all
	 * previous readings are reset.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            voltage channel to stop updating its value.
	 **/
	public void stopVoltageChannelAcquisition(VoltageChnl chnl) {
		Enmchannel voltageChnl = getVoltageChnlEnm(chnl);
		this.getObj().afcstopVoltageAcquistion(voltageChnl);

	}


	/**
	 * Get access to the instantaneous voltage signal. </br>
	 * <p>
	 * This API is intended for advanced testers. </br> This API doesn't manage
	 * the ADC channel, the tester must manage the start,stop and data reset on
	 * his own.
	 * 
	 * @category Preprocessor
	 * @param chnl
	 *            voltage channel to get its signal.
	 **/
	public Itf_SignalValue getInstVoltageSignal(VoltageChnl chnl) {

		int index = getIndexChnl(chnl);
		return this.getObj().objInstantenousVoltage(index);
	}

	/**
	 * Get access to the average voltage signal. </br>
	 * <p>
	 * This API is intended for advanced testers. </br> This API doesn't manage
	 * the ADC channel, the tester must manage the start,stop and data reset on
	 * his own.
	 * 
	 * @category Preprocessor
	 * @param chnl
	 *            voltage channel to get its signal.
	 **/
	public Itf_SignalValue getAverageVoltageSignal(VoltageChnl chnl) {

		int index = getIndexChnl(chnl);
		return this.getObj().objAverageVoltage(index);
	}

	/**
	 * Reset all stored data for all channel.
	 * 
	 * @category Firmware Action
	 **/
	public void resetMeasuremnents() {
		//this.getObj().afcresetMeaurments();

	}

	/**
	 * Convert from library enum to index.
	 * */
	private int getIndexChnl(VoltageChnl chnl) {

		int index = Arrays.asList(VoltageChnl.values()).indexOf(chnl);

		if (index > 2 || index < 0) {
			Assert.fail("getIndexChnl:Invalid Voltage channel index used !!");
		}

		return index;

	}

	/**
	 * Convert from library enum to firmware enum.
	 * */
	private Enmchannel getVoltageChnlEnm(VoltageChnl chnl) {

		int index = Arrays.asList(VoltageChnl.values()).indexOf(chnl);

		if (index > 2 || index < 0) {
			Assert.fail("getIndexChnl:Invalid ADC channel index used !!");
		}

		return Enmchannel.values()[index];

	}

	private int getVoltagemV(float voltage, VoltageUnit unit) {
		double scale = 1;

		if (unit == VoltageUnit.V) {
			scale = 1000.0;
		} else if (unit == VoltageUnit.mV) {
			scale = 1.0;
		} else if (unit == VoltageUnit.uV) {
			scale = 1 / 1000.0;
		}

		double voltageMilli = voltage * scale;
		int voltageMilliInt = (int) Math.round(voltageMilli);

		return voltageMilliInt;
	}

	private int getTolerancemV(int mVvoltage, float tolerance) {
		
	    int mVTolerance = (int) Math.round((mVvoltage) * (tolerance / 100.0));
	    
	    if(mVvoltage != 0 &&  mVTolerance == 0)
	    {
	    	mVTolerance = (int)tolerance;
	    }
		return mVTolerance; 
	    
	}

	private ItfVoltageSense getObj() {
		return exu.modTS().objVoltageSense();
	}
	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void checkEventBasedSignalsOnMaxVoltage(VoltageChnl port,EventType Type,int Value,int evTime,int evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		Enmchannel channel = getVoltageChnlEnm(port);
		int channelIndx = channel.ordinal();
		IEvent ev = volatgeMaxEventValueUpdated.get(channelIndx);
		
		this.getObj().objMaxVoltage(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value, 0, evTime, evTolerance,SignalFactor.VOLTAGE_Signal_Factor.ordinal());
	}
	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void checkEventBasedSignalsOnAverageVoltage(VoltageChnl port,EventType Type,int Value,int evTime,int evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		Enmchannel channel = getVoltageChnlEnm(port);
		int channelIndx = channel.ordinal();
		IEvent ev = volatgeAverageEventValueReached.get(channelIndx);
		
		this.getObj().objAverageVoltage(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value, 0, evTime, evTolerance,SignalFactor.VOLTAGE_Signal_Factor.ordinal());
	}
	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void checkEventBasedSignalsOnInstantenousVoltage(VoltageChnl port,EventType Type,int Value,int evTime,int evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		Enmchannel channel = getVoltageChnlEnm(port);
		int channelIndx = channel.ordinal();
		IEvent ev = volatgeInstantenousEventValueReached.get(channelIndx);
		
		this.getObj().objInstantenousVoltage(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value, 0, evTime, evTolerance,SignalFactor.VOLTAGE_Signal_Factor.ordinal());
	}
	

}
