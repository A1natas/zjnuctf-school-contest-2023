#include "igs.h"

int cg0l4ng_sandbox() {
    close(2);   // 关闭错误流
    struct sock_filter filter[] = {
        // ban arch && x32 syscall
        BAN_ARCH_WITH_X32_SYSCALL,
        // ban func
        BAN_FUNC(59),       // ban execve
        BAN_FUNC(322),      // ban execveat
        BAN_FUNC(2),        // ban open
        BAN_FUNC(3),        // ban close
        BAN_FUNC(10),       // ban mprotect
        BAN_FUNC(40),       // ban sendfile
        BAN_FUNC(41),       // ban socket
        BAN_FUNC(42),       // ban connect
        BAN_FUNC(50),       // ban listen
        BAN_FUNC(57),       // ban fork
        BAN_FUNC(58),       // ban forkv
        BAN_FUNC(78),       // ban getdents
        BAN_FUNC(217),      // ban getdents64
        BAN_FUNC(61),       // ban wait4
        BAN_FUNC(101),      // ban ptrace
        // sandbox over
        SANDBOX_OVER
    };

    struct sock_fprog prog = {
        .len = (unsigned short)(sizeof(filter)/sizeof(filter[0])),
        .filter = filter,
    };
    
    if(prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
        perror("prctl PR_SET_NO_NEW_PRIVS");
        return 0;
    }

    if(prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)) {
        perror("prctl PR_SET_SECCOMP");
        return 0;
    }

    return 1;
}

void cg0l4ng_n3ver_kn0vv_th1s_1n1t() {
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);
    mmap(0x114000, 0x1000, 0b111, 34, -1, 0);
}

int cg0l4ng_vu1n_7unc(char *zjnuctf, char *sandbox) {
    if (!DEBUG && ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
        puts("fxxk gdb ptrace!");
        _exit(0);
    }
    char ctf[20];
    puts(zjnuctf);
    puts(sandbox);
    cg0l4ng_sandbox();
    return read(0, ctf, 0x50);
}