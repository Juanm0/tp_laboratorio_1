/*
 * menu_tp3.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Juan-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menu(void)
{
	int opcion;
	system("cls");
	printf("Menu de opciones\n\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
	printf("10 - SALIR\n");
	utn_getNumero(&opcion, "Ingrese opcion: ","eRROR..OPCION invalida", 10, 1, 3);

	return opcion;
}
