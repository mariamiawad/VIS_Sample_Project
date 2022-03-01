package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfPWMOutput.EnmPwmOutChannel;
import libs.TestingPlatform.CastleCommlayer.UtilitiesLib.Rational;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
public class CastlePwmOutPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	EnmPwmOutChannel fChannelId;
	PwmOutFreqUnit fFrequencyUnit;
	ETS exu;
	double fFrequency;

		/**
		 * Unit of Frequency to be measured.
		 */
		public enum PwmOutFreqUnit {
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
		
	private double getFrequencyValue(double Frequency, PwmOutFreqUnit unit) {
		double scale = 1;

		if (unit == PwmOutFreqUnit.Hz) {
			scale = 1 / 1000.0;
		} else if (unit == PwmOutFreqUnit.KHz) {
			scale = 1.0;
		} else if (unit == PwmOutFreqUnit.MHz) {
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
	public CastlePwmOutPort(EnmPwmOutChannel channelId, double frequency, PwmOutFreqUnit frequencyUnit, ETS executionUnit){
		fChannelId = channelId;
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
	public Object[] apply(Object ... args){
		double dutyCyclePercent = (double) args[0];
		double frequencyKHz = getFrequencyValue(fFrequency, fFrequencyUnit);	
		Rational dutyRational = new Rational(dutyCyclePercent);
		Rational freqRational = new Rational(frequencyKHz);

		exu.comment("Generated PWM on channel %s with %.2f KHz and duty cycle equals %.2f ", fChannelId.toString(),
					frequencyKHz, dutyCyclePercent);
		exu.modTS().objPWMOutput().afcSetPwmChnlFreq(
							fChannelId,
							dutyRational.getNum(),
							freqRational.getNum(),
							freqRational.getDenom(),
							dutyRational.getDenom()
								);

		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}

	public void finalize() throws Throwable {

	}
}