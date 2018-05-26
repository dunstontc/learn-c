CFLAGS=-Wall

all: ex1 ex3 ex7 ex8

# Exercise #1
ex1:
	gcc -Wall -g ./src/ex1.c -o ./out/ex1.o

# Exercise #3
ex3:
	gcc -Wall -g ./src/$@.c -o ./out/$@.o

# Exercise #7
ex7:
	gcc -Wall -g ./src/$@.c -o ./out/$@.o

# Exercise #8
ex8:
	gcc -Wall -g ./src/$@.c -o ./out/$@.o

# Clean compiled files
clean:
	rm -f ./out/**.o && rm -rf ./out/**.o.dSYM
