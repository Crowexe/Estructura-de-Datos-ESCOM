typedef struct Nodo{
    Elem tope;
    struct Nodo *left;
    struct Nodo *right;
}*Arbin;

Arbin newArbin(){
    return NULL;
}

Arbin consArb(Elem top, Arbin left, Arbin right){
    Arbin temp = (Arbin)malloc(sizeof(struct Nodo));
    temp->tope = top;
    temp->right = right;
    temp->left = left;
    return temp;
}

int isNewArbin(Arbin a){
    return a==NULL;
}

Elem tope(Arbin a){
    return a->tope;
}

Arbin getLeftBranch(Arbin a){
    return a->left;
}

Arbin getRightBranch(Arbin a){
    return a->right;
}

int numElems(Arbin a){
    if(isNewArbin(a)){
        return 0;
    }else{
        return 1 + numElems(getLeftBranch(a)) + numElems(getRightBranch(a));
    }
}

void inOrder(Arbin a){
    if(!isNewArbin(a)){
        inOrder(getLeftBranch(a));
        impElem(tope(a));
        inOrder(getRightBranch(a));
    }
}

void preOrder(Arbin a){
    if(!isNewArbin(a)){
        impElem(tope(a));
        preOrder(getLeftBranch(a));
        preOrder(getRightBranch(a));
    }
}

void postOrder(Arbin a){
    if(!isNewArbin(a)){
        postOrder(getLeftBranch(a));
        postOrder(getRightBranch(a));
        impElem(tope(a));
    }
}
//////////////////////////////////
int getMaxInt(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
//////////////////////////////////
int getArbHeight(Arbin a){
    if(isNewArbin(a))
        return 0;
    else
        return 1 + getMaxInt(getArbHeight(getLeftBranch(a)),
                             getArbHeight(getRightBranch(a)));
}

//Una hoja es un nodo que no tiene subnodos (su izquierdo y su derecho son vacíos)  :3  sadfsadfdsa
int isLeaf(Arbin a){
    return isNewArbin(getLeftBranch(a)) && isNewArbin(getRightBranch(a));
}

//Un nodo interno es un nodo que tiene al menos un subnodo
