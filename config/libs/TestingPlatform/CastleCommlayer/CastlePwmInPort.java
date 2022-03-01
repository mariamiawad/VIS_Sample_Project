package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;
import config.ItfPwmIn.EnmPwm_Chnl;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager.PortType;
import libs.TestingPlatform.CastleCommlayer.UtilitiesLib.Rational;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
public class CastlePwmInPort implements ICastlePort {
	
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	EnmPwm_Chnl fChannelId;
	PwmSignalMeasured fSignalMeasured;
	PwmInFreqUnit fFrequencyUnit;
	double fduytTolerancePercent;
	double fFreqTolerancePercent;
	double fFrequency;
	String fname;
	int EDGE = 0;
	int LEVEL = 1;
	double RESET = -2.0;
	double fprevVal = RESET;
	public static PortType fPortType = PortType.Eventbased;
	
		/**
		 * Unit of Frequency to be measured.
		 */
		public enum PwmInFreqUnit {
			/**
			 * Hertz
			 */
			Hz,
			/**
			 * Kilo Hertz
			 */
			KHz,
			/**
			 * Mega Hertz
			 */
			MHz
		}
		
		/**
		 * PWM Signals to be measured.
		 */
		public enum PwmSignalMeasured {
			/**
			 * PWMDutyCycle
			 */
			PWMDutyCycle,
			/**
			 * PWMFrequency
			 */
			PWMFrequency,
			/**
			 * PWMDutyCycleAndFrequency
			 */
			PWMDutyCycleAndFrequency,
		}
		
	private double getFrequencyValue(double Frequency, PwmInFreqUnit unit) {
		double scale = 1;

		if (unit == PwmInFreqUnit.Hz) {
			scale = 1 / 1000.0;
		} else if (unit == PwmInFreqUnit.KHz) {
			scale = 1.0;
		} else if (unit == PwmInFreqUnit.MHz) {
			scale = 1000;
		}
		double frequencyKiloHz = Frequency * scale;
		return frequencyKiloHz;
	}
	/**
	 * 
	 * @param channelId
	 * @param signalMeasured
	 * @param duytTolerancePercent
	 * @param frequency
	 * @param freqTolerancePercent
	 * @param frequencyUnit
	 * @param executionUnit
	 */
	public CastlePwmInPort(EnmPwm_Chnl channelId, PwmSignalMeasured signalMeasured, double duytTolerancePercent, double frequency, double freqTolerancePercent, PwmInFreqUnit frequencyUnit , ETS executionUnit){
		fChannelId = channelId;
		fduytTolerancePercent = duytTolerancePercent;
		fSignalMeasured = signalMeasured;
		fFrequency = frequency;
		fFreqTolerancePercent = freqTolerancePercent;
		fFrequencyUnit = frequencyUnit;
		exu = executionUnit;
	}

	/**
	 * 
	 * @param args
	 */
	@Override
	public Object[] apply(Object ... args){
		double value =(double) args[0];
		double valueTolerance = fduytTolerancePercent;
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		Rational dutyRational = new Rational(value);
		int toleranceDuty = (int) Math.round(1000 * (value) * (valueTolerance / 100.0));
		double frequencyKHz = getFrequencyValue(fFrequency,fFrequencyUnit);
		Rational freqRational = new Rational(frequencyKHz);
		int toleranceHz = (int) Math.round(1000 * (1000 * frequencyKHz)
				* (fFreqTolerancePercent / 100.0));
				
		switch(fSignalMeasured)
		{
			case PWMDutyCycle:
			switch(fPortType)
				 {
				 	case Eventbased:
						IEvent evPwmReached = exu.modTS().objPWMInput().objDutyCycle(fChannelId.ordinal()).evtValueReached();
				
						if(value == RESET)
						{
							fprevVal =RESET;
							return ReturnObj();
						}
						
						if(fprevVal == RESET)
						{
							fprevVal = value;
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
							exu.modTS().objPWMInput().afcStartPwm(fChannelId);
							exu.comment("Assert PWM on channel %s with duty cycle equals %.2f with %.2f tolerance",
									fChannelId.toString(), value, valueTolerance);
							exu.modTS().objPWMInput().afcAssertPwmDuty(dutyRational.getNum(), dutyRational.getDenom(), toleranceDuty, fChannelId);
						}
						else if( value != fprevVal )
						{		
							exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
							exu.modTS().objPWMInput().afcStartPwm(fChannelId);
							exu.comment("PWM Signal %s equals to  %d within time %d ms ",fname,(int)value,(int) registerTime);
							exu.modTS().objPWMInput().objDutyCycle(fChannelId.ordinal()).afcCheckEventBasedSignals(
									evPwmReached.getModEventId(),
									EDGE,
									value,
									valueTolerance,
									registerTime,
									registerTimeTolerance
									,1
									);
							fprevVal = value;
							
						}
						else if(value == fprevVal) 
						{
							exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
							exu.modTS().objPWMInput().afcStartPwm(fChannelId);
							exu.comment("PWM Signal %s equals to  %d within time %d ms",fname,(int)value,(int) registerTime);
							exu.modTS().objPWMInput().objDutyCycle(fChannelId.ordinal()).afcCheckEventBasedSignals(
									evPwmReached.getModEventId(),
									LEVEL,
									value,
									valueTolerance,
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
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
							exu.modTS().objPWMInput().afcStartPwm(fChannelId);
							exu.comment("Assert PWM on channel %s with duty cycle equals %.2f with %.2f tolerance",
									fChannelId.toString(), value, valueTolerance);
							exu.modTS().objPWMInput().afcAssertPwmDuty(dutyRational.getNum(), dutyRational.getDenom(), toleranceDuty, fChannelId);
						}
						break;
				 }
		break;
		case PWMFrequency:
				Request_pauseInToOutDelay(registerTime);
				exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
				exu.modTS().objPWMInput().afcStartPwm(fChannelId);
				exu.comment("Assert PWM on channel %s with frequency %.2f KHz with %.2f tolerance.", fChannelId.toString(), fFrequency,
					fFreqTolerancePercent);	
				exu.modTS().objPWMInput().afcAssertPwmFrequency(freqRational.getNum(),freqRational.getDenom(), toleranceHz,fChannelId);	
			break;
			
		case PWMDutyCycleAndFrequency:
				Request_pauseInToOutDelay(registerTime);
				exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
				exu.modTS().objPWMInput().afcStartPwm(fChannelId);
				exu.comment("Assert PWM on channel %s with frequency %.2f KHz with %.2f tolerance  and duty cycle equals %.2f with %.2f tolerance",
					fChannelId.toString(), fFrequency, fFreqTolerancePercent, value, valueTolerance);
				exu.modTS().objPWMInput().afcAssertPwm(freqRational.getNum(),freqRational.getDenom(), toleranceHz, dutyRational.getNum(), dutyRational.getDenom(),
						toleranceDuty, fChannelId);	
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

	public void finalize() throws Throwable {

	}
}