typedef struct Nodo{
        Elem dato;
        struct Nodo *sig;
}*Circular;

Circular newC(){
    return NULL;
}

int isNewC(Circular q){
    return q == NULL;
}

Circular addElem(Circular q, Elem e){
     Circular t = (Circular)malloc(sizeof(struct Nodo));
     t->dato = e;

     if(isNewC(q)){
        q = t;
        q->sig = q;
     }else{
        t->sig = q->sig;
        q->sig = t;
     }
     return t;
}

Elem getFirstElem(Circular q){
    return q->sig->dato;
}

Circular removeFirstElem(Circular q){
    Circular t;

    if(q==q->sig)
        return newC();
    else{
        t = q->sig;
        q->sig = q->sig->sig;
        free(t);
        return q;
    }
}

Circular rotateC(Circular q){
    return q->sig;
}


void printCircular(Circular q){
    if(!isNewC(q)){
        impElem(getFirstElem(q));
        //printCircular(removeFirstElem(q));
        q = rotateC(q);
        getchar();
        printCircular(q);
    }
}
