typedef int Elem;
//typedef char *Elem;

void impElem(Elem e){
	printf("%d\t", e);
	//printf("%s\n", e);
}

int esMenor(Elem e, Elem e2){
    return e<e2; //devuelve un número distinto de 0 si es menor
    //return strcmp(e1,e2)<0; //Un número negativo indica que la resta de los números ASCII es negativa.
}

int sonIguales(Elem e1, Elem e2){
    return e1==e2;
    //return strcmp(e1, e2)==0;
}
