#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "entradas.h"
#include "tda.h"

const double pct_interno = 0.25;
const int cant_externo = 5000;

int main(int argc, char **argv){

    //IMPLEMENTACION DE ITEM 1, USO DE LISTA ENLAZADA SIMPLE
    char nro[20], se[20];
    int nsec ,pre, ide, asi;
    float primer_fac,ultimo_fac;
    FILE *arch;
    arch = fopen(argv[1],"r");
    if(arch == NULL){
        printf("no se reconoce el archivo");
        return(-1);
    }
    stadium *estadio = NULL;
    fscanf(arch,"%s %d %s %d ", nro , &nsec, se, &pre);
    sector *cabeza = NULL;
    fscanf(arch,"%d %d %f",&ide,&asi,&primer_fac);
    first_node(&cabeza,ide,asi,primer_fac);
    while(!feof(arch)){
        fscanf(arch,"%d %d %f",&ide,&asi,&ultimo_fac);
        append(cabeza,ide,asi,ultimo_fac);
    }
    fclose(arch);
    ordenar_lista(cabeza);
    node_stadium(&estadio,cabeza,nsec,pre);
    int suma_asientos = list_sum(cabeza);
    //VEMOS LA FILA DE CLIENTES, ITEM 2, USO DE COLAS
    srand(time(NULL));
    long int nro_clientes = (rand () % (20 - 5 + 1) + 5); //forma natural de determinar un randon entre rangos: (M - n + 1) + n, con M mayor y n menor
    int precio_alto = 3*pre*primer_fac;                       //linea 36, multiplicar por suma_asientos
    int precio_bajo = 0.5*pre*ultimo_fac;
    queue *cola = malloc(sizeof(queue));
    cola->head = NULL;
    cola->final= NULL;
    int percent = pct_interno*suma_asientos;
    printf("\nSECCIONES ORDENADAS DE LA MAS CARA A LA MAS BARATA\n\n");
    for(int i=1;i<=nro_clientes;i++){
        int ident = 20000 + i;
        char *id = malloc(sizeof(char[20]));
        itoa(ident,id,10);
        long int presupuesto = 2*(rand() % (precio_alto - precio_bajo +1) + precio_bajo); //sacar la multi de rand, solo dejarlo con rand
        int n_sec = nro_seccion_cliente(cabeza,presupuesto,pre);
        int c_entr = cantidad_entradas(cabeza,presupuesto,pre);
        enqueue(cola,id,presupuesto,n_sec,c_entr);
        if(i % 4 == 0){                                       //cambiar 4 por cant_ext //
            lista_externa_sum(cabeza);
        }
        if(i % 4 == 0){
            FILE *archivo;
            percent = percent + percent;
            int cantidad_actual = list_sum(cabeza);
            long int recaudacion = recaudacion_queue(cola,estadio);
            printf("\ncantidad de entradas vendidas %d\nentradas restantes %d\n",suma_asientos - cantidad_actual,cantidad_actual);
            printf("recaudacion total:%li\n",recaudacion);
        }
    }
    free(cola);
    free(estadio);
    free(cabeza);
    return 0;
}