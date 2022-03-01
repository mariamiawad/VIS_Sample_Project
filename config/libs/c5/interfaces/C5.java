package libs.c5.interfaces;

import castle.testenv.base.config.IEvent;
import castle.testenv.base.config.IExu;
import castle.util.Assert;
import config.ETS;
import config.Itf_SignalValue;
import libs.c5.implementation.CurrentMeasurementLib;
import libs.c5.implementation.DACLib;
import libs.c5.implementation.DefectCellLib;
import libs.c5.implementation.DifferentialUARTLib;
import libs.c5.implementation.DigitalInputLib;
import libs.c5.implementation.DigitalOutputLib;
import libs.c5.implementation.MotorMeasurementLib;
import libs.c5.implementation.PWMInputLib;
import libs.c5.implementation.PWMOutputLib;
import libs.c5.implementation.PowerInputsControlLib;
import libs.c5.implementation.PowerSupplyLib;
import libs.c5.implementation.RS232Lib;
import libs.c5.implementation.UtilitiesLib;
import libs.c5.implementation.VoltageMeasurementLib;
import libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels;
import libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue;
import libs.c5.interfaces.C5.PowerSupply.SupplyState;
import libs.c5.interfaces.C5.Util.EventType;

/**
 * Castle 5 testing library to facilitate controlling the bench and its test
 * programming.
 * 
 * @version 1.0
 */
public class C5 {

	private static PowerInputsControlLib powerInputs;
	private static PowerSupplyLib powerSupply;
	private static DACLib dac;
	private static DigitalOutputLib digOutput;
	private static DigitalInputLib digInput;
	private static PWMOutputLib pwmOutput;
	private static PWMInputLib pwmInput;
	private static DefectCellLib defectCell;
	private static CurrentMeasurementLib currentMeasurement;
	private static VoltageMeasurementLib voltageMeasurement;
	private static UtilitiesLib utilities;
	private static RS232Lib rs232;
	private static MotorMeasurementLib motors;
	private static DifferentialUARTLib differentialUART;

	private static SupplyState supply1State = SupplyState.Off;
	private static SupplyState supply2State = SupplyState.Off;

	private static double pausedTime = 0;
	private static boolean dynamicPauseEnable = true;

	private static IExu exu;

	public C5(IExu exu) {
		C5.exu = (ETS) exu;
		powerSupply = new PowerSupplyLib(C5.exu);
		powerInputs = new PowerInputsControlLib(C5.exu);
		dac = new DACLib(C5.exu);
		digOutput = new DigitalOutputLib(C5.exu);
		digInput = new DigitalInputLib(C5.exu);
		pwmOutput = new PWMOutputLib(C5.exu);
		pwmInput = new PWMInputLib(C5.exu);
		currentMeasurement = new CurrentMeasurementLib(C5.exu);
		utilities = new UtilitiesLib(C5.exu);
		defectCell = new DefectCellLib(C5.exu);
		voltageMeasurement = new VoltageMeasurementLib(C5.exu);
		rs232 = new RS232Lib(C5.exu);
		motors = new MotorMeasurementLib(C5.exu);
		differentialUART =  new DifferentialUARTLib(C5.exu);
	}

	/**
	 * This class is interface of standard library APIs to be used in
	 * controlling power supply.
	 * 
	 * @version 1.0
	 */
	public static class PowerSupply {

		/**
		 * Value of power supply in nominal case.
		 */
		final static double SUPPLY_NOMINAL = 13.5;

		/** Type of power supplies that can be used */
		public enum SupplyType {
			/** ZUP2020: Max Power is 20V 20A */
			ZUP2020,
			/** TOELLNER4010: Max Power is 40V 10A */
			TOELLNER4010,
			/** TOELLNER4010: Max Power is 20V 20A */
			TOELLNER2020
		}

		/**
		 * ID of power supply to control <br>
		 * By default two power supplies can be controlled by castle.
		 */
		public enum SupplyID {
			/**
			 * Power supply 1
			 * <p>
			 * Here are configurations for the supply itself:<br/>
			 * Address: 1<br/>
			 * Protocol: RS232 <br/>
			 * Baud rate: 9600 bps <br/>
			 */
			S1,
			/**
			 * Power supply 2
			 * <p>
			 * Here are configurations for the supply itself:<br/>
			 * Address: 2<br/>
			 * Protocol: RS485 <br/>
			 * Baud rate: 9600 bps <br/>
			 */
			S2
		}

		/**
		 * Power supply state.
		 */
		public enum SupplyState {
			On, Off,
		}

		private static SupplyID selectedChannel;

		/**
		 * Get the maximum voltage that can be provided by power supply used
		 * now.
		 * <p>
		 * The maximum value is dependent on the type of the supply connected,
		 * You must set the used power supply type using the API
		 * {@link PowerSupply #setSupplyType setSupplyType} before invoking this
		 * API.
		 * 
		 * @category Preprocessor
		 * @param Supp
		 *            Voltage value in volts.
		 * @return maxVolt Maximum volt for selected supply.
		 * @see {@link PowerSupply #setSupplyType setSupplyType}
		 */
		public static double getMaxVolt() {
			return C5.powerSupply.getMaxVolt();
		}

		/**
		 * Get the maximum current(A) that can be provided by power supply used
		 * now.
		 *
		 * <p>
		 * The maximum value is dependent on the type of the supply
		 * connected,You must set the used power supply type using the API
		 * {@link PowerSupply #setSupplyType setSupplyType} before invoking this
		 * API.
		 *
		 * @category Preprocessor
		 * @param Supp
		 *            current value in milli ampere.
		 * @return maxCurrent Maximum current for selected supply in Ampere.
		 * @see {@link PowerSupply #setSupplyType setSupplyType}
		 */
		public static double getMaxCurrent() {
			return C5.powerSupply.getMaxCurrent();
		}

