main: main.o filter.o
	gcc -Wall -o main main.o filter.o

main.o: main.c filter.h
	gcc -c main.c filter.c

filter.o: filter.c filter.h
	gcc -c filter.c