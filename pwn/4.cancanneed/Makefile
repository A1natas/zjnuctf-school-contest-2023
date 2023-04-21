all: clean main

main:
	gcc -fstack-protector -no-pie -o ./file/cancanneed ./code/main.c
	cp ./file/cancanneed ./docker/pwn
clean:
	rm -rf ./file/cancanneed