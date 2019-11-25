#ifndef __DLIGADA_H__
#define __DLIGADA_H__

#include<stdio.h>
#include<stdlib.h>

struct Doble
{
	int dato;
	struct Doble *siguiente;
	struct Doble *anterior;
};

int agregar(struct Doble **lista, int valor);
int eliminar(struct Doble **lista, int valor);
void mostrar(struct Doble *lista);
void mostrarInverso(struct Doble *lista);

#endif 
