#ifndef __SCIRCULAR_H__
#define __SCIRCULAR_H__

#include<stdio.h>
#include<stdlib.h>

struct Circular
{
  int dato;
  struct Circular *siguiente;
};

int agregar (struct Circular **lista, int valor);
int eliminar (struct Circular **lista, int valor);
void mostrar (struct Circular *lista);

#endif
