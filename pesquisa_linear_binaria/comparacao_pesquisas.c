#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000000
void gerarVetor(int *vetor){
    for(int i = 0; i < TAM ; i ++)
        vetor[i] = i + 1;
};

int pesquisaLinear(int *vetor, int valor){

    int comp = 0;

    for(int i = 0 ; i < TAM ; i ++){
        comp++;
        if(vetor[i] == valor) break;
    }

    return comp;
};

int pesquisaLinearBlocos(int *vetor, int inicio, int fim, int valor){
    int comp = 0;
    for(int i = inicio ; i <= fim ; i ++){
        comp++;
        if(vetor[i] == valor) break;
    }
    return comp;
};

int pesquisaIndexada(int *vetor, int valor){


    int comp = 0;
    if(valor <= vetor[49])
        comp = pesquisaLinearBlocos(vetor, 0, 49, valor);
    comp =  pesquisaLinearBlocos(vetor, 50, TAM, valor);

    return comp;
};

int pesquisaBinaria (int *vet, int valor)
{

     int comp = 0;
     int inf = 0;     
     int sup = TAM - 1; 
     int meio;
     while (inf <= sup)
     {
          comp ++;
          meio = (inf + sup)/2;
          if (valor == vet[meio])
               break;
          if (valor < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
    return comp;
};



int main(){
  
    srand(time(NULL));

    int vet[TAM];
    gerarVetor(vet);  
    int buscar = rand() % TAM;
    printf("Valor buscado: %d", buscar);
    printf(" \nPesquisa Linear - Comparacoes: %d ", pesquisaLinear(vet, buscar));    
    printf(" \nPesquisa Indexada - Comparacoes: %d ", pesquisaIndexada(vet, buscar));
    printf(" \nPesquisa Binaria - Comparacoes: %d ", pesquisaBinaria(vet, buscar));
    
    return 0;
};