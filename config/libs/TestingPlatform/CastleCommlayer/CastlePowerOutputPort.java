package libs.TestingPlatform.CastleCommlayer;

import java.util.Arrays;

import castle.util.Assert;
import config.ETS;
import config.ItfPowerControl.EnmPowerInputChannel;
import config.ItfPowerControl.EnmPowerSource;
import config.ItfPowerSupplyControl.EnmPowerSupply;
import config.ItfPowerSupplyControl.EnmPowerSupplyOutput;

/**
 * @author mnagah
 * @version 1.0
 * @created 28-Jan-2018 1:53:46 PM
 */
public class CastlePowerOutputPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	EnmPowerInputChannel fChannelId;
	PowerSupplyID fSupplyID;
	EnmPowerSource fsupply;
	double fCurrentLimit;
	ETS exu;
		
		/**
		 * ID of power supply to control <br>
		 * By default two power supplies can be controlled by castle.
		 */
		public enum PowerSupplyID {
			/**
			 * Power supply 1
			 * <p>
			 * Here are configurations for the supply itself:<br/>
			 * Address: 1<br/>
			 * Protocol: RS232 <br/>
			 * Baud rate: 9600 bps <br/>
			 */
			S1,
			/**
			 * Power supply 2
			 * <p>
			 * Here are configurations for the supply itself:<br/>
			 * Address: 2<br/>
			 * Protocol: RS485 <br/>
			 * Baud rate: 9600 bps <br/>
			 */
			S2
		}
		
		/**
		 * Power supply state.
		 */
		public enum PowerSupplyState {
			On, Off,
		}
		
	private EnmPowerSupply getChnl(PowerSupplyID chnl) {

		int index = Arrays.asList(PowerSupplyID.values()).indexOf(chnl);

		return EnmPowerSupply.values()[index];
	}

	private EnmPowerSupplyOutput getState(PowerSupplyState state) {

		int index = Arrays.asList(PowerSupplyState.values()).indexOf(state);

		return EnmPowerSupplyOutput.values()[index];
	}
	
	private int getScaledVolt(double Volt) {
	CastlePowerSupplyLib obj = new CastlePowerSupplyLib(exu);
		if ((new Double(Volt)).intValue() > obj.getMaxVolt()) {
			Assert.fail("The input voltage \"%.3f\" Volt is larger than the "
					+ "maximum voltage that can be provided by supply", Volt);
		}
		else if ((new Double(Volt)).intValue() < 0) {
			Assert.fail("The input voltage \"%.3f\" Volt is Negative!"
					+ " can't be applied !", Volt);
		}

		Double d = new Double(Volt * 100);
		int intVolt = d.intValue();
		return intVolt;
	}
	
	private int getScaledCurrent(double currentAmpere) {
	CastlePowerSupplyLib obj = new CastlePowerSupplyLib(exu);
		if (currentAmpere > obj.getMaxCurrent()) {
			Assert.fail("The requeste current \"%.3f\" A is larger than the"
					+ "maximum current that can be provided by supply",
					currentAmpere);
		}
		else if (currentAmpere < 0) {
			Assert.fail("The requeste current \"%.3f\" A is Negative!"
					+ " can't be applied !", currentAmpere);
		}

		Double d = new Double(currentAmpere * 1000);
		int intCurr = d.intValue();

		return intCurr;
	}
	/**
	 * PowerOutput, 10 ms tolerance should be considered in the test design so in case of the inputOutputTime is 200ms in requirements 
	 * so it should be 210 ms in test case <br>
	 * In case of using Supply Channel Directly without Castle Power Inputs, pass null to channelId argument
	 * 
	 * @param channelId
	 * @param name
	 * @param PoweSupplyChannel
	 * @param powerSupplyID
	 */
	public CastlePowerOutputPort(EnmPowerInputChannel channelId, PowerSupplyID PoweSupplyChannel, EnmPowerSource powerSupplyID, double currentLimit, ETS executionUnit){
		fChannelId = channelId;
		fSupplyID= PoweSupplyChannel;
		fsupply = powerSupplyID;
		fCurrentLimit = currentLimit;
		exu =executionUnit; 
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args){
	double Volt;
	if(args[0] instanceof String)
	{
		Volt=Double.parseDouble(args[0].toString());
	}
	else
	{
	    Volt = (double)args[0];
	}
	
	int intCurr = getScaledCurrent(fCurrentLimit);
	int intVolt = getScaledVolt(Volt);
		
		if(fChannelId == null)
		{
			exu.comment("Select Power Supply Channel %s to be controlled by following RS232 commands",
					fSupplyID.toString());
			EnmPowerSupply enuChnl = getChnl(fSupplyID);
			exu.modTS().objPowerSupplyControl().afcSelectPowerSupply(enuChnl);
			exu.pause(10);
			exu.comment("Set maximum output current drawn from the supply channel to %.2f",
					fCurrentLimit);
			exu.modTS().objPowerSupplyControl().afcSetSupplyCurrent(intCurr);
			exu.pause(10);
			EnmPowerSupplyOutput state = getState(PowerSupplyState.On);
			exu.comment("Turn %s power supply output", state.toString());
			exu.modTS().objPowerSupplyControl().afcSetPowerSupplyOutput(state);
			exu.pause(10);
			exu.comment("Set output volt for power supply channel to %.2f V", Volt);
			exu.modTS().objPowerSupplyControl().afcSetSupplyVoltage(intVolt);
		}
		else
		{
			if(Volt > 0)
			{	
				exu.comment("Select Power Supply Channel %s to be controlled by following RS232 commands",
						fSupplyID.toString());
				EnmPowerSupply enuChnl = getChnl(fSupplyID);
				exu.modTS().objPowerSupplyControl().afcSelectPowerSupply(enuChnl);
				exu.pause(10);
				exu.comment("Set maximum output current drawn from the supply channel to %.2f",
						fCurrentLimit);
				exu.modTS().objPowerSupplyControl().afcSetSupplyCurrent(intCurr);
				exu.pause(10);
				EnmPowerSupplyOutput state = getState(PowerSupplyState.On);
				exu.comment("Turn %s power supply output", state.toString());
				exu.modTS().objPowerSupplyControl().afcSetPowerSupplyOutput(state);
				exu.pause(10);
				exu.modTS().objPowerControl().afcConnectInputPowerChannel(fChannelId,
					fsupply);
				exu.pause(10);
				exu.comment("Set output volt for power supply channel to %.2f V", Volt);
				exu.modTS().objPowerSupplyControl().afcSetSupplyVoltage(intVolt);
			}
			else
			{
				exu.modTS().objPowerControl().afcConnectInputPowerChannel(fChannelId,
				EnmPowerSource.Open_Circuit);
			}
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