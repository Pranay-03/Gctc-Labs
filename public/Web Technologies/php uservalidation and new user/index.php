<?php
$con = mysqli_connect("localhost","root","","project");

if(!$con)
{
	die(mysqli_error($con));
} 
if(isset($_POST['submit'])) 
{	
	$uname = $_POST['user'];
	$pwd = $_POST['pass'];
	if($uname && $pwd) 
    {		
		$res = mysqli_query($con,"select * from users where username='$uname' and password = '$pwd'");	
		if(mysqli_num_rows($res)>0) {
			$row = mysqli_fetch_assoc($res);
			echo '<h1>Welcome '.$row['name'].'</h1>';
			exit;
		}
		$res = mysqli_query($con,"select * from users where username='$uname'");
			if(mysqli_num_rows($res)>0) {
			echo '<center><h3>Password Mismatch!<h3></center>';
		}
		else {
		echo '<center>
                User is not available.  
                <h2>Registration Form</h2>
                <form method="post">
                    Full Name: <input type="text" name="name"><br>
                    Username: <input type="text" name="user"><br>
                    Password: <input type="password" name="pass"><br>
                    Retype Password: <input type="password" name="pass1"><br>
                    <input type="submit" name="register" value="Register">
                </form>
                </center>';
		exit;
		}
    }
}
if(isset($_POST['register'])) {
	$uname = $_POST['user'];
	$name = $_POST['name'];
	$pwd = $_POST['pass'];
	$pwd1 = $_POST['pass1'];
	if($uname && $name && $pwd && $pwd1)
    {
	    if(strcmp($pwd,$pwd1)!=0)
        {
            echo "Passwords are not matched!";
        }
	    else {
		    $res = mysqli_query($con,"insert into users values('$uname','$pwd','$name')");
		    echo 'Inserted Successfully';
	    }
    }
}
?>
<h2>Sign In</h2>
<form method="post">
Username: <input type="text" name="user"><br>
Password: <input type="password" name="pass"><br>
<input type="submit" name="submit" value="Login">
</form>
