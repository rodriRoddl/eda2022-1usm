#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"

int main(int argc, char **argv){
    FILE *arch;
    arch = fopen(argv[0],"r");
    fclose(arch);
    return 0;
}