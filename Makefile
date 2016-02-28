all: assign3

assign3: matrix.o main.c
	clang -Wall main.c matrix.o -o assign3

matrix.o: matrix.ll
	clang -Wall -c matrix.ll
