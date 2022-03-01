package libs.TestingPlatform.TestingTechLayer;

import castle.testenv.base.config.IEvent;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 */
public class StateMachineEntryValues {

	public String fdescription;
	public String fInitialState;
	public String fFinalState;
	public double fInputValue[];
	public String fSInputValue[];
	public double fTimetoFinalStateDelay;
	public IEvent fStateEvent;

	/**
	 * Input Double array.
	 * @param description
	 * @param InitialState
	 * @param FinalState
	 * @param InputValue
	 * @param TimetoFinalStateDelay
	 * @param StateEvent
	 */
	
	public StateMachineEntryValues(String description, String InitialState, String FinalState, double[] InputValue, double TimetoFinalStateDelay, IEvent StateEvent){
		fdescription =description;
		fInputValue = InputValue;
		fStateEvent = StateEvent;
		fInitialState = InitialState;
		fFinalState = FinalState;
		fTimetoFinalStateDelay = TimetoFinalStateDelay;
	}
	
	public void finalize() throws Throwable {

	}

}