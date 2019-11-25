contigua.o: DLigada.c
	gcc DLigada.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o DLigada.o
	gcc main.o DLigada.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o DLigada.o
