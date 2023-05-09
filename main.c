#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
//#define BIG
#include "utils.h"


#ifdef BIG
    #define TAM 1000
#else
#define TAM 10
#endif

int main(void){
    int vet[TAM];
    createArray(vet, TAM);
    shuffleArray(vet, TAM);

    #ifndef BIG
    printf("Antes: \n");
    printArray(vet, TAM);
    printf("\n");
    #endif

    // sort the array
    shellSort(vet, TAM);

    printf("Depois: \n");
    printArray(vet, TAM);
    printf("\n");
}