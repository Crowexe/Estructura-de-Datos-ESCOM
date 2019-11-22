#include<stdlib.h>
#include<stdio.h>
#include "Elem.h"
#include "Lista.h"

Lista mult3();

int main(){
	//Lista n = cons(1, cons(2, cons(3, cons(4, vacia()))));
	Lista n = vacia();

	printf("isVacia(): \n");
	if(isVacia(n)){
        printf("The list has no items.\n");
	}

    n = cons(11, cons(22, cons(33, cons(44, n))));

    printf("impElem() con cabeza(): \n");
    impElem(cabeza(n));

    printf("impList(): \n");

    impList(n);

    printf("invList(): \n");
    impList(invList(n));

    printf("pegaList(): \n");
    Lista n2 = cons(8, cons(5, cons(7, cons(3, vacia()))));
    impList(pegaList(n, n2));

    printf("listSize(): \n");
    printf("List 1: %d items\n", listSize(n));
    printf("List 2: %d items\n", listSize(n2));

	printf("ordListAs(n2): \n");
	impList(ordListAs(n2));

    printf("estaEn(5, n2): \n");
    estaEn(5, n2)?printf("Verdadero \n"):printf("Falso \n");
	return 0;
}

/*Lista mult3(Lista l){
	if(isVacia(l)){
		return l;
	}
	return cons(cabeza(l)*3, mult3(resto(l)));
}*/
