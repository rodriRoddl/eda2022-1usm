# include <stdio.h>
# include <stdlib.h>
# include <string.h>

extern const double pct_interno;
extern const int cant_externo;

typedef struct seccion {
    int id ;
    int asientos ;
    float factor ;
    struct seccion *sgte;
} sector ;
typedef struct estadio {
    int cant_sec;
    int pbase ;
    sector * secc ;
} stadium ;
typedef struct cliente {
    char * id;
    int presupuesto ;
    int n_seccion ;
    int n_entradas ;
    struct cliente * sgte;
} fans ;

typedef struct cola{
    fans *head;
    fans *final;
}queue;

/*  nota: vamos a crear la cola con la cantidad de personas totales, ojo, si la persona no le da el presupuesto para comprar ninguna, se marca como 0, tanto el n_sec
    como la entrada, al final, se tendra un contador al momento de pasar por la lista enlazada de secciones, el cual me dira la cantidad de personas que compraron y la cantidad
    que no compro.  */