#include <stdio.h>
#include "heapBinario.h"

int main(){
    Heap* mHeap = criar_heap();
    Heap* mHeap2 = criar_heap();
    int i;
    for(i = 0; i < MAX1/2; i++){
        inserir_heap(mHeap);
        printf("Insercao %d com sucesso!\tTamanho do heap: %d\n", i + 1, tamanho_heap(mHeap));
    }
    for(i = 0; i < MAX2; i++){
        inserir_heap(mHeap2);
        printf("Insercao %d com sucesso!\tTamanho do heap: %d\n", i + 1, tamanho_heap(mHeap2));
    }
    if(uniao_heap(mHeap, mHeap2)){
        printf("Unicao com sucesso!\n");
    } else{
        printf("Falha na uniao!\n");
    }
    int tamAtual = tamanho_heap(mHeap);
    for(i = 0; i < tamAtual; i++){
        remover_heap(mHeap);
        printf("Remocao %d com sucesso!\tTamanho do heap: %d\n\n", i + 1, tamanho_heap(mHeap));
    }
    destruir_heap(&(mHeap));
    return 0;
}