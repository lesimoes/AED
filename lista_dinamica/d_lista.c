#include <stdio.h>
#include <stdlib.h>
#define TAM 10
struct No {
    char info;
    struct No *prox;
};

void inserir(struct No *no, char valor){
    struct No *novo;
    novo = malloc(sizeof(struct No));
    novo->info = valor;
    novo->prox = no->prox;
    no->prox = novo;
};


void imprime(struct No *no){
    struct No *novo;
    for(novo = no ; novo->info != '\0' ; novo = novo->prox)
        printf("%c", novo->info);
};

struct No* buscar(struct No *no, char valor){
    struct No *novo;
    novo = no;
    while(novo->info != '\0' && novo->info != valor){
        novo = novo->prox;
    }
    return novo;   
}

int remover(struct No *no, char valor){
    struct No *aux = buscar(no, valor);
    if(aux->info == '\0') return 0;
    no->prox = aux->prox;
    free(aux);
    return 1;
}

int main(){
    struct No no;
    no.info = 'A';
    inserir(&no, 'B');
    inserir(&no,'C');
    printf("Antes da remocao \n");
    imprime(&no);
    remover(&no, 'B');
    printf("\nApos a remocao \n");
    imprime(&no);
    return 0;
}