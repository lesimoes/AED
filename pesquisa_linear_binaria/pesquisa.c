#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100
void gerarVetor(int *vetor){
    for(int i = 0; i < TAM ; i ++)
        vetor[i] = i + 1;
};

int pesquisaLinear(int *vetor, int valor){
    for(int i = 0 ; i < TAM ; i ++){
        if(vetor[i] == valor) return 1;
    }
    return 0;
};

int pesquisaLinearBlocos(int *vetor, int inicio, int fim, int valor){
    for(int i = inicio ; i <= fim ; i ++){
        if(vetor[i] == valor) return 1;
    }
    return 0;
};

int pesquisaIndexada(int *vetor, int valor){
    if(valor <= vetor[49])
        return pesquisaLinearBlocos(vetor, 0, 49, valor);
    return pesquisaLinearBlocos(vetor, 50, TAM, valor);
};

int pesquisaBinaria (int *vet, int valor)
{
     int inf = 0;     
     int sup = TAM - 1; 
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (valor == vet[meio])
               return meio;
          if (valor < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return 0;
};

int pesquisaBinariaRec (int *vetor, int inicio, int fim, int valor)
{
 int meio = (inicio + fim)/2;
 if (vetor[meio] == valor)
    return 1;
 if (inicio >= fim)
    return 0;
 else
     if (vetor[meio] < valor)
        return pesquisaBinariaRec(vetor, meio + 1, fim, valor);
     else
        return pesquisaBinariaRec(vetor, inicio, meio - 1, valor);
};

int main(){
  
    int vet[TAM];
    gerarVetor(vet);  
    printf("%d ", pesquisaBinariaRec(vet, 0, TAM, 2));
    return 0;
};