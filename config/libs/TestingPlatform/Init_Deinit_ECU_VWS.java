package libs.TestingPlatform;

import config.ETS;
//import prj.cte.LinNetwork3;
public class Init_Deinit_ECU_VWS {
	//TODO add all Initializations and Deinitializations for ECU and it's prefered to use Exu instead of C5 as All channels definitions not supported by C5.
	
	/******************** * STD VTP Tests Init function * ************************/
/*	public static void Init_ECU(ETS exu) {
		//TODO add your implementation for Init Function
		exu.modTS().objLinMaster().afcConfigureBaudRate(9600);
		exu.pause(300);
		exu.modTS().objLinMaster().afcSetStartSchedulingDelay(200);
				exu.pause(300);
		
		exu.modTS().objLinMaster().afcStartScheduling(false);		
				exu.pause(300);
		//LinNetwork3.Table_WiperMotorModule_Mode_L6.activate();
		LinNetwork3.Table_WiperMotorModule_Mode_L6.activate();
			exu.pause(300);		
				exu.modTS().objLinMaster().afcSetStartSchedulingDelay(200);
				exu.pause(300);
				exu.modTS().objLinMaster().afcStartScheduling(true);
		
				
				
				exu.pause(1000);
			exu.modTS().objLinMaster().afcEventNoSlaveDataConfig(false);
			exu.pause(1000);
			
		
	} */

	/****************** * STD VTP Tests Deinit function * ************************/
	public static void Deinit_ECU(ETS exu) {
		//TODO add your implementation for Deinit Function
		
	}
}
