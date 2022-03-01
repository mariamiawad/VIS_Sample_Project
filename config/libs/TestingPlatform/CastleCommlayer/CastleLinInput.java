package libs.TestingPlatform.CastleCommlayer;

import castle.testenv.base.config.IEvent;
import config.ETS;
import config.Itf_SignalValue;

/**
 * @author mnagah
 * @version 2.0
 * @created 28-Jan-2018 1:53:45 PM
 */ 
public class CastleLinInput implements ICastlePort{

	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	public final double RESET = -2.0;
	int EDGE = 0;
	int LEVEL = 1;
	ETS exu;
	String fname;
	String fsignal = "";
	String fFrame = "";
	String fDataMask = "FF FF FF FF FF FF FF FF";
	double fTolerance = 0;
	int fFrameID = 0;
	double fprevVal = RESET;
	
	public CastleLinInput (String signalName, double signalTolerance, ETS executionUnit)
	{
		exu = executionUnit;
		fsignal = signalName;
		fTolerance = signalTolerance;
	}
	
	public CastleLinInput (String frameName, int frameID, String dataMask, ETS executionUnit)
	{
		exu = executionUnit;
		fFrame = frameName;
		fTolerance = 0;
		fFrameID = frameID;
		fDataMask = dataMask;
	}

	@Override
	public Object[] apply(Object...args){
		double signalValue = 0;
		String frameValue = "";
		try{
			signalValue =(double) args[0];
		}
		catch(Exception e)
		{
			frameValue =(String) args[0];
		}
			double registerTime = (double) args[1];
			double registerTimeTolerance = (double) args[2];
			InToOutDelay_paused = (boolean) args[3];
		if(fsignal != "" && fFrame == "")
		     {
		     	if(fTolerance == 0)
		     	{	IEvent evelLinValueReached = this.GetSignalObject().evtValueReached();						
					if(signalValue == RESET)
					{
						fprevVal =RESET;
						return ReturnObj();
					}
					
					if(fprevVal == RESET)
					{
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check for signal %s to be %d within time %d ms", fname , (int)signalValue , (int)registerTime );
						this.GetSignalObject().afcEqualsCheck(signalValue);
						fprevVal = signalValue;
					}
					else if( signalValue != fprevVal )
					{		
						exu.comment("Check for signal %s to change from %d to %d within time %d ms",fname,(int)fprevVal,(int)signalValue,(int)registerTime);
						this.GetSignalObject().afcCheckEventBasedSignals(
								evelLinValueReached.getModEventId(),
								EDGE,
								(int)signalValue, 
								0,
								registerTime,
								registerTimeTolerance,
								1);
						fprevVal = signalValue;
					}
					else if(signalValue == fprevVal) 
					{
						exu.comment("Check for signal %s to be %d within time %d ms" ,fname,(int)signalValue,(int)registerTime);
						this.GetSignalObject().afcCheckEventBasedSignals(
								evelLinValueReached.getModEventId(),
								LEVEL,
								(int)signalValue, 
								0,
								registerTime,
								registerTimeTolerance,
								1);
					}
				}
				else
				{
					IEvent evelLinSignalwithTolerance = this.GetSignalObject().evtValueReached();						
					if(signalValue == RESET)
					{
						fprevVal =RESET;
						return ReturnObj();
					}
					
					if(fprevVal == RESET)
					{
						Request_pauseInToOutDelay(registerTime);
						exu.comment("Check for signal %s to be %d within time %d ms", fname , (int)signalValue , (int)registerTime );
						this.GetSignalObject().afcEqualsCheck(signalValue);
						fprevVal = signalValue;
					}
					else if( signalValue != fprevVal )
					{		
						exu.comment("Check for signal %s to change from %d to %d within time %d ms",fname,(int)fprevVal,(int)signalValue,(int)registerTime);
						this.GetSignalObject().afcCheckEventBasedSignals(
								evelLinSignalwithTolerance.getModEventId(),
								EDGE,
								(int)signalValue, 
								fTolerance,
								registerTime,
								registerTimeTolerance,
								1);
						fprevVal = signalValue;
					}
					else if(signalValue == fprevVal) 
					{
						exu.comment("Check for signal %s to be %d within time %d ms" ,fname,(int)signalValue,(int)registerTime);
						this.GetSignalObject().afcCheckEventBasedSignals(
								evelLinSignalwithTolerance.getModEventId(),
								LEVEL,
								(int)signalValue, 
								fTolerance,
								registerTime,
								registerTimeTolerance,
								1);
					}
				}	
			}
		if(fFrame != "" && fsignal == "")
		{
			Request_pauseInToOutDelay(registerTime);
			exu.comment("Check for Frame %s to be %s within time %d ms", fname , frameValue , (int)registerTime );
			exu.modTS().objLinMaster().afcSetLinSignalsByMask(fFrameID, String.valueOf(frameValue), fDataMask);
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
	
	Itf_SignalValue GetSignalObject()
	{
		
		Itf_SignalValue returnSignalObject = null;
		
		//it depends on LIN Message Names generated from LPF
/*		switch (fsignal){
		case "SHL_li1_BRL_haupt_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_BRL_haupt_def.getObject();

			break;
		case "SHL_li1_BRL_zusatz_kompl_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_BRL_zusatz_kompl_def.getObject();
			break;
		case "SHL_li1_RFL_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_RFL_def.getObject();
			break;
		case "SHL_li1_RFL_kompl_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_RFL_kompl_def.getObject();
			break;
		case "SHL_li1_SHL_haupt_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_SHL_haupt_def.getObject();
			break;
		case "SHL_li1_SHL_haupt_kompl_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_SHL_haupt_kompl_def.getObject();
			break;
		case "SHL_li1_FRA_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_FRA_def.getObject();
			break;
		case "SHL_li1_BRL_zusatz_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_BRL_zusatz_def.getObject();
			break;
			
		case "SHL_li1_Unterspannung":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_Unterspannung.getObject();
			break;
		case "SHL_li1_Versorgung_def":	
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_Versorgung_def.getObject();
			break;
		case"SHL_li1_Ueberspannung":
			returnSignalObject = LIN_Network3.Rx_SHL_li1s_01.Sig_SHL_li1_Ueberspannung.getObject();
			break;

			
		}	*/
		return returnSignalObject;
	}
}
