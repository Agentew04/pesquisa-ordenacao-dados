#include "shellsort.h"
#include <stdio.h>
void shellSort(int* v, int tam){
    for (int intervalo = (tam+1)/2; intervalo >= 1; intervalo/=2)
    { // intervalo => 5, 2, 1
        printf("no intervalo %d\n", intervalo);
        for (int i = intervalo; i < tam; i++)
        { // i => 5{5, 6, 7, 8, 9} 2{3, 4, 5, 6, 7, 8, 9} 1{1, 2, 3, 4, 5, 6, 7, 8, 9}
            printf("i = %d\n", i);
            int aux = v[i];
            int j = i-intervalo;
            while (j >= 0 && aux<v[j])
            {
                printf("j = %d\n", j);
                v[j+intervalo] = v[j];
                j-=intervalo;
            }
            v[j+intervalo] = aux;
            printf("troca %d com %d\n", v[j+intervalo], aux);
        }
    }
}