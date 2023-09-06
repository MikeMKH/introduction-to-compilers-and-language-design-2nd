calc: main.o scanner.o parser.o
	gcc main.o scanner.o parser.o -o calc -lm

%.o: %.c *.h
	gcc -Wall -c $< -o $@

scanner.c: boolean.l parser.h
	flex -oscanner.c boolean.l

parser.c parser.h: boolean.y
	bison --defines=parser.h --output=parser.c -v boolean.y

clean:
	rm -f parser.* parser.output scanner.c *.o calc
