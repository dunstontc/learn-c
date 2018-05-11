CFLAGS=-Wall -g -o

all: ex1 ex3 ex7 ex8

ex1:
	gcc -Wall -g ./src/ex1.c -o ./out/ex1.o

ex3:
	gcc -Wall -g ./src/$@.c -o ./out/$@.o

ex7:
	gcc -Wall -g ./src/$@.c -o ./out/$@.o

ex8:
	gcc -Wall -g ./src/$@.c -o ./out/$@.o

clean:
	rm -f ./out/**.o && rm -rf ./out/**.o.dSYM
