#include <string.h>
//typedef int elem;
typedef char *elem;

void impElem(elem e){
	//printf("%d\n", e);
	printf("%s\n", e);
}

int esMenor(elem e1, elem e2){
    //return e1<e2; //devuelve un n�mero distinto de 0 si es menor
    return strcmp(e1,e2)<0; //Un n�mero negativo indica que la resta de los n�meros ASCII es negativa.
}

int sonIguales(elem e1, elem e2){
    //return el==e2;
    return strcmp(e1, e2)==0;
}
