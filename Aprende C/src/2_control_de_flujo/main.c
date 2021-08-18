/*****************************************************************************/
/*                                  Flujo                                    */
/*****************************************************************************/
/*                                                                           */
/* C provee las herramientas de control de flujo estándares:                 */
/*   - if, else if, else                                                     */
/*   - while                                                                 */
/*   - for                                                                   */
/*                                                                           */
/* Estas tambien son estandares pero son menos importantes:                  */
/*   - do while                                                              */
/*   - switch                                                                */
/*****************************************************************************/

#include <stdio.h>
// Importamos el módulo estandar para valores de verdad (bool)
#include <stdbool.h>

int main(int argc, char** argv)
{
  // Prueba modificar los valores de x e y
  int x = 3;
  int y = 5;

  if (x < y)
  {
    printf("X < Y\n");
  }
  else if (x == y)
  {
    printf("X = Y\n");
  }
  else
  {
    printf("X > Y\n");
  }

  /////////////////////////////////////////////////////////////////////////////

  // En C existe el concepto de valores falsosos y verdadosos
  // Falsosos: el 0.
  // Verdadosos: TODO LO DEMAS

  int c = 1;
  while (38)
  {
    printf("C = %i\n", c);
    // Incrementamos C en 1
    c++;

    if(c > 10)
    {
      break;
    }
  }

  // Para hacer esto más legible usamos bools (ver linea 16)

  while (true)
  {
    printf("C = %i\n", c);
    c++;

    if(c > 15)
    {
      break;
    }
  }

  /////////////////////////////////////////////////////////////////////////////

  // El FOR en C tiene la siguiente sintaxis: for(A; B; C) { }
  // A es una (o varias, separadas por comas) instrucciones que se ejecutan antes de entrar al for
  // B es la condición de término, un valor booleano. Mientras sea true el for sigue
  // C es una (o varias, separadas por comas) instrucciones que se ejecutan despues de cada iteracion

  printf("i++\n");
  for(int i = 1; i <= 10; i++)
  {
    printf("\ti = %i\n", i);
  }

  printf("i+=2\n");
  for(int i = 1; i <= 10; i+=2)
  {
    printf("\ti = %i\n", i);
  }

  printf("i*=2\n");
  for(int i = 1; i <= 10; i*=2)
  {
    printf("\ti = %i\n", i);
  }

  /////////////////////////////////////////////////////////////////////////////

  // Los valores de verdad permiten operaciones logicas como AND y OR:

  // Prueba cambiar estos valores
  bool a = true;
  bool b = false;

  if(a || b)
  {
    printf("A o B = TRUE\n");
  }
  else
  {
    printf("A o B = FALSE\n");
  }

  if(a && b)
  {
    printf("A y B = TRUE\n");
  }
  else
  {
    printf("A y B = FALSE\n");
  }

  return 0;
}
