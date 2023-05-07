<html>
<body>
<%@ page import="java.io.*,java.util.*" %>
<%
 
	Date time1=new Date();
    
     out.println("Hello"+request.getParameter("name"));
	 out.println("<br>start time: <br>"+time1);
 
     session.setAttribute("starttime",time1);
     session.setAttribute("name",request.getParameter("name"));
  
  
%>

</body>
</html>