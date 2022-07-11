#include "tweets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void insertionSort(tweet arr[], int n){
int i, j;
double value;
tweet key;
clock_t start = clock();
for (i= 1 ; i < n ; i ++){
    key = arr[i];
    j = i-1;
    while(j >= 0 && (strcmp(arr[j].fecha,key.fecha) >= 0)){
        arr [j+1] = arr [j] ;
        j--;
    }
    arr [j+1] = key;
    }
}

void merge(tweet arr[], int l, int m,int r){
    int i,j,k;
    int n1 = m-l +1;
    int n2 = r-m;
    tweet L[n1], R[n2];
    for(i = 0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    i = 0; j = 0 ; k = l;
    while(i<n1 && j<n2){
        if(strcmp(L[i].fecha,R[j].fecha) <= 0){
            arr[k] = L[i]; i++;
        }
        else{
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i]; i++;k++;
    }
    while( j < n2){
        arr[k] = R[j]; j++;k++;
    }
}

void mergeSort(tweet arr[],int l, int r){
    if(l<r){
    int m = l + (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    }
}

tweet maximo(tweet *A, int tam){
    int i;
    tweet mayor = A[0];
    for( i = 1; i< tam;i++){
        if (strcmp(A[i].fecha,mayor.fecha) > 0){
            mayor = A[i];
        }
    }
    return mayor;
}

void CountingSort(tweet *A, int tam, int lugar){
    tweet B[tam];
    char y[4],m[2],d[2];
    int  i , ind_sgte,veces,fecha;
    int max = 0;
    for(i=1;i<tam;i++){
        sscanf(A[i].fecha,"%s:%s:%s",y,m,d);
        strcat(y,m);
        strcat(y,d);
        fecha = atoi(y);
        if(((fecha/lugar)%10)> max){
            max = (fecha/lugar) %10;
        }
    }
    //no se que mas hacer a partir de aca.
}

void RadixSort(tweet *A, int tam){
    int pos, fecha;
    char y[4],m[2],d[2];
    tweet max = maximo(A,tam);
    sscanf(max.fecha,"%s:%s:%s",y,m,d);
    strcat(y,m);
    strcat(y,d);
    fecha = atoi(y);
    printf("%d",fecha);
    for(pos = 0; (fecha / pow(10,pos)) > 0 ;pos++){
        CountingSort(A,tam,pow(10,pos));
    }
}