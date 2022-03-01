package libs.TestingPlatform.CastleCommlayer;

import castle.util.Assert;
import config.ETS;
import config.ItfDAC.EnmDacChnls;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
public class CastleDacOutputPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	EnmDacChnls fChannelId;
	DACVoltageUnit fVoltageUnit;
	ETS exu;
	
		/**
		 * Unit of Voltage to be Generated.
		 */
		public enum DACVoltageUnit {
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
	
	private int getVoltagemV(double voltage, DACVoltageUnit unit) {
		double scale = 1;

		if (unit == DACVoltageUnit.V) {
			scale = 1000.0;
		} else if (unit == DACVoltageUnit.mV) {
			scale = 1.0;
		} else if (unit == DACVoltageUnit.uV) {
			scale = 1 / 1000.0;
		}

		double voltageMilli = voltage * scale;
		int voltageMilliInt = (int) Math.round(voltageMilli);

		return voltageMilliInt;
	}
	/**
	 * 
	 * @param channelId
	 * @param name
	 */
	public CastleDacOutputPort(EnmDacChnls channelId, DACVoltageUnit voltageUnit, ETS executionUnit){
		fChannelId = channelId;
		fVoltageUnit= voltageUnit;
		exu = executionUnit;
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args){
		double volt = (double)args[0];
		if(volt > 0)
		{	
			int mVvoltage = getVoltagemV(volt, fVoltageUnit);
		
		if (mVvoltage > 12000 || mVvoltage < 0) {
			Assert.fail("setDacChannelVolt: The requested DAC voltage is out of the acceptable range");
		}
		exu.comment("Set DAC channel %s output to %s ", fChannelId.toString(), mVvoltage);
		exu.modTS().objDAC().afcsetVoltage(mVvoltage, fChannelId);			
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