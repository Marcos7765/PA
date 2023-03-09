#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(){
    int teste[3] = {27, 90, 2};
    ordenar(teste, sizeof(int), 3, comparacao);
    printf("Teste com vetor {27, 90, 2}:\n%d %d %d\n", teste[0], teste[1], teste[2]);
    return 0;
}