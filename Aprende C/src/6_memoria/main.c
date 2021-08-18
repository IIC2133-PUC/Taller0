/*****************************************************************************/
/*                                 Memoria                                   */
/*****************************************************************************/
/*                                                                           */
/* Hablamos anteriormente del STACK de memoria y de sus limitaciones         */
/* Dado que el STACK es limitado, necesitamos acceso a memoria adicional     */
/* Esta memoria existe en lo que se conoce como el HEAP de memoria, y debe   */
/* ser solicitada explicitamente al sistema operativo.                       */
/*****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
// Librería estándar de C, para poder tener acceso al HEAP de memoria
#include <stdlib.h>

int main(int argc, char** argv)
{
  // Imagina que queremos tener un par de arreglos de 10000000 elementos

  // int A[10000000];
  // int B[10000000];
  // int C[10000000];
  // int D[10000000];

  // Estas lineas esta comentadas ya que, desgraciadamente, el STACK no es lo
  // suficientemente grande para crear un arreglo tan grande, ni mucho menos 4
  // Prueba descomentar las lineas si no me crees.

  // Como solucionamos esto? Simple, solicitamos memoria al sistema operativo
  // Para esto usamos la funcion malloc, que recibe como único parámetro
  // LA CANTIDAD DE BYTES que debe tener el bloque de memoria que queremos.
  // La función retorna la direccion de memoria donde comienza este bloque.
  // Perfecto para un arreglo (y como veremos despues, para inicializar objetos)

  int* E = malloc(10000000 * sizeof(int));
  int* F = malloc(10000000 * sizeof(int));
  int* G = malloc(10000000 * sizeof(int));
  int* H = malloc(10000000 * sizeof(int));

  // Donde está esta memoria? Cada bloque puede estar en un lugar completamente
  // distinto: revisa la guía "Memoria.pdf" que hay en esta carpeta para ver
  // el diagrama. Todos los bloques de memoria solicitados de esta manera se
  // conocen colectivamente como el HEAP de memoria.

  // MUY IMPORTANTE: el sistema operativo registra el puntero que te entrega
  // y lo marca en una tabla como que está en uso. Cuando termines de usar esta
  // memoria debes devolverla al sistema operativo: si tu programa termina
  // sin devolver la memoria esta memoria se queda marcada como ocupada hasta
  // que apagues el computador. Esto se conoce como MEMORY LEAK y es la razón
  // por la que algunos programas hacen lento el computador luego de llevar
  // mucho rato corriendo, incluso aplicaciones web como facebook.

  // Para devolver esta memoria simplemente tienes que usar la función "free"

  free(E);
  free(F);
  free(G);
  free(H);

  // La función malloc y free son parte de un grupo de funciones que interactuan
  // con el sistema operativo, conocidas como "llamadas al sistema" o SYSCALLS.
  // Las SYSCALLS detienen la ejecución de tu programa para esperar a la
  // respuesta del sistema operativo, por lo que pedir muchas veces un poco
  // de memoria va a ser mas lento que pedir de una vez un gran bloque.
  // Si en una funcion necesitas un poco de memoria, y luego deberás devolverla,
  // o necesitas una variable temporal, utiliza el STACK, que es mucho más
  // rapido ya que no requiere de la interacción con el sistema operativo.

  // Ahora la pregunta importante... que pasa si no queda memoria disponible?
  int* I = malloc(1000000000000000 * sizeof(int));

  // Recuerda que este bloque es de memoria adyacente, por lo que mientras más
  // grande es, menos probable va a ser que esté disponible.

  // Malloc retorna el puntero nulo si falla.
  if(I == NULL)
  {
    printf("Malloc falló\n");
  }

  // Como habiamos hablado, en C el 0 es falsoso y TODO LO DEMAS ES TRUE.
  // Da la casualidad de que NULL == 0. Por lo que podemos hacer esto:

  if(I)
  {
    printf("Malloc funcionó\n");
    free(I);
  }

  // Trabajar con el HEAP de memoria tiene otras ventajas.
  // Recuerdas que salirse de un arreglo en el stack no daba problemas?
  // Existe una aplicación capaz de monitorear toda la actividad del HEAP, la
  // cual es capaz de detectar errores como este (además de LEAKS).
  // Esta aplicación es VALGRIND y será nuestra principal herramienta para
  // encontrar errores causados por mal uso de memoria.

  // Por ejemplo, creemos un arreglo de 10 elementos:
  int* J = malloc(10 * sizeof(int));

  // Si nos pasamos, el programa se PUEDE caer, pero valgrind nos va a avisar:
  // Esto es un ERROR DE MEMORIA
  // (INVALID WRITE) -> y dice el archivo, stack de llamadas, funcion y linea.
  J[10] = 1;
  // (INVALID READ) -> y dice el archivo, stack de llamadas, funcion y linea.
  J[4] = J[10];
  // (USE OF UNINITIALIZED VALUE) -> y dice el archivo, stack de llamadas, funcion y linea.
  printf("%i\n", J[3]);

  // Prueba ejecutar el programa con valgrind:
  // valgrind ./6_memoria

  // Prueba tu programa con valgrind luego de cada cambio, y asegurate de no
  // tener errores de memoria en ningun momento. Así a la hora de debugear
  // vas a tener que preocuparte unicamente de la lógica de tu programa,
  // y no de cambios extraños debido a mal uso de memoria.
  // Asegurate que el ERROR SUMMARY diga 0. Ojo que si tienes un error en una
  // función, y la llamas 1000 veces, valgrind dirá 1000 errores en 1 contexto.

  // OJO: valgrind sólo es capaz de detectar errores en el uso del HEAP,
  // si tus errores están en el STACK no los detectará. (Por lo que se
  // recomienda usar el HEAP siempre que sea posible.)

  // Si el programa no devuelve la memoria al final, tendremos leaks.
  // Asegurate de que en LEAK SUMMARY todos los items sean 0.
  // De ser así, aparecera "All heap blocks were freed -- no leaks are possible"
  // Para identificar de donde vienen los leaks, utiliza las flags que aparecen
  // abajo:
  // valgrind --leak-check=full ./6_memoria

  return 0;
}
