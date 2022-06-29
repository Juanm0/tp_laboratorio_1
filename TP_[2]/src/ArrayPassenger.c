/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juan-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayPassenger.h"


int autoIncrementarId()
{
    static int id = 1000;
    id++;
    return id;
}

int sortPassengers(Passenger* list, int len, int order) {

	int retorno = -1;
	Passenger auxList;
	int estaOrdenado;
//order = 1 es ASENDENTE y order = 0 es DESENDENTE
	if(list != NULL && len > 0 && (order == 1 || order == 0)) {

		do {
			estaOrdenado = 1;
			len--;
			for(int i = 0; i < len; i++) {
				if ((order == 1 && ((strcmp(list[i].lastName,list[i+1].lastName) > 0) ||
					(strcmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger > list[i+1].typePassenger)))
						||
					(order == 0 && ((strcmp(list[i].lastName,list[i+1].lastName) < 0) ||
					(strcmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger > list[i+1].typePassenger)))) {

					auxList = list[i];
					list[i] = list[i+1];
					list[i+1] = auxList;
					estaOrdenado = 0;
				}
			}

		}while(estaOrdenado == 0);
		retorno = 0;
	}

	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order) {

	int retorno = -1;
	Passenger auxList;
	int estaOrdenado;
//order = 1 es ASENDENTE y order = 0 es DESENDENTE
	if(list != NULL && len > 0 && (order == 1 || order == 0)) {

		do {
			estaOrdenado = 1;
			len--;
			for(int i = 0; i < len; i++) {
				if (((order == 1 && list[i].statusFlight == STATUS_ACTIVO && (strcmp(list[i].flyCode,list[i+1].flyCode))>0)) ||
					((order == 0 && list[i].statusFlight == STATUS_ACTIVO && (strcmp(list[i].flyCode,list[i+1].flyCode))<0))) {
					//Ordena de forma ASENDENTE o DESENDENTE a los activos
					auxList = list[i];
					list[i] = list[i+1];
					list[i+1] = auxList;
					estaOrdenado = 0;
				}
			}

		}while(estaOrdenado == 0);
		retorno = 0;
	}

	return retorno;
}

int initPassengers(Passenger* list, int len)
{//recorre todo el array colocando el campo isEmpty en 1
	int huboError = 0;
	if (list != NULL && len > 0)
	{
		for (int i=0; i<len; i++)
		{
			list[i].isEmpty=1;
		}
		huboError=1;
	}
	return huboError;
}

int altaPasajero (Passenger sPassenger[], int len) {

	int retorno = -1;
	Passenger auxList;
	if (sPassenger != NULL && len > 0) {

			system("cls");
			printf("  ******Alta de Pasajero***** \n\n");
			if((utn_getNombre(auxList.name, sizeof(auxList.name), "Ingrese Nombre: ", "Error. El nombre ingresado es invalido", 3))==0
				&& (utn_getNombre(auxList.lastName, sizeof(auxList.lastName), "Ingrese Apellido: ", "Error. El apellido ingresado es invalido", 3))==0
				&& (utn_getAlfanumerico(auxList.flyCode,sizeof(auxList.flyCode), "Ingrese FlyCode: ", "Error. El Flycode ingresado es invalido", 3))==0
				&& (utn_getNumero(&auxList.typePassenger, "[1]GENERAL\n[2]PRIMERA CLASE\n[3]TURISTA\nIngrese Tipo de Pasajero: ", "eRROR..El tipo de pasajero es invalido", 3, 1, 3))==0
				&& (utn_getNumero(&auxList.statusFlight, "[1]ACTIVO\n[2]DEMORADO\n[3]CANCELADO\nIngrese estado de vuelo: ", "eRROR..El estado de vuelo es invalido", 3, 1, 3))==0
				&& (utn_getFlotante(&auxList.price,"Ingrese precio: $", "eRROR..Precio invalido", 0, 8000000, 3))==0)
			{//El vuelo redondo mas caro del mundo sale 7.63 millones de pesos (65mil DLS), por eso use ese numero
				auxList.id = autoIncrementarId();
				retorno = addPassenger(sPassenger, len,auxList.id, auxList.name, auxList.lastName, auxList.price, auxList.typePassenger, auxList.flyCode,auxList.statusFlight);
			}else{
				printf("Hubo un error con el alta del pasajero\n");
				system("pause");
			}

	}
	return retorno;
}


