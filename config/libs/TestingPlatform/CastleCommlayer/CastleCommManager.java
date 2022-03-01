package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfCurrentSense.Enmchannel;
import config.ItfDAC.EnmDacChnls;
import config.ItfDI.EnmDigitalInputChannelID;
import config.ItfDO.EnmDigitalOutChannels;
import config.ItfDefectCell.EnmCellState;
import config.ItfDefectCell.EnmDefectCellChannel;
import config.ItfDefectCell.EnmSupply;
import config.ItfMotorMeasurement.EnmMotorID;
import config.ItfPWMOutput.EnmPwmOutChannel;
import config.ItfPowerControl.EnmPowerInputChannel;
import config.ItfPowerControl.EnmPowerSource;
import config.ItfPwmIn.EnmPwm_Chnl;
import config.Itf_SignalValue.EnmToleranceType;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.CANID;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.CANLines;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.CANLinesDefect;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.DTCInput;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.DTCOutput;
import libs.TestingPlatform.CastleCommlayer.CastleCanLinesDefectsPort.FAILURE_CREATION;
import libs.TestingPlatform.CastleCommlayer.CastleCurrentInPort.CurrUnit;
import libs.TestingPlatform.CastleCommlayer.CastleCurrentInPort.MeasuredCurrent;
import libs.TestingPlatform.CastleCommlayer.CastleDacOutputPort.DACVoltageUnit;
import libs.TestingPlatform.CastleCommlayer.CastleDigitalOutputPort.HighLogicVoltage;
import libs.TestingPlatform.CastleCommlayer.CastleElmosInputPort.Elmos_PortType;
import libs.TestingPlatform.CastleCommlayer.CastleLinOutput.LinOutType;
import libs.TestingPlatform.CastleCommlayer.CastleMotorInPort.MeasuredType;
import libs.TestingPlatform.CastleCommlayer.CastleMotorInPort.PhaseType;
import libs.TestingPlatform.CastleCommlayer.CastlePowerOutputPort.PowerSupplyID;
import libs.TestingPlatform.CastleCommlayer.CastlePowerPWMOutputPort.PowerSupplySource;
import libs.TestingPlatform.CastleCommlayer.CastlePowerSupplyLib.PowerSupplyType;
import libs.TestingPlatform.CastleCommlayer.CastlePwmInPort.PwmInFreqUnit;
import libs.TestingPlatform.CastleCommlayer.CastlePwmInPort.PwmSignalMeasured;
import libs.TestingPlatform.CastleCommlayer.CastlePwmInPortWithFreq.PwmInUpdatedFreqUnit;
import libs.TestingPlatform.CastleCommlayer.CastlePwmInPortWithFreq.PwmUpdatedSignalMeasured;
import libs.TestingPlatform.CastleCommlayer.CastlePwmOutPort.PwmOutFreqUnit;
import libs.TestingPlatform.CastleCommlayer.CastlePwmOutPortWithFreq.PwmGeneratedSignal;
import libs.TestingPlatform.CastleCommlayer.CastlePwmOutPortWithFreq.PwmOutUpdatedFreqUnit;
import libs.TestingPlatform.CastleCommlayer.CastleVoltageInPort.MeasuredVoltage;
import libs.TestingPlatform.CastleCommlayer.CastleVoltageInPort.VoltUnit;
import libs.TestingPlatform.CastleCommlayer.CastleXCP_CAN.RLConfiguration;
import libs.TestingPlatform.CastleCommlayer.CastleXCP_CanGetPort.XCP_PortType;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 * @updated 22-Jul-2019 maboelkh
 * @updated 05-OCT-2020 ahamisa
 */ 
public class CastleCommManager {
	
	/**
	* PortType (Timebased or Eventbased).
	*/
	public enum PortType {
		/**
		 * Timebased porting
		 */
		Timebased,
		/**
		* Eventbased porting
		 */
		Eventbased
	}
	
