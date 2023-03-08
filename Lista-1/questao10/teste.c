#include <stdio.h>

int main(void){
    int exemplo[4];
    int tamanhoInt = sizeof(int);
    unsigned int endereco0 = exemplo;
    printf("Suposição: %u %u %u %u", endereco0, endereco0+tamanhoInt,
            endereco0+2*tamanhoInt, endereco0+3*tamanhoInt);
    printf("\nTeste: %u %u %u %u", &exemplo[0], &exemplo[1], &exemplo[2],
        &exemplo[3]);

    return 0;
}