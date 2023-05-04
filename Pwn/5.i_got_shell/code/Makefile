all: clean main

main: ./libs/igs.o ./libs/igs.a ./main.go
	go build -ldflags="-s -w -n" -o ../file/i_got_shell ./main.go

./libs/igs.o:
	gcc -fno-stack-protector -no-pie -c ./libs/igs.c -o ./libs/igs.o -Wl,-s -Wl,-S

./libs/igs.a:
	ar rs ./libs/igs.a ./libs/igs.o

clean:
	rm -rf ./libs/igs.o ./libs/igs.a ../file/i_got_shell