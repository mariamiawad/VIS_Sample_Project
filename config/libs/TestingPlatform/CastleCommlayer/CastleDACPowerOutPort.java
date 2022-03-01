package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfDAC.EnmDacChnls;
import config.ItfPowerControl.EnmPowerInputChannel;
import config.ItfPowerControl.EnmPowerSource;
import libs.TestingPlatform.CastleCommlayer.CastlePowerOutputPort.PowerSupplyID;
import libs.TestingPlatform.CastleCommlayer.CastlePowerSupplyLib.PowerSupplyType;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
public class CastleDACPowerOutPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	EnmPowerInputChannel fChannelId;
	PowerSupplyID fSupplyID = PowerSupplyID.S1;
	EnmPowerSource fsupply = EnmPowerSource.PowerSupply1_DC;
	EnmDacChnls powerSupplyExternalControl;
	PowerSupplyType fSupplyType;
	ETS exu;

	/**
	 * 
	 * @param channelId
	 * @param name
	 * @param PoweSupplyChannel
	 * @param powerSupplyID
	 * @param ExternalControlChnl
	 */
	public CastleDACPowerOutPort(EnmPowerInputChannel channelId, PowerSupplyID PoweSupplyChannel, EnmPowerSource powerSupplyID, EnmDacChnls ExternalControlChnl, PowerSupplyType supplyType ,ETS executionUnit){
		fChannelId = channelId;
		fSupplyID= PoweSupplyChannel;
		fsupply = powerSupplyID;
		powerSupplyExternalControl=ExternalControlChnl;
		fSupplyType = supplyType;
		exu = executionUnit;
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args){
		double outputVal = (double)args[0];
		int mVvoltage = 0;
		if(fSupplyType == PowerSupplyType.TOELLNER2020)
		{
			mVvoltage = (int)(outputVal*1000.0/4.0);
		}
		if(fSupplyType == PowerSupplyType.TOELLNER4010)
		{
			mVvoltage = (int)(outputVal*1000.0/8.0);
		}
		if(fSupplyType == PowerSupplyType.ZUP2020)
		{
			mVvoltage = (int)(outputVal*1000.0/4.0);
		}
		if(outputVal > 0){
			exu.comment("Set DAC channel %s output to %s", powerSupplyExternalControl.toString(), mVvoltage);
			exu.modTS().objDAC().afcsetVoltage(mVvoltage, powerSupplyExternalControl);	
			exu.modTS().objPowerControl().afcConnectInputPowerChannel(fChannelId,
				fsupply);
		}
		else
		{
			exu.comment("Set DAC channel %s output to %s", powerSupplyExternalControl.toString(), 0);
			exu.modTS().objDAC().afcsetVoltage(0, powerSupplyExternalControl);	
			exu.modTS().objPowerControl().afcConnectInputPowerChannel(fChannelId,
				fsupply);
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