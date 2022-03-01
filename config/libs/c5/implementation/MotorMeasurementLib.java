package libs.c5.implementation;

import java.util.Arrays;

import castle.testenv.base.config.IExu;
import castle.testenv.base.script.ILib;
import castle.util.Assert;
import config.ETS;
import config.ItfMotorMeasurement;
import config.ItfMotorMeasurement.EnmMotorID;
import libs.c5.interfaces.C5.MotorMeasurement.MotorType;

/**
 * This class is standard library APIs to be used in measuring Voltage.
 *
 * <p>
 * C5 EPIP V2 has 3 Motors channel that can be used to measure Steps and Speed Indexes. This
 * library provides APIs for measuring steps and speeds for each motor.
 *
 * <p>
 * This class must not be used directly by testers (only firmware team).
 * <p>
 * SVN Path:
 *
 * @author Wesam Khattab
 * @version 1.0
 */
public class MotorMeasurementLib implements ILib {

	/** Execution Unit corresponding to this library instance */
	ETS exu;

	/**
	 * Class Constructors
	 **/
	public MotorMeasurementLib() {
	}

	public MotorMeasurementLib(IExu exu) {
		this.exu = (ETS) exu;
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
	public void startMotorMeasurement(MotorType chnl) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		this.getObj().afcStartMotorMeasurement(motorCh);
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
	public void stopMotorMeasurement(MotorType chnl) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		this.getObj().afcStopMotorMeasurement(motorCh);
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
	public void checkSpeedIndexInQs(MotorType chnl,int speedIndex,int speed,float speedTolerance) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		int stepToleranceInt = getStepsTolerance(speed, speedTolerance);
		this.getObj().afcCheckMotorSpeedInQS(motorCh, speedIndex, speed, stepToleranceInt);
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
	
	public void checkSpeedIndexInHs(MotorType chnl,int speedIndex,int speed,float speedTolerance) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		int stepToleranceInt = getStepsTolerance(speed, speedTolerance);
		this.getObj().afcCheckMotorSpeedInHS(motorCh, speedIndex, speed, stepToleranceInt);
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
	public void checkSpeedIndexInFs(MotorType chnl,int speedIndex,int speed,float speedTolerance) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		int stepToleranceInt = getStepsTolerance(speed, speedTolerance);
		this.getObj().afcCheckMotorSpeedInFS(motorCh, speedIndex, speed, stepToleranceInt);
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
	public void checkStepCountsInQs(MotorType chnl,int steps,float stepsTolerance) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		int stepToleranceInt = getStepsTolerance(steps, stepsTolerance);
		this.getObj().afcCheckMotorStepsInQs(motorCh, steps, stepToleranceInt);
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
	public void checkStepCountsInHs(MotorType chnl,int steps,float stepsTolerance) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		int stepToleranceInt = getStepsTolerance(steps, stepsTolerance);
		this.getObj().afcCheckMotorStepsInHs(motorCh, steps, stepToleranceInt);
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
	public void checkStepCountsInFs(MotorType chnl,int steps,float stepsTolerance) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		int stepToleranceInt = getStepsTolerance(steps, stepsTolerance);
		this.getObj().afcCheckMotorStepsInFs(motorCh, steps, stepToleranceInt);
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
	public void checkNumberOfPhases(MotorType chnl,int numberOfPhases) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		this.getObj().afcCheckNumberOfPhases(motorCh, numberOfPhases);
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
	public void checkStepsPerPhaseHs(MotorType chnl,int phaseIndex,int steps,float stepsTolerance) {
		EnmMotorID motorCh = getMotorTypeEnm(chnl);
		int stepToleranceInt = getStepsTolerance(steps, stepsTolerance);
		this.getObj().afcCheckStepsPerPhaseHs(motorCh, phaseIndex, steps, stepToleranceInt);
	}

	
	/**
	 * Convert from library enum to firmware enum.
	 * */
	private EnmMotorID getMotorTypeEnm(MotorType chnl) {

		int index = Arrays.asList(MotorType.values()).indexOf(chnl);

		if (index > 2 || index < 0) {
			Assert.fail("getIndexChnl:Invalid Motor channel index used !!");
		}

		return EnmMotorID.values()[index];

	}

	private int getStepsTolerance(int steps, float tolerance) {
		
	    int stepTolerance = (int) Math.round((steps) * (tolerance / 100.0));
	    
	    if(steps != 0 &&  stepTolerance == 0)
	    {
	    	stepTolerance = (int)tolerance;
	    }
		return stepTolerance; 
	    
	}

	private ItfMotorMeasurement getObj() {
		return exu.modTS().objMotorMeasurement();
	}

}
