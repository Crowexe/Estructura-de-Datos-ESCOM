typedef struct nodoL{
	elem dato;
	struct nodoL *sig;
}*Lista;

Lista vacia(){
	return NULL;
}

Lista cons(elem e, Lista l){
	Lista temp = (Lista)malloc(sizeof(struct nodoL));
	temp->dato=e;
	temp->sig=l;
	return temp;
}

int isVacia(Lista l){
	return l==NULL;
	//si se cumple la condición, se devuelve un número distinto de cero
}

elem cabeza(Lista l){
	return l->dato;
}

Lista resto(Lista l){
	return l->sig;
}

void impList(Lista l){
    if(!isVacia(l)){
        impElem(cabeza(l));
        impList(resto(l));
    }

}

int listSize(Lista l){
    if(isVacia(l)){
        return 0;
    }else{
        return 1 + listSize(resto(l));
    }
}

Lista pegaList(Lista l1, Lista l2){
    if(isVacia(l1)){
        return l2;
    }else{
        return cons(cabeza(l1), pegaList(resto(l1), l2));
    }
}

Lista invList(Lista l){
    if(isVacia(l)){
        return l;
    }else{
        return pegaList(invList(resto(l)), cons(cabeza(l), vacia()));
    }
}

//insOrdAs inserta un elemento donde debe ir en una lista ordenada ascendentemente
Lista insOrdAs(elem e, Lista l){
    if(isVacia(l) || esMenor(e, cabeza(l))){
        return cons(e, l);
    }else{
        return cons(cabeza(l), insOrdAs(e, resto(l)));
    }
}

//ordListAs recibe una lista y la devuelve ordenada con la cabeza como el elemento más pequeño
Lista ordListAs(Lista l){
    if(isVacia(l)){
        return l;
    }else{
        return insOrdAs(cabeza(l), ordListAs(resto(l)));
    }
}

//Definir una función que reciba como argumento una lista y devuelva una lista ordenada descendentemente
Lista ordListDes(Lista l){
    return invList(ordListAs(l));
}

//Recibir un elemento y una lista devuelve verdadero si el elemento está en la lista
int estaEn(elem e, Lista l){
    if(isVacia(l)){
        return 0;
    }else if(sonIguales(e, cabeza(l))){
        return 1;
    }else{
        estaEn(e, resto(l));
    }
}
