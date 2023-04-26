Telnet Implementation

//Week 11: Install Telnet on one of the systems connected by a switch and telnet to it
//from the other system. Using Wireshark tool, capture the packets and analyze the TCP 3-way 
//Handshake for connection establishment and tear down.

Telnet:
TELNET (Terminal Network (or)Teletype Network) is the service that allows you to access another
computer by logging in to the remote system, such that, you can pass commands to another system by
sitting back at your place. It allows you to send the instructions to a remote client, but in a plain-text 
format. Telnet listens to all the requests by the user usually on TCP port 23.
Installation of Telnet:
Step 1: sudo apt-get install telnetd
This will complete the installation of Telnet. “telnetd” is a daemon that gets invoked by “inetd” or its
extension “xinetd”, both are the internet servers.
 
Step 2:
Then you are asked to enter the user password and then press enter. Processing will start as soon as you
press enter. After this, I have noticed a line “274 KB additional disk space will be used” on the terminal screen.
You may also observe some sort of a message like this and then you”ll be asked to continue or not.
Just write “y” and then press enter to continue.
 

Step 3: Now when you are done with it, restart “inetd”. Type “sudo /etc/init.d.open-bsd-inetd restart”.
“inetd” is daemon used for dealing with incoming network and it is responsible for deciding which 
program to run when a request comes.
 

Step 4: To ensure “inetd” is started, press enter after writing the above command.
 
To connect with any remote client:
Step 5: Just type:“telnet hostipaddress”. For an example: “telnet 192.168.0.68” and press enter.
Step 6: Then you”ll see, it is connected to “host ip address”. For security reasons, you are required
to provide “username” and “password” as well.
//
                                                          Wireshark

Wireshark is a network packet analyzer. A network packet analyzer presents captured packet data in as
much detail as possible.
You could think of a network packet analyzer as a measuring device for examining what’s happening inside a 
network cable, just like an electrician uses a voltmeter for examining what’s happening inside an electric
cable (but at a higher level, of course).
In the past, such tools were either very expensive, proprietary, or both. However, with the advent of Wireshark,
that has changed. Wireshark is available for free, is open source, and is one of the best packet analyzers available 
today.
Here are some reasons people use Wireshark:
•	Network administrators use it to troubleshoot network problems
•	Network security engineers use it to examine security problems
•	QA engineers use it to verify network applications
•	Developers use it to debug protocol implementations
•	People use it to learn network protocol internals
Wireshark is an open source software.
Here are some things Wireshark does not provide:
•	Wireshark isn’t an intrusion detection system. It will not warn you when someone does strange things on
your network that he/she isn’t allowed to do. However, if strange things happen, Wireshark might help you
figure out what is really going on.
•	Wireshark will not manipulate things on the network, it will only “measure” things from it. Wireshark 
doesn’t send packets on the network or do other active things. 




How to Use Wireshark to Capture, Filter and Inspect Packets

You can download Wireshark for Windows or macOS from its official website. If you’re using 
Linux or another UNIX-like system, you’ll probably find Wireshark in its package repositories. 
For example, if you’re using Ubuntu, you’ll find Wireshark in the Ubuntu Software Center.
Capturing Packets
After downloading and installing Wireshark, you can launch it and double-click the name of a network
interface under Capture to start capturing packets on that interface. For example, if you want to capture
traffic on your wireless network, click your wireless interface. You can configure advanced features by 
clicking Capture > Options, but this isn’t necessary for now.
  
As soon as you click the interface’s name, you’ll see the packets start to appear in real time. Wireshark
captures each packet sent to or from your system.
If you have promiscuous mode enabled—it’s enabled by default—you’ll also see all the other packets on the
network instead of only packets addressed to your network adapter. To check if promiscuous mode is enabled,
click Capture > Options and verify the “Enable promiscuous mode on all interfaces” checkbox is activated at
the bottom of this window.
  

Click the red “Stop” button near the top left corner of the window when you want to stop capturing traffic. 
 



Color Coding
You’ll probably see packets highlighted in a variety of different colors. Wireshark uses colors to help you 
identify the types of traffic at a glance. By default, light purple is TCP traffic, light blue is UDP traffic,
and black identifies packets with errors—for example, they could have been delivered out of order.
To view exactly what the color codes mean, click View > Coloring Rules. You can also customize and modify the 
coloring rules from here, if you like.
 

Sample Captures
If there’s nothing interesting on your own network to inspect, Wireshark’s wiki has you covered. 
The wiki contains a page of sample capture files that you can load and inspect. Click File > Open 
in Wireshark and browse for your downloaded file to open one.
You can also save your own captures in Wireshark and open them later. Click File > Save to save your
captured packets.

 

Filtering Packets
If you’re trying to inspect something specific, such as the traffic a program sends when 
phoning home,it helps to close down all other applications using the network so you can narrow 
down the traffic. Still,you’ll likely have a large amount of packets to sift through.
That’s where Wireshark’s filters come in.
The most basic way to apply a filter is by typing it into the filter box at the top 
of the window and clicking  Apply (or pressing Enter).
For example, type “dns” and you’ll see only DNS packets.
When you start typing, Wireshark will help you autocomplete your filter.
 

You can also click Analyze > Display Filters to choose a filter from among the default filters 
included in Wireshark. From here, you can add your own custom filters and save 
them to easily access them 
in the future.

 

Inspecting Packets
Click a packet to select it and you can dig down to view its details.
 







