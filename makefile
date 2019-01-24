build:
	gcc -Wall -std=c11 -o min_find main.c

run:
	./min_find

buildrun: build run
