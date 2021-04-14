#include <stdio.h>
#include <stdlib.h>
#include "utn_tp.h"
#include <ctype.h>



int main()
{
	setvbuf (stdout, NULL, _IONBF, 0);
	setvbuf (stderr, NULL, _IONBF, 0);

    int operador[2];
    char salir = 'n';
    char opcion;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorialA = 1;
    int resultadoFactorialB = 1;
    int flagMenu = 1;
    int flagOperandos = 0;
    int flagCalculos = 0;
    int flagResultados = 0;

    do
    {
        system("cls");
        opcion = menu(&opcion, &operador[0], &operador[1], &flagMenu);

       switch(opcion)
        {
        case '1':
        	if(!flagOperandos)
        	{
            printf("1er operando:");
            fflush(stdin);
            scanf("%d", &operador[0]);
            flagMenu = 2;
            flagOperandos = 1;

        	}
        	else
        	{
        		printf("Ya se ingreso el 1er operador, ingrese siguiente operador y continue con las operaciones\n");
        		fflush(stdin);
        		printf("Presione una tecla para continuar...");
        		getchar();
        	}
            break;

        case '2':
            if(flagOperandos)
            {
                printf("2do operando:");
                fflush(stdin);
                scanf("%d", &operador[1]);
                flagMenu = 0;
                flagCalculos = 1;
            }
            else
            {
                printf("Antes debe ingresar 1er operando, ingrese opcion 1\n");
                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getchar();
            }
            break;
        case '3':
            if(flagCalculos)
            {
            resultadoSuma = suma(operador[0], operador[1]);
            resultadoResta = resta(operador[0], operador[1]);
            if(operador[1] != 0)
            {
                resultadoDivision = division(operador[0], operador[1]);
            }
            resultadoMultiplicacion = multiplicacion(operador[0], operador[1]);
            resultadoFactorialA = factorial(operador[0]);
            resultadoFactorialB = factorial(operador[1]);
            flagResultados = 1;
            printf("Se han realizados los calculos\n");
            }
            else
            {
                printf("Antes debe ingresar los operandos, ingrese opcion 1 y 2\n");
            }
            fflush(stdin);
            printf("Presione una tecla para continuar...");
            getchar();
            break;
        case '4':
            if(flagResultados)
            {
            printf("a) El resultado de %d+%d es: %d\n", operador[0], operador[1], resultadoSuma);
            printf("b) El resultado de %d-%d es: %d\n", operador[0], operador[1], resultadoResta);
            if(operador[1] == 0)
            {
                printf("c) No es posible dividir por cero\n ");
            }
            else
            {
                printf("c) El resultado de %d/%d es: %.2f\n", operador[0], operador[1], resultadoDivision);
            }
            printf("d) El resultado de %d*%d es: %d\n", operador[0], operador[1], resultadoMultiplicacion);
            printf("e) El factorial de %d es: %d y el factorial de %d es: %d\n", operador[0], resultadoFactorialA, operador[1], resultadoFactorialB);
            }
            else
            {
                printf("Antes debe ingresar los operandos y realizar los calculos\n");
            }
            fflush(stdin);
            printf("Presione una tecla para continuar...");
            getchar();
            break;
        case '5':
            salir = 's';
            break;

        default:
            printf("No es una opcion valida\n");
            fflush(stdin);
            printf("Presione una tecla para continuar...");
        	getchar();
            break;
        }

    }while(salir == 'n');

    return EXIT_SUCCESS;
}