int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int status)
{
	int huboError = -1;
	int index;
	char opcion;
	if (list != NULL && len > 0 && name != NULL && lastName != NULL && flycode != NULL)
	    {

			index = buscarEspacioLibre(list, len);
			if(index != -1) {
				primeraLetraMayuscula(name, strlen(name));
				primeraLetraMayuscula(lastName, strlen(lastName));
				strupr(flycode);
			 	printf("ID          NOMBRE         APELLIDO      PRECIO    TIPO DE PASAJERO      FLYCODE  ESTADO\n");
			 	printf("%d   %10s      %10s      %10.2f   %10d   %15s    %d\n",
			 						id,
			 						name,
			 						lastName,
			 						price,
			 						typePassenger,
			 						flycode,
									status
			 						);
	            utn_getCaracterSoN(&opcion, "Confirma dar de alta este pasajero? (s/n): ", "Error..Opcion invalida", 's', 'n', 3);
			}
			if(opcion == 's') {

				strncpy(list[index].name, name,sizeof(list[index].name));
				strncpy(list[index].lastName, lastName,sizeof(list[index].lastName));
				strncpy(list[index].flyCode, flycode,sizeof(list[index].flyCode));
				list[index].price = price;
				list[index].typePassenger = typePassenger;
				list[index].id = id;
				list[index].isEmpty = 0;
				list[index].statusFlight = status;
				huboError = 0;
			}

	    }
	    return huboError;
}

