#include <stdio.h>

void multMatriz(int linA, int colA, int colB, int A[][colA], int B[][colB], int C[][colB]){
    for (int i=0;i<linA; i++){
        for (int j=0;j<colB; j++){
            //garantir que C tá limpa
            C[i][j] = 0;
            for (int k=0;k<colA;k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main(int argc, char* argv[]){

    int testeA[1][2] = {1, 2};
    int testeB[2][2] = {{3, 4},{5, 6}};
    int testeC[1][2] = {0, 0};

    multMatriz(1, 2, 2, testeA, testeB, testeC);

    printf("%d %d", testeC[0][0], testeC[0][1]);

    return 0;
}