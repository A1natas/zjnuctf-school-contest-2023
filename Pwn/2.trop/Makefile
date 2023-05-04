all: clean main

main:
	gcc -O2 -fno-stack-protector -no-pie -o ./file/trop ./code/main.c
	cp ./file/trop ./docker/pwn
clean:
	rm -rf ./file/trop