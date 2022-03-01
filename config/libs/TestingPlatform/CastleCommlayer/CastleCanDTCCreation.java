package libs.TestingPlatform.CastleCommlayer;
import config.ETS;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.FAILURE_CREATION;
//import prj.cte.CAN;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
 
public class CastleCanDTCCreation implements ICastlePort{
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	String space = " ";
	String valueS = "";
	double valueD = 0;
	
	public CastleCanDTCCreation (ETS executionUnit, FAILURE_CREATION Create)
	{
		exu = executionUnit;
	}
	
	private void createDefect(String valueS2)
	{
		switch (valueS2)
		{
			case "PEPS":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_PEPS_Message_Sts.getFrameObject().afcSendPerTimerOff();
			break;
			
			case "BCM_LGT":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_BCM_LightChimeReq.getFrameObject().afcSendPerTimerOff();
			break;
						
			case "BCM":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_BCM_RLSState.getFrameObject().afcSendPerTimerOff();
			break;	
					
			case "EMS":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_EMS_EngineRPM.getFrameObject().afcSendPerTimerOff();
			break;	
					
			case "ESC":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_ESC_Status.getFrameObject().afcSendPerTimerOff();
			break;	
					
			case "FCS":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_FCS_ADBMsg.getFrameObject().afcSendPerTimerOff();
			break;
						
			case "IPK":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_IPK_TotalOdometer.getFrameObject().afcSendPerTimerOff();
			break;
						
			case "MMI":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_MMI_Amap_Msg.getFrameObject().afcSendPerTimerOff();
			break;
						
			case "MMI_DSCU":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_MMI_DSCU_Command.getFrameObject().afcSendPerTimerOff();
			break;	
					
			case "SAS":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_SAS_Status.getFrameObject().afcSendPerTimerOff();
			break;
						
			case "TCU":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_TCU_Status.getFrameObject().afcSendPerTimerOff();
			break;
			
			case "TCM":
			exu.comment("Create timeout failure on Frame %s", valueS2);
			//CAN.Tx_TCM_IntegrationSwtCtrl.getFrameObject().afcSendPerTimerOff();
			break;
			/********************/
			case "REMOVE_PEPS":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_PEPS_Message_Sts.getFrameObject().afcSendPerTimer(20);
			break;
			
			case "REMOVE_BCM_LGT":
			exu.comment("Remove timeout failure on Frame %s", valueS2);			
			//CAN.Tx_BCM_LightChimeReq.getFrameObject().afcSendPerTimer(50);
			break;
						
			case "REMOVE_BCM":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_BCM_RLSState.getFrameObject().afcSendPerTimer(100);
			break;	
					
			case "REMOVE_EMS":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_EMS_EngineRPM.getFrameObject().afcSendPerTimer(10);
			break;	
					
			case "REMOVE_ESC":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_ESC_Status.getFrameObject().afcSendPerTimer(20);
			break;	
					
			case "REMOVE_FCS":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_FCS_ADBMsg.getFrameObject().afcSendPerTimer(10);
			break;
						
			case "REMOVE_IPK":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_IPK_TotalOdometer.getFrameObject().afcSendPerTimer(1000);
			break;
						
			case "REMOVE_MMI":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_MMI_Amap_Msg.getFrameObject().afcSendPerTimer(100);
			break;
						
			case "REMOVE_MMI_DSCU":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_MMI_DSCU_Command.getFrameObject().afcSendPerTimer(100);
			break;	
					
			case "REMOVE_SAS":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_SAS_Status.getFrameObject().afcSendPerTimer(10);
			break;
						
			case "REMOVE_TCU":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_TCU_Status.getFrameObject().afcSendPerTimer(20);			
			break;
			
			case "REMOVE_TCM":
			exu.comment("Remove timeout failure on Frame %s", valueS2);
			//CAN.Tx_TCM_IntegrationSwtCtrl.getFrameObject().afcSendPerTimer(100);
			break;	
		}
	}
	//TODO
	private void createDefect(double valueD2) 
	{
		if(valueD2 == 1)
		{
			/*create failure*/
		}
		else
		{
			/*remove failure*/
		}
		
	}
	
	@Override
	public Object[] apply(Object...args)
	{
		if(args[0] instanceof String)
		{
			valueS = args[0].toString();
			createDefect(valueS);
		}
		else
		{
			valueD = (double)args[0];
			createDefect(valueD);
		}
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}

	
}
