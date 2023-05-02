<?php
$url = $_GET['url'];
if(!isset($_GET['url'])){
    header("Location: /?url=http://www.baidu.com");
}
if(!preg_match('/localhost|127\.0\.|\。/i', $url)){
    $ch=curl_init($url);
    curl_setopt($ch, CURLOPT_HEADER, 0);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    $result=curl_exec($ch);
    curl_close($ch);
    echo ($result);
}else{
    die("Hacker?!");
}