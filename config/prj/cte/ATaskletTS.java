package prj.cte;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ITasklet;
import config.ETS;

public abstract class ATaskletTS implements ITasklet {

	private ETS exu;
	private String name;

	public ATaskletTS(String name) {
		this.name = name;
	}

	@Override
	public String getName() {
		return name;
	}

	@Override
	public ETS exu() {
		return exu;
	}

	@Override
	public void init() {
	}

	@Override
	public void internalSetExu(IExu exu) {
		this.exu = (ETS) exu;
	}

}
