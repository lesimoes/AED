#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

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

void bubbleSort(int *vetor){
    //INÍCIO DA CONTAGEM DE TEMPO
    time_t start, end;
    double elapsed;
    time(&start);
    //=========================
    for(int i = 0; i < TAM -1; i++){
        for(int j = (i + 1); j < TAM ; j++){
            if(vetor[j] < vetor[i])
                troca(&vetor[j], &vetor[i]);
        }
    }
        //FIM DA CONTAGEM DE TEMPO
        time(&end);    
        printf("\nBubble Sort: %.2f", difftime(end, start));
        //================
}

void insertionSort(int *vetor){
    time_t start, end;
    double elapsed;
    time(&start);

    int esc, j;
    for(int i = 1 ; i < TAM ; i ++){
        esc = vetor[i];
        j = i - 1;
        while((j >= 0) && (vetor[j] > esc)){
            vetor[j + 1] = vetor[j];
            j --;
        }
        vetor[j + 1] = esc;
    }

    time(&end);    
    printf("\nInsertion Sort: %.2f", difftime(end, start));
};

void selectionSort(int *vetor){
    time_t start, end;
    double elapsed;
    time(&start);

    int min;
    for(int i = 0 ; i < (TAM -1) ; i ++){
        min = i;
        for(int j = (i + 1) ; j < TAM ; j ++){
            if(vetor[j] < vetor[min]) 
                min = j;
        }
        if(vetor[i] != vetor[min]){
            troca(&vetor[min], &vetor[i]);
        }
    }

    time(&end);    
    printf("\nSelection Sort: %.2f", difftime(end, start));
};

int main(){
    
    int vetor[TAM], vetorCopia[TAM];
    aleatorio(vetor);
    copia(vetor, vetorCopia);
    bubbleSort(vetorCopia);
    copia(vetor, vetorCopia);
    insertionSort(vetorCopia);
    copia(vetor, vetorCopia);
    selectionSort(vetorCopia);
    return 0;
}