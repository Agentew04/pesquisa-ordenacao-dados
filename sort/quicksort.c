#include "quicksort.h"

// retorna o indice do pivo
int particao(int* v, int indexStart, int indexEnd){
    int pivo = v[indexStart]; // primeiro
    int i = indexStart;
    int j = indexEnd;
    do{
        while(v[i] < pivo /*&& i < indexEnd*/){ // mover i para a direita
            i++;
        }
        while(v[j] > pivo /*&& j > indexStart*/){ // mover j para a esquerda
            j--;
        }

        if(i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while(i<j);
    return i;
}

void __quickSort(int* v, int indexStart, int indexEnd){
    if (indexEnd == indexStart)
        return;
    int indexPivo = particao(v, indexStart, indexEnd);
    // 1a parte
    __quickSort(v, indexStart, indexPivo-1);
    // 2a parte
    __quickSort(v, indexPivo, indexEnd);
}

void quickSort(int* v, int tam){
    __quickSort(v, 0, tam-1);
}