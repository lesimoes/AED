#include <stdio.h>
#define TAM 10
struct lista {
    int n;
    char elemen[TAM];
}Lista;


void iniciaListaVazia(struct lista *L){ L->n = 0;}
void iniciaListaCheia(struct lista *L){ L->n = 9;}
void iniciaLista(struct lista *L){ L->n = 4;}

int validaLista(struct lista *L, int k){
    if(k < 0 || k > (L->n-1) || (L->n > TAM - 1))
        return 0;
    return 1;
 };

char acessarElemento(struct lista *L, int k){
    if(!validaLista(L, k)) 
        return 0;
    return(L->elemen[k]);  
};

int alterarElemento(struct lista *L, int k, char valor){
    if(!validaLista(L, k)) 
        return 0;
    L->elemen[k] = valor;
    return 1;
};

int inserirFinalLista(struct lista *L, char valor){
    L->elemen[L->n] = valor;
    L->n ++;
    return 1;
};

int inserirEntreElementos(struct lista *L, int k, char valor){
    if(!validaLista(L, k)) return 0;
    for(int i = L->n ; i > k ; i --){
        L->elemen[i] =  L->elemen[i - 1];
    }
    L->elemen[k] = valor;
    L->n ++;
    return 1;
};

int inserir(struct lista *L, int k, char valor){
    if(k == L->n) return inserirFinalLista(L, valor);
    return inserirEntreElementos(L, k, valor);
    return 0;   
};

int remover(struct lista *L, int k){
    if(!validaLista(L, k)) return 0;
    for(int i = k ; i < L->n ; i ++){
        L->elemen[i] = L->elemen[i + 1];
    }
    L->n --;
    return 1;
};

void concatena(struct lista *L, struct lista *L1){
    int limite;
    if(L->n + L1->n <= TAM)
        limite = L1->n;
    for(int i = 1 ; i <= limite ; i ++){
        L->elemen[L->n] = L1->elemen[i - 1];
        L->n++;
    }
};

struct lista sublista(struct lista *L, int k, int n){
    struct lista subLista;
    iniciaListaVazia(&subLista);
    for(int i = 0 ; i < n ; i ++){
        inserir(&subLista, i, L->elemen[k + i]);
    }
    return subLista;
};

int main(){

    struct lista listaNova;

    iniciaListaVazia(&Lista);
    inserir(&Lista, 0, 'A');
    inserir(&Lista, 1, 'B');
    inserir(&Lista, 2, 'C');
    inserir(&Lista, 3, 'D');
    inserir(&Lista, 4, 'E');
    
    listaNova = sublista(&Lista, 2, 3);
 
    for(int i = 0 ; i < Lista.n ; i ++)
        printf("%c", acessarElemento(&listaNova, i));
   
    return 0;
}