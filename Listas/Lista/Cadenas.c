#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Elem.h"
#include "Lista.h"

int main(int argc, char*argv[]){
    FILE *in = fopen(*(argv+1), "r");
    char word1[80], *word2;
    Lista words = vacia();

    while(fscanf(in,"%s", word1)!=EOF){
        word2 = (char*)malloc(80);
        strcpy(word2, word1);
        words = cons(word2, words);
    }

    impList(ordListAs(words));

    fclose(in);

    return 0;
}
