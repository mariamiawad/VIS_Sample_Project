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
 * @updated 21-Jan-2020 ahamisa
 */ 
public class CastlePwmInPortWithFreq implements ICastlePort {
	
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	EnmPwm_Chnl fChannelId;
	PwmUpdatedSignalMeasured fSignalMeasured;
	PwmInUpdatedFreqUnit fFrequencyUnit;
	double fduytTolerancePercent;
	double fFreqTolerancePercent;
	double fFrequency;
	double fduty;
	String fname;
	int EDGE = 0;
	int LEVEL = 1;
	double RESET = -2.0;
	double fprevVal = RESET;
	public static PortType fPortType = PortType.Eventbased;
	
		/**
		 * Unit of Frequency to be measured.
		 */
		public enum PwmInUpdatedFreqUnit {
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
		public enum PwmUpdatedSignalMeasured {
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
		
	private double getFrequencyValue(double Frequency, PwmInUpdatedFreqUnit unit) {
		double scale = 1;

		if (unit == PwmInUpdatedFreqUnit.Hz) {
			scale = 1 / 1000.0;
		} else if (unit == PwmInUpdatedFreqUnit.KHz) {
			scale = 1.0;
		} else if (unit == PwmInUpdatedFreqUnit.MHz) {
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
	 
		 
	public CastlePwmInPortWithFreq(EnmPwm_Chnl channelId,PwmUpdatedSignalMeasured signalMeasured,double duty,double duytTolerancePercent, double frequency, double freqTolerancePercent,PwmInUpdatedFreqUnit frequencyUnit , ETS executionUnit){
		fChannelId = channelId;
		fduty=duty ;
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
	
		double valueTolerance = fduytTolerancePercent;
		double FreqTolerance =  fFreqTolerancePercent;
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		
		switch(fSignalMeasured)
		{
			case PWMDutyCycle:
			
			double value =(double) args[0];
			Rational dutyRational1 = new Rational(value);
			// int toleranceDuty1 = (int) Math.round(1000* (value) * (valueTolerance / 100.0));  
            int toleranceDuty1 = (int) Math.round(1000* (value) * (valueTolerance / 100.0));  
			
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
							exu.modTS().objPWMInput().afcAssertPwmDuty(dutyRational1.getNum(), dutyRational1.getDenom(), toleranceDuty1, fChannelId);
							
						}
						else if( value != fprevVal )
						{		
							exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
							exu.modTS().objPWMInput().afcStartPwm(fChannelId);
							exu.comment("PWM Signal %s equals to  %d within time %d ms ",fname,(int)value*1000,(int) registerTime);
							exu.modTS().objPWMInput().objDutyCycle(fChannelId.ordinal()).afcCheckEventBasedSignals(
									evPwmReached.getModEventId(),
									EDGE,
									value*1000,
									toleranceDuty1,
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
									value*1000,
									toleranceDuty1,
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
							exu.modTS().objPWMInput().afcAssertPwmDuty(dutyRational1.getNum(), dutyRational1.getDenom(), toleranceDuty1, fChannelId);
						}
						break;
				 }
		break;
		case PWMFrequency:
		
		double frequencyKHz =(double) args[0];
	    double frequencyKHz1 = getFrequencyValue(frequencyKHz,fFrequencyUnit);
		Rational freqRational = new Rational(frequencyKHz1);
		int toleranceHz =( (int) Math.round(1000 * (1000*frequencyKHz1)
		* (FreqTolerance / 100.0)))/1000;
		
				Request_pauseInToOutDelay(registerTime);
				exu.comment("Start continuous check the PWM frequency on the %s PWM channel", fChannelId.toString());
				exu.modTS().objPWMInput().afcStartPwm(fChannelId);
				exu.comment("Assert PWM on channel %s with frequency %.2f KHz with %.2f tolerance.", fChannelId.toString(), frequencyKHz,
					FreqTolerance);	
				exu.modTS().objPWMInput().afcAssertPwmFrequency(freqRational.getNum(),freqRational.getDenom(), toleranceHz,fChannelId);
				
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