		/**
		 * Select Power Supply Channel.
		 * <P>
		 * Before Configuring the Power Supply Channel you need to call this API
		 * to select the channel you will configure
		 * <P>
		 * Timing: Execution of this API takes around 50 msec.
		 * <P>
		 * Warning: At least pause 50 msec after calling this API.
		 *
		 * @category Firmware Action
		 * @param Chnl
		 *            Power Supply Channel Index.
		 * @see {@link libs.c5.examples.library.powersupply.SwitchingAllChnlsTest #TaskExample}
		 **/
		public static void selectChannel(SupplyID Chnl, String comment, Object... args) {

			selectedChannel = Chnl;

			Util.commentNxtFunctionCall(comment, args);

			C5.powerSupply.selectPwrSuppChannel(Chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * Select Power Supply Channel.
		 * <P>
		 * Before Configuring the Power Supply Channel you need to call this API
		 * to select the channel you will configure
		 * <P>
		 * Timing: Execution of this API takes around 50 msec.
		 * <P>
		 * Warning: At least pause 50 msec after calling this API.
		 *
		 * @category Firmware Action
		 * @param Chnl
		 *            Power Supply Channel Index.
		 * @see {@link libs.c5.examples.library.powersupply.SwitchingAllChnlsTest #TaskExample}
		 **/
		public static void selectChannel(SupplyID Chnl) {
			selectChannel(Chnl, "Select Power Supply Channel %s to be controlled by following RS232 commands",
					Chnl.toString());
		}

		/**
		 * Set output volt for power supply channel.
		 * <P>
		 * The required voltage must be less than the maximum voltage that can
		 * be provided by the supply itself. Use the method
		 * {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt} to get the
		 * maximum value supported by your supply.
		 * <P>
		 * Timing: Execution of this API takes around 50 msec.
		 *
		 * @category Firmware Action
		 * @param Volt
		 *            Voltage value in volts
		 * @throw RuntimeException if required voltage value is greater than the
		 *        maximum value that can be provided by the supply.
		 * @see {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}
		 * @see {@link libs.c5.examples.library.powersupply.SetVoltAllChnl #TaskExample}
		 **/
		public static void setVoltage(double Volt, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.powerSupply.setChannelVolt(Volt);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set output volt for power supply channel.
		 * <P>
		 * The required voltage must be less than the maximum voltage that can
		 * be provided by the supply itself. Use the method
		 * {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt} to get the
		 * maximum value supported by your supply.
		 * <P>
		 * Timing: Execution of this API takes around 50 msec.
		 *
		 * @category Firmware Action
		 * @param Volt
		 *            Voltage value in volts
		 * @throw RuntimeException if required voltage value is greater than the
		 *        maximum value that can be provided by the supply.
		 * @see {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}
		 * @see {@link libs.c5.examples.library.powersupply.SetVoltAllChnl #TaskExample}
		 **/
		public static void setVoltage(double Volt) {
			setVoltage(Volt, "Set output volt for power supply channel to %.2f", Volt);
		}

		/**
		 * Set output volt for power supply channel.
		 * <P>
		 * The required voltage must be less than the maximum voltage that can
		 * be provided by the supply itself. Use the method
		 * {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt} to get the
		 * maximum value supported by your supply.
		 * <P>
		 * Timing: Execution of this API takes around 50 msec.
		 *
		 * @category Firmware Action
		 * @param Volt
		 *            Voltage value in volts
		 * @throw RuntimeException if required voltage value is greater than the
		 *        maximum value that can be provided by the supply.
		 * @see {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}
		 * @see {@link libs.c5.examples.library.powersupply.SetVoltAllChnl #TaskExample}
		 **/
		public static void setVoltageExt(SupplyID Channel,double Volt, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.powerSupply.setChannelVoltExt(Channel, Volt);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set output volt for power supply channel.
		 * <P>
		 * The required voltage must be less than the maximum voltage that can
		 * be provided by the supply itself. Use the method
		 * {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt} to get the
		 * maximum value supported by your supply.
		 * <P>
		 * Timing: Execution of this API takes around 50 msec.
		 *
		 * @category Firmware Action
		 * @param Volt
		 *            Voltage value in volts
		 * @throw RuntimeException if required voltage value is greater than the
		 *        maximum value that can be provided by the supply.
		 * @see {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}
		 * @see {@link libs.c5.examples.library.powersupply.SetVoltAllChnl #TaskExample}
		 **/
		public static void setVoltageExt(SupplyID Channel,double Volt) {
			setVoltageExt(Channel,Volt, "Set output volt for power supply channel to %.2f", Volt);
		}

		/**
		 * Set type of power supply used.
		 *
		 * <p>
		 * This API doesn't affect the operation between castle and the supply.
		 * The only effect is in the supply capabilities, e.g. a ZUP supply can
		 * provide only 21 volt but Toellner supply can provide up to 40 volt.
		 * <P>
		 * You can get maximum voltage and current value for this type of supply
		 * using the API {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}.
		 * 
		 * @category Preprocessor
		 * @param Supp
		 *            Voltage value in volts
		 * @see {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}
		 * @see {@link libs.c5.examples.library.powersupply.SetVoltChnl #TaskExample}
		 */
		public static void setSupplyType(SupplyType Supp, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.powerSupply.setSupplyType(Supp);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set type of power supply used.
		 *
		 * <p>
		 * This API doesn't affect the operation between castle and the supply.
		 * The only effect is in the supply capabilities, e.g. a ZUP supply can
		 * provide only 21 volt but Toellner supply can provide up to 40 volt.
		 * <P>
		 * You can get maximum voltage and current value for this type of supply
		 * using the API {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}.
		 * 
		 * @category Preprocessor
		 * @param Supp
		 *            Voltage value in volts
		 * @see {@link PowerSupply #getSupplyMaxVolt getSupplyMaxVolt}
		 * @see {@link libs.c5.examples.library.powersupply.SetVoltChnl #TaskExample}
		 */
		public static void setSupplyType(SupplyType Supp) {
			setSupplyType(Supp, " Set type of power connected to the bench to %s", Supp.toString());
		}

		/**
		 * Set maximum output current drawn from the supply channel.
		 * <P>
		 * The required current must be less than the maximum current that can
		 * be provided by the supply itself. Use the method
		 * {@link PowerSupply #getSupplyMaxCurr getSupplyMaxCurr} to get the
		 * maximum value supported by your supply.
		 *
		 * @category Firmware Action
		 * @param Current
		 *            value in Ampere.
		 * @throw RuntimeException if required current value is greater than the
		 *        maximum value that can be provided by the supply.
		 * @see {@link prj.Specific_Tests.Library_Tests.PS.SetCurrentChnl#task
		 * Example
		 * @see {@link PowerSupply #getMaxCurrent "getMaxCurrent"}
		 * @see {@link libs.c5.examples.library.powersupply.SetCurrentAllChnls #TaskExample}
		 **/
		public static void setChannelCurrentLimit(double currentAmpere, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.powerSupply.setChannelCurrentLimit(currentAmpere);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set maximum output current drawn from the supply channel.
		 * <P>
		 * The required current must be less than the maximum current that can
		 * be provided by the supply itself. Use the method
		 * {@link PowerSupply #getSupplyMaxCurr getSupplyMaxCurr} to get the
		 * maximum value supported by your supply.
		 *
		 * @category Firmware Action
		 * @param Current
		 *            value in Ampere.
		 * @throw RuntimeException if required current value is greater than the
		 *        maximum value that can be provided by the supply.
		 * @see {@link prj.Specific_Tests.Library_Tests.PS.SetCurrentChnl#task
		 * Example
		 * @see {@link PowerSupply #getMaxCurrent "getMaxCurrent"}
		 * @see {@link libs.c5.examples.library.powersupply.SetCurrentAllChnls #TaskExample}
		 **/
		public static void setChannelCurrentLimit(double currentAmpere) {
			setChannelCurrentLimit(currentAmpere, "Set maximum output current drawn from the supply channel to %.2f",
					currentAmpere);
		}

		/**
		 * Switch on/off the supply output for the assigned channels/power
		 * supplies.
		 *
		 * @category Firmware Action
		 * @param state
		 *            New output state (on/off)
		 * @see {@link libs.c5.examples.library.powerinputs#task Example Example
		 *      for setChannelOutput API}
		 * @see {@link libs.c5.examples.library.powersupply.SwitchingAllChnlsTest #TaskExample}
		 **/
		public static void setOutput(SupplyState state, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			if (selectedChannel != null) {
				switch (selectedChannel) {
				case S1:
					supply1State = state;
					break;
				case S2:
					supply2State = state;
					break;
				default:
					break;
				}
			}

			C5.powerSupply.setChannelOutput(state);

			C5.Util.adddefaultPause();
		}

		/**
		 * Switch on/off the supply output for the assigned channels/power
		 * supplies.
		 *
		 * @category Firmware Action
		 * @param state
		 *            New output state (on/off)
		 * @see {@link libs.c5.examples.library.powerinputs#task Example Example
		 *      for setChannelOutput API}
		 * @see {@link libs.c5.examples.library.powersupply.SwitchingAllChnlsTest #TaskExample}
		 **/
		public static void setOutput(SupplyState state) {
			setOutput(state, "Turn %s power supply output", state.toString());
		}


		/**
		 * Switch on/off the supply External Mode for the assigned channels/power
		 * supplies.
		 *
		 * @category Firmware Action
		 * @param state
		 *            New output state (on/off)
		 * @see {@link libs.c5.examples.library.powerinputs#task Example Example
		 *      for setChannelOutput API}
		 * @see {@link libs.c5.examples.library.powersupply.SwitchingAllChnlsTest #TaskExample}
		 **/
		public static void setExt(SupplyID Channel, SupplyState state, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.powerSupply.setExternalMode(Channel, state);

			C5.Util.adddefaultPause();
		}

		/**
		 * Switch on/off the supply External Mode for Channel
		 * supplies.
		 *
		 * @category Firmware Action
		 * @param state
		 *            New output state (on/off)
		 * @see {@link libs.c5.examples.library.powerinputs#task Example Example
		 *      for setChannelOutput API}
		 * @see {@link libs.c5.examples.library.powersupply.SwitchingAllChnlsTest #TaskExample}
		 **/
		public static void setExt(SupplyID Channel,SupplyState state) {
			setExt(Channel,state, "Turn %s power supply External Mode", state.toString());
		}

		/**
		 * 
		 * Select power supply 2 channel and then turn it off.
		 * <p>
		 * 
		 * Note that this function has an execution time in the range of 45 msec
		 * and the response of the supply can't be used for real time operations
		 * because the time needed to change the supply voltage is not
		 * deterministic.
		 */
		public static void turnOffPowerSupply2() {
			C5.PowerSupply.selectChannel(SupplyID.S1, "Select Power Supply1");

			C5.pause(15);

			C5.PowerSupply.setVoltage(SUPPLY_NOMINAL, "Configure Supply1 voltage to 13.5 Volt");

			C5.pause(15);

			C5.PowerSupply.setOutput(SupplyState.Off, "Turn off power supply 1");

			C5.pause(15);

			C5.Util.adddefaultPause();
		}

		/**
		 * 
		 * Select power supply 1 channel and then turn it off.
		 * <p>
		 * 
		 * Note that this function has an execution time in the range of 45 msec
		 * and the response of the supply can't be used for real time operations
		 * because the time needed to change the supply voltage is not
		 * deterministic.
		 */
		public static void turnOffPowerSupply1() {
			C5.PowerSupply.selectChannel(SupplyID.S1, "Select Power Supply1");

			C5.pause(15);

			C5.PowerSupply.setVoltage(SUPPLY_NOMINAL, "Configure Supply1 voltage to 13.5 Volt");

			C5.pause(15);

			C5.PowerSupply.setOutput(SupplyState.Off, "Turn off power supply 1");

			C5.pause(15);

			C5.Util.adddefaultPause();
		}

		/**
		 * 
		 * Select power supply 1 channel and init it to nominal voltage then
		 * turn it on.
		 * <p>
		 * 
		 * Note that this function has an execution time in the range of 45 msec
		 * and the response of the supply can't be used for real time operations
		 * because the time needed to change the supply voltage is not
		 * deterministic.
		 */
		public static void turnOnPowerSupply1() {
			C5.PowerSupply.selectChannel(SupplyID.S1, "Select Power Supply1");

			C5.pause(15);

			C5.PowerSupply.setVoltage(SUPPLY_NOMINAL, "Configure Supply1 voltage to 13.5 Volt");

			C5.pause(15);

			C5.PowerSupply.setOutput(SupplyState.On, "Turn on power supply 1");

			C5.pause(15);

			C5.Util.adddefaultPause();
		}

		/**
		 * 
		 * Select power supply 2 channel and init it to nominal voltage then
		 * turn it on.
		 * <p>
		 * 
		 * Note that this function has an execution time in the range of 45 msec
		 * and the response of the supply can't be used for real time operations
		 * because the time needed to change the supply voltage is not
		 * deterministic.
		 */
		public static void turnOnPowerSupply2() {
			C5.PowerSupply.selectChannel(SupplyID.S2, "Select Power Supply2");

			C5.pause(15);

			C5.PowerSupply.setVoltage(SUPPLY_NOMINAL, "Configure Supply2 voltage to 13.5 Volt");

			C5.pause(15);

			C5.PowerSupply.setOutput(SupplyState.On, "Turn on power supply 2");

			C5.pause(15);

			C5.Util.adddefaultPause();
		}

	}

	/**
	 * This class is standard library APIs to be used in controlling inputs used
	 * for powering the ECU.
	 *
	 * <p>
	 * Any of the power inputs can either be connected to constant power supply
	 * , variable power supply or open circuit. Also this library can be used to
	 * create power PWM signal by modulating the use input supply (constant or
	 * variable).
	 *
	 * 
	 * @version 1.0
	 */
	public static class PowerInputs {

		/***
		 * Input power channels controlled by relays.
		 */
		public enum PowerInput {
			/** Power Input Channel 1 */
			Chnl01,
			/** Power Input Channel 2 */
			Chnl02,
			/** Power Input Channel 3 */
			Chnl03,
			/** Power Input Channel 4 */
			Chnl04,
			/** Power Input Channel 5 */
			Chnl05,
			/** Power Input Channel 4 */
			Chnl06,
			/** Power Input Channel 5 */
			Chnl07,
		}

		/***
		 * State of input power channels controlled by relays.
		 */
		public enum PowerInputState {
			/** Power Input Channel To DC Supply Channel 1 */
			PowerSupply1,
			/** Power Input Channel To DC Supply Channel 2 */
			PowerSupply2,
			/** Power Input Channel To PWM Supply Channel 1 */
			PWM_PowerSupply1,
			/** Power Input Channel To PWM Supply Channel 2 */
			PWM_PowerSupply2,
			/** Power Input Channel To Open Circuit State */
			Open_Circuit,
		}

		/**
		 * Connect the selected channel to the desired power supply source.
		 * 
		 * <p>
		 * The physical connection is done between the desired channel found on
		 * the extension board from the connectors PWR1 to the connector PWR7.
		 * Accordingly, the tester shall connect the power supply channel that
		 * shall be used for nominal operation to the (CH1) connector. So, the
		 * naming "connect to DC_PWR1" is a logical connection.
		 * 
		 * @param enuChnl
		 *            Power Input Channel Index
		 * @param enuState
		 *            Power Input state [(DC-Ch1)(DC-Ch2)(PWM-Ch1)(PWM-Ch2)(OC)]
		 * 
		 * @category Firmware Action
		 * @see {@link prj.Specific_Tests.Library_Tests.Power_Inputs.SimpleExample #task
		 *      Example
		 */
		public static void connect(PowerInput chnl, PowerInputState channelMode, String comment, Object... args) {

			switch (channelMode) {
			case Open_Circuit:
				break;
			case PWM_PowerSupply1:
			case PowerSupply1:
				if (supply1State != SupplyState.On)
					Assert.fail("Power supply # 1 is not switched on !");
				break;
			case PWM_PowerSupply2:
			case PowerSupply2:
				if (supply2State != SupplyState.On)
					Assert.fail("Power supply # 2 is not switched on !");
				break;
			default:
				break;

			}

			Util.commentNxtFunctionCall(comment, args);

			powerInputs.setPowerInputChannelMode(chnl, channelMode);

			C5.Util.adddefaultPause();
		}

		/**
		 * Connect the selected channel to the desired power supply source.
		 * 
		 * <p>
		 * The physical connection is done between the desired channel found on
		 * the extension board from the connectors PWR1 to the connector PWR7.
		 * Accordingly, the tester shall connect the power supply channel that
		 * shall be used for nominal operation to the (CH1) connector. So, the
		 * naming "connect to DC_PWR1" is a logical connection.
		 * 
		 * @param enuChnl
		 *            Power Input Channel Index
		 * @param enuState
		 *            Power Input state [(DC-Ch1)(DC-Ch2)(PWM-Ch1)(PWM-Ch2)(OC)]
		 * 
		 * @category Firmware Action
		 * @see {@link prj.Specific_Tests.Library_Tests.Power_Inputs.SimpleExample #task
		 *      Example
		 */
		public static void connect(PowerInput chnl, PowerInputState channelMode) {
			connect(chnl, channelMode, "Connect power channel %s to %s.", chnl.toString(), channelMode.toString());
		}

		/**
		 * Generate PWM on power channel.
		 * 
		 * <p>
		 * Use the {@link c5.tests.library.powerinputs.connect} API to connect
		 * the power channel to the generated PWM
		 * {@link c5.tests.library.powerinputs.PowerInputState.PWM_PowerSupply1}
		 * or
		 * {@link c5.tests.library.powerinputs.PowerInputState.PWM_PowerSupply2}
		 * .
		 * 
		 * @param chnl
		 *            ID of channel to connect to.
		 * @see {@link libs.c5.examples.library.powerinputs.VarSupplyAllChnls #task
		 *      Example}
		 * @category Firmware Action
		 */
		public static void setPwmPowerInputChannelMode(PowerInput chnl, PowerInputState channelMode, double frequencyHz,
				double dutyCyclePercent, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			powerInputs.setPwmPowerInputChannelMode(chnl, channelMode, frequencyHz, dutyCyclePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Generate PWM on power channel.
		 * 
		 * <p>
		 * Use the {@link c5.tests.library.powerinputs.connect} API to connect
		 * the power channel to the generated PWM
		 * {@link c5.tests.library.powerinputs.PowerInputState.PWM_PowerSupply1}
		 * or
		 * {@link c5.tests.library.powerinputs.PowerInputState.PWM_PowerSupply2}
		 * .
		 * 
		 * @param chnl
		 *            ID of channel to connect to.
		 * @see {@link libs.c5.examples.library.powerinputs.VarSupplyAllChnls #task
		 *      Example}
		 * @category Firmware Action
		 */
		public static void setPwmPowerInputChannelMode(PowerInput chnl, PowerInputState channelMode, double frequencyHz,
				double dutyCyclePercent) {
			setPwmPowerInputChannelMode(chnl, channelMode, frequencyHz, dutyCyclePercent,
					"Generate PWM on power channel %s of value %.2f Hz", chnl.toString(), frequencyHz);
		}
	}

	/**
	 * This class is standard library APIs to be used in controlling DACs.
	 *
	 * <p>
	 * PIP V1 board has 16 DAC channel; 8 channels can generate voltage from 0
	 * to 15 volt and the other eight can only generate voltage from zero to 5
	 * volt.
	 *
	 * 
	 * @version 1.0
	 */
	public static class DAC {

		/**
		 * Logical ID of DAC channels with there range and location on the EPIP
		 * board. Note all DAC channels exist on the connector P32.
		 */
		public enum DacChnl {
			/**
			 * <p>
			 * DAC Channel 1 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 1 <br/>
			 * * P19 pin 1 <br/>
			 */
			Chnl01,
			/**
			 * <p>
			 * DAC Channel 2 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 21 <br/>
			 * * P19 pin 2 <br/>
			 */
			Chnl02,
			/**
			 * <p>
			 * DAC Channel 3 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 3 <br/>
			 * * P19 pin 3 <br/>
			 */
			Chnl03,
			/**
			 * <p>
			 * DAC Channel 4 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 4 <br/>
			 * * P19 pin 4 <br/>
			 */
			Chnl04,
			/**
			 * <p>
			 * DAC Channel 5 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 5 <br/>
			 * * P19 pin 5 <br/>
			 */
			Chnl05,
			/**
			 * <p>
			 * DAC Channel 6 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 6 <br/>
			 * * P19 pin 6 <br/>
			 */
			Chnl06,
			/**
			 * <p>
			 * DAC Channel 7 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 7 <br/>
			 * * P19 pin 7 <br/>
			 */
			Chnl07,
			/**
			 * <p>
			 * DAC Channel 8 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 8 <br/>
			 * * P19 pin 8 <br/>
			 */
			Chnl08,
			/**
			 * <p>
			 * DAC Channel 9 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 9 <br/>
			 * * P19 pin 9 <br/>
			 */
			Chnl09,
			/**
			 * <p>
			 * DAC Channel 10 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 10 <br/>
			 * * P19 pin 10 <br/>
			 */
			Chnl10,
			/**
			 * <p>
			 * DAC Channel 11 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 11 <br/>
			 * * P20 pin 1 <br/>
			 */
			Chnl11,
			/**
			 * <p>
			 * DAC Channel 12 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 12 <br/>
			 * * P20 pin 2 <br/>
			 */
			Chnl12,
			/**
			 * <p>
			 * DAC Channel 13 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 13 <br/>
			 * * P20 pin 3 <br/>
			 */
			Chnl13,
			/**
			 * <p>
			 * DAC Channel 14 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 14 <br/>
			 * * P20 pin 4 <br/>
			 */
			Chnl14,
			/**
			 * <p>
			 * DAC Channel 15 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 15 <br/>
			 * * P20 pin 5 <br/>
			 */
			Chnl15,
			/**
			 * <p>
			 * DAC Channel 16 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 16 <br/>
			 * * P20 pin 6 <br/>
			 */
			Chnl16
		}

		/**
		 * Logical ID of DAC channels with there range and location on the EPIP
		 * board. Note all DAC channels exist on the connector P32.
		 */
		public enum MuxDacChannels {
			/**
			 * <p>
			 * DAC Channel 13 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 13 [P20 pin 3] <br/>
			 * * Real Sensor 13 [P20 pin 7]<br/>
			 */
			Mux_Chnl13,
			/**
			 * <p>
			 * DAC Channel 14 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * Connection : <br/>
			 * * Product Analog Input 14 [P20 pin 4] <br/>
			 * * Real Sensor 14 [P20 pin 8]<br/>
			 */
			Mux_Chnl14,
			/**
			 * <p>
			 * DAC Channel 15 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 15 [P20 pin 5] <br/>
			 * * Real Sensor 15 [P20 pin 9]<br/>
			 */
			Mux_Chnl15,
			/**
			 * <p>
			 * DAC Channel 16 Specifications: <br/>
			 * Maximum Output Voltage : 12 Volt <br/>
			 * Connection : <br/>
			 * * Product Analog Input 16 [P20 pin 6] <br/>
			 * * Real Sensor 16 [P20 pin 10]<br/>
			 */
			Mux_Chnl16
		}

		/**
		 * Logical ID of DAC cha/nnels with there range and location on the EPIP
		 * board. Note all DAC channels exist on the connector P32.
		 */
		public enum MuxOut {
			/** DAC Channel 1, maximum output is 15 volt - P32 Pin 18 */
			DAC,
			/** DAC Channel 2, maximum output is 15 volt - P32 Pin 17 */
			Real,
		}

		/**
		 * Unit of Voltage to be Generated.
		 */
		public enum DacVoltageUnit {
			/**
			 * Volt
			 */
			V,
			/**
			 * Milli Volt
			 */
			mV,
			/**
			 * Micro Volt
			 */
			uV
		}

		/**
		 * Set one DAC channel output to the desired value in volt. e.g.
		 * setChnlMilliVolt(DACChnls.Chnl01, 1.5).
		 * 
		 * <p>
		 * Set the output of a channel to the desired value.Note that PIP V2
		 * board has 16 DAC channel can generate voltage from 0 to 12 volt
		 * 
		 * @param chnl
		 *            ID of channel to set its output.
		 * @param volt
		 *            Output value in volt e.g. 1.75 volt.
		 * @param unit
		 *            The unit of the output value.
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DAC#getMaxRangeChnlVolt Get maximum
		 *      output for a channel.}
		 * @see {@link libs.c5.interfaces.C5.DAC#setChnlMilliVolt Set channel in
		 *      milli volt}
		 * @see {@link libs.c5.interfaces.C5.DAC.DacVoltageUnit}
		 */
		public static void setMilliVolt(DacChnl chnl, double voltInMiliVolt, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.dac.setDacChannelVolt(chnl, voltInMiliVolt, DacVoltageUnit.mV);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set one DAC channel output to the desired value in volt. e.g.
		 * setChnlMilliVolt(DACChnls.Chnl01, 1.5).
		 * 
		 * <p>
		 * Set the output of a channel to the desired value.Note that PIP V2
		 * board has 16 DAC channel can generate voltage from 0 to 12 volt
		 * 
		 * @param chnl
		 *            ID of channel to set its output.
		 * @param volt
		 *            Output value in volt e.g. 1.75 volt.
		 * @param unit
		 *            The unit of the output value.
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DAC#getMaxRangeChnlVolt Get maximum
		 *      output for a channel.}
		 * @see {@link libs.c5.interfaces.C5.DAC#setChnlMilliVolt Set channel in
		 *      milli volt}
		 * @see {@link libs.c5.interfaces.C5.DAC.DacVoltageUnit}
		 */
		public static void setMilliVolt(DacChnl chnl, double voltInMiliVolt) {
			setMilliVolt(chnl, voltInMiliVolt, "Set DAC channel %s output to %.2f", chnl.toString(), voltInMiliVolt);
		}

		/**
		 * Set one DAC channel output to the desired value in volt. e.g.
		 * setChannel(DACChnls.Chnl01, 1.5).
		 * 
		 * <p>
		 * Set the output of a channel to the desired value.Note that PIP V2
		 * board has 16 DAC channel can generate voltage from 0 to 12 volt
		 * 
		 * @param chnl
		 *            ID of channel to set its output.
		 * @param volt
		 *            Output value in volt e.g. 1.75 volt.
		 * @param unit
		 *            The unit of the output value.
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DAC#getMaxRangeChnlVolt Get maximum
		 *      output for a channel.}
		 * @see {@link libs.c5.interfaces.C5.DAC#setChnlMilliVolt Set channel in
		 *      milli volt}
		 * @see {@link libs.c5.interfaces.C5.DAC.DacVoltageUnit}
		 */
		public static void setChannel(DacChnl chnl, double voltInMiliVolt, DacVoltageUnit unit, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.dac.setDacChannelVolt(chnl, voltInMiliVolt, unit);
		}

		/**
		 * Set one DAC channel output to the desired value in volt. e.g.
		 * setChannel(DACChnls.Chnl01, 1.5).
		 * 
		 * <p>
		 * Set the output of a channel to the desired value.Note that PIP V2
		 * board has 16 DAC channel can generate voltage from 0 to 12 volt
		 * 
		 * @param chnl
		 *            ID of channel to set its output.
		 * @param volt
		 *            Output value in volt e.g. 1.75 volt.
		 * @param unit
		 *            The unit of the output value.
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DAC#getMaxRangeChnlVolt Get maximum
		 *      output for a channel.}
		 * @see {@link libs.c5.interfaces.C5.DAC#setChnlMilliVolt Set channel in
		 *      milli volt}
		 * @see {@link libs.c5.interfaces.C5.DAC.DacVoltageUnit}
		 */
		public static void setChannel(DacChnl chnl, double voltInMiliVolt, DacVoltageUnit unit) {
			setChannel(chnl, voltInMiliVolt, unit, "Set DAC channel %s output to %.2f %s", chnl.toString(),
					voltInMiliVolt, unit.toString());
		}

		/**
		 * Set one DAC channel output to the desired value in volt. e.g.
		 * setChnlMilliVolt(DACChnls.Chnl01, 1.5).
		 * 
		 * <p>
		 * Set the output of a channel to the desired value.Note that PIP V1
		 * board has 16 DAC channel; 8 channels can generate voltage from 0 to
		 * 15 volt and the other eight can only generate voltage from zero to 5
		 * volt.
		 * 
		 * @param chnl
		 *            ID of channel to set its output.
		 * @param volt
		 *            Output value in volt e.g. 1.75 volt.
		 * @category Firmware Action
		 * @see {@link STD_Libraries.Interface.DAC#getMaxRangeChnlVolt Get
		 * maximum output for a channel.
		 * @see {@link STD_Libraries.Interface.DAC#setChnlMilliVolt Set channel
		 *      in milli volt.
		 */
		public static void setMuxOut(MuxDacChannels chnl, MuxOut dacSource, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.dac.setDacPinSource(chnl, dacSource);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set one DAC channel output to the desired value in volt. e.g.
		 * setChnlMilliVolt(DACChnls.Chnl01, 1.5).
		 * 
		 * <p>
		 * Set the output of a channel to the desired value.Note that PIP V1
		 * board has 16 DAC channel; 8 channels can generate voltage from 0 to
		 * 15 volt and the other eight can only generate voltage from zero to 5
		 * volt.
		 * 
		 * @param chnl
		 *            ID of channel to set its output.
		 * @param volt
		 *            Output value in volt e.g. 1.75 volt.
		 * @category Firmware Action
		 * @see {@link STD_Libraries.Interface.DAC#getMaxRangeChnlVolt Get
		 * maximum output for a channel.
		 * @see {@link STD_Libraries.Interface.DAC#setChnlMilliVolt Set channel
		 *      in milli volt.
		 */
		public static void setMuxOut(MuxDacChannels chnl, MuxOut dacSource) {
			setMuxOut(chnl, dacSource, "Connect analog multiplexer %s to %s", chnl.toString(), dacSource.toString());

		}
	}

	/**
	 * This class is implementation of standard library APIs to be used in
	 * controlling digital output pins.
	 *
	 * 
	 * @version 1.0
	 */
	public static class DigitalOutput {

		/**
		 * Digital output logic values.
		 * <P>
		 * Note that PIP V1 supports changing the high logic to 3.3 or 12 volt
		 * but the value is output logic value is set to 5 volt by default. The
		 * tester shall not change the
		 */
		public enum DigitalOutputValue {
			/**
			 * <p>
			 * Logic Low
			 */
			Low,
			/**
			 * <p>
			 * Logic High
			 */
			High
		}

		/**
		 * Digital output logic values.
		 * <P>
		 * Note that PIP V2 supports changing the high logic to 3.3 or 5 volt
		 * but the value is output logic value is configured for the whole Port,
		 * So you configure the high logic for the two ports
		 */
		public enum DigitalOutputBanks {
			/**
			 * <p>
			 * Bank One Product Digital Input channels [1 - 6]
			 */
			Bank1,
			/**
			 * <p>
			 * Bank Two Bank One Product Digital Input channels [7 - 12]
			 */
			Bank2
		}

		/**
		 * Digital output logic values.
		 * <P>
		 * Note that PIP V2 supports changing the high logic to 3.3 or 5 volt
		 * but the value is output logic value is set to 5 volt by default.
		 */
		public enum HighLogicValue {
			/**
			 * <p>
			 * High logic is 3 Volt
			 */
			HighLogic_3Volt,
			/**
			 * <p>
			 * High logic is 5 Volt
			 */
			HighLogic_5Volt
		}

		/**
		 * Logical mapping of digital output ports that are used as DO not PWM.
		 * <p>
		 * There are 14 DO ports . In this library implementation, There are 9
		 * port Multiplixed for PWM and 5 port reserved for DO. The tester Can
		 * change the type of the port as long as using this standard library.
		 */
		public enum DigitalOutputChannels {
			/**
			 * <p>
			 * Digital Port 1 Connection : <br/>
			 * P8 Pin 03<br/>
			 * Product Digital Output Pin 1
			 */
			Port01,
			/**
			 * <p>
			 * Digital Port 2 Connection : <br/>
			 * P8 Pin 04<br/>
			 * Product Digital Output Pin 2
			 */
			Port02,
			/**
			 * <p>
			 * Digital Port 3 Connection : <br/>
			 * P8 Pin 05<br/>
			 * Product Digital Output Pin 3
			 */
			Port03,
			/**
			 * <p>
			 * Digital Port 4 Connection : <br/>
			 * P8 Pin 06<br/>
			 * Product Digital Output Pin 4
			 */
			Port04,
			/**
			 * <p>
			 * Digital Port 5 Connection : <br/>
			 * P8 Pin 07<br/>
			 * Product Digital Output Pin 5
			 */
			Port05,
			/**
			 * <p>
			 * Digital Port 6 Connection : <br/>
			 * P8 Pin 08<br/>
			 * Product Digital Output Pin 6
			 */
			Port06,
			/**
			 * <p>
			 * Digital Port 7 Connection : <br/>
			 * P8 Pin 09<br/>
			 * Product Digital Output Pin 7
			 */
			Port07,
			/**
			 * <p>
			 * Digital Port 8 Connection : <br/>
			 * P8 Pin 10<br/>
			 * Product Digital Output Pin 8
			 */
			Port08,
			/**
			 * <p>
			 * Digital Port 9 Connection : <br/>
			 * P12 Pin 01<br/>
			 * Product Digital Output Pin 9
			 */
			Port09,
			/**
			 * <p>
			 * Digital Port 10 Connection : <br/>
			 * P12 Pin 02<br/>
			 * Product Digital Output Pin 10
			 */
			Port10,
			/**
			 * <p>
			 * Digital Port 11 Connection : <br/>
			 * P12 Pin 03<br/>
			 * Product Digital Output Pin 11
			 */
			Port11,
			/**
			 * <p>
			 * Digital High Speed 5 Volt channel 4 Connection : <br/>
			 * P16 Pin 04<br/>
			 * Product Digital Output Pin 12
			 */
			Port12,
			/**
			 * <p>
			 * Digital High Speed 5 Volt channel 5 Connection : <br/>
			 * P16 Pin 05<br/>
			 * Product Digital Output Pin 3
			 */
			Port13,
			/**
			 * <p>
			 * Digital High Speed 5 Volt channel 6 Connection : <br/>
			 * P16 Pin 06<br/>
			 * Product Digital Output Pin 3
			 */
			Port14,

		}

		/**
		 * Set one digital output port to the desired value.
		 * 
		 * 
		 * @param port
		 *            ID of port to set its output. See
		 *            {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels
		 * Ports Enum
		 * @param digValue
		 *            Digital output value. See
		 *            {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue
		 * Digital output values enum
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels
		 * Ports Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue
		 *      Digital output values enum
		 **/
		public static void setDigitalOutputPin(DigitalOutputChannels port, DigitalOutputValue digValue, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			digOutput.setDigitalOutputPin(port, digValue);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set one digital output port to the desired value.
		 * 
		 * 
		 * @param port
		 *            ID of port to set its output. See
		 *            {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels
		 * Ports Enum
		 * @param digValue
		 *            Digital output value. See
		 *            {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue
		 * Digital output values enum
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels
		 * Ports Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue
		 *      Digital output values enum
		 **/
		public static void setDigitalOutputPin(DigitalOutputChannels port, DigitalOutputValue digValue) {
			setDigitalOutputPin(port, digValue, "Set %s digital output port to %s.", port.toString(),
					digValue.toString());
		}

		/**
		 * Set the high logic value of the specified bank.
		 * 
		 * 
		 * @param bankId
		 *            The Digital Output Bank to be Configured
		 * @param LogicValue
		 *            The High Logic Value [3.3 volt] or [5 volt]
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputBanks
		 * Banks Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.HighLogicValue Logic
		 *      High values enum
		 **/
		public static void setPortVolt(DigitalOutputBanks bankId, HighLogicValue LogicValue, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			digOutput.setPortVolt(bankId, LogicValue);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set the high logic value of the specified bank.
		 * 
		 * 
		 * @param bankId
		 *            The Digital Output Bank to be Configured
		 * @param LogicValue
		 *            The High Logic Value [3.3 volt] or [5 volt]
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputBanks
		 * Banks Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalOutput.HighLogicValue Logic
		 *      High values enum
		 **/
		public static void setPortVolt(DigitalOutputBanks bankId, HighLogicValue LogicValue) {
			setPortVolt(bankId, LogicValue, "Set the high logic value of the %s bank to %s.", bankId.toString(),
					LogicValue.toString());
		}

	}

	/**
	 * This class is implementation of standard library APIs to be used in
	 * controlling digital input pins.
	 *
	 * 
	 * @version 1.0
	 */
	public static class DigitalInput {

		/**
		 * Digital output logic values.
		 * <P>
		 * Note that PIP V1 supChannels changing the high logic to 3.3 or 12
		 * volt but the value is output logic value is set to 5 volt by default.
		 * The tester shall not change the
		 */
		public enum DigitalInputValue {
			/** Low logic is Zero Volt with strong zero */
			Low,
			/** High logic is 5 Volt with strong one */
			High
		}

		/**
		 * Logical mapping of digital output Channels that are used as DO not
		 * PWM.
		 * <p>
		 * There are 40 DO Channels any one can be configured either as PWM or a
		 * for DO. In this library implementation, There are 16 Channel reserved
		 * for PWM and 24 Channel reserved for DO. The tester shall not change
		 * the type of the Channel as long as using this standard library.
		 */
		public enum DigitalInputChannels {
			/**
			 * <p>
			 * Product Digital Input Channel 1 Connection : <br/>
			 * P07 Pin 01<br/>
			 * Product Digital Input Pin 1
			 */
			Channel01,
			/**
			 * <p>
			 * Product Digital Input Channel 2 Connection : <br/>
			 * P07 Pin 02<br/>
			 * Product Digital Input Pin 2
			 */
			Channel02,
			/**
			 * <p>
			 * Product Digital Input Channel 3 Connection : <br/>
			 * P07 Pin 03<br/>
			 * Product Digital Input Pin 3
			 */
			Channel03,
			/**
			 * <p>
			 * Product Digital Input Channel 4 Connection : <br/>
			 * P07 Pin 04<br/>
			 * Product Digital Input Pin 4
			 */
			Channel04,
			/**
			 * <p>
			 * Product Digital Input Channel 5 Connection : <br/>
			 * P07 Pin 05<br/>
			 * Product Digital Input Pin 5
			 */
			Channel05,
			/**
			 * <p>
			 * Product Digital Input Channel 6 Connection : <br/>
			 * P07 Pin 06<br/>
			 * Product Digital Input Pin 6
			 */
			Channel06,
			/**
			 * <p>
			 * Product Digital Input Channel 7 Connection : <br/>
			 * P07 Pin 07<br/>
			 * Product Digital Input Pin 7
			 */
			Channel07,
			/**
			 * <p>
			 * Product Digital Input Channel 8 Connection : <br/>
			 * P07 Pin 08<br/>
			 * Product Digital Input Pin 8
			 */
			Channel08,
			/**
			 * <p>
			 * Product Digital Input Channel 9 Connection : <br/>
			 * P07 Pin 09<br/>
			 * Product Digital Input Pin 9
			 */
			Channel09,
			/**
			 * <p>
			 * Product Digital Input Channel 10 Connection : <br/>
			 * P07 Pin 10<br/>
			 * Product Digital Input Pin 10
			 */
			Channel10,
			/**
			 * <p>
			 * Product Digital Input Channel 11 Connection : <br/>
			 * P11 Pin 01<br/>
			 * Product Digital Input Pin 11
			 */
			Channel11,
			/**
			 * <p>
			 * Product Digital Input Channel 12 Connection : <br/>
			 * P11 Pin 02<br/>
			 * Product Digital Input Pin 12
			 */
			Channel12,
			/**
			 * <p>
			 * Product Digital Input Channel 13 Connection : <br/>
			 * P11 Pin 03<br/>
			 * Product Digital Input Pin 13
			 */
			Channel13,
			/**
			 * <p>
			 * Product Digital Input Channel 14 Connection : <br/>
			 * P11 Pin 04<br/>
			 * Product Digital Input Pin 14
			 */
			Channel14,
			/**
			 * <p>
			 * Product Digital Input Channel 15 Connection : <br/>
			 * P11 Pin 05<br/>
			 * Product Digital Input Pin 15
			 */
			Channel15,
			/**
			 * <p>
			 * Product Digital Input Channel 16 Connection : <br/>
			 * P11 Pin 06<br/>
			 * Product Digital Input Pin 16
			 */
			Channel16,
			/**
			 * <p>
			 * Product Digital Input Channel 17 Connection : <br/>
			 * P11 Pin 07<br/>
			 * Product Digital Input Pin 17
			 */
			Channel17,
			/**
			 * <p>
			 * Product Digital Input Channel 18 Connection : <br/>
			 * P11 Pin 08<br/>
			 * Product Digital Input Pin 18
			 */
			Channel18,
			/**
			 * <p>
			 * Product Digital Input Channel 19 Connection : <br/>
			 * P11 Pin 09<br/>
			 * Product Digital Input Pin 19
			 */
			Channel19,
			/**
			 * <p>
			 * Product Digital Input Channel 20 Connection : <br/>
			 * P11 Pin 10<br/>
			 * Product Digital Input Pin 20
			 */
			Channel20,
			/**
			 * <p>
			 * Product Digital Input Channel 21 Connection : <br/>
			 * P15 Pin 01<br/>
			 * Product Digital Input Pin 21
			 */
			Channel21,
			/**
			 * <p>
			 * Product Digital Input Channel 22 Connection : <br/>
			 * P15 Pin 02<br/>
			 * Product Digital Input Pin 22
			 */
			Channel22,
			/**
			 * <p>
			 * Product Digital Input Channel 23 Connection : <br/>
			 * P15 Pin 03<br/>
			 * Product Digital Input Pin 23
			 */
			Channel23,
			/**
			 * <p>
			 * Product Digital Input Channel 24 Connection : <br/>
			 * P15 Pin 04<br/>
			 * Product Digital Input Pin 24
			 */
			Channel24,
			/**
			 * <p>
			 * Product Digital Input Channel 25 Connection : <br/>
			 * P15 Pin 05<br/>
			 * Product Digital Input Pin 25
			 */
			Channel25,
			/**
			 * <p>
			 * Product Digital Input Channel 26 Connection : <br/>
			 * P15 Pin 06<br/>
			 * Product Digital Input Pin 26
			 */
			Channel26,
			/**
			 * <p>
			 * Product Digital Input Channel 27 Connection : <br/>
			 * P15 Pin 07<br/>
			 * Product Digital Input Pin 27
			 */
			Channel27,
			/**
			 * <p>
			 * Product Digital Input Channel 28 Connection : <br/>
			 * P15 Pin 08<br/>
			 * Product Digital Input Pin 28
			 */
			Channel28,
			/**
			 * <p>
			 * Product Digital Input Channel 29 Connection : <br/>
			 * P15 Pin 09<br/>
			 * Product Digital Input Pin 29
			 */
			Channel29,
			/**
			 * <p>
			 * Product Digital Input Channel 30 Connection : <br/>
			 * P15 Pin 10<br/>
			 * Product Digital Input Pin 30
			 */
			Channel30,
			/**
			 * <p>
			 * Product Digital Input Channel 31 Connection : <br/>
			 * P18 Pin 01<br/>
			 * Product Digital Input Pin 31
			 */
			Channel31,
			/**
			 * <p>
			 * Product Digital Input Channel 32 Connection : <br/>
			 * P18 Pin 02<br/>
			 * Product Digital Input Pin 32
			 */
			Channel32,
			/**
			 * <p>
			 * Product Digital Input Channel 33 Connection : <br/>
			 * P18 Pin 03<br/>
			 * Product Digital Input Pin 33
			 */
			Channel33,
			/**
			 * <p>
			 * Product Digital Input Channel 34 Connection : <br/>
			 * P18 Pin 04<br/>
			 * Product Digital Input Pin 34
			 */
			Channel34,
			/**
			 * <p>
			 * Product Digital Input Channel 35 Connection : <br/>
			 * P18 Pin 05<br/>
			 * Product Digital Input Pin 35
			 */
			Channel35,
			/**
			 * <p>
			 * Product Digital Input Channel 36 Connection : <br/>
			 * P18 Pin 06<br/>
			 * Product Digital Input Pin 36
			 */
			Channel36,
			/**
			 * <p>
			 * Product Digital Input Channel 37 Connection : <br/>
			 * P18 Pin 07<br/>
			 * Product Digital Input Pin 37
			 */
			Channel37,
			/**
			 * <p>
			 * Product Digital Input Channel 38 Connection : <br/>
			 * P18 Pin 08<br/>
			 * Product Digital Input Pin 38
			 */
			Channel38,
			/**
			 * <p>
			 * Product Digital Input Channel 39 Connection : <br/>
			 * P18 Pin 09<br/>
			 * Product Digital Input Pin 39
			 */
			Channel39,
			/**
			 * <p>
			 * Product Digital Input Channel 40 Connection : <br/>
			 * P18 Pin 10<br/>
			 * Product Digital Input Pin 40
			 */
			Channel40,
			/**
			 * <p>
			 * Product Digital Input Channel 41 Connection : <br/>
			 * P8 Pin 01<br/>
			 * Product Digital Input Pin 41
			 */
			Channel41,
			/**
			 * <p>
			 * Product Digital Input Channel 42 Connection : <br/>
			 * P8 Pin 02<br/>
			 * Product Digital Output Pin 42
			 */
			Channel42,
		}

		/**
		 * Check the state of one digital input Channel to the desired value.
		 * 
		 * 
		 * @param Channel
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @param digValue
		 *            Digital Input state. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputValue
		 * Digital Input values Enum
		 * 
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputValue
		 *      Digital input values enum
		 */
		public static void assertEquals(DigitalInputChannels Channel, DigitalInputValue digValue, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			digInput.assertDigitalInputPin(Channel, digValue);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the state of one digital input Channel to the desired value.
		 * 
		 * 
		 * @param Channel
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @param digValue
		 *            Digital Input state. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputValue
		 * Digital Input values Enum
		 * 
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputValue
		 *      Digital input values enum
		 */
		public static void assertEquals(DigitalInputChannels Channel, DigitalInputValue digValue) {
			assertEquals(Channel, digValue, "Assert the value of digital input %s is %s", Channel.toString(),
					digValue.toString());
		}

		/**
		 * Starts the digital inputs capture task. It is a periodic task with
		 * periodicity 1msec. After the task start the digital input signals
		 * values are updated periodically.
		 * 
		 */
		public static void startDigitalInputAcquisition(DigitalInputChannels Channel) {
			digInput.startDigitalInputAcquisition(Channel);

			C5.Util.adddefaultPause();
		}

		/**
		 * Stop the digital inputs capture task. It is a periodic task with
		 * periodicity 1msec. After the task start the digital input signals
		 * values are updated periodically.
		 * 
		 */
		public static void stopDigitalInputAcquisition(DigitalInputChannels Channel) {
			digInput.stopDigitalInputAcquisition(Channel);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the state of one digital input Channel to the desired value.
		 * 
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @param value
		 *            Digital Input value to be reached [0 or 1]
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in Percentage %            		           
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputValue
		 *      Digital input values enum
		 */
		public static void registerValueReachedEvent(DigitalInputChannels port,int value,int ValueTol,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			int eventTolernaceTime = (int)(evTime*evTimeTolerance);

			digInput.registerValueReachedEvent(port, value,evTime,eventTolernaceTime);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the state of one digital input Channel to the desired value.
		 * 
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputEventType
		 * Channels Enum
		 * @param value
		 *            Digital Input value to be reached [0 or 1]
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in Percentage %            		           
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputValue
		 *      Digital input values enum
		 */
		public static void checkEventBasedSignals(DigitalInputChannels port,EventType type,double value,double evTime,double evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			digInput.checkEventBasedSignals(port, type,value,evTime,evTimeTolerance);

			C5.Util.adddefaultPause();
		}

		/**
		 * Read now, without waiting for the task time, the DI registers and
		 * update the signals. task start the digital input signals values are
		 * updated periodically.
		 * 
		 */
		public static void readDigitalInputValue() {
			digInput.readDigitalInputValue();

			C5.Util.adddefaultPause();
		}

	}

	/**
	 * This class is implementation of standard library APIs to be used in
	 * controlling PWM output pins.
	 * <p>
	 * A PWM output is by nature a Digital port, it can be either set to PWM or
	 * digital output.
	 *
	 * 
	 * @version 1.0
	 */
	public static class PwmOutput {
		/**
		 * Logical mapping of PWM output channels that will used for PWM
		 * generation.
		 * <p>
		 * There are 40 DO ports any one can be configured either as PWM or a
		 * for DO. In this library implementation, There are 16 port reserved
		 * for PWM and 24 port reserved for DO. The tester shall not change the
		 * type of the port as long as using this standard library.
		 * <P>
		 * The channels have a push pull configuration (strong one and zerp)
		 * with a voltage level of 5 volt. If any other configuration needed
		 * please refer to the firmware team (e.g. weak one, weak zero).
		 * <p>
		 * Note that 8 channel are only available for testers as a PWM bank us
		 * used in the power supply PWM generation. Please refer to the firmware
		 * team in case of more channels are needed.
		 */
		/** PWM Channel 1 ,P35 Pin 38 - Voltage Level 5 Volt */
		public enum PWMGenChnl {
			/**
			 * <p>
			 * PWM Gen Channel 1 Connection : <br/>
			 * P12 Pin 05<br/>
			 * High Speed 3.3 Volt Pin 1
			 */
			Chnl01,
			/**
			 * <p>
			 * PWM Gen Channel 2 Connection : <br/>
			 * P12 Pin 06<br/>
			 * High Speed 3.3 Volt Pin 2
			 */
			Chnl02,
			/**
			 * <p>
			 * PWM Gen Channel 3 Connection : <br/>
			 * P12 Pin 07<br/>
			 * High Speed 3.3 Volt Pin 3
			 */
			Chnl03,
			/**
			 * <p>
			 * PWM Gen Channel 4 Connection : <br/>
			 * P12 Pin 08<br/>
			 * High Speed 3.3 Volt Pin 4
			 */
			Chnl04,
			/**
			 * <p>
			 * PWM Gen Channel 5 Connection : <br/>
			 * P12 Pin 09<br/>
			 * High Speed 3.3 Volt Pin 5
			 */
			Chnl05,
			/**
			 * <p>
			 * PWM Gen Channel 6 Connection : <br/>
			 * P12 Pin 10<br/>
			 * High Speed 3.3 Volt Pin 6
			 */
			Chnl06,
			/**
			 * <p>
			 * PWM Gen Channel 7 Connection : <br/>
			 * P16 Pin 01<br/>
			 * High Speed 5.5 Volt Pin 1
			 */
			Chnl07,
			/**
			 * <p>
			 * PWM Gen Channel 8 Connection : <br/>
			 * P16 Pin 02<br/>
			 * High Speed 5.5 Volt Pin 2
			 */
			Chnl08,
			/**
			 * <p>
			 * PWM Gen Channel 9 Connection : <br/>
			 * P16 Pin 03<br/>
			 * High Speed 5.5 Volt Pin 3
			 */
			Chnl09
		}

		/**
		 * Unit of Frequency to be measured.
		 */
		public enum PwmOutFrequencyUnit {
			/**
			 * Hertz
			 */
			Hz,
			/**
			 * Kilo Hertz
			 */
			KHz,
			/**
			 * Mega Hertz
			 */
			MHz
		}

		/**
		 * Set the Generated PWM Wave Form Frequency And Duty-Cycle .
		 * <P>
		 * Note that any PWM channel by nature is a digital output port, So if
		 * you need to use it as digital output please refer to the digital
		 * output module :
		 * 
		 * @see {@link libs.c5.implementation.DigitalOutputLib#setDigitalOutputPin(DigitalOutputChannels, DigitalOutputValue)}
		 *      Example:
		 * @see {@link libs.c5.examples.library.pwmout.GeneratePwmSignal#GeneratePwmSignal()}
		 * @category Firmware Action
		 * @param chnl
		 *            PWM channel to apply PWM to it See
		 *            {@link libs.c5.interfaces.C5.PwmOutput.PWMGenChnl PWM
		 *            Channels Enum}
		 * @param frequencyKHz
		 *            PWM Frequency
		 * @param dutyCyclePercent
		 *            PWM Duty Cycle in Percentage
		 * @param unit
		 *            PWM Frequency Unit
		 * @see {@link libs.c5.implementation.PWMOutputLib#setPwmOutputChannel(PWMGenChnl, double, double)}
		 * @see {@link libs.c5.interfaces.C5.PwmOutput.PwmOutFrequencyUnit
		 *      Frequency units}
		 * @see {@link libs.c5.interfaces.C5.PwmOutput.PWMGenChnl Channels}
		 */
		public static void setPwmOutput(PWMGenChnl chnl, double frequencyKHz, double dutyCyclePercent,
				PwmOutFrequencyUnit unit, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmOutput.setPwmOutputChannel(chnl, frequencyKHz, unit, dutyCyclePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Set the Generated PWM Wave Form Frequency And Duty-Cycle .
		 * <P>
		 * Note that any PWM channel by nature is a digital output port, So if
		 * you need to use it as digital output please refer to the digital
		 * output module :
		 * 
		 * @see {@link libs.c5.implementation.DigitalOutputLib#setDigitalOutputPin(DigitalOutputChannels, DigitalOutputValue)}
		 *      Example:
		 * @see {@link libs.c5.examples.library.pwmout.GeneratePwmSignal#GeneratePwmSignal()}
		 * @category Firmware Action
		 * @param chnl
		 *            PWM channel to apply PWM to it See
		 *            {@link libs.c5.interfaces.C5.PwmOutput.PWMGenChnl PWM
		 *            Channels Enum}
		 * @param frequencyKHz
		 *            PWM Frequency
		 * @param dutyCyclePercent
		 *            PWM Duty Cycle in Percentage
		 * @param unit
		 *            PWM Frequency Unit
		 * @see {@link libs.c5.implementation.PWMOutputLib#setPwmOutputChannel(PWMGenChnl, double, double)}
		 * @see {@link libs.c5.interfaces.C5.PwmOutput.PwmOutFrequencyUnit
		 *      Frequency units}
		 * @see {@link libs.c5.interfaces.C5.PwmOutput.PWMGenChnl Channels}
		 */
		public static void setPwmOutput(PWMGenChnl chnl, double frequencyKHz, double dutyCyclePercent,
				PwmOutFrequencyUnit unit) {
			setPwmOutput(chnl, frequencyKHz, dutyCyclePercent, unit,
					"Generated PWM on channel %s with %.2f KHz and duty cycle equals %.2f ", chnl.toString(),
					frequencyKHz, dutyCyclePercent);
		}
	}

	/**
	 * This class is standard library APIs to be used in controlling PWM input
	 * measurement Channels.
	 *
	 * <p>
	 * PIP V1 board has 60 digital input channels, any of them can either be
	 * used as PWM or Digital input. But 16 channels can only be active at once.
	 * <p>
	 * To simplify the design of the library, the first 16 digital PWM input
	 * channel are dedicated to PWM.
	 *
	 * 
	 * @version 1.0
	 */
	public static class PwmInput {
		/**
		 * Logical mapping of PWM measuring channels that will used for PWM
		 * Acquisition.
		 * <p>
		 * There are 16 DI ports as PWM or a for DI.
		 * <p>
		 * Note that 16 channel are only available for testers as a PWM bank.
		 * Please refer to the firmware team in case of more channels are
		 * needed.
		 */
		public enum PwmInChnl {
			/**
			 * <p>
			 * Product Digital Input Channel 1 Connection : <br/>
			 * P07 Pin 01<br/>
			 * Product Digital Input Pin 1
			 */
			Chnl01,
			/**
			 * <p>
			 * Product Digital Input Channel 2 Connection : <br/>
			 * P07 Pin 02<br/>
			 * Product Digital Input Pin 2
			 */
			Chnl02,
			/**
			 * <p>
			 * Product Digital Input Channel 3 Connection : <br/>
			 * P07 Pin 03<br/>
			 * Product Digital Input Pin 3
			 */
			Chnl03,
			/**
			 * <p>
			 * Product Digital Input Channel 4 Connection : <br/>
			 * P07 Pin 04<br/>
			 * Product Digital Input Pin 4
			 */
			Chnl04,
			/**
			 * <p>
			 * Product Digital Input Channel 5 Connection : <br/>
			 * P07 Pin 05<br/>
			 * Product Digital Input Pin 5
			 */
			Chnl05,
			/**
			 * <p>
			 * Product Digital Input Channel 6 Connection : <br/>
			 * P07 Pin 06<br/>
			 * Product Digital Input Pin 6
			 */
			Chnl06,
			/**
			 * <p>
			 * Product Digital Input Channel 7 Connection : <br/>
			 * P07 Pin 07<br/>
			 * Product Digital Input Pin 7
			 */
			Chnl07,
			/**
			 * <p>
			 * Product Digital Input Channel 8 Connection : <br/>
			 * P07 Pin 08<br/>
			 * Product Digital Input Pin 8
			 */
			Chnl08,
			/**
			 * <p>
			 * Product Digital Input Channel 9 Connection : <br/>
			 * P07 Pin 09<br/>
			 * Product Digital Input Pin 9
			 */
			Chnl09,
			/**
			 * <p>
			 * Product Digital Input Channel 10 Connection : <br/>
			 * P07 Pin 10<br/>
			 * Product Digital Input Pin 10
			 */
			Chnl10,
			/**
			 * <p>
			 * Product Digital Input Channel 11 Connection : <br/>
			 * P11 Pin 01<br/>
			 * Product Digital Input Pin 11
			 */
			Chnl11,
			/**
			 * <p>
			 * Product Digital Input Channel 12 Connection : <br/>
			 * P11 Pin 02<br/>
			 * Product Digital Input Pin 12
			 */
			Chnl12,
			/**
			 * <p>
			 * Product Digital Input Channel 13 Connection : <br/>
			 * P11 Pin 03<br/>
			 * Product Digital Input Pin 13
			 */
			Chnl13,
			/**
			 * <p>
			 * Product Digital Input Channel 14 Connection : <br/>
			 * P11 Pin 04<br/>
			 * Product Digital Input Pin 14
			 */
			Chnl14,
			/**
			 * <p>
			 * Product Digital Input Channel 15 Connection : <br/>
			 * P11 Pin 05<br/>
			 * Product Digital Input Pin 15
			 */
			Chnl15,
			/**
			 * <p>
			 * Product Digital Input Channel 16 Connection : <br/>
			 * P11 Pin 06<br/>
			 * Product Digital Input Pin 16
			 */
			Chnl16
		}

		/**
		 * Unit of Frequency to be measured.
		 */
		public enum PwmInFrequencyUnit {
			/**
			 * Hertz
			 */
			Hz,
			/**
			 * Kilo Hertz
			 */
			KHz,
			/**
			 * Mega Hertz
			 */
			MHz
		}
		
		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqTolerancePercent
		 *            Accepted tolerance in frequency e.g. 5%. E.g. if the
		 *            expected frequency is 1K and tolerance is 5% then any
		 *            measured value between 1050 and 950 Hz will be ok for the
		 *            test.
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytTolerancePercent
		 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 63.05% to 66.95% will be ok.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequencyAndDutyCycle(PwmInChnl chnl, double frequency, double freqTolerancePercent,
				double dutyCyclePercent, double duytTolerancePercent, PwmInFrequencyUnit unit, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.assertPwmFrequencyAndDutyCycle(chnl, frequency, freqTolerancePercent, dutyCyclePercent,
					duytTolerancePercent, unit);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqTolerancePercent
		 *            Accepted tolerance in frequency e.g. 5%. E.g. if the
		 *            expected frequency is 1K and tolerance is 5% then any
		 *            measured value between 1050 and 950 Hz will be ok for the
		 *            test.
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytTolerancePercent
		 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 63.05% to 66.95% will be ok.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequencyAndDutyCycle(PwmInChnl chnl, double frequency, double freqTolerancePercent,
				double dutyCyclePercent, double duytTolerancePercent, PwmInFrequencyUnit unit) {
			assertPwmFrequencyAndDutyCycle(chnl, frequency, freqTolerancePercent, dutyCyclePercent,
					duytTolerancePercent, unit,
					"Assert PWM on channel %s with frequency %.2f KHz with %.2f tolerance  and duty cycle equals %.2f with %.2f tolerance",
					chnl.toString(), frequency, freqTolerancePercent, dutyCyclePercent, duytTolerancePercent);
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqTolerancePercent
		 *            Accepted tolerance in frequency e.g. 5%. E.g. if the
		 *            expected frequency is 1K and tolerance is 5% then any
		 *            measured value between 1050 and 950 Hz will be ok for the
		 *            test.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequency(PwmInChnl chnl, double frequency, double freqTolerancePercent,
				PwmInFrequencyUnit unit, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.assertPwmFrequency(chnl, frequency, freqTolerancePercent, unit);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqTolerancePercent
		 *            Accepted tolerance in frequency e.g. 5%. E.g. if the
		 *            expected frequency is 1K and tolerance is 5% then any
		 *            measured value between 1050 and 950 Hz will be ok for the
		 *            test.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequency(PwmInChnl chnl, double frequency, double freqTolerancePercent,
				PwmInFrequencyUnit unit) {
			assertPwmFrequency(chnl, frequency, freqTolerancePercent, unit,
					"Assert PWM on channel %s with frequency %.2f KHz with %.2f tolerance.", chnl.toString(), frequency,
					freqTolerancePercent);
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytTolerancePercent
		 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 63.05% to 66.95% will be ok.
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmDutyCycle(PwmInChnl chnl, double dutyCyclePercent, double duytTolerancePercent,
				String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.assertPwmDutyCycle(chnl, dutyCyclePercent, duytTolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytTolerancePercent
		 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 63.05% to 66.95% will be ok.
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmDutyCycle(PwmInChnl chnl, double dutyCyclePercent, double duytTolerancePercent) {
			assertPwmDutyCycle(chnl, dutyCyclePercent, duytTolerancePercent,
					"Assert PWM on channel %s with duty cycle equals %.2f with %.2f tolerance", chnl.toString(),
					dutyCyclePercent, duytTolerancePercent);
		}

		/**
		 * Reset continuous check the PWM frequency on the desired PWM channel
		 * 
		 * @category Firmware Action
		 */
		public static void resetPwmInputRegisters(PwmInChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.resetPwmMeasurementRegisters(chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * Reset continuous check the PWM frequency on the desired PWM channel
		 * 
		 * @category Firmware Action
		 */
		public static void resetPwmInputRegisters(PwmInChnl chnl) {
			resetPwmInputRegisters(chnl, "Reset continuous check the PWM frequency on PWM channel %s", chnl.toString());
		}

		/**
		 * Start continuous check the PWM frequency on the desired PWM channel
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 */
		public static void startAcquistion(PwmInChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.startPWMContinousAcquisition(chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * Start continuous check the PWM frequency on the desired PWM channel
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 */
		public static void startAcquistion(PwmInChnl chnl) {
			startAcquistion(chnl, "Start continuous check the PWM frequency on the %s PWM channel", chnl.toString());
		}

		/**
		 * Stop continuous check the PWM frequency on the desired PWM channel
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * 
		 */
		public static void stopAcquistion(PwmInChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.stopPWMContinousAcquisition(chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * Stop continuous check the PWM frequency on the desired PWM channel
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * 
		 */
		public static void stopAcquistion(PwmInChnl chnl) {
			stopAcquistion(chnl, "Stop continuous check the PWM frequency on the %s PWM channel", chnl.toString());
		}

		/**
		 * Check the state of one digital input Channel to the desired value.
		 * 
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @param value
		 *            Digital Input value to be reached [0 or 1]
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in Percentage %            		           
		 * @category Firmware Action
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputChannels
		 * Channels Enum
		 * @see {@link libs.c5.interfaces.C5.DigitalInput.DigitalInputValue
		 *      Digital input values enum
		 */
		public static void registerValueReachedEventOnFrequency(PwmInChnl port,int value,int ValueTol,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			int eventTolernaceTime = (int)(evTime*evTimeTolerance);

			pwmInput.registerValueReachedEventOnFrequency(port, value,evTime,eventTolernaceTime);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the value of one PWM input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            PWM in Frequency Input value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnFrequency(PwmInChnl port,EventType type,int value,double ValueTol,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.checkEventBasedSignalsOnFrequency(port, type,value, ValueTol,evTime,evTimeTolerance);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the value of one PWM input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Current Input value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void registerValueReachedEventOnDuty(PwmInChnl port,int value,int ValueTol,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			int eventTolernaceTime = (int)(evTime*evTimeTolerance);

			pwmInput.registerValueReachedEventOnDuty(port, value,evTime,eventTolernaceTime);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the value of one PWM input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            PWM in Duty Input value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnDuty(PwmInChnl port,EventType type,double value,double ValueTol,double evTime,double evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.checkEventBasedSignalsOnDuty(port, type, value, ValueTol, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqToleranceAbsoulte
		 *            Accepted tolerance in frequency e.g. 5. E.g. if the
		 *            expected frequency is 1K and tolerance is 5 Hz then any
		 *            measured value between 1005 and 995 Hz will be ok for the
		 *            test.
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytToleranceAbsoulte
		 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 62% to 68% will be ok.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycleAbs(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequencyAndDutyCycleAbs(PwmInChnl chnl, double frequency, double freqToleranceAbsoulte,
				double dutyCyclePercent, double duytToleranceAbsoulte, PwmInFrequencyUnit unit, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.assertPwmFrequencyAndDutyCycleAbs(chnl, frequency, freqToleranceAbsoulte, dutyCyclePercent,
					duytToleranceAbsoulte, unit);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqToleranceAbsoulte
		 *            Accepted tolerance in frequency e.g. 5 Hz. E.g. if the
		 *            expected frequency is 1K and tolerance is 5% then any
		 *            measured value between 1005 and 995 Hz will be ok for the
		 *            test.
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytToleranceAbsoulte
		 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 62% to 68% will be ok.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequencyAndDutyCycleAbs(PwmInChnl chnl, double frequency, double freqToleranceAbsoulte,
				double dutyCyclePercent, double duytToleranceAbsoulte, PwmInFrequencyUnit unit) {
			assertPwmFrequencyAndDutyCycleAbs(chnl, frequency, freqToleranceAbsoulte, dutyCyclePercent,
					duytToleranceAbsoulte, unit,
					"Assert PWM on channel %s with frequency %.2f KHz with %.2f tolerance  and duty cycle equals %.2f with %.2f tolerance",
					chnl.toString(), frequency, freqToleranceAbsoulte, dutyCyclePercent, duytToleranceAbsoulte);
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqToleranceAbsoulte
		 *            Accepted tolerance in frequency e.g. 5 Hz. E.g. if the
		 *            expected frequency is 1K and tolerance is 5% then any
		 *            measured value between 1005 and 995 Hz will be ok for the
		 *            test.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequencyAbs(PwmInChnl chnl, double frequency, double freqToleranceAbsoulte,
				PwmInFrequencyUnit unit, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.assertPwmFrequencyAbs(chnl, frequency, freqToleranceAbsoulte, unit);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param frequency
		 *            Frequency in KHz e.g. 1.75 KHz
		 * @param freqToleranceAbsoulte
		 *            Accepted tolerance in frequency e.g. 5 Hz. E.g. if the
		 *            expected frequency is 1K and tolerance is 5% then any
		 *            measured value between 1005 and 995 Hz will be ok for the
		 *            test.
		 * @param unit
		 *            Unit of the value to expect
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmFrequencyAbs(PwmInChnl chnl, double frequency, double freqToleranceAbsoulte,
				PwmInFrequencyUnit unit) {
			assertPwmFrequencyAbs(chnl, frequency, freqToleranceAbsoulte, unit,
					"Assert PWM on channel %s with frequency %.2f KHz with %.2f tolerance.", chnl.toString(), frequency,
					freqToleranceAbsoulte);
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytToleranceAbsoulte
		 *            Accepted tolerance in duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 62% to 68% will be ok.
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmDutyCycleAbs(PwmInChnl chnl, double dutyCyclePercent, double duytToleranceAbsoulte,
				String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			pwmInput.assertPwmDutyCycleAbs(chnl, dutyCyclePercent, duytToleranceAbsoulte);

			C5.Util.adddefaultPause();
		}

		/**
		 * Check the PWM Wave Form characteristics [Frequency - duty cycle]
		 * 
		 * Example:
		 * 
		 * @see {@link libs.c5.examples.library.pwmin.ReadPwmInChannel}
		 * 
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            ID of input PWM channel
		 * @param dutyCyclePercent
		 *            Dutycycle percentage e.g. 56.7
		 * @param duytToleranceAbsoulte
		 *            Accepted tolerance in absoulute duty cycle e.g. 5%. E.g. if the
		 *            expected duty cycle is 65% and tolerance is 3% then any
		 *            duty cycle between 62% to 68% will be ok.
		 * 
		 * @see {@link libs.c5.interfaces.C5.PwmInput.PwmInChnl PWM Channels
		 *      Enum}
		 * @see {@link STD_Libraries.Implmentation.PWMInputLib#assertPwmFrequencyAndDutyCycle(PwmInChnl, double, double, double, double)}
		 * 
		 */
		public static void assertPwmDutyCycleAbs(PwmInChnl chnl, double dutyCyclePercent, double duytToleranceAbsoulte) {
			assertPwmDutyCycleAbs(chnl, dutyCyclePercent, duytToleranceAbsoulte,
					"Assert PWM on channel %s with duty cycle equals %.2f with %.2f tolerance", chnl.toString(),
					dutyCyclePercent, duytToleranceAbsoulte);
		}
		
	}

	/**
	 * This class is standard library APIs to be used in creating defects.
	 *
	 * <p>
	 * C5 EPIP V1 has 6 defect cells that can be used to create different types
	 * of defects. This library provides APIs for clear and create defect.
	 *
	 * @author Wesam Khattab
	 * @version 1.0
	 */

	public static class Defect {
		/**
		 * Logical mapping of PWM measuring channels that will used for PWM
		 * Acquisition.
		 * <p>
		 * There are 6 defect cells which can take on of these states 1- S.C to
		 * GND 2- S.C to VCC 3- S.C to on the same Cell 4- O.C
		 * <p>
		 * Note that 6 channel are only available for testers as a defect cells.
		 * Please refer to the firmware team in case of more channels are
		 * needed.
		 */
		public enum DefectCell {
			/**
			 * Current Sense Channel 1.
			 * <p>
			 * Positive Input: P5 Pin2 LOADA1
			 * <p>
			 * Negative Input: P6 Pin2 ECUA1
			 */
			Cell01,
			/**
			 * Current Sense Channel 2.
			 * <p>
			 * Positive Input: P5 Pin3 LOADA2
			 * <p>
			 * Negative Input: P6 Pin3 ECUA2
			 */
			Cell02,
			/**
			 * Current Sense Channel 3.
			 * <p>
			 * Positive Input: P9 Pin4 LOADA3
			 * <p>
			 * Negative Input: P10 Pin4 ECUA3
			 */
			Cell03,
			/**
			 * Current Sense Channel 4.
			 * <p>
			 * Positive Input: P9 Pin5 LOADA4
			 * <p>
			 * Negative Input: P10 Pin5 ECUA4
			 */
			Cell04,
			/**
			 * Current Sense Channel 5.
			 * <p>
			 * Positive Input: P13 Pin4 LOADA5
			 * <p>
			 * Negative Input: P14 Pin4 ECUA5
			 */
			Cell05,
			/**
			 * Current Sense Channel 6.
			 * <p>
			 * Positive Input: P13 Pin3 LOADA6
			 * <p>
			 * Negative Input: P14 Pin3 ECUA6
			 */
			Cell06
		}

		public enum DefectType {
			/**
			 * Defect Type
			 * <p>
			 * Short Circuit between the two adjacent Cells
			 */
			NoDefects,
			/**
			 * Defect Type
			 * <p>
			 * Open Circuit Defect
			 */
			OpenCircuit,
			/**
			 * Defect Type
			 * <p>
			 * Short Circuit to ground
			 */
			ScToGnd,
			/**
			 * Defect Type
			 * <p>
			 * Short Circuit to battery
			 */
			ScToBatt,
			/**
			 * Defect Type
			 * <p>
			 * Short Circuit on the same Cell
			 */
			ScOnCell,
			/**
			 * Defect Type
			 * <p>
			 * Short Circuit between the two adjacent Cells
			 */
			ScBetweenCells,
		}

		public enum ScToBattSrc {
			/**
			 * Defect Type Source
			 * <p>
			 * Power Supply Channel 1 is the S.C to battery source
			 */
			PwrSuppCh1,
			/**
			 * Defect Type Source
			 * <p>
			 * Power Supply Channel 2 is the S.C to battery source
			 */
			PwrSuppCh2,
		}

		/**
		 * Remove all of the applied defects.
		 * 
		 * @category Firmware Action
		 * 
		 * @see {@link libs.c5.examples.library.defects.ClearAllDefects #task
		 *      Example}
		 * 
		 **/
		public static void ClearAllDefects(String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.defectCell.removeAllDefects();

			C5.Util.adddefaultPause();
		}

		/**
		 * Remove all of the applied defects.
		 * 
		 * @category Firmware Action
		 * 
		 * @see {@link libs.c5.examples.library.defects.ClearAllDefects #task
		 *      Example}
		 * 
		 **/
		public static void ClearAllDefects() {
			ClearAllDefects("Remove all of the applied defects on all defect channels.");
		}

		/**
		 * Apply [s.c - o.c - ...] defect on one of the available 6 defect cells
		 * .
		 * <p>
		 * Select the Cell index to apply the defect on it.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Select the defect Index [cell01, ......] 2-Select The Defect type
		 * you need to create [OpenCircuit, .....]
		 * 
		 * @category Firmware Action
		 * @param defectCellIndex
		 *            Defect Cell Index
		 * 
		 * @param defectType
		 *            Defect Cell Type to be applied on the requested cell
		 *
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitToGnd #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitToBatt #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.OpenCircuitOnDefectCells #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitBetweenCells #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitOnSameCell #task
		 *      Example}
		 *
		 **/
		public static void setDefectCellDefectType(DefectCell defectCellIndex, DefectType defectType, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.defectCell.setDefectCellDefectType(defectCellIndex, defectType);

			C5.Util.adddefaultPause();
		}

		/**
		 * Apply [s.c - o.c - ...] defect on one of the available 6 defect cells
		 * .
		 * <p>
		 * Select the Cell index to apply the defect on it.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Select the defect Index [cell01, ......] 2-Select The Defect type
		 * you need to create [OpenCircuit, .....]
		 * 
		 * @category Firmware Action
		 * @param defectCellIndex
		 *            Defect Cell Index
		 * 
		 * @param defectType
		 *            Defect Cell Type to be applied on the requested cell
		 *
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitToGnd #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitToBatt #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.OpenCircuitOnDefectCells #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitBetweenCells #task
		 *      Example}
		 * @see {@link libs.c5.examples.library.defects.ShortCircuitOnSameCell #task
		 *      Example}
		 *
		 **/
		public static void setDefectCellDefectType(DefectCell defectCellIndex, DefectType defectType) {
			setDefectCellDefectType(defectCellIndex, defectType, "Apply %s defect on defect cells %s",
					defectType.toString(), defectCellIndex.toString());
		}

		/**
		 * Configure the S.C to power supply source.
		 * <p>
		 * Warnings:
		 * <p>
		 * The Source of the ScToBatt defect is by default connected to power
		 * supply channel 1
		 * 
		 * @category Firmware Action
		 * @param defectCellIndex
		 *            Defect Cell Index
		 **/
		public static void setSourceOfShortCircuitToBattery(ScToBattSrc defectSrc, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.defectCell.setSourceOfShortCircuitToBattery(defectSrc);

			C5.Util.adddefaultPause();
		}

		/**
		 * Configure the S.C to power supply source.
		 * <p>
		 * Warnings:
		 * <p>
		 * The Source of the ScToBatt defect is by default connected to power
		 * supply channel 1
		 * 
		 * @category Firmware Action
		 * @param defectCellIndex
		 *            Defect Cell Index
		 **/
		public static void setSourceOfShortCircuitToBattery(ScToBattSrc defectSr) {
			setSourceOfShortCircuitToBattery(defectSr, "Configure the S.C to power supply source to %s",
					defectSr.toString());
		}

	}

	/**
	 * This class is standard library APIs to be used in measuring voltage.
	 *
	 * <p>
	 * C5 PIP V2 has 2 voltage channel that can be used to measure voltage. This
	 * library provides APIs for measuring instantaneous voltage, filtered
	 * voltage, average voltage.
	 *
	 * @author Wesam Khattb
	 * @version 1.0
	 */
	public static class VoltageMeasurement {

		/**
		 * Unit of Voltage to be measured.
		 */
		public enum VoltageUnit {
			/**
			 * Volt
			 */
			V,
			/**
			 * Milli Volt
			 */
			mV,
			/**
			 * Micro Volt
			 */
			uV
		}

		/**
		 * C5 PIP V2 has 2 Voltage channel that can be used to measure Voltage.
		 */
		public enum VoltageChnl {
			/**
			 * Voltage Sense Channel 1.
			 * <p>
			 * Connection : <br/>
			 * *Product Analog Output 1 <br/>
			 * *P16 Pin 09<br/>
			 */
			Channel01,
			/**
			 * Voltage Sense Channel 2.
			 * <p>
			 * Connection :<br/>
			 * *Product Analog Output 2 <br/>
			 * *P16 Pin 10<br/>
			 */
			Channel02,
		}

		/**
		 * Measure a filtered Voltage value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * <p>
		 * Get filtered Voltage value on a channel by averaging all the readings
		 * done during the assigned duration. This API a prior start acquisition
		 * of the ADC channel, the tester need to care about starting or
		 * stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used Voltage channel should be enabled before reading.<br/>
		 * 2-The API returns the value of average Voltage over 1024 sample.<br/>
		 * 3-The used Voltage channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to read its value.
		 * @param Voltage
		 *            Voltage value e.g. 1800 mA
		 * @param VoltageUnit
		 *            unit of Voltage passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured Voltage in percentage e.g. 3%
		 **/
		public static void assertFilteredVoltage(VoltageChnl chnl, float voltage, VoltageUnit unit,
				float tolerancePercent, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.voltageMeasurement.assertFilteredvoltage(chnl, voltage, unit, tolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure a filtered Voltage value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * <p>
		 * Get filtered Voltage value on a channel by averaging all the readings
		 * done during the assigned duration. This API a prior start acquisition
		 * of the ADC channel, the tester need to care about starting or
		 * stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used Voltage channel should be enabled before reading.<br/>
		 * 2-The API returns the value of average Voltage over 1024 sample.<br/>
		 * 3-The used Voltage channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to read its value.
		 * @param Voltage
		 *            Voltage value e.g. 1800 mA
		 * @param VoltageUnit
		 *            unit of Voltage passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured Voltage in percentage e.g. 3%
		 **/
		public static void assertFilteredVoltage(VoltageChnl chnl, float voltage, VoltageUnit unit,
				float tolerancePercent) {
			assertFilteredVoltage(chnl, voltage, unit, tolerancePercent,
					"Assert filtered Voltage value for channel %s equals %.2f %s with tolerance %.2f", chnl.toString(),
					voltage, unit.toString(), tolerancePercent);
		}

		/**
		 * Measure a instantaneous Voltage value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous Voltage value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used Voltage channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous Voltage.<br/>
		 * 3-The used Voltage channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to read its value.
		 * @param Voltage
		 *            Voltage value e.g. 1800 mA
		 * @param VoltageUnit
		 *            unit of Voltage passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured Voltage in percentage e.g. 3%
		 **/
		public static void assertInstantaneousVoltage(VoltageChnl chnl, float voltage, VoltageUnit unit,
				float tolerancePercent, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.voltageMeasurement.assertVoltageInstantenous(chnl, voltage, unit, tolerancePercent);

			C5.Util.adddefaultPause();

		}

		/**
		 * Measure a instantaneous Voltage value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous Voltage value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used Voltage channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous Voltage.<br/>
		 * 3-The used Voltage channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to read its value.
		 * @param Voltage
		 *            Voltage value e.g. 1800 mA
		 * @param VoltageUnit
		 *            unit of Voltage passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured Voltage in percentage e.g. 3%
		 **/
		public static void assertInstantaneousVoltage(VoltageChnl chnl, float voltage, VoltageUnit unit,
				float tolerancePercent) {
			assertInstantaneousVoltage(chnl, voltage, unit, tolerancePercent,
					"Assert instantenous Voltage value for channel %s equals %.2f %s with tolerance %.2f",
					chnl.toString(), voltage, unit.toString(), tolerancePercent);

		}

		/**
		 * Measure the maximum Voltage value for one channel during desired
		 * duration. This API manages the start and the stop of the ADC channel.
		 * <p>
		 * Get maximum Voltage value on a channel during the assigned duration.
		 * This API manages the start and the stop of the ADC channel, the
		 * tester doesn't need to worry about starting or stopping the ADC
		 * channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used Voltage channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Max Measured Voltage from starting
		 * from the start acquisition of this channel to the end of the
		 * acquisition.<br/>
		 * 3-The used Voltage channel should be disabled if it is not used.<br/>
		 *
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to read its value.
		 * @param Voltage
		 *            Voltage value 1800 mA
		 * @param VoltageUnit
		 *            unit of Voltage passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured Voltage in percentage e.g. 3%
		 **/
		public static void assertMaximumVoltage(VoltageChnl chnl, float voltage, VoltageUnit unit,
				float tolerancePercent, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.voltageMeasurement.assertVoltageMax(chnl, voltage, unit, tolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the maximum Voltage value for one channel during desired
		 * duration. This API manages the start and the stop of the ADC channel.
		 * <p>
		 * Get maximum Voltage value on a channel during the assigned duration.
		 * This API manages the start and the stop of the ADC channel, the
		 * tester doesn't need to worry about starting or stopping the ADC
		 * channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used Voltage channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Max Measured Voltage from starting
		 * from the start acquisition of this channel to the end of the
		 * acquisition.<br/>
		 * 3-The used Voltage channel should be disabled if it is not used.<br/>
		 *
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to read its value.
		 * @param Voltage
		 *            Voltage value 1800 mA
		 * @param VoltageUnit
		 *            unit of Voltage passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured Voltage in percentage e.g. 3%
		 **/
		public static void assertMaximumVoltage(VoltageChnl chnl, float voltage, VoltageUnit unit,
				float tolerancePercent) {
			assertMaximumVoltage(chnl, voltage, unit, tolerancePercent,
					"Assert maximum Voltage value for channel %s equals %.2f %s with tolerance %.2f", chnl.toString(),
					voltage, unit.toString(), tolerancePercent);
		}

		/**
		 * Start measuring Voltage on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum Voltage values can be acquired at at any time.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The API must be called prior to measuring any Voltage value at a
		 * channel (unless using the APIs checkInstVoltageAuto or
		 * checkFilteredVoltageAuto). <br/>
		 * 2-Always stop the Voltage channel when not using it so that other
		 * channels work as fast as possible. <br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to start updating its value.
		 **/
		public static void startVoltageChannelAcquisition(VoltageChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.voltageMeasurement.startVoltageChannelAcquision(chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * Start measuring Voltage on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum Voltage values can be acquired at at any time.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The API must be called prior to measuring any Voltage value at a
		 * channel (unless using the APIs checkInstVoltageAuto or
		 * checkFilteredVoltageAuto). <br/>
		 * 2-Always stop the Voltage channel when not using it so that other
		 * channels work as fast as possible. <br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to start updating its value.
		 **/
		public static void startVoltageChannelAcquisition(VoltageChnl chnl) {
			startVoltageChannelAcquisition(chnl, "Start continous measuring of voltage on a channel %s",
					chnl.toString());
		}

		/**
		 * stop measuring Voltage on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum Voltage values will not be updated.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Always stop the Voltage channel when not using it so that other
		 * channels work as fast as possible. 2-When stopping ADC channel, all
		 * previous readings are reset.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to stop updating its value.
		 **/
		public static void stopVoltageChannelAcquisition(VoltageChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.voltageMeasurement.stopVoltageChannelAcquisition(chnl);

			C5.Util.adddefaultPause();
		}
		
		/**
		 * Check the value of one Volatge input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.VoltageMeasurement.VoltageChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Average Input Voltage value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnAverageVoltage(VoltageChnl port,EventType type,int value,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			voltageMeasurement.checkEventBasedSignalsOnAverageVoltage(port, type, value, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}
		
		/**
		 * Check the value of one Volatge input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.VoltageMeasurement.VoltageChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Instantenous Input Voltage value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnInstantenousVoltage(VoltageChnl port,EventType type,int value,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			voltageMeasurement.checkEventBasedSignalsOnInstantenousVoltage(port, type, value, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}
		
		/**
		 * Check the value of one Volatge input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.VoltageMeasurement.VoltageChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Max Input Voltage value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnMaxVoltage(VoltageChnl port,EventType type,int value,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			voltageMeasurement.checkEventBasedSignalsOnMaxVoltage(port, type, value, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}

		/**
		 * stop measuring Voltage on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum Voltage values will not be updated.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Always stop the Voltage channel when not using it so that other
		 * channels work as fast as possible. 2-When stopping ADC channel, all
		 * previous readings are reset.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Voltage channel to stop updating its value.
		 **/
		public static void stopVoltageChannelAcquisition(VoltageChnl chnl) {
			stopVoltageChannelAcquisition(chnl, "Stop continous measuring of voltage on a channel %s", chnl.toString());
		}

		/**
		 * Get access to the instantaneous Voltage signal. </br>
		 * <p>
		 * This API is intended for advanced testers. </br>
		 * This API doesn't manage the ADC channel, the tester must manage the
		 * start,stop and data reset on his own.
		 * 
		 * @category Preprocessor
		 * @param chnl
		 *            Voltage channel to get its signal.
		 **/
		@SuppressWarnings("unused")
		private static Itf_SignalValue getInstVoltageSignal(VoltageChnl chnl, String comment, Object... args) {
			// Util.commentNxtFunctionCall(comment, args);

			return C5.voltageMeasurement.getInstVoltageSignal(chnl);
		}

		/**
		 * Get access to the average Voltage signal. </br>
		 * <p>
		 * This API is intended for advanced testers. </br>
		 * This API doesn't manage the ADC channel, the tester must manage the
		 * start,stop and data reset on his own.
		 * 
		 * @category Preprocessor
		 * @param chnl
		 *            Voltage channel to get its signal.
		 **/
		@SuppressWarnings("unused")
		private static Itf_SignalValue getAverageVoltageSignal(VoltageChnl chnl, String comment, Object... args) {
			return C5.voltageMeasurement.getAverageVoltageSignal(chnl);
		}

		/**
		 * Reset all stored data for a channel.
		 * 
		 * @category Firmware Action
		 **/
		public static void resetMeasuremnents(String comment, Object... args) {

			Util.commentNxtFunctionCall(comment, args);

			C5.voltageMeasurement.resetMeasuremnents();

			C5.Util.adddefaultPause();
		}

		/**
		 * Reset all stored data for a channel.
		 * 
		 * @category Firmware Action
		 **/
		public static void resetMeasuremnents() {
			resetMeasuremnents("Reset all stored data for ADC module.");
		}
	}

	/**
	 * This class is standard library APIs to be used in measuring current.
	 *
	 * <p>
	 * C5 EPIP V1 has 16 current channel that can be used to measure current.
	 * This library provides APIs for measuring instantaneous current, filtered
	 * current, average current and PWM current signals.
	 *
	 * 
	 * @version 1.0
	 */
	public static class CurrentSense {

		/**
		 * Unit of current to be measured.
		 */
		public enum CurrentUnit {
			/**
			 * Ampere
			 */
			A,
			/**
			 * Milli Ampere
			 */
			mA,
			/**
			 * Micro Ampere
			 */
			uA
		}

		/**
		 * C5 PIP V2 has 6 current channel that can be used to measure current.
		 * <p>
		 * Warning: These current channels are shared with the defect cells
		 * channels.
		 */
		public enum CurrentChnl {
			/**
			 * Current Sense Channel 1.
			 * <p>
			 * Positive Input: P5 Pin2 LOADA1
			 * <p>
			 * Negative Input: P6 Pin2 ECUA1
			 */
			Channel01,
			/**
			 * Current Sense Channel 2.
			 * <p>
			 * Positive Input: P5 Pin3 LOADA2
			 * <p>
			 * Negative Input: P6 Pin3 ECUA2
			 */
			Channel02,
			/**
			 * Current Sense Channel 3.
			 * <p>
			 * Positive Input: P9 Pin4 LOADA3
			 * <p>
			 * Negative Input: P10 Pin4 ECUA3
			 */
			Channel03,
			/**
			 * Current Sense Channel 4.
			 * <p>
			 * Positive Input: P9 Pin5 LOADA4
			 * <p>
			 * Negative Input: P10 Pin5 ECUA4
			 */
			Channel04,
			/**
			 * Current Sense Channel 5.
			 * <p>
			 * Positive Input: P13 Pin4 LOADA5
			 * <p>
			 * Negative Input: P14 Pin4 ECUA5
			 */
			Channel05,
			/**
			 * Current Sense Channel 6.
			 * <p>
			 * Positive Input: P13 Pin3 LOADA6
			 * <p>
			 * Negative Input: P14 Pin3 ECUA6
			 */
			Channel06,
		}


		/**
		 * Measure the frequency current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param frequency
		 *            Frequency values in Hz
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertFrequencyCurrent(CurrentChnl chnl, float frequency, float tolerancePercent, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertFrequencyCurrent(chnl, frequency, tolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the frequency current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param frequency
		 *            Frequency values in Hz
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertFrequencyCurrent(CurrentChnl chnl, float frequency, float tolerancePercent) {
			assertFrequencyCurrent(chnl,frequency,tolerancePercent,
					"Assert frequency current value for channel %s equals %.2f Hz with tolerance %.2f", chnl.toString(),
					frequency, tolerancePercent);
		}


		/**
		 * Measure a filtered current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * <p>
		 * Get filtered current value on a channel by averaging all the readings
		 * done during the assigned duration. This API a prior start acquisition
		 * of the ADC channel, the tester need to care about starting or
		 * stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of average current over 1024 sample.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertFilteredCurrent(CurrentChnl chnl, float current, CurrentUnit unit,
				float tolerancePercent, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertFilteredCurrent(chnl, current, unit, tolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure a filtered current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * <p>
		 * Get filtered current value on a channel by averaging all the readings
		 * done during the assigned duration. This API a prior start acquisition
		 * of the ADC channel, the tester need to care about starting or
		 * stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of average current over 1024 sample.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertFilteredCurrent(CurrentChnl chnl, float current, CurrentUnit unit,
				float tolerancePercent) {
			assertFilteredCurrent(chnl, current, unit, tolerancePercent,
					"Assert filtered current value for channel %s equals %.2f %s with tolerance %.2f", chnl.toString(),
					current, unit.toString(), tolerancePercent);
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertInstantaneousCurrentmA(CurrentChnl chnl, float current, float tolerancePercent,
				String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertInstantaneousCurrent(chnl, current, CurrentUnit.mA, tolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertInstantaneousCurrentmA(CurrentChnl chnl, float current, float tolerancePercent) {
			assertInstantaneousCurrentmA(chnl, current, tolerancePercent,
					"Assert instantaneous current value for channel %s equals %.2f mA with tolerance %.2f",
					chnl.toString(), current, tolerancePercent);
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertInstantaneousCurrent(CurrentChnl chnl, float current, CurrentUnit unit,
				float tolerancePercent, String comment, Object... args) {
			// Util.comment(comment, args);

			C5.currentMeasurement.assertInstantaneousCurrent(chnl, current, unit, tolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertInstantaneousCurrent(CurrentChnl chnl, float current, CurrentUnit unit,
				float tolerancePercent) {
			assertInstantaneousCurrent(chnl, current, unit, tolerancePercent,
					"Assert instantaneous current value for channel %s equals %.2f %s with tolerance %.2f",
					chnl.toString(), current, unit.toString(), tolerancePercent);
		}

		/**
		 * Measure the maximum current value for one channel during desired
		 * duration. This API manages the start and the stop of the ADC channel.
		 * <p>
		 * Get maximum current value on a channel during the assigned duration.
		 * This API manages the start and the stop of the ADC channel, the
		 * tester doesn't need to worry about starting or stopping the ADC
		 * channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Max Measured current from starting
		 * from the start acquisition of this channel to the end of the
		 * acquisition.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 *
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertMaximumCurrent(CurrentChnl chnl, float current, CurrentUnit unit,
				float tolerancePercent, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertMaximumCurrent(chnl, current, unit, tolerancePercent);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the maximum current value for one channel during desired
		 * duration. This API manages the start and the stop of the ADC channel.
		 * <p>
		 * Get maximum current value on a channel during the assigned duration.
		 * This API manages the start and the stop of the ADC channel, the
		 * tester doesn't need to worry about starting or stopping the ADC
		 * channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Max Measured current from starting
		 * from the start acquisition of this channel to the end of the
		 * acquisition.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 *
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param tolerancePercent
		 *            tolerance in measured current in percentage e.g. 3%
		 **/
		public static void assertMaximumCurrent(CurrentChnl chnl, float current, CurrentUnit unit,
				float tolerancePercent) {
			assertMaximumCurrent(chnl, current, unit, tolerancePercent,
					"Assert maximum current value for channel %s equals %.2f %s with tolerance %.2f", chnl.toString(),
					current, unit.toString(), tolerancePercent);
		}

		/**
		 * Start measuring current on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum current values can be acquired at at any time.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The API must be called prior to measuring any current value at a
		 * channel (unless using the APIs checkInstCUrrentAuto or
		 * checkFilteredCurrentAuto). <br/>
		 * 2-Always stop the current channel when not using it so that other
		 * channels work as fast as possible. <br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to start updating its value.
		 **/
		public static void startAcquistion(CurrentChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.startCurrentChannelAcquision(chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * Start measuring current on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum current values can be acquired at at any time.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The API must be called prior to measuring any current value at a
		 * channel (unless using the APIs checkInstCUrrentAuto or
		 * checkFilteredCurrentAuto). <br/>
		 * 2-Always stop the current channel when not using it so that other
		 * channels work as fast as possible. <br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to start updating its value.
		 **/
		public static void startAcquistion(CurrentChnl chnl) {
			startAcquistion(chnl, "Start measuring current on a channel %s", chnl.toString());
		}

		/**
		 * stop measuring current on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum current values will not be updated.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Always stop the current channel when not using it so that other
		 * channels work as fast as possible. 2-When stopping ADC channel, all
		 * previous readings are reset.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to stop updating its value.
		 **/
		public static void stopAcquisition(CurrentChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.stopCurrentChannelAcquisition(chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * stop measuring current on a channel. This API shall be used when the
		 * tester wants to control the ADC channels manually.
		 * <p>
		 * After calling this API, the instantaneous, average, maximum and
		 * minimum current values will not be updated.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Always stop the current channel when not using it so that other
		 * channels work as fast as possible. 2-When stopping ADC channel, all
		 * previous readings are reset.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to stop updating its value.
		 **/
		public static void stopAcquisition(CurrentChnl chnl) {
			stopAcquisition(chnl, "Stop measuring current on a channel %s");
		}

		/**
		 * Get access to the instantaneous current signal. </br>
		 * <p>
		 * This API is intended for advanced testers. </br>
		 * This API doesn't manage the ADC channel, the tester must manage the
		 * start,stop and data reset on his own.
		 * 
		 * @category Preprocessor
		 * @param chnl
		 *            Current channel to get its signal.
		 **/
		@SuppressWarnings("unused")
		private static Itf_SignalValue getInstCurrentSignal(CurrentChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			return C5.currentMeasurement.getInstCurrentSignal(chnl);
		}

		/**
		 * Get access to the average current signal. </br>
		 * <p>
		 * This API is intended for advanced testers. </br>
		 * This API doesn't manage the ADC channel, the tester must manage the
		 * start,stop and data reset on his own.
		 * 
		 * @category Preprocessor
		 * @param chnl
		 *            Current channel to get its signal.
		 **/
		@SuppressWarnings("unused")
		private static Itf_SignalValue getAverageCurrentSignal(CurrentChnl chnl, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			return C5.currentMeasurement.getAverageCurrentSignal(chnl);
		}

		/**
		 * Reset all stored data for a channel.
		 * 
		 * @category Firmware Action
		 **/
		public static void resetMeasuremnents(String comment, Object... args) {

			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.resetMeasuremnents();

			C5.Util.adddefaultPause();
		}

		/**
		 * Reset all stored data for a channel.
		 * 
		 * @category Firmware Action
		 **/
		public static void resetMeasuremnents() {

			resetMeasuremnents("Reset all measurements for current sense module.");
		}

		/**
		 * Assert instantaneously on the value of the duty cycle of the applied
		 * current signal.</br>
		 * The Dutycycle passed shall be multiplied by 1000 e.g. if you want to
		 * assert on duyt cycle of 32.51% then you shall pass 32510.</br>
		 * This API will not wait till the next sampling window and it will get
		 * the reading directly from the FPGA module.</br>
		 * Warning: The channel must be activated using the API
		 * startCurrentacquistion before invoking this API.</br>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param currentDutyCycle
		 *            Current Duty Cylce Value ex.[32.3%]
		 * @param tolerancePercent
		 *            Tolernace in Percentage ex.[5%]
		 **/
		public static void assertCurrentDutyCycle(CurrentChnl chnl, float currentDutyCycle, float tolerancePercent,
				String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			C5.currentMeasurement.assertCurrentDutyCycle(chnl, currentDutyCycle, tolerancePercent);
			C5.Util.adddefaultPause();
		}

		/**
		 * Assert instantaneously on the value of the duty cycle of the applied
		 * current signal.</br>
		 * The Dutycycle passed shall be multiplied by 1000 e.g. if you want to
		 * assert on duyt cycle of 32.51% then you shall pass 32510.</br>
		 * This API will not wait till the next sampling window and it will get
		 * the reading directly from the FPGA module.</br>
		 * Warning: The channel must be activated using the API
		 * startCurrentacquistion before invoking this API.</br>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param currentDutyCycle
		 *            Current Duty Cylce Value ex.[32.3%]
		 * @param tolerancePercent
		 *            Tolernace in Percentage ex.[5%]
		 **/
		public static void assertCurrentDutyCycle(CurrentChnl chnl, float currentDutyCycle, float tolerancePercent) {

			C5.currentMeasurement.assertCurrentDutyCycle(chnl, currentDutyCycle, tolerancePercent);
			C5.Util.adddefaultPause();
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////// APIs for Absolute Tolerance ///////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/**
		 * Measure the frequency current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param frequency
		 *            Frequency values in Hz
		 * @param toleranceAbsolute
		 *            tolerance in measured current in Hz
		 **/
		public static void assertFrequencyCurrentAbs(CurrentChnl chnl, float frequency, float toleranceAbsolute, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertFrequencyCurrentAbs(chnl, frequency, toleranceAbsolute);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the frequency current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param frequency
		 *            Frequency values in Hz
		 * @param toleranceAbsolute
		 *            tolerance in measured current in Hz
		 **/
		public static void assertFrequencyCurrentAbs(CurrentChnl chnl, float frequency, float toleranceAbsolute) {
			assertFrequencyCurrentAbs(chnl,frequency,toleranceAbsolute,
					"Assert frequency current value for channel %s equals %.2f Hz with tolerance %.2f", chnl.toString(),
					frequency, toleranceAbsolute);
		}


		/**
		 * Measure a filtered current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * <p>
		 * Get filtered current value on a channel by averaging all the readings
		 * done during the assigned duration. This API a prior start acquisition
		 * of the ADC channel, the tester need to care about starting or
		 * stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of average current over 1024 sample.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertFilteredCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit,
				float toleranceAbsolute, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertFilteredCurrentAbs(chnl, current, unit, toleranceAbsolute);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure a filtered current value for one channel. This API manages
		 * the start and the stop of the ADC channel.
		 * <p>
		 * Get filtered current value on a channel by averaging all the readings
		 * done during the assigned duration. This API a prior start acquisition
		 * of the ADC channel, the tester need to care about starting or
		 * stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of average current over 1024 sample.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertFilteredCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit,
				float toleranceAbsolute) {
			assertFilteredCurrentAbs(chnl, current, unit, toleranceAbsolute,
					"Assert filtered current value for channel %s equals %.2f %s with tolerance %.2f", chnl.toString(),
					current, unit.toString(), toleranceAbsolute);
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertInstantaneousCurrentmAAbs(CurrentChnl chnl, float current, float toleranceAbsolute,
				String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertInstantaneousCurrentAbs(chnl, current, CurrentUnit.mA, toleranceAbsolute);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertInstantaneousCurrentmAAbs(CurrentChnl chnl, float current, float toleranceAbsolute) {
			assertInstantaneousCurrentmAAbs(chnl, current, toleranceAbsolute,
					"Assert instantaneous current value for channel %s equals %.2f mA with tolerance %.2f",
					chnl.toString(), current, toleranceAbsolute);
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertInstantaneousCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit,
				float toleranceAbsolute, String comment, Object... args) {
			// Util.comment(comment, args);

			C5.currentMeasurement.assertInstantaneousCurrentAbs(chnl, current, unit, toleranceAbsolute);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure a instantaneous current value for one channel. This API will
		 * not manages the start and the stop of the ADC channel.
		 * <p>
		 * Get instantaneous current value on a channel by averaging all the
		 * readings done during the assigned duration. This API a prior start
		 * acquisition of the ADC channel, the tester need to care about
		 * starting or stopping the ADC channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Instantaneous current.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value e.g. 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertInstantaneousCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit,
				float toleranceAbsolute) {
			assertInstantaneousCurrentAbs(chnl, current, unit, toleranceAbsolute,
					"Assert instantaneous current value for channel %s equals %.2f %s with tolerance %.2f",
					chnl.toString(), current, unit.toString(), toleranceAbsolute);
		}

		/**
		 * Measure the maximum current value for one channel during desired
		 * duration. This API manages the start and the stop of the ADC channel.
		 * <p>
		 * Get maximum current value on a channel during the assigned duration.
		 * This API manages the start and the stop of the ADC channel, the
		 * tester doesn't need to worry about starting or stopping the ADC
		 * channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Max Measured current from starting
		 * from the start acquisition of this channel to the end of the
		 * acquisition.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 *
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertMaximumCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit,
				float toleranceAbsolute, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			C5.currentMeasurement.assertMaximumCurrentAbs(chnl, current, unit, toleranceAbsolute);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the maximum current value for one channel during desired
		 * duration. This API manages the start and the stop of the ADC channel.
		 * <p>
		 * Get maximum current value on a channel during the assigned duration.
		 * This API manages the start and the stop of the ADC channel, the
		 * tester doesn't need to worry about starting or stopping the ADC
		 * channel.
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-The used current channel should be enabled before reading.<br/>
		 * 2-The API returns the value of the Max Measured current from starting
		 * from the start acquisition of this channel to the end of the
		 * acquisition.<br/>
		 * 3-The used current channel should be disabled if it is not used.<br/>
		 *
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param current
		 *            current value 1800 mA
		 * @param currentUnit
		 *            unit of current passed (mA, A, uA)
		 * @param toleranceAbsolute
		 *            tolerance in measured current in mA
		 **/
		public static void assertMaximumCurrentAbs(CurrentChnl chnl, float current, CurrentUnit unit,
				float toleranceAbsolute) {
			assertMaximumCurrentAbs(chnl, current, unit, toleranceAbsolute,
					"Assert maximum current value for channel %s equals %.2f %s with tolerance %.2f", chnl.toString(),
					current, unit.toString(), toleranceAbsolute);
		}


		/**
		 * Assert instantaneously on the value of the duty cycle of the applied
		 * current signal.</br>
		 * The Dutycycle passed shall be multiplied by 1000 e.g. if you want to
		 * assert on duyt cycle of 32.51% then you shall pass 32510.</br>
		 * This API will not wait till the next sampling window and it will get
		 * the reading directly from the FPGA module.</br>
		 * Warning: The channel must be activated using the API
		 * startCurrentacquistion before invoking this API.</br>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param currentDutyCycle
		 *            Current Duty Cylce Value ex.[32.3%]
		 * @param tolerancePercent
		 *            Tolernace in Percentage ex.[5%] 
		 *			  if CurrentDuty = 50 and Tolerance = 5
		 *            Check window will be from 45 to 55 %
		 **/
		public static void assertCurrentDutyCycleAbs(CurrentChnl chnl, float currentDutyCycle, float tolerancePercent,
				String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			C5.currentMeasurement.assertCurrentDutyCycleAbs(chnl, currentDutyCycle, tolerancePercent);
			C5.Util.adddefaultPause();
		}

		/**
		 * Assert instantaneously on the value of the duty cycle of the applied
		 * current signal.</br>
		 * The Dutycycle passed shall be multiplied by 1000 e.g. if you want to
		 * assert on duyt cycle of 32.51% then you shall pass 32510.</br>
		 * This API will not wait till the next sampling window and it will get
		 * the reading directly from the FPGA module.</br>
		 * Warning: The channel must be activated using the API
		 * startCurrentacquistion before invoking this API.</br>
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            Current channel to read its value.
		 * @param currentDutyCycle
		 *            Current Duty Cylce Value ex.[32.3%]
		 * @param tolerancePercent
		 *            Tolernace in Percentage ex.[5%] 
		 *			  if CurrentDuty = 50 and Tolerance = 5
		 *            Check window will be from 45 to 55 %
		 **/
		public static void assertCurrentDutyCycleAbs(CurrentChnl chnl, float currentDutyCycle, float tolerancePercent) {

			C5.currentMeasurement.assertCurrentDutyCycleAbs(chnl, currentDutyCycle, tolerancePercent);
			C5.Util.adddefaultPause();
		}

		
		/**
		 * Check the value of one current input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.CurrentSense.CurrentChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Current Input value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnMaxCurrent(CurrentChnl port,EventType type,int value,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			currentMeasurement.checkEventBasedSignalsOnMaxCurrent(port, type, value, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}
		
		/**
		 * Check the value of one current input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.CurrentSense.CurrentChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Current Input value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnAverageCurrent(CurrentChnl port,EventType type,int value,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			currentMeasurement.checkEventBasedSignalsOnAverageCurrent(port, type, value, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}
		
		/**
		 * Check the value of one current input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.CurrentSense.CurrentChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Current Input value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnDutyCycleCurrent(CurrentChnl port,EventType type,int value,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			currentMeasurement.checkEventBasedSignalsOnDutyCycleCurrent(port, type, value, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}
		
		/**
		 * Check the value of one current input Channel to the desired value.
		 * 
		 * @param port
		 *            ID of Channel to be checked. See
		 *            {@link libs.c5.interfaces.C5.CurrentSense.CurrentChnl
		 * @param type
		 *            Check the event type transition or level. See
		 *            {@link libs.c5.interfaces.C5.Util.EventType
		 * Channels Enum
		 * @param value
		 *            Current Input value to be reached
		 * @param evTime
		 *            time out for event in mSec
		 * @param evTimeTolerance
		 *            timeoutTolerance in mSec           		           
		 * @category Firmware Action
		 */
		public static void checkEventBasedSignalsOnInstantenousCurrent(CurrentChnl port,EventType type,int value,int evTime,int evTimeTolerance, String comment,
				Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			currentMeasurement.checkEventBasedSignalsOnInstantenousCurrent(port, type, value, evTime, evTimeTolerance);

			C5.Util.adddefaultPause();
		}
	}

	/**
	 * Standard library APIs to be used in RS232 communications.
	 *
	 * <p>
	 * C5 Bench has to RS232 lines; RS232_0 and RS232_1. The first one is -by
	 * default- used to control remote power supply. <br>
	 * Accordingly, the tester shall use the second line RS232_1 when
	 * communicating with the ECU.
	 * 
	 * 
	 * @version 1.0
	 */
	public static class RS232 {

		/**
		 * Reset the latest value of both the data and the type signals to zero.
		 */
		public static void platformResetSignals(String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			rs232.platformResetSignals();
			C5.Util.adddefaultPause();
		}

		/**
		 * Reset the latest value of both the data and the type signals to zero.
		 */
		public static void platformResetSignals() {
			platformResetSignals(" Reset the latest value of both the data and the type signals to zero.");
		}

		/**
		 * Enable/Disable logging when receiving a message following the VLS
		 * platofrm protocol.
		 * 
		 * @param enable
		 */
		public static void platformLogEnable(boolean enable, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			rs232.platformLogEnable(enable);
			C5.Util.adddefaultPause();
		}

		/**
		 * Enable/Disable logging when receiving a message following the VLS
		 * platofrm protocol.
		 * 
		 * @param enable
		 */
		public static void platformLogEnable(boolean enable) {
			platformLogEnable(enable, "Set logging when receiving a message following the VLS platofrm protocol to %s",
					String.valueOf(enable));
		}

		public static String asciiToHex(String ascii) {
			return rs232.asciiToHex(ascii);
		}

		/**
		 * Get the data signal.
		 * 
		 * @return
		 */
		public static Itf_SignalValue dataSignal() {
			return rs232.data();
		}

		/**
		 * Get the type signal.
		 * 
		 * @return
		 */
		public static Itf_SignalValue typeSignal() {
			return rs232.type();
		}

		/**
		 * Set the baud rate for a given RS232 channel and enable the
		 * transmission lines.
		 * 
		 * @param _Baudrate
		 *            Baudrate
		 */
//		public static void setBaudRate(Enme_baudrate _Baudrate, String comment, Object... args) {
//			Util.commentNxtFunctionCall(comment, args);
//
//			rs232.setBaudRate(_Baudrate);
//			C5.Util.adddefaultPause();
//		}
//
//		/**
//		 * Set the baud rate for a given RS232 channel and enable the
//		 * transmission lines.
//		 * 
//		 * @param _Baudrate
//		 *            Baudrate
//		 */
//		public static void setBaudRate(Enme_baudrate _Baudrate) {
//			setBaudRate(_Baudrate, "Set the baud rate for a to %s", _Baudrate.toString());
//		}

		/**
		 * Tests the buffer for a given sequence of bytes. In case of error a
		 * message with the current buffer content is logged.
		 * <p>
		 * Note that the buffer can be reset @see
		 * 
		 * 
		 * @param offset
		 * @param msg
		 */
		public static void assertMsg(int offset, String msg, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			rs232.assertMsg(offset, msg);
			C5.Util.adddefaultPause();
		}

		/**
		 * Tests the buffer for a given sequence of bytes. In case of error a
		 * message with the current buffer content is logged.
		 * <p>
		 * Note that the buffer can be reset @see
		 * 
		 * 
		 * @param offset
		 * @param msg
		 */
		public static void assertMsg(int offset, String msg) {
			assertMsg(offset, msg, "Assert the message buffer starting from %d to be %s", offset, msg);
		}

		/**
		 * Log the current message stored in the buffer.
		 * <p>
		 * Note that the buffer can be reset @see
		 */
		public static void logMsg(String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			rs232.logMsg();
			C5.Util.adddefaultPause();
		}

		/**
		 * Log the current message stored in the buffer.
		 * <p>
		 * Note that the buffer can be reset @see
		 */
		public static void logMsg() {
			logMsg("Log the current message stored in the buffer.");
		}

		/**
		 * Reset the buffer contents. Note that the buffer has a maximum length
		 * currently set to 200 character and a buffer overrun error is reported
		 * in case buffer not cleared.
		 */
		public static void resetRxBuffer(String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			rs232.resetRxBuffer();
			C5.Util.adddefaultPause();
		}

		/**
		 * Reset the buffer contents. Note that the buffer has a maximum length
		 * currently set to 200 character and a buffer overrun error is reported
		 * in case buffer not cleared.
		 */
		public static void resetRxBuffer() {
			resetRxBuffer("Reset the rs232 buffer contents.");
		}

		/**
		 * Send the message on the rs232 bus.
		 * 
		 * @param msg
		 */
		public static void send(String msg, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			rs232.send(msg);
			C5.Util.adddefaultPause();
		}

		/**
		 * Send the message on the rs232 bus.
		 * 
		 * @param msg
		 */
		public static void send(String msg) {
			send(msg, "Send the message on the rs232 bus %s", msg);
		}

	}

	/**
	 * This class is standard library APIs to be used in measuring voltage.
	 *
	 * <p>
	 * C5 PIP V2 has 2 voltage channel that can be used to measure voltage. This
	 * library provides APIs for measuring instantaneous voltage, filtered
	 * voltage, average voltage.
	 *
	 * @author Wesam Khattb
	 * @version 1.0
	 */
	public static class MotorMeasurement {
		/**
		 * C5 PIP V2 has 2 Voltage channel that can be used to measure Voltage.
		 */
		public enum MotorType {
			/**
			 * Voltage Sense Channel 1.
			 * <p>
			 * Connection : <br/>
			 * *Product Analog Output 1 <br/>
			 * *P16 Pin 09<br/>
			 */
			LVL,
			/**
			 * Voltage Sense Channel 2.
			 * <p>
			 * Connection :<br/>
			 * *Product Analog Output 2 <br/>
			 * *P16 Pin 10<br/>
			 */
			DBL,
			/**
			 * Voltage Sense Channel 2.
			 * <p>
			 * Connection :<br/>
			 * *Product Analog Output 2 <br/>
			 * *P16 Pin 10<br/>
			 */
			ADB,
		}

		/**
		 * Start the measurement on the requested motor ID
		 * <p>
		 * Start Measurement of the steps and the speed indexes. 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-If the motor is not used Stop the motor measurement for increasing
		 *   Castle performance.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 **/
		public static void startMotorMeasurement(MotorType chnl,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.startMotorMeasurement(chnl);

			C5.Util.adddefaultPause();
		}

		/**
		 * Stop the measurement on the requested motor ID
		 * <p>
		 * Stop Measurement of the steps and the speed indexes. 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-If the motor is not used Stop the motor measurement for increasing
		 *   Castle performance.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 **/
		public static void stopMotorMeasurement(MotorType chnl,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.stopMotorMeasurement(chnl);

			C5.Util.adddefaultPause();
		}



		/**
		 * Measure the speed index of the requested motor
		 * <p>
		 * measure the requested motor speed index 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param speedIndex
		 *            index of the speed to be measured            
		 * @param speed
		 *            value of the speed to be measured             
		 * @param speedTolerance
		 *            tolerance value of the speed to be measured            
		 **/
		public static void checkSpeedIndexInQs(MotorType chnl,int speedIndex,int speed,float speedTolerance,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkSpeedIndexInQs(chnl, speedIndex, speed, speedTolerance);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the speed index of the requested motor
		 * <p>
		 * measure the requested motor speed index 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param speedIndex
		 *            index of the speed to be measured            
		 * @param speed
		 *            value of the speed to be measured             
		 * @param speedTolerance
		 *            tolerance value of the speed to be measured            
		 **/

		public static void checkSpeedIndexInHs(MotorType chnl,int speedIndex,int speed,float speedTolerance,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkSpeedIndexInHs(chnl, speedIndex, speed, speedTolerance);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the speed index of the requested motor
		 * <p>
		 * measure the requested motor speed index 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param speedIndex
		 *            index of the speed to be measured            
		 * @param speed
		 *            value of the speed to be measured             
		 * @param speedTolerance
		 *            tolerance value of the speed to be measured            
		 **/
		public static void checkSpeedIndexInFs(MotorType chnl,int speedIndex,int speed,float speedTolerance,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkSpeedIndexInFs(chnl, speedIndex, speed, speedTolerance);

			C5.Util.adddefaultPause();
		}


		/**
		 * Measure the step counts of the requested motor
		 * <p>
		 * measure number of step counts for the requested 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param speedIndex
		 *            index of the speed to be measured            
		 * @param steps
		 *            value of the speed to be measured             
		 * @param stepsTolerance
		 *            tolerance value of the speed to be measured            
		 **/
		public static void checkStepCountsInQs(MotorType chnl,int steps,float stepsTolerance,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkStepCountsInQs(chnl, steps, stepsTolerance);

			C5.Util.adddefaultPause();
		}


		/**
		 * Measure the step counts of the requested motor
		 * <p>
		 * measure number of step counts for the requested 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param speedIndex
		 *            index of the speed to be measured            
		 * @param steps
		 *            value of the speed to be measured             
		 * @param stepsTolerance
		 *            tolerance value of the speed to be measured            
		 **/
		public static void checkStepCountsInHs(MotorType chnl,int steps,float stepsTolerance,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkStepCountsInHs(chnl, steps, stepsTolerance);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the step counts of the requested motor
		 * <p>
		 * measure number of step counts for the requested 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param speedIndex
		 *            index of the speed to be measured            
		 * @param steps
		 *            value of the speed to be measured             
		 * @param stepsTolerance
		 *            tolerance value of the speed to be measured            
		 **/
		public static void checkStepCountsInFs(MotorType chnl,int steps,float stepsTolerance,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkStepCountsInFs(chnl, steps, stepsTolerance);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the number of phases the motor had moved
		 * <p>
		 * Measure the number of phases the motor had moved 
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param speedIndex
		 *            index of the speed to be measured            
		 * @param numberOfPhases
		 *            measure number of phases the mototr had moved          
		 **/
		public static void checkNumberOfPhases(MotorType chnl,int numberOfPhases,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkNumberOfPhases(chnl, numberOfPhases);

			C5.Util.adddefaultPause();
		}

		/**
		 * Measure the step counts of the requested motor per each phase
		 * <p>
		 * Measure the step counts of the requested motor per each phase
		 * <p>
		 * Warnings:
		 * <p>
		 * 1-Motor must be started before measuring the speed test.
		 * 
		 * @category Firmware Action
		 * @param chnl
		 *            motor channel to measure the speed and the steps.
		 * @param phaseIndex
		 *            phase index of the steps to be measured            
		 * @param steps
		 *            value of the speed to be measured             
		 * @param stepsTolerance
		 *            tolerance value of the speed to be measured            
		 **/
		public static void checkStepsPerPhaseHs(MotorType chnl,int phaseIndex,int steps,float stepsTolerance,String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);

			motors.checkStepsPerPhaseHs(chnl, phaseIndex, steps, stepsTolerance);

			C5.Util.adddefaultPause();
		}

	}


	public static class Util {
		private static double dynamicPauseTime = 1;

		/**
		 * Digital output logic values.
		 * <P>
		 * Note that PIP V1 supChannels changing the high logic to 3.3 or 12
		 * volt but the value is output logic value is set to 5 volt by default.
		 * The tester shall not change the
		 */
		public enum EventType {
			/** Low logic is Zero Volt with strong zero */
			Edge,
			/** High logic is 5 Volt with strong one */
			Level
		}
		
		/**
		 * C5 Signal Factors.
		 */
		public enum SignalFactor {
			/**
			 * LIN Signal Factor.
			 * <p>
			 * Factor : <br/>
			 * *Factor Value = 1 <br/>
			 */
			Lin_Signal_Factor,
			/**
			 * CAN Signal Factor.
			 * <p>
			 * Factor : <br/>
			 * *Factor Value = 1 <br/>
			 */
			CAN_Signal_Factor,
			/**
			 * Current Signal Factor.
			 * <p>
			 * Factor : <br/>
			 * *Factor Value = 1 <br/>
			 */
			CURRENT_Signal_Factor,
			/**
			 * Voltage Signal Factor.
			 * <p>
			 * Factor : <br/>
			 * *Factor Value = 1 <br/>
			 */
			VOLTAGE_Signal_Factor,
			/**
			 * Digital Signal Factor.
			 * <p>
			 * Factor : <br/>
			 * *Factor Value = 1 <br/>
			 */
			DIGITAL_IN_Signal_Factor,
			/**
			 * Pwm_In Duty Signal Factor.
			 * <p>
			 * Factor : <br/>
			 * *Factor Value = 10 <br/>
			 */
			PWM_IN_Duty_Signal_Factor,
			/**
			 * Pwm_In Freq Signal Factor.
			 * <p>
			 * Factor : <br/>
			 * *Factor Value = 1 <br/>
			 */
			PWM_IN_Freq_Signal_Factor,
		}
		/**
		 * Create a pause in execution for this amount of time
		 * 
		 * @param timeMs
		 *            in milliseconds. Must be >= 0. If 0 is passed, this
		 *            returns without action.
		 * @throws RuntimeException
		 *             when timeMs is negative
		 */
		public static void pause(double timeMs) {
			if (dynamicPauseEnable) {

				int result = Double.compare(timeMs - pausedTime, 0);

				if (result < 0)
					Assert.fail("Invalid pause time requsted, the minimum pause time is %f ms in the library.",
							dynamicPauseTime);

				timeMs -= pausedTime;
			}

			C5.utilities.pauseMilliSec(timeMs);
			pausedTime = 0;
		}

		private static void adddefaultPause() {
			if (dynamicPauseEnable) {
				C5.Util.pause(dynamicPauseTime);
				pausedTime = dynamicPauseTime;
			}else{
				pausedTime = 0;
			}

		}

		public static void setDynamicPause(boolean state) {
			dynamicPauseEnable = state;
		}

		public static void setDynamicPauseTime(double msec) {
			int result = Double.compare(msec, 1);
			if (result < 0)
				Assert.fail("Invalid pause time requsted, the minimum pause time is 1 msec in the library.");

			dynamicPauseTime = msec;
		}

		/**
		 * Post a comment to the CTE logging sequence.
		 * 
		 * @param comment
		 *            String with the comment to be added.
		 * @param args
		 *            List of arguments if needed.
		 */
		private static void commentNxtFunctionCall(String comment, Object... args) {

			if (comment == null)
				return;
			else
				C5.exu.commentNextFuncCall(comment, args);

		}

		/**
		 * Post a comment to the CTE logging sequence.
		 * 
		 * @param comment
		 *            String with the comment to be added.
		 * @param args
		 *            List of arguments if needed.
		 */
		public static void comment(String comment, Object... args) {

			if (comment == null) {
				return;
			} else {
				C5.exu.comment(comment, args);

				adddefaultPause();
			}

		}

		/**
		 * Post a comment to the CTE logging sequence. All the firmware actions
		 * with no comment following to this comment will be added below it.
		 * 
		 * @param comment
		 *            String with the comment to be added.
		 * @param args
		 *            List of arguments if needed.
		 */
		public static void commentAction(String comment, Object... args) {

			if (comment == null) {
				return;
			} else {
				C5.exu.comment(comment, args);

				adddefaultPause();
			}

		}

		/**
		 * Add one entry to the context comment stack.<br/>
		 * For each {@link #commentLevelEnter(String, Object...)} there shall be
		 * a matching call to {@link #commentLevelLeave()}.</br>
		 *
		 * @param fmt
		 *            a format string like it is used in
		 *            {@link String#format(String, Object...)}
		 * @param args
		 *            optional argument, like they are used in
		 *            {@link String#format(String, Object...)}
		 */
		@SuppressWarnings("unused")
		private static void writeCommenttLevelEnter(String comment, Object... args) {

			C5.exu.commentLevelEnter(comment, args);

		}

		/**
		 * wait for an event to happen or time out happens.<br/>
		 * 
		 * @param event
		 *            Event to wait until it trigger the bench.
		 * @param timeout
		 *            max time to wait before continue the execuiton.
		 * @param comment
		 *            String with the comment to be added.
		 * @param args
		 *            List of arguments if needed.
		 */
		@SuppressWarnings("unused")
		private static void pauseUntilEvent(IEvent event, double timeout,String comment, Object... args) {

			Util.commentNxtFunctionCall(comment, args);

			C5.exu.pauseUntilEvent(event, timeout);

			C5.Util.adddefaultPause();
		}

		/**
		 * Removes one level of the context comment stack.</br>
		 * <b>Note:</b> This is only allowed in direct mode or in the main HIL
		 * thread.
		 *
		 */
		@SuppressWarnings("unused")
		private static void writeCommenttLevelLeave() {

			C5.exu.commentLevelLeave();

		}

		/**
		 * Convert unit to Kilo unit.
		 */
		public static int convertToKilo(double fractionUnint) {

			return C5.utilities.convertToKilo(fractionUnint);

		}

		/**
		 * Convert unit to Mili unit.
		 */
		public static double convertToMili(int integerUnint) {

			return C5.utilities.convertToMili(integerUnint);

		}

	}

	public static class DifferentialUARt {

		/**
		 * This functions clears UART-CAN Receive Buffer
		 **/

		public static void ResetRxBuffer(String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			differentialUART.ResetRxBuffer();
			C5.Util.adddefaultPause();
		}

		/**
		 * This functions clears UART-CAN Receive Buffer
		 **/

		public static void ResetRxBuffer() {
			C5.DifferentialUARt.ResetRxBuffer("clears UART-CAN Receive Buffer");
		}

		/**
		 * Send data on the CAN bus as raw frame without any headers -only raw frame but
		 * with CAN physical layer (differential)-. This call is by passing the normal
		 * signal processing
		 * 
		 * @category Firmware Action
		 * @param frame
		 *            frame data to send on can bus.
		 **/

		public static void TxOnlyRawFrame(String frame, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			differentialUART.TxOnlyRawFrame(frame);
			C5.Util.adddefaultPause();
		}

		/**
		 * Send data on the CAN bus as raw frame without any headers -only raw frame but
		 * with CAN physical layer (differential)-. This call is by passing the normal
		 * signal processing
		 * 
		 * @category Firmware Action
		 * @param frame
		 *            frame data to send on can bus.
		 **/

		public static void TxOnlyRawFrame(String frame) {
			C5.DifferentialUARt.TxOnlyRawFrame(frame, "Send data on the CAN bus as raw frame");
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

		public static void AssertSequence(String frame, String comment, Object... args) {
			Util.commentNxtFunctionCall(comment, args);
			differentialUART.AssertSequence(frame);
			C5.Util.adddefaultPause();
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

		public static void AssertSequence(String frame) {
			C5.DifferentialUARt.AssertSequence(frame, "Compares the frame received with the frame passed");
		}

	}

	public static void pause(double msec) {
		C5.Util.pause(msec);

	}
}
