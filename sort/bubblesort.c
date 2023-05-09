#include "bubblesort.h"

void bubbleSort(int* v, int tam){
    for (int i = 0; i < tam; i++)
    {
        int trocou;
        for (int j = 0; j < tam-i-1; j++)
        {
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                trocou = 1;
            }
        }
        if(!trocou)
            return;
    }
    return;
}

void bubble(int* v, int tam){
    int trocou;
    do{
        trocou = 0;
        for(int i=1; i<tam;i++){
            if(v[i] > v[i-1]){
                int aux = v[i];
                v[i] = v[i-1];
                v[i-1] = aux;
                trocou = 1;
            }
        }
    }while (trocou);
}
void insercaodireta(int*v, int tam){
    for (int i = 1; i < tam; i++)
    {
        int aux = v[i];
        int j = i-1;
        while (v[j] > aux && j>=0)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j] = aux;
    }
}
void shell(int*v,int tam){
    for (int intervalo = (tam+1)/2; intervalo>0; intervalo/=2)
    {
        for(int i = intervalo; i<tam;i++){
            int aux = v[i];
            int j = i-intervalo;
            while (v[j]>aux && j>=0)
            {
                v[j+intervalo] = v[j];
                j-=intervalo;
            }
            v[j+intervalo] = aux;
        }
    }
}
// retorna pivo
void quicksort(int *v, int start, int end){
    int pivo = start;
    int i = start;
    int j = end;
    do{
        while(v[i] < v[pivo]) i++;
        while(v[j] > v[pivo]) j--;

        if(i<=j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }while(i <= j);

    if(j > start){
        quicksort(v, start, j);
    }
    if(i < end){
        quicksort(v, i, end);
    }
}
void selecaodireta(int*v, int tam){
    for (int i = 0; i < tam; i++)
    {

        int menoridx = i;
        // achar menor
        for (int j = i; j < tam; j++)
        {
            if(v[j] < v[menoridx]){
                menoridx = j;
            }
        }
        int aux = v[i];
        v[i] = v[menoridx];
        v[menoridx] = aux;
    }
}
void heapify1(int*v, int tam, int pai){
    int esq = pai*2+1;
    int dir = pai*2+2;

    int maior = pai;
    if(v[esq] > v[maior] && esq < tam){
        maior = esq;
    }
    if(v[dir] > v[maior] && dir < tam){
        maior = dir;
    }
    if(maior != pai){
        int aux = v[maior];
        v[maior] = v[pai];
        v[pai] = aux;
        heapify1(v, tam, maior);
    }
}
void maxheap(int*v, int tam){
    for (int i = tam/2+1; i >=0; i--)
    {
        heapify1(v, tam, i);
    }
}

void heapsort(int*v, int tam){
    maxheap(v, tam);
    for(int i=tam-1; i>=0; i--){
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        heapify1(v, i, 0);
    }
}