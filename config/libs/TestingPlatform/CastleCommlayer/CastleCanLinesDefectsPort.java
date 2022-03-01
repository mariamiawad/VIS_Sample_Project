package libs.TestingPlatform.CastleCommlayer;

import config.ETS;
import config.ItfBipIo.EnmBusBi;
import config.ItfBipIo.EnmLine;
import config.ItfBipIo.EnmLineError;

/**
 * @author mnagah
 * @version 2.0
 * @created 24-Jan-2018 1:53:45 PM
 */ 
public class CastleCanLinesDefectsPort implements ICastlePort {
	boolean InToOutDelay_paused = false;
	Object[] returnObj = {InToOutDelay_paused};
	ETS exu;
	CANID fCANId;
	CANLines fCanLine;
	CANLinesDefect fDefectType;
	
	public enum CANLines {
			/**
			 * CAN Line for Defect
			 * <p>
			 * CAN High Line
			 */
			CANHigh,
			/**
			 * CAN Line for Defect
			 * <p>
			 * CAN Low Line
			 */
			CANLow,
		}
		
		
	public enum CANLinesDefect {
			/**
			 * CAN Line Defect
			 * <p>
			 * CAN Line defect Type OpenCircuit
			 */
			OpenCircuit,
			/**
			 * CAN Line Defect
			 * <p>
			 * CAN Line defect Type SCToGND
			 */
			SCToGND,
			/**
			 * CAN Line Defect
			 * <p>
			 * CAN Line defect Type SCToVCC
			 */
			SCToVCC,
			/**
			 * CAN Line Defect
			 * <p>
			 * CAN Line defect Type Short between CANhigh and CANlow
			 */
			SCBetweenCANhighCANlow,
		}
		
		public enum CANID {
			/**
			 * CAN Port
			 * <p>
			 * CAN Port 0
			 */
			CAN0,
			/**
			 * CAN Port
			 * <p>
			 * CAN Port 1
			 */
			CAN1,
		}
		
		public enum DTCInput {
			Input
		}
		
		public enum DTCOutput {
			Output
		}
		
		public enum FAILURE_CREATION {
			Create
		}
	
	/**
	 * Defect Cell on CAN high and CAN low.
	 * @param CANId
	 * @param CanLine
	 * @param defectType
	 * @param executionUnit
	 */
	public CastleCanLinesDefectsPort(CANID  canId, CANLines canLine, CANLinesDefect defectType, ETS executionUnit){
		exu = executionUnit;
		fCANId = canId;
		fCanLine = canLine;
		fDefectType = defectType;
	}

