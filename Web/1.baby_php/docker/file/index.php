<?php

highlight_file('index.php');
$a = $_GET['a'];
$b = $_GET['b'];
$c = $_GET['c'];

if(is_numeric($a))
{
    echo "哼，一个能打的都没有";
}

if($a>1000)
{
    if($b!==$c&md5($b)==md5($c))
    {
        $cmd = $_POST['cmd']; // flag.php
        @eval($cmd);
    }
    else
    {
        echo "我渴望,有价值的对手";
    }

}
else
{
    echo "flag{1_am_th3_f4ke_one}";
}

?>
