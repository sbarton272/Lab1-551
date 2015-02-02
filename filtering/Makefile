main: main.o filter.o modulate.o
	gcc -Wall -o main main.o filter.o modulate.o

main.o: main.c filter.h modulate.h
	gcc -c main.c filter.c modulate.c

filter.o: filter.c filter.h
	gcc -c filter.c

modulate.o: modulate.c modulate.h
	gcc -c modulate.c