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
    fclose(arch);
    int opcion;
    double time_response;
    printf("1)InsertSort (n^2)\n2)mergeSort(n log n)\n3)Radixsort(d(c*n))\n");
    printf("elija el algoritmo de ordenamiento: ");
    scanf("%d",&opcion);
    FILE *file = fopen("reporte.txt","w+");
    if(opcion == 1){
        time_response = insertionSort(data,it);
        fprintf(file,"Tiempo de ejecucion de insertSort: %f [s]",time_response);
    }
    else if(opcion == 2){
        time_response = mergeSort(data,0,it);
        fprintf(file,"Tiempo de ejecucion de mergeSort: %f [s]",time_response);
    }
    else if(opcion == 3){
        time_response = RadixSort(data,it);
        fprintf(file,"Tiempo de ejecucion de RadixSort: %f [s]",time_response);
    }
    else{
        printf("error al elegir metodo");
    }
    return 0;
}