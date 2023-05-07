//Stop and Wait Protocol:
//Program:
//SENDER// 
import java.io.*;
import java.net.*;
import java.util.Scanner;
class stopwaitsender
{
  public static void main (String args[]) throws Exception
  {
    stopwaitsender sws = new stopwaitsender ();
      sws.run ();
  }
  public void run () throws Exception
  {
    Scanner sc = new Scanner (System.in);
      System.out.println ("Enter no of frames to be sent:");
    int n = sc.nextInt ();
    Socket myskt = new Socket ("localhost", 9999);
    PrintStream myps = new PrintStream (myskt.getOutputStream ());
    for (int i = 0; i <= n;)
      {
	if (i == n)
	  {
	    myps.println ("exit");
	    break;
	  }
	System.out.println ("Frame no " + i + " is sent");
	  myps.println (i);
	BufferedReader bf =
	  new BufferedReader (new
			      InputStreamReader (myskt.getInputStream ()));
	String ack = bf.readLine ();
	if (ack != null)
	  {
	    System.out.println ("Acknowledgement was Received from receiver");
	    i++;
	    Thread.sleep (4000);
	  }
	else

	  {
	    myps.println (i);
	  }
      }
  }
}

//RECEIVER// 
import java.io.*;
import java.net.*;
class stopwaitreceiver
{
  public static void main (String args[]) throws Exception
  {
    stopwaitreceiver swr = new stopwaitreceiver ();
      swr.run ();
  }
  public void run () throws Exception
  {
    String temp = "any message", str = "exit";
    ServerSocket myss = new ServerSocket (9999);
    Socket ss_accept = myss.accept ();
    BufferedReader ss_bf =
      new BufferedReader (new
			  InputStreamReader (ss_accept.getInputStream ()));
    PrintStream myps = new PrintStream (ss_accept.getOutputStream ());
    while (temp.compareTo (str) != 0)
      {
	Thread.sleep (1000);
	temp = ss_bf.readLine ();
	if (temp.compareTo (str) == 0)
	  {
	    break;

	  }
	System.out.println ("Frame " + temp + " was received");
	  Thread.sleep (500);
	  myps.println ("Received");
      }
    System.out.println ("ALL FRAMES WERE RECEIVED SUCCESSFULLY");
  }
}
