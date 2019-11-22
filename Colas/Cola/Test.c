#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Cola.h"

int main(){
    char elementos[] = "123456789";

    Cola queue = nueva();
    int cont = 0;

    while(elementos[cont]!='\0'){
        queue = formar(queue, elementos[cont]);
        cont++;
    }

    while(!esNueva(queue)){
        printCola(queue); printf(" Ahora se le va a quitar '%c'", primero(queue));
        queue = desformar(queue);
        putchar('\n');
    }

    return 0;
}
