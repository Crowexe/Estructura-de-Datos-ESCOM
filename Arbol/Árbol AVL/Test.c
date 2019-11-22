#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "AVL.h"

int main(){

    AVL a = newArbin();
    int i;
    int nums[] = {30, 21, 43, 45, 50, 48};

    for(i=0;i<(sizeof(nums)/sizeof(nums[0]));i++){
        a = insord(nums[i], a);
        printf("%d - %d = %d\n", getArbHeight(getLeftBranch(a)), getArbHeight(getRightBranch(a)), factBal(a));
    }

    isAVL(a)?puts("It is AVL"):puts("It isn't AVL");

    a = makeAVL(a);
    isAVL(a)?puts("It is AVL"):puts("It isn't AVL");
    preOrder(a);
    return 0;
}
