#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H

#define MAX1 4
#define MAX2 2

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

int uniao_heap(Heap* mHeap, Heap* mHeap2);
int buscar_heap(Heap* mHeap, Paciente* dadosH2);
int inserir2_heap(Heap* mHeap, Paciente* dadosH2);
int remover2_heap(Heap* mHeap2);
#endif