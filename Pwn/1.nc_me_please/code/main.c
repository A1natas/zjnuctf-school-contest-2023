#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char chs[20];
const char key[] = "hello_ZJNUCTF2023";

void init() {
    setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

int main() {
    init();
    puts("Welcome to ZJNUCTF 2023!");
    puts("Please input `hello_ZJNUCTF2023` to get a shell!");
    gets(chs);
    if (strcmp(chs, key) == 0) {
        system("/bin/sh");
        return 0;
    }
    puts("Nonononononono! Again?!");
    return 0;
}