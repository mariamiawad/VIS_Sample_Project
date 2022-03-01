package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfMotorMeasurement.EnmMotorID;

/**
 * @author mnagah
 * @version 1.0
 * @created 15-Apr-2018 1:05:45 PM
 */  
public class CastleMotorInPort implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	MeasuredType fMeasuredType;
	EnmMotorID fMotorChnl;
	PhaseType fPhaseType;
	double fTolerancePercent;
	int fSpeedIndex;
	double MotorInit =-10.0; // for init the motor and Start Measurment.
	ETS exu;

	public enum MeasuredType {
			/**
			 * SpeedIndex 1.
			 */
			SpeedIndex,
			/**
			 * StepCounts 2.
			 */
			StepCounts,
			/**
			 * NumberOfPhases 3.
			 */
			NumberOfPhases,
		}
		
	public enum PhaseType {
			/**
			 * QuarterStep 1.
			 */
			QS,
			/**
			 * HalfStep 2.
			 */
			HS,
			/**
			 * FullStep 3.
			 */
			FS,
		}	
		
	/**
	 * MotorIn
	 *
	 * It's applicable for CountSteps, SpeedIndex and NumberOfPhases.
 	 * you have to choose MeasuredType in porting to be one of CountSteps, SpeedIndex and NumberOfPhases.
	 * Also you have to choose PhaseType between (QS, HS & FS).
	 * @param motorCh
	 * @param measuredIndex
	 * @param phase
	 * @param tolerance
	 * @param executionUnit
	 */
	public CastleMotorInPort(EnmMotorID motorCh, MeasuredType measuredIndex, PhaseType phase, double tolerancePercent, int speedIndex, ETS executionUnit){
		fMotorChnl = motorCh;
		fMeasuredType = measuredIndex;
		fPhaseType = phase;
		fTolerancePercent = tolerancePercent;
		fSpeedIndex = speedIndex;
		exu = executionUnit;
	}

	private int getStepsTolerance(int steps, float tolerance) {
		
	    int stepTolerance = (int) Math.round((steps) * (tolerance / 100.0));
	    
	    if(steps != 0 &&  stepTolerance == 0)
	    {
	    	stepTolerance = (int)tolerance;
	    }
		return stepTolerance; 
	    
	}
	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object... args){
		double value =(double) args[0];
		double registerTime = (double) args[1];
		double registerTimeTolerance = (double) args[2];
		InToOutDelay_paused = (boolean) args[3];
		int stepToleranceInt = getStepsTolerance((int)value, (float)fTolerancePercent);
		
		if(value == MotorInit)
		{
			exu.comment("Start Motor measurements on %s ", String.valueOf(fMotorChnl));
			exu.modTS().objMotorMeasurement().afcStartMotorMeasurement(fMotorChnl);
		}
		if(value != MotorInit)
		{
			switch(fMeasuredType)
			{
				case SpeedIndex:
					if(fPhaseType == PhaseType.QS)
					{
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check the Motor Speed to be %s in Quarter Steps with tolerance %s ", String.valueOf(value), String.valueOf(stepToleranceInt));
						exu.modTS().objMotorMeasurement().afcCheckMotorSpeedInQS(fMotorChnl, fSpeedIndex, (int)value, stepToleranceInt);
						exu.comment("Stop Motor measurements on %s ", String.valueOf(fMotorChnl));
						exu.modTS().objMotorMeasurement().afcStopMotorMeasurement(fMotorChnl);
					}
					if(fPhaseType == PhaseType.HS)
					{
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check the Motor Speed to be %s in Quarter Steps with tolerance %s ", String.valueOf(value), String.valueOf(stepToleranceInt));
						exu.modTS().objMotorMeasurement().afcCheckMotorSpeedInHS(fMotorChnl, fSpeedIndex, (int)value, stepToleranceInt);
						exu.comment("Stop Motor measurements on %s ", String.valueOf(fMotorChnl));
						exu.modTS().objMotorMeasurement().afcStopMotorMeasurement(fMotorChnl);
					}
					if(fPhaseType == PhaseType.FS)
					{
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check the Motor Speed to be %s in Quarter Steps with tolerance %s ", String.valueOf(value), String.valueOf(stepToleranceInt));
						exu.modTS().objMotorMeasurement().afcCheckMotorSpeedInFS(fMotorChnl, fSpeedIndex, (int)value, stepToleranceInt);
						exu.comment("Stop Motor measurements on %s ", String.valueOf(fMotorChnl));
						exu.modTS().objMotorMeasurement().afcStopMotorMeasurement(fMotorChnl);
					}
				break;
				
				case StepCounts:
					if(fPhaseType == PhaseType.QS)
					{	
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check the Motor steps to be %s in Quarter Steps with tolerance %s ", String.valueOf(value), String.valueOf(stepToleranceInt));
						exu.modTS().objMotorMeasurement().afcCheckMotorStepsInQs(fMotorChnl, (int)value, stepToleranceInt);
						exu.comment("Stop Motor measurements on %s ", String.valueOf(fMotorChnl));
						exu.modTS().objMotorMeasurement().afcStopMotorMeasurement(fMotorChnl);
					}
					if(fPhaseType == PhaseType.HS)
					{
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check the Motor steps to be %s in Quarter Steps with tolerance %s ", String.valueOf(value), String.valueOf(stepToleranceInt));
						exu.modTS().objMotorMeasurement().afcCheckMotorStepsInHs(fMotorChnl, (int)value, stepToleranceInt);
						exu.comment("Stop Motor measurements on %s ", String.valueOf(fMotorChnl));
						exu.modTS().objMotorMeasurement().afcStopMotorMeasurement(fMotorChnl);
					}
					if(fPhaseType == PhaseType.FS)
					{
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check the Motor steps to be %s in Quarter Steps with tolerance %s ", String.valueOf(value), String.valueOf(stepToleranceInt));
						exu.modTS().objMotorMeasurement().afcCheckMotorStepsInFs(fMotorChnl, (int)value, stepToleranceInt);
						exu.comment("Stop Motor measurements on %s ", String.valueOf(fMotorChnl));
						exu.modTS().objMotorMeasurement().afcStopMotorMeasurement(fMotorChnl);
					}
				break;
				
				case NumberOfPhases:
					Request_pauseInToOutDelay(registerTime);
					exu.comment("Check the Motor kNumber Of Phases to be %s ", String.valueOf(value));
					exu.modTS().objMotorMeasurement().afcCheckNumberOfPhases(fMotorChnl, (int)value);
					exu.comment("Stop Motor measurements on %s ", String.valueOf(fMotorChnl));
					exu.modTS().objMotorMeasurement().afcStopMotorMeasurement(fMotorChnl);
				break;
			}
		}
		return ReturnObj();
	}
	
	private void Request_pauseInToOutDelay(double IntoOutDelay){
		if(InToOutDelay_paused == false){
			exu.comment("Wait for Input to Output Delay of %s mSec", IntoOutDelay);
			exu.pause(IntoOutDelay);
			InToOutDelay_paused = true;
		}
	}
	
	private Object[] ReturnObj(){
		returnObj[0] = InToOutDelay_paused;
		return returnObj;
	}
}
