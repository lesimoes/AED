#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

struct arvore {
    char info;
    struct no *esq, *dir;
}parvore;



void inserir(struct arvore *plist, char valor){
    if(plist == NULL){
        plist = (parvore) malloc(sizeof(struct arvore));
        plist->info = valor;
        plist->esq = NULL;
        plist->dir = NULL;
    }else{
        if(valor < plist->info)
            inserir(&plist->esq, valor);
        else
            inserir(&plist->dir, valor);
    }
}


int main(){
    
    
    return 0;
}