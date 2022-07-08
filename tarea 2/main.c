#include "sorting.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
    FILE *arch;
    arch = fopen(argv[1],"r");
    int it = 0, append = 0;
    char c;
    for (c = getc(arch); c != EOF; c = getc(arch)){
        if (c == '\n'){
            it = it + 1;
        }
    }
    tweet data[it];
    rewind(arch);
    while(!feof(arch)){
        data[append].fecha = malloc(sizeof(char*)*12);
        data[append].hora = malloc(sizeof(char*)*12);
        data[append].user = malloc(sizeof(char*)*12);
        data[append].mensaje = malloc(sizeof(char*)*355);
        fscanf(arch,"%[^;];%[^;];%[^;];%[^\n]",data[append].fecha,data[append].hora,data[append].user,data[append].mensaje);
        //printf("%s  %s  %s  %s\n",data[append].fecha,data[append].hora,data[append].user,data[append].mensaje);
        append = append +1;
    }
    printf("funciona\n");
    insertionSort(data,it);
    //uso de insert sort para pregunta 1 de orden= n^2
    //uso de merge sort para pregunta 2, de orden = nlog(n)
    //crear sorting.c para las implementaciones de los algoritmos
    fclose(arch);
    return 0;
}