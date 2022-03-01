package libs.TestingPlatform.TestingProcLayer.FBDexternalLib;

import config.ETS;
import libs.TestingPlatform.TestingProcLayer.SimpleInputOutput;
import libs.TestingPlatform.TestingProcLayer.SimpleInputOutput.ExternalLib;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;

public class BINSelec {
	public final static double ZeroCurrent=-3;
	final  public static double RESET = -2.0;
	public  final static double NO_VAL = -1.0;
	public  final static double TBD = 0 ;
	public  final static double ON = 5;
	public  final static double OFF = 0;
	
	/** 
	 * 
	 * BIN Selection test:	
	 * first set BIN then enable the function after that assert on output
	 * second change the BIN value to another value during Run Time 
	 * and make sure that the current is not changed
	 * @param PSNominalVoltage		(unit) Volt
	 * @param ONSignl				(e.g. input power (unit) Volt)
	 * @param BINVoltage Array		(unit) mVolt
	 * @param NominalOutput	Array	(e.g. Output Current (unit) mAmp)
	 * @param castlePorting
	 * @param executionUnit
	 * @author mteama
	 */
	public static void BINTest (double PSNominalVoltage, double ONSignal,double[] BINVoltage,double[] NominalOutputCurrent,CastlePortingMap castlePorting, ETS executionUnit)
	{	 /* first set BIN then enable the function after that assert on output
		 * second change the BIN value to the Second Value  during Run Time 
		 * and make sure that the current is not changed*/
		int arrayindex=0;
		DecisonTableEntryValue[] BINSelect1 = new DecisonTableEntryValue[BINVoltage.length*3];
		for(int index = 0; index < (BINVoltage.length-1) ; index++)
		{
			BINSelect1[arrayindex]	= new DecisonTableEntryValue("set BIN to BIN+(index+1)+after that Power on the PS and enable the function then assert on the output", 	new double[]{BINVoltage[index], 	PSNominalVoltage,	ONSignal},null,	1000, 0 , new double[]{ NominalOutputCurrent[index]	},	2000);			
			BINSelect1[arrayindex+1]= new DecisonTableEntryValue("change the BIN value to BIN+(index+2)+then make sure that the output doesn't changed",		new double[]{BINVoltage[index+1],	NO_VAL,				NO_VAL},null,	1000, 0 , new double[]{ NominalOutputCurrent[index]	},	2000);	
			BINSelect1[arrayindex+2]= new DecisonTableEntryValue("Power off the PS",		new double[]{NO_VAL,				OFF,				OFF			},null,	1000, 0 , new double[]{ NO_VAL	},	2000);	
					arrayindex=(index+1)*3;
		}
//		BINSelect1[(BINVoltage.length*3)-3]	= new DecisonTableEntryValue("set BIN to BIN"+(BINVoltage.length)+"after that Power on the PS and enable the function then assert on the output", 	new double[]{BINVoltage[BINVoltage.length-1], 	PSNominalVoltage,	ONSignal	},null,	1000, 0 , new double[]{ NominalOutputCurrent[BINVoltage.length]	},	2000);	
//		BINSelect1[(BINVoltage.length*3)-2]	= new DecisonTableEntryValue("change the BIN value to BIN"+(BINVoltage.length+1)+"then make sure that the output doesn't changed",		new double[]{BINVoltage[0],						NO_VAL,				NO_VAL		},null,	1000, 0 , new double[]{ NominalOutputCurrent[BINVoltage.length]	},	2000);	
//		BINSelect1[(BINVoltage.length*3-1)]	= new DecisonTableEntryValue("Power off the PS",		new double[]{NO_VAL,							OFF,				OFF			},null,	1000, 0 , new double[]{ NO_VAL						},	2000);	
				
		////////////////////////////////////////////////////////////////////////
		/*Finally concatenate the arrays*/
		DecisonTableEntryValue[] inputOutpu =  fBDTools.joinArray(BINSelect1);
		////////////////////////////////////////////////////////////////////////
		SimpleInputOutput BINSelectionOb1=new SimpleInputOutput();
		BINSelectionOb1.RunDecisionTable(inputOutpu, castlePorting, executionUnit,ExternalLib.WithoutExLib);
		
		
	}
}
