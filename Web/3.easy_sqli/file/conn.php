<?php
$conn=mysqli_connect("localhost","ctf","ctf","ctf");
if (!$conn)
{
    echo("连接错误: " . mysqli_connect_error());
} 
