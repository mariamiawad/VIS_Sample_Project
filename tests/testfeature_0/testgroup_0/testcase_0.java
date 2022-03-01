package testfeature_0.testgroup_0;

import castle.testenv.base.script.anno.RunContextHil;
import castle.util.ConsoleOut;
import castle.testenv.base.anno.testcase.*;
import libs.c5.interfaces.C5;
import libs.c5.interfaces.C5.PowerSupply.SupplyID;
import libs.c5.interfaces.C5.PowerSupply.SupplyState;
import prj.cte.AMainTaskTS;

@TestCaseObjective("")
@TestCaseVersion("")
@TestCaseRequirements({})
@TestCaseMantis("")
@TestCaseAuthor("")
@TestCaseTestBench("")
@TestCaseDefectSeverity("")
@TestCaseASIL("")
@TestCaseSequence()
@TestCaseImpacted(false)
@TestCaseRegression(false)

@RunContextHil
public class testcase_0 extends AMainTaskTS {

	@Override
	public void task() {
		ConsoleOut.println("testcase_0.task()"); 
		C5.PowerSupply.turnOnPowerSupply1();
		C5.PowerSupply.selectChannel(SupplyID.S1);
		C5.PowerSupply.setOutput(SupplyState.On);
		C5.pause(1000);
		C5.PowerSupply.setVoltage(13.5f);
		C5.PowerSupply.setChannelCurrentLimit(5.0f);
		ConsoleOut.println("testcase_0.task()"); 
		ConsoleOut.println("testcase_0.task(1)"); 
		ConsoleOut.println("testcase_0.task(2)"); 
		ConsoleOut.println("testcase_0.task(3)"); 
		ConsoleOut.println("testcase_0.task(4)"); 
		ConsoleOut.println("testcase_0.task(5)"); 
		ConsoleOut.println("testcase_0.task()"); 
	}
}
