typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
}*Nodo;

typedef struct CNodo{
    Nodo out;
    Nodo inp;
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
    Nodo t = (Nodo)malloc(sizeof(struct Nodo));
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
    Nodo t;
    if(q->out==q->inp)
        return nueva();
    else{
        t = q->out;
        q->out = q->out->sig;
        free(t);
        return q;
    }
}
