/*
 * menu_tp2.c
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
	printf("1 - ALTA DE UN PASAJERO\n");
	printf("2 - MODIFICAR DATOS DE UN PASAJERO\n");
	printf("3 - DAR DE BAJA A UN PASAJERO\n");
	printf("4 - INFORMAR DATOS DE LOS PASAJEROS\n");
	printf("5 - CARGA FORZADA DE PASAJEROS\n");
	printf("6 - SALIR\n");
	utn_getNumero(&opcion, "Ingrese opcion: ","eRROR..OPCION invalida", 6, 1, 3);

	return opcion;
}
