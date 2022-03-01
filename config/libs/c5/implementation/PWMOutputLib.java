package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import config.ETS;
import config.ItfPWMOutput.EnmPwmOutChannel;
import libs.c5.implementation.UtilitiesLib.Rational;
import libs.c5.interfaces.C5.PwmOutput.PWMGenChnl;
import libs.c5.interfaces.C5.PwmOutput.PwmOutFrequencyUnit;

/**
 * This class is implementation of standard library APIs to be used in
 * controlling PWM output pins.
 * <p>
 * A PWM output is by nature a Digital port, it can be either set to PWM or
 * digital output. This class must not be used directly by testers (only
 * firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class PWMOutputLib implements ILib {

	ETS exu;
	
	/** Maximum frequency that can be generated using the current firmware */
	//private static final int MAX_FREQ_HZ = 400000;

	/**
	 * /** Class Constructors
	 **/
	public PWMOutputLib() {
		this.exu = (ETS) exu;
	}

	public PWMOutputLib(IExu exu) {
		this.exu = (ETS) exu;
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

	public void setPwmOutputChannel(PWMGenChnl chnl, double frequency, PwmOutFrequencyUnit unit,
			double dutyCyclePercent) {
		
		double frequencyKHz = getFrequencyValue(frequency, unit);
		
		Rational dutyRational = new Rational(dutyCyclePercent);
		Rational freqRational = new Rational(frequencyKHz);

		EnmPwmOutChannel pwmObj = this.getPwmOutChannel(chnl);

		exu().modTS().objPWMOutput().afcSetPwmChnlFreq(
							pwmObj,
							dutyRational.getNum(),
							freqRational.getNum(),
							freqRational.getDenom(),
							dutyRational.getDenom()
								);

		return ;
	}

	
	private EnmPwmOutChannel getPwmOutChannel(PWMGenChnl chnl) {

		int index = Arrays.asList(PWMGenChnl.values()).indexOf(chnl);

		return EnmPwmOutChannel.values()[index];
	}
	
	private double getFrequencyValue(double Frequency, PwmOutFrequencyUnit unit) {
		double scale = 1;

		if (unit == PwmOutFrequencyUnit.Hz) {
			scale = 1 / 1000.0;
		} else if (unit == PwmOutFrequencyUnit.KHz) {
			scale = 1.0;
		} else if (unit == PwmOutFrequencyUnit.MHz) {
			scale = 1000;
		}

		double frequencyKiloHz = Frequency * scale;

		return frequencyKiloHz;
	}
}
