package libs.TestingPlatform.TestingTechLayer.UDS;


import castle.testenv.base.config.IEvent;

public class UDS_EntryValues 
{	
	public String fdescription;
	public String fInputValue[];
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
	public UDS_EntryValues(String description, String[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, double[] OutputValue, double InterspaceDelay)
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
	public UDS_EntryValues(String description, String[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, String[] OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		fInputValue = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fSOutputValue = OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
		
	public void finalize() throws Throwable 
	{

	}
}
