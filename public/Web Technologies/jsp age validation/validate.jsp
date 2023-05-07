<% 
String name=request.getParameter("name");
int age=Integer.parseInt(request.getParameter("age"));
if(age>=18){
	out.println("Welcome "+name);
}else{
	out.println("Hello "+name+" you are not authorized to vote");
}

%>