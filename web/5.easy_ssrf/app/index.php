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

$ser = $_POST['ser'];
if(isset($ser)){
    unserialize($ser);
}else{
    highlight_file(__FILE__);
}