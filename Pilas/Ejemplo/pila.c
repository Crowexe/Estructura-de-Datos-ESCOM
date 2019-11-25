#include "pila.h"

void push(Nodo *&pila,char caracter,int linea){
    Nodo *nuevo = new Nodo();
    nuevo->caracter = caracter; //Se guarda el caracter
    nuevo->linea = linea;       //Se guarda la linea de codigo del caracter
    nuevo->sig = pila;
    pila = nuevo;
    //printf("Elemento %c agregado\n",caracter);
}

/* Quitar elemento de la pila */
char pop(Nodo *&pila){
    char caracter;
    Nodo *aux = pila;
    caracter = aux->caracter;
    pila = aux->sig;
    delete aux;
    //printf("Sacaste el elemento %c \n",caracter);
    return caracter;    //Regresas el elemento
}
//--Fin de codigo de la pila


/* Nombre del archivo */
char N_archivo[]="Archivo.txt";


/* Funcion para imprimir un error */
void error(char caracter,int linea){
    printf("Nombre del archivo: %s\nPosible linea de error: %d\nPosible error: hace falta simbolo %c\n",N_archivo,linea,caracter);
    printf("\n");

}