	/**
	 * Elmos Input
	 * working on Elmos Chip (CAN/UART) on Castle CAN1 Channel
	 * @param ElmosId
	 * @param MemoryAddress
	 * @param Elmos_PortType
	 * @param Tolerance
	 * @param executionUnit
	 */
	public ICastlePort getPort(int ElmosId, int MemoryAddress, Elmos_PortType PortType, int Tolerance, ETS executionUnit){
		return new CastleElmosInputPort(ElmosId, MemoryAddress, PortType, Tolerance, executionUnit);
	}
	
	
	/**
	 * MotorIn
	 *
 	 * Choose MeasuredType in porting to be one of the following types:- 
	 * CountSteps, SpeedIndex and NumberOfPhases.
	 * Also you have to choose PhaseType between (QS, HS & FS).
	 * @param motorCh
	 * @param measuredIndex
	 * @param phase
	 * @param tolerance
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmMotorID motorCh, MeasuredType measuredIndex, PhaseType phase, double tolerancePercent, int speedIndex, ETS executionUnit){
		return new CastleMotorInPort(motorCh, measuredIndex, phase, tolerancePercent, speedIndex, executionUnit);
	}
	
	/**
	 * CanDTCManagementInput
	 * @param executionUnit
	 * @param Input
	 */
	public ICastlePort getPort(ETS executionUnit,DTCInput Input){
		return new CastleCanDTCManagementInput(executionUnit, Input);
	}
	
	/**
	 * CanDTCManagementOutput
	 * @param executionUnit
	 * @param Output
	 */
	public ICastlePort getPort(ETS executionUnit,DTCOutput Output){
		return new CastleCanDTCManagementOutput(executionUnit, Output );
	}
	
		/**
	 * anDTCCreation 
	 * @param executionUnit
	 * @param Create
	 */
	public ICastlePort getPort(ETS executionUnit,FAILURE_CREATION Create){
		return new CastleCanDTCCreation(executionUnit, Create );
	}
	
	/**
	 * CAN lines defects (OC, SCToGND, SCToVCC & SC between CANhigh and CANlow)
	 * CAN port, and which line in CAN should be selected to apply a certain defect on this line.
	 * In case of choosing SC between CANhigh and CANlow, Canlines input is not important and you can choose any of them. 
	 * @param canId
	 * @param canLine
	 * @param comment
	 */
	public ICastlePort getPort(CANID  canId, CANLines canLine, CANLinesDefect defectType, ETS executionUnit){
		return new CastleCanLinesDefectsPort( canId, canLine, defectType, executionUnit);
	}
	
	/**
	 * Digital Input Signals
	 * 
	 * @param channelId
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmDigitalInputChannelID channelId, ETS executionUnit){
		return new CastleDigitalInputPort( channelId, executionUnit);
	}

	/**
	 * Digital Output Signals
	 * Digital output ChannelID and the logic high voltage (3 Volt or 5 Volt) should be selected.
	 * @param channelId
	 * @param highVoltage
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmDigitalOutChannels channelId, HighLogicVoltage highVoltage, ETS executionUnit){
		return new  CastleDigitalOutputPort(channelId, highVoltage, executionUnit);
	}
	
	/**
	 * PWM Input
	 * This porting function can be used to measure PWM Signal, PWM Frequency or both of them on a certain channel.
	 * by choosing signalMeasured as PWMDutyCycle so user will assert on Dutycycle only.
	 * by choosing signalMeasured as PWMFrequency so user will assert on PWMFrequency only.
	 * by choosing signalMeasured as PWMDutyCycleAndFrequency so user will assert on both values.
	 * @param channelId
	 * @param signalMeasured
	 * @param duytTolerancePercent
	 * @param frequency
	 * @param freqTolerancePercent
	 * @param frequencyUnit
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmPwm_Chnl channelId, PwmSignalMeasured signalMeasured, double duytTolerancePercent, double frequency, double freqTolerancePercent, PwmInFreqUnit frequencyUnit , ETS executionUnit){
		return new  CastlePwmInPort(channelId, signalMeasured, duytTolerancePercent, frequency, freqTolerancePercent, frequencyUnit, executionUnit);
	}
	
	/**
	 * CastlePwmInPortWithFreq
	 * This porting function can be used to measure PWM Signal, PWM Frequency .
     * 
	 * by choosing signalMeasured as PWMDutyCycle so user will assert on Dutycycle only.
	 * by choosing signalMeasured as PWMFrequency so user will assert on PWMFrequency only.
	 * 
	 * @param channelId
	 * @param signalMeasured
	 * @param duytTolerancePercent
	 * @param frequency
	 * @param freqTolerancePercent
	 * @param frequencyUnit
	 * @param executionUnit
	 */
	
