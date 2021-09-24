#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

/** EJERCICIO 3 **/

/*1*/
Pila pila_crear() {
    return NULL;
}

/*2*/
int pila_es_vacia(Pila p) {
    return p == NULL;
}

/*3*/
int pila_top (Pila p) {
    return p->dato;
}

/*4*/
Pila pila_push(Pila p, int dato){
Pila nuevaPila = malloc(sizeof(int)*MAX_PILA);
nuevaPila->dato = dato;
nuevaPila->sig = p;
p = nuevaPila;
return nuevaPila;
}

/*5*/
Pila pila_pop(Pila p) {
if (p == NULL) return NULL;
Pila tmp = p;
tmp = tmp->sig;
return tmp;
}

/*6*/
void pila_imprimir(Pila p){
    for(; p != NULL; p = p->sig)
        printf("%d\n",p->dato);
}

/*7*/
void pila_destruir(Pila p) {
    free(p);
}

/** EJERCICIO 4 **/

SList slist_crear() {
  return NULL;
}

void imprimir(int dato){
    printf("%d\n",dato);
}

SList slist_agregar_final(SList lista, int dato) {
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    if (lista == NULL)
        return nuevoNodo;
    else {
        SNodo* temp = lista;
        for (;temp->sig != NULL;temp = temp->sig); /* ahora 'nodo' apunta al ultimo elemento en la lista */
        temp->sig = nuevoNodo;
    }
    return lista;
}


void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

SList slist_reverso(SList lista){
    Pila newPila = malloc(sizeof(int)*MAX_PILA);
    newPila = pila_crear();
    int c=0;

    SList tmp = lista;
    for(;tmp != NULL; tmp=tmp->sig) {
            newPila = pila_push(newPila,tmp->dato);
            c++;
        }

        /*hasta aca tenemos la pila con los elementos invertidos*/

    for(int i=0;i<c;i++) {
        lista = slist_agregar_final(lista,newPila->dato); /*agregamos al final de la lista lo que esta al principio de la pila etc etc*/
        lista = lista->sig;
        newPila = newPila->sig;
    } 

return lista;
}

/** EJERCICIO 5 **/

Cola cola_crear() {
Cola c = malloc(sizeof(Cola));
c->primero = -1; 
c->ultimo = -1;
return c;
}

int cola_es_vacia(Cola c) {
    return c->primero==(-1);
}

int cola_primero(Cola c) {
    return c->primero;
}

void cola_encolar(Cola c, int d) {
    if((c->primero == 0 && c->ultimo == MAX_COLA-1) || c->primero == c->ultimo+1){ /*no queda ningun espacio por utilizar.*/
        printf("\nexcedido tamanio de cola\n");
        printf("intento: encolo: %d, primero: %d, ultimo: %d\n",d,c->primero,c->ultimo);
        return;
    }
    if(c->primero == -1){ /**pregunto si la cola esta vacia, en caso de estarla hago que el primer y el ultimo indice apunten a 0**/
        c->primero = 0; 
        c->ultimo = 0;
    }
    else{
        if(c->ultimo == MAX_COLA-1) /*cuando el ultimo indice este por alcanzar el limite de elementos, lo hacemos volver al principio*/
            c->ultimo = 0;
        else c->ultimo++;
    }
    
    printf("encolo: %d, primero: %d, ultimo: %d\n",d,c->primero,c->ultimo);
    c->datos[c->ultimo] = d;
}

void cola_desencolar(Cola c) {
    if(c->primero == -1){    /*pregunto si la cola esta vacia*/   
        printf("no hay elementos por desencolar\n");
        return;
    }
    printf("\nelemento a eliminar: %d\n",c->datos[c->primero]);
    if(c->primero == c->ultimo){ /*desencolo el unico elemento de la cola, por lo cual los indices deben quedar apuntando a la nada*/
        c->primero = -1;
        c->ultimo = -1;
    }
    else{
        if(c->primero == MAX_COLA-1){   /*cuando el indice del primer elemento esta por alcanzar el limite, lo hacemos volver al principio*/
            c->primero = 0;
        }
        else c->primero++;
    }
}

void cola_imprimir(Cola c) {
    int i_primero = c->primero;
    int i_ultimo = c->ultimo;

    if(i_primero <= i_ultimo){              /*en caso de que ninguno los ultimos elementos haya sido puesto al principio*/
        while(i_primero <= i_ultimo){       /*^^basicamente, la cantidad de elementos encolados es menor a la del limite de elementos aceptado*/
            printf("%d\n",c->datos[i_primero]);
            i_primero++;
        }
    }
        else {                  
                while(i_primero <= MAX_COLA-1){ /*imprimo primero a la derecha del primero*/
                    printf("%d\n",c->datos[i_primero]);
                    i_primero++;
                }
            i_primero = 0;
            while(i_primero <= i_ultimo){ /*imprimo a la izquierda del primero*/
                printf("%d\n",c->datos[i_primero]);
                    i_primero++;
            }

        }
    }

void cola_destruir(Cola c) {
    free(c);
}