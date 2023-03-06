all: clean main

main:
	gcc -O2 -fno-stack-protector -no-pie -z lazy  -o ./file/crop ./code/main.c

clean:
	rm -rf ./file/crop