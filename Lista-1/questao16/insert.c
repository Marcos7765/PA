#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

void inserir(void* array, int tamByte, int posI, int posF){
    /*
    vendo como qsort() consegue ser genérica e pega info do tipo com um
    parâmetro para tamanho dos elementos, pesquisei e achei essa ideia de castar
    para char* (já que char tem size de 1 byte): 
    https://stackoverflow.com/questions/28130524/how-to-split-a-generic-void-array-into-parts-c
    */
    void* temp;
    memmove(&temp, ((char*)array)+(posI*tamByte), tamByte);
    int incr = (posF>posI ? 1 : -1);
    for(int i = posI; i != posF; i +=incr){
        memmove( ( (char*) array) + i*tamByte, 
                ( (char*) array) + (i+incr)*tamByte, tamByte);
    }
    ((char*)array)[posF*tamByte] = temp;
}

void ordenar(void* array, int tamByte, int tamanho, 
            int (*comparacao)(void*, void*)){
    int i = 0;
    while (i<tamanho){

        int posF = -1;

        for(int j = i-1; j>=0;  j--){
            if (comparacao(((char*)array)+j*tamByte,((char*)array)+i*tamByte) ==
                1){ posF=j; } else { break; }
        }

        if (posF != -1){inserir(array, tamByte, i, posF);}

        i++;
    }
}

int comparacao(int* valor1, int* valor2){
    return (*valor1 > *valor2) ? 1 : ((*valor2 > *valor1) ? -1 : 0);
}

int main(int argc, char* argv[]){
    
    int n = argc - 1;
    int* teste = (int*) malloc(sizeof(int)*n);
    
    for (int i=0; i<n; i++){
        teste[i] = atoi(argv[i+1]);
    }
    
    /*
    usando o get_wtime do OpenMP pela praticidade e precisão, compile com a flag
    do openmp no seu compilador (-fopenmp no gcc, /openmp no msvc)
    */
    double tempo = omp_get_wtime();
    ordenar(teste, sizeof(int), n, comparacao);
    double tempo2 = omp_get_wtime();
    //só o tempo para facilitar na medição
    printf("%f", tempo2-tempo);
    free(teste);
    return 0;
}