package libs.TestingPlatform.TestingTechLayer;

import castle.testenv.base.config.IEvent;

/**
 * @author mnagah
 * @version 1.0
 * @created 01-Aug-2017 1:52:08 PM
 */
 
 
public class DecisonTableEntryValue {

	public String fdescription;
	public String frequirement;
	public double fInputValue[];
	public double fInterspaceDelay;
	public double fInToOutDelay;
	public double fInToOutDelayTolerance;
	public IEvent fInToOutEvent = null;
	public double fOutputValue[];
	
	
	/** 
	 * @param description
	 * @param InputValue
	 * @param InToOutEvent
	 * @param InToOutDelay
	 * @param InToOutDelayTolerance
	 * @param OutputValue
	 * @param InterspaceDelay
	 */
	public DecisonTableEntryValue(String description, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, double[] OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		fInputValue = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fOutputValue = OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
	
	
	
	public String fSOutputValue[];
	
	/** 
	 * @param description
	 * @param InputValue
	 * @param InToOutEvent
	 * @param InToOutDelay
	 * @param InToOutDelayTolerance
	 * @param OutputValue
	 * @param InterspaceDelay
	 */
	public DecisonTableEntryValue(String description, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, String[] OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		fInputValue = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fSOutputValue = OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
	
	public int[] fIOutputValue;
	
	/** 
	 * @param description
	 * @param InputValue
	 * @param InToOutEvent
	 * @param InToOutDelay
	 * @param InToOutDelayTolerance
	 * @param OutputValue
	 * @param InterspaceDelay
	 */
	public DecisonTableEntryValue(String description, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, int[] OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		fInputValue = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fIOutputValue = OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
	
	
		/** 
	 * @param description
     * @param Requirement
	 * @param InputValue
	 * @param InToOutEvent
	 * @param InToOutDelay
	 * @param InToOutDelayTolerance
	 * @param OutputValue
	 * @param InterspaceDelay
	 */
	public DecisonTableEntryValue(String description,String requirement, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, double[] OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		frequirement =requirement;
		fInputValue = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fOutputValue = OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
	
}