	/**
	 * 
	 * @param args
	 * @return 
	 */
	@Override
	public Object[] apply(Object ... args){
		switch(fDefectType)
		{
			case OpenCircuit:
				switch(fCANId)
				{
					case CAN0:
		
						if(fCanLine == CANLines.CANHigh)
							{
									if((double)args[0] == 1){
									    exu.comment("Apply OC defect on CAN high");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN0, EnmLine.HIGH, EnmLineError.OPEN);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove OC defect from CAN high");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}else if(fCanLine == CANLines.CANLow)
							{
								if((double)args[0] == 1){
									    exu.comment("Apply OC defect on CAN low");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN0, EnmLine.LOW, EnmLineError.OPEN);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove OC defect from CAN low");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}
					break;
					case CAN1:
						if(fCanLine == CANLines.CANHigh)
							{
									if((double)args[0] == 1){
									    exu.comment("Apply OC defect on CAN high");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN1, EnmLine.HIGH, EnmLineError.OPEN);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove OC defect from CAN high");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}else if(fCanLine == CANLines.CANLow)
							{
								if((double)args[0] == 1){
									    exu.comment("Apply OC defect on CAN low");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN1, EnmLine.LOW, EnmLineError.OPEN);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove OC defect from CAN low");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}
					break;
				default:
					break;	
				}
			break;
		
		case SCToGND:
			switch(fCANId)
				{
					case CAN0:
		
						if(fCanLine == CANLines.CANHigh)
							{
									if((double)args[0] == 1){
									    exu.comment("Apply SC to GND defect on CAN high");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN0, EnmLine.HIGH, EnmLineError.SC_GND);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to GND defect from CAN high");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}else if(fCanLine == CANLines.CANLow)
							{
								if((double)args[0] == 1){
									    exu.comment("Apply SC to GND defect on CAN low");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN0, EnmLine.LOW, EnmLineError.SC_GND);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to GND defect from CAN low");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}
					break;
					case CAN1:
						if(fCanLine == CANLines.CANHigh)
							{
									if((double)args[0] == 1){
									    exu.comment("Apply SC to GND defect on CAN high");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN1, EnmLine.HIGH, EnmLineError.SC_GND);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to GND defect from CAN high");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}else if(fCanLine == CANLines.CANLow)
							{
								if((double)args[0] == 1){
									    exu.comment("Apply SC to GND defect on CAN low");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN1, EnmLine.LOW, EnmLineError.SC_GND);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to GND defect from CAN low");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}
					break;
				default:
					break;	
				}
			break;
			
		case SCToVCC:
			switch(fCANId)
				{
					case CAN0:
		
						if(fCanLine == CANLines.CANHigh)
							{
									if((double)args[0] == 1){
									    exu.comment("Apply SC to VCC defect on CAN high");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN0, EnmLine.HIGH, EnmLineError.SC_VCC);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to VCC defect from CAN high");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}else if(fCanLine == CANLines.CANLow)
							{
								if((double)args[0] == 1){
									    exu.comment("Apply SC to VCC defect on CAN low");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN0, EnmLine.LOW, EnmLineError.SC_VCC);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to VCC defect from CAN low");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}
					break;
					case CAN1:
						if(fCanLine == CANLines.CANHigh)
							{
									if((double)args[0] == 1){
									    exu.comment("Apply SC to VCC defect on CAN high");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN1, EnmLine.HIGH, EnmLineError.SC_VCC);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to VCC defect from CAN high");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}else if(fCanLine == CANLines.CANLow)
							{
								if((double)args[0] == 1){
									    exu.comment("Apply SC to VCC defect on CAN low");
									    exu.modTS().objBipIo().afcLineErrorBipolar(EnmBusBi.CAN1, EnmLine.LOW, EnmLineError.SC_VCC);
									    exu.modTS().objBipIo().afcSetErrorEnablement(true);	
									}
									else if((double)args[0] == 0){
										exu.comment("Remove SC to VCC defect from CAN low");
										exu.modTS().objBipIo().afcSetErrorEnablement(false);	
										}
							}
					break;
				default:
					break;	
				}
			break;
			
			case SCBetweenCANhighCANlow:
			switch(fCANId)
				{
					case CAN0:
						if((double)args[0] == 1){
							exu.comment("Apply SC defect betweeen CAN high and CAN low on %s",fCANId.toString());
							exu.modTS().objBipIo().afcLineShorting(EnmBusBi.CAN0);
							exu.modTS().objBipIo().afcSetErrorEnablement(true);	
						}
						else if((double)args[0] == 0){
							exu.comment("Remove SC defect betweeen CAN high and CAN low on %s",fCANId.toString());
							exu.modTS().objBipIo().afcSetErrorEnablement(false);	
						}
					break;
					case CAN1:
						if((double)args[0] == 1){
							exu.comment("Apply SC betweeen CAN high and CAN low on %s",fCANId.toString());
							exu.modTS().objBipIo().afcLineShorting(EnmBusBi.CAN1);
							exu.modTS().objBipIo().afcSetErrorEnablement(true);	
						}
						else if((double)args[0] == 0){
							exu.comment("Remove SC defect betweeen CAN high and CAN low on %s",fCANId.toString());
							exu.modTS().objBipIo().afcSetErrorEnablement(false);	
						}
					break;
				default:
					break;	
				}
			break;
		}
		return ReturnObj();
	}
	
	private Object[] ReturnObj(){
		//TODO: Update returnObj before return if needed
		return returnObj;
	}
}