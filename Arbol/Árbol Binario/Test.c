#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Tree.h"
int  main(){
    Arbin q = newArbin();
    /*q = consArb(5, consArb(10, newArbin(), consArb(15, newArbin(), newArbin())),
                consArb(20, newArbin(), newArbin()));*/
    q = consArb(4, consArb(1, newArbin(), newArbin()), consArb(6, consArb(5, newArbin(), newArbin()), consArb(7, newArbin(), newArbin())));
    printf("Inorder:\t"); inOrder(q);
    puts("");
    printf("Preorder:\t"); preOrder(q);
    puts("");
    printf("Posorder:\t"); postOrder(q);
    puts("");
    printf("Altura: %d\n", getArbHeight(q));
    printf("%d", isLeaf(getLeftBranch(q)));
    return 0;
}
