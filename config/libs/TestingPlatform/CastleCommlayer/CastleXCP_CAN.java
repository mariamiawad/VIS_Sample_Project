package libs.TestingPlatform.CastleCommlayer;

import java.math.BigDecimal;
import java.math.BigInteger;
import castle.testenv.base.config.IEvent;
import config.ETS;
import config.Itf_ComFrameCanTx;
import config.Itf_SignalRaw;
import config.Itf_SignalValue;
import config.Itf_SignalValue.EnmCANFrameEndianness;
import config.Itf_SignalValue.EnmToleranceType;

/**
 * XCP Library
 * 
 * @author Hosam-Eldin Mostafa
 * @version 6.1
 * @created 28-Jan-2018 3:53:45 PM
 * @updated maboelkh: 22-Feb-2018 -> V5.0
 * @updated maboelkh: 30-Jan-2019 -> V6.0
 * @updated maboelkh: 14-Feb-2019 -> V6.1
 */
public class CastleXCP_CAN
{
	private Itf_ComFrameCanTx 	XCP_Request_ComFrameCanTxObj_Left;
	private Itf_SignalRaw 		XCP_Request_FrameSignalRawTxObj_Left;
	private Itf_SignalRaw 		XCP_Response_FrameSignalRawRxObj_Left;
	private Itf_SignalValue 		XCP_Response_FrameSignalValueRxObj_Left;
	
	private Itf_ComFrameCanTx 	XCP_Request_ComFrameCanTxObj_Right;
	private Itf_SignalRaw 		XCP_Request_FrameSignalRawTxObj_Right;
	private Itf_SignalRaw 		XCP_Response_FrameSignalRawRxObj_Right;
	private Itf_SignalValue 		XCP_Response_FrameSignalValueRxObj_Right;
	
	private EnmCANFrameEndianness CANFrameEndianType;
	
	private double 				XCP_Connect_TimeoutDelay;
	private double 				XCP_SendMTA_TimeoutDelay;
	private double 				XCP_GetData_TimeoutDelay;
	private double 				XCP_SetData_TimeoutDelay;
	
	private String 		Prepared_Address_Hex = "";
	private String 		Prepared_Data_Hex = "";
	
	private long   		Prepared_Data= 0;
	private BigInteger  Prepared_Data_Big;
    private BigDecimal  Prepared_Data_BigD;
	
	private Itf_ComFrameCanTx 	XCP_Request_ComFrameCanTxObj;
	private Itf_SignalRaw 		XCP_Request_FrameSignalRawTxObj;
	private Itf_SignalRaw 		XCP_Response_FrameSignalRawRxObj;
	private Itf_SignalValue 	XCP_Response_FrameSignalValueRxObj;
	
	public enum  RLConfiguration 
	{
		Right,Left
	};
	
	/**
	 * @description: CastleXCP_CAN Library Initialization function
	 * @TODO Initialize Library Used XCP Frames according to Project Frames
	 * @TODO Configure CANFrameEndianType according to Project Configuration
	 * @TODO Configure Timeout Delays according to Project Configuration
	 */	
	private void Init_CastleXCP_CAN()
	{
		//TODO Configure CANFrameEndianType according to Project Configuration
//		CANFrameEndianType = EnmCANFrameEndianness.LittleEndian;
		
		//TODO Configure Timeout Delays according to Project Configuration
//		XCP_Connect_TimeoutDelay = 500;
//		XCP_SendMTA_TimeoutDelay = 500;
//		XCP_GetData_TimeoutDelay = 500;
//		XCP_SetData_TimeoutDelay = 500;

		//TODO Initialize Library Used XCP Left Frames according to Project Frames
//		XCP_Request_ComFrameCanTxObj_Left 			= CAN.Tx_XCP_REQ_L.getFrameObject();
//		XCP_Request_FrameSignalRawTxObj_Left 		= CAN.Tx_XCP_REQ_L.getFrameSignalRaw();
//		XCP_Response_FrameSignalRawRxObj_Left 		= CAN.Rx_XCP_REP_L.getFrameSignalRaw();
//		XCP_Response_FrameSignalValueRxObj_Left 	= CAN.Rx_XCP_REP_L.SIG_Data_xcp_REP_L.getSignalValue();
		
		//TODO Initialize Library Used XCP Right Frames according to Project Frames
//		XCP_Request_ComFrameCanTxObj_Right 			= CAN.Tx_XCP_REQ_R.getFrameObject();
//		XCP_Request_FrameSignalRawTxObj_Right 		= CAN.Tx_XCP_REQ_R.getFrameSignalRaw();
//		XCP_Response_FrameSignalRawRxObj_Right 		= CAN.Rx_XCP_REP_R.getFrameSignalRaw();
//		XCP_Response_FrameSignalValueRxObj_Right 	= CAN.Rx_XCP_REP_R.SIG_Data_xcp_REP_R.getSignalValue();
	}
	
