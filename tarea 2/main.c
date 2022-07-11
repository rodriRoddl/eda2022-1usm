#include "sorting.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *arch;
    arch = fopen(argv[1],"r");
    int it = 0, append = 0;
    char c[2100];
    while(fscanf(arch, "%[^\n] ", c) != EOF){
        it = it +1;
    }
    tweet *data = malloc(it*sizeof(tweet));
    rewind(arch);
    while(!feof(arch)){
        data[append].fecha = malloc(sizeof(char)*20);
        data[append].hora = malloc(sizeof(char)*20);
        data[append].user = malloc(sizeof(char)*20);
        data[append].mensaje = malloc(sizeof(char)*2000);
        fscanf(arch,"%[^;];%[^;];%[^;];%[^\n]",data[append].fecha,data[append].hora,data[append].user,data[append].mensaje);
        //printf("%d\n",append);
        append = append +1;
    }
    int opcion;
    printf("elija el algoritmo de ordenamiento:");
    printf("1)InsertSort (n^2)\n2)mergeSort(n log n)\n3)Radixsort(d(c*n))\n");
    printf("elija el algoritmo de ordenamiento: ");
    scanf("%d",&opcion);
    if(opcion == 1){
        insertionSort(data,it);
    }
    else if(opcion == 2){
        mergeSort(data,0,it);
    }
    else if(opcion == 3){
        RadixSort(data,it);
    }
    else{
        printf("error al elegir metodo");
    }
    fclose(arch);
    return 0;
}