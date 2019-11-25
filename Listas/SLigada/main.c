#include "SLigada.h"

int
main ()
{
  struct Lista *lista = NULL;

  agregar (&lista, 46);
  agregar (&lista, 29);
  agregar (&lista, 53);
  agregar (&lista, 409);
  agregar (&lista, 89);
  mostrar (lista);
  eliminar (&lista, 53);
  mostrar (lista);

  return 0;
}
