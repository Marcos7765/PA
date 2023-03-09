#include <stdio.h>

int terceiraFunc(const char* texto){
    return fprintf(stdout, texto);
}

int main(){    
    
    int (*teste[])() = {printf, puts, terceiraFunc};
    
    for (int i = 0; i < 3; i++){
        teste[i]("Ola mundo\n");
    }
    return 0;
}