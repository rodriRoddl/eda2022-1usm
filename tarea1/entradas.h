# include <stdio.h>
# include <stdlib.h>
# include <string.h>
extern const double pct_interno = 0.25;
extern const int cant_externo = 5000;
typedef struct seccion {
    int id ;
    int asientos ;
    float factor ;
    struct seccion *sgte;
} sector ;
typedef struct estadio {
    int cant_sec ;
    int pbase ;
    sector * secc ;
} stadium ;
typedef struct cliente {
    char * id ;
    int presupuesto ;
    int n_seccion ;
    int n_entradas ;
    struct cliente * sgte ;
} fans ;
