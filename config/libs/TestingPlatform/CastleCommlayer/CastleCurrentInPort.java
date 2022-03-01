package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;
import config.ItfCurrentSense.Enmchannel;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager.PortType;

/**
 * @author mnagah
 * @version 2.2
 * @created 24-Jan-2018 1:53:45 PM
 * @updated 09-Oct-2018 2:54:10 PM
 * @updated maboelkh: 15-Jan-2019
 */  
public class CastleCurrentInPort implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};

	public enum ToleranceType{
		Absolute,
		Relative
	};

	Enmchannel fChannelId;
	MeasuredCurrent fMeasuredCurrent;
	CurrUnit fCurrentUnit;
	double fTolerance;
	ETS exu;
	final public static double ZeroCurrent =-3.0;
	public static int ZeroCurrent_MaxVal = 30;
	final public static double RESET = -2.0;
	final int EDGE = 0;
	final int LEVEL = 1;
	double fprevVal = RESET;
	public static PortType fPortType = PortType.Eventbased;
	public static ToleranceType fToleranceType = ToleranceType.Relative;
	
	/**
	* Unit of current to be measured.
	*/
	public enum CurrUnit {
		/**
		 * Ampere
		 */
		A,
		/**
		* Milli Ampere
		 */
		mA,
		/**
		* Micro Ampere
		*/
		uA,
	}
		
	public enum MeasuredCurrent {
			/**
			 * InstantaneousCurrent 1. <br>
			 * 	- No time pause is applied for Instantaneous Current assertion! <br>
			 */
			InstantaneousCurrent,
			/**
			 * AverageCurrent 2. <br>
			 * 	- 15mSec pause is applied to calculate Average Current (for PWM Current) before each Time Based assertion! <br>
			 */
			AverageCurrent,
			/**
			 * MaximumCurrent 3. <br>
			 * 	- 15mSec pause is applied for Maximum Current assertion! <br>
			 */
			MaximumCurrent,
			/**
			 * CurrentDutyCycle 4. <br>
			 * 	- 15mSec pause is applied to calculate Current Duty Cycle before each Time Based assertion! <br>
			 */
			CurrentDutyCycle,
			/**
			 * CurrentFrequency 5. <br>
			 * 	- 15mSec pause is applied to calculate Current Frequency before each Time Based assertion! <br>
			 * 	- Only Time Based assertion is available, No Events for Current Frequency yet! <br>
			 */
			CurrentFrequency,
			/**
			 * FilteredCurrent 6. <br>
			 * 	- 2000mSec pause is applied to calculate Filtered Current (more than 1024 samples for DC Current) before each Time Based assertion! <br>
			 * 	- Only Time Based assertion is available, No Events for Filtered Current yet! <br>
			 */
			FilteredCurrent
		}
		
	/**
	 * CurrentInPort <br>
	 * <br>
 	 * Choose MeasuredCurrentType in porting to be one of the following types:- <br>
 	 * 
	 * InstantaneousCurrent 1. <br>
	 * 	- No time pause is applied for Instantaneous Current assertion! <br>
	 * 
	 * AverageCurrent 2. <br>
	 * 	- 15mSec pause is applied to calculate Average Current (for PWM Current) before each Time Based assertion! <br>
	 * 
	 * MaximumCurrent 3. <br>
	 * 	- 15mSec pause is applied for Maximum Current assertion! <br>
	 * 
	 * CurrentDutyCycle 4. <br>
	 * 	- 15mSec pause is applied to calculate Current Duty Cycle before each Time Based assertion! <br>
	 * 
	 * CurrentFrequency 5. <br>
	 * 	- 15mSec pause is applied to calculate Current Frequency before each Time Based assertion! <br>
	 * 	- Only Time Based assertion is available, No Events for Current Frequency yet! <br>
	 * 
	 * FilteredCurrent 6. <br>
	 * 	- 2000mSec pause is applied to calculate Filtered Current (more than 1024 samples for DC Current) before each Time Based assertion! <br>
	 * 	- Only Time Based assertion is available, No Events for Filtered Current yet! <br>
	 * 
	 * @param channelId
	 * @param currentType
	 * @param currentUnit
	 * @param tolerance
	 * @param executionUnit
	 */
	public CastleCurrentInPort(Enmchannel channelId, MeasuredCurrent currentType, CurrUnit currentUnit, double tolerancePercent, ETS executionUnit){
		fChannelId = channelId;
		fMeasuredCurrent = currentType;
		fCurrentUnit = currentUnit;
		fTolerance = tolerancePercent;
		exu = executionUnit;
		
	}
		
	private double getCurrentmA(double current, CurrUnit unit) {
		double scale = 1;

		if (unit == CurrUnit.mA) {
			scale = 1.0;
		} else if (unit == CurrUnit.A) {
			scale = 1000.0;
		} else if (unit == CurrUnit.uA) {
			scale = 1 / 1000.0;
		}

		double currentMilli = current * scale;

		return currentMilli;
	}

	private double getTolerancemA(double mACurrent, float tolerance) {

		double mATolerance = (int) Math.round((mACurrent) * (tolerance / 100.0));

		if (mACurrent != 0 && mATolerance == 0) {
			mATolerance = (int) tolerance;
		}

		return mATolerance;
	}
	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object... args){
			double value =(double) args[0];
			double registerTime = (double) args[1];
			double registerTimeTolerance = (double) args[2];
			InToOutDelay_paused = (boolean) args[3];
			double mACurrent = getCurrentmA(value, fCurrentUnit);
			double tolerancemA = getTolerancemA(mACurrent, (float)fTolerance);
			if (fToleranceType == ToleranceType.Absolute){
				tolerancemA = fTolerance;
			}

		switch(fMeasuredCurrent)
		{
			case InstantaneousCurrent:
			 switch(fPortType)
			 {
			 	case Eventbased:
					IEvent instantenousCurrentReached = exu.modTS().objCurrentSense().objInstantenousCurrent(fChannelId.ordinal()).evtValueReached();
					if(value == RESET)
					{
						fprevVal =RESET;
						return ReturnObj();
					}
					if(fprevVal == RESET)
					{
						fprevVal = value;
						if(value == ZeroCurrent)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Assert Instantaneous current value for channel %s Zero Current", fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentInstantenous(fChannelId, ZeroCurrent_MaxVal/2, ZeroCurrent_MaxVal/2);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Assert Instantaneous current value %s on channel %s ", String.valueOf(mACurrent),fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentInstantenous(fChannelId, (int)mACurrent, (int)tolerancemA);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
					}
					else if( value != fprevVal )
					{	
						if(value == ZeroCurrent)
						{	
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Instantaneous current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objInstantenousCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									instantenousCurrentReached.getModEventId(),
									EDGE,
									ZeroCurrent_MaxVal/2,
									ZeroCurrent_MaxVal/2,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
						    exu.comment("Start measuring current on a channel %s", fChannelId.toString());
						    exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Instantaneous current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objInstantenousCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									instantenousCurrentReached.getModEventId(),
									EDGE,
									mACurrent,
									tolerancemA,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						fprevVal = value;
					}
					else if(value == fprevVal) 
					{
						if(value == ZeroCurrent)
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
						    exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Instantaneous current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objInstantenousCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									instantenousCurrentReached.getModEventId(),
									LEVEL,
									ZeroCurrent_MaxVal/2,
									ZeroCurrent_MaxVal/2,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
						    exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Instantaneous current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objInstantenousCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									instantenousCurrentReached.getModEventId(),
									LEVEL,
									mACurrent,
									tolerancemA,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
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
						if(value == ZeroCurrent)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Assert Instantaneous current value for channel %s Zero Current", fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentInstantenous(fChannelId, ZeroCurrent_MaxVal/2, ZeroCurrent_MaxVal/2);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Assert Instantaneous current value %s on channel %s ", String.valueOf(mACurrent),fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentInstantenous(fChannelId, (int)mACurrent, (int)tolerancemA);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
					}
					break;
			 	}
			
			break;
			
			case AverageCurrent:
			switch(fPortType)
			 {
			 	case Eventbased:
					IEvent averageCurrentReached = exu.modTS().objCurrentSense().objAverageCurrent(fChannelId.ordinal()).evtValueReached();
					if(value == RESET)
					{
						fprevVal =RESET;
						return ReturnObj();
					}
					if(fprevVal == RESET)
					{
						fprevVal = value;
						if(value == ZeroCurrent)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert Average current value for channel %s Zero Current", fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentAverage(fChannelId, ZeroCurrent_MaxVal/2, ZeroCurrent_MaxVal/2);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert Average current value %s on channel %s ", String.valueOf(mACurrent),fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentAverage(fChannelId, (int)mACurrent, (int)tolerancemA);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
					}
					else if( value != fprevVal )
					{	
						if(value == ZeroCurrent)
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Average current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objAverageCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									averageCurrentReached.getModEventId(),
									EDGE,
									ZeroCurrent_MaxVal/2,
									ZeroCurrent_MaxVal/2,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Average current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objAverageCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									averageCurrentReached.getModEventId(),
									EDGE,
									mACurrent,
									tolerancemA,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						fprevVal = value;
					}
					else if(value == fprevVal) 
					{
						if(value == ZeroCurrent)
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Average current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objAverageCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									averageCurrentReached.getModEventId(),
									LEVEL,
									ZeroCurrent_MaxVal/2,
									ZeroCurrent_MaxVal/2,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Average current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objAverageCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									averageCurrentReached.getModEventId(),
									LEVEL,
									mACurrent,
									tolerancemA,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
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
							if(value == ZeroCurrent)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
								exu.pause(15);
								exu.comment("Assert Average current value for channel %s Zero Current", fChannelId.toString());
								exu.modTS().objCurrentSense().afcassertCurrentAverage(fChannelId, ZeroCurrent_MaxVal/2, ZeroCurrent_MaxVal/2);
								exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
								exu.modTS().objCurrentSense().afcresetMeaurments();
							}
							else
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
								exu.pause(15);
								exu.comment("Assert Average current value %s on channel %s ", String.valueOf(mACurrent),fChannelId.toString());
								exu.modTS().objCurrentSense().afcassertCurrentAverage(fChannelId, (int)mACurrent, (int)tolerancemA);
								exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
								exu.modTS().objCurrentSense().afcresetMeaurments();
							}
						}
					break;
			 	}
			break;
			
			case MaximumCurrent:
			switch(fPortType)
			 {
			 	case Eventbased:
					IEvent maximumCurrentReached = exu.modTS().objCurrentSense().objMaxCurrent(fChannelId.ordinal()).evtValueReached();
					if(value == RESET)
					{
						fprevVal =RESET;
						return ReturnObj();
					}
					if(fprevVal == RESET)
					{
						fprevVal = value;
						if(value == ZeroCurrent)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert Maximum current value %s on channel %s ", String.valueOf(mACurrent),fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentMax(fChannelId, ZeroCurrent_MaxVal/2, ZeroCurrent_MaxVal/2);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert Maximum current value for channel %s Zero Current", fChannelId.toString());
							exu.modTS().objCurrentSense().afcassertCurrentMax(fChannelId, (int)mACurrent, (int)tolerancemA);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
					}
					else if( value != fprevVal )
					{	
						if(value == ZeroCurrent)
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
						    exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Maximum current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objMaxCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									maximumCurrentReached.getModEventId(),
									EDGE,
									ZeroCurrent_MaxVal/2,
									ZeroCurrent_MaxVal/2,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
						    exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Maximum current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objMaxCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									maximumCurrentReached.getModEventId(),
									EDGE,
									mACurrent,
									tolerancemA,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						fprevVal = value;
					}
					else if(value == fprevVal) 
					{
						if(value == ZeroCurrent)
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
						    exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Maximum current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objMaxCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									maximumCurrentReached.getModEventId(),
									LEVEL,
									ZeroCurrent_MaxVal/2,
									ZeroCurrent_MaxVal/2,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
						    exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("Maximum current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objMaxCurrent(fChannelId.ordinal()).afcCheckEventBasedSignals(
									maximumCurrentReached.getModEventId(),
									LEVEL,
									mACurrent,
									tolerancemA,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
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
							if(value == ZeroCurrent)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
								exu.pause(15);
								exu.comment("Assert Maximum current value for channel %s Zero Current", fChannelId.toString());
								exu.modTS().objCurrentSense().afcassertCurrentMax(fChannelId, ZeroCurrent_MaxVal/2, ZeroCurrent_MaxVal/2);
								exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
								exu.modTS().objCurrentSense().afcresetMeaurments();	
							}
							else
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
								exu.pause(15);
								exu.comment("Assert Maximum current value %s on channel %s ", String.valueOf(mACurrent),fChannelId.toString());
								exu.modTS().objCurrentSense().afcassertCurrentMax(fChannelId, (int)mACurrent, (int)tolerancemA);
								exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
								exu.modTS().objCurrentSense().afcresetMeaurments();	
							}
						}
					break;
					}
			break;
			
			case CurrentDutyCycle:
				int requestedDuty = (int) (value * 100);
				int toleranceDuty = (int) Math.round((value) * (fTolerance / 100.0));
				if (fToleranceType == ToleranceType.Absolute){
					toleranceDuty = (int) fTolerance;
				}
			switch(fPortType)
			 {
			 	case Eventbased:
					IEvent DutyCurrentReached = exu.modTS().objCurrentSense().objDutyCycle(fChannelId.ordinal()).evtValueReached();
					if(value == RESET)
					{
						fprevVal =RESET;
						return ReturnObj();
					}
					if(fprevVal == RESET)
					{
						fprevVal = value;
						if(value == ZeroCurrent)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert CurrentDutyCycle value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)0, (float)0);
							exu.modTS().objCurrentSense().afcassertCurrentDutyCycle(fChannelId, 0, 0);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();	
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert CurrentDutyCycle value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)requestedDuty, (float)toleranceDuty);
							exu.modTS().objCurrentSense().afcassertCurrentDutyCycle(fChannelId, requestedDuty/100, toleranceDuty);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();	
						}	
					}
					else if( value != fprevVal )
					{	
						if(value == ZeroCurrent)
						{
							exu.comment("Start measuring current DutyCycle on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("DutyCycle current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objDutyCycle(fChannelId.ordinal()).afcCheckEventBasedSignals(
									DutyCurrentReached.getModEventId(),
									EDGE,
									0,
									0,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
							exu.comment("Start measuring current DutyCycle on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("DutyCycle current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objDutyCycle(fChannelId.ordinal()).afcCheckEventBasedSignals(
									DutyCurrentReached.getModEventId(),
									EDGE,
									mACurrent,
									toleranceDuty,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						fprevVal = value;
					}
					else if(value == fprevVal) 
					{
						if(value == ZeroCurrent)
						{
							exu.comment("Start measuring current DutyCycle on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("DutyCycle current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objDutyCycle(fChannelId.ordinal()).afcCheckEventBasedSignals(
									DutyCurrentReached.getModEventId(),
									LEVEL,
									0,
									0,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						else
						{
							exu.comment("Start measuring current DutyCycle on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.comment("DutyCycle current Value on Channel %s equals to  %d within time %d ms ",fChannelId.toString(),0,(int) (double) args[1]);
							exu.modTS().objCurrentSense().objDutyCycle(fChannelId.ordinal()).afcCheckEventBasedSignals(
									DutyCurrentReached.getModEventId(),
									LEVEL,
									mACurrent,
									toleranceDuty,
									registerTime,
									registerTimeTolerance
									,1
									);
						}
						fprevVal = value;
					}
					break;
					
					case Timebased:
						requestedDuty = (int) (value * 100);
						toleranceDuty = (int) Math.round((requestedDuty) * (fTolerance / 100.0));
						if (fToleranceType == ToleranceType.Absolute){
							toleranceDuty = (int) fTolerance * 100;
						}
						if(value == RESET)
						{
							return ReturnObj();
						}
						else 
						{	
							if(value == ZeroCurrent)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
								exu.pause(15);
								exu.comment("Assert CurrentDutyCycle value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)0, (float)0);
								exu.modTS().objCurrentSense().afcassertCurrentDutyCycle(fChannelId, 0, 0);
								exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
								exu.modTS().objCurrentSense().afcresetMeaurments();	
							}
							else
							{
								Request_pauseInToOutDelay(registerTime);
								exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
								exu.pause(15);
								exu.comment("Assert CurrentDutyCycle value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)requestedDuty, (float)toleranceDuty);
								exu.modTS().objCurrentSense().afcassertCurrentDutyCycle(fChannelId, requestedDuty/100, toleranceDuty);
								exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
								exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
								exu.modTS().objCurrentSense().afcresetMeaurments();	
							}	
						}
					break;
					}
			break;
			
			case CurrentFrequency:
				int requestedFreq = (int) value;
				int toleranceFreq = (int) Math.round((value) * (fTolerance / 100.0));
				if (fToleranceType == ToleranceType.Absolute){
					toleranceFreq = (int) fTolerance;
				}
				if(value == RESET)
					{
						return ReturnObj();
					}
					else 
					{	
						if(value == ZeroCurrent)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert CurrentFrequency value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)requestedFreq, (float)toleranceFreq);
							exu.modTS().objCurrentSense().afcassertCurrentFrequency(fChannelId, 0, 0);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(15);
							exu.comment("Assert CurrentFrequency value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)requestedFreq, (float)toleranceFreq);
							exu.modTS().objCurrentSense().afcassertCurrentFrequency(fChannelId, requestedFreq, toleranceFreq);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}	
					}			
			break;
			
			case FilteredCurrent:
				int requestedcurr = (int) mACurrent;
				int tolerancecurr = (int) Math.round((mACurrent) * (fTolerance / 100.0));
				if (fToleranceType == ToleranceType.Absolute){
					tolerancecurr = (int) fTolerance;
				}
				if(value == RESET)
					{
						return ReturnObj();
					}
					else 
					{	
						if(value == ZeroCurrent)
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(2000);
							exu.comment("Assert FilteredCurrent value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)requestedcurr, (float)tolerancecurr);
							exu.modTS().objCurrentSense().afcAssertFilteredCurrent(fChannelId, ZeroCurrent_MaxVal/2, ZeroCurrent_MaxVal/2);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
						}
						else
						{
							Request_pauseInToOutDelay(registerTime);
							exu.comment("Start measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstartCurrentacquisition(fChannelId);
							exu.pause(2000);
							exu.comment("Assert FilteredCurrent value for channel %s equals %.2f mA with tolerance %.2f", fChannelId.toString(), (float)requestedcurr, (float)tolerancecurr);
							exu.modTS().objCurrentSense().afcAssertFilteredCurrent(fChannelId, requestedcurr, tolerancecurr);
							exu.comment("Stop measuring current on a channel %s", fChannelId.toString());
							exu.modTS().objCurrentSense().afcstopCurrentacquisition(fChannelId);
							exu.modTS().objCurrentSense().afcresetMeaurments();
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
}
