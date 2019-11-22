#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Pila.h"
#define zero 0;

Pila llena(Pila , Elem);

int main(){

    char li = 'Z';
    Pila p = empty();

    p = llena(p, li);

    while(!isEmpy(p)){
        printElem(top(p));putchar('\n');
        p = pop(p);
    }

    return zero;
}


Pila llena(Pila p, Elem e){
    if(e>='A'){
        llena(push(e, p), e-1);
    }else{
        return p;
    }
}
