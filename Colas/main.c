#include "Cola.h"

int
main (void)
{
  struct Contigua *cola= NULL;

  encolar (&cola, 2019);
  encolar (&cola, 105);
  encolar (&cola, 12);
  encolar (&cola, 45);
  encolar (&cola, 33);
  encolar (&cola, 19);
  encolar (&cola, 70);
  encolar (&cola, 89);
  encolar (&cola, 93);
  mostrar (cola);
  desencolar (&cola, 45);
  desencolar (&cola, 33);
  desencolar (&cola, 19);
  desencolar (&cola, 70);
  desencolar (&cola, 89);
  desencolar (&cola, 93);
  mostrar (cola);
  return 0;
}
