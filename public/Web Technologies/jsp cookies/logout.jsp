<%@ page import="java.io.*,java.util.*" %>
<%
 
	 Date time2=new Date();
 
     Date time1=(Date)session.getAttribute("starttime");
     String name=(String)session.getAttribute("name");
	out.println("Thank You "+name);
	out.println("<br>Usage Time:");
	out.print((time2.getTime()-time1.getTime())/1000);
	
	session.removeAttribute("starttime");
	session.removeAttribute("name");
  
%>