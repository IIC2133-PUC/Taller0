#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>


/** Inicializa una lista vacía */
List* list_init()
{
  List* list = malloc(sizeof(List));
  list -> head = NULL;
  list -> tail = NULL;

  return list;
}

/** Inserta un nuevo elemento al final de la lista */
void list_append(List* list, int value)
{
  Node* node = malloc(sizeof(Node));
  node -> value = value;
  node -> next = NULL;

  // Si la lista está vacía entonces queda como el primer elemento
  if(list -> head == NULL)
  {
    list -> head = node;
  }
  // Sino, se pone como el siguiente del ultimo
  else
  {
    list -> tail -> next = node;
  }
  // Luego se deja a este nodo como el último
  list -> tail = node;
}

/** Imprime todos los elementos de la lista */
void list_print(List* list)
{
  for(Node* current = list -> head; current; current = current -> next)
  {
    printf("%i\n", current -> value);
  }
}

/** Libera todos los recursos asociados a esta lista */
void list_destroy(List* list)
{
  // Liberamos los nodos
  if(list -> head)
  {
    Node* curr = list -> head -> next;
    Node* prev = list -> head;

    while(curr)
    {
      free(prev);
      prev = curr;
      curr = curr -> next;
    }
    free(prev);
  }
  // Liberamos la lista en si
  free(list);
}
