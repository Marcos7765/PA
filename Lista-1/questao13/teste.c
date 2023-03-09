#include <stdio.h>
#include <stdlib.h>

void inserir(float* array, int posI, int posF){
    /*
    quase funciona com void*, precisaria recuperar informação do tipo original
    ou castar os valores dentro do array para void*
    */
    float temp = array[posI];
    int incr = (posF>posI ? 1 : -1);
    for(int i = posI; i != posF; i +=incr){
        array[i] = array[i+incr];
    }
    array[posF] = temp;
}

int main(){
    
    int n;
    printf("Que tamanho terá o vetor? ");
    scanf("%d", &n);
    
    float* vetor = (float*) malloc(sizeof(float)*n);

    printf("Insira, um por linha, os valores do vetor.\n");
    
    for (int i = 0; i < n; i++){
        scanf("%f", &vetor[i]);
    }

    int i = 0;
    while (i<n){

        int posF = -1;

        for(int j = i-1; j>=0;  j--){

            if(vetor[i]<vetor[j]){posF=j;}else{break;}
        }

        if (posF != -1){inserir(vetor, i, posF);}

        i++;
    }
    printf("O vetor ordenado é:\n");
    for(int i=0; i<n; i++){
        printf("%f ", vetor[i]);
    }
    free(vetor);

    return 0;
}