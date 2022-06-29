/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "LinkedList.h"

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr) {
	Passenger* retorno = NULL;

	return retorno;
}

void Passenger_delete(Passenger* this) {
	this = NULL;
}

Passenger* Passenger_new() {
	Passenger* retorno = NULL;

	return retorno;
}

Passenger* newPassengerParamUsuarios(int id,char* nombre,char* apellido, float precio,int tipoPasajero, char* codigoVuelo) {

	Passenger* retorno = NULL;
	Passenger * pPassenger;
	pPassenger = Passenger_new();


	if(pPassenger != NULL) {

		if((Passenger_setId(pPassenger, id))!=-1 &&
		(Passenger_setNombre(pPassenger, nombre))!=-1 &&
		(Passenger_setApellido(pPassenger, apellido))!=-1 &&
	    (Passenger_setPrecio(pPassenger, precio))!=-1 &&
		(Passenger_setTipoPasajero(pPassenger, tipoPasajero))!=-1 &&
		(Passenger_setCodigoVuelo(pPassenger, codigoVuelo))!=-1) {

			retorno = pPassenger;
		}
	}

	return retorno;
}

int mostrarPasajeros(Passenger* arrayPPasajero[], int len) {

	int retorno = -1;

	if(arrayPPasajero != NULL && len > 0) {

		for(int i=0; i < len; i++) {
			mostrarUnPasajero(arrayPPasajero[i]);
			//mostrarUnProducto(*(arrayPProducto + i));
		}
		retorno = 0;
	}
	return retorno;
}

int mostrarUnPasajero(Passenger* pPassenger) {

	int retorno = -1;
	Passenger auxList;
	char tipoPasajeroAux[10];

	//aca va un if enorme
	Passenger_getId(pPassenger, &auxList.id);
	Passenger_getNombre(pPassenger, auxList.nombre);
	Passenger_getApellido(pPassenger, auxList.apellido);
	Passenger_getPrecio(pPassenger, &auxList.precio);
	Passenger_getCodigoVuelo(pPassenger, &auxList.codigoVuelo);
	Passenger_getTipoPasajero(pPassenger,&auxList.tipoPasajero);

	switch (auxList.tipoPasajero) {
		case 1:
			strcpy(tipoPasajeroAux, "GENERAL");
			break;
		case 2:
			strcpy(tipoPasajeroAux, "PRIMERA CLASE");
			break;
		case 3:
			strcpy(tipoPasajeroAux, "TURISTA");
			break;
	}


	if(auxList != NULL) {
		retorno = 0;

		printf("%d %-10s %-15s %-10.2f %-10s %-15s \n",auxList.id, auxList.nombre,
				auxList.apellido, auxList.precio, auxList.codigoVuelo, tipoPasajeroAux);
	}
	return retorno;
}

int findPassengerById(LinkedList* list, int idBuscar)
{
	int retorno = -1;
	int len;
	int idAux;
	Passenger* pPassenger;
	len = ll_len(list);

	if (list != NULL && len > 0) {

		for(int i = 0; i < len; i++) {

			pPassenger = (Passenger*)ll_get(list,i);
			if (Passenger_getId(list[i],&idAux) == idBuscar) {

				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
