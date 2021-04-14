/*
 * utn_tp.c
 *
 *  Created on: 10 abr. 2021
 *      Author: Fernando
 */
#include "utn_tp.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char menu(char* opcion, int* x, int* y, int* bandera)
{
    if(*bandera == 1)
    {
    	printf("    *** MENU DE OPCIONES ***\n\n");
        printf("1. Ingresar 1er operando (A=x)\n");
        printf("2. Ingresar 2do operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n");
        printf("   a) Calcular la suma (x+y)\n");
        printf("   b) Calcular la resta (x-y)\n");
        printf("   c) Calcular la division (x/y)\n");
        printf("   d) Calcular la multiplicacion (x*y)\n");
        printf("   e) Calcular la factorial (x!, y!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("\nIngrese opcion: ");
    	fflush(stdin);
        *opcion = getchar();
    }
    else if(*bandera == 2)
    {
    	printf("    *** MENU DE OPCIONES ***\n\n");
    	        printf("1. Ingresar 1er operando (A=%d)\n", *x);
    	        printf("2. Ingresar 2do operando (B=y)\n");
    	        printf("3. Calcular todas las operaciones\n");
    	        printf("   a) Calcular la suma (%d +y)\n", *x);
    	        printf("   b) Calcular la resta (%d -y)\n", *x);
    	        printf("   c) Calcular la division (%d /y)\n", *x);
    	        printf("   d) Calcular la multiplicacion (%d *y)\n", *x);
    	        printf("   e) Calcular la factorial (%d! , y!)\n", *x);
    	        printf("4. Informar resultados\n");
    	        printf("5. Salir\n");
    	        printf("\nIngrese opcion: ");
    	        fflush(stdin);
    	        *opcion = getchar();
    }
    else
    {
    	printf("    *** MENU DE OPCIONES ***\n\n");
        printf("1. Ingresar 1er operando (A=%d)\n", *x);
        printf("2. Ingresar 2do operando (B=%d)\n", *y);
        printf("3. Calcular todas las operaciones\n");
        printf("   a) Calcular la suma (%d+%d)\n", *x, *y);
        printf("   b) Calcular la resta (%d-%d)\n", *x, *y);
        printf("   c) Calcular la division (%d/%d)\n", *x, *y);
        printf("   d) Calcular la multiplicacion (%d*%d)\n", *x, *y);
        printf("   e) Calcular la factorial (%d!, %d)\n", *x, *y);
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        *opcion = getchar();
    }
    return *opcion;
}
int suma(int a, int b)
{
    int suma;

    suma = a + b;

    return suma;
}

int resta(int a, int b)
{
    int resta;

    resta = a - b;

    return resta;
}

float division(int a, int b)
{
    float division;

    division = (float) a / b;

    return division;

}
int multiplicacion(int a, int b)
{
    int multiplicacion;

    multiplicacion = a * b;

    return multiplicacion;
}
int factorial(int a)
{
    int factorizacion = 1;

    for(int i = 1; a >= i; a--)
    {
        factorizacion *= a;
    }

    return factorizacion;
}

