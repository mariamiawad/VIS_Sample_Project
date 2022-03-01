package prj.cte;

import java.util.Collection;
import java.util.Collections;
import castle.testenv.base.config.IExu;
import castle.testenv.base.script.IMainTask;
import castle.testenv.base.script.ITasklet;
import config.ETS;
import libs.c5.interfaces.C5;

public abstract class AMainTaskTS implements IMainTask {

	protected ETS exu;
	protected C5 c5;

	@Override
	public ETS exu() {
		return exu;
	}

	@Override
	public final void internalSetExu(IExu exu) {
		this.exu = (ETS) exu;
	}

	@Override
	public void init() {
		c5 = new C5(exu);
	}

	@Override
	public Collection<ITasklet> getTasklets() {
		return Collections.emptyList();
	}

}
