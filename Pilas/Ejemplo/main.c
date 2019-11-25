#include "pila.h"

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
