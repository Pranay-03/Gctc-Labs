import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class Login extends HttpServlet 
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException 
    {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        
        String name = request.getParameter("uname");
        String pass = request.getParameter("pwd");
	    try 
        {
            //loading drivers for mysql
            Class.forName("com.mysql.jdbc.Driver");
            //creating connection with the database
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/gcet","root","root");
            PreparedStatement ps = con.prepareStatement("select * from registeruser where n=? and p=?");
            ps.setString(1, name);
            ps.setString(2, pass);
            ResultSet rs =ps.executeQuery();
            boolean st = rs.next();
            if(st)
            {
                RequestDispatcher rd = request.getRequestDispatcher("Welcome");
                rd.forward(request, response);
        	    out.println("login credientials are valid");
            }
            else
            {
                out.println("Username or Password incorrect");
                RequestDispatcher rd = request.getRequestDispatcher("./login.html");
                rd.include(request, response);
            }
        }  
	    catch(Exception e) {
            e.printStackTrace();
        }
	}
}
