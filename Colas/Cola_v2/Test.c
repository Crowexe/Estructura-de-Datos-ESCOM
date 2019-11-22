#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Cola.h"

int main(){
    Cola q = nueva();
    esNueva(q)?puts("Efectivamente"):puts("No lo es");
    q = formar(q, "c88");
    esNueva(q)?puts("Efectivamente"):puts("No lo es");
    impElem(primero(q));
    q = desformar(q);
    esNueva(q)?puts("Efectivamente"):puts("No lo es");
    return 0;
}
