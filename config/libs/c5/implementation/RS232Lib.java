package libs.c5.implementation;

import java.util.Locale;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import config.ETS;
import config.Itf_SignalValue;

/**
 * This class is standard library APIs to be used in RS232 communications.
 *
 * <p>
 * C5 Bench has to RS232 lines; RS232_0 and RS232_1. The first one is -by
 * default- used to control remote power supply. <br>
 * Accordingly, the tester shall use the second line RS232_1 when communicating
 * with the ECU.
 * 
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class RS232Lib implements ILib {

	/** Execution Unit corresponding to this library instance */
	ETS exu;
//	ItfRs232 rs232;

	public RS232Lib(IExu exu) {
		this.exu = (ETS) exu;

//		this.rs232 = this.exu.modTS().objBaseIo().objRs232(1);
	}

	/**
	 * Set the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @param exu
	 *            instance of execution unit
	 */
	public void setExu(IExu exu) {
		this.exu = (ETS) exu;
	}

	/**
	 * Get the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @return used execution unit instance for voltage object
	 */
	public ETS exu() {
		return exu;
	}

//	public void setBaudRate(Enme_baudrate _Baudrate) {

//		this.rs232.afcConfigure(_Baudrate, true);

//	}

	public void assertMsg(int offset, String msg) {

		String hex = asciiToHex(String.format(Locale.US, msg));

//		this.rs232.afcTestByteSequence(offset, hex);

	}

	public void logMsg() {
//		this.rs232.afcLogResponseString();
	}

	public void resetRxBuffer() {
//		this.rs232.afcResetReceiverBuffer();
	}
	
	public void platformResetSignals(){
		exu.modTS().objPlatformProtocol().afcresetSignals();
	}

	public void send(String msg) {

		String hex = asciiToHex(String.format(Locale.US, msg));

//		rs232.afcSendString(false, hex);
	}

	public String asciiToHex(String ascii) {
		String hex = "";
		String s;
		for (int i = 0; i < ascii.length(); i++) {
			if (i < ascii.length() - 1) {
				s = String.format("%x ", (byte) (ascii.charAt(i)));
			} else {
				s = String.format("%x", (byte) (ascii.charAt(i)));
			}
			hex = hex + s;
		}
		return hex;
	}

	public Itf_SignalValue data() {
		return exu.modTS().objPlatformProtocol().objData();
	}

	public Itf_SignalValue type() {
		return exu.modTS().objPlatformProtocol().objData();
	}

	public void platformLogEnable(boolean enable) {
		if (enable)
			exu.modTS().objPlatformProtocol().afclogEnable();
		else
			exu.modTS().objPlatformProtocol().afclogDisable();
	}

}
