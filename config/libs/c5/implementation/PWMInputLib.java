package libs.c5.implementation;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import castle.testenv.base.config.IEvent;
import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import config.ETS;
import config.ItfPwmIn;
import config.ItfPwmIn.EnmPwm_Chnl;
import libs.c5.implementation.UtilitiesLib.Rational;
import libs.c5.interfaces.C5.PwmInput.PwmInChnl;
import libs.c5.interfaces.C5.PwmInput.PwmInFrequencyUnit;
import libs.c5.interfaces.C5.Util.EventType;
import libs.c5.interfaces.C5.Util.SignalFactor;

/**
 * This class is standard library APIs to be used in controlling PWM input
 * Channels.
 *
 * <p>
 * PIP V1 board has 60 digital input channels, any of them can either be used as
 * PWM or Digital input. But 16 channels can only be active at once.
 * <p>
 * To simplify the design of the library, the first 16 digital PWM input channel
 * are dedicated to PWM.
 *
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class PWMInputLib implements ILib {

	/** Execution Unit corresponding to this library instance */
	ETS exu;
	ItfPwmIn PWMobj;

	List<IEvent> PWMDutyEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> PWMDutyEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> PWMDutyEventValueReached = new ArrayList<IEvent>();
	
	List<IEvent> PWMFreqEventValueUpdated = new ArrayList<IEvent>();
	List<IEvent> PWMFreqEventValueChanged = new ArrayList<IEvent>();
	List<IEvent> PWMFreqEventValueReached = new ArrayList<IEvent>();
	
	/**
	 * Class Constructors
	 **/
	public PWMInputLib() {
		this.exu = (ETS) exu;
		this.PWMobj = this.exu.modTS().objPWMInput();	
		int lastChannelIndx = EnmPwm_Chnl.Ch_16.ordinal();
		
		for (int channelIndx = 0; channelIndx <= lastChannelIndx; channelIndx++) {
			PWMDutyEventValueUpdated.add(PWMobj.objDutyCycle(channelIndx).evtUpdate());
			PWMDutyEventValueChanged.add(PWMobj.objDutyCycle(channelIndx).evtValueChange());
			PWMDutyEventValueReached.add(PWMobj.objDutyCycle(channelIndx).evtValueReached());
			
			PWMFreqEventValueUpdated.add(PWMobj.objFrequency(channelIndx).evtUpdate());
			PWMFreqEventValueChanged.add(PWMobj.objFrequency(channelIndx).evtValueChange());
			PWMFreqEventValueReached.add(PWMobj.objFrequency(channelIndx).evtValueReached());
		}
	}

	public PWMInputLib(IExu exu) {
		this.exu = (ETS) exu;
		this.PWMobj = this.exu.modTS().objPWMInput();	
		int lastChannelIndx = EnmPwm_Chnl.Ch_16.ordinal();
		
		for (int channelIndx = 0; channelIndx <= lastChannelIndx; channelIndx++) {
			PWMDutyEventValueUpdated.add(PWMobj.objDutyCycle(channelIndx).evtUpdate());
			PWMDutyEventValueChanged.add(PWMobj.objDutyCycle(channelIndx).evtValueChange());
			PWMDutyEventValueReached.add(PWMobj.objDutyCycle(channelIndx).evtValueReached());
			
			PWMFreqEventValueUpdated.add(PWMobj.objFrequency(channelIndx).evtUpdate());
			PWMFreqEventValueChanged.add(PWMobj.objFrequency(channelIndx).evtValueChange());
			PWMFreqEventValueReached.add(PWMobj.objFrequency(channelIndx).evtValueReached());
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

	private ItfPwmIn getObj() {
		return this.PWMobj;
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
	 * Check the PWM frequency in KHz of a PWM channel.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @param frequency
	 *            Frequency in KHz e.g. 1.75 KHz
	 * @param freqTolerancePercent
	 *            Accepted tolerance in frequency e.g. 5%. E.g. if the expected
	 *            frequency is 1K and tolerance is 5% then any measured value
	 *            between 1050 and 950 Hz will be ok for the test.
	 * @param dutyCyclePercent
	 *            Dutycycle percentage e.g. 56.7
	 * @param duytTolerancePercent
	 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the expected
	 *            duty cycle is 65% and tolerance is 3% then any duty cycle
	 *            between 63.05% to 66.95% will be ok.
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void assertPwmFrequencyAndDutyCycle(PwmInChnl chnl, double frequency,
			double freqTolerancePercent, double dutyCyclePercent,double duytTolerancePercent,
			PwmInFrequencyUnit unit) 
	{

		EnmPwm_Chnl diChnl = getPwmInChnl(chnl);
		
		double frequencyKHz = getFrequencyValue(frequency,unit);

		Rational dutyRational = new Rational(dutyCyclePercent);
		Rational freqRational = new Rational(frequencyKHz);

		int toleranceHz = (int) Math.round(1000 * (1000 * frequencyKHz)
				* (freqTolerancePercent / 100.0));

		int toleranceDuty = (int) Math.round(1000 * (dutyCyclePercent)
				* (duytTolerancePercent / 100.0));

		exu.modTS()
				.objPWMInput()
				.afcAssertPwm(freqRational.getNum(),
						freqRational.getDenom(), toleranceHz,
						dutyRational.getNum(), dutyRational.getDenom(),
						toleranceDuty, diChnl);
	}

	/**
	 * Check the PWM frequency in KHz of a PWM channel.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @param frequency
	 *            Frequency in KHz e.g. 1.75 KHz
	 * @param freqTolerancePercent
	 *            Accepted tolerance in frequency e.g. 5%. E.g. if the expected
	 *            frequency is 1K and tolerance is 5% then any measured value
	 *            between 1050 and 950 Hz will be ok for the test.
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void assertPwmFrequency(PwmInChnl chnl, double frequency,
			double freqTolerancePercent,
			PwmInFrequencyUnit unit) 
	{

		EnmPwm_Chnl diChnl = getPwmInChnl(chnl);
		
		double frequencyKHz = getFrequencyValue(frequency,unit);

		Rational freqRational = new Rational(frequencyKHz);

		int toleranceHz = (int) Math.round(1000 * (1000 * frequencyKHz)
				* (freqTolerancePercent / 100.0));


		exu.modTS()
				.objPWMInput()
				.afcAssertPwmFrequency(freqRational.getNum(),
						freqRational.getDenom(), toleranceHz,
						 diChnl);
	}
	
	/**
	 * Check the PWM Duty Cycle of a PWM channel.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @param dutyCyclePercent
	 *            Dutycycle percentage e.g. 56.7
	 * @param duytTolerancePercent
	 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the expected
	 *            duty cycle is 65% and tolerance is 3% then any duty cycle
	 *            between 63.05% to 66.95% will be ok.
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void assertPwmDutyCycle(PwmInChnl chnl,double dutyCyclePercent,double duytTolerancePercent) 
	{

		EnmPwm_Chnl diChnl = getPwmInChnl(chnl);
		

		Rational dutyRational = new Rational(dutyCyclePercent);


		int toleranceDuty = (int) Math.round(1000 * (dutyCyclePercent) * (duytTolerancePercent / 100.0));

		exu.modTS()
				.objPWMInput()
				.afcAssertPwmDuty(dutyRational.getNum(), dutyRational.getDenom(),
						toleranceDuty, diChnl);
	}

	/**
	 * Start continuous check the PWM frequency on the desired PWM channel
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void startPWMContinousAcquisition(PwmInChnl chnl) {

		EnmPwm_Chnl pwmIndx = getPwmInChnl(chnl);
		
		exu.modTS().objPWMInput().afcStartPwm(pwmIndx);
	}

	/**
	 * Stop continuous check the PWM frequency on the desired PWM channel
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void stopPWMContinousAcquisition(PwmInChnl chnl) {

		EnmPwm_Chnl pwmIndx = getPwmInChnl(chnl);
		
		exu.modTS().objPWMInput().afcStopPwm(pwmIndx);
	}
	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void registerValueReachedEventOnFrequency(PwmInChnl port,int Value,int evTime,int evTolerance) {
		EnmPwm_Chnl channel = getPwmInChnl(port);
		int channelIndx = channel.ordinal();
		IEvent ev = PWMFreqEventValueChanged.get(channelIndx);
    	this.getObj().objFrequency(channelIndx).afcSetTriggerValue(Value, 0);
    	this.getObj().objFrequency(channelIndx).afcCheckForEvent(ev.getModEventId(), evTime,evTolerance);
	}


	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void checkEventBasedSignalsOnFrequency(PwmInChnl port,EventType Type,double Value,double ValueTol,double evTime,double evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		EnmPwm_Chnl channel = getPwmInChnl(port);
		int channelIndx = channel.ordinal();
		IEvent ev = PWMFreqEventValueReached.get(channelIndx);

		this.getObj().objFrequency(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value, ValueTol, evTime, evTolerance,SignalFactor.PWM_IN_Freq_Signal_Factor.ordinal());
	}
	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void registerValueReachedEventOnDuty(PwmInChnl port,int Value,int evTime,int evTolerance) {
		EnmPwm_Chnl channel = getPwmInChnl(port);
		int channelIndx = channel.ordinal();
		IEvent ev = PWMDutyEventValueChanged.get(channelIndx);
    	this.getObj().objDutyCycle(channelIndx).afcSetTriggerValue(Value, 0);
    	this.getObj().objDutyCycle(channelIndx).afcCheckForEvent(ev.getModEventId(), evTime,evTolerance);
	}


	
	/**
	 * register event on value reached, The event will be triggered if 
	 * the timeout reached or the value reached. 
	 */
	public void checkEventBasedSignalsOnDuty(PwmInChnl port,EventType Type,double Value,double ValueTol,double evTime,double evTolerance) {
		int eventTypeInteger = Arrays.asList(EventType.values()).indexOf(Type);
		EnmPwm_Chnl channel = getPwmInChnl(port);
		int channelIndx = channel.ordinal();
		IEvent ev = PWMDutyEventValueChanged.get(channelIndx);
		
		this.getObj().objDutyCycle(channelIndx).afcCheckEventBasedSignals(ev.getModEventId(), eventTypeInteger, Value, ValueTol, evTime, evTolerance,SignalFactor.PWM_IN_Duty_Signal_Factor.ordinal());
	}
	
	/**
	 * Stop continuous check the PWM frequency on the desired PWM channel
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void resetPwmMeasurementRegisters(PwmInChnl chnl) {

		EnmPwm_Chnl pwmIndx = getPwmInChnl(chnl);
		
		exu.modTS().objPWMInput().afcResetPwm(pwmIndx);
	}



	private EnmPwm_Chnl getPwmInChnl(PwmInChnl chnl) {

		int index = Arrays.asList(PwmInChnl.values()).indexOf(chnl);

		return EnmPwm_Chnl.values()[index];

	}
	
	private double getFrequencyValue(double Frequency, PwmInFrequencyUnit unit) {
		double scale = 1;

		if (unit == PwmInFrequencyUnit.Hz) {
			scale = 1 / 1000.0;
		} else if (unit == PwmInFrequencyUnit.KHz) {
			scale = 1.0;
		} else if (unit == PwmInFrequencyUnit.MHz) {
			scale = 1000;
		}

		double frequencyKiloHz = Frequency * scale;

		return frequencyKiloHz;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * Check the PWM frequency in KHz of a PWM channel.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @param frequency
	 *            Frequency in KHz e.g. 1.75 KHz
	 * @param freqTolerancePercent
	 *            Accepted tolerance in frequency e.g. 5%. E.g. if the expected
	 *            frequency is 1K and tolerance is 5% then any measured value
	 *            between 1050 and 950 Hz will be ok for the test.
	 * @param dutyCyclePercent
	 *            Dutycycle percentage e.g. 56.7
	 * @param duytTolerancePercent
	 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the expected
	 *            duty cycle is 65% and tolerance is 3% then any duty cycle
	 *            between 63.05% to 66.95% will be ok.
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void assertPwmFrequencyAndDutyCycleAbs(PwmInChnl chnl, double frequency,
			double freqTolerancePercent, double dutyCyclePercent,double duytTolerancePercent,
			PwmInFrequencyUnit unit) 
	{

		EnmPwm_Chnl diChnl = getPwmInChnl(chnl);
		
		double frequencyKHz = getFrequencyValue(frequency,unit);

		Rational dutyRational = new Rational(dutyCyclePercent);
		Rational freqRational = new Rational(frequencyKHz);

		int toleranceHz = (int) (freqTolerancePercent);

		int toleranceDuty = (int) (duytTolerancePercent);

		exu.modTS()
				.objPWMInput()
				.afcAssertPwm(freqRational.getNum(),
						freqRational.getDenom(), toleranceHz,
						dutyRational.getNum(), dutyRational.getDenom(),
						toleranceDuty, diChnl);
	}

	/**
	 * Check the PWM frequency in KHz of a PWM channel.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @param frequency
	 *            Frequency in KHz e.g. 1.75 KHz
	 * @param freqTolerancePercent
	 *            Accepted tolerance in frequency e.g. 5%. E.g. if the expected
	 *            frequency is 1K and tolerance is 5% then any measured value
	 *            between 1050 and 950 Hz will be ok for the test.
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void assertPwmFrequencyAbs(PwmInChnl chnl, double frequency,
			double freqTolerancePercent,
			PwmInFrequencyUnit unit) 
	{

		EnmPwm_Chnl diChnl = getPwmInChnl(chnl);
		
		double frequencyKHz = getFrequencyValue(frequency,unit);

		Rational freqRational = new Rational(frequencyKHz);

		int toleranceHz = (int) (freqTolerancePercent);


		exu.modTS()
				.objPWMInput()
				.afcAssertPwmFrequency(freqRational.getNum(),
						freqRational.getDenom(), toleranceHz,
						 diChnl);
	}
	
	/**
	 * Check the PWM Duty Cycle of a PWM channel.
	 * 
	 * @category Firmware Action
	 * @param chnl
	 *            ID of input PWM channel
	 * @param dutyCyclePercent
	 *            Dutycycle percentage e.g. 56.7
	 * @param duytTolerancePercent
	 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the expected
	 *            duty cycle is 65% and tolerance is 3% then any duty cycle
	 *            between 63.05% to 66.95% will be ok.
	 * @See {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM
	 *      Channels Enum}
	 */
	public void assertPwmDutyCycleAbs(PwmInChnl chnl,double dutyCyclePercent,double duytTolerancePercent) 
	{

		EnmPwm_Chnl diChnl = getPwmInChnl(chnl);
		

		Rational dutyRational = new Rational(dutyCyclePercent);


		int toleranceDuty = (int) (duytTolerancePercent);

		exu.modTS()
				.objPWMInput()
				.afcAssertPwmDuty(dutyRational.getNum(), dutyRational.getDenom(),
						toleranceDuty, diChnl);
	}
	
}
