#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "utils.h"

void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void printArray(int* v, int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
}

void shuffleArray(int* v, int tam){
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        int newPos = rand() % tam;
        swap(&v[i], &v[newPos]);
    }
}

void createArray(int* v, int tam){
    for (int i = 0; i < tam; i++)
    {
        v[i] = i;
    }
}