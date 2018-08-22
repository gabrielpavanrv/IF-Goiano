#include "heapBinario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente{
    char nome[30];
    int prio;
} Paciente;

typedef struct elemento{
    int qtd;
    Paciente dados[MAX];
} Heap;

Heap* criar_heap(){
    Heap* mHeap;
    mHeap = (Heap*) malloc(sizeof(Heap));
    if(mHeap != NULL){
        mHeap->qtd = 0;
    }
    return mHeap;
}

void destruir_heap(Heap** mHeap){
    free(*mHeap);
    *mHeap = NULL;
}

int tamanho_heap(Heap* mHeap){
    if(mHeap == NULL){
        return -1;
    }
    return mHeap->qtd;
}

int cheio_heap(Heap* mHeap){
    if(mHeap == NULL){
        return 0;
    }
    if(mHeap->qtd == MAX){
        return 1;
    }
    return 0;
}

int  vazio_heap(Heap* mHeap){
    if(mHeap == NULL){
        return 0;
    }
    if(mHeap->qtd == 0){
        return 1;
    }
    return 0;
}

int inserir_heap(Heap* mHeap){
    if(mHeap == NULL){
        return 0;
    }
    if(mHeap->qtd == MAX){
        return 0;
    }
    char nome[30];
    int prio;
    printf("Digite o nome: ");
    scanf("\n%[^\n]", nome);
    printf("Digite a prioridade: ");
    scanf("%d", &prio);
    strcpy(mHeap->dados[mHeap->qtd].nome, nome);
    mHeap->dados[mHeap->qtd].prio = prio;
    promover_heap(mHeap, mHeap->qtd);
    mHeap->qtd++;
    return 1;
}

int promover_heap(Heap* mHeap, int filho){
    int pai = (filho - 1) / 2;
    Paciente aux;
    while((filho > 0) && (mHeap->dados[pai].prio <= mHeap->dados[filho].prio)){
        aux = mHeap->dados[pai];
        mHeap->dados[pai] = mHeap->dados[filho];
        mHeap->dados[filho] = aux;
        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int remover_heap(Heap* mHeap){
    if(mHeap == NULL){
        return 0;
    }
    if(mHeap->qtd == 0){
        return 0;
    }
    printf("*** Paciente a ser atendido ***\n");
    printf("Nome: %s\tPrioridade: %d\n", mHeap->dados[mHeap->qtd - 1].nome, mHeap->dados[mHeap->qtd - 1].prio);
    mHeap->qtd--;
    mHeap->dados[0] = mHeap->dados[mHeap->qtd];
    rebaixar_heap(mHeap, 0);
    return 1;
}

int rebaixar_heap(Heap* mHeap, int pai){
    int filho = 2 * pai + 1;
    Paciente aux;
    while(filho < mHeap->qtd){
        if(filho < mHeap->qtd - 1){
            if(mHeap->dados[filho].prio < mHeap->dados[filho + 1].prio){
                filho++;
            }
        }
        if(mHeap->dados[pai].prio >= mHeap->dados[filho].prio){
            break;
        }
        aux = mHeap->dados[pai];
        mHeap->dados[pai] = mHeap->dados[filho];
        mHeap->dados[filho] = aux;

        pai = filho;
        filho = 2 * filho + 1; 
    }
    return 1;
}