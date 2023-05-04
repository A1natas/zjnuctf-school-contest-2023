all: clean main

main:
	gcc -fno-stack-protector -no-pie -o ./file/nc_me_please ./code/main.c
	cp ./file/nc_me_please ./docker/pwn
clean:
	rm -rf ./file/nc_me_please