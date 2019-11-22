#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "AVL.h"
void printAVL(AVL);
int main(){
    AVL a = newArbin();

    a = insord(-4, a);
    a = insord(2, a);
    a = insord(5, a);
    a = insord(1, a);
    a = insord(3, a);
    a = insord(6, a);
    a = insord(7, a);

    inOrder(a);
puts("");
 a = makeAVL(a);
 a = delElem(-4, a);
 inOrder(a);
 puts("");
    impElem(minElem(a));

    return 0;
}

/*void printAVL(AVL a){
    int i = 0;
    for(i;i<getArbHeight(a); i++){
        printf("");
    }
}*/