	public ICastlePort getPort(EnmPwm_Chnl channelId, PwmUpdatedSignalMeasured signalMeasured , double duty ,double duytTolerancePercent, double frequency, double freqTolerancePercent, PwmInUpdatedFreqUnit frequencyUnit , ETS executionUnit){
		return new CastlePwmInPortWithFreq(channelId, signalMeasured,duty,duytTolerancePercent, frequency, freqTolerancePercent, frequencyUnit, executionUnit);
	}

	/**
	 * PWM Output
	 * @param channelId
	 * @param frequency
	 * @param frequencyUnit
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmPwmOutChannel channelId, double frequency, PwmOutFreqUnit frequencyUnit, ETS executionUnit){
		return new CastlePwmOutPort(channelId,frequency,frequencyUnit,executionUnit);
	}

/**
	 * PWM Output Updated
	 * @param channelId
     * @param GeneratedSignal
	 * @param frequency
	 * @param frequencyUnit
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmPwmOutChannel channelId,PwmGeneratedSignal GeneratedSignal,double Duty,double frequency, PwmOutUpdatedFreqUnit frequencyUnit, ETS executionUnit){
		return new CastlePwmOutPortWithFreq(channelId,GeneratedSignal,Duty,frequency,frequencyUnit,executionUnit);
	}
	/**
	 * DAC Output
	 * you have to choose the Voltage unit that will be used.
	 * @param channelId
	 * @param voltageUnit
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmDacChnls channelId, DACVoltageUnit voltageUnit, ETS executionUnit){
		return new  CastleDacOutputPort(channelId,voltageUnit, executionUnit);
	}

	/**
	 * LIN Signal Input
	 * In case of not using Tolerance with the Signal Value tolerance so it should be 0. 
	 * @param signalName
	 * @param signalTolerance
	 * @param executionUnit
	 */
	public ICastlePort getPort(String signalName, float signalTolerance, ETS executionUnit){
		return new CastleLinInput(signalName, (double)signalTolerance, executionUnit);
	}
	
	/**
	 * LIN Frame Input
	 * 
	 * @param frameName
	 * @param frameID
	 * @param dataMask
	 * @param executionUnit
	 */
	public ICastlePort getPort(String frameName, int frameID, String dataMask, ETS executionUnit){
		return new CastleLinInput(frameName, frameID, dataMask, executionUnit);
	}

	/**
	 * Lin Output
	 * It can send Lin Signal Value if linOutType is SignalValue and can send Lin frame if linOutType is FramneValue.
	 * @param linOutType
	 * @param signalFrame : Signal Name/ Frame Name
	 * @param executionUnit
	 */
	public ICastlePort getPort(LinOutType linOutType, String signalFrame, ETS executionUnit){
		return new CastleLinOutput(linOutType, signalFrame, executionUnit);
	}

/**
	 * UDSLinWrite
	 * @param sessionType
	 * @param DID
	 * @param comment
	 * @param executionUnit
	 */
	public ICastlePort getPort(UDSSessionType sessionType, String DID, String comment, ETS executionUnit){
		return new CastleUDSLinWritePort(sessionType, DID, executionUnit);
	}
	
	/**
	 * UDSLINRead
	 * @param sessionType
	 * @param DID
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param comment
	 * @param executionUnit
	 */
	public ICastlePort getPort(UDSSessionType sessionType, String DID, int ResponseOffset, String ResponseMask, String comment, ETS executionUnit){
		return new CastleUDSLinReadPort(sessionType, DID, ResponseOffset, ResponseMask, executionUnit);
	}
	
	/**
	 * UDS LIN Hard Reset
	 * @param NADAddress
	 * @param executionUnit
	 */
	public void UDS_LIN_HardReset(int NADAddress, ETS executionUnit) {
		CastleUDS_LIN.Init(NADAddress, executionUnit);
		CastleUDS_LIN.HardReset();
	}
	
	/**
	 * UDS Read Diag over LIN
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public void UDS_LIN_ReadDiag(int NADAddress, String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit) {
		CastleUDS_LIN.Init(NADAddress, executionUnit);
		CastleUDS_LIN.ReadandCheckResponse(DIDNumber, ResponseOffset, ResponseMask, ExpectedResponseData);
	}
	
	/**
	 * UDS Test Read DID over LIN
	 * @param DIDNumber
	 */
	public void UDS_LIN_TestReadDID(int NADAddress, String DIDNumber, ETS executionUnit) {
		CastleUDS_LIN.Init(NADAddress, executionUnit);
		CastleUDS_LIN.ReadandCheckSuccessResponse(DIDNumber);
	}
	
