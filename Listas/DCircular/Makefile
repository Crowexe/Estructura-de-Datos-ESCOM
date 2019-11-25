contigua.o: DCircular.c
	gcc DCircular.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o DCircular.o
	gcc main.o DCircular.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o DCircular.o
