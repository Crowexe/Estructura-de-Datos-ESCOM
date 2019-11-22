#include <stdlib.h>
#include <stdio.h>
#include "Elem.h"
#include "Lista.h"

int main(){
        Lista h = vacia();
        h = cons(1, h);
        h = cons(2, h);
        h = cons(3, h);
        h = cons(4, h);
        printf("%f", promedio(h));
        return 0;
}
