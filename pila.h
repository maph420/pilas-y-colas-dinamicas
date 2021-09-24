//Esto pregunta si está definida la librería, en caso de no
//estarlo la define
#ifndef __PILA_H__
#define __PILA_H__
#define MAX_PILA 20
#define MAX_COLA 5

#include <stddef.h>

//SNodo def
typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

//SList def
typedef SNodo *SList;

//Pila def
typedef SNodo *Pila;

//Cola def
typedef struct _Cola {
int datos[MAX_COLA];
int primero, ultimo;
} *Cola;



//FuncionVisitante def
typedef void (*FuncionVisitante) (int dato);
/**
 * pila_crear: inicializa la pila.
 */
Pila pila_crear();


/**
 * es_vacia: retorna True (1) si la pila no contiene elementos y False (0) en caso contrario.
 */
int pila_es_vacia(Pila);


/**
 * pila_top: retorna el elemento que esta en el tope.
 */
int pila_top (Pila p);

/**
 * pila_push: inserta el elemento "dato" en el tope de la pila.
 */
Pila pila_push(Pila p, int dato);

/**
 * pila_pop: retorna el elemento que se encuentre en el tope de la pila y lo elimina.
 */
Pila pila_pop(Pila p); 

/**
 * pila_imprimir: imprime contenido de la pila
 */
void pila_imprimir(Pila p);

void pila_destruir(Pila p);

SList slist_reverso(SList);

SList slist_crear();

SList slist_agregar_inicio(SList lista, int dato);

SList slist_agregar_final(SList lista, int dato);

void imprimir(int dato);

void slist_recorrer(SList lista, FuncionVisitante visit);

SList slist_reverso(SList lista);

/*5*/
Cola cola_crear(); /*crea e inicializa una nueva cola vacía.*/

int cola_es_vacia(Cola c);  /*determina si la cola está vacía*/

int cola_primero(Cola c); /*toma una cola y devuelve el elemento en la primera posición*/

void cola_encolar(Cola c, int d); /*toma una cola y un elemento y agrega el elemento al fin de la cola*/

void cola_desencolar(Cola c); /*toma una cola y elimina su primer elemento.*/

void cola_imprimir(Cola c); /*toma una cola y la imprime en orden.*/

void cola_destruir(Cola c); /*libera la memoria requerida para la cola.*/


#endif /* __PILA_H__ */
