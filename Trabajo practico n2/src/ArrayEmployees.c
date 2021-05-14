/*
 * ArrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: Fernando
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)
{
	int isOk= -1;

	if(list != NULL && len > 0)
	{
		 for(int i=0; i<len; i++)
		    {
		        list[i].isEmpty = 1;
		    }
		isOk = 0;
	}
	return isOk;
}
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int isOk=-1;

		if(list != NULL && len>0 && len <= 1000)
		{
			   for(int i=0;i<len;i++)
			   {

			    if(list[i].isEmpty)
			    {
			    	strcpy(list[i].name, name);
			    	strcpy(list[i].lastName, lastName);
			    	list[i].id = id;
			    	list[i].salary = salary;
			    	list[i].sector = sector;
			    	list[i].isEmpty = 0;
			        isOk=0;
			        break;
			    }
			   }
		}
	return isOk;
}
int findEmployeeById(Employee* list, int len,int id)
{
	int index=-1;

	if(list != NULL && len>0 && len <= 1000 && id >0)
	{
	    for(int i=0;i<len;i++)
	    {
	        if(list[i].id == id && !list[i].isEmpty)
	        {
	            index=i;
	            break;
	        }
	    }
	}
	return index;
}
int removeEmployee(Employee* list, int len, int id)
{
		int isOk=-1;
	    int indice=-1;
	    char confirmacion = 'n';

	    if(list != NULL && len > 0 && len <= 1000 && id >= 0)
	    indice = findEmployeeById(list, len, id);
	    if(indice == -1)
	    {
	        printf("No se encontro legajo\n");
	    }
	    else
	    {
	        printf("Confirma baja? s/n:  ");
	        fflush(stdin);
	        scanf("%c", &confirmacion);
	        if(confirmacion == 's')
	        {
	            list[indice].isEmpty = 1;
	            isOk=0;
	        }
	        else
	        {
	            printf("Baja cancelada por el usuario\n");
	        }
	    }

	return isOk;
}
int sortEmployees(Employee* list, int len, int order)
{
	Employee auxEmpleado;
	int isOk=-1;
	if(list != NULL && len > 0 && len <= 1000 && !isalpha(order))
	{
	if(order == 1)
	{
	for(int i=0;i<len-1;i++)
	    {
	        for(int j=i+1;j<len;j++)
	        {
	            if((strcmp(list[i].lastName, list[j].lastName) == 1) ||
	            (strcmp(list[i].lastName, list[j].lastName) == 0 &&
	             list[i].sector > list[j].sector))
	            {
	                auxEmpleado=list[i];
	                list[i]=list[j];
	                list[j]=auxEmpleado;

	            }
	        }
	    }
	}
	else if(order == 0)
	{
		for(int i=0;i<len-1;i++)
			    {
			        for(int j=i+1;j<len;j++)
			        {
			            if((strcmp(list[i].lastName, list[j].lastName) == -1) ||
			            (strcmp(list[i].lastName, list[j].lastName) == 0 &&
			             list[i].sector < list[j].sector))
			            {
			                auxEmpleado=list[i];
			                list[i]=list[j];
			                list[j]=auxEmpleado;

			            }
			        }
			    }

	}
	isOk= 0;
	}
	return isOk;
}
int printEmployees(Employee* list, int length)
{
		int flag = 1;
		int isOk = -1;
	    if(list!=NULL && length <=1000 && length > 0 )
	    {
		printf("                        Lista de Empleados   \n");
	    printf("----------------------------------------------------------------\n");
	    printf("Legajo\t        Nombre        apellido      sueldo      sector\n");

	    for(int i=0; i<length; i++)
	    {
	        if(!list[i].isEmpty)
	        {
	            printf("%4d     %10s  %15s      %6.2f       %3d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
	            flag = 0;
	            isOk=1;
	        }
	    }
	    if(flag)
	    {
	        printf("       No hay empleados que mostrar\n\n");
	        isOk=0;
	    }

	    }
	return isOk;
}
int menu()
{
	int opcion=0;

			printf("    *** ABM EMPLEADOS ***\n\n");
	        printf("1. ALTAS\n");
	        printf("2. MODIFICAR\n");
	        printf("3. BAJA\n");
	        printf("4. INFORMAR\n");
	        printf("\nIngrese opcion: ");
	    	scanf("%d", &opcion);

	return opcion;
}
int modifyEmployee(Employee* list, int len, int id)
{
	int isOk=-1;
	int indice;
	char salir = 'n';

	if(list != NULL && len > 0 && len <= 1000)
	{
    indice = findEmployeeById(list, len, id);

    if(indice == -1)
    {
    	printf("No se encontro legajo\n");
    }
    else
    {
    	do
    	{
    	switch(subMenuModify())
    	{
			case 1:
				printf("Ingrese nuevo nombre: ");
				fflush(stdin);
				gets(list[indice].name);
				break;
			case 2:
				printf("Ingrese nuevo apellido: ");
				fflush(stdin);
				gets(list[indice].lastName);
				break;
			case 3:
				printf("Ingrese cambio en el salario: ");
				fflush(stdin);
				scanf("%f", &list[indice].salary);
				break;
			case 4:
				printf("Ingrese nuevo sector: ");
				fflush(stdin);
				scanf("%d", &list[indice].sector);
				break;
			case 5:
				salir = 's';
				break;
			default:
				printf("No es un opcion valida\n");
				system("pause");
				break;
    	}
    	}while(salir == 'n');
    }
	isOk=0;
	}
	return isOk;
}
int  subMenuModify()
{
	int opcion;

		printf("   SUBMENU MODIFICAR:\n");
		printf("----------------------------\n");
		printf("1. Modificar Nombre del empleado.\n");
		printf("2. Modificar Apellido del empleado.\n");
		printf("3. Modificar sueldo del empleado.\n");
		printf("4. Modificar sector del empleado.\n");
		printf("5. Salir.\n");
		printf("Ingrese opcion: \n");
		scanf("%d", &opcion);

	return opcion;
}
