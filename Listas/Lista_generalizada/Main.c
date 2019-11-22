#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Lista.h"
#include "ListaG.h"

int main(){
    elem li[] = {"1", "3", "5", "6"};
    elem le[] = {"30", "20", "15"};
    int i;

    ListaG listag = nuevaLG();
    Lista l = vacia();
    Lista ld = vacia();

    for(i=0;i<4;i++)
        l = cons(li[i], l);
    for(i=0;i<3;i++)
        ld = cons(le[i], ld);

    listag = addElem("4", listag);
    listag = addList(ld, listag);
    listag = addList(l, listag);
    listag = addElem("10", listag);

    printLG(listag);
    printf("\n");
    puts(cabeza(ld->sig->sig));
    return 0;
}
