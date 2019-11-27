#ifndef __PILA_H__
#define __PILA_H__

#include<stdio.h>
#include<stdlib.h>

struct Pila
{
  int dato;
  struct Pila *siguiente;
};

int push (struct Pila **pila, int valor);
int pop (struct Pila **pila);
void mostrar (struct Pila *pila);

#endif
