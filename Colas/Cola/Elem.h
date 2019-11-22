#include <string.h>
//typedef int elem;
typedef char *elem;

void impElem(elem e){
	//printf("%d\n", e);
	printf("%s\n", e);
}

int esMenor(elem e1, elem e2){
    //return e1<e2; //devuelve un número distinto de 0 si es menor
    return strcmp(e1,e2)<0; //Un número negativo indica que la resta de los números ASCII es negativa.
}

int sonIguales(elem e1, elem e2){
    //return el==e2;
    return strcmp(e1, e2)==0;
}
