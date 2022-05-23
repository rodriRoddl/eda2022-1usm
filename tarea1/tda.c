#include<stdio.h>
#include<stdlib.h>
#include "entradas.h"

//IMPLEMENtACION PARA ESTADIOS
void node_stadium(stadium **cabeza,sector *head,int cant_sec, int pbase){
    stadium *nuevo = malloc(sizeof(stadium));
    nuevo->cant_sec = cant_sec;
    nuevo->pbase = pbase;
    nuevo->secc = head;
    *cabeza = nuevo;
}

//IMPLEMENTACION PARA SECTORES
void first_node(sector **cabeza,int id, int asientos,float factor){
    sector *nuevo = malloc(sizeof(sector));
    nuevo->id =id;
    nuevo->asientos = asientos;
    nuevo->factor = factor;
    nuevo->sgte = NULL;
    *cabeza = nuevo;
}

void append(sector *cabeza,int id, int asientos,float factor){
    sector *nuevo = malloc(sizeof(sector));
    nuevo->id =id;
    nuevo->asientos = asientos;
    nuevo->factor = factor;
    sector *recorrer = cabeza;
    while(recorrer->sgte!=NULL){
        recorrer = recorrer->sgte;
    }
    nuevo->sgte = recorrer->sgte;
    recorrer->sgte = nuevo;
}

int list_sum(sector *cabeza){
    sector *recorrer = cabeza;
    int suma_asientos = 0;
    while(recorrer!=NULL){
        suma_asientos = suma_asientos + recorrer->asientos;
        recorrer = recorrer->sgte;
    }
    return suma_asientos;
}

//IMPLEMENTACION DE FUNCIONES DE COLA PARA CLIENTES

void enqueue(queue *cola,char *id,int presupuesto,int n_seccion,int n_entradas){
    fans *temp = malloc(sizeof(fans));
    temp->presupuesto = presupuesto;
    temp->n_seccion = n_seccion;
    temp->n_entradas = n_entradas;
    temp->id = id;
    temp->sgte = NULL;
    if(cola->head == NULL){
        cola->head = temp;    //encola primer elemento
    }
    else{
        (cola->final)->sgte = temp;
    }
    cola->final = temp;          //puntero que apunta al final.
}


int nro_seccion_cliente(sector *cabeza, int presupuesto, int precio){
    sector *recorrer = cabeza;
    int nro_seccion=0;
    while(recorrer!=NULL){
        int precio_boleto = precio*recorrer->factor;
        if(presupuesto >= precio_boleto){
            nro_seccion = recorrer->id;
            break;
        }
        recorrer = recorrer->sgte;
    }
    return nro_seccion;
}

int cantidad_entradas(sector *cabeza, int presupuesto, int precio){
    sector *recorrer = cabeza;
    int nro_boletos = 0;
    while(recorrer!=NULL){
        int precio_boleto = precio*recorrer->factor;
        if(presupuesto >= precio_boleto && recorrer->asientos>0){
            presupuesto = presupuesto-precio_boleto;
            nro_boletos = 1;
            recorrer->asientos = recorrer->asientos -1;
            if(presupuesto >= precio_boleto && recorrer->asientos>0){
                recorrer->asientos = recorrer->asientos -1;
                nro_boletos = 2;
                break;
            }
        }
        recorrer = recorrer->sgte;
    }
    return nro_boletos;
}

//FUNCIONES PARA MOSTRAR REPORTES PUBLICOS Y PRIVADOS RESPECTIVAMENTE

void lista_externa_sum(sector *cabeza){
    sector *recorrer = cabeza;
    int suma_asientos = 0;
    printf("---Lista De Estadio---\n");
    while(recorrer!=NULL){
        suma_asientos = suma_asientos + recorrer->asientos;
        printf("seccion: %d, asientos: %d\n",recorrer->id,recorrer->asientos);
        recorrer = recorrer->sgte;
    }
    printf("TOTAL DE BOLETOS DISPONIBLES: %d\n",suma_asientos);
    printf("---Fin De Lista---\n\n");
}

int recaudacion_queue(queue *cola,stadium *cabeza){
    fans *temp = cola->head;
    sector *recorrer = cabeza->secc;
    int recaudacion = 0;
    while(recorrer!=NULL){
        int recaudacion_por_seccion =0;
        while(temp!=NULL){
            if(temp->n_seccion == recorrer->id){
                recaudacion = recaudacion + (cabeza->pbase*recorrer->factor)*temp->n_entradas;
                recaudacion_por_seccion = recaudacion_por_seccion + (cabeza->pbase*recorrer->factor)*temp->n_entradas;
            }
            temp = temp->sgte;
        }
        printf("recaudacion de seccion:%d:%d\n",recorrer->id,recaudacion_por_seccion);
        recorrer = recorrer->sgte;
    }
    return recaudacion;
}