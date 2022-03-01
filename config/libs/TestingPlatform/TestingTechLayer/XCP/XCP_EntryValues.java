package libs.TestingPlatform.TestingTechLayer.XCP;


import castle.testenv.base.config.IEvent;

public class XCP_EntryValues 
{	
	public String fdescription;
	public double fInputValue[];
	public double fInterspaceDelay;
	public double fInToOutDelay;
	public double fInToOutDelayTolerance;
	public IEvent fInToOutEvent = null;
	public String fOutputValue_XCP[];


	/**
	 * Normal i/p only 
	 * XCP o/p only
	 */	
	public XCP_EntryValues(String description, double[] InputValue, IEvent InToOutEvent, double InToOutDelay, double InToOutDelayTolerance, String[] XCP_OutputValue, double InterspaceDelay)
	{
		fdescription =description;
		fInputValue = InputValue;
		fInToOutEvent = InToOutEvent;
		fInToOutDelay = InToOutDelay;
		fInToOutDelayTolerance = InToOutDelayTolerance;
		fOutputValue_XCP = XCP_OutputValue;
		fInterspaceDelay = InterspaceDelay;
	}
		
	public void finalize() throws Throwable 
	{

	}
}
