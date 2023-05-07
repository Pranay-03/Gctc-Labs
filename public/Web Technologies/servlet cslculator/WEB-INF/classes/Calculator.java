import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

public class Calculator extends HttpServlet 
{
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException 
        {
            response.setContentType("text/html;charset=UTF-8");
        }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException 
        {
        
            PrintWriter out = response.getWriter();
            String n1 = request.getParameter("txt1");
            String n2 = request.getParameter("txt2");
                              
            out.println("Addition Answer = "+(Integer.parseInt(n1) + Integer.parseInt(n2)));
        
            out.println("Substraction Answer = "+(Integer.parseInt(n1) - Integer.parseInt(n2)));
        
            out.println("Multiplication Answer = "+(Integer.parseInt(n1) * Integer.parseInt(n2)));
            out.println("Division Answer = "+(Integer.parseInt(n1) / Integer.parseInt(n2)));    
        } 
}

