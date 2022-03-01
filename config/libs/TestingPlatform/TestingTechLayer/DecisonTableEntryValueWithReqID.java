package libs.TestingPlatform.TestingTechLayer;

import castle.testenv.base.config.IEvent;

/**
 * @author ahamisa
 * @version 1.0
 * @created 04-OCT-2020 
 */
 
 public class DecisonTableEntryValueWithReqID  {

	public String fdescription;
	public String fRequirement="";
	public double fInputValue[];
	public double fInterspaceDelay;
	public double fInToOutDelay;
	public double fInToOutDelayTolerance;
	public IEvent fInToOutEvent = null;
	public double fOutputValue[];
	
	
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
	public DecisonTableEntryValueWithReqID(String description,String Requirement, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, double[] OutputValue, double InterspaceDelay)
	{
		fdescription  =description;
		fRequirement  =Requirement;
		fInputValue   = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fOutputValue = OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
	
	
	
	public String fSOutputValue[];
	
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
	public DecisonTableEntryValueWithReqID(String description,String Requirement, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, String[] OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		fRequirement =Requirement;
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
     * @param Requirement
	 * @param InputValue
	 * @param InToOutEvent
	 * @param InToOutDelay
	 * @param InToOutDelayTolerance
	 * @param OutputValue
	 * @param InterspaceDelay
	 */
	public DecisonTableEntryValueWithReqID(String description,String Requirement, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, int[] OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		fRequirement =Requirement;
		fInputValue = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fIOutputValue = OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
	
	public void finalize() throws Throwable {

	}
}
