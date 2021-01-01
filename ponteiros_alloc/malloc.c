#include <stdio.h>


int main(int argc, const char * argv[]) {
    
    int tamanho;
    printf("Digite um tamanho para o vetor: ");
    scanf("%d", &tamanho);
    
    //Aqui separamos um espaço em memório dinamicamente do tamanhao digitado pelo usuário
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    
    for (int i = 0 ; i < tamanho ; i ++) {
        vetor[i] = i + 1;
        printf("%d ", vetor[i]);
    }
    
    printf("\n");
    return 0;
}