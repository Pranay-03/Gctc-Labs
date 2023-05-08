//Server.java

import java.io.*;
import java.net.*;

public class Server
{
  public static void main(String[] args)
  {
    try
    {
    System.out.println("============ Client 2 ==============="); ServerSocket ss = new ServerSocket(3000); System.out.println("Waiting for connection");

    Socket con = ss.accept(); System.out.println("Connected");
    ObjectInputStream in = new ObjectInputStream(con.getInputStream()); System.out.println((String)in.readObject());

    in.close();
    ss.close();
    }
    catch(Exception e)
    {
    System.out.println(e);
    }
  }
}

//Client1.java
import java.io.*;
import java.net.*;

public class client1 {
  public static void main(String[] args) {
    try {
      System.out.println("============ Client 1 ===============");
      client1 cli = new client1();
      int Tp = 2000;
      int R = 0;
      int Tb = 0;

      for (int i = 1; i <= 15; i++) {
        System.out.println("attempt : " + i);
        if (cli.send() == "sent") {

        } else {

          break;

          R = 2 ^ i - 1;

          System.out.println("Selected Random number :" + R);

          Tb = R * Tp;
          System.out.println("waiting for next attempt in seconds): " + Tb);
          Thread.sleep(Tb);
        }
      }
    } catch (InterruptedException e) {
      System.out.println(e);
    }
  }

  String send() {
    String str = null;
    try {
      Socket soc = new Socket("localhost", 3000);
      ObjectOutputStream out = new ObjectOutputStream(soc.getOutputStream());
      String msg = "CNLAB";
      out.writeObject(msg);
      System.out.println("Message sent : " + msg);
      str = "sent";
      soc.close();
    } catch (Exception e) {
      str = "collision occured";
      String msg = null;
      System.out.println("Message sent : " + msg);
    }
    return str;
  }
}
