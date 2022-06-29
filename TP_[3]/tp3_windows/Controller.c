#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListPassenger != NULL) {

		pFile = fopen(path,"r");
		if(pFile != NULL) {
			retorno = parser_PassengerFromText(pFile, pArrayListPassenger);
			fclose(pFile);
		}
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListPassenger != NULL) {

		pFile = fopen(path,"rb");
		if(pFile != NULL) {
			retorno = parser_PassengerFromBinary(pFile, pArrayListPassenger);
			fclose(pFile);
		}
	}
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pNewPassenger;
	int id;
	id = autoIncrementarId();
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	if(pArrayListPassenger != NULL) {
		if(id != -1) {

			pNewPassenger = newPassengerParamUsuarios(id, nombre, apellido, precio, tipoPasajero, codigoVuelo);
			if(pNewPassenger != NULL) {

				if(ll_add(pArrayListPassenger, pNewPassenger)!=-1) {

					retorno = 0;
				}else{
					Passenger_delete(pNewPassenger);
				}
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pToEditPassenger;
	int idIngresada;
	int index;

	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger)) {

//		mostrarPasajeros(pArrayListPassenger,ll_len(pArrayListPassenger));
		if(utn_getNumero(&idIngresada, "Ingrese el ID del pasajero que quiere modificar\n", "Error..ID invalida\n", 9999, 1, 3)!=-1) {

			index = findPassengerById(list, id)
		}
	}
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

int controller_GetUltimoId(char* path)
{
	int retorno = -1;
	FILE* pFile;
	char idAsignar[10];
	int idRetorno;

	if(path != NULL) {

		pFile = fopen(path,"r");
		if(pFile != NULL) {

			fscanf(pFile,"%[^\n]\n",idAsignar);//toma el primer dato de la lista
			idRetorno = atoi(idAsignar);
			if(idRetorno > 0){
				retorno = idRetorno;
			}

			fclose(pFile);
		}

	}
    return retorno;
}

int autoIncrementarId()
{
    static int id = controller_GetUltimoId("lastId.csv");
    id++;
    return id;
}

