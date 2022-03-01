package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import castle.util.Assert;
import config.ETS;
import config.ItfDAC;
import config.ItfDAC.EnmDacChnls;
import config.ItfDAC.EnmMuxChnls;
import config.ItfDAC.EnmMuxStates;
import libs.c5.interfaces.C5.DAC.DacChnl;
import libs.c5.interfaces.C5.DAC.DacVoltageUnit;
import libs.c5.interfaces.C5.DAC.MuxDacChannels;
import libs.c5.interfaces.C5.DAC.MuxOut;

/**
 * This class is standard library APIs to be used in controlling DACs.
 *
 * <p>
 * PIP V1 board has 16 DAC channel; 8 channels can generate voltage from 0 to 15
 * volt and the other eight can only generate voltage from zero to 5 volt.
 *
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Hisham ElMeligi
 * @version 1.0
 */
public class DACLib implements ILib {

	/** Power input control object to be used as for direct FW APIs access */
	private ItfDAC dacObj;

	/** Values of maximum output for each DAC channel */
	private final int DAC_CHNLS_MAX_VOLT = 12000;

	/** Execution Unit corresponding to this library instance */
	ETS exu;

	/**
	 * Class Constructors
	 **/
	public DACLib() {
		this.dacObj = exu.modTS().objDAC();
	}

	public DACLib(IExu exu) {
		this.exu = (ETS) exu;
		this.dacObj = this.exu.modTS().objDAC();

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

	/**
	 * Set one DAC channel output to the desired value in volt. e.g.
	 * setChnlMilliVolt(DACChnls.Chnl01, 1.5).
	 * 
	 * <p>
	 * Set the output of a channel to the desired value.Note that PIP V2 board
	 * has 16 DAC channel can generate voltage from 0 to 12 volt
	 * 
	 * @param chnl
	 *            ID of channel to set its output.
	 * @param volt
	 *            Output value in volt e.g. 1.75 volt.
	 * @category Firmware Action
	 * @see {@link libs.c5.interfaces.C5.DAC.DacChnl}
	 */
	public void setDacChannelVolt(DacChnl chnl, double volt,DacVoltageUnit unit) {
		
		EnmDacChnls channel = this.getEnmChnl(chnl);
		
		int mVvoltage = getVoltagemV(volt, unit);
		
		if (mVvoltage > DAC_CHNLS_MAX_VOLT || mVvoltage < 0) {
			Assert.fail("setDacChannelVolt: The requested DAC voltage is out of the acceptable range");
		}
		
		this.getObj().afcsetVoltage(mVvoltage, channel);
		
	}
	
	
	/**
	 * Set one DAC channel output to the desired value in volt. e.g.
	 * setChnlMilliVolt(DACChnls.Chnl01, 1.5).
	 * 
	 * <p>
	 * Set the output of a channel to the desired value.Note that PIP V1 board
	 * has 16 DAC channel; 8 channels can generate voltage from 0 to 15 volt and
	 * the other eight can only generate voltage from zero to 5 volt.
	 * 
	 * @param chnl
	 *            ID of channel to set its output.
	 * @param volt
	 *            Output value in volt e.g. 1.75 volt.
	 * @category Firmware Action
	 * @see {@link libs.c5.implementation.DACLib#getDacSource Get DAC Pin Source}
	 * @see {@link libs.c5.implementation.DACLib#getMuxDacChnl Get Mux DAC Pin Source
	 *      maximum output for a channel.}
	 * @see {@link libs.c5.interfaces.C5.DAC.MuxDacChannels}
	 * @see {@link libs.c5.interfaces.C5.DAC.MuxOut}
	 */
	public void setDacPinSource(MuxDacChannels chnl, MuxOut selector) {
		
		EnmMuxStates source = this.getDacSource(selector);
		EnmMuxChnls channel = this.getMuxDacChnl(chnl);
		
		
		
		this.getObj().afcsetDacMux(channel,source);
		
	}



	private EnmMuxChnls getMuxDacChnl(MuxDacChannels chnl) {

		int index = Arrays.asList(MuxDacChannels.values()).indexOf(chnl);

		if (index > 15 || index < 0) {
			Assert.fail("getIndexChnl:Invalid DAC channel index used !!");
		}

		return EnmMuxChnls.values()[index];

	}
	
	private EnmDacChnls getEnmChnl(DacChnl chnl) {

		int index = Arrays.asList(DacChnl.values()).indexOf(chnl);

		if (index > 15 || index < 0) {
			Assert.fail("getIndexChnl:Invalid DAC channel index used !!");
		}

		return EnmDacChnls.values()[index];

	}

	
	private EnmMuxStates getDacSource(MuxOut source) {

		int index = Arrays.asList(MuxOut.values()).indexOf(source);

		return EnmMuxStates.values()[index];

	}
	
	private int getVoltagemV(double voltage, DacVoltageUnit unit) {
		double scale = 1;

		if (unit == DacVoltageUnit.V) {
			scale = 1000.0;
		} else if (unit == DacVoltageUnit.mV) {
			scale = 1.0;
		} else if (unit == DacVoltageUnit.uV) {
			scale = 1 / 1000.0;
		}

		double voltageMilli = voltage * scale;
		int voltageMilliInt = (int) Math.round(voltageMilli);

		return voltageMilliInt;
	}

	
	/**
	 * Get the power input control object for the main PIM (modTS).
	 * 
	 * <p>
	 * The direct access to the module object instead of using the library APIs
	 * enables performing custom commands.
	 * @return 
	 * 
	 * @category Preprocessor
	 * @return dacObj Instance from ItfGenericPIPAOutputs to be used for direct
	 *         access to firmware APIs instead of the library implementation.
	 */
	private  ItfDAC getObj() {
		return this.dacObj;
	}
}