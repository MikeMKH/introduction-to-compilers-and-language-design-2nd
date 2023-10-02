bminor: decl.o expr.o param_list.o stmt.o symbol.o type.o scanner.o parser.o
	gcc decl.o expr.o param_list.o stmt.o symbol.o type.o scanner.o parser.o -o bminor -lm

%.o: %.c *.h
	gcc -Wall -c $< -o $@

scanner.c: bminor.l parser.h
	flex -oscanner.c bminor.l

parser.c parser.h: bminor.y
	bison --defines=parser.h --output=parser.c -v bminor.y

clean:
	rm -f parser.* parser.output scanner.c *.o bminor
