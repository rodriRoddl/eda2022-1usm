#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"

int main(int argc, char **argv){
    FILE *arch;
    arch = fopen(argv[1],"r");
    char nro[20],se[20];
    int nsec,pre;
    fscanf(arch,"%s%d%s%d",nro,&nsec,se,&pre);
    fprintf(stdout,"%s %d %s %d ",nro,nsec,se,pre);
    fclose(arch);
    return 0;
}