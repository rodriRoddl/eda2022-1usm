CC=gcc
FLAGS=-Wall
FLAGS1= -lm -ltr

#nom: dep1 dep2 dep3 ...
#all: dependencias
#BIN: dependencias
all: TEST clean exe

TEST: main.o tda.o
	$(CC) -o $@ $^ $(FLAGS1)


main.o: main.c
	$(CC) -c $^ $(FLAGS)

tda.o: tda.c 
	$(CC) -c $^ $(FLAGS)

main.o: entradas.h tda.h
tda.o: entradas.h

clean:
	rm -rf *.o *.gch

exe:
	./TEST "estadio1.txt"