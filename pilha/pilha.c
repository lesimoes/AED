#include <stdio.h>
#define TAM 10
struct pilha {
    int topo;
    char elemen[TAM];
}Pilha;

void inicia(struct pilha *P){
    P->topo = -1;
};

char topo(struct pilha *P){
    if(P->topo == -1) return 0;
    return P->elemen[P->topo];
};

int empilhar(struct pilha *P, char valor){
    if(P->topo == TAM - 1) return 0;
    P->topo ++;
    P->elemen[P->topo] = valor;
    return 1;
};

char desempilhar(struct pilha *P){
    if(P->topo == -1) return 0;
    P->topo --;
    return P->elemen[P->topo];  
};

int main(){

    inicia(&Pilha);
    empilhar(&Pilha, 'A');
    empilhar(&Pilha, 'B');
    printf("Empilhando... %c",topo(&Pilha));
    desempilhar(&Pilha);
    printf("\nDesempilhando... %c",topo(&Pilha));
    
    return 0;
}
