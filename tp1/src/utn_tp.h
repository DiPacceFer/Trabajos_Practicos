/*
 * utn_tp.h
 *
 *  Created on: 10 abr. 2021
 *      Author: Fernando
 */

#ifndef UTN_TP_H_
#define UTN_TP_H_



#endif /* UTN_TP_H_ */

/** \brief toma dos enteros y los suma devolviendo la solucion
 *
 * \param a int primer valor a sumar
 * \param b int segundo valor a sumar
 * \return int solucion de la suma
 *
 */
int suma(int a, int b);
/** \brief toma dos enteros y los resta
 *
 * \param a int primer valor a restar
 * \param b int valor que resta
 * \return int solucion de la resta
 *
 */
int resta(int a, int b);
/** \brief toma dos enteros y devuelve la solucion de la division con un valor flotante
 *
 * \param a int dividendo de la division
 * \param b int divisor
 * \return float cociente
 *
 */
float division(int a, int b);
/** \brief toma dos numeros enteros y los multiplica devolviendo un entero
 *
 * \param a int primer factor a multiplicar
 * \param b int segundo factor
 * \return int producto de la multiplicacion
 *
 */
int multiplicacion(int a, int b);
/** \brief toma un numero entero y realiza su factorial
 *
 * \param a int numero a factorizar
 * \return int solucion del factorial
 *
 */
int factorial(int a);
/** \brief muestra un menu de opciones y pide que se seleccione una
 *
 * \param opcion char* la variable donde se va a pasar la seleccion del usuario
 * \param x int* primera de las variables que se van a ir actualizando dentro del menu
 * \param y int* segunda de las variables que se van a ir actualizando dentro del menu
 * \return char la opcion seleccionada por el usuario
 *
 */
char menu(char* opcion, int* x, int* y, int* bandera);

