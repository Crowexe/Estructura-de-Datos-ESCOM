#include "Pila.c"
#include<stdlib.h>
#include<stdio.h>

using namespace std;

/* Estructura de un nodo de la pila */
struct Nodo{
    char caracter;
    int linea;
    Nodo *sig;
};

/* Agregar elemento a la pila */
void push(Nodo *&pila,char caracter,int linea){
    Nodo *nuevo = new Nodo();   
    nuevo->caracter = caracter; //Se guarda el caracter
    nuevo->linea = linea;       //Se guarda la linea de codigo del caracter
    nuevo->sig = pila;          
    pila = nuevo;               
    //printf("Elemento %c agregado\n",caracter);
}

/* Quitar elemento de la pila */
char pop(Nodo *&pila){
    char caracter;
    Nodo *aux = pila;
    caracter = aux->caracter;
    pila = aux->sig;
    delete aux; 
    //printf("Sacaste el elemento %c \n",caracter);
    return caracter;    //Regresas el elemento
}
//--Fin de codigo de la pila


/* Nombre del archivo */
char N_archivo[]="Archivo.txt";


/* Funcion para imprimir un error */
void error(char caracter,int linea){
    printf("Nombre del archivo: %s\nPosible linea de error: %d\nPosible error: hace falta simbolo %c\n",N_archivo,linea,caracter);
    printf("\n");

}


int main(){
    
    /* Pila */
    Nodo *pila = NULL;

    /* Linea de codigo */ 
    int linea=1;
 

    FILE* archivo = fopen(N_archivo,"r");

    while( !feof(archivo) ){
       char caracter=fgetc(archivo);
       // Contador de lineas de codigo
       if(caracter == '\n'){
           linea++;
       }
       
       /* Si encuentras un caracter de 
       apertura lo metes a la pila */
       if(caracter == '(' || caracter == '[' || caracter == '{' || caracter == '<'){
           push(pila,caracter,linea);
       }

       /* Si encuentras un caracter de 
       cierre sacas un elemento de la pila 
       y comparas */
       if(caracter == ')' || caracter == ']' || caracter == '}' || caracter == '>'){
           // Si la pila esta vacia falta un caracter de entrada
           if(pila==NULL){
                switch (caracter){
                    case ')':
                            error('(',linea);
                            return 0;
                    break;
                    case ']':
                            error('[',linea);
                            return 0;
                    break;
                    case '}':
                        if(caracter!='}'){
                            error('{',linea);
                            return 0;
                        }
                    break;
                    case '>':
                        if(caracter!='>'){
                            error('<',linea);
                            return 0;
                        }
                    break;
                    default:
                    break;
                }
           // La pila no esta vacia
           }else{
                int auxLinea=pila->linea;       
                char auxCaracter = pop(pila);   
                /* Si el elemento que se lee es diferente al 
                caracter abierto del elemento que se saco de la pila
                existe un error*/
                switch (auxCaracter){
                    case '(':
                        if(caracter!=')'){
                            error('(',auxLinea);
                            return 0;
                        }
                    break;

                    case '[':
                        if(caracter!=']'){
                            error('[',auxLinea);
                            return 0;
                        }
                    break;

                    case '{':
                        if(caracter!='}'){
                            error('{',auxLinea);
                            return 0;
                        }
                    break;

                    case '<':
                        if(caracter!='>'){
                            error('<',auxLinea);
                            return 0;
                        }
                    break;
                
                    default:
                        break;
                }
            }     
        }   
    }

    return 0;
}



