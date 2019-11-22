#include <stdlib.h>
#include <stdio.h>

struct Lista
{
	int *datos;
	int Nelementos;
	int actual;
};


/* crear lista desde 0 */
struct Lista *
inicializar (struct Lista * lista)	
{
      if(lista==NULL) {
           lista = (struct Lista *) malloc(sizeof(struct Lista));
           if( lista == NULL) {
              return NULL;
           }
           lista->datos = NULL;
           lista->Nelementos = 4;
           lista->actual = -1;
           lista->datos  = (int *) malloc(sizeof(int)*4);
           if( lista->datos == NULL) {
               return NULL;
           }
      }

     lista->actual  = -1;

     return lista;
}



/* Duplica el tamaño de la lista en caso de estar llena */
struct Lista *
expandir(struct Lista *lista)
{
	struct Lista *tmp = NULL;
	tmp = inicializar ( tmp );
 	tmp->datos= (int *) malloc (sizeof(int)*lista->Nelementos*2);
	for(int i=0; i<lista->actual + 1; i++)
	{
		*(tmp->datos + i) = *(lista->datos + i);
	}
	lista->datos = tmp->datos;
	lista->Nelementos = lista->Nelementos*2;
	free( lista->datos );
	return lista;
}


struct Lista *
ahorrar(struct Lista *lista)
{
        struct Lista *tmp = NULL;
        tmp = inicializar ( tmp );
        tmp->datos= (int *) malloc (sizeof(int)*lista->Nelementos/2);
        for(int i=0; i<lista->actual + 1; i++)
        {
                *(tmp->datos + i) = *(lista->datos + i);
        }
        free( lista->datos );
        lista->datos = tmp->datos;
        lista->Nelementos = lista->Nelementos/2;

        return lista;
}



/* Checar si la está llena comparando actual a elementos*/
int estaLlena( struct Lista * lista)
{
      if( lista == NULL) {
           return 1;
      }   
      if ( lista->actual == lista->Nelementos)  {
        return 1;
      }
      return 0;
}

int seDesperdicia( struct Lista * lista)
{
      if ( lista->actual < (lista->Nelementos)/2)  {
        return 1;
      }
      return 0;
}


/* insertar al final */
struct Lista *
insertar (struct Lista *lista, int dato)
{
	if( lista == NULL)
	{
		lista = inicializar( lista );
	}
	if( estaLlena( lista ) == 1 )
	{
		lista = expandir ( lista ); 
	}
	
        lista->actual ++; 
	*(lista->datos + lista->actual) = dato;

         return lista;
}

struct Lista *
eliminar (struct Lista *lista, int dato)
{
	int i = 0;
	if( seDesperdicia ( lista ) == 1)
	{
		lista = ahorrar ( lista );
	} 
	while (lista->actual!=dato)
	{
		//int x = lista -> actual;
		for (i=0; lista->actual+i<Nelementos; i++)
		{
			if(*(lista->datos)==dato)
			{
				lista->actual --;
				break;
			}
		}
		for(;i<
}	
	if(lista->actual==lista->Nelementos)
	{
		return 0;
	}
	for(int i=0;i==lista->Nelementos; i++)
	{
		lista->actual = lista->actual + 1;
	}
	return lista;
	
}


void mostrar (struct Lista *lista)
{
	for(int i=0; i<lista->actual + 1; i++)
	{
		printf("%d, ",*(lista->datos+i ));	      
	}	

	printf("\n");

}



int main (void)
{
	struct Lista *lista = NULL;

	lista = insertar (lista, 2019);
	lista = insertar (lista, 105);
	lista = insertar (lista, 19);
	lista = insertar (lista, 201);
	lista = insertar (lista, 219);
	/*lista = insertar (lista, 12);
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
        lista = insertar (lista, 27);*/
	lista = eliminar (lista, 201);
	mostrar ( lista );
}
