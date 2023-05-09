#include "directselectionsort.h"

void directSelectionSort(int* v, int tam){
    for (int i = 0;i < tam;i++)
    {
        int menorIndice = i;

        // achar menor
        for (int j = i; j < tam; j++)
        {
            if(v[j] < v[menorIndice]){
                menorIndice = j;
            }
        }

        int aux = v[i];
        v[i] = v[menorIndice];
        v[menorIndice] = aux;
    }
}