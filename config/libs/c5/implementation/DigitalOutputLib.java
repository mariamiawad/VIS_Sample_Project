package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import config.ETS;
import config.ItfDO;
import config.ItfDO.EnmBank;
import config.ItfDO.EnmDigitalOutChannels;
import config.ItfDO.EnmVolt;
import libs.c5.interfaces.C5.DigitalOutput.DigitalOutputBanks;
import libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels;
import libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue;
import libs.c5.interfaces.C5.DigitalOutput.HighLogicValue;


/**
 * This class is implementation of standard library APIs to be used in
 * controlling digital output pins.
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class DigitalOutputLib implements ILib {

	ETS exu;
	/** digital output object to be used as for direct FW APIs access */
	private  ItfDO doObj;

	
	/**
	 * Class Constructors
	 **/
	public DigitalOutputLib() {
		this.exu = (ETS) exu;
		this.doObj = this.exu.modTS().objDOutput();
	}

	public DigitalOutputLib(IExu exu) {
		this.exu = (ETS) exu;
		this.doObj = this.exu.modTS().objDOutput();
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

	private ItfDO getObj() {
		return this.doObj;
	}

/**
	 * Set one digital output port to the desired value.
	 *  
	 * 
	 * @param port
	 *            ID of port to set its output. See {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels Ports Enum
	 * @param digValue
	 *            Digital output value. See {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue Digital output values enum
	 * @category Firmware Action
	 * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputChannels Ports Enum
     * @see {@link libs.c5.interfaces.C5.DigitalOutput.DigitalOutputValue Digital output values enum
     * @see {@link STD_Libraries.Implementation.DigitalOutput#setArrayPins Set array of digital pins
     * @see {@link STD_Libraries.Implementation.DigitalOutput#setAllPinsHigh Set All pins to high
     * @see {@link STD_Libraries.Implementation.DigitalOutput#setAllPinsLow Set All pins to low
	 */
	public void setDigitalOutputPin(DigitalOutputChannels port, DigitalOutputValue digValue) {
		// index starts from zero
		EnmDigitalOutChannels channel = getDigitalOutChannel(port);
		boolean state = getDigitalOutState(digValue);
		
		this.getObj().afcSetPortOutput(state, channel);
	}
	

    /**
     *  This Function sets the voltage level for output Port [Bank].
     *             
     * @see <a href="C5_VLS.html#ItfDO/fncsetBankVolt">HTML doc: config/data/C5_VLS.html#ItfDO/fncsetBankVolt</a>
     * @param _BankID {@link EnmBank} 
     * @param _Volt {@link EnmVolt} 
     */
    public void setPortVolt(DigitalOutputBanks BankID, HighLogicValue HighLogicVolt)
    {
    	int index = Arrays.asList(DigitalOutputBanks.values()).indexOf(BankID);
    	EnmBank portId = EnmBank.values()[index];
    	
       	index = Arrays.asList(HighLogicValue.values()).indexOf(HighLogicVolt);
    	EnmVolt logicVoltage = EnmVolt.values()[index];
    	
    	this.getObj().afcsetBankVolt(portId, logicVoltage);
    }
    

    private EnmDigitalOutChannels getDigitalOutChannel(DigitalOutputChannels port)
    {
    	int index = Arrays.asList(DigitalOutputChannels.values()).indexOf(port);
    	return EnmDigitalOutChannels.values()[index];
    }
    
    private boolean getDigitalOutState(DigitalOutputValue digValue)
    {
		int logicOut = Arrays.asList(DigitalOutputValue.values()).indexOf(digValue);
    	boolean out;
    	
		if(logicOut ==0)
		{
			out=false;
		}
		else
		{
			out=true;
		}
		return out;
    }
    
    
}
