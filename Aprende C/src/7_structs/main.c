/*****************************************************************************/
/*                                 Structs                                   */
/*****************************************************************************/
/*                                                                           */
/* En C podemos definir nuestros propios tipos de datos, parecidos a las     */
/* clases, llamados Struct. La unica diferencia que tienen con las clases    */
/* es el hecho de que no tienen funciones, por lo que cualquier operación    */
/* que queramos hacer con ellos requerirá que los pasemos como parámetro.    */
/* Esto último es similar al self de python (porque de aquí viene)           */
/*                                                                           */
/* Para organizarnos, definimos los structs y declaramos las funciones       */
/* externas en un archivo llamado header .h, mientras que en un archivo .c   */
/* aparte escribimos el codigo de esas funciones y funciones internas.       */
/* El .h es la cara visible de tu struct, como si fuera una librería.        */
/* Es lo primero que la gente va a leer si quiere utilizar la estructura     */
/* que definiste, sin tener que ponerse a leer el código de las funciones    */
/* Revisa los archivos .h y .c que están junto a este para tener un ejemplo. */
/*                                                                           */
/* Como aclaración:                                                          */
/* Si S es un struct en STACK que tiene los elementos a y b, podemos acceder */
/* a ellos usando S.a y S.b. En cambio si P es un puntero a un struct de ese */
/* mismo tipo, se accede a los elementos con P -> a y P -> b                 */
/*****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
// Importamos la matriz
#include "matrix.h"
// Importamos la lista ligada
#include "linked_list.h"

void matrix_test(int height, int width)
{
  // REVISA MATRIX.H Y MATRIX.C
  Matrix* mat = matrix_init(height, width);

  printf("La matriz vale:\n");

  matrix_print(mat);

  Matrix* trans = matrix_transpose(mat);

  printf("La transpuesta vale:\n");

  matrix_print(trans);

  // Liberamos ambas matrices
  matrix_destroy(mat);
  matrix_destroy(trans);
}

void list_test(int n)
{
  // REVISA LINKED_LIST.H Y LINKED_LIST.C
  List* list = list_init();


  for(int i = 1; i <= n; i++)
  {
    list_append(list, i*i);
  }

  printf("La lista con los numeros al cuadrado contiene:\n");

  list_print(list);

  list_destroy(list);
}

int main(int argc, char** argv)
{
  matrix_test(4, 3);

  list_test(10);

  return 0;
}
