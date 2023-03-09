#include <stdio.h>
#include <stdlib.h>

/*
Função de comparação de valores exigida pelo qsort.
float* ao invés de const void * porque eu ia castar de qualquer forma
*/
int comparacao(float* valor1, float* valor2){
    //Os valores 1, -1 e 0 são pedidos pela qsort para definir o ordenamento
    //é uma one-liner porque one-liners são legais
    return (*valor1 > *valor2) ? 1 : ((*valor2 > *valor1) ? -1 : 0);
}

int main(){
    
    //Recebe o tamanho desejado do vetor e atribui a variável n;
    int n;
    printf("Que tamanho terá o vetor? ");
    scanf("%d", &n);
    
    //Aloca memória para o vetor
    float* vetor = (float*) malloc(sizeof(float)*n);

    //Preenchimento dos valores do vetor, queria saber um jeito melhor
    printf("Insira, um por linha, os valores do vetor.\n");    
    for (int i = 0; i < n; i++){
        scanf("%f", &vetor[i]);
    }

    /*
    Chamada da função, com parâmetros para o array, o tamanho do array, o
    tamanho dos elementos do array na memória e uma função para comparar os
    valores, passada por ponteiro.
    */
    qsort(vetor, n, sizeof(float), comparacao);

    //Demonstração do vetor ordenado.
    printf("O vetor ordenado é:\n");
    for(int i=0; i<n; i++){
        printf("%f ", vetor[i]);
    }

    //Boas práticas
    free(vetor);
    return 0;
}