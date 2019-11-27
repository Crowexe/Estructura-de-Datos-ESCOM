#include "Pila.h"

int
pop (struct Pila **pila)
{
  if (pila == NULL)
    {
      return 0;
    }
  else
    {
      (*pila) = (*pila)->siguiente;
      return 0;
    }
}

int
push (struct Pila **pila, int valor)
{
  struct Pila *nuevo = NULL;

  nuevo = (struct Pila *) malloc (sizeof (struct Pila));

  if (nuevo == NULL)
    {
      return 0;
    }

  if (*pila == NULL)
    {
      *pila = nuevo;
      (*pila)->dato = valor;
      (*pila)->siguiente = NULL;
    }
  else
    {
      nuevo->dato = valor;
      nuevo->siguiente = *pila;
      *pila = nuevo;
    }


}


void
mostrar (struct Pila *pila)
{
  while (pila != NULL)
    {
      printf ("%d  ", pila->dato);
      pila = pila->siguiente;
    }

  printf ("\n");
}