int removePassenger(Passenger* list, int len, int id)
{
	int huboError = -1;
	int index;
	char opcion;
	if (list != NULL && len > 0 && id > 0) {
			index = findPassengerById(list, len, id);
			if(index != -1)
			{
				mostrarPasajero(list[index]);
				utn_getCaracterSoN(&opcion, "Confirma ELIMINAR a este pasajero? (S/N): ", "Error..Ingrese (S/N): ", 's', 'n', 3);
				if(opcion == 's')
				{
					list[index].isEmpty = 1;//si es 1 quiere decir que el espacio está vacío

					huboError = 0;
				}
			}else{
				printf(MENSAJE_ERROR_2);
			}
		}

	return huboError;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno = -1;

	if (list != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0) {//busca posiciones vacias
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int modificarPasajero (Passenger pArray[], int len) {

	int retorno = -1;
	int index;
	int idAux = -1;
	char opcion;
	system("cls");
	printf("    ****   MODIFICAR PASAJERO   ****  \n\n");
	listarPasajeros(pArray, len);
	utn_getNumero(&idAux, "Ingrese ID: ", "Error, el id ingresado es invalido", 9999, 0, 3);
	if (pArray != NULL && len > 0 && idAux > 0) {
		index = findPassengerById(pArray, len, idAux);
		if(index != -1) {
			mostrarPasajero(pArray[index]);
			utn_getCaracterSoN(&opcion, "Confirma MODIFICAR a este pasajero?(S/N): ", "Error, ingrese S/N", 's', 'n', 3);
			if(opcion == 's')
			{
				retorno = 0;//el retorno es cero si el usuario confirma la modificacion
				do
				{
					switch(subMenu(pArray, len, idAux)) {
					case 1:
						if(utn_getNombre(pArray[index].name, sizeof(pArray[index].name), "Ingrese nuevo Nombre: ", "eRROR..Nombre invalido", 3)!=-1){
							primeraLetraMayuscula(pArray[index].name, sizeof(pArray[index].name));
						}

						break;
					case 2:
						if(utn_getNombre(pArray[index].lastName, sizeof(pArray[index].lastName), "Ingrese nuevo Apellido: ", "eRROR..Apellido invalido", 3)!=-1){
							primeraLetraMayuscula(pArray[index].lastName, sizeof(pArray[index].lastName));
						}

						break;
					case 3:
						utn_getFlotante(&pArray[index].price, "Ingrese nuevo Precio: $", "eRROR..Precio invalido", 0, 7632625, 3);

						break;
					case 4:
						utn_getNumero(&pArray[index].typePassenger, "[1]GENERAL\n[2]PRIMERA CLASE\n[3]TURISTA\nIngrese nuevo Tipo de Pasajero: ", "eRROR..Tipo invalido", 3, 1, 3);

						break;
					case 5:
						if(utn_getNombre(pArray[index].flyCode, sizeof(pArray[index].flyCode), "Ingrese nuevo Codigo de Vuelo: ", "eRROR..Codigo invalido", 3)!=-1){
							primeraLetraMayuscula(pArray[index].flyCode, sizeof(pArray[index].flyCode));
						}

						break;
					case 6:
						opcion = 'n';
						break;
					default:
						printf("Opcion incorrecta\n");
						break;
					}

				}while(opcion == 's');

			}

		}else{
			printf(MENSAJE_ERROR_2);
		}
	}


	return retorno;//-1 = no se encontro el id
}

int subMenu(Passenger sPasajero[], int len, int id)
{
	int opcion;
	int index;
	char aux[51];
	index = findPassengerById(sPasajero, len, id);
	system("cls");
	printf("     ************  INGRESE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR  ****************** \n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("ID    NOMBRE[1]   APELLIDO[2]    PRECIO[3]  TIPO DE PASAJERO[4]   COD. VUELO[5]  SALIR[6]\n");
	printf("-----------------------------------------------------------------------------------------\n");
    switch(sPasajero[index].typePassenger){
    case PRIMERA_CLASE:
    	strncpy(aux,"PRIMERA CLASE",sizeof(aux));
    	break;
    case CLASE_GENERAL:
    	strncpy(aux,"GENERAL",sizeof(aux));
    	break;
    case CLASE_TURISTA:
    	strncpy(aux,"TURISTA",sizeof(aux));
    	break;
    }
	printf("%d    %-10s %-12s  $%-10.2f      %-15s  %s\n",sPasajero[index].id,
	sPasajero[index].name,sPasajero[index].lastName,sPasajero[index].price,
	aux,sPasajero[index].flyCode);
	utn_getNumero(&opcion, "Indique opcion: ","eRROR..Opcion invalida",6, 1, 3);

	return opcion;
}

void mostrarPasajero (Passenger unPasajero) {

	char estado[51];
	char clase[51];
	if (unPasajero.isEmpty == 0) {
		switch(unPasajero.statusFlight){
		case STATUS_ACTIVO:
			strncpy(estado,"ACTIVO",sizeof(estado));
			break;
		case STATUS_DEMORADO:
			strncpy(estado,"DEMORADO",sizeof(estado));
			break;
		case STATUS_CANCELADO:
			strncpy(estado,"CANCELADO",sizeof(estado));
			break;
		}
	    switch(unPasajero.typePassenger){
	    case PRIMERA_CLASE:
	    	strncpy(clase,"PRIMERA CLASE",sizeof(clase));
	    	break;
	    case CLASE_GENERAL:
	    	strncpy(clase,"GENERAL",sizeof(clase));
	    	break;
	    case CLASE_TURISTA:
	    	strncpy(clase,"TURISTA",sizeof(clase));
	    	break;
	    }
		printf("%d  %-10s %-10s $%-7.2f  %-20s  %-11s %s\n",
					unPasajero.id,
					unPasajero.name,
					unPasajero.lastName,
					unPasajero.price,
					clase,
					unPasajero.flyCode,
					estado
					);
	}

}

int buscarEspacioLibre(Passenger pArray[], int len) {

	int retorno = -1;
	if(pArray != NULL && len > 0) {
		for (int i = 0; i < len; i++) {

			if (pArray[i].isEmpty == 1) {
				retorno = i;
				break;
		    }
		}

	}
	return retorno;//Si retorno es -1 quiere decir que no hay espacios libres
}

int printPassengers(Passenger* list, int length)
{
	int huboError=1;
	int flag = 1;
	char opcionChar = '1';//valor ilogico
	int opcionInt;
	float acumPrecio = 0;
	float contador = 0;
	float promedio;
	int contSuperanPromedio = 0;
	if ( list!=NULL && length > 0)
	{
		utn_getNumero(&opcionInt, "[1]Listado por Apellido y Tipo de pasajero\n[2]Listado por Codigo de vuelo y estados de vuelos ACTIVO\nIndique opcion: ",
				"eRROR..Opcion invalida", 2, 1, 3);
		if(opcionInt==1) {
			utn_getCaracterSoN(&opcionChar, "En que orden quiere ver la lista?\nAsendente o desendente? (A/D): ", "eRROR..Ingrese (A/D)", 'a', 'd',3);
			if(opcionChar == 'a') {
				sortPassengers(list, length, 1);
			}else if(opcionChar == 'd'){
				sortPassengers(list, length, 0);
			}
		}else if(opcionInt == 2){
			utn_getCaracterSoN(&opcionChar, "En que orden quiere ver la lista de ACTIVOS?\nAsendente o desendente? (A/D): ", "eRROR..Ingrese (A/D)", 'a', 'd',3);
			if(opcionChar == 'a') {
				sortPassengersByCode(list, length, 1);
			}else if(opcionChar == 'd') {
				sortPassengersByCode(list, length, 0);
			}

		}
		if(opcionChar != '1') {
			system("cls");
			printf("     ***********************  LISTA DE PASAJEROS  **********************     \n");
			printf("-------------------------------------------------------------------------------\n");
			printf("ID    NOMBRE     APELLIDO   PRECIO   TIPO DE PASAJERO     COD. VUELO    ESTADO  \n");
			printf("-------------------------------------------------------------------------------\n");

			for(int i=0;i<length;i++)
			{
				if((list[i].isEmpty == 0 && opcionInt == 1) || (list[i].isEmpty == 0 && opcionInt == 2 && list[i].statusFlight == STATUS_ACTIVO))
				{

					mostrarPasajero(list[i]);//Muestra los pasajeros en los indices otorgados
					acumPrecio = acumPrecio + list[i].price;
					contador++;
					flag=0;
				}
			}
			if(!flag)
			{
				promedio = acumPrecio/contador;
				for(int i=0;i<length;i++){

					if((opcionInt == 1 && list[i].isEmpty == 0 && list[i].price > promedio) ||
						(opcionInt == 2 && list[i].isEmpty == 0 && list[i].price > promedio && list[i].statusFlight == STATUS_ACTIVO)){
						contSuperanPromedio++;
					}
				}
				printf("El total de los precios es de $%.2f, su promedio es de $%.2f, existen %d pasajero(s) que superan el promedio\n",
						acumPrecio,promedio,contSuperanPromedio);

			}else{
				printf("No hay personas para mostrar\n");
			}
			huboError=0;
		}

	}

	return huboError;
}

int listaVacia(Passenger* list, int len)
{//recorre todo el array fijandose si esta vacia o no
	int retorno;
	int contador = 0;
	if (list != NULL && len > 0)
	{
		for (int i=0; i<len; i++)
		{
			if(list[i].isEmpty==1) {
				contador++;
			}
		}
		if(contador == len) {
			retorno = 1;//la lista esta vacia
		}else{
			retorno = 0;//la lista no esta vacia
		}

	}
	return retorno;
}

void listarPasajeros(Passenger* list, int len) {

	if(list != NULL && len > 0) {
		for(int i = 0; i < len;i++) {
			mostrarPasajero(list[i]);
		}
	}

}
