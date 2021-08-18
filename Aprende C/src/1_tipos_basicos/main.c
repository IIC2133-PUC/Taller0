/*****************************************************************************/
/*                                  Tipos                                    */
/*****************************************************************************/
/*                                                                           */
/* En clases vimos que cada variable tiene:                                  */
/*   - Posición en memoria                                                   */
/*   - Tamaño en bytes                                                       */
/*   - Valor                                                                 */
/*                                                                           */
/* C es un lenguaje fuertemente tipificado. Esto significa que las variables */
/* tienen un TIPO, el cual debe ser especificado y no puede cambiar          */
/*                                                                           */
/* Un TIPO tiene dos características: tamaño en bytes y representación. La   */
/* representación indica como deben ser interpretados los datos en memoria.  */
/*****************************************************************************/

#include <stdio.h>

int main(int argc, char** argv)
{
  // x es una variable de tipo int (numero entero)
  int x = 1287;

  // Lo imprimimos interpretandolo como si fuera un int
  printf("X = %i\n", x);

  // Imprimimos cual es el tamaño de un int en bytes
  printf("Size of INT: %zu\n", sizeof(int));

  /////////////////////////////////////////////////////////////////////////////

  // y es una variable de tipo char (caracter). Las comillas son simples
  char y = 'h';

  // Lo imprimimos interpretandolo como si fuera un char
  printf("Y = %c\n", y);

  // Imprimimos cual es el tamaño de un int en bytes
  printf("Size of CHAR: %zu\n", sizeof(char));

  /////////////////////////////////////////////////////////////////////////////

  // z es una variable de tipo float (numero real en formato de punto flotante)
  float z = 2.72181;

  // Lo imprimimos interpretandolo como si fuera un float
  printf("Z = %f\n", z);

  // Imprimimos cual es el tamaño de un int en bytes
  printf("Size of FLOAT: %zu\n", sizeof(float));

  // Tambien existe el double, que es un float con el doble de precisión
  double z2 = 122189.128391;

  // %lf = long float
  printf("Z2 = %lf\n", z2);

  // Imprimimos cual es el tamaño de un int en bytes
  printf("Size of DOUBLE: %zu\n", sizeof(double));

  /////////////////////////////////////////////////////////////////////////////

  // Una variable en el computador es simplemente una secuecia de 0s y 1s

  // Los tipos nos dicen como interpretar eso.

  // Veamos que pasa si tomamos una variable y la interpretamos
  // (incorrectamente) como si fuera de otro tipo

  printf("Z = 2.721810 interpretado como int: %i\n", z);

  // Nótese que interpretar char como un numero entero es perfectamente legal

  printf("Y = 'h' interpretado como int: %i\n", y);

  // Incluso podemos asignarle valores numéricos:

  y = 105;

  printf("Y = 105 interpretado como int: %i\n", y);
  printf("Y = 105 interpretado como char: %c\n", y);

  // Y operar sobre el como si fuera un número

  y = y - 1;
  printf("Y = 104 interpretado como char: %c\n", y);

  /////////////////////////////////////////////////////////////////////////////

  // OJO: Las división de dos numeros enteros entrega como resultado un numero entero

  double r = 5 / 3;

  printf("5 / 3 = %lf\n", r);

  // Si necesitamos interpretar correctamente un valor de un tipo como otro debemos usar CASTING

  r = (double) 5 / (double) 3;

  printf("5 / 3 con casting = %lf\n", r);

  // Basta con que uno de los dos sea double para que la operacion sea correcta

  r = (double) 5 / 3;

  printf("5 / 3 con un solo cast = %lf\n", r);

  return 0;
}
