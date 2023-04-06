#include "gc.h"
#include <stdio.h>

void prtStatus(){
    printf("Tamanho do heap (%lu), bytes livres (%lu), total de bytes \
alocados durante a execução (%lu)\n\n",
    GC_get_heap_size(), GC_get_free_bytes(), GC_get_total_bytes());

}

void alocacao(){
    printf("Função com alocação que não é liberada e o ponteiro é perdido fora \
do escopo, criando um memory leak.\n");
    void* ptrExemplo = GC_malloc(GC_get_heap_size()-1);
    prtStatus();
}

int main(){
    
    GC_init();
    //garantir que não aumentem o heap ao alocar mais memória
    GC_set_max_heap_size(GC_get_heap_size());
    
    printf("Início do programa.\n");
    prtStatus();

    alocacao();

    printf("Forçando o garbage collector na função principal para mostrar seu \
efeito.\n");
    
    //assim no loop porque o gc não percebe de primeira
    while(GC_get_free_bytes()==0){
    GC_gcollect();
    }

    prtStatus();

    printf("Realocando outro ponteiro.\n");
    void* prtExemplo2 = GC_malloc(GC_get_heap_size()-1);

    prtStatus();

    return 0;
}
