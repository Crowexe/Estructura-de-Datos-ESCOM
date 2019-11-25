#ifndef __PILA_H__
#define __PILA_H__

#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct Nodo{
    char caracter;
    int linea;
    Nodo *sig;
};

void push(Nodo *&pila,char caracter,int linea);
char pop(Nodo *&pila);
void error(char caracter,int linea);

#endif
