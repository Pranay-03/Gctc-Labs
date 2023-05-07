//CSMA/CA PROGRAM
//CLIENT 1 (Sender Side)
import java.io.*;
import java.net.*;
public class client
{

  public static void main (String[]args)
  {
    try
    {
      System.out.println ("============ Client 1 ===============");
      client cli = new client ();
      int R = 0;
      Boolean bln = false;
      for (int k = 1; k <= 15; k++)
	{
	  System.out.println ("attempt : " + k);
// is idle channel? 
	  System.out.println ("is Channel idle? ");
	  int i = 0;
	  while (true)
	    {
	      System.out.print (i = i + 1);
	      if (cli.isidle ())
		{
		  System.out.println ("\n Channel idle");
		  System.out.println ("Wait IFS time 5000");
// wait for IFS time
		  Thread.sleep (5000);
// is still idle channel? 
		  System.out.println ("is still idle?");
		  if (cli.isidle ())
		    {
		      System.out.println ("Still idle");
// Choose random number
		      R = 2 ^ k - 1;
		      System.out.println ("Selected Random number :" + R);
		      System.out.println ("waiting for R slot time: " +
					  R * 6000);
// wait R slot
		      Thread.sleep (R * 6000);
// send frame
		      System.out.println ("Message sent");
// Timer runs and wait for time out 
		      System.out.println ("Wait for time out : " + 10000);
		      Thread.sleep (10000);
// ack check

		      if (cli.isidle ())
			{
			  System.out.println ("Ack received");
			  bln = true;
			  break;
			}
		      else
			{
			  System.out.println ("Ack not received");
			  break;
			}
		    }
		  else
		    {
		      System.out.println ("Busy, goes to channel idle check");
		    }
		}
	    }
	  if (bln == true)
	    {
	      break;
	    }
	}
    }
    catch (InterruptedException e)
    {
      System.out.println (e);
    }
  }
  Boolean isidle ()
  {
    try
    {
      Socket soc = new Socket ("localhost", 137);
      soc.close ();
      return true;
    }
    catch (Exception e)
    {
      return false;
    }

  }
}

//Receiver side:
//CSMA/CA
//CLIENT 2
import java.io.*;
import java.net.*;
public class server
{
  public static void main (String[]args)
  {
    try
    {
      System.out.println ("============ Client 2 ===============");
      while (true)
	{
	  ServerSocket ss = new ServerSocket (137);
	    System.out.println ("Waiting for connection");
	    ss.accept ();
	    ss.close ();
	    System.out.println ("Connected");
	}
    }
    catch (Exception e)
    {
      System.out.println (e);
    }
  }
}
