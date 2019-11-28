#ifndef __COLA_H__
#define __COLA_H__

#include<stdio.h>
#include<stdlib.h>
struct Cola
{
  int *datos;
  int frente;
  int cuantos;
  int atras;
};

void encolar (struct Cola **, int);
void desencolar (struct Cola **, int);
void mostrar (struct Cola *);
#endif
