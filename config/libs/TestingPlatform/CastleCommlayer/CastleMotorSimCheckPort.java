package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;
import config.ItfCurrentSense.Enmchannel;
import libs.TestingPlatform.CastleCommlayer.CastleCommManager.PortType;

/**
 * @author mmegahed
 * @version 1.0
 * @created 26-May-2019 2:56:00 PM
 * @updated 
 * @updated 
 */  
public class CastleMotorSimCheckPort implements ICastlePort {

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};

	MotorMeasurments parameter;
	double inTolerance;
	ETS exu;
	
	public enum MotorMeasurments {
		/**
		 * Motor PWM output
		 */
		PWM,
		/**
		* Check pause time for INT. mode
		*/
		PauseTime,
		/**
		* Motor angle
		*/
		Angle,
		/**
		* Number of wipes
		*/
		NWipes,
	
	}
		

	/**
	 * CastleMotorSimCheckPort <br>
	 * <br>
 	 * Choose MotorMeasurement type in porting to be one of the following types:- <br>
 	 * 
	 * PWM 			1. <br>
	 * 	- Check the PWM of the wiper motor  <br>
	 * 
	 * PauseTime 	2. <br>
	 * 	- Check pause time for INT. mode in ms <br>
	 * 
	 * Angle		3. <br>
	 * 	- Check wiper motor angle in degrees <br>
	 * 
	 * NWipes 		4. <br>
	 * 	- Check the number of wipes of motor  <br>
	 * @param tolerance
	 * @param executionUnit
	 */
	public CastleMotorSimCheckPort(MotorMeasurments measuredParameter ,double tolerance, ETS executionUnit){
		measuredParameter = parameter;
		inTolerance = tolerance;
		exu = executionUnit;
		
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
		

		switch(parameter)
		{
			case PWM:
			Request_pauseInToOutDelay(registerTime);
			double PWM = value;
			double fTolerance = inTolerance;
			
			exu.comment("Check that motor PWM is in range %f",(PWM-fTolerance)," , %f",(PWM+fTolerance) );
			exu.modTS().objMotorSim().afcCheck_PWM(PWM-fTolerance, PWM+fTolerance);
			
			break;
			
			case Angle:
			Request_pauseInToOutDelay(registerTime);
			float angle = (float)value;
			float aTolerance = (float) inTolerance;
			exu.comment("Check that motor angle is in range %f and %f ",(angle-aTolerance),(angle+aTolerance) );
			exu.modTS().objMotorSim().afcCheck_Angle_Range(angle-aTolerance, angle+aTolerance);
			
			break;
			
			case PauseTime:
			Request_pauseInToOutDelay(registerTime);
			int tTolerance = ((Double)inTolerance).intValue();
			int checkedTime = ((Double)value).intValue();
			exu.comment("Check that last INT. time is %d s", checkedTime);
			exu.modTS().objMotorSim().afcCheck_Last_Intermitent_Pause_Millis(checkedTime-tTolerance	,checkedTime+tTolerance);
		
			break;
			
			case NWipes:
			Request_pauseInToOutDelay(registerTime);
			int nWipes = ((Double)value).intValue();
			int wTolerance = ((Double)inTolerance).intValue();
			exu.comment("Check that number of wipes = %d ",wTolerance);
			exu.modTS().objMotorSim().afcCheck_Number_Of_Motor_Wipes(nWipes-wTolerance, nWipes+wTolerance);
			break;
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
