#include "contigua.h"

int
main (void)
{
  struct Contigua *lista = NULL;

  insertar (&lista, 2019);
  insertar (&lista, 105);
  insertar (&lista, 12);
  insertar (&lista, 45);
  insertar (&lista, 33);
  insertar (&lista, 19);
  insertar (&lista, 70);
  insertar (&lista, 89);
  insertar (&lista, 93);
  mostrar (lista);
  eliminar (&lista, 45);
  eliminar (&lista, 33);
  eliminar (&lista, 19);
  eliminar (&lista, 70);
  eliminar (&lista, 89);
  eliminar (&lista, 93);
  mostrar (lista);
  return 0;
}
