typedef struct Node{
    char *e;
    Lista li;
    struct Node *next;
} *ListaG;

ListaG nuevaLG(){
    return NULL;
}

ListaG esNuevaLG(ListaG lg){
    return lg==NULL;
}

ListaG addElem(elem el, ListaG lg){
	ListaG temp = (ListaG)malloc(sizeof(struct Node));
	temp->e=el;
	temp->li=NULL;
	temp->next=lg;
	return temp;
}

ListaG addList(Lista l, ListaG lg){
    ListaG temp = (ListaG)malloc(sizeof(struct Node));
	temp->e=NULL;
	temp->li=l;
	temp->next=lg;
	return temp;
}

elem getEl(ListaG lg){
    return lg->e;
}

Lista getL(ListaG lg){
    return lg->li;
}

ListaG tail(ListaG lg){
    return lg->next;
}

void printLG(ListaG lg){
    if(!esNuevaLG(lg)){
        if(getEl(lg)==NULL){
            printf("(");
            impList(getL(lg));
            printf("), ");
            printLG(tail(lg));
        }else{
            impElem(getEl(lg));
            printLG(tail(lg));
        }
    }
}

