#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/*
Função de comparação de valores exigida pelo qsort.
float* ao invés de const void * porque eu ia castar de qualquer forma
*/
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
    qsort(teste, n, sizeof(int), comparacao);
    double tempo2 = omp_get_wtime();
    //só o tempo para facilitar na medição
    printf("%f", tempo2-tempo);
    free(teste);
    return 0;
}