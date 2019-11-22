#include <stdio.h>
#include <stdlib.h>

#define elementos 0

struct Lista														/*Definimos la estructura Lista*/
{
	int actual;
	int fin;
	int *datos;
};

int agregar(struct Lista *lista,int dato);
int eliminar(struct Lista *lista,int dato);
void mostrar(struct Lista *lista);

int main ()
{
	struct Lista *lista;											/*Declaramos el apuntador lista con la estuctura*/
	int i, op, datos;
	
	lista=(struct Lista*)malloc(sizeof(struct Lista));							/*Se crea una memoria dinamica para la lista*/						
	
	lista->fin=elementos;										/*Se le asigna un valor inicial a fin*/
	
	agregar(lista, 1);
	agregar(lista, 2);
	agregar(lista, 3);
	agregar(lista, 4);
	agregar(lista, 5);
	mostrar(lista);
	
	eliminar(lista,5);
	mostrar(lista);
	           
}


int agregar(struct Lista *lista, int dato)
{
	int *tmp, i;
	
	if(lista==NULL)													/*Se valida si la lista contiene dato nulo o no*/
	{
		return -1;
	}
	
	tmp=(int *)malloc((lista->fin+1)*sizeof(int));					/* Se reserva memoria por medio de malloc y se asigna a una lista temporal*/

	*(tmp+(lista->fin))=dato;										/*Se agrega el dato una posición despues de donde llegaba fin originalmente*/
	
	if(tmp==NULL)
	{
		return 0;
	}
	
	for(i=0;i<lista->fin;i++)										/*Se copia la lista original en tmp que es la lista temporal*/
	{
		//tmp[i]=lista->datos[i];									/*El código de abajo es su equivalente con apuntadores*/
		*(tmp + i)=*(lista->datos + i);
	}
	
	free(lista->datos);												/*Se libera la lista original guardada en datos*/
	lista->datos=tmp;												/*Se asigna la lista temporal a la original que fue liberada*/
	lista->fin+=1;													/*El valor de fin se va actualizando cada vez que se termina el proceso de la funcion*/
	
	return 0;
}


int eliminar(struct Lista *lista, int dato)						/*Se eliminan todos los valores que se repitan en la lista*/
{
	int *tmp, i, pos=0, j=0;
	
	if(lista==NULL)													/*Se valida si la lista contiene dato nulo o no*/
	{
		return -1;
	}
	
	for(i=0;i<lista->fin;i++)									/*Se busca la posicion del dato a eliminar*/
	{
		if(dato==*(lista->datos+i))								/*Si el dato a eliminar es igual a el dato dentro de la posicion siguiente de la lista*/
		{
			pos=i;												/*Se guarda la posicion del dato a eliminar*/ 
		}
	}
	
	tmp=(int *)malloc((lista->fin-1)*sizeof(int));					/*Se crea la lista temporal con una casilla menos*/
	//*(tmp+(lista->fin))=dato;
	
	for(int i=0;i<lista->fin;i++)									/*Se recorre nuevamente la lista*/
	{
        if(i!=pos)													/*Si la posicion es diferente del valor de pos*/
		{
           // tmp[j]=lista->datos[i];                         		
            *(tmp + j)=*(lista->datos + i);							/*Copia todos excepto el de la posicion a eliminar*/
            j++;
        }
    }
    
    free(lista->datos);												/*Se libera la lista original guardada en datos*/
	lista->datos=tmp;												/*Se asigna la lista temporal a la original que fue liberada*/
	lista->fin-=1;													/*El valor de fin se va actualizando cada vez que se termina el proceso de la funcion*/
	
	return 0;
}

void mostrar (struct Lista *lista)
{
	for(int i=0;i<lista->fin;i++)
	{
		printf("%d  ", *(lista->datos + i));							/*Se muestran los datos de la lista*/
	}
	printf("\n");
	
}

