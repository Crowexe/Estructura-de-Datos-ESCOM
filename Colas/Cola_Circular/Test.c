#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "ColaC.h"
int main(){
    int i;
    Circular q = newC();
    for(i=1;i<=10;i++){
        q = addElem(q, i);
    }
    printCircular(q);
    return 0;
}
