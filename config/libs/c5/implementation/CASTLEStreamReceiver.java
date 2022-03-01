package libs.c5.implementation;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.Instant;

public class CASTLEStreamReceiver implements Runnable{

	private boolean isRunning = false;
	private Thread task ;
	private boolean shutdown = false;
	PrintWriter csvWriter;
	private String reportsDir = "";
	private String suffix;

	private int myListenPort = 18888;
	private int castlePort = 14444;
	public boolean isProcessing = false;
	
	public CASTLEStreamReceiver(String fileDir, String fileSuffix) {

		reportsDir = fileDir;
		suffix = fileSuffix;
		task = new Thread(this,"Thread");
		
		try {
			Files.createDirectories(Paths.get(fileDir));
		} catch (IOException e) {
			e.printStackTrace();
		}

		if (isRunning == true) {
			System.out.println("Server is already up! Make sure to close it first.\n");
			return;
		}
		task.start();
	}

	public boolean close() {
		if (isRunning == false) {
			System.out.println("Server is already closed, server is not running!\n");
			return false;
		}

		shutdown = true;

		return true;
	}

	public void run() {
		DatagramSocket serverSocket = null;
		try {
			serverSocket = new DatagramSocket(myListenPort);
			byte[] receiveData = new byte[65535];

			DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

			String sendString = "CNG_2020";
			byte[] sendData = sendString.getBytes("UTF-8");
			InetSocketAddress address = new InetSocketAddress("192.168.144.11", castlePort);
			DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, address);
			serverSocket.send(sendPacket);

			while (shutdown == false) {
				serverSocket.receive(receivePacket);

				process(receivePacket.getData(), receivePacket.getLength());
			}
		} catch (IOException e) {
			System.out.println(e);
		} finally {
			serverSocket.close();
		}
	}

	private void process(byte[] data, int length) {
		if (length < 20) {
			System.err.println("Invalid Packet Received!\n");
			return;
		}

		isProcessing = true;
		ByteBuffer buffer = ByteBuffer.wrap(data);
		buffer.order(ByteOrder.LITTLE_ENDIAN);

		// Read Header (20 bytes)
		int sigID = buffer.getInt(); // Sig_ID "4bytes"
		int dataType = buffer.getInt(); // Sig Data Type "4Bytes"
		int dataCount = buffer.getInt(); // Data Bytes Count "4bytes"
		long initTimeStamp = buffer.getLong(); // Start Time Stamp "8Bytes"
		int sigSamplingRate = buffer.getInt(); // Sig Refresh Rate Micro Sec "4Bytes"

		try {
			long now = Instant.now().toEpochMilli();
			String fileName = reportsDir + "/" + suffix + "_" + sigID+"_"+now+".csv";
			csvWriter = new PrintWriter(new File(fileName)); // TODO Map SigID to Name
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		{
			StringBuilder sb = new StringBuilder();
	
			sb.append("Time Stamp (nsec)");
			sb.append(',');
			sb.append("Value");
			sb.append(',');
			sb.append('\n');
			csvWriter.write(sb.toString());
			csvWriter.flush();
		}
		
		// Read Data
		int samplesCount=0;
		while (samplesCount < dataCount) {
			StringBuilder sb = new StringBuilder();			
			
			long v = Long.MAX_VALUE;

			// XXX: Negative is not handled at the moment.
			/*
			 * 0 --> bool 1 --> uint8_t 2 --> uint16_t 3 --> uint32_t 4 --> uint64_t 5 -->
			 * int8_t 6 --> int16_t 7 --> int32_t 8 --> int64_t
			 */

			switch (dataType) {
			case 0:
				if (buffer.getChar() == 0) {
					v = 0;
				} else if (buffer.getChar() == 1) {
					v = 1;
				} else
					System.err.println("Error: Unknown Value Received!\n");
				break;
			case 1:
				v = buffer.getChar();
				break;
			case 2:
				v = buffer.getShort();
				break;
			case 3:
				v = buffer.getInt();
				break;
			case 4:
				v = buffer.getLong();
				break;
			case 5:
				v = buffer.getChar();
				break;
			case 6:
				v = buffer.getShort();
				break;
			case 7:
				v = buffer.getInt();
				break;
			case 8:
				v = buffer.getLong();
				break;
			default:
				System.err.println("Unknow Type Received!!");
			}

			sb.append(initTimeStamp);
			sb.append(',');
			sb.append(v);
			sb.append('\n');
			initTimeStamp += sigSamplingRate * 1000; // micro to nano

			samplesCount++;
			csvWriter.append(sb.toString());
			csvWriter.flush();
		}
		csvWriter.close();
		isProcessing = false;		
	}
}