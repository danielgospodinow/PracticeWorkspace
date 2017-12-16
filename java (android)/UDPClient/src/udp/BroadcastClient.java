package udp;

import java.net.*;

public class BroadcastClient 
{
	public InetAddress address;
	public byte[] buffer;
	public String str1, str2;
	public DatagramPacket packet;
	public MulticastSocket socket;
	public int port = 1502;
	
	public BroadcastClient() throws Exception
	{
		socket = new MulticastSocket(port);
		System.out.println("Listening for broadcasts!");
		
		transmit();
	}

	private void transmit() 
	{
		try
		{
			address = InetAddress.getByName("233.0.0.1");
			socket.joinGroup(address);
			
			while(true)
			{
				buffer = new byte[256];
				packet = new DatagramPacket(buffer, buffer.length);
				socket.receive(packet);
				str1 = new String(packet.getData());
				
				System.out.println("Got IP: " + str1);
			}
		}
		catch(Exception e){}
		finally
		{
			try
			{
				socket.leaveGroup(address);
				socket.close();
			}
			catch(Exception e){}
		}
	}
}
