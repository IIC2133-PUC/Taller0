/*****************************************************************************/
/*                                 Arreglos                                  */
/*****************************************************************************/
/*                                                                           */
/* En clases vimos que los arreglos son la más básica de las estructuras o,  */
/* más bien, maneras de agrupar un conjunto de datos.                        */
/*                                                                           */
/* En particular, se mencionó lo siguiente:                                  */
/*      - Los arreglos son un conjunto de celdas del mismo tamaño            */
/*      - Estas celdas están ADYACENTES en memoria                           */
/*      - El tamaño de un arreglo es fijo                                    */
/*      - Todo esto permite acceso a los elementos de un arreglo en O(1)     */
/*                                                                           */
/* Ahora hablaremos de como funciona todo esto en C y como se relaciona con  */
/* los punteros.                                                             */
/*****************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv)
{
  // En primer lugar, se dijo que las celdas de un arreglo son del mismo tamaño
  // Para C esto significa que todos los elementos de un arreglo son del mismo
  // TIPO.

  // La sintaxis para declarar un arreglo A de N celdas del tipo T es:
  // T A[n];
  // Por ejemplo si T = int, y n = 6:

  // Declarado el arreglo
  int A[6];

  // Podemos imprimir sus elementos
  for(int i = 0; i < 6; i++)
  {
    // Ojo que no hay manera de, dado A, obtener su largo. Tu como programador
    // deberas asegurarte de pasarlo junto con el arreglo si quieres recorrerlo
    printf("A[%i] = %i\n", i, A[i]);
  }

  printf("OJO que no se va a caer si te sales del arreglo!\n");

  for(int i = -1; i <= 6; i++)
  {
    printf("A[%i] = %i\n", i, A[i]);
  }

  // Estos valores que aparecen en consola son lo que sea que haya habido en
  // ese espacio de memoria al declarar el arreglo, ya que no los hemos asignado

  printf("Esos valores vienen sin inicializar. Ahora dandole un valor:\n");

  for(int i = 0; i < 6; i++)
  {
    A[i] = i*i;
    printf("A[%i] = %i\n", i, A[i]);
  }

  // Tambien es posible darle valores iniciales al arreglo al crearlo.
  int B[6] = {4, 8, 15, 16, 23, 42};

  printf("Ahora con un arreglo que trae valores iniciales\n");

  for(int i = 0; i < 6; i++)
  {
    printf("B[%i] = %i\n", i, B[i]);
  }

  // Habiamos dicho que las celdas de un arreglo están adyacentes en memoria
  // Comprobemoslo:

  for(int i = 0; i < 6; i++)
  {
    printf("&B[%i] = %p\n", i, &B[i]);
  }

  // Podemos ver que la diferencia entre cada uno es de 4 bytes.
  // Y eso es justmente el tamaño de un int.

  printf("La diferencia entre las posiciones de cada elemento es de %zu\n", sizeof(int));

  // La pregunta que queda por hacerse es... que es B realmente?
  // La respuesta es: la direccion de memoria al primer elemento
  printf("B = %p\n", B);

  // Es decir, todo este tiempo los arreglos eran punteros?
  int* pB = B;

  printf("Ahora si interpretamos B como un puntero, pB\n");

  for(int i = 0; i < 6; i++)
  {
    printf("pB[%i] = %i\n", i, pB[i]);
  }

  // Pero por qué sería valido usar los corchetes para acceder al iésimo elemento
  // de...un puntero?!
  // La respuesta está en el significado del operador A[i]

  // Sea A un arreglo de elementos de tipo T.
  // A[i] = *(A + i * sizeof(T))

  // Hay un detalle si, si haces A + i el compilador le pone automáticamente el
  // * sizeof(T) al i ya que conoce el tipo, y asume que simplemente quieres
  // avanzar en memoria "i" celdas. Comprobémoslo.

  printf("*(pB + 3) = pB[3] = %i\n", *(pB + 3));

  // En la practica no recomiendo sumar ni restar cosas a los punteros ya que
  // si tienes un bug es mucho más dificil encontrarlo, este ejemplo es para
  // ilustrar lo que está pasando por detrás.

  // Y si, eso significa que para un puntero cualquiera, *p = p[0]

  // Esto es lo que nos permite acceder a los elementos de un arreglo en O(1)
  // ya que consiste simplemente de una suma seguida de un acceso a esa
  // dirección de memoria. Y es por esto que es tan importante que las celdas
  // sean adyacentes en memoria. El arreglo es de largo fijo ya que al definirlo
  // el compilador debe buscar el grupo de celdas adyacentes, y no hay garantia
  // de que las siguientes esten disponibles para hacer crecer el arreglo.

  // Esto significa que los punteros no solo apuntan a variables...
  // Al final del día, un puntero es una direccion de memoria, la direccion
  // de memoria de un BLOQUE de memoria. Este bloque puede ser usado para
  // guardar una sola variable (un arreglo de largo 1), o múltiples variables
  // del mismo tipo, (un arreglo). Cual de los dos es es algo que el programador
  // debe tener claro, y nuevamente, el tipo de los elementos del arreglo va
  // en el puntero seguido de un asterisco.

  // En particular, int** puede ser:
  // - Un puntero a un puntero a un int
  // - Un arreglo de punteros a int
  // - Un puntero a un arreglo de int
  // - Un arreglo de arreglos de int (una matriz)

  return 0;
}
