package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfPWMOutput.EnmPwmOutChannel;
import libs.TestingPlatform.CastleCommlayer.UtilitiesLib.Rational;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 * @updated 21-Jan-2020 ahamisa
 */ 
public class CastlePwmOutPortWithFreq implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	EnmPwmOutChannel fChannelId;
	PwmOutUpdatedFreqUnit fFrequencyUnit;
	PwmGeneratedSignal fGeneratedSignal;
	ETS exu;
	double fFrequency;
	double fduty;
	

		/**
		 * Unit of Frequency to be measured.
		 */
		public enum PwmOutUpdatedFreqUnit {
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
		 * PWM Signals to be Generated.
		 */
		public enum PwmGeneratedSignal {
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
		
	private double getFrequencyValue(double Frequency, PwmOutUpdatedFreqUnit unit) {
		double scale = 1;

		if (unit == PwmOutUpdatedFreqUnit.Hz) {
			scale = 1 / 1000.0;
		} else if (unit == PwmOutUpdatedFreqUnit.KHz) {
			scale = 1.0;
		} else if (unit == PwmOutUpdatedFreqUnit.MHz) {
			scale = 1000;
		}

		double frequencyKiloHz = Frequency * scale;
		return frequencyKiloHz;
	}
	
	    
	/**
	 * 
	 * @param channelId
	 * @param frequency
	 * @param frequencyUnit
	 * @param executionUnit
	 */
	 // duty and frequency as an initial value 
	public CastlePwmOutPortWithFreq(EnmPwmOutChannel channelId,PwmGeneratedSignal GeneratedSignal,double Duty, double frequency, PwmOutUpdatedFreqUnit frequencyUnit, ETS executionUnit){
		fChannelId = channelId;
		fGeneratedSignal=GeneratedSignal;
		fduty = Duty ;
		fFrequencyUnit = frequencyUnit;
		exu = executionUnit;
		fFrequency=frequency;
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args)
	{
		
		double dutyValue =fduty ;
        Rational dutyRational1 = new Rational(dutyValue);
		double frequencyKHz = getFrequencyValue(fFrequency, fFrequencyUnit);	
		Rational freqRational = new Rational(frequencyKHz);
		
		switch (fGeneratedSignal)
		{
		case PWMDutyCycle:
		
		double dutyCyclePercent = (double) args[0];
        Rational dutyRational = new Rational(dutyCyclePercent);
		exu.comment("Generated PWM on channel %s with %.2f KHz and duty cycle equals %.2f ", fChannelId.toString(),
					frequencyKHz, dutyCyclePercent);
		exu.modTS().objPWMOutput().afcSetPwmChnlFreq(
							fChannelId,
							dutyRational.getNum(),
							freqRational.getNum(),
							freqRational.getDenom(),
							dutyRational.getDenom()
								);
	     break;
	
	
	 case PWMFrequency :
	
	double frequencyValue = (double) args[0];
	double frequencyGenerateKHz  = getFrequencyValue(frequencyValue, fFrequencyUnit);
	Rational freqRational2 = new Rational(frequencyGenerateKHz);
	
	   exu.comment("Generated PWM on channel %s with %.2f KHz and duty cycle equals %.2f ", fChannelId.toString(),
					frequencyGenerateKHz, dutyValue);
		exu.modTS().objPWMOutput().afcSetPwmChnlFreq(
							fChannelId,
							dutyRational1.getNum(),
							freqRational2.getNum(),
							freqRational2.getDenom(),
							dutyRational1.getDenom()
								);
								

		
		break ;
	default:
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