	private void Init_CastleXCP_CAN(RLConfiguration config)
	{
		Init_CastleXCP_CAN();
		
		switch(config)
		{
			case Left:
				XCP_Request_ComFrameCanTxObj 		= XCP_Request_ComFrameCanTxObj_Left;
		  		XCP_Request_FrameSignalRawTxObj 	= XCP_Request_FrameSignalRawTxObj_Left;
		  		XCP_Response_FrameSignalRawRxObj 	= XCP_Response_FrameSignalRawRxObj_Left;
		  		XCP_Response_FrameSignalValueRxObj 	= XCP_Response_FrameSignalValueRxObj_Left;
			break;
			
			case Right:
				XCP_Request_ComFrameCanTxObj 		= XCP_Request_ComFrameCanTxObj_Right;
		  		XCP_Request_FrameSignalRawTxObj 	= XCP_Request_FrameSignalRawTxObj_Right;
		  		XCP_Response_FrameSignalRawRxObj 	= XCP_Response_FrameSignalRawRxObj_Right;
		  		XCP_Response_FrameSignalValueRxObj 	= XCP_Response_FrameSignalValueRxObj_Right;
			break;
			
			default:
			break;
		}
	}
	
	/**
	 * @description: This API is in charge of connecting to the Slave ECU
	 * @param: None
	 * @return: None
	 *  
	 */
	public void XCP_Connect(RLConfiguration config, ETS exu) 
	{
		/*
		 * Set up the connection with the slave
		 * According to XCP protocol, 
		 * you shall send the frame xcp_connect with first byte = FF  
		 */
		
		Init_CastleXCP_CAN(config);
		
		IEvent XCP_Connect_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();
		
		exu.comment("Set up connection with slave ");

		XCP_Request_FrameSignalRawTxObj.afcSet("FF 00 00 00 00 00 00 00");
		XCP_Request_ComFrameCanTxObj.afcSendOnce();

		exu.pauseUntilEvent(XCP_Connect_Event, XCP_Connect_TimeoutDelay);

		XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF 00 00 08 08 00 01 01");
	}

	/**
	 * @description: This API is in charge of disconnecting from slave
	 * @param: None
	 * @return:None
	 * 
	 */
	public void XCP_Disconnect(RLConfiguration config, ETS exu) 
	{
		/*
		 * disconnection from the slave
		 * According to XCP protocol, 
		 * you shall send the frame xcp_disconnect with first byte = FE  
		 */

		Init_CastleXCP_CAN(config);
		
		exu.comment("Disconnect from slave ");
		
		XCP_Request_FrameSignalRawTxObj.afcSet("FE 00 00 00 00 00 00 00");
		XCP_Request_ComFrameCanTxObj.afcSendOnce();
	}

	/**
	 * @description: This API is in charge of sending the MTA, And check the positive response
	 * @param I/P: GlobalVariable object
	 * @return: None
	 * 
	 */
	public void XCP_Set_MTA_And_CheckResponse(int address, RLConfiguration config, ETS exu) 
	{
		/*
		 * MTA : Memory Temporary Address
		 * According to XCP protocol, 
		 * you shall send the frame xcp_address with first byte = F6  
		 * And then the address 
		 */
		 
		Init_CastleXCP_CAN(config);
		
		exu.comment("Send the MTA");
		Send_MTA(address, exu);
	}

	/**
	 * @description: This API is in charge of sending a specific frame
	 * 
	 * @param framename
	 * @param frame
	 * 
	 *  
	 */
	public void XCP_Send_Frame(String framename, String frame, RLConfiguration config)
	{
		Init_CastleXCP_CAN(config);
		
		Send_Frame(framename, frame);
	}

