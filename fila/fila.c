#include <stdio.h>
#define TAM 10
struct fila {
    int inicio, fim, tamanho;
    char elemen[TAM];
}Fila;

void iniciar(struct fila *F){
    F->inicio = 1;
    F->fim = 0;
    F->tamanho = 0;
};

int filaVazia(struct fila *F){
    if(F->tamanho == 0) return 1;
    return 0;
};

int inserir(struct fila *F, char valor){
    if(F->fim == TAM -1) return 0;
    F->tamanho ++;
    F->fim = (F->fim % (TAM - 1) ) + 1;
    F->elemen[F->fim] = valor;
    return 1;
};

char retirar(struct fila *F){
    if(filaVazia(F)) return 0;
    F->tamanho --;
    F->inicio = (F->inicio % (TAM - 1)) + 1;
    return F->elemen[F->inicio - 1];
};



int main(){

    iniciar(&Fila);
    inserir(&Fila, 'A');
    inserir(&Fila, 'B');
    inserir(&Fila, 'C');
    printf("%c", retirar(&Fila));
    return 0;
}