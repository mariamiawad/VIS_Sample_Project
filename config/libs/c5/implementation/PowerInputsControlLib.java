package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import castle.util.Assert;
import config.ETS;
import config.ItfPowerControl;
import config.ItfPowerControl.EnmPowerInputChannel;
import config.ItfPowerControl.EnmPowerSource;
import libs.c5.implementation.UtilitiesLib.Rational;
import libs.c5.interfaces.C5.PowerInputs.PowerInput;
import libs.c5.interfaces.C5.PowerInputs.PowerInputState;
import libs.c5.interfaces.C5.PowerSupply.SupplyID;

/**
 * This class is standard library APIs to be used in controlling inputs used for
 * powering the ECU.
 *
 * <p>
 * Any of the power inputs can either be connected to constant power supply ,
 * variable power supply or open circuit. Also this library can be used to
 * create power PWM signal by modulating the use input supply (constant or
 * variable).
 *
 * <p>This class must not be used directly by testers (only firmware team). 
 * <p>SVN Path:
 *
 * @author  Hisham ElMeligi
 * @version 1.0    
 */
public class PowerInputsControlLib implements ILib {

	/**
	 * Class Variables
	 **/

	
	/** Default Values for the DC signals */
	private final int DC_DUTY = 0;
	private final int DC_FREQ = 0;
	private final int DC_FREQ_DIV = 1;
	private final int DC_DUTY_DIV = 1;
	
	/** Power input control object to be used as for direct FW APIs access */
	private ItfPowerControl picObj;
	ETS exu;

	/**
	 * Class Constructors
	 **/
	public PowerInputsControlLib() {
		this.picObj = exu.modTS().objPowerControl();
	}

