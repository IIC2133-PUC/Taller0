/*****************************************************************************/
/*                                 Matrices                                  */
/*****************************************************************************/
/*                                                                           */
/* Una matriz de dos dimensiones donde cada celda es de tipo int.            */
/*****************************************************************************/

// Indica que este archivo solo se debe incluir una vez en la compilación
#pragma once

// Declaramos el struct para la matriz
struct matrix;
// Definimos un alias para el struct matriz.
// La sintaxis es "typedef tipo alias"
typedef struct matrix Matrix;

// Definimos el struct matriz
struct matrix
{
  /** La matriz en si: un arreglo de arreglos */
  int** matrix;
  /** El alto de la matriz */
  int height;
  /** El ancho de la matriz */
  int width;
};

// Declaramos las funciones asociadas

/** Inicializa una matriz aleatoria con las dimensiones especificadas */
Matrix* matrix_init(int height, int width);
/** Entrega una nueva matriz que corresponde a la traspuesta de la original */
Matrix* matrix_transpose(Matrix* original);
/** Imprime la matriz en consola */
void matrix_print(Matrix* mat);
/** Libera los recursos asociados a esta matriz */
void matrix_destroy(Matrix* mat);
