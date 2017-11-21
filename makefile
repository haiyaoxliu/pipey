all: pipey.c
	gcc -o p pipey.c

run: all
	./p
