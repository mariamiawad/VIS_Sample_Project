package tf00.tg00;

import castle.testenv.base.script.anno.RunContextHil;
import castle.testenv.base.anno.testcase.*;
import libs.c5.interfaces.C5;
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
public class tc02 extends AMainTaskTS {

	@Override
	public void task() {
		// TODO Auto-generated method - Add your test here
		for(int i = 0 ; i < 10 ; i++)
		{
			C5.pause(1000);
			exu.modTS().objDInput().objDigitalInput(0).afcGet();
		}
	}
}
