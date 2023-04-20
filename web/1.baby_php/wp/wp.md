# baby_php

### flag:  zjnuctf{We1c0nne_tO_zjn(u_c)tf}

```php
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
    if($b!==$c&md5($b)===md5($c))
    {
        $cmd = $_POST['cmd'];//flag.php
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
```

get方法传入三个参数，a不能是数字，但是a要大于1000，这里是php经典的弱类型，a只要 = 1001a,在和 1000 作比较时， 1001a > 1000 的值会为 true就可以绕过is_numeric()函数.

`if($b!==$c&md5($b)===md5($c))`

第二个if里b不等于c,b和c的md5值相等，则让b=QNKCDZO,c=240610708.两者在md5加密后都为0e开头的字符，而php处理哈希字符时把每一个**以0e开头并且后面字符均为纯数字的哈希值**都解析为0。这样就绕过了md5,进入了rce(远程命令执行)，这里可以用蚁剑进行连接或者cmd=system('cat flag.php');得到flag

zjnuctf{We1c0nne_tO_zjn(u_c)tf}



