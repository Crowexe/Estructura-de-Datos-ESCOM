#include "Lista.h"

typedef Lista Cola;

int esNueva(Cola q){
    return isVacia(q);
}

Cola nueva(){
    return vacia();
}

Cola formar(Cola q, elem e){
    if(esNueva(q))
        return cons(e, q);
    else
        return cons(cabeza(q), formar(resto(q), e));
}

elem primero(Cola q){
    return cabeza(q);
}

Cola desformar(Cola q){
    return resto(q);
}

void printPrimero(Cola q){
    putchar(primero(q));
}

void printCola(Cola q){
    if(!esNueva(q)){
        printPrimero(q);
        printCola(desformar(q));
    }
}
