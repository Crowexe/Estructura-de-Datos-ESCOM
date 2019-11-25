#ifndef __SLIGADA_H__
#define __SLIGADA_H__

#include<stdio.h>
#include<stdlib.h>

struct Lista
{
  int dato;
  struct Lista *siguiente;
};

int agregar (struct Lista **lista, int valor);
int eliminar (struct Lista **lista, int valor);
void mostrar (struct Lista *lista);

#endif
