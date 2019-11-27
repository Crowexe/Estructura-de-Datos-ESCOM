#include "Pila.h"

int
main ()
{
  struct Pila *pila = NULL;

  push (&pila, 46);
  push (&pila, 29);
  push (&pila, 53);
  push (&pila, 409);
  push (&pila, 89);
  mostrar (pila);
  pop (&pila);
  pop (&pila);
  mostrar (pila);

  return 0;
}
