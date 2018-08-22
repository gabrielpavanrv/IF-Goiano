#include <stdio.h>
#include "heapBinario.h"

int main(){
    Heap* mHeap = criar_heap();
    int i;
    for(i = 0; i < MAX; i++){
        inserir_heap(mHeap);
        printf("Insercao %d com sucesso!\tTamanho do heap: %d\n", i + 1, tamanho_heap(mHeap));
    }
    printf("\n");
    for(i = 0; i < MAX; i++){
        remover_heap(mHeap);
        printf("Remocao %d com sucesso!\tTamanho do heap: %d\n", i + 1, tamanho_heap(mHeap));
    }
    destruir_heap(&(mHeap));
    return 0;
}