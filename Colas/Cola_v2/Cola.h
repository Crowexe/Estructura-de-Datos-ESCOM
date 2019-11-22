typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
}*NodoP;

typedef struct CNodo{
    NodoP out;
    NodoP inp;
} *Cola;

Cola nueva(){
    Cola t = (Cola)malloc(sizeof(struct CNodo));
    t->out=t->inp=NULL;
    return t;
}

int esNueva(Cola q){
    return ((q->inp==NULL) && (q->out==NULL));
}

Cola formar(Cola q, Elem e){
    NodoP t = (NodoP)malloc(sizeof(struct Nodo));
    t->dato = e;
    t->sig = NULL;

    if(esNueva(q))
        q->out = q->inp = t;
    else
        q->inp->sig = q->inp = t;
    return q;
}

Elem primero(Cola q){
    return q->out->dato;
}

Cola desformar(Cola q){
    NodoP t;
    if(q->out==q->inp)
        return nueva();
    else{
        t = q->out;
        q->out = q->out->sig;
        free(t);
        return q;
    }
}

void impCola(Cola q){
    Cola temp = nueva();
    temp->out = q->out;
    temp->inp = q->inp;
    impElem(primero(q));
    impCola(desformar(temp));
    free();
}
