#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void help() {
    asm (
        "pop %rdi\n\t"
        "ret\n\t"
        "pop %rsi\n\t"
        "ret\n\t"
        "pop %r10\n\t"
        "ret\n\t"
    );
}

void init() {
    setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

void vuln() {
    char *c[20];
    char v[20];
    puts("Where you want read?");
    read(0, c, 0x8);
    puts("Got it! Read 1 is ok...");
    read(0, *c, 0x1);
    puts("fxxk canary!");
    read(0, v, 0x40);   // stack overflow
    close(1);
}

int main() {
    init();
    char zjnuctf[0x20];
    puts("Welcome to ZJNUCTF!");
    read(0, zjnuctf + 0x38, 0x20);
    for (int i = 0; i < 0x20; i+=8) {   // check address
        if (*(size_t *) (zjnuctf + 0x38 + i) >= &main && *(size_t *) (zjnuctf + 0x38 + i) < 0x402000) {
            puts("fxxk address?!");
            _exit(0);
        }
    }
    return 0;
}