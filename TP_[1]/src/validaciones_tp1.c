/*
 * validaciones_tp1.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Juan-PC
 */


#include "utn.h"

float validarKilometros() {
	float km = -1;

	utn_getFlotante(&km,"Ingrese kilometros: \n", "ERROR..opcion invalida\n", 0, 1000000, 3);

	return km;
}

float validarVuelos() {

	float vuelo = -1;

	utn_getFlotante(&vuelo,"Ingrese Precio: \n", "ERROR..opcion invalida\n", 0, 1000000, 3);

	return vuelo;
}