	/**
	 * UDS Test Read DID over LIN
	 * @param DIDNumber
	 * @param Datalength
	 */
	public void UDS_LIN_TestReadDID(int NADAddress, String DIDNumber, int Datalength, ETS executionUnit) {
		CastleUDS_LIN.Init(NADAddress, executionUnit);
		CastleUDS_LIN.ReadandCheckSuccessResponse(DIDNumber, Datalength);
	}
	
	/**
	 * UDS Write Diag over LIN
	 * @param DIDNumber
	 * @param commandData
	 */
	public void UDS_LIN_WriteDiag(int NADAddress, String DIDNumber, String commandData, ETS executionUnit) {
		CastleUDS_LIN.Init(NADAddress, executionUnit);
		CastleUDS_LIN.WriteAndCheckResponse(DIDNumber, commandData);
	}
	
	/**
	 * UDS Write Diag over LIN
	 * @param DID
	 * @param commandData
	 * @param length
	 */
	public void UDS_LIN_WriteDiag(int NADAddress, String DID, String commandData, int length, ETS executionUnit) {
		CastleUDS_LIN.Init(NADAddress, executionUnit);
		CastleUDS_LIN.WriteAndCheckResponse(DID, commandData, length);
	}
	
	/**
	 * UDS Switch Sessions over LIN
	 * @param sessionType
	 */
	public void UDS_LIN_SwitchSessions(int NADAddress, UDSSessionType sessionType, ETS executionUnit) {
		CastleUDS_LIN.Init(NADAddress, executionUnit);
		CastleUDS_LIN.SwitchSessions(sessionType);
	}
	
	/**
	 * DefectCell
	 * Choose Defect cellID and DefectType as (SCToGND, SCToBatt, OpenCircuit)
 	 * Battery Supply Source should be selected as in case of choosing SCtoBatt type this source will be used.
	 * @param channelId
	 * @param name
	 */
	public ICastlePort getPort(EnmDefectCellChannel cellId, EnmCellState defectType, EnmSupply battSupplySource, ETS executionUnit){
		return new CastleDefectCellPort( cellId, defectType, battSupplySource, executionUnit);
	}

	/**
	 * PowerOutput, 10 ms tolerance should be considered in the test design so in case of the inputOutputTime is 200ms in requirements 
	 * so it should be 210 ms in test case <br>
	 * In case of using Supply Channel Directly without Castle Power Inputs, pass null to channelId argument
	 * 
	 * @param channelId
	 * @param PoweSupplyChannel
	 * @param powerSupplyID
	 * @param CurrentLimit
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmPowerInputChannel channelId, PowerSupplyID PoweSupplyChannel, EnmPowerSource powerSupplyID, double currentLimit, ETS executionUnit){
		return new CastlePowerOutputPort(channelId, PoweSupplyChannel, powerSupplyID, currentLimit, executionUnit);
	}
	
	/**
	 * Power PWM Output, 10 ms tolerance should be considered in the test design so in case of the inputOutputTime is 200ms in requirements 
	 * so it should be 210 ms in test case <br>
	 * Power PWM which is running with a fixed duty cycle 50% but with configurable frequency.
	 * 
	 * @param channelId
	 * @param PoweSupplyChannel
	 * @param powerSupplyID
	 * @param CurrentLimit
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmPowerInputChannel channelId, PowerSupplySource poweSupplyChannel, EnmPowerSource powerSupplyID, double operatingVoltage , int duty , int frequencyDivisor, double currentLimit, ETS executionUnit){
		return new CastlePowerPWMOutputPort(channelId, poweSupplyChannel, powerSupplyID, operatingVoltage , duty , frequencyDivisor, currentLimit, executionUnit);
	}
	
	/**
	 * DACPowerOut
	 * @param channelId
	 * @param PoweSupplyChannel
	 * @param powerSupplyID
	 * @param ExternalControlChnl
	 * @param executionUnit
	 */
	public ICastlePort getPort(EnmPowerInputChannel channelId, PowerSupplyID PoweSupplyChannel, EnmPowerSource powerSupplyID, EnmDacChnls ExternalControlChnl, PowerSupplyType supplyType, ETS executionUnit){
		return new CastleDACPowerOutPort(channelId,PoweSupplyChannel , powerSupplyID ,ExternalControlChnl, supplyType ,executionUnit);
	}

