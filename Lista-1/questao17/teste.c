#include <stdio.h>
#include <stdlib.h>

void somaVetor(int v1[], int v2[], int res[], int tamanho){
    for (int i=0;i<tamanho;i++){res[i] = v1[i]+v2[i];}
}
//li errado a questão e fiz mais que o necessário
int main(int argc, char* argv[]){
    
    if (argc != 5){printf("Use: %s <NOME V1> <NOME V2> <TAMANHO>", argv[0]);}

    int tamanho = atoi(argv[4]);

    struct vetor {
        int* array;
        char* nome;
    };
    struct vetor vetor1 = {(int*)malloc(sizeof(int)*tamanho), argv[1]};
    struct vetor vetor2 = {(int*)malloc(sizeof(int)*tamanho), argv[2]};
    struct vetor resultado = {(int*)malloc(sizeof(int)*tamanho), argv[3]};

    printf("Insira, um por vez, os %d valores do vetor %s:\n",tamanho,vetor1.nome);
    for (int i=0; i<tamanho; i++){scanf("%d",&vetor1.array[i]);}

    printf("Insira, um por vez, os %d valores do vetor %s:\n",tamanho,vetor2.nome);
    for (int i=0; i<tamanho; i++){scanf("%d",&vetor2.array[i]);}

    /*
    for (int i=0; i<tamanho; i++){
        resultado.array[i] = vetor1.array[i] + vetor2.array[i];
    }
    */
   somaVetor(vetor1.array, vetor2.array, resultado.array, tamanho);

    printf("Vetor \"%s\" = (%d", vetor1.nome, vetor1.array[0]);
    for (int i=1; i<tamanho; i++){printf(", %d",vetor1.array[i]);}

    printf(");\nVetor \"%s\" = (%d", vetor2.nome, vetor2.array[0]);
    for (int i=1; i<tamanho; i++){printf(", %d",vetor2.array[i]);}

    printf(");\nVetor \"%s\" = (%d", resultado.nome, resultado.array[0]);
    for (int i=1; i<tamanho; i++){printf(", %d",resultado.array[i]);}
    printf(");\n");

    return 0;
}