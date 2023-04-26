Week 10 implementation
FTP server configuration on windows 7

1) Type in cmd  ipconfig to find the ip address of the system
2) Create a folder in desktop and store files that you would want to share
3) To configure FTP server go to control panel, click on programs  -> programs and features.
4) Click on turn windows features on /off
5) Check mark IIS (internet and information services)
6) Expand IIS and check mark ftp server 
7) Expand ftp server check mark ftp extensibility and ftp services
8) Make sure web management tools and World Wide Web services are checked.
9) Click ok
10) Click on control panel home
11) Click on administrative tools (if windows 10 or 11, search for administrative tools).
12) Click on IIS MANAGER
13) Under connections look for the root (folder name) (available on top right)
14) Expand root
15) Expand sites
16) Right click on sites and select add ftp site
17) Name the ftp site
18) Browse physical path for the folder created in step 2.
19) Click on next
20) Select ip address of your computer. And select no ssl under ssl and click on next.
21) Select basic authentication
22) Select authorization as specific users and type in Gcet (username)
23) Check in required permissions.
24) Click on finish
25) FTP site is configured.
26) Go to MyComputer, type in ftp://ip address and click enter
27) Provide user credentials and access the files available in the ftp server. This access is internally with in a network
28) To access this ftp outside a network we need to enable port no 21 at the router.









