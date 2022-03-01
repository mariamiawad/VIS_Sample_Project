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
@TestCaseKind("")

@RunContextHil
public class tc01 extends AMainTaskTS {

	@Override
	public void task() {
		// TODO Auto-generated method - Add your test here
		// exu.modTS().objCanDiag().afcSend("AA B");
		C5.pause(100);
	}
}
