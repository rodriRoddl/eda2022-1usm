#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    long int nro_clientes = /*suma_asientos**/suma_asientos*(rand () % (20 - 5 + 1) + 5); //forma natural de determinar un randon entre rangos: (M - n + 1) + n, con M mayor y n menor
    int precio_alto = 3*pre*primer_fac;
    int precio_bajo = 0.5*pre*ultimo_fac;
    queue *cola = malloc(sizeof(queue));
    cola->head = NULL;
    cola->final= NULL;
    int factor_percent = 1, sin_entradas = 0;
    int porcentaje = factor_percent*pct_interno*suma_asientos;
    printf("\nSECCIONES ORDENADAS DE LA MAS CARA A LA MAS BARATA\n\n");
    int i = 1;
    int entradas = 0;
    char id[20];
    while(i<=nro_clientes){
        int ident = 20000 + i;
        sprintf(id,"%d",ident);
        long int presupuesto = (rand() % (precio_alto - precio_bajo +1) + precio_bajo);
        int n_sec = nro_seccion_cliente(cabeza,presupuesto,pre);
        int c_entr = cantidad_entradas(cabeza,presupuesto,pre);
        enqueue(cola,id,presupuesto,n_sec,c_entr);
        entradas = entradas + c_entr;
        if(n_sec == 0){
            sin_entradas = sin_entradas +1;
        }
        //REPORTE EXTERNO
        if(entradas >= cant_externo && (entradas % cant_externo == 0 || entradas %cant_externo == 1)){
            lista_externa_sum(cabeza);
        }
        //REPORTE INTERNO
        if(entradas >= porcentaje && (entradas %  porcentaje == 0 || entradas % porcentaje == 1)){
            char *nombre = malloc(sizeof(char[20]));
            sprintf(nombre,"%0.0f",factor_percent*pct_interno*100);
            strcat(nombre,"%");
            strcat(nombre,".txt");
            FILE *archivo = fopen(nombre,"w");
            int cantidad_actual = list_sum(cabeza);
            unsigned long int recaudacion = recaudacion_queue(cola,estadio,archivo);
            fprintf(archivo,"\ncantidad de entradas vendidas %d\nentradas restantes %d\n",suma_asientos - cantidad_actual,cantidad_actual);
            fprintf(archivo,"Cantidad de clientes que no pudieron adquirir una entrada %d\n",sin_entradas);
            fprintf(archivo,"Cantidad de clientes restantes en la fila simulada %li\n",nro_clientes-i);
            fprintf(archivo,"recaudacion total %li\n\n",recaudacion);
            factor_percent = factor_percent + 1;
            porcentaje = factor_percent*pct_interno*suma_asientos;
            free(nombre);
        }
        i = i + 1;
    }
    clean_list(cabeza);
    clean_queue(cola);
    free(cola->head);
    free(cola->final);
    free(cola);
    free(cabeza);
    free(estadio->secc);
    free(estadio);
    return 0;
}