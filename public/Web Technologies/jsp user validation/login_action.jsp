
<!DOCTYPE html>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="connection.jsp" %>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <%
        String id=request.getParameter("UID");
        String pw=request.getParameter("PASSWORD");
        Statement st=con.createStatement();
        ResultSet  rs=st.executeQuery("select * from register where u='"+id+"' ");
        while(rs.next())
        {
            String u=rs.getString(1);
            String p=rs.getString(2);
            if(id.equals(u)&&pw.equals(p))
            {
                out.println("valid user");
            }   
        else
            out.println("Invalid user");        
        }  
         %>
    </body>
</html>
