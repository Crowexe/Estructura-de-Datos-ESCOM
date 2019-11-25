contigua.o: SLigada.c
	gcc SLigada.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o SLigada.o
	gcc main.o SLigada.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o SLigada.o