	/**
	 * VoltageInPort <br>
	 * <br>
 	 * Choose MeasuredVoltageType in porting to be one of the following types:- <br>
 	 *
	 * InstantaneousVoltage 1. <br>
	 * 	- No time pause is applied for Instantaneous Voltage assertion! <br>
	 *
	 * AverageVoltage 2. <br>
	 * 	- 15mSec pause is applied to calculate Average Voltage before each Time Based assertion! <br>
	 *
	 * MaximumVoltage 3. <br>
	 * 	- 15mSec pause is applied for Maximum Voltage assertion! <br>
	 *
	 * @param channelId
	 * @param voltageType
	 * @param voltageUnit
	 * @param tolerance
	 * @param executionUnit
	 */
	public ICastlePort getPort(config.ItfVoltageSense.Enmchannel channelId, MeasuredVoltage voltageType, VoltUnit voltageUnit, double tolerancePercent, ETS executionUnit){
		return new CastleVoltageInPort(channelId, voltageType, voltageUnit, tolerancePercent , executionUnit);
	}
	
	/**
	 * CurrentInPort <br>
	 * <br>
 	 * Choose MeasuredCurrentType in porting to be one of the following types:- <br>
 	 * 
	 * InstantaneousCurrent 1. <br>
	 * 	- No time pause is applied for Instantaneous Current assertion! <br>
	 * 
	 * AverageCurrent 2. <br>
	 * 	- 15mSec pause is applied to calculate Average Current (for PWM Current) before each Time Based assertion! <br>
	 * 
	 * MaximumCurrent 3. <br>
	 * 	- 15mSec pause is applied for Maximum Current assertion! <br>
	 * 
	 * CurrentDutyCycle 4. <br>
	 * 	- 15mSec pause is applied to calculate Current Duty Cycle before each Time Based assertion! <br>
	 * 
	 * CurrentFrequency 5. <br>
	 * 	- 15mSec pause is applied to calculate Current Frequency before each Time Based assertion! <br>
	 * 	- Only Time Based assertion is available, No Events for Current Frequency yet! <br>
	 * 
	 * FilteredCurrent 6. <br>
	 * 	- 2000mSec pause is applied to calculate Filtered Current (more than 1024 samples for DC Current) before each Time Based assertion! <br>
	 * 	- Only Time Based assertion is available, No Events for Filtered Current yet! <br>
	 * 
	 * @param channelId
	 * @param currentType
	 * @param currentUnit
	 * @param tolerance
	 * @param executionUnit
	 */
	public ICastlePort getPort(Enmchannel channelId, MeasuredCurrent currentType, CurrUnit currentUnit, double tolerancePercent, ETS executionUnit){
		return new CastleCurrentInPort(channelId, currentType, currentUnit, tolerancePercent , executionUnit);
	}
	
	/**
	 * CAN Output
	 * 
	 * @param canSignal
	 * @param periodicity
	 * @param executionUnit
	 */
	public ICastlePort getPort(String canSignal, double periodicity, ETS executionUnit){
		return new CastleCanOutputPort(canSignal, periodicity, executionUnit);
	}
	
	
	
	
	
	/**
	 * CAN Input
	 * 
	 * @param signal
	 */
	public ICastlePort getPort(String signal){
		return new CastleCanInputPort(signal);
	}
	
	
	
	/**
	 * UART Input
	 * 
	 * @param executionUnit
	 */
	public ICastlePort getPort(ETS executionUnit){
		return new CastleUARTInputPort(executionUnit);
	}
	
	/**
	 * SPI Input
	 * working only on SPI with word 16 bits
	 * @param bufferSize
	 * @param wordSize
	 * @param executionUnit
	 */
	public ICastlePort getPort(int bufferSize, String Mask, ETS executionUnit){
		return new CastleSPIInputPort(bufferSize, Mask , executionUnit);
	}

	/**
	 * UDSCanWrite
	 * @param sessionType
	 * @param DID
	 */
	public ICastlePort getPort(UDSSessionType sessionType, String DID, ETS executionUnit){
		return new CastleUDSCanWritePort(sessionType, DID, executionUnit);
	}
	
