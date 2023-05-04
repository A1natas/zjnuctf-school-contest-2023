#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

uint16_t b = 114;
int16_t a;
uint16_t c;

void init() {
	setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,_IONBF,0);
    setvbuf(stderr,0,_IONBF,0);
}

int check() {
    puts("Enter a number to make it greater than 514 after adding 114");
    scanf("%hu",&c);
    b += c;
    if(b <= 514){
        puts("Smaller than 514? Nononono!");
        return 0;
    }
    a = b;
    if(a > 0){
        puts("Nonoononono~");
        return 0;
    }
    puts("1!5!");
    return 1;
}

void help() {
    puts("/bin/sh\x00");
    asm(
        "pop %rdi\n\t"
        "ret\n\t"
        "pop %rsi\n\t"
        "ret\n\t"
        "pop %rdx\n\t"
        "ret\n\t"
        "pop %rax\n\t"
        "ret\n\t"
        "syscall\n\t"
    );
}

int main() {
    init();
    char zjnuctf[114];
    if (check() != 1) {
        return 0;
    }
    puts("You win, give zjnuctf some blessings ok?");
    read(0, zjnuctf, 514);
    puts("We received your blessing! Thanks!");
    return 0;
}