	public PowerInputsControlLib(IExu exu) {
		this.exu = (ETS) exu;
		this.picObj = this.exu.modTS().objPowerControl();
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
	 * Get the power input control object for the main PIM (modTS).
	 * 
	 * <p>
	 * The direct access to the module object instead of using the library APIs
	 * enables performing custom commands.
	 * 
	 * @category Preprocessor
	 * @return picObj Instance from ItfPowerControl to be used for direct access
	 *         to firmware APIs instead of the library implementation.
	 */
	public ItfPowerControl getObj() {
		return this.picObj;
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
	
	
	/**
	 * Connect desired channel to the constant power supply source.
	 * 
	 * <p>
	 * The physical connection is done between the desired channel found on the
	 * extension board from the connectors (J3,J7,J9,j11,J13) to the connector
	 * (J1). Accordingly, the tester shall connect the power supply channel that
	 * shall be used for nominal operation to the (J1) connector. So, the naming
	 * "connect to constant supply" is a logical connection.
	 * 
	 * @param enuChnl
	 *      Power Input Channel Index
	 * @param enuState
	 *  	Power Input state [(DC-Ch1)(DC-Ch2)(PWM-Ch1)(PWM-Ch2)(OC)]  
	 *  
	 * @category Firmware Action
	 * @see {@link prj.Specific_Tests.Library_Tests.Power_Inputs.SimpleExample 
	 * 		 #task Example}
	 * @see {@link libs.c5.interfaces.C5.PowerInputs.PowerInput}
	 * @see {@link libs.c5.interfaces.C5.PowerInputs.PowerInputState}
	 */
	public void setPowerInputChannelMode(PowerInput enuChnl,PowerInputState enuState) {
		
	    EnmPowerInputChannel chnl = getEnmChnl(enuChnl);
	    EnmPowerSource	channelState = getEnmChannelState(enuState);
	    
	 //   this.disablePWMChnl(chnl);
		this.getObj().afcConnectInputPowerChannel(chnl,
				channelState);
	}
	
	
	/**
	 * Connect desired channel to the constant power supply source.
	 * 
	 * <p>
	 * The physical connection is done between the desired channel found on the
	 * extension board from the connectors (J3,J7,J9,j11,J13) to the connector
	 * (J1). Accordingly, the tester shall connect the power supply channel that
	 * shall be used for nominal operation to the (J1) connector. So, the naming
	 * "connect to constant supply" is a logical connection.
	 * 
	 * @param enuChnl
	 *      Power Input Channel Index
	 * @param enuState
	 *  	Power Input state [(PWM-Ch1)(PWM-Ch2)]  
	 * @param frequencyHz
	 * 		Frequency of the Power PWM signal if the mode is (PWM-Ch1)(PWM-Ch2)
	 * @param dutyCyclePercent 
	 *      Duty Cycle of the Power PWM signal if the mode is (PWM-Ch1)(PWM-Ch2)
	 *      
	 * @category Firmware Action
	 * @see {@link prj.Specific_Tests.Library_Tests.Power_Inputs.SimpleExample 
	 * 		 #task Example}
	 * @see {@link libs.c5.interfaces.C5.PowerInputs.PowerInput}
	 * @see {@link libs.c5.interfaces.C5.PowerInputs.PowerInputState}
	 */
	public void setPwmPowerInputChannelMode(PowerInput enuChnl,PowerInputState enuState,double frequencyHz,double dutyCyclePercent) {
		
	    EnmPowerInputChannel chnl = getEnmChnl(enuChnl);
	    EnmPowerSource	channelState = getEnmChannelState(enuState);
	    
	    if(channelState == EnmPowerSource.PowerSupply1_PWM || channelState == EnmPowerSource.PowerSupply2_PWM )
	    {
		   //this.disablePWMChnl(chnl);
		    setChnlPWM(enuChnl,frequencyHz,dutyCyclePercent);
			this.getObj().afcConnectInputPowerChannel(chnl,
					channelState);
	    }
	    else
	    {	
			Assert.fail("The Channel State is not compatible with the PWM mode");
	    }
	}
	
		
	
	
	/**
	 * Connect desired channel to the constant power supply source.
	 * 
	 * <p>
	 * This API is generated for the [C3-C5] migration 
	 * 
	 * @param enuSuppCh ID of supply channel to connect to.
	 * @param enuChnl ID of power input channel to connect to.
	 * @category Firmware Action
	 */
	public void castle3ConnectChnlToSupply( SupplyID enuSuppCh ,PowerInput enuChnl) {
		EnmPowerSource suppSource;
		
		if(enuSuppCh == SupplyID.S1)
		{
			suppSource = EnmPowerSource.PowerSupply1_DC;	
		}
		else
		{
			suppSource = EnmPowerSource.PowerSupply2_DC;
		}
		
		this.setChnl(enuChnl, suppSource);
		
	}

	
	/**
	 * Set desired channel to be connected to any desired state.
	 * 
	 * @param dacChannel
	 *            Array channel to be connected to desired state.
	 * @param source
	 *            Power source to be connected to channel.
	 * @category Firmware Action
	 * @see {@link prj.Specific_Tests.Library_Tests.Power_Inputs.SetChnlandState#task
	 *      Example
	 */
	private void setChnl(PowerInput enuChnl, EnmPowerSource source) {
	    	
	        EnmPowerInputChannel chnl = getEnmChnl(enuChnl);
		this.getObj().afcConnectInputPowerChannel(chnl, source);
	}

	
	private EnmPowerInputChannel getEnmChnl(PowerInput chnl) {

		int index = Arrays.asList(PowerInput.values()).indexOf(chnl);

		if (index > 7 || index < 0) {
			Assert.fail("getIndexChnl:Invalid Power Input channel index used !!");
		}

		return EnmPowerInputChannel.values()[index];

	}
	
	
	private EnmPowerSource getEnmChannelState(PowerInputState chnl) {

		int index = Arrays.asList(PowerInputState.values()).indexOf(chnl);

		if (index > 5 || index < 0) {
			Assert.fail("getIndexChnl:Invalid Power Input channel State !!");
		}

		return EnmPowerSource.values()[index];
	}

	private void setChnlPWM(PowerInput enuChnl, double frequencyHz,
			double dutyCyclePercent) {
		double frequencyKHz = (frequencyHz / 1000.0);

		dutyCyclePercent = Math.abs(100 - dutyCyclePercent);
		
		Rational dutyRational = new Rational(dutyCyclePercent);
		Rational freqRational = new Rational(frequencyKHz);
		
	        EnmPowerInputChannel chnl = getEnmChnl(enuChnl);
		
		this.getObj().afcConfigurePowerPwm(chnl,
		/* Duty */
		dutyRational.getNum(),
		/* Freq */
		freqRational.getNum(),
		/* FrequencyDivisor */
		freqRational.getDenom(),
		/* DutyDivisor */
		dutyRational.getDenom());

	}
	

	/**
	 * Remove PWM signal from desired channel.
	 * 
	 * @param chnl ID of channel to connect to disabled PWM signal on it.
	 * @category Firmware Action
	 * @see {@link prj.Specific_Tests.Library_Tests.Power_Inputs.PWMSupplyAllChnls#task Example
	 * @see  {@link libs.c5.implementation.PowerInputsControlLib#DisablePWMAllChnls Disable PWM on all channels at once.
     * @see  {@link libs.c5.implementation.PowerInputsControlLib#SetPWMChnl Enable PWM on a channel.	 
	 */
	public void disablePWMChnl(EnmPowerInputChannel chnl) {

		this.getObj().afcConfigurePowerPwm(chnl, DC_DUTY, DC_FREQ, DC_FREQ_DIV, DC_DUTY_DIV);
	}

}