	/**
	 * UDSCanRead
	 * @param sessionType
	 * @param DID
	 * @param ResponseOffset
	 * @param ResponseMask
	 */
	public ICastlePort getPort(UDSSessionType sessionType, String DID, int ResponseOffset, String ResponseMask, ETS executionUnit){
		return new CastleUDSCanReadPort(sessionType, DID, ResponseOffset, ResponseMask, executionUnit);
	}
	
	/**
	 * UDS Hard Reset
	 */
	public void UDS_HardReset(ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.HardReset();
	}
	
	/**
	 * UDS Read Diag over CAN
	 * @param DIDNumber
	 * @param commandData
	 * @param ResponseOffset
	 * @param ResponseMask
	 * @param ExpectedResponseData
	 */
	public void UDS_ReadDiag(String DIDNumber, String commandData, int ResponseOffset, String ResponseMask, String ExpectedResponseData, ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.ReadandCheckResponse(DIDNumber, ResponseOffset, ResponseMask, ExpectedResponseData);
	}
	
	/**
	 * UDS Test Read DID over CAN
	 * @param DIDNumber
	 */
	public void UDS_TestReadDID(String DIDNumber, ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.ReadandCheckSuccessResponse(DIDNumber);
	}
	
	/**
	 * UDS Test Read DID over CAN with supported sessions only
	 * @param DIDNumber
	 * @param Datalength
	 * @param SupportedSessions
	 * @param executionUnit
	 */
	public void UDS_TestReadDID(String DIDNumber, int Datalength, String[] SupportedSessions, ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.ReadandCheckSuccessResponse(DIDNumber, Datalength, SupportedSessions);
	}
	
	/**
	 * UDS Test Read DID over CAN
	 * @param DIDNumber
	 * @param Datalength
	 * @param executionUnit
	 */
	public void UDS_TestReadDID(String DIDNumber, int Datalength, ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.ReadandCheckSuccessResponse(DIDNumber, Datalength);
	}
	
	/**
	 * UDS Write Diag over CAN
	 * @param DIDNumber
	 * @param commandData
	 */
	public void UDS_WriteDiag(String DIDNumber, String commandData, ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.WriteAndCheckResponse(DIDNumber, commandData);
	}
	
	/**
	 * UDS Write Diag over CAN
	 * @param DID
	 * @param commandData
	 * @param length
	 * @param SupportedSessions
	 * @param executionUnit
	 */
	public void UDS_WriteDiag(String DID, String commandData, int length, String[] SupportedSessions , ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.WriteAndCheckResponse(DID, commandData, SupportedSessions, length);
	}
	
	/**
	 * UDS Write Diag over CAN
	 * @param DID
	 * @param commandData
	 * @param length
	 */
	public void UDS_WriteDiag(String DID, String commandData, int length, ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.WriteAndCheckResponse(DID, commandData, length);
	}
	
	/**
	 * UDS Switch Sessions over CAN
	 * @param sessionType
	 */
	public void UDS_SwitchSessions(UDSSessionType sessionType, ETS executionUnit) {
		CastleUDS_CAN.Init(executionUnit);
		CastleUDS_CAN.SwitchSessions(sessionType);
	}
	
	/**
	 * XCP_Get
	 * @param Global Variable object
	 * @param Number Of Data as String
	 * @param data to be checked as String 
	 */
	public ICastlePort getPort(int Address, String NumberOfBytes, String Mask, long ToleranceValue, EnmToleranceType ToleranceType, RLConfiguration Side , XCP_PortType XCP_portType, ETS executionUnit)
	{
		return new CastleXCP_CanGetPort(Address, NumberOfBytes, Mask, ToleranceValue, ToleranceType, Side , XCP_portType, executionUnit);
	}
	
	/**
	 * XCP_Set
	 * @param Global Variable Object
	 * @param Data to be sent as String
	 * 
	 * 
	 */
	public ICastlePort getPort(int Address, String NumberOfData, RLConfiguration Side , ETS executionUnit)
	{
		return new CastleXCP_CanSetPort(Address, NumberOfData, Side , executionUnit);
	}
	
		/**
	 * Clear all DTCs over CAN Diag
	 * @param executionUnit
	 */
	public void ClearDTCs(ETS executionUnit)
	{
		CastleDTC_CAN dtc = new CastleDTC_CAN(executionUnit);
		dtc.ClearDTCs();
	}
	
