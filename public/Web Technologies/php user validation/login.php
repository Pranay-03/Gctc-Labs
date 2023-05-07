<?php
$uname=$_POST["uname"];
$pass=$_POST["pass"];
// _POST  global variable which is used to collect form data after submitting an HTML form with method="post". 
$con=mysqli_connect("localhost","root","","test");
if(!$con){  // not empty
 die('Could not connect: '.mysqli_connect_error());  // same as exit function
} 
echo 'Connected successfully<br/>'; 
$query="select * from user where uname='$uname' and pass='$pass'";

$records=mysqli_query($con,$query);
if(mysqli_num_rows($records)>=1)
{
header("Location: success.html"); // The header() is a pre-defined network function of PHP, which sends a raw HTTP header to a client.
}
else{
echo "User Entered wrong credentials";
}
?>

