package libs.TestingPlatform.TestingProcLayer.VWSLib;

//import com.sun.corba.se.spi.orbutil.fsm.Input;
//import com.sun.java_cup.internal.runtime.Scanner;
//import com.sun.java_cup.internal.runtime.Symbol;

import config.ETS;
import config.ItfCurrentSense.Enmchannel;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;


/**
 * @author mmegahed
 * @version 2.0
 * @created 29-May-2019 12:00:00 PM
 * @updated 11-Dec-2019	03:32:00 PM
 */

public class TemperatureSensor {
	
	private static float[][] tempLookUp=
	{
			{125	,(float)0.607843},
			{120	,(float)0.686275},
			{115	,(float)0.764706},
			{110	,(float)0.862745},
			{105	,(float)0.980392},
			{100	,(float)1.098039},
			{95		,(float)1.235294},
			{90		,(float)1.372549},
			{85		,(float)1.54902	},
			{80		,(float)1.72549 },
			{75		,(float)1.901961},
			{70		,(float)2.098039},
			{65		,(float)2.294118},
			{60		,(float)2.509804},
			{55		,(float)2.72549 },
			{50		,(float)2.921569},
			{45		,(float)3.117647},
			{40		,(float)3.313725},
			{35		,(float)3.490196},
			{30		,(float)3.666667},
			{25		,(float)3.803922},
			{20		,(float)3.941176},
			{15		,(float)4.058824},
			{10		,(float)4.156863},
			{5		,(float)4.235294},
			{0		,(float)4.294118},
			{-5		,(float)4.352941},
			{-10	,(float)4.392157},
			{-15	,(float)4.431373},
			{-20	,(float)4.470588},
			{-30	,(float)4.490196},
			{-25	,(float)4.490196},
			{-35	,(float)4.509804},
			{-40	,(float)4.529412}

	};
	private static  float vTemp;
	/**
	 * Setting temperature sensor output to the controller V_TEMP
	 * @param temp: ECU temperature
	 */
	public static float getTemperatureSensorValue (float temp){

		
		if (temp<-40)
		{
			return 5;
		}
		else if (temp > 125)
		{
			return 0;
		}
		for (int i =0;i<34;i++)
		{
			float x0 =tempLookUp[i][0];
			float x1 =tempLookUp[i+1][0];
			
			float y0 = tempLookUp[i][1];
			float y1 = tempLookUp[i+1][1];
			
			if (temp == x0)
			{
				return y0;
			}
			
			
			else if (temp == x1)
			{
				return y1;
			}

			else if (temp<tempLookUp[i][0]&&temp>tempLookUp[i+1][0])
			{
				vTemp = ((y0)*(1-((temp-x0)/(x1-x0))))+((y1)*(1-((x1-temp)/(x1-x0))));
				break;
			}
			
			else
			{
				continue;
			}
		}
		return vTemp;
	}
	

	
	//main function to test functions 
	
	/*
	 * public static void main(String[] args) {
	 * 
	 * 
	 * System.out.println(getTemperatureSensorValue(0f));
	 * 
	 * }
	 */

}