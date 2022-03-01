package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import castle.util.Assert;
import config.ETS;
import config.ItfDAC;
import config.ItfDAC.EnmDacChnls;
import config.ItfPowerSupplyControl;
import config.ItfPowerSupplyControl.EnmPowerSupply;
import config.ItfPowerSupplyControl.EnmPowerSupplyOutput;
import libs.c5.interfaces.C5.PowerSupply.SupplyID;
import libs.c5.interfaces.C5.PowerSupply.SupplyState;
import libs.c5.interfaces.C5.PowerSupply.SupplyType;

/**
 * This class is implementation of standard library APIs to be used in
 * controlling power supply.
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class PowerSupplyLib implements ILib {
	/**
	 * Class Constants
	 * */
	/** Scaled used for sending a voltage */
	private final int VOLT_SCALE = 100;
	/** Scaled used for sending a current */
	private final int CURRENT_SCALE = 1000;
	/** Default max volt */
	private final int DEFUALT_MAX_VOLT = 40;
	/** Default max current (A) */
	private final int DEFUALT_MAX_CURRENT = 20;
	/** Max rated volt for ZUP2020 */
	private final int ZUP2020_MAX_VOLT = 20;
	/** Max rated current for ZUP2020 */
	private final int ZUP2020_MAX_CURRENT = 20;
	/** Max rated volt for tollener4010 */
	private final int TOELLNER4010_MAX_VOLT = 40;
	/** Max rated current tollener4010 */
	private final int TOELLNER4010_MAX_CURRENT = 10;
	/** Max rated volt for tollener2020 */
	private final int TOELLNER2020_MAX_VOLT = 20;
	/** Max rated current tollener2020 */
	private final int TOELLNER2020_MAX_CURRENT = 20;

	/**
	 * Class Members
	 **/
	private double maxVolt; /* <Unit Volt */
	private double maxCurrent; /* <Unit A */
	static private ItfDAC psDacObj;
	static private ItfPowerSupplyControl psObj; /*
	 * Power Supply object for
	 * direct FW
	 */
	static ETS exu; /* Execution unit used */

	/**
	 * Class Constructors
	 **/
	public PowerSupplyLib() {
		PowerSupplyLib.psObj = this.exu().modTS().objPowerSupplyControl();
		PowerSupplyLib.psDacObj = this.exu().modTS().objDAC();
		initSupplyParameters();
	}

	public PowerSupplyLib(IExu exu) {
		initSupplyParameters();
		PowerSupplyLib.exu = (ETS) exu;
		PowerSupplyLib.psObj = this.exu().modTS().objPowerSupplyControl();
		PowerSupplyLib.psDacObj = this.exu().modTS().objDAC();
	}

	/**
	 * Public Methods
	 **/

	/**
	 * Get the power supply object for the main PIM (modTS).
	 * 
	 * <p>
	 * The direct access to the module object instead of using the library APIs
	 * enables performing custom commands.
	 * 
	 * @category Preprocessor
	 * @return psObj Instance from ItfPowerSupplyControl to be used for direct
	 *         access to firmware APIs instead of the library implementation.
	 */
	public ItfPowerSupplyControl getObj() {
		return PowerSupplyLib.psObj;
	}



	/**
	 * Get the maximum voltage that can be provided by power supply used now.
	 *
	 * <p>
	 * The maximum value is dependent on the type of the supply connected, You
	 * must set the used power supply type using the API {@link#setSupplyType
	 * "setSupplyType"} before invoking this API.
	 * 
	 * @category Preprocessor
	 * @param Supp
	 *            Voltage value in volts.
	 * @return maxVolt Maximum volt for selected supply.
	 * @see {@link#setSupplyType "setSupplyType"}
	 */
	public double getMaxVolt() {
		return this.maxVolt;
	}

	/**
	 * Get the maximum current(A) that can be provided by power supply used now.
	 *
	 * <p>
	 * The maximum value is dependent on the type of the supply connected, You
	 * must set the used power supply type using the API {@link#setSupplyType
	 * "setSupplyType"} before invoking this API.
	 *
	 * @category Preprocessor
	 * @param Supp
	 *            current value in milli ampere.
	 * @return maxCurrent Maximum current for selected supply in Ampere.
	 * @see {@link#setSupplyType "setSupplyType"}
	 */
	public double getMaxCurrent() {
		return this.maxCurrent;
	}

	/**
	 * Set the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @param exu
	 *            instance of execution unit
	 */
	public void setExu(IExu exu) {
		PowerSupplyLib.exu = (ETS) exu;
	}

	/**
	 * Get the execution unit to be used for an instance from this library.
	 * 
	 * @category Preprocessor
	 * @return used execution unit instance for current object
	 */
	public ETS exu() {
		return PowerSupplyLib.exu;
	}

	/**
	 * Set Power Supply output voltage.
	 * <P>
	 * Timing: Execution of this API takes around 10 msec.
	 * <P>
	 * Warning: Please Pause at least 10 ms after requesting this command
	 *
	 * @category Firmware Action
	 * @param Volt
	 *            Voltage value in volts
	 * @throw RuntimeException if required voltage value is greater than the
	 *        maximum value that can be provided by the supply.
	 * @see {@link #getSupplyMaxVolt getSupplyMaxVolt"}
	 **/
	public void setChannelVolt(double Volt) {

		int intVolt = getScaledVolt(Volt);

		psObj.afcSetSupplyVoltage(intVolt);
	}
	
	/**
	 * Set Power Supply output voltage by DAC External Control
	 * <P>
	 * Timing: Execution of this API takes around 40 usec.
	 * <P>
	 * Warning:- Please Enable External Control setExternalControl() First
	 *         - Please Makesure to Select the Tolner Supply Type setSupplyType()
	 *
	 * @category Firmware Action
	 * @param Channel
	 *            Channel to Be Controlled
	 * @param Volt
	 *            Voltage value in volts
	 * @throw RuntimeException if required voltage value is greater than the
	 *        maximum value that can be provided by the supply.
	 * @see {@link #getSupplyMaxVolt getSupplyMaxVolt"}
	 **/
	public void setChannelVoltExt(SupplyID Channel, double Volt) {

		// Select proper DAC channel 
		EnmDacChnls dacChannel = EnmDacChnls.DAC_Ch_15;
		if (Channel.equals(SupplyID.S2)){dacChannel = EnmDacChnls.DAC_Ch_16;}
		
		int voltage =(int) (1000 * (Volt * 5.0) / getMaxVolt());
		
		psDacObj.afcsetVoltage(voltage, dacChannel);
	}

	/**
	 * Select Power Supply Channel to Control.
	 * <P>
	 * Timing: Execution of this API takes around 10 msec.
	 * <P>
	 * Warning: Please Pause at least 10 ms after requesting this command
	 *
	 * @category Firmware Action
	 * @param Chnl
	 *            ID of channel to be used
	 **/
	public void selectPwrSuppChannel(SupplyID Chnl) {

		EnmPowerSupply enuChnl = getChnl(Chnl);

		psObj.afcSelectPowerSupply(enuChnl);
	}

	/**
	 * Set type of power supply used.
	 *
	 * <p>
	 * This API doesn't affect the operation between castle and the supply. The
	 * only effect is in the supply capabilities, e.g. a ZUP supply can provide
	 * only 21 volt but Toellner supply can provide up to 40 volt.
	 * <P>
	 * You can get maximum voltage and current value for this type of supply
	 * using the API {@link #getSupplyMaxVolt "getSupplyMaxVolt"}.
	 * 
	 * @category Preprocessor
	 * @param Supp
	 *            Voltage value in volts
	 */
	public void setSupplyType(SupplyType Supp) {
		if (Supp.equals(SupplyType.ZUP2020)) {
			this.maxVolt = ZUP2020_MAX_VOLT;
			this.maxCurrent = ZUP2020_MAX_CURRENT;
		} else if (Supp.equals(SupplyType.TOELLNER4010)) {
			this.maxVolt = TOELLNER4010_MAX_VOLT;
			this.maxCurrent = TOELLNER4010_MAX_CURRENT;
		} else if (Supp.equals(SupplyType.TOELLNER2020)) {
			this.maxVolt = TOELLNER2020_MAX_VOLT;
			this.maxCurrent = TOELLNER2020_MAX_CURRENT;
		} else {
			this.maxVolt = DEFUALT_MAX_VOLT;
			this.maxCurrent = DEFUALT_MAX_CURRENT;
		}

	}

	

	/**
	 * Set maximum output current drawn from the supply channel.
	 * <P>
	 * The required current must be less than the maximum current that can be
	 * provided by the supply itself. Use the method {@link #getSupplyMaxCurr
	 * "getSupplyMaxCurr"} to get the maximum value supported by your supply.
	 *
	 * <P>
	 * Timing: Execution of this API takes around 10 msec.
	 * <P>
	 * Warning: Please Pause at least 10 ms after requesting this command
	 *
	 * @category Firmware Action
	 * @param Current
	 *            value in Ampere.
	 * @throw RuntimeException if required current value is greater than the
	 *        maximum value that can be provided by the supply.
	 * @see {@link #getMaxCurrent "getMaxCurrent"}
	 **/
	public void setChannelCurrentLimit(double currentAmpere) {

		int intCurr = getScaledCurrent(currentAmpere);

		this.getObj().afcSetSupplyCurrent(intCurr);
	}



	/**
	 * Switch on/off the supply output for the assigned channels/power supplies.
	 *
	 * @category Firmware Action
	 * @param state
	 *            New output state (on/off)
	 * @see {@link prj.Specific_Tests.Library_Tests.PS.SwitchingTest#task
	 *      Example for setChannelOutput API}
	 **/
	public void setChannelOutput(SupplyState enuState) {
		
		EnmPowerSupplyOutput state = getState(enuState);

		this.getObj().afcSetPowerSupplyOutput(state);
	}

	/**
	 * Switch on/off the supply external mode.
	 *
	 * @category Firmware Action
	 * @param state
	 *            New external state (on/off)
	 * @see {@link prj.Specific_Tests.Library_Tests.PS.SwitchingTest#task
	 *      Example for setChannelOutput API}
	 **/
	public void setExternalMode(SupplyID Channel, SupplyState enuState) {
		
		selectPwrSuppChannel(Channel);
		EnmPowerSupplyOutput state = getState(enuState);
		this.getObj().afcSetPowerSupplyExternalMode(state);
	}




	/**
	 * Private Methods
	 **/
	private void initSupplyParameters() {
		this.maxVolt = DEFUALT_MAX_VOLT;
		this.maxCurrent = DEFUALT_MAX_CURRENT;
	}

	/**
	 * Convert current from A to mA and check range. Throw exception if out of
	 * range.
	 **/
	private int getScaledCurrent(double currentAmpere) {
		if (currentAmpere > this.getMaxCurrent()) {
			Assert.fail("The requeste current \"%.3f\" A is larger than the"
					+ "maximum current that can be provided by supply",
					currentAmpere);
		}

		Double d = new Double(currentAmpere * CURRENT_SCALE);
		int intCurr = d.intValue();

		return intCurr;
	}

	/**
	 * Convert voltage from v to proper scale for firmware and check range.
	 * Throw exception if out of range voltage requested.
	 **/
	private int getScaledVolt(double Volt) {
		if ((new Double(Volt)).intValue() > this.getMaxVolt()) {
			Assert.fail("The input voltage \"%.3f\" Volt is larger than the "
					+ "maximum voltage that can be provided by supply", Volt);
		}

		Double d = new Double(Volt * VOLT_SCALE);
		int intVolt = d.intValue();
		return intVolt;
	}
	
		

	/* TODO :Power Supply Self Test() */

	/**
	 * Map power supply logical ID to physical ID in the firmware.
	 * */
	private EnmPowerSupply getChnl(SupplyID chnl) {

		int index = Arrays.asList(SupplyID.values()).indexOf(chnl);

		return EnmPowerSupply.values()[index];
	}

	private EnmPowerSupplyOutput getState(SupplyState state) {

		int index = Arrays.asList(SupplyState.values()).indexOf(state);

		return EnmPowerSupplyOutput.values()[index];
	}

}

//
