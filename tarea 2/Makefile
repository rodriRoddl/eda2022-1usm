CC=gcc
FLAGS=-Wall
FLAGS1= -lm

#nom: dep1 dep2 dep3 ...
#all: dependencias
#BIN: dependencias
all: TEST clean exe

TEST: main.o
        $(CC) -o $@ $^ $(FLAGS1)


main.o: main.c
        $(CC) -c $^ $(FLAGS)

sorting.o: sorting.c
        $(CC) -c $^ $(FLAGS)

sorting.o: tweets.h

clean:
    rm -rf *.o *.gch

exe:
    ./TEST "tweets.csv"

