#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void aleatorio(int *vetor){
    srand(time(NULL));
    for(int i = 0 ; i < TAM ; i ++)
        vetor[i] = rand() % 20;
};

void copia(int *vetorOriginal, int *vetorCopia){
    for(int i = 0 ; i < TAM ; i ++){
        vetorCopia[i] = vetorOriginal[i];
    }
}

void imprime(int *vetor){
    for(int i = 0 ; i < TAM ; i ++)
        printf("%d ", vetor[i]);
};

void troca(int *valor1, int *valor2){
    int temp = *valor2;
    *valor2 = *valor1;
    *valor1 = temp;
};

void shellSort(int *vetor){
    int valor, i, j;
    int gap = 1;
    while(gap < TAM){
        gap = 3*gap+1;
    }
    while(gap > 1){
        gap /= 3;
        for(int i = gap ; i < TAM ; i++){
            valor = vetor[i];
            j = i;
            while(j >= gap && valor < vetor[j - gap]){
                vetor[j] = vetor[j - gap];
                j = j - gap;
            }
            vetor[j] = valor;
        }
    }
};


void quickSort(int *vetor, int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = vetor[(began + end) / 2];
	while(i <= j)
	{
		while(vetor[i] < pivo && i < end)
		{
			i++;
		}
		while(vetor[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
            troca(&vetor[j], &vetor[i]);
			i++;
			j--;
		}
	}
	if(j > began)
		quickSort(vetor, began, j+1);
	if(i < end)
		quickSort(vetor, i, end);
};


void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int *vetor, int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main(){
    
    int vetor[TAM], vetorCopia[TAM];
    aleatorio(vetor);
    //quickSort(vetor, 0, TAM);
    mergeSort(vetor, 0, TAM);
    imprime(vetor);
    return 0;
}