#ifndef WOOD
#define WOOD

#include <stdio.h>
#include <stdlib.h>
#include <seccomp.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <linux/seccomp.h>
#include <linux/filter.h>

#define DEBUG 0

#define BAN_ARCH_WITH_X32_SYSCALL \
    BPF_STMT(BPF_LD | BPF_W | BPF_ABS, 4),\
    BPF_JUMP(BPF_JMP | BPF_JEQ, AUDIT_ARCH_X86_64, 0, 2),\
    BPF_STMT(BPF_LD | BPF_W | BPF_ABS, 0),\
    BPF_JUMP(BPF_JMP | BPF_JGE | BPF_K, __X32_SYSCALL_BIT, 0, 1),\
    BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_KILL)

#define BAN_FUNC(code) \
    BPF_JUMP(BPF_JMP | BPF_JEQ, code ,0 , 1)

#define SANDBOX_OVER \
    BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_KILL),\
    BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW)

int cg0l4ng_sandbox();
void cg0l4ng_n3ver_kn0vv_th1s_1n1t();
int cg0l4ng_vu1n_7unc(char *zjnuctf, char *sandbox);

#endif