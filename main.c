//Autor: Alan Hergenreder.
/*Pila
Una pila (Stack) es una estructura de datos definida por la siguiente forma:
-Solo se puede extraer el último elemento instertado.
La posicion en la que se encuentra dicho elemento se denomina Tope.
Se dice que las Pilas son una estuctura de datos LIFO (Last-In First-Out).*/

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main (){

  /**3: pilas enlazadas**/
  Pila pila = malloc(sizeof(int)*MAX_PILA);
  pila = pila_crear();
  printf("\nNueva pila\n");
  printf("pila_es_vacia: %d\n",pila_es_vacia(pila));
  pila = pila_push(pila,2);
  pila = pila_push(pila,4);
  pila = pila_push(pila,6);
  pila = pila_push(pila,8);
  pila = pila_push(pila,10);
  pila = pila_push(pila,12);
  printf("pila_es_vacia: %d\n",pila_es_vacia(pila));
  printf("pila_top: %d\n",pila_top(pila));
  pila = pila_pop(pila);
  printf("pila_top: %d\n",pila_top(pila));
  printf("Elementos de la pila:\n");
  pila_imprimir(pila);
 
pila_destruir(pila);
printf("------------\n");

/**4: revertir una lista enlazada SList usando una pila**/
SList lista = slist_crear();
  printf("Nueva slist\n");
lista = slist_agregar_final(lista,3); //3
lista = slist_agregar_final(lista,6); //3, 6
lista = slist_agregar_final(lista,9); //3, 6, 9
printf("slist:\n");
slist_recorrer(lista,imprimir);
lista = slist_reverso(lista); //9, 6, 3
printf("slist_reverso:\n");
slist_recorrer(lista,imprimir);
printf("------------\n");


/**5: colas con arreglos circulares**/
Cola cola = cola_crear();
printf("creo nueva cola\n");
printf("cola_es_vacia: %d\n",cola_es_vacia(cola));
printf("encolo elementos\n");
cola_encolar(cola,2);
cola_encolar(cola,4);
cola_encolar(cola,6);
cola_encolar(cola,8);
cola_encolar(cola,10);
cola_encolar(cola,12);
printf("cola_es_vacia: %d\n",cola_es_vacia(cola));
printf("cola:\n");
cola_imprimir(cola);
printf("\nllamo cola_desencolar\n\n");
cola_desencolar(cola);
cola_encolar(cola,14);
cola_encolar(cola,16);
printf("\nllamo cola_desencolar\n\n");
cola_desencolar(cola);
cola_encolar(cola,16);

printf("\n----\n");
printf("cola:\n");
cola_imprimir(cola);

printf("Finalmente, libero la memoria invertida en cola\n");
cola_destruir(cola);
return 0;
}
