#include "DicBin.h"
#include <math.h>

typedef DicBin AVL;

AVL rotateR(DicBin a){
    return consArb(tope(getLeftBranch(a)), getLeftBranch(getLeftBranch(a)), consArb(tope(a), getRightBranch(getLeftBranch(a)), getRightBranch(a)));
}

AVL rotateL(DicBin a){
    return consArb(tope(getRightBranch(a)), consArb(tope(a), getLeftBranch(a), getLeftBranch(getRightBranch(a))), getRightBranch(getRightBranch(a)));
}

AVL rotateLtoR(DicBin a){
    return rotateR(consArb(tope(a), rotateL(getLeftBranch(a)), getRightBranch(a)));
}

AVL rotateRtoL(DicBin a){
    return rotateL(consArb(tope(a), getLeftBranch(a), rotateR(getRightBranch(a))));
}

int factBal(DicBin a){
    if(isNewArbin(a))
        return 0;
    return getArbHeight(getLeftBranch(a)) - getArbHeight(getRightBranch(a));
}

int isAVL(DicBin a){
    if(isNewArbin(a))
        return 1;
    else{
        if(abs(getArbHeight(getLeftBranch(a))-getArbHeight(getRightBranch(a)))>1){
            return 0;
        }
        return isAVL(getLeftBranch(a)) && isAVL(getRightBranch(a));
    }

}

AVL makeAVL(DicBin a){
        if(isAVL(a))
            return a;
        else if(factBal(a)>0){
            if(factBal(getLeftBranch(a))>0)
                a = rotateR(a);
            else
                a = rotateLtoR(a);
        }
        else{
            if(factBal(getRightBranch(a))<0)
                a = rotateL(a);
            else
                a = rotateRtoL(a);
        }

        return consArb(tope(a), makeAVL(getLeftBranch(a)), makeAVL(getRightBranch(a)));
}

AVL consAVL(Elem e, AVL a){
    return makeAVL(insord(e, a));
}

int isIn(Elem e, DicBin a){
    if(isNewArbin(a))
        return 0;
    else if(sonIguales(e, tope(a)))
        return 1;
    else
        return isIn(e, getLeftBranch(a)) || isIn(e, getRightBranch(a));
}

AVL delElem(Elem e, AVL a){
    if(sonIguales(e, tope(a))){
        if(isLeaf(a))
            return newArbin();
        else if(isNewArbin(getRightBranch(a)))
            return getLeftBranch(a);
        else if(isNewArbin(getLeftBranch(a)))
            return getRightBranch(a);
        else
            return makeAVL(consArb(minElem(getRightBranch(a)), getLeftBranch(a), delElem(minElem(getRightBranch(a)), getRightBranch(a))));
    }else if(esMenor(e, tope(a)))
        return makeAVL(consArb(tope(a), delElem(e, getLeftBranch(a)), getRightBranch(a)));
     else
        return makeAVL(consArb(tope(a), getLeftBranch(a), delElem(e, getRightBranch(a))));
}
