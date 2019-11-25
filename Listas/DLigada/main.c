#include "DLigada.h"
int
main () { 
	struct Doble *lista = NULL;
	agregar (&lista, 21);
 	agregar (&lista, 34);
 	agregar (&lista, 80);
 	agregar (&lista, 50);
 	agregar (&lista, 94);
  	mostrar (lista);
  	mostrarInverso (lista);
  	eliminar (&lista, 50);
  	mostrar (lista);
  	mostrarInverso (lista);
 	return 0;
}
