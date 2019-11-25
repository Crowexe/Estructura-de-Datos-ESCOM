#include "SCircular.h"

int agregar(struct Circular **lista, int valor)
{
	struct Circular *nuevo=NULL;
	struct Circular *aux=NULL;
	aux=*lista;
	
	nuevo=(struct Circular*)malloc(sizeof(struct Circular));
	
	if(nuevo==NULL)
	{
		return 0;
	}
	
	if(*lista==NULL)
	{
		*lista=nuevo;
		(*lista)->siguiente=nuevo;
		nuevo->dato=valor;
	}
	else
	{
		nuevo->dato=valor;
		nuevo->siguiente=*lista;	
		if(aux!=*lista)	
		{
			aux->siguiente=nuevo;
			*lista=nuevo;
		}
		else
		{
			(*lista)->siguiente=nuevo;
			*lista=nuevo;
		}
	}

	return 0;
	
}

int eliminar(struct Circular **lista, int valor)
{
	struct Circular *anterior;
	struct Circular *actual;
	struct Circular *ultimo;
	actual=*lista;
	anterior=NULL;
	ultimo=*lista;
	
	while(ultimo->siguiente!=*lista)
	{
		ultimo=ultimo->siguiente;
	}
	
	if(actual->dato==valor)
	{
		if(actual=*lista)
		{
			*lista=(*lista)->siguiente;
			ultimo->siguiente=*lista;
			free(actual);
			actual=*lista;
		}
		else
			if(actual==ultimo)
			{
				ultimo=anterior;
				anterior=NULL;
				ultimo->siguiente=*lista;
				free(actual);
				actual=*lista;
			}
			else
				{
					anterior->siguiente=actual->siguiente;
					free(actual);
					anterior=NULL;
					actual=*lista;
				}
	}
	else
		{
			if(*lista==actual)
			{
				anterior=*lista;
			}
			else
				{
					anterior=anterior->siguiente;
				}
			
			actual=actual->siguiente;
		}
		
	return 0;
}


void mostrar(struct Circular *lista)
{
	struct Circular *ultimo;
	ultimo=lista->siguiente;
	
	while(ultimo->siguiente!=lista)
	{
		ultimo=ultimo->siguiente;
	}
	
	while(lista!=ultimo)
	{
		printf("%d  ", lista->dato);
		lista=lista->siguiente;
	}
	
	printf("\n");
	
}
