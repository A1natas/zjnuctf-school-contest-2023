all: clean main

main:
	gcc -O2 -fno-stack-protector -no-pie -z lazy  -o ./file/crop ./code/main.c
	cp ./file/crop ./docker/pwn
clean:
	rm -rf ./file/crop