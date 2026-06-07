# Makefile
main: main.o coord.o
	gcc main.o coord.o -o main

main.o: main.c coord.h
	gcc -c main.c

coord.o: coord.c coord.h
	gcc -c coord.c

clean:
	rm *.o main