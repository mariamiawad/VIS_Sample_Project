package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;
import config.ItfVoltageSense.Enmchannel;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager.PortType;

/**
 * @author mnagah
 * @version 2.1
 * @created 28-Jan-2018 1:53:45 PM
 * @updated maboelkh: 16-Jan-2019
 */  
public class CastleVoltageInPort implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	Enmchannel voltageChnl;
	MeasuredVoltage fMeasuredVoltage;
	VoltUnit fVoltageUnit;
	double fTolerance;
	ETS exu;
	final public static double ZeroVoltage =-4.0;
	public static int ZeroVoltage_MaxVal = 40;
	final public static double RESET = -2.0;
	final int EDGE = 0;
	final int LEVEL = 1;
	double fprevVal = RESET;
	public static PortType fPortType = PortType.Eventbased;
	
	/**
		 * Unit of Voltage to be measured.
		 */
		public enum VoltUnit {
			/**
			 * Volt
			 */
			V,
			/**
			 * Milli Volt
			 */
			mV,
			/**
			 * Micro Volt
			 */
			uV
		}

	public enum MeasuredVoltage {
			/**
			 * InstantaneousVoltage 1. <br>
			 * 	- No time pause is applied for Instantaneous Voltage assertion! <br>
			 */
			InstantaneousVoltage,
			/**
			 * AverageVoltage 2. <br>
			 * 	- 15mSec pause is applied to calculate Average Voltage before each Time Based assertion! <br>
			 */
			AverageVoltage,
			/**
			 * MaximumVoltage 3. <br>
			 * 	- 15mSec pause is applied for Maximum Voltage assertion! <br>
			 */
			MaximumVoltage,
		}
		
	/**
	 * VoltageInPort <br>
	 * <br>
 	 * Choose MeasuredVoltageType in porting to be one of the following types:- <br>
 	 *
	 * InstantaneousVoltage 1. <br>
	 * 	- No time pause is applied for Instantaneous Voltage assertion! <br>
	 *
	 * AverageVoltage 2. <br>
	 * 	- 15mSec pause is applied to calculate Average Voltage before each Time Based assertion! <br>
	 *
	 * MaximumVoltage 3. <br>
	 * 	- 15mSec pause is applied for Maximum Voltage assertion! <br>
	 *
	 * @param channelId
	 * @param voltageType
	 * @param voltageUnit
	 * @param tolerance
	 * @param executionUnit
	 */
	public CastleVoltageInPort(config.ItfVoltageSense.Enmchannel channelId, MeasuredVoltage voltageType, VoltUnit voltageUnit, double tolerancePercent, ETS executionUnit){
		voltageChnl = channelId;
		fMeasuredVoltage = voltageType;
		fVoltageUnit = voltageUnit;
		fTolerance = tolerancePercent;
		exu = executionUnit;	
	}
		
	private double getVoltagemA(double voltage, VoltUnit unit) {
		double scale = 1;

		if (unit == VoltUnit.mV) {
			scale = 1.0;
		} else if (unit == VoltUnit.V) {
			scale = 1000.0;
		} else if (unit == VoltUnit.uV) {
			scale = 1 / 1000.0;
		}

		double voltageMilli = voltage * scale;

		return voltageMilli;
	}

	private double getTolerancemV(double mVVoltage, float tolerance) {

		int mVTolerance = (int) Math.round((mVVoltage) * (tolerance / 100.0));

		if (mVVoltage != 0 && mVTolerance == 0) {
			mVTolerance = (int) tolerance;
		}

		return mVTolerance;
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
		double mAVoltage = getVoltagemA(value, fVoltageUnit);
		double tolerancemV = getTolerancemV(mAVoltage, (float)fTolerance);
		
		switch(fMeasuredVoltage)
		{
			case InstantaneousVoltage:
				switch(fPortType)
				 {
				 	case Eventbased:
						IEvent instantenousVoltageReached = exu.modTS().objVoltageSense().objInstantenousVoltage(voltageChnl.ordinal()).evtValueReached();
						if(value == RESET)
						{
							fprevVal =RESET;
							return ReturnObj();
						}
						if(fprevVal == RESET)
						{
							fprevVal = value;
							
							if(value == ZeroVoltage)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value for channel %s Zero volt", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageInstantenous(voltageChnl, ZeroVoltage_MaxVal/2, ZeroVoltage_MaxVal/2);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
							else
							{	
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value %s on channel %s ", String.valueOf(mAVoltage),voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageInstantenous(voltageChnl, (int)mAVoltage, (int)tolerancemV);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
						}
						else if( value != fprevVal )
						{	
							if(value == ZeroVoltage)
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value for channel %s Zero Voltage", voltageChnl.toString());
								exu.modTS().objVoltageSense().objInstantenousVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
										instantenousVoltageReached.getModEventId(),
										EDGE,
										ZeroVoltage_MaxVal/2,
										ZeroVoltage_MaxVal/2,
										registerTime,
										registerTimeTolerance
										,1
										);
							}
							else
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value for channel %s equals %s with tolerance %s", voltageChnl.toString(), mAVoltage, fTolerance);
								exu.modTS().objVoltageSense().objInstantenousVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
										instantenousVoltageReached.getModEventId(),
										EDGE,
										mAVoltage,
										tolerancemV,
										registerTime,
										registerTimeTolerance
										,1
										);
							}
							fprevVal = value;
						}
						else if(value == fprevVal) 
						{
							if(value == ZeroVoltage)
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value for channel %s Zero Voltage", voltageChnl.toString());
								exu.modTS().objVoltageSense().objInstantenousVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
										instantenousVoltageReached.getModEventId(),
										LEVEL,
										ZeroVoltage_MaxVal/2,
										ZeroVoltage_MaxVal/2,
										registerTime,
										registerTimeTolerance
										,1
										);
							}
							else
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value for channel %s equals %s with tolerance %s", voltageChnl.toString(), mAVoltage, fTolerance);
								exu.modTS().objVoltageSense().objInstantenousVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
										instantenousVoltageReached.getModEventId(),
										LEVEL,
										mAVoltage,
										tolerancemV,
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
							if(value == ZeroVoltage)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value for channel %s Zero volt", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageInstantenous(voltageChnl, ZeroVoltage_MaxVal/2, ZeroVoltage_MaxVal/2);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
							else
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Instantaneous Voltage value %s on channel %s ", String.valueOf(mAVoltage),voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageInstantenous(voltageChnl, (int)mAVoltage, (int)tolerancemV);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
						}
						break;
				 	}
			break;
			
			case AverageVoltage:
				switch(fPortType)
				 {
				 	case Eventbased:
						IEvent averageVoltageReached = exu.modTS().objVoltageSense().objAverageVoltage(voltageChnl.ordinal()).evtValueReached();
						if(value == RESET)
						{
							fprevVal =RESET;
							return ReturnObj();
						}
						if(fprevVal == RESET)
						{
							fprevVal = value;
							if(value == ZeroVoltage)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Average Voltage value for channel %s Zero volt", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageAverage(voltageChnl, ZeroVoltage_MaxVal/2, ZeroVoltage_MaxVal/2);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
							else
							{	
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Average Voltage value %s on channel %s ", String.valueOf(mAVoltage),voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageAverage(voltageChnl, (int)mAVoltage, (int)tolerancemV);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
						}
						else if( value != fprevVal )
						{	
							if(value == ZeroVoltage)
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Average Voltage value for channel %s equals %s with tolerance %s after pausing time %s for sampling", voltageChnl.toString(), mAVoltage, fTolerance, registerTime);
								exu.modTS().objVoltageSense().objAverageVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								averageVoltageReached.getModEventId(),
								EDGE,
								ZeroVoltage_MaxVal/2,
								ZeroVoltage_MaxVal/2,
								registerTime,
								registerTimeTolerance
								,1
								);
							}
							else
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Average Voltage value for channel %s equals %s with tolerance %s after pausing time %s for sampling", voltageChnl.toString(), mAVoltage, fTolerance, registerTime);
								exu.modTS().objVoltageSense().objAverageVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								averageVoltageReached.getModEventId(),
								EDGE,
								mAVoltage,
								tolerancemV,
								registerTime,
								registerTimeTolerance
								,1
								);
							}
							fprevVal = value;
						}
						else if(value == fprevVal) 
						{
							if(value == ZeroVoltage)
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Average Voltage value for channel %s equals %.2f mV with tolerance %.2f after pausing time %s for sampling", voltageChnl.toString(), (float)mAVoltage, (float)fTolerance, registerTime);
								exu.modTS().objVoltageSense().objAverageVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								averageVoltageReached.getModEventId(),
								LEVEL,
								ZeroVoltage_MaxVal/2,
								ZeroVoltage_MaxVal/2,
								registerTime,
								registerTimeTolerance
								,1
								);
							}
							else
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Average Voltage value for channel %s equals %.2f mV with tolerance %.2f after pausing time %s for sampling", voltageChnl.toString(), (float)mAVoltage, (float)fTolerance, registerTime);
								exu.modTS().objVoltageSense().objAverageVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								averageVoltageReached.getModEventId(),
								LEVEL,
								mAVoltage,
								tolerancemV,
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
							if(value == ZeroVoltage)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Average Voltage value for channel %s Zero volt", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageAverage(voltageChnl, ZeroVoltage_MaxVal/2, ZeroVoltage_MaxVal/2);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
							else
							{	
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Average Voltage value %s on channel %s ", String.valueOf(mAVoltage),voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageAverage(voltageChnl, (int)mAVoltage, (int)tolerancemV);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
						}
					break;
					}
			break;
			case MaximumVoltage:
				switch(fPortType)
				 {
				 	case Eventbased:
						IEvent maximumVoltageReached = exu.modTS().objVoltageSense().objMaxVoltage(voltageChnl.ordinal()).evtValueReached();
						if(value == RESET)
						{
							fprevVal =RESET;
							return ReturnObj();
						}
						if(fprevVal == RESET)
						{
							fprevVal = value;
							if(value == ZeroVoltage)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Maximum Voltage value for channel %s Zero volt", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageMax(voltageChnl, ZeroVoltage_MaxVal/2, ZeroVoltage_MaxVal/2);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
							else
							{	
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Maximum Voltage value %s on channel %s ", String.valueOf(mAVoltage),voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageMax(voltageChnl, (int)mAVoltage, (int)tolerancemV);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
						}
						else if( value != fprevVal )
						{	
							if(value == ZeroVoltage)
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Maximum Voltage value for channel %s equals %.2f mA with tolerance %.2f", voltageChnl.toString(), (float)mAVoltage, (float)fTolerance);
								exu.modTS().objVoltageSense().objMaxVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								maximumVoltageReached.getModEventId(),
								EDGE,
								ZeroVoltage_MaxVal/2,
								ZeroVoltage_MaxVal/2,
								registerTime,
								registerTimeTolerance
								,1
								);
							}
							else
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Maximum Voltage value for channel %s equals %.2f mA with tolerance %.2f", voltageChnl.toString(), (float)mAVoltage, (float)fTolerance);
								exu.modTS().objVoltageSense().objMaxVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								maximumVoltageReached.getModEventId(),
								EDGE,
								mAVoltage,
								tolerancemV,
								registerTime,
								registerTimeTolerance
								,1
								);
							}
							fprevVal = value;
						}
						else if(value == fprevVal) 
						{
							if(value == ZeroVoltage)
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Maximum Voltage value for channel %s equals %.2f mA with tolerance %.2f", voltageChnl.toString(), (float)mAVoltage, (float)fTolerance);
								exu.modTS().objVoltageSense().objMaxVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								maximumVoltageReached.getModEventId(),
								LEVEL,
								ZeroVoltage_MaxVal/2,
								ZeroVoltage_MaxVal/2,
								registerTime,
								registerTimeTolerance
								,1
								);
							}
							else
							{
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.comment("Assert Maximum Voltage value for channel %s equals %.2f mA with tolerance %.2f", voltageChnl.toString(), (float)mAVoltage, (float)fTolerance);
								exu.modTS().objVoltageSense().objMaxVoltage(voltageChnl.ordinal()).afcCheckEventBasedSignals(
								maximumVoltageReached.getModEventId(),
								LEVEL,
								mAVoltage,
								tolerancemV,
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
							if(value == ZeroVoltage)
							{
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Maximum Voltage value for channel %s Zero volt", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageMax(voltageChnl, ZeroVoltage_MaxVal/2, ZeroVoltage_MaxVal/2);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
							else
							{	
								Request_pauseInToOutDelay(registerTime);
								exu.comment("Start measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstartVoltageAcquistion(voltageChnl);
								exu.pause(15);
								exu.comment("Assert Maximum Voltage value %s on channel %s ", String.valueOf(mAVoltage),voltageChnl.toString());
								exu.modTS().objVoltageSense().afcassertVoltageMax(voltageChnl, (int)mAVoltage, (int)tolerancemV);
								exu.comment("Stop measuring Voltage on a channel %s", voltageChnl.toString());
								exu.modTS().objVoltageSense().afcstopVoltageAcquistion(voltageChnl);
								exu.modTS().objVoltageSense().afcresetMeaurments();
							}
						}
					break;
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
