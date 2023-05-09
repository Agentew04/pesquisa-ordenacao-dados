#include "heapsort.h"
#include "utils.h"

void heapify(int* v, int tam, int i){
    int esq = 2*i+1;
    int dir = 2*i+2;

    int maior = i;
    if (esq < tam && v[esq] > v[maior]){
        maior = esq;
    }
    if (dir < tam && v[dir] > v[maior]){
        maior = dir;
    }

    if (maior != i){
        swap(v+i, v+maior);
        heapify(v, tam, maior);
    }
}

void maxHeap(int* v, int tam){
    for (int i = tam/2-1; i >=0; i--) {
        heapify(v, tam, i);
    }
}

void heapSort(int* v, int tam){
    maxHeap(v,tam);
    for (int i = tam-1; i>=0; i--)
    {
        swap(v, v+i);
        heapify(v,i,0);
    }

    // do{
    //     maxHeap(v, tam);
    //     swap(v, v+tam-1);
    //     tam--;
    // } while (tam > 1);
}