	/**
	 * @description : This API is in charge of getting data from slave and checks the returned data
	 * 
	 * @param I/P: GlobalVariable object
	 * @param I/P: String as the number of data
	 * @param I/P: String as the data expected to be returned 
	 * 
	 */
	public void XCP_Get_data_from_Slave_And_Check(int address, String NumberOfData, String data, RLConfiguration config, ETS exu) 
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F5  
		 * And then the number of data expected to be returned
		 * 
		 * The response consists of FF as positive response then the data 
		 *  
		 */

		Init_CastleXCP_CAN(config);
		
		getData( address,  NumberOfData,  data, exu);

	}
	
	/**
	 * @description : This API is in charge of getting data from slave and checks the returned data
	 * 
	 * @param I/P: GlobalVariable object
	 * @param I/P: String as the number of data
	 * @param I/P: String as the data expected to be returned 
	 * 
	 */
	public void XCP_Get_data_from_Slave_And_Check(int address, String NumberOfData, String Mask, String data, RLConfiguration config, ETS exu) 
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F5  
		 * And then the number of data expected to be returned
		 * 
		 * The response consists of FF as positive response then the data 
		 *  
		 */

		Init_CastleXCP_CAN(config);
		
		getData(address, NumberOfData, Mask, data, exu);

	}
	
	/**
	 * @description : This API is in charge of getting data from slave and checks the returned data
	 * 
	 * @param I/P: GlobalVariable object
	 * @param I/P: String as the number of data
	 * @param I/P: String as the data expected to be returned 
	 * 
	 */
	public void XCP_Get_data_from_Slave_And_Check(int address, String NumberOfData, String[] data, RLConfiguration config, ETS exu) 
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F5  
		 * And then the number of data expected to be returned
		 * 
		 * The response consists of FF as positive response then the data 
		 *  
		 */
		
		Init_CastleXCP_CAN(config);
		
		getData( address,  NumberOfData,  data, exu);
	}


	public void XCP_Get_DataInBoundries_from_Slave_And_Check(int address, String NumberOfData, String[] Data, int ToleranceValue, EnmToleranceType ToleranceType, RLConfiguration config, ETS exu) 
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F5  
		 * And then the number of data expected to be returned
		 * 
		 * The response consists of FF as positive response then the data 
		 *  
		 */
		
		Init_CastleXCP_CAN(config);
		
		getDataInBoundries(address, NumberOfData, Data, ToleranceValue, ToleranceType, exu);
	}

	/**
	 * @description: This API is in charge of sending data to the slave "ECU"
	 * @param I/P: GlobalVariable object
	 * @param I/P: String as the data to be sent
	 * 
	 */
	public void XCP_Set_data_to_Slave(int address, String data, RLConfiguration config, ETS exu) 
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F4  
		 * And then the number of data expected to be returned
		 * 
		 * Note:
		 * No response expected, as per the XCP protocol:
		 * Only return negative response :
		 * if the number of data elements doesn't match the expected value .
		 * The negative response will contain the expected number of data elements 
		 *  
		 */
		
		Init_CastleXCP_CAN(config);
		
		SetData(address, data, exu);
	}

		/**
	 * @description: This API is in charge of sending data to the slave "ECU"
	 * @param I/P: GlobalVariable object
	 * @param I/P: String as the data to be sent
	 * 
	 */
	public void XCP_Set_data_to_Slave(int address, String NumberOfData, String data, RLConfiguration config, ETS exu) 
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F4  
		 * And then the number of data expected to be returned
		 * 
		 * Note:
		 * No response expected, as per the XCP protocol:
		 * Only return negative response :
		 * if the number of data elements doesn't match the expected value .
		 * The negative response will contain the expected number of data elements 
		 *  
		 */
		Init_CastleXCP_CAN(config);
		
		SetData(address, NumberOfData, data, exu);
	}

	/**
	 * @description: This API is in charge of sending data to the slave "ECU"
	 * @param I/P: GlobalVariable object
	 * @param I/P: String as the data to be sent
	 * 
	 */
	public void XCP_Set_data_to_Slave(int address, String NumberOfData, String[] data, RLConfiguration config, ETS exu) 
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F4  
		 * And then the number of data expected to be returned
		 * 
		 * Note:
		 * No response expected, as per the XCP protocol:
		 * Only return negative response :
		 * if the number of data elements doesn't match the expected value .
		 * The negative response will contain the expected number of data elements 
		 *  
		 */

		Init_CastleXCP_CAN(config);
		
		SetData(address, NumberOfData, data, exu);
	}

	private void SetData(int Address, String NumberOfData, String Data , ETS exu)
	{
		IEvent XCP_setData_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();
		
		/*------------------------------------------------------
		1- Set MTA: Means Send the address to Slave to 
  			put a pointer at the required address in the Memory
		-------------------------------------------------------*/
		exu.comment("SeT MTA : Set apointer to agiven address in the Memory");
		Send_MTA(Address, exu);
		
		/*-------------------------------------------------------
 		2- Download request: Means download data from Master to 
			slave to be written at the address sent before
		 -------------------------------------------------------*/
		switch(NumberOfData)
		{
			case "01":
				PrepareData_WithoutReturn(Data);
				exu.comment("Send XCP Set Data Frame");
				Send_Frame("Send Data","F0"+" "+NumberOfData+" "+Prepared_Data_Hex +" 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_setData_Event, XCP_SetData_TimeoutDelay);
				/*-------------------------
				  3- Check the returned data 	
				  -------------------------*/
				exu.comment("Check positive response");
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+"00 00 00 00 00 00 00"); 
			break;
			
			case "02":
				exu.comment("Send XCP Set Data Frame");
				PrepareData_WithoutReturn(Data);
				Send_Frame("Send Data","F0"+" "+NumberOfData+" "+Prepared_Data_Hex +" 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_setData_Event, XCP_SetData_TimeoutDelay);
				/*-------------------------
				  3- Check the returned data 	
				  -------------------------*/
				exu.comment("Check positive response");
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+"00 00 00 00 00 00 00"); 
			break;
			
			case "04":
				exu.comment("Send XCP Set Data Frame");
				PrepareData_WithoutReturn(Data);
				Send_Frame("Send Data","F0"+" "+NumberOfData+" "+Prepared_Data_Hex +" 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_setData_Event, XCP_SetData_TimeoutDelay);
				/*-------------------------
				  3- Check the returned data 	
				  -------------------------*/
				exu.comment("Check positive response");
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+"00 00 00 00 00 00 00"); 
			break;
			
			default :
			break;
		}
	}

	/**
	 * @description: This API is in charge of preparing the address before using due to the Endianness
	 * 
	 * @param Global variable: as an object to get the addressed to be prepared , due to the Endianness
	 * @return: Number of address bytes as integer number
	 */
	private int PrepareAddress( int address)
	{
		/*
		 * Due to the Endianness , the address shall be  reversed 
		 * Ex: in case the address = 0xFEDF00BA
		 * what shall be sent : BA 00 DF FE   
		 */

		/*
		 * local variables
		 */
		String hex = Integer.toHexString(address);
		int k =0;
		String []arr = new String [hex.length()/2];
		String []arr_temp = new String[hex.length()/2];

		/*
		 * Sub stringing the address to array to be reversed
		 */
		for(int j =0; j<(hex.length()/2); j++ )
		{
			arr[j]= hex.toUpperCase().substring( (j*2), ( (j*2) + 2 ) );
		}

		/*
		 * reverse the address in the array
		 */
		for(int j =(hex.length()/2)-1; j>-1; j--)
		{
			arr_temp[k] = arr[j];
			k++;
		}
		/*
		 * flushing the buffer before loading the data
		 */
		Prepared_Address_Hex = "";

		/*
		 * loading the prepared address to the global variable
		 */
		for (int m=0 ; m< arr_temp.length; m++)
		{
			Prepared_Address_Hex += arr_temp[m];
			Prepared_Address_Hex = Prepared_Address_Hex.concat(" ");
		}

		/*
		 * returning the Number of data
		 */
		return hex.length()/2;
	}


	/**
	 * @description: This API is in charge of preparing the data before using due to the Endianness
	 * 
	 * @param data: as String to be prepared , due to the Endianness
	 * @return: Number of data as integer number
	 */
	private int PrepareData_AndReturnNumberOfData( String data)
	{
		/*
		 * Due to the Endianness , the data shall be  reversed 
		 * Ex: in case the data = 0xFEDF00BA
		 * what shall be sent : BA 00 DF FE   
		 */

		/*
		 * local variables
		 */
		int k =0;
		String []arr = new String[data.length()/2];
		String []arr_temp = new String[data.length()/2];		

		/*
		 * Sub stringing the data to the array to be reversed 
		 */
		for(int j =0; j<(data.length()/2); j++ )
		{
			arr[j]= data.toUpperCase().substring( (j*2), ( (j*2) + 2 ) );
		}

		/*
		 * reverse the data, due to the Endianness
		 */
		for(int j =(data.length()/2)-1; j>-1; j--)
		{
			arr_temp[k] = arr[j];
			k++;
		}

		/*
		 * Flushing the buffer, before filling the global variable
		 */
		Prepared_Data_Hex = "";

		/*
		 * loading the prepared data to the global variable
		 */
		for (int m=0 ; m< arr_temp.length; m++)
		{
			Prepared_Data_Hex += arr_temp[m];
			Prepared_Data_Hex = Prepared_Data_Hex.concat(" ");
		}

		/*
		 * returning the number of data
		 */
		return data.length()/2;
	}


	/**
	 * @description: This API is in charge of preparing the data before using due to the Endianness
	 * 
	 * @param data: as String to be prepared , due to the Endianness
	 * @return: NONE
	 */
	private void PrepareData_WithoutReturn( String[] data)
	{
		/*
		 * Due to the Endianness , the data shall be  reversed 
		 * Ex: in case the data = 0xFEDF00BA
		 * what shall be sent : BA 00 DF FE   
		 */

		/*
		 * Flushing the buffer, before filling the global variable
		 */

		Prepared_Data_Hex = "";

		/*
		 * loading the prepared data to the global variable
		 */

		switch (data.length)
		{
			case 1:
				Prepared_Data_Hex = data[0];
			break;
			case 2:
				Prepared_Data_Hex = data[0].concat(" ").concat(data[1]);
			break;
			case 4:
				Prepared_Data_Hex = data[0].concat(" ").concat(data[1].concat(" ").concat(data[2].concat(" ").concat(data[3])));
			break;
			default:
			break;
		}


	}

	private void PrepareDatainBoundries_WithoutReturn(String NumberOfData, String[] Data)
	{
		/*
		 * Due to the Endianness , the data shall be  reversed 
		 * Ex: in case the data = 0xFEDF00BA
		 * what shall be sent : BA 00 DF FE   
		 */

		/*
		 * Flushing the buffer, before filling the global variable
		 */

		Prepared_Data_Hex = "";
		Prepared_Data = 0;

		String temp_loc;

		/*
		 * loading the prepared data to the global variable
		 */

		switch (NumberOfData)
		{
			case "01":
				temp_loc      		= Data[0];
				Prepared_Data_Big 	= new BigInteger(temp_loc , 16);
				Prepared_Data_BigD 	= new BigDecimal(Prepared_Data_Big);
			break;
				
			case "02":
				temp_loc      		= Data[1].concat(Data[0]);
				Prepared_Data_Big 	= new BigInteger(temp_loc , 16);
				Prepared_Data_BigD 	= new BigDecimal(Prepared_Data_Big);
			break;
				
			case "04":
				temp_loc      		= Data[3].concat(Data[2]).concat(Data[1]).concat(Data[0]);
				Prepared_Data_Big 	= new BigInteger(temp_loc , 16);
				Prepared_Data_BigD 	= new BigDecimal(Prepared_Data_Big);
			break;
				
			default:
			break;
		}
	}

	/**
	 * @description: This API is in charge of preparing the data before using due to the Endianness
	 * 
	 * @param data: as String to be prepared , due to the Endianness
	 * @return: NONE
	 */
	private void PrepareData_WithoutReturn( String data)
	{
		/*
		 * Due to the Endianness , the data shall be  reversed 
		 * Ex: in case the data = 0xFEDF00BA
		 * what shall be sent : BA 00 DF FE   
		 */

		/*
		 * local variables
		 */
		int k =0;
		String []arr = new String[data.length()/2];
		String []arr_temp = new String[data.length()/2];		

		/*
		 * Sub stringing the data to the array to be reversed 
		 */

		for(int j =0; j<(data.length()/2); j++ )
		{
			arr[j]= data.toUpperCase().substring( (j*2), ( (j*2) + 2 ) );
		}


		/*
		 * reverse the data, due to the Endianness
		 */
		for(int j =(data.length()/2)-1; j>-1; j--)
		{
			arr_temp[k] = arr[j];
			k++;
		}

		/*
		 * Flushing the buffer, before filling the global variable
		 */

		Prepared_Data_Hex = "";

		/*
		 * loading the prepared data to the global variable
		 */
		for (int m=0 ; m< arr_temp.length; m++)
		{
			Prepared_Data_Hex += arr_temp[m];
			Prepared_Data_Hex = Prepared_Data_Hex.concat(" ");
		}
	}

	private void Send_MTA(int address, ETS exu)
	{
		int tempInt ;
		tempInt =PrepareAddress(address);
		IEvent XCP_MTA_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();

		switch(tempInt)
		{
			case 4:
				XCP_Request_FrameSignalRawTxObj.afcSet("F6 "+"00 00 00 "+Prepared_Address_Hex);
				XCP_Request_ComFrameCanTxObj.afcSendOnce();
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SendMTA_TimeoutDelay);
				exu.pauseUntilEvent(XCP_MTA_Event, XCP_SendMTA_TimeoutDelay);
			break;
	
			default:
			break;
		}
	}

	private void Send_Frame(String framename, String frame)
	{
		switch(framename)
		{
			case "get data":
				XCP_Request_FrameSignalRawTxObj.afcSet(frame);
				XCP_Request_ComFrameCanTxObj.afcSendOnce();
			break;
			case "send_MTA":
				XCP_Request_FrameSignalRawTxObj.afcSet(frame);
				XCP_Request_ComFrameCanTxObj.afcSendOnce();
			break;	
			case "Send Data":
				XCP_Request_FrameSignalRawTxObj.afcSet(frame);
				XCP_Request_ComFrameCanTxObj.afcSendOnce();
			break;
			default:
			break;
		}

	}

	private void getData(int address, String NumberOfData, String[] data, ETS exu)
	{	
	
		IEvent XCP_getData_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();
		
		exu.comment("Send the MTA");	
		Send_MTA(address, exu);

		switch(NumberOfData)
		{
			case "01":
				exu.comment("Send XCP Get Data Frame");
				Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);
				
				exu.comment("Check the returned data");
				PrepareData_WithoutReturn(data);
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00 00 00 00");
			break;
	
			case "02":
				exu.comment("Send XCP Get Data Frame");
				Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);
				
				exu.comment("Check the returned data");
				PrepareData_WithoutReturn(data);
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00 00 00");
			break;
	
			case "04":
				exu.comment("Send XCP Get Data Frame");
				Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);
	
				exu.comment("Check the returned data");
				PrepareData_WithoutReturn(data);
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00");
			break;
		}
	}
	
	private void getDataInBoundries(int address, String NumberOfData, String[] Data, long ToleranceValue, EnmToleranceType ToleranceType, ETS exu)
	{	

		IEvent XCP_getDataInBoundries_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();
		
		exu.comment("Send the MTA");	
		Send_MTA(address, exu);
			
		switch(NumberOfData)
		{
			case "01":
				exu.comment("Send XCP Get Data Frame");
				Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_getDataInBoundries_Event, XCP_GetData_TimeoutDelay);
				
				exu.comment("Check the returned data");
				PrepareDatainBoundries_WithoutReturn(NumberOfData, Data);
				XCP_Response_FrameSignalValueRxObj.afcXCPInRangeCheck(1, Prepared_Data_BigD, ToleranceValue, ToleranceType, CANFrameEndianType);
			break;
	
			case "02":
				exu.comment("Send XCP Get Data Frame");
				Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_getDataInBoundries_Event, XCP_GetData_TimeoutDelay);
				
				exu.comment("Check the returned data");
				PrepareDatainBoundries_WithoutReturn(NumberOfData, Data);
				XCP_Response_FrameSignalValueRxObj.afcXCPInRangeCheck(2, Prepared_Data_BigD, ToleranceValue, ToleranceType, CANFrameEndianType);
			break;
	
			case "04":
				exu.comment("Send XCP Get Data Frame");
				Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_getDataInBoundries_Event, XCP_GetData_TimeoutDelay);
				
				exu.comment("Check the returned data");
				PrepareDatainBoundries_WithoutReturn(NumberOfData, Data);
				XCP_Response_FrameSignalValueRxObj.afcXCPInRangeCheck(4, Prepared_Data_BigD, ToleranceValue, ToleranceType, CANFrameEndianType);
			break;
				
			default:
			break;
		}
	}

	private void getData(int address, String NumberOfData, String data, ETS exu)
	{	
		IEvent XCP_getData_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();

		exu.comment("Send the MTA");	
		Send_MTA(address, exu);
		
		switch(NumberOfData)
		{
		case "01":
			exu.comment("Send XCP Get Data Frame");
			Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
			exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
			exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);

			exu.comment("Check the returned data");
			PrepareData_WithoutReturn(data);
			XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00 00 00 00");
		break;
		
		case "02":
			exu.comment("Send XCP Get Data Frame");
			Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
			exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
			exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);

			exu.comment("Check the returned data");
			PrepareData_WithoutReturn(data);
			XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00 00 00");
		break;
		
		case "04":
			exu.comment("Send XCP Get Data Frame");
			Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
			exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
			exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);

			exu.comment("Check the returned data");
			PrepareData_WithoutReturn(data);
			XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00");
		break;
		
		default:
		break;
		}
	}

	private void getData(int address, String NumberOfData, String Mask, String data, ETS exu)
	{	
		IEvent XCP_getData_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();

		exu.comment("Send the MTA");	
		Send_MTA(address, exu);
		
		switch(NumberOfData)
		{
		case "01":
			exu.comment("Send XCP Get Data Frame");
			Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
			exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
			exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);

			exu.comment("Check the returned data");
			PrepareData_WithoutReturn(data);
			XCP_Response_FrameSignalRawRxObj.afcMaskedEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00 00 00 00", "FF "+ Mask + " 00 00 00 00 00 00");
		break;
		
		case "02":
			exu.comment("Send XCP Get Data Frame");
			Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
			exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
			exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);

			exu.comment("Check the returned data");
			PrepareData_WithoutReturn(data);
			XCP_Response_FrameSignalRawRxObj.afcMaskedEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00 00 00", "FF "+ Mask + " 00 00 00 00 00");
		break;
		
		case "04":
			exu.comment("Send XCP Get Data Frame");
			Send_Frame("get data","F5 "+NumberOfData+" 00 00 00 00 00 00");
			exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
			exu.pauseUntilEvent(XCP_getData_Event, XCP_GetData_TimeoutDelay);

			exu.comment("Check the returned data");
			PrepareData_WithoutReturn(data);
			XCP_Response_FrameSignalRawRxObj.afcMaskedEqualsCheck("FF "+ Prepared_Data_Hex + " 00 00 00", "FF "+ Mask + " 00 00 00");
		break;
		
		default:
		break;
		}
	}

	private void SetData(int address,  String data, ETS exu)
	{
		IEvent XCP_setData_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();

		exu.comment("Send the MTA");

		Send_MTA(address, exu);

		int tempInt ;
		tempInt =PrepareData_AndReturnNumberOfData(data);

		switch(tempInt)
		{
			case 1:
				exu.comment("Send XCP Set Data Frame");
				XCP_Request_FrameSignalRawTxObj.afcSet("F4 "+"00 00 00 00 00 00 "+Prepared_Data_Hex);
			break;
			case 2:
				exu.comment("Send XCP Set Data Frame");
				XCP_Request_FrameSignalRawTxObj.afcSet("F4 "+"00 00 00 00 00 "+Prepared_Data_Hex);				
				break;
			case 3:
				exu.comment("Send XCP Set Data Frame");
				XCP_Request_FrameSignalRawTxObj.afcSet("F4 "+"00 00 00 00 "+Prepared_Data_Hex);
			break;
			case 4:
				exu.comment("Send XCP Set Data Frame");
				XCP_Request_FrameSignalRawTxObj.afcSet("F4 "+"00 00 00 "+Prepared_Data_Hex);
			break;
			case 5:
				exu.comment("Send XCP Set Data Frame");
				XCP_Request_FrameSignalRawTxObj.afcSet("F4 "+"00 00 "+Prepared_Data_Hex);
			break;
			case 6:
				exu.comment("Send XCP Set Data Frame");
				XCP_Request_FrameSignalRawTxObj.afcSet("F4 "+"00 "+Prepared_Data_Hex);
			break;
			case 7:
				exu.comment("Send XCP Set Data Frame");
				XCP_Request_FrameSignalRawTxObj.afcSet("F4 "+Prepared_Data_Hex);
			break;
			default:
			break;
		}
		
		XCP_Request_ComFrameCanTxObj.afcSendOnce();
		
		exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SetData_TimeoutDelay);
		exu.pauseUntilEvent(XCP_setData_Event, XCP_SetData_TimeoutDelay);
		
		exu.comment("Check positive response");
		XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+"00 00 00 00 00 00 00"); 
	}
	
	private void SetData(int Address, String NumberOfData, String []Data , ETS exu)
	{
		IEvent XCP_setData_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();
		/*------------------------------------------------------
		1- Set MTA: Means Send the address to Slave to 
  			put a pointer at the required address in the Memory
		-------------------------------------------------------*/
		exu.comment("SeT MTA : Set apointer to agiven address in the Memory");
		Send_MTA(Address, exu);

		/*-------------------------------------------------------
 		2- Download request: Means download data from Master to 
			slave to be written at the address sent before
		 -------------------------------------------------------*/
		switch(NumberOfData)
		{
			case "01":
				PrepareData_WithoutReturn(Data);
				exu.comment("Send XCP Set Data Frame");
				Send_Frame("Send Data","F0"+" "+NumberOfData+" "+Prepared_Data_Hex +" 00 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_setData_Event, XCP_SetData_TimeoutDelay);
				/*-------------------------
				  3- Check the returned data 	
				  -------------------------*/
				exu.comment("Check positive response");
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+"00 00 00 00 00 00 00"); 
			break;
			
			case "02":
				exu.comment("Send XCP Set Data Frame");
				PrepareData_WithoutReturn(Data);
				Send_Frame("Send Data","F0"+" "+NumberOfData+" "+Prepared_Data_Hex +" 00 00 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_setData_Event, XCP_SetData_TimeoutDelay);
				/*-------------------------
				  3- Check the returned data 	
				  -------------------------*/
				exu.comment("Check positive response");
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+"00 00 00 00 00 00 00"); 
			break;
			
			case "04":
				exu.comment("Send XCP Set Data Frame");
				PrepareData_WithoutReturn(Data);
				Send_Frame("Send Data","F0"+" "+NumberOfData+" "+Prepared_Data_Hex +" 00 00");
				exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_SetData_TimeoutDelay);
				exu.pauseUntilEvent(XCP_setData_Event, XCP_SetData_TimeoutDelay);
				/*-------------------------
				  3- Check the returned data 	
				  -------------------------*/
				exu.comment("Check positive response");
				XCP_Response_FrameSignalRawRxObj.afcEqualsCheck("FF "+"00 00 00 00 00 00 00"); 
			break;
			
			default :
			break;
		}
	}
	
	public void XCP_Get_DataInRange_from_Slave_And_Check(int address, String NumberOfBytes, double Data, long ToleranceValue, EnmToleranceType ToleranceType,RLConfiguration config, ETS exu)
	{
		/*
		 * Upload data from exact address to the ECU 
		 * According to XCP protocol, 
		 * you shall send the frame xcp_get_data with first byte = F5  
		 * And then the number of data expected to be returned
		 * 
		 * The response consists of FF as positive response then the data 
		 *  
		 */
		
		int iNumberOfBytes = Integer.parseInt(NumberOfBytes);
		
		Init_CastleXCP_CAN(config);
		
		IEvent XCP_getDataInRange_Event = XCP_Response_FrameSignalRawRxObj.evtUpdate();
		
		exu.comment("Send the MTA");
		Send_MTA(address, exu);
		
		exu.comment("Send XCP Get Data Frame");
		Send_Frame("get data","F5 "+NumberOfBytes+" 00 00 00 00 00 00");
		exu.comment("Pause untill receiving a response with Timeout = %s mSec", XCP_GetData_TimeoutDelay);
		exu.pauseUntilEvent(XCP_getDataInRange_Event, XCP_GetData_TimeoutDelay);
		
		exu.comment("Check the returned data");
		XCP_Response_FrameSignalValueRxObj.afcXCPInRangeCheck(iNumberOfBytes, Data, ToleranceValue, ToleranceType, CANFrameEndianType);
	}
}