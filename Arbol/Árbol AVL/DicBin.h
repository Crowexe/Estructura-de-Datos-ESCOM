#include "Tree.h"

typedef Arbin DicBin;

DicBin insord(Elem e, DicBin a){
    if(isNewArbin(a))
        return consArb(e, newArbin(), newArbin());
    else{
        if(esMenor(e, tope(a)))
            return consArb(tope(a), insord(e, getLeftBranch(a)), getRightBranch(a));
        return consArb(tope(a), getLeftBranch(a), insord(e, getRightBranch(a)));
    }

}

Elem minElem(DicBin a){
    if(isLeaf(a) || isNewArbin(getLeftBranch(a)))
        return tope(a);
    else
        return minElem(getLeftBranch(a));
}
