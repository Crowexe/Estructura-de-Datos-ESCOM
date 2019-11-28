#include "Cola.h"

void
encolar (struct Cola **cola, int dato)
{
  int *temporal = NULL;
  int i = 0;
  
  if (cola== NULL)
    {
      return;
    }
  if (*cola== NULL)
    {
      *cola= (struct Cola *) malloc (sizeof (struct Cola));
      if (*cola== NULL)
	{
	  return;
	}
      (*cola)->datos = (int *) malloc (sizeof (int) * 8);
      if ((*cola)->datos == NULL)
	{
	  free (*cola);
	  return;
	}
      (*cola)->cuantos = 8;
      (*cola)->actual = 0;
      *((*cola)->datos) = dato;
      return;
    }
  if ((*cola)->cuantos == (*cola)->actual + 1)
    {
      temporal = (int *) malloc (sizeof (int) * (*cola)->cuantos * 2);
      if (temporal == NULL)
	{
	  return;
	}
      for (i = 0; i < (*cola)->cuantos; i++)
	{
	  *(temporal + i) = *((*cola)->datos + i);
	}
      free ((*cola)->datos);
      (*cola)->datos = temporal;
      (*cola)->cuantos = (*cola)->cuantos * 2;
    }
  (*cola)->actual = (*cola)->actual + 1;
  *((*cola)->datos + (*cola)->actual) = dato;
}

void
desencolar (struct Cola **cola, int dato)
{
  int i = 0;
  int *temporal = NULL;
  if (cola == NULL)
    {
      return 0;
    }
  if ((*cola) == NULL)
    {
      return 0;
    }
  if ((*cola)->datos == NULL)
    {
      return 0;
    }
   (*cola)->actual= 
/*  for (i = 0; i <= (*cola)->actual; i++)
    {
      if (*((*cola)->datos + i) == cuantos)
	{
	  (*cola)->actual--;
	  break;
	}
    }

  for (; i <= (*cola)->actual; i++)
    {
      *((*cola)->datos + i) = *((*cola)->datos + i + 1);
    }

  if ((*cola)->actual < (*cola)->cuantos / 2)
    {
      temporal = (int *) malloc (sizeof (int) * (*cola)->cuantos / 2);
      if (temporal == NULL)
	{
	  return;
	}
      for (i = 0; i <= (*cola)->actual; i++)
	{
	  *(temporal + i) = *((*cola)->datos + i);
	}
      free ((*cola)->datos);
      (*cola)->datos = temporal;
      (*cola)->cuantos = (*cola)->cuantos / 2;
    }*/

}

void
mostrar (struct Cola *cola)
{
  int i = 0;
  if (cola== NULL)
    {
      printf ("\n");
      return;
    }
  for (i = 0; i < cola->actual; i++)
    {
      printf ("%d,", *(cola->datos + i));
    }
  printf ("%d\n", *(cola->datos + cola->actual));
}
