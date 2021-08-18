/*****************************************************************************/
/*                              Lista Ligada                                 */
/*****************************************************************************/
/*                                                                           */
/* Lista simplemente ligada para guardar datos de tipo int. Cada nodo tiene  */
/* un puntero al nodo siguiente en la lista. La estructura principal tiene   */
/* un puntero al primer y ultimo elemento de la lista.                       */
/*****************************************************************************/

// Indica que este archivo solo se debe incluir una vez en la compilación
#pragma once

// Declaramos el struct para un nodo de la lista
struct linked_list_node;
// Definimos un alias para el struct nodo.
// La sintaxis es "typedef tipo alias"
typedef struct linked_list_node Node;

// Definimos el struct nodo
struct linked_list_node
{
  /** El valor que guarda el nodo */
  int value;
  /** Un puntero al siguiente nodo de la lista */
  Node* next;
};

// Declaramos el struct para la lista
struct linked_list;
// Definimos un alias para el struct lista
typedef struct linked_list List;

// Definimos el struct lista
struct linked_list
{
  /** El primer nodo de la lista */
  Node* head;
  /** El último nodo de la lista */
  Node* tail;
};

// Declaramos las funciones asociadas

/** Inicializa una lista vacía */
List* list_init();
/** Inserta un nuevo elemento al final de la lista */
void list_append(List* list, int value);
/** Imprime todos los elementos de la lista */
void list_print(List* list);
/** Libera todos los recursos asociados a esta lista */
void list_destroy(List* list);
