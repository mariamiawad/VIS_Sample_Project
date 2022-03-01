package libs.TestingPlatform.TestingProcLayer.VWSLib;

import config.ETS;
import config.ItfCurrentSense.Enmchannel;
import libs.TestingPlatform.TestingTechLayer.CastlePortingMap;
import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;


/**
 * @author mmegahed
 * @version 2.0
 * @created 29-May-2019 10:56:00 PM
 * @updated 11-Dec-2019	03:32:00 PM
 */

public class VoltageSensor {

	private static float [][] voltageLookUp =
	{
			{0f		,(float) 0			},
			{1f		,(float) 0.137254902 },
			{2f		,(float) 0.2745098039},
			{3f		,(float) 0.3921568627},
			{4f		,(float) 0.5294117647},
			{5f		,(float) 0.6666666667},
			{6f		,(float) 0.7843137255},
			{7f		,(float) 0.9215686275},
			{7.5f	,(float) 0.9803921569},
			{8f		,(float) 1.058823529 },
			{8.5f	,(float) 1.117647059 },
			{9f		,(float) 1.176470588 },
			{9.5f	,(float) 1.254901961 },
			{10f	,(float) 1.31372549  },
			{10.5f	,(float) 1.37254902  },
			{11f	,(float) 1.450980392 },
			{11.5f	,(float) 1.509803922 },
			{12f	,(float) 1.568627451 },
			{12.5f	,(float) 1.647058824 },
			{13f	,(float) 1.705882353 },
			{13.5f	,(float) 1.764705882 },
			{14f	,(float) 1.843137255 },
			{14.5f	,(float) 1.901960784 },
			{15f	,(float) 1.960784314 },
			{15.5f	,(float) 2.039215686 },
			{16f	,(float) 2.098039216 },
			{16.5f	,(float) 2.156862745 },
			{17f	,(float) 2.235294118 },
			{17.5f	,(float) 2.294117647 },
			{18f	,(float) 2.352941176 },
			{19f	,(float) 2.490196078 },
			{20f	,(float) 2.62745098  },
			{21f	,(float) 2.745098039 },
			{22f	,(float) 2.882352941 },
			{23f	,(float) 3.019607843 },
			{24f	,(float) 3.137254902 },
			{25f	,(float) 3.274509804 },
			{26f	,(float) 3.411764706 },
			{27f	,(float) 3.529411765 },
			{28f	,(float) 3.666666667 },
			{29f	,(float) 3.803921569 },
			{30f	,(float) 3.921568627 },
			{31f	,(float) 4.058823529 },
			{32f	,(float) 4.196078431 },
			{33f	,(float) 4.31372549  },
			{34f	,(float) 4.450980392 },
			{35f	,(float) 4.588235294 },
			{36f	,(float) 4.705882353 },
			{36.1f	,(float) 4.725490196 },
			{36.9f	,(float) 4.823529412 }
				
	
	};
	
	/**
	 * Setting voltage sensor output to the controller VBATDETECT
	 * @param voltage: Supply voltage
	 */
	private static float VBATDETECT ;
	public static float getVoltageSensorValue (float voltage)
	{
		/*
		 * if (voltage <=1) { return 0f; } else if (voltage >=30) { return 5f; } else {
		 * return (voltage-0.15f)*(10f/76.5f); }
		 */
		 
		if (voltage<0)
		{
			return 0;
		}
		else if (voltage >= 37)
		{
			return 5;
		}
		for (int i =0;i<49;i++)
		{
			float x0 =voltageLookUp[i][0];
			float x1 =voltageLookUp[i+1][0];
			
			float y0 = voltageLookUp[i][1];
			float y1 = voltageLookUp[i+1][1];
			
			if (voltage == x0)
			{
				return y0;
			}
			
			
			else if (voltage == x1)
			{
				return y1;
			}

			else if (voltage>voltageLookUp[i][0]&&voltage<voltageLookUp[i+1][0])
			{
				VBATDETECT = ((y0)*(1-((voltage-x0)/(x1-x0))))+((y1)*(1-((x1-voltage)/(x1-x0))));
				break;
			}
			
			else
			{
				continue;
			}
		}
		return VBATDETECT;
	}
	
	
	 
	 //main function to test voltage sensor function
	
	/*
	 * public static void main (String[] args) {
	 * System.out.println(getVoltageSensorValue(40)); }
	 */
	 
}