hello-O3: hello-O3.o
	gcc hello-O3.o -o hello-O3 -O3

hello-O3.o: hello-O3.s
	gcc -c hello-O3.s -o hello-O3.o -O3

hello-O3.s: hello-O3.i
	gcc -S hello-O3.i -o hello-O3.s -O3

hello-O3.i:
	gcc -E hello.c -o hello-O3.i -O3

hello: hello.o
	gcc hello.o -o hello

hello.o: hello.s
	gcc -c hello.s

hello.s: hello.i
	gcc -S hello.i

hello.i:
	gcc -E hello.c -o hello.i

clean:
	rm -f hello*.o hello*.i hello-O3 hello
