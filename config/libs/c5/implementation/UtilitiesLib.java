package libs.c5.implementation;

import castle.testenv.base.config.IExu;
import config.ETS;

public class UtilitiesLib {

	private ETS exu;

	public UtilitiesLib(IExu exu) {
		this.exu = (ETS) exu;

	}

	public void pauseMilliSec(double timeMs) {
		this.exu.pause(timeMs);
	}

	public double convertToMili(int integerUnint) {
		return integerUnint / 1000;
	}

	public int convertToKilo(double fractionUnint) {
		return ((int) (fractionUnint * 1000));
	}

	public static class Rational {
		private long num;
		private long denom;
		private final int digitsDec = 5;

		public Rational(double d) {

			if (d % 1 == 0) {
				int num = (int) Math.round(d);
				this.setNum(num);
				this.setDenom(1);

				return;
			}

			//String s = String.valueOf(d);

			int denom = 1;

			for (int i = 0; i < digitsDec; i++) {
				d *= 10;
				denom *= 10;
			}
			int num = (int) Math.round(d);

			this.setNum(num);
			this.setDenom(denom);
		}

		public int getNum() {
			return (int) num;
		}

		private void setNum(int num) {
			this.num = num;
		}

		public int getDenom() {
			return (int) denom;
		}

		private void setDenom(int denom) {
			this.denom = denom;
		}
	}
}
