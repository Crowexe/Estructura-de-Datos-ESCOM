#include <stdio.h>
#include <stdlib.h>

struct Lista
{
	int dato;
	struct Lista *siguiente;
};


struct Lista *
inicializar (struct Lista *lista)
{
	if( lista == NULL )
	{
		lista = ( struct Lista *) malloc( sizeof( struct Lista ));
		if( lista == NULL ) 
		{
			return NULL;
		}
	}
	
}


struct Lista *
insertar (struct Lista *lista, int dato)
{
	if( lista == NULL)
	{
		lista = inicializar( lista );
		lista->dato = dato;
		lista->siguiente = NULL;
        	return lista;
	}
	struct Lista *nuevo = inicializar( NULL );
	nuevo->dato = dato;
	nuevo->siguiente = lista;
	return nuevo;
}


struct Lista *
eliminar (struct Lista *lista, int dato)
{	
	struct Lista *sig = inicializar( NULL );
	struct Lista *ant = inicializar( NULL );

	while( lista->dato!=dato)
        	{
                	lista = lista->siguiente;
			sig = lista->siguiente;
			if(sig == NULL)
			{	
				return 0;	
			} 
        	}
	while( lista!=sig->siguiente)
                {
		
                        lista = lista->siguiente;
                       	ant = lista;
                        if(ant == NULL)
                        {       
                                return 0;
                        }
                }
	ant->siguiente = sig;
	

	
}

struct Lista *
mostrar (struct Lista *lista)
{
	while( lista!=NULL)
	{
		printf( "%d, ", lista->dato);
		lista = lista->siguiente;
	}
	printf("\n");
}

/*struct Lista *
mostrarInvertida (struct Lista *lista)
{
	while(lista->siguiente != NULL )
	{
		lista = lista->siguiente;
	}
	while(lista != NULL)
	{
		printf("%d, ", lista->dato);
		lista -> 
	}
}*/


int main (void)
{
        struct Lista *lista = NULL;

        lista = insertar (lista, 2019);
        lista = insertar (lista, 105);
        lista = insertar (lista, 19);
        lista = insertar (lista, 201);
        lista = insertar (lista, 219);
        lista = insertar (lista, 12);
        lista = insertar (lista, 15);
        lista = insertar (lista, 19);
        lista = insertar (lista, 200);
        lista = insertar (lista, 222);
        lista = insertar (lista, 21);
        lista = insertar (lista, 5);
        lista = insertar (lista, 9);
        lista = insertar (lista, 1);
        lista = insertar (lista, 3);
        lista = insertar (lista, 29);
        lista = insertar (lista, 51);
        lista = insertar (lista, 91);
        lista = insertar (lista, 32);
        lista = insertar (lista, 27);
	//lista = eliminar (lista, 2019);
	mostrar ( lista );
}
