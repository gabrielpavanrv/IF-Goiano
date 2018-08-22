#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H

#define MAX 5

typedef struct paciente Paciente;
typedef struct elemento Heap;

Heap* criar_heap();
void destruir_heap(Heap** mHeap);
int tamanho_heap(Heap* mHeap);
int cheio_heap(Heap* mHeap);
int vazio_heap(Heap* mHeap);
int inserir_heap(Heap* mHeap);
int promover_heap(Heap* mHeap, int filho);
int remover_heap(Heap* mHeap);
int rebaixar_heap(Heap* mHeap, int pai);


#endif