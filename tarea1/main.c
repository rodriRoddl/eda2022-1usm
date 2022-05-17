#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"
const double pct_interno = 0.25;
const int cant_externo = 5000;

int main(int argc, char **argv){
    FILE *arch;
    arch = fopen(argv[0],"r");
    fclose(arch);
    return 0;
}