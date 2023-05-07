import  javax.servlet.http.*;  
import java.io.*;
import javax.servlet.*;

public class SecondServlet extends HttpServlet 
{  
	public void doPost(HttpServletRequest request, HttpServletResponse response) 
	throws    ServletException, IOException 
	{  
  
    	response.setContentType("text/html");  
    	PrintWriter out = response.getWriter();  
		String n=request.getParameter("username");  
    	String p=request.getParameter("userpass");  

		ServletConfig config = getServletConfig();
		String name = config.getInitParameter("username");    		
    	String pass = config.getInitParameter("password");  
          		
		if(n.equals(name) && p.equals(pass))
		{
			out.println("Welcome "+n);  
		} 
		else
		{  
        	out.println("Sorry username or password error");  
        	RequestDispatcher rd=request.getRequestDispatcher("/index.html");  
       		rd.include(request,response);  
    	}  		
	out.close();  
	}
}
