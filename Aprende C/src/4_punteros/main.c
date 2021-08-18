/*****************************************************************************/
/*                                 Punteros                                  */
/*****************************************************************************/
/*                                                                           */
/* Hacemos un pequeño parentesis para hablar de punteros en más detalle      */
/*****************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv)
{
  // Sea "a" una VARIABLE cualquiera de un tipo cualquiera
  int a = 7;
  printf("a = %i\n", a);
  // Podemos obtener su posición en memoria con el operador & como vimos antes
  printf("&a = a está en %p\n", &a);

  // Ahora, esa dirección de memoria se puede guardar a su vez en una variable
  int* x = &a;
  // x es un PUNTERO. Es una direccion de memoria que corresponde a otra variable
  // El tipo es int* porque si queremos leer lo que hay en la posicion x
  // debemos conocer el tipo de lo que hay guardado ahi para interpretarlo correctamente

  // Podemos imprimir x
  printf("x = &a = %p\n", x);
  // Y podemos leer lo que hay en x usando el operador *
  printf("*x = x apunta a un %i\n", *x);
  // No solo eso. Podemos modificar el valor que hay en a a traves de x
  *x *= 2;
  printf("Luego de *x *= 2;\n\t*x = x apunta a un %i\n", *x);
  // *x es equivalente a referirnos directamente a "a". Esto significa que
  printf("&(*x) = %p\n", &(*x));

  // El operador * es el opuesto del operador &
  // &v = obtener la direccion de memoria de v. Sólo es válido si v es una
  // VARIABLE.
  // *p = ACCEDER a la variable guardada en esa direccion de memoria. Sólo es
  // válido si p es una direccion de memoria.
  // Por lo tanto *(&v) = v, y &(*p) = p

  // x también es una variable. Por lo tanto tiene una posición en memoria
  printf("&x = x está en %p\n", &x);
  // Y a su vez podemos guardarla en otra variable, otro puntero.
  int** y = &x;
  // No hay limite para cuantos asteriscos puede tener un puntero:
  // Lo importante es recordar que si X es un puntero que apunta a una variable
  // de tipo T, entonces el tipo de X es T*. Por lo tanto el tipo de
  // *(T{n asteriscos}) = T{n-1 asteriscos}.

  // Podemos tambien leer a "a" desde y
  printf("*(*y) = y apunta a x que apunta a un %i\n", *(*y));
  // Y por lo tanto modificarla!
  *(*y) -= 2;
  printf("Luego de *(*y) -= 2;\n\t*(*y) = y apunta a x que apunta a un %i\n", *(*y));

  // Ojo que no es válido repetir el operador & tal como hacemos aqui con el *
  // para una varaible v, &(&v) no es valido, ya que &v NO ES UNA VARIABLE.

  ////////////////////////////////////////////////////////////////////////////

  // Todos los lenguajes de programación trabajan con punteros por detrás,
  // de ahi sale el concepto de "paso por referencia" vs "paso por valor" de
  // los parametros de funciones: todo lo que se pasa por referencia en realidad
  // está pasando un puntero. Es por eso que al imprimir un objeto en python
  // directamente imprime su direccion de memoria: ese objeto ES un puntero.

  // En C todos los pasos de parámetros son por valor, por lo que si queremos
  // hacer una funcion que modifique un objeto que recibe como parametro,
  // es necesario usar punteros.

  // Para este curso nos interesa que entiendan bien las conexiones entre las
  // distintas componentes de una estructura de datos (como en la lista ligada)
  // Por eso es importante que manejen explicitamente estas referencias.
  // Esto permite escribir programas más eficientes y a su vez entender
  // como funcionan las estructuras de datos por debajo, sea cual sea el lenguaje
  // que vayan a usar.

  return 0;
}
