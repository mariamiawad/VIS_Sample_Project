package libs.TestingPlatform.TestingProcLayer.ILexternalLib;

public class OfflightRGB {

	/**************************************************************************
	 * ********************** Private variables ********************************
	 *************************************************************************/
	private static boolean bOVDefectStatus = false;
	private static boolean bUVDefectStatus = false;

	private static boolean bSCDefectStatus = false;
	private static boolean bOCDefectStatus = false;

	private static boolean bOTDefectStatus = false;

	private static boolean bLBFaultStatus = false;

	private static double dDCderating = 100;

	private static final int aiRawCommandPoints[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	private static final int aiDimmedCommandPoints[] = { 0, 1, 3, 6, 9, 14, 22, 34, 50, 72, 100 };

	private static int ThermDerHighThreshold = 60;
	private static int ThermDerLowThreshold = 55;
	private static int ThermShutdownHighThreshold = 80;
	private static int ThermDerStep = 10;

	private static double TempFiltered = 25;

	private static double VltFiltered = 12;

	private static double DcRedcmd = 0;
	private static double DcGreencmd = 0;
	private static double DcBluecmd = 0;
	
	private static double RawCommandRed=0,RawCommandGreen=0,RawCommandBlue=0;
	
	private static final int RED = 0;
	private static final int GREEN = 1;
	private static final int BLUE = 2;

	/** private static final int NUM_LED_OlderAge = 1000;
	private static final int INTERPOLATION_FACTOR = 16;
	private static int NUM_LED_OperationTime = 10;
	private static final int u8CONV_MATRIX_SIZE = 3;
	private static final int[][] Coeff_ConvMat_Cold0 = { { 26281, 14315, 2191 }, { 6504, 24046, 4426 },
			{ -12176, 1040, 2264 } };

	private static final int[][] Coeff_ConvMat_Hot0 = { { 18761, 404, 6603 }, { 13967, 23591, -1211 },
			{ 20428, 6221, -133 } };

	private static final int[][] Coeff_ConvMat_Cold1 = { { 26281, 14315, 2191 }, { 6504, 24046, 4426 },
			{ -12176, 1040, 2264 } };

	private static final int[][] Coeff_ConvMat_Hot1 = { { 18761, 404, 6603 }, { 13967, 23591, -1211 },
			{ 20428, 6221, -133 } };

	private static final int MatriceCie[][] = { { 3190, 531, 2559 }, { 1433, 2252, 511 }, { -1, 344, 13994 } };

	private static int[][] Coeff_ConvMat_A = new int[3][3];
	private static int[][] Coeff_ConvMat_B = new int[3][3];

	private static final int LBTY_s32MAX_VALUE = 2147483647;

	private static double[] NUM_VLED = { 0, 0, 0 };

	private static int Coeff_ConvMat[][] = new int[3][3];

	private static int[] RGB2_Setpoint = new int[3];

	private static int[] RGB_SelSetPoint = new int[3];

	private static boolean FLAG_CD_FaultDetected = false;

	private static final int Max_Num_Of_16Bit = 65535;

	private static final int RED = 0;
	private static final int GREEN = 1;
	private static final int BLUE = 2;

	private static int[] RGB2_SetpointRamped = { 0, 0, 0 };

	private static final int NUM_DefaultRampTime = 500;

	private static final int TIME_OF_COLOR_Conversion = 10;*/

	/**
	 * End of Private variables
	 *************************************************************************/
	
	/**************************************************************************
	 * ********************** Public Functions ********************************
	 *************************************************************************/
	/**
	 * Initialization: Initialize all defects as false, DCderating=100%,
	 * Temperature value by 25, Input voltage = 12, Output PWM by 0.
	 * 
	 */
	public static void vidRLInit() {

		bOVDefectStatus = false;
		bUVDefectStatus = false;

		bSCDefectStatus = false;
		bOCDefectStatus = false;

		bOTDefectStatus = false;

		bLBFaultStatus = false;

		dDCderating = 100;

		TempFiltered = 25;

		VltFiltered = 12;

		DcRedcmd = 0;
		DcGreencmd = 0;
		DcBluecmd = 0;
	}
	/**
	 * End of Initialization Function
	 ***********************************************************************/
	/**
	 * vidRGBSetTemp: - Input: Temperature value. This function used to manually
	 * set temperature value.
	 */
	public static void vidRGBSetTemp(double temp) {
		TempFiltered = temp;
	}

	/**
	 * End of vidRGBSetTemp Function
	 ***********************************************************************/
	/**
	 * vidRGBSetVolt: - Input: Input voltage value. This function used to
	 * manually set voltage value.
	 */
	public static void vidRGBSetVolt(double volt) {
		VltFiltered = volt;
	}

	/**
	 * End of vidRGBSetTemp Function
	 ***********************************************************************/
	/**
	 * vidRGBOV_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate an over voltage defect
	 */
	public static void vidRGBOV_Defect(boolean status) {
		bOVDefectStatus = status;
	}

	/**
	 * End of vidRGBOV_Defect Function
	 ***********************************************************************/
	/**
	 * vidRGBUV_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate an under voltage defect
	 */
	public static void vidRGBUV_Defect(boolean status) {
		bUVDefectStatus = status;
	}

	/**
	 * End of vidRGBUV_Defect Function
	 ***********************************************************************/
	/**
	 * vidRGBSC_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate short circuit defect
	 */
	public static void vidRGBSC_Defect(boolean status) {
		bSCDefectStatus = status;
	}

	/**
	 * End of vidRGBSC_Defect Function
	 ***********************************************************************/
	/**
	 * vidRGBOC_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate open circuit defect
	 */
	public static void vidRGBOC_Defect(boolean status) {
		bOCDefectStatus = status;
	}

	/**
	 * End of vidRGBOC_Defect Function
	 ***********************************************************************/
	/**
	 * vidRGBOT_Defect: - Input: Validate or invalidate. This function used to
	 * manually generate over temperature defect
	 */
	public static void vidRGBOT_Defect(boolean status) {
		bOTDefectStatus = status;
	}

	/**
	 * End of vidRGBOT_Defect Function
	 ***********************************************************************/
	/**
	 * vidRGBLB_Fault: - Input: Validate or invalidate. This function used to
	 * manually generate LIN bus fault.
	 */
	public static void vidRGBLB_Fault(boolean status) {
		bLBFaultStatus = status;
	}

	/**
	 * End of vidRGBLB_Fault Function
	 ***********************************************************************/
	/**
	 * dRGBGetPWM: This function used to calculate the O/P PWM for the RGB 
	 * light.
	 * */
	public static double[] dRGBGetPWM(int Redcommand, int Greencommand, int Bluecommand){
		double DCRGBcmd[] = new double[3];
		double dAlpha[] = new double[3];
		/** Map the input command from 0-255 to 0-100%*/
		DCRGBcmd[RED]  = dLightCommand(Redcommand);
		DCRGBcmd[GREEN]  = dLightCommand(Greencommand);
		DCRGBcmd[BLUE]  = dLightCommand(Bluecommand);
		/** Check if Valid value */
		/** True: update DcRedcmd value */
		if(DCRGBcmd[RED] != -1){
			RawCommandRed  = DCRGBcmd[RED];
		}
		/** False: do nothing*/
		else{
			// Do nothing
		}
		/** True: update DcGreencmd value */
		if(DCRGBcmd[GREEN] != -1){
			RawCommandGreen  = DCRGBcmd[GREEN];
		}
		/** False: do nothing*/
		else{
			// Do nothing
		}
		/** True: update DcBluecmd value */
		if(DCRGBcmd[BLUE] != -1){
			RawCommandBlue  = DCRGBcmd[BLUE];
		}
		/** False: do nothing*/
		else{
			// Do nothing
		}
		/** Apply the output to Dimming conversion function */
		DcRedcmd  = dDimmingConversion(RawCommandRed);
		DcGreencmd  = dDimmingConversion(RawCommandGreen);
		DcBluecmd  = dDimmingConversion(RawCommandBlue);
		/** Update the DC_Derating value*/
		vidThermalDerating();
		/** Get Alpha value*/
		dAlpha = dGetAlphaValue();
		/** PWM = DcGreencmd * DCderating * alpha */
		DcRedcmd = ( (DcRedcmd * dDCderating) / 100 ) * dAlpha[RED];
		DcGreencmd = ( (DcGreencmd * dDCderating) / 100 ) * dAlpha[GREEN];
		DcBluecmd = ( (DcBluecmd * dDCderating) / 100 ) * dAlpha[BLUE];
		/** Check if the output bigger than 100% saturate it to 100%*/
		if(DcRedcmd >= 100){
			DcRedcmd = 100;
		}
		if(DcGreencmd >= 100){
			DcGreencmd = 100;
		}
		if(DcBluecmd >= 100){
			DcBluecmd = 100;
		}
		/** Check if any defect existing */
		if(bSCDefectStatus == true){
			DcRedcmd=0;
			DcGreencmd=0;
			DcBluecmd=0;
		}
		if(bOCDefectStatus == true){
			DcRedcmd=0;
			DcGreencmd=0;
			DcBluecmd=0;
		}
		if(bOVDefectStatus == true){
			DcRedcmd=0;
			DcGreencmd=0;
			DcBluecmd=0;
		}
		if(bUVDefectStatus == true){
			DcRedcmd=0;
			DcGreencmd=0;
			DcBluecmd=0;
		}
		if(bOTDefectStatus == true){
			DcRedcmd=0;
			DcGreencmd=0;
			DcBluecmd=0;
		}
		if(bLBFaultStatus == true){
			DcRedcmd=0;
			DcGreencmd=0;
			DcBluecmd=0;
		}
		/** Update DCRGBcmd values*/
		DCRGBcmd[RED]=DcRedcmd;
		DCRGBcmd[GREEN]=DcGreencmd;
		DCRGBcmd[BLUE]=DcBluecmd;
		
		return DCRGBcmd;
	}
	/**
	 * End of dRGBGetPWM function
	 * ************************************************************************/
	
	/**************************************************************************
	 * ********************** Private Functions ********************************
	 *************************************************************************/
	/**
	 * dLightCommand: 
	 * if input command ( 0 - 64 )h mapped to ( 0 - 100 )%
	 * if input command ( 64 - FE )h mapped to 100%
	 * if input command FFh mapped to invalid value.
	 * */
	private static double dLightCommand(int command){
		double TargetPWMValue = 0;
		/**if input command ( 0 - 64 )h mapped to ( 0 - 100 )% */
		if(command>=0 && command<=100){
			TargetPWMValue = command;
		}
		/** if input command ( 64 - FE )h mapped to 100% */
		else if (command>100 && command<=254){
			TargetPWMValue = 100;
		}
		/** if input command FFh mapped to invalid value. */
		else if (command == 255){
			TargetPWMValue = -1;
		}
		else{
			/** Do nothing*/
		}
		
		return TargetPWMValue;
	}
	/**
	 * End of LightCommand Function
	 ***********************************************************************/
	/**
	 * dDimmingConversion: 
	 * */
	private static double dDimmingConversion(double command){
		double TargetPWMValue=0;
		
		if(command>=aiRawCommandPoints[0] && command<aiRawCommandPoints[1]){
			TargetPWMValue = dLinearInterpol(0,1,command);
		}
		else if(command>=aiRawCommandPoints[1] && command<aiRawCommandPoints[2]){
			TargetPWMValue = dLinearInterpol(1,2,command);
		}
		else if(command>=aiRawCommandPoints[2] && command<aiRawCommandPoints[3]){
			TargetPWMValue = dLinearInterpol(2,3,command);
		}
		else if(command>=aiRawCommandPoints[3] && command<aiRawCommandPoints[4]){
			TargetPWMValue = dLinearInterpol(3,4,command);
		}
		else if(command>=aiRawCommandPoints[4] && command<aiRawCommandPoints[5]){
			TargetPWMValue = dLinearInterpol(4,5,command);
		}
		else if(command>=aiRawCommandPoints[5] && command<aiRawCommandPoints[6]){
			TargetPWMValue = dLinearInterpol(5,6,command);
		}
		else if(command>=aiRawCommandPoints[6] && command<aiRawCommandPoints[7]){
			TargetPWMValue = dLinearInterpol(6,7,command);
		}
		else if(command>=aiRawCommandPoints[7] && command<aiRawCommandPoints[8]){
			TargetPWMValue = dLinearInterpol(7,8,command);
		}
		else if(command>=aiRawCommandPoints[8] && command<aiRawCommandPoints[9]){
			TargetPWMValue = dLinearInterpol(8,9,command);
		}
		else if(command>=aiRawCommandPoints[9] && command<=aiRawCommandPoints[10]){
			TargetPWMValue = dLinearInterpol(9,10,command);
		}
		else{
			// Do nothing
		}
		return TargetPWMValue;
		
	}
	/**
	 * End of dDimmingConversion Function
	 ***********************************************************************/
	/**
	 * dLinearInterpol: 
	 * */
	private static double dLinearInterpol(int index1,int index2,double command){
		double TargetPWMValue;
		
		TargetPWMValue = 
				( ( (double)(aiDimmedCommandPoints[index2]-aiDimmedCommandPoints[index1]) / 
				   (aiRawCommandPoints[index2]-aiRawCommandPoints[index1]) ) *
				 (command-aiRawCommandPoints[index1]) ) + aiDimmedCommandPoints[index1]; 
		
		return TargetPWMValue;
	}
	/**
	 * End of dLinearInterpol Function
	 **************************************************************************/
	/**
	 * vidThermalDerating:	- Output: dDCderating range from 0 to 100
	 * */
	private static void vidThermalDerating(){
		
		if( TempFiltered >= ThermShutdownHighThreshold ){
			dDCderating = 0;
		}
		
		if( TempFiltered > ThermDerHighThreshold && TempFiltered < ThermShutdownHighThreshold ){
			dDCderating -= ThermDerStep;
			
			if( dDCderating <= 0){
				dDCderating = 0;
			}
		}
		
		if( TempFiltered < ThermDerLowThreshold ){
			dDCderating += ThermDerStep;
			
			if( dDCderating >= 100){
				dDCderating = 100;
			}
		}
	}
	/**
	 * End of vidThermalDerating Function
	 **************************************************************************/
	/**
	 * dGetAlphaValue:	- Output: alpha 
	 * */
	private static double[] dGetAlphaValue(){
		double alpha[] = new double[3];
		
		alpha[RED] = 3.99 / (VltFiltered - 2.1);
		alpha[GREEN] = 2.48 / (VltFiltered - 3.3);
		alpha[BLUE] = 8.7325 / (VltFiltered - 3.3);
		
		return alpha;
	}
	/**
	 * End of vidThermalDerating Function
	 *  * *********************************************************************/
	/**
	 * vidSelectConversionMatrix:
	 * *
	private static void vidSelectConversionMatrix() {

		int s16CoolerYoungerLoc = 0;
		int s16HotterYoungerLoc = 0;
		int s16CoolerOlderLoc = 0;
		int s16HotterOlderLoc = 0;
		int s16AgeingValueLoc;
		/* int s16AgeStart = BTY_s16ZERO ; *
		int s16AgeEnd = NUM_LED_OlderAge / INTERPOLATION_FACTOR;
		int u8LineIdxLoc;
		int u8ColumnIdxLoc;

		/* !Pseudo: Get ageing of RGB LED *
		s16AgeingValueLoc = NUM_LED_OperationTime / INTERPOLATION_FACTOR;

		for (u8LineIdxLoc = 0; u8LineIdxLoc < u8CONV_MATRIX_SIZE; u8LineIdxLoc++) {
			for (u8ColumnIdxLoc = 0; u8ColumnIdxLoc < u8CONV_MATRIX_SIZE; u8ColumnIdxLoc++) {
				s16CoolerYoungerLoc = Coeff_ConvMat_Cold0[u8LineIdxLoc][u8ColumnIdxLoc];
				s16HotterYoungerLoc = Coeff_ConvMat_Hot0[u8LineIdxLoc][u8ColumnIdxLoc];
				s16CoolerOlderLoc = Coeff_ConvMat_Cold1[u8LineIdxLoc][u8ColumnIdxLoc];
				s16HotterOlderLoc = Coeff_ConvMat_Hot1[u8LineIdxLoc][u8ColumnIdxLoc];

				Coeff_ConvMat_A[u8LineIdxLoc][u8ColumnIdxLoc] = s32ExtrapoleInterpole(0/* s16AgeStart *, s16AgeEnd,
						s16CoolerYoungerLoc, s16CoolerOlderLoc, s16AgeingValueLoc);

				Coeff_ConvMat_B[u8LineIdxLoc][u8ColumnIdxLoc] = s32ExtrapoleInterpole(0/* s16AgeStart *, s16AgeEnd,
						s16HotterYoungerLoc, s16HotterOlderLoc, s16AgeingValueLoc);

			}
		}
		return;
	}
	/**
	 * End of vidSelectConversionMatrix Function
	 *  * *********************************************************************/
	/**
	 * RGB_Color_Conversion:
	 * *
	private static void RGB_Color_Conversion() // every 10ms
	{
		// RGB2_Setpoint[3x1] has value from 0 to 65535 with Resolution 1

		int RGB3_SetPoint_A[] = new int[3];
		RGB2_Setpoint[0] = '0'; // initialized by 0
		RGB2_Setpoint[1] = '0';
		RGB2_Setpoint[2] = '0';

		GetCOEF_ConvMat();

		Mul_2_MAT(Coeff_ConvMat, RGB_SelSetPoint, RGB3_SetPoint_A);

		if (CheckAndCorrect_for_NegValues(RGB3_SetPoint_A) == true) {
			FLAG_CD_FaultDetected = true;

		} else {
			FLAG_CD_FaultDetected = false;
		}

		int Max_RGB3_SetPoint_A = GET_Max_Value(RGB3_SetPoint_A);

		while (Max_RGB3_SetPoint_A > Max_Num_Of_16Bit) {
			RGB3_SetPoint_A[RED] = RGB3_SetPoint_A[RED] / 2;
			RGB3_SetPoint_A[GREEN] = RGB3_SetPoint_A[GREEN] / 2;
			RGB3_SetPoint_A[BLUE] = RGB3_SetPoint_A[BLUE] / 2;
			Max_RGB3_SetPoint_A = Max_RGB3_SetPoint_A / 2;
		}

		RGB2_Setpoint[RED] = RGB3_SetPoint_A[RED];
		RGB2_Setpoint[GREEN] = RGB3_SetPoint_A[GREEN];
		RGB2_Setpoint[BLUE] = RGB3_SetPoint_A[BLUE];

	}
	/**
	 * End of RGB_Color_Conversion Function
	 *  * *********************************************************************/
	/**
	 * LinearColor_Ramp:
	 * *
	private static void LinearColor_Ramp(int Counter_LCR) // every 10ms
	{
		int[] RGB2_SetpointStart = new int[3];
		int[] RGB2_SetpointEnd = new int[3];
		int Ramp_Time = 0;

		if (Check_If_Equal_3x1(RGB2_SetpointRamped, RGB2_Setpoint) == false) {
			Copy_Matrix_3x1_Int(RGB2_SetpointStart, RGB2_SetpointRamped);
			Copy_Matrix_3x1_Int(RGB2_SetpointEnd, RGB2_Setpoint);
			Ramp_Time = NUM_DefaultRampTime; // can use Ramp time from LIN
		}

		RGB2_SetpointRamped[RED] = (int) (RGB2_SetpointStart[RED]
				+ ((double) Counter_LCR * TIME_OF_COLOR_Conversion / Ramp_Time)
						* (RGB2_SetpointEnd[RED] - RGB2_SetpointStart[RED]));
		RGB2_SetpointRamped[GREEN] = (int) (RGB2_SetpointStart[GREEN]
				+ ((double) Counter_LCR * TIME_OF_COLOR_Conversion / Ramp_Time)
						* (RGB2_SetpointEnd[GREEN] - RGB2_SetpointStart[GREEN]));
		RGB2_SetpointRamped[BLUE] = (int) (RGB2_SetpointStart[BLUE]
				+ ((double) Counter_LCR * TIME_OF_COLOR_Conversion / Ramp_Time)
						* (RGB2_SetpointEnd[BLUE] - RGB2_SetpointStart[BLUE]));

	}
	/**
	 * End of LinearColor_Ramp Function
	 *  * *********************************************************************/
	/**
	 * s32ExtrapoleInterpole:
	 * *
	private static int s32ExtrapoleInterpole(int s16Abcissa1Cpy, int s16Abscissa2Cpy, int s32Ordinate1Cpy,
			int s32Ordinate2Cpy, int s16PointCpy) {
		int s32RetResult;
		int s32Var1Loc;
		int s16Var2Loc;
		int s32Var3Loc;

		if (s16Abscissa2Cpy != s16Abcissa1Cpy) {
			s32Var1Loc = s32Ordinate2Cpy - s32Ordinate1Cpy;

			s16Var2Loc = s16PointCpy - s16Abcissa1Cpy;

			s32Var3Loc = s32Var1Loc * s16Var2Loc;

			s16Var2Loc = s16Abscissa2Cpy - s16Abcissa1Cpy;

			s32Var3Loc = s32Var3Loc / s16Var2Loc;

			s32RetResult = s32Var3Loc + s32Ordinate1Cpy;
		} else {
			s32RetResult = LBTY_s32MAX_VALUE;
		}

		return s32RetResult;
	}
	/**
	 * End of s32ExtrapoleInterpole Function
	 *  * *********************************************************************/
	/**
	 * GetCOEF_ConvMat:
	 * *
	private static void GetCOEF_ConvMat() {
		int as32Matrix1[][] = new int[3][3];
		vidArcmColorConversionInterpLedModel(
				as32Matrix1); /* as32Matrix1 = LED xyY Model *
		vidArcmColorConversionXYZTransform(as32Matrix1,
				Coeff_ConvMat); /* as32Matrix2 = LED XYZ Model *
		vidArcmColorConversionNormalizeMatrix(Coeff_ConvMat);
		vidArcmColorConversionMatrixInverse(Coeff_ConvMat, as32Matrix1);
		vidArcmColorConversionNormalizeMatrix(as32Matrix1);
		vidArcmColorConversionMatrixMulCie(as32Matrix1,
				Coeff_ConvMat); /* as32Matrix2 = MCie/MLed *
		vidArcmColorConversionNormalizeMatrix(Coeff_ConvMat);
	}
	/**
	 * End of GetCOEF_ConvMat Function
	 *  * *********************************************************************/
	/**
	 * vidArcmColorConversionInterpLedModel:
	 * *
	private static void vidArcmColorConversionInterpLedModel(int[][] as32MatrixOut) {

		int u8ColumnIdxLoc;
		int u8LineIdxLoc;
		int s16CurrentVfLoc;

		for (u8ColumnIdxLoc = 0; u8ColumnIdxLoc < 3; u8ColumnIdxLoc++) {
			s16CurrentVfLoc = (int) (((int) (NUM_VLED[u8ColumnIdxLoc] * 1023 / 5) * 7500 / 1023));

			for (u8LineIdxLoc = 0; u8LineIdxLoc < 3; u8LineIdxLoc++) {

				as32MatrixOut[u8LineIdxLoc][u8ColumnIdxLoc] = ((int) (Coeff_ConvMat_A[u8LineIdxLoc][u8ColumnIdxLoc]));
				as32MatrixOut[u8LineIdxLoc][u8ColumnIdxLoc] = as32MatrixOut[u8LineIdxLoc][u8ColumnIdxLoc]
						+ ((((int) Coeff_ConvMat_B[u8LineIdxLoc][u8ColumnIdxLoc])
								- ((int) Coeff_ConvMat_A[u8LineIdxLoc][u8ColumnIdxLoc])) * ((int) s16CurrentVfLoc))
								/ ((int) 4000);
			}
		}
	}
	/**
	 * End of vidArcmColorConversionInterpLedModel Function
	 *  * *********************************************************************/
	/**
	 * vidArcmColorConversionXYZTransform:
	 * *
	private static void vidArcmColorConversionXYZTransform(int[][] as32MatrixIn, int[][] as32MatrixOut) {

		int u8ColumnIdxLoc;

		for (u8ColumnIdxLoc = 0; u8ColumnIdxLoc < 3; u8ColumnIdxLoc++) {
			as32MatrixOut[0][u8ColumnIdxLoc] = (int) (((int) (as32MatrixIn[0][u8ColumnIdxLoc]))
					* ((int) (as32MatrixIn[2][u8ColumnIdxLoc])));
			as32MatrixOut[0][u8ColumnIdxLoc] = as32MatrixOut[0][u8ColumnIdxLoc]
					/ ((int) (as32MatrixIn[1][u8ColumnIdxLoc]));
			as32MatrixOut[1][u8ColumnIdxLoc] = (int) (as32MatrixIn[2][u8ColumnIdxLoc]);
			as32MatrixOut[2][u8ColumnIdxLoc] = (int) (((int) ((int) (32768 - as32MatrixIn[0][u8ColumnIdxLoc]
					- as32MatrixIn[1][u8ColumnIdxLoc]) * as32MatrixIn[2][u8ColumnIdxLoc]))
					/ as32MatrixIn[1][u8ColumnIdxLoc]);
		}
	}
	/**
	 * End of vidArcmColorConversionXYZTransform Function
	 *  * *********************************************************************/
	/**
	 * vidArcmColorConversionNormalizeMatrix:
	 * *
	private static void vidArcmColorConversionNormalizeMatrix(int[][] as32Matrix) {
		int u8ColumnIdxLoc;
		int u8LineIdxLoc;
		int u16ShiftPosLoc;
		int s16FirstSetBitPositionloc = 0;
		int s32Max = ((int) -2147483647 - 1);
		int s32Min = ((int) 2147483647);
		int u32Tmp;
		int s32Tmp;

		for (u8LineIdxLoc = 0; u8LineIdxLoc < 3; u8LineIdxLoc++) {
			for (u8ColumnIdxLoc = 0; u8ColumnIdxLoc < 3; u8ColumnIdxLoc++) {
				s32Tmp = as32Matrix[u8LineIdxLoc][u8ColumnIdxLoc];
				if (s32Tmp > s32Max)
					s32Max = s32Tmp;
				if (s32Tmp < s32Min)
					s32Min = s32Tmp;
			}
		}

		u32Tmp = LMATH_u32GetAbsValue(s32Min);
		if ((int) u32Tmp < s32Max) {
			u32Tmp = (int) s32Max;
		}
		s16FirstSetBitPositionloc = _fsb((int) (u32Tmp >> 16));
		/* while *
		if (s16FirstSetBitPositionloc > 0) {
			u16ShiftPosLoc = ((int) 1 + (int) s16FirstSetBitPositionloc);
			for (u8LineIdxLoc = 0; u8LineIdxLoc < 3; u8LineIdxLoc++) {
				for (u8ColumnIdxLoc = 0; u8ColumnIdxLoc < 3; u8ColumnIdxLoc++) {
					if (as32Matrix[u8LineIdxLoc][u8ColumnIdxLoc] >= 0) {
						as32Matrix[u8LineIdxLoc][u8ColumnIdxLoc] >>= u16ShiftPosLoc;
					} else {
						as32Matrix[u8LineIdxLoc][u8ColumnIdxLoc] = ((as32Matrix[u8LineIdxLoc][u8ColumnIdxLoc] >> u16ShiftPosLoc)
								+ 1);
					}
				}
			}
		}
	}
	/**
	 * End of vidArcmColorConversionNormalizeMatrix Function
	 *  * *********************************************************************/
	/**
	 * LMATH_u32GetAbsValue
	 * *
	private static int LMATH_u32GetAbsValue(int s32ValueCpy) {
		int u32ValueLoc;

		if (s32ValueCpy < ((int) 0)) {
			u32ValueLoc = (int) (-s32ValueCpy);
		} else {
			u32ValueLoc = (int) (s32ValueCpy);
		}

		return (u32ValueLoc);
	}
	/**
	 * End of LMATH_u32GetAbsValue Function
	 *  * *********************************************************************/
	/**
	 * _fsb
	 * *
	private static int _fsb(int v) {
		int result;
		/* fsb(0) = -1 *
		/* note: may be different from MLX16-8/x8 instruction: 0 or -1 *
		if (v == 0) {
			result = -1; /* 0xFFFF *
		} else {
			/* alt: first do a binary tree search *
			int one = 0x8000;

			result = 15;
			/* total time, looping over all 16bit values: 249ms *
			while ((v & one) == 0) {
				one >>= 1;
				result--;
			}
		}

		return result;
	}
	/**
	 * End of _fsb Function
	 *  * *********************************************************************/
	/**
	 * vidArcmColorConversionMatrixInverse
	 * *
	private static void vidArcmColorConversionMatrixInverse(int[][] as32MatrixIn, int[][] as32MatrixInv) {

		as32MatrixInv[0][0] = (as32MatrixIn[1][1] * as32MatrixIn[2][2]) - (as32MatrixIn[2][1] * as32MatrixIn[1][2]);
		as32MatrixInv[1][0] = -1
				* ((as32MatrixIn[1][0] * as32MatrixIn[2][2]) - (as32MatrixIn[2][0] * as32MatrixIn[1][2]));
		as32MatrixInv[2][0] = (as32MatrixIn[1][0] * as32MatrixIn[2][1]) - (as32MatrixIn[2][0] * as32MatrixIn[1][1]);
		as32MatrixInv[0][1] = -1
				* ((as32MatrixIn[0][1] * as32MatrixIn[2][2]) - (as32MatrixIn[2][1] * as32MatrixIn[0][2]));
		as32MatrixInv[1][1] = (as32MatrixIn[0][0] * as32MatrixIn[2][2]) - (as32MatrixIn[2][0] * as32MatrixIn[0][2]);
		as32MatrixInv[2][1] = -1
				* ((as32MatrixIn[0][0] * as32MatrixIn[2][1]) - (as32MatrixIn[2][0] * as32MatrixIn[0][1]));
		as32MatrixInv[0][2] = (as32MatrixIn[0][1] * as32MatrixIn[1][2]) - (as32MatrixIn[1][1] * as32MatrixIn[0][2]);
		as32MatrixInv[1][2] = -1
				* ((as32MatrixIn[0][0] * as32MatrixIn[1][2]) - (as32MatrixIn[1][0] * as32MatrixIn[0][2]));
		as32MatrixInv[2][2] = (as32MatrixIn[0][0] * as32MatrixIn[1][1]) - (as32MatrixIn[1][0] * as32MatrixIn[0][1]);
	}
	/**
	 * End of vidArcmColorConversionMatrixInverse Function
	 *  * *********************************************************************/
	/**
	 * vidArcmColorConversionMatrixMulCie
	 * *
	private static void vidArcmColorConversionMatrixMulCie(int[][] as32MatrixIn, int[][] as32MatrixOut) {

		int u8LineIdxLoc;
		int u8ColumnIdxLoc;
		int u8IdxLoc;

		for (u8LineIdxLoc = 0; u8LineIdxLoc < 3; u8LineIdxLoc++) {
			for (u8ColumnIdxLoc = 0; u8ColumnIdxLoc < 3; u8ColumnIdxLoc++) {
				as32MatrixOut[u8LineIdxLoc][u8ColumnIdxLoc] = 0;
				for (u8IdxLoc = 0; u8IdxLoc < 3; u8IdxLoc++) {
					as32MatrixOut[u8LineIdxLoc][u8ColumnIdxLoc] += as32MatrixIn[u8LineIdxLoc][u8IdxLoc]
							* MatriceCie[u8IdxLoc][u8ColumnIdxLoc];
				}
			}
		}
	}
	/**
	 * End of vidArcmColorConversionMatrixMulCie Function
	 *  * *********************************************************************/
	/**
	 * Mul_2_MAT
	 * *
	private static void Mul_2_MAT(int[][] Coeff_ConvMat, int[] RGB_SelSetPoint, int[] result) {

		for (int i = 0; i < 3; i++) {
			result[i] = Coeff_ConvMat[i][0] * RGB_SelSetPoint[0] + Coeff_ConvMat[i][1] * RGB_SelSetPoint[1]
					+ Coeff_ConvMat[i][2] * RGB_SelSetPoint[2];
		}

	}
	/**
	 * End of Mul_2_MAT Function
	 *  * *********************************************************************/
	/**
	 * CheckAndCorrect_for_NegValues
	 * *
	private static boolean CheckAndCorrect_for_NegValues(int[] MAT) {
		boolean FLAG_Neg_Value = false;
		for (int i = 0; i < 3; i++) {
			if (MAT[i] < 0) {
				MAT[i] = 0; // change negative values to zeros
				FLAG_Neg_Value = true;
			}
		}

		return FLAG_Neg_Value;
	}
	/**
	 * End of CheckAndCorrect_for_NegValues Function
	 *  * *********************************************************************/
	/**
	 * GET_Max_Value
	 * *
	private static int GET_Max_Value(int[] Array) {
		int Max = Array[0];
		if (Array[1] > Max)
			Max = Array[1];
		if (Array[2] > Max)
			Max = Array[2];
		return Max;
	}
	/**
	 * End of GET_Max_Value Function
	 *  * *********************************************************************/
	/**
	 * Check_If_Equal_3x1
	 * *
	private static boolean Check_If_Equal_3x1(int[] Mat1, int[] Mat2) {
		if ((Mat1[0] == Mat2[0]) && (Mat1[1] == Mat2[1]) && (Mat1[2] == Mat2[2]))
			return true;
		else
			return false;
	}
	/**
	 * End of Check_If_Equal_3x1 Function
	 *  * *********************************************************************/
	/**
	 * Copy_Matrix_3x1_Int
	 * *
	private static void Copy_Matrix_3x1_Int(int[] Mat2, int[] Mat1) {
		for (int i = 0; i < 3; i++) {
			Mat2[i] = Mat1[i];
		}
	}
	/**
	 * End of Copy_Matrix_3x1_Int Function
	 *  * *********************************************************************/
	/**
	  *  End of private functions
	  * ***********************************************************************/
}
