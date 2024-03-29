#include "DCircular.h"


int
agregar (struct DobleCirc **lista, int valor)
{
  struct DobleCirc *nuevo;
  struct DobleCirc *aux;
  nuevo = NULL;
  aux = *lista;

  nuevo = (struct DobleCirc *) malloc (sizeof (struct DobleCirc));

  if (nuevo == NULL)
    {
      return 0;
    }

  if (*lista == NULL)
    {
      nuevo->dato = valor;
      *lista = nuevo;
      nuevo->siguiente = *lista;
      nuevo->anterior = *lista;
    }
  else
    {
      nuevo->dato = valor;
      nuevo->siguiente = *lista;
      (*lista)->anterior = nuevo;
      nuevo->anterior = aux;
      aux->siguiente = nuevo;
      *lista = nuevo;

    }

  return 0;
}

int
eliminar (struct DobleCirc **lista, int valor)
{
  struct DobleCirc *actual;
  struct DobleCirc *ultimo;
  actual = *lista;
  ultimo = *lista;

  while (ultimo->siguiente != *lista)
    {
      ultimo = ultimo->siguiente;
    }

  if (actual->dato == valor)
    {
      if (actual == *lista)
	{
	  *lista = (*lista)->siguiente;
	  ultimo->siguiente = *lista;
	  (*lista)->anterior = ultimo;
	  free (actual);
	  actual = *lista;
	}
      else
	{
	  if (actual == ultimo)
	    {
	      ultimo = actual->anterior;
	    }

	  actual->anterior->siguiente = actual->siguiente;
	  actual->siguiente->anterior = actual->anterior;
	  free (actual);
	  actual = *lista;
	}
    }
  else
    {
      actual = actual->siguiente;
    }

}

void
mostrar (struct DobleCirc *lista)
{
  struct DobleCirc *ultimo;
  ultimo = lista->siguiente;

  while (ultimo->siguiente != lista)
    {
      ultimo = ultimo->siguiente;
    }

  while (lista != ultimo)
    {
      printf ("%d  ", lista->dato);
      lista = lista->siguiente;
    }

  printf ("\n");
}
