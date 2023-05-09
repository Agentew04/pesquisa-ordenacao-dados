#include "insertionsort.h"

void insertionSort(int* v, int tam){
    for(int i=1; i<tam; i++){
        int j = i-1;
        int aux = v[i];
        while (v[j] > aux && j >=0)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
    return;
}