contigua.o: contigua.c
	gcc contigua.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o contigua.o
	gcc main.o contigua.o

run: a.out
	./a.out
	rm -f a.out main.o contigua.o
