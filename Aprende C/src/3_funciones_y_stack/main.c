/*****************************************************************************/
/*                                 Funciones                                 */
/*****************************************************************************/
/*                                                                           */
/* El compilador de C lee el archivo de arriba hacia abajo, por lo que solo  */
/* se pueden llamar funciones que se sabe que existen, es decir que fueron   */
/* DECLARADAS anteriormente.                                                 */
/*                                                                           */
/* Hacemos la distinción entre DECLARAR y DEFINIR una función:               */
/*                                                                           */
/* DECLARAR:                                                                 */
/*    int funcion(int parametro);                                            */
/*                                                                           */
/* Esto sirve solo para que el compilador identifique que efectivamente      */
/* existe una funcion con ese nombre, tipo de retorno y tipos de parámetros  */
/* y te permita utilizarla.                                                  */
/*                                                                           */
/* DEFINIR:                                                                  */
/*    int funcion(int parametro)                                             */
/*    {                                                                      */
/*        // El código de la función                                         */
/*    }                                                                      */
/*                                                                           */
/* DEFINIR una función tambien la DECLARA. El concepto de DEFINIR y DECLARAR */
/* aplica tambien para variables y definiciones de tipos.                    */
/*                                                                           */
/* La definición de algo no necesariamente está en el mismo archivo          */
/* que su declaración. Ya vamos a ver por que esto es util para organizarnos */
/*                                                                           */
/* Este archivo tiene un par de experimentos que se caen intencionalmente,   */
/* asegurate de seguir las instrucciones para entender lo que esta pasando   */
/*                                                                           */
/* La guia Memoria.pdf explica como funciona el STACK en la segunda página   */
/*****************************************************************************/

/** Una funcion totalmente normal que recibe dos ints y entrega su suma */
int sumar(int a, int b)
{
  return a + b;
}

// void significa que no retorna nada
void funcion_para_ver_direccion_uno(int a);
void funcion_para_ver_direccion_dos(int a);

void funcion_recursiva_infinita(int depth);

#include <stdio.h>

int main(int argc, char** argv)
{
  // En primer lugar, vamos a hablar de la posicion en memoria de las variables
  int x = 7;

  // Esta se obtiene con el operador "&" (Ampersand / "Y" / "AND")
  printf("X está en %p\n", &x);
  // Las direcciones de memoria son numeros muy grande por lo que para
  // aprovechar espacio se escriben en HEXADECIMAL (buscalo en google)

  // Donde estan en memoria las variables que existen dentro de las funciones?
  funcion_para_ver_direccion_uno(7);
  funcion_para_ver_direccion_dos(3);

  // Esto pasa por que a medida que llamamos funciones se van creando las
  // variables haciendo crecer el STACK de memoria. Al salir de una funcion se marca
  // esas memoria como disponible y el STACK se achica. Ver guia de Memoria.pdf

  // TODAS LAS VARIABLES CREADAS DENTRO DE UNA FUNCION VIVEN EN EL STACK
  // ESTO INCLUYE LAS VARIABLES CREADAS EN EL MAIN

  // Esto queda ilustrado al hacer STACK OVERFLOW: el STACK llega a su limite:

  // DESCOMENTA LA SIGUIENTE LINEA Y ANOTA HASTA QUE PROFUNDIDAD LLEGA
  // funcion_recursiva_infinita(0);

  // Ahora, si declaramos un arreglo de 1000000 elementos en el STACK...
  // (recuerda que un arreglo es un gran bloque de celdas consecutivas en memoria)

  int A[1000000];

  // DESCOMENTA LA SIGUIENTE LINEA Y ANOTA HASTA QUE PROFUNDIDAD LLEGA
  // funcion_recursiva_infinita(0);

  // Como veras, llega a menos profundidad, lo cual tiene sentido, ya que
  // con la memoria que usa el arreglo el STACK tiene menos espacio para crecer

  // Esto significa que hacer una recursión infinita no es la unica forma
  // de hacer stack overflow... es posible hacerlo simplemente creando variables

  return 0;
}

void funcion_para_ver_direccion_uno(int a)
{
  printf("El parámetro de F1 está en %p\n", &a);
  int b = a + 1;
  printf("La variable creada dentro de F1 está en %p\n", &b);

}

void funcion_para_ver_direccion_dos(int a)
{
  printf("El parámetro de F2 está en %p\n", &a);
  int b = a + 2;
  printf("La variable creada dentro de F2 está en %p\n", &b);
  printf("Si llamamos F1 dentro de F2 entonces...\n");
  funcion_para_ver_direccion_uno(a);
}

void funcion_recursiva_infinita(int depth)
{
  if (depth >= 0)
  {
    printf("Profundidad: %i\n", depth);
    funcion_recursiva_infinita(depth + 1);
  }
}
