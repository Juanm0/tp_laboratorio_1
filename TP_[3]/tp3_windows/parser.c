#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* newPasajero;
	char id[10];
	char nombre[50];
	char apellido[50];
	char precio[10];
	char tipoPasajero[50];
	char codigoVuelo[10];

	if(pFile != NULL && pArrayListPassenger != NULL) {

		do {

			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,
				nombre,apellido,precio,tipoPasajero,codigoVuelo) == 6) {

				newPasajero = Passenger_newParametros(id, nombre,apellido,precio,tipoPasajero,codigoVuelo);

				if(newPasajero != NULL) {

					if(ll_add(pArrayListPassenger, newPasajero)!=-1) {
						retorno = 0;
					}else{
						Passenger_delete(newPasajero);
					}
				}
			}
		}while(!feof(pFile));
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* newPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL) {

		do {

				newPasajero = Passenger_new();

				if(newPasajero != NULL && fread(newPasajero,sizeof(Passenger),1,pFile)==1) {

					if(ll_add(pArrayListPassenger, newPasajero)!=-1) {
						retorno = 0;
					}else{
						Passenger_delete(newPasajero);
					}
				}

		}while(!feof(pFile));
	}

    return retorno;
}
