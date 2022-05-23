# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// ESTAS FUNCIONES SON DE LA EDA CORRESPONDIENTE A UNA LISTA ENLAZADA SIMPLE
void node_stadium(stadium **cabeza,sector *head,int cant_sec, int pbase);
void first_node(sector **cabeza,int id, int asientos,float factor);
void append(sector *cabeza,int id, int asientos,float factor);
int list_sum(sector *cabeza);
void ordenar_lista(sector *cabeza);
//FUNCIONES PARA LA FILA DE CLIENTES *COLA
void enqueue(queue *cola,char *id,int presupuesto,int n_seccion,int n_entradas);
void print_queue(queue *cola);
int nro_seccion_cliente(sector *cabeza, int presupuesto, int precio);
int cantidad_entradas(sector *cabeza, int presupuesto, int precio);

//FUNCIONES PARA SALIDA DE INFORMACION
void lista_externa_sum(sector *cabeza);
int lista_interna(sector *cabeza);
int recaudacion_queue(queue *cola,stadium *cabeza);