 
// Java Code for Byte_Stuffing Sender package byte_stuffing;
import java.io.*; 
import java.util.*; 
import java.net.*;
public class Byte_Stuffing_Client {
public static void main(String args[]) throws IOException
{
InetAddress ip = InetAddress.getLocalHost(); 
int port = 45678;
Scanner sc = new Scanner(System.in);

// Opens a socket for connection 
Socket s = new Socket(ip, port);

// Declaring I/O Streams
DataInputStream dis = new DataInputStream(s.getInputStream()); 
DataOutputStream dos = new DataOutputStream(s.getOutputStream());

while (true) {
System.out.println("Enter the Message to be Sent : "); 
String data = sc.nextLine();
String res = new String();

// Data in each frame is stuffed by 'F' at beginning and end data = 'F' + data + 'F';
for (int i = 0; i < data.length(); i++) {

// Stuff with 'E' if 'F' is found in the data to be sent
if (data.charAt(i) == 'F' && i != 0 && i != (data.length() - 1)) res = res + 'E' + data.charAt(i);

// Stuff with 'E' if 'E' is found in the data to be sent 
else if (data.charAt(i) == 'E')
res = res + 'E' + data.charAt(i); 
else
res = res + data.charAt(i);
}

System.out.println("The data being sent (with byte stuffed) is : " + res);

// Send the data to the receiver 
dos.writeUTF(res); 
System.out.println("Seding Message	");
if (dis.readUTF().equals("success")) 
System.out.println("Thanks for the Feedback Server!!");

// End Messaging 
dos.writeUTF("bye"); 
break;

 
}

// Close all connections 
s.close();
dis.close();
dos.close();
}
}

//At Receiver (Server) Side:
// Java code for Byte_Stuffing Receiver package byte_stuffing;
import java.io.*; 
import java.net.*;

public class Byte_Stuffing {
public static void main(String[] args) throws IOException
{
// Opens a socket for connection
ServerSocket servsock = new ServerSocket(45678);

// Used to block until a client connects to the server 
Socket socket = servsock.accept();

// Declaring I/O Streams
DataInputStream dis = new DataInputStream(socket.getInputStream()); 
DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

while (true) {
String out = new String();
// Used to read the data sent by client String 
res = dis.readUTF();
System.out.println("Message Recevied...Successfully!!!"); 
System.out.println("The Stuffed Message is : " + res);

for (int i = 1; i < res.length() - 1; i++) {

// If data contains a 'D' or 'F' do not unstuff it 
if (res.charAt(i) == 'D' || res.charAt(i) == 'F')
out = out + res.charAt(i);

// If data contains 'E' followed by 'E', de-stuff the former 'E' 
else if (res.charAt(i) == 'E' && res.charAt(i + 1) == 'E') {
out = out + 'E'; i++;

 
}
}
System.out.println("The Destuffed Message is : " + out); dos.writeUTF("success");
String ch = dis.readUTF(); if (ch.equals("bye")) {
System.out.println("Messaging is over.	EXITING");
break;
}
}

// Closing all connections 
socket.close(); 
dis.close();
dos.close();
}
}

