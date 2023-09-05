calc: main.o expr.o scanner.o parser.o
	gcc main.o expr.o scanner.o parser.o -o calc -lm

%.o: %.c *.h
	gcc -Wall -c $< -o $@

scanner.c: calc.l parser.h
	flex -oscanner.c calc.l

parser.c parser.h: calc.y
	bison --defines=parser.h --output=parser.c -v calc.y

clean:
	rm -f parser.* parser.output scanner.c *.o calc
