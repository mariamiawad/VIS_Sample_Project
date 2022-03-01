package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import config.ETS;
import config.ItfDI;
import config.ItfPWMOutput.EnmPwmOutChannel;
import libs.c5.implementation.UtilitiesLib.Rational;
import libs.c5.interfaces.C5.PwmOutput.PWMGenChnl;
import libs.c5.interfaces.C5.PwmOutput.PwmOutFrequencyUnit;

/**
 * This class is implementation of standard library APIs to be used in
 * controlling PWM output pins.
 * <p>
 * A PWM output is by nature a Digital port, it can be either set to PWM or
 * digital output. This class must not be used directly by testers (only
 * firmware team).
 * <p>
 */
public class DifferentialUARTLib implements ILib {

	ETS exu;
	/** digital input object to be used as for direct FW APIs access */
	ItfDI DIObj;

	/**
	 * /** Class Constructors
	 **/
	public DifferentialUARTLib() {
		this.exu = (ETS) exu;
		this.DIObj = this.exu.modTS().objDInput();
	}

	public DifferentialUARTLib(IExu exu) {
		this.exu = (ETS) exu;
		this.DIObj = this.exu.modTS().objDInput();
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
	 * @return used execution unit instance for current object
	 */
	public ETS exu() {
		return exu;
	}

	private ItfDI getObj() {
		return this.DIObj;
	}
	
	/**
	 * This functions Initializes UART-CAN (CANTP) Module and disables CAN Network 1.
	 * 
	 * 
	 * @category Firmware Action
	 **/

	public void Init() {
		exu.modTS().objcanTP().afcInit();
	}
	
	/**
	 * This functions Disables UART-CAN (CANTP) Module and enables CAN Network 1.
	 * 
	 * 
	 * @category Firmware Action
	 **/

	public void DeInit() {
		exu.modTS().objcanTP().afcDeInit();
	}
	
	/**
	 * This functions Starts UART-CAN Receive Buffer data Acquisition. All data on the bus will be captured.
	 * 
	 * 
	 * @category Firmware Action
	 **/

	public void StartDataAcquisition() {
		exu.modTS().objcanTP().afcStartDataAcquisition();
	}
	
	/**
	 * This functions Stops UART-CAN Receive Buffer data Acquisition. No data on the bus will be captured.
	 * 
	 * 
	 * @category Firmware Action
	 **/

	public void StopDataAcquisition() {
		exu.modTS().objcanTP().afcStopDataAcquisition();
	}
	
	/**
	 * This functions clears UART-CAN Receive Buffer
	 **/

	public void ResetRxBuffer() {
		exu.modTS().objcanTP().afcResetRxBuffer();
	}

	/**
	 * Send data on the CAN bus as raw frame without any headers -only raw frame but with CAN physical layer
	 *  (differential)-. This call is by passing the normal signal processing
	 * 
	 * @category Firmware Action
	 * @param frame
	 *            frame data to send on can bus.
	 **/

	public void TxOnlyRawFrame(String frame) {
		exu.modTS().objcanTP().afcTxOnlyRawFrame(frame);
	}

	/**
	 * This functions compares the frame received in the buffer with the frame
	 * passed to it
	 * 
	 * 
	 * @category Firmware Action
	 * @param frame
	 *            frame data to send on can bus.
	 **/

	public void AssertSequence(String frame) {
		exu.modTS().objcanTP().afcAssertSequence(frame);
	}
}
