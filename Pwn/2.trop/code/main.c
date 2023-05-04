#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char *NUM = "114514";

void init() {
    setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

void boy_next_door() {
    puts("You find my backdoor!?");
    system("/bin/sh\x00");
}

int main() {
    init();
    char num[10];
    puts("Let's play a game!");
    puts("Guess my number one chance!");
    gets(num);
    puts(strcmp(num, NUM) == 0 ? "Right! But..." : "Error! However...");
    puts("Bye!");
    return 0;
}