/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"


int main(void) {

	setvbuf (stdout, NULL, _IONBF, 0);
	setvbuf (stderr, NULL, _IONBF, 0);


	Employee nomina[1000];
	char salir='n';
	char name[51];
	char lastName[51];
	float salary;
	int id=20000;
	int sector;
	int sistemaDeOrdenamiento;
	initEmployees(nomina, 1000);


	do
	{
		switch(menu() )
		{
		case 1:
			 printf("   Alta empleado\n\n");
			 printf("Ingrese nombre: ");
			 fflush(stdin);
			 gets(name);
			 while(strlen(name) > 50 || strlen(name)< 1)
			 {
					printf("Error. Ingrese nombre: ");
					fflush(stdin);
					gets(name);
			 }

			 printf("Ingrese apellido: ");
			 fflush(stdin);
			 gets(lastName);
			 while(strlen(lastName) > 50 || strlen(lastName)< 1)
			 {
				 printf("Error. Ingrese apellido: ");
				 fflush(stdin);
				 gets(lastName);
			 }

			 printf("Ingrese sueldo: ");
			 scanf("%f", &salary);

			 printf("Ingrese id del sector: ");
			 scanf("%d", &sector);

			addEmployee(nomina, 1000, id, name, lastName, salary, sector);
			 id++;
			system("pause");
			break;
		case 2:
			printf("    MODIFICACION DE DATOS DE EMPLEADOS\n\n");
			printf("Ingrese numero de legajo: ");
			scanf("%d", &id);

			modifyEmployee(nomina, 1000, id);
			system("pause");
			break;
		case 3:
			 printf("     BAJA DE EMPLEADOS\n\n");
			 printf("Ingrese numero de legajo: ");
			 scanf("%d", &id);

			 removeEmployee(nomina, 1000, id);
			 system("pause");
			 break;
		case 4:
			printf("Indique orden ascendente con 1 o descendente con 0: ");
			scanf("%d", &sistemaDeOrdenamiento);
			while(sistemaDeOrdenamiento != 0 || sistemaDeOrdenamiento != 1)
			{
				printf("Error. Indique orden ascendente con 1 o descendente con 0: ");
				scanf("%d", &sistemaDeOrdenamiento);
			}
			sortEmployees(nomina, 1000, sistemaDeOrdenamiento);
			printEmployees(nomina, 1000);
			break;

		case 5:
			salir = 's';
			break;
		}

	}while(salir == 'n');


	return EXIT_SUCCESS;
}
