package udp;

public class UDPClient
{
	public static void main(String[] args) throws Exception
	{
		//BroadcastClient bc = new BroadcastClient();
		
		int x=7, y=3;
		
		while(y-- > 0)
		{
			System.out.println(y);
			x *= 2;
		}
		
		System.out.println(x);
		System.out.println(y);
	}
}