	/**
	 * Check No Stored DTCs over CAN Diag
	 * @param executionUnit
	 */
	public void CheckNoDTCStored(ETS executionUnit)
	{
		CastleDTC_CAN dtc = new CastleDTC_CAN(executionUnit);
		dtc.CheckNoDTCStored();
	}
	
	/**
	 * Read a certain Stored DTC over CAN Diag
	 * @param DTCs
	 * @param executionUnit
	 */
	public void ReadStoredDTCs(String DTC, ETS executionUnit)
	{
		CastleDTC_CAN dtc = new CastleDTC_CAN(executionUnit);
		dtc.ReadStoredDTCs(DTC);

	}
	
	/**
	 * Validate a certain Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public void ValidateDTCAfterApplyingDefect(String DTC, ETS executionUnit)
	{
		CastleDTC_CAN dtc = new CastleDTC_CAN(executionUnit);
		dtc.ValidateDTCAfterApplyingDefect(DTC);

	}
	
	/**
	 * DeValidate a certain Stored DTC over CAN Diag after validation time
	 * @param DTCs
	 * @param executionUnit
	 */
	public void DeValidateDTCAfterApplyingDefect(String DTC, ETS executionUnit)
	{
		CastleDTC_CAN dtc = new CastleDTC_CAN(executionUnit);
		dtc.DeValidateDTCAfterRemovingDefect(DTC);

	}
	
	/**
	 * Check wiper motor PWM 
	 * @param tolerance
	 * @param executionUnit
	 */
	 
	public ICastlePort getPort(float pTolerance,ETS executionUnit)
	{
		return new CastleMotorPWMCheck(pTolerance,executionUnit);
	}
	
		
	/**
	 * Check wiper motor direction
	 * @param executionUnit
	 * @param dummy string
	 */
	 
	public ICastlePort getPort(ETS executionUnit,String dummy)
	{
		return new CastleMotorDirectionCheck(executionUnit);
	}
	
	/**
	 * Check wiper motor angle
	 * @param aTolerance
	 * @param executionUnit
	 * @param dummy string
	 */
	 
	 public ICastlePort getPort(float aTolerance,ETS executionUnit,String dummy)
	 {
		 return new CastleMotorAngleCheck(aTolerance, executionUnit);
	 }
	 
	 /**
	  * Check wiper motor speed in CPM
	  *	@param Speed tolerance
	  *	@param Angle tolerance
	  *	@param IW angle
	  *	@param OW angle
	  *	@param executionUnit
	  */
	  
	  public ICastlePort getPort(int sTolerance,int aTolerance,float IW,float OW,ETS executionUnit)
	  {
		  return new CastleMotorSpeedCheck(sTolerance, aTolerance, IW, OW, executionUnit);
	  }
	  
	  /**
	   * Check last pause time 
	   * @param tTolerance
	   * @param executionUnit
	   * @param dummy string
	   */
	   public ICastlePort getPort(int tTolerance,ETS executionUnit,String dummy)
	   {
		   return new CastleMotorPauseTimeCheck(tTolerance, executionUnit);
	   }
	   
	   /**
		* Set motor overload factor	    
		* @param executionUnit    
		* @param dummy char
	    */
	   public ICastlePort getPort(ETS executionUnit,char dummy)
	   {
		   return new CastleMotorSetOverLoad(executionUnit);
	   }
	   
	   
	   /**
		* Apply CRC angle sensor error
		* @param errorState 
		* String "true or false"
		* @param executionUnit
	    */
	   public ICastlePort getPort (String errorState , ETS executionUnit)
	   {
		   return new CastleMotorSetCRCError(errorState,executionUnit);
	   }
	   
	   /**
	    * Force motor to move to angle
		* @param dummy char
		* @param executionUnit
	    */
	   public ICastlePort getPort (char dummy,ETS executionUnit )
	   {
		   return new CastleMotorSetAngle( executionUnit);
	   }
	   
	   /**
		* Set stall angle 
		* @param stallCount 
		* stall position
		* @param executionUnit
	    */
	    
	    public ICastlePort getPort (int stallAngleCount,ETS executionUnit)
	    {
	    	return new CastleMotorSetStallAngle(stallAngleCount,executionUnit);
	    }
	    
	    /**
	     * Remove stall angle
	     * @param executionUnit
	     */
	    public ICastlePort getPort (byte dummy,ETS executionUnit)
	    {
	    	return new CastleMotorRemoveStallAngle(executionUnit);
	    }

	public void finalize() throws Throwable {

	}
}