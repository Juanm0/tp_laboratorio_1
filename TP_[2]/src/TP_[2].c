/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Juan Navarro
 Version     : Div 1E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "utn.h"

#define LEN_ESTRUCT_HARDCODE 6



int main(void) {


	setbuf(stdout, NULL);

	Passenger sPasajeros[QTY_PASSENGER];
	Passenger EstructuraHardcodeo[LEN_ESTRUCT_HARDCODE] = {{000, "Juan", "Navarro", 18000, "AAA",PRIMERA_CLASE,STATUS_ACTIVO,0 } ,
							{000, "Violeta", "Perez", 43536, "AAA",CLASE_GENERAL,STATUS_DEMORADO,0},
							{000, "Esteban", "Quito", 566500, "BDA",CLASE_TURISTA,STATUS_CANCELADO,0},
							{000, "Baracko", "Bama", 35367, "FGF",PRIMERA_CLASE,STATUS_ACTIVO,0},
							{000,"Marcos", "Placido", 24523, "DDD",CLASE_GENERAL,STATUS_ACTIVO,0},
							{000, "Juan Carlos", "Almeida", 62756, "ZHK",CLASE_TURISTA,STATUS_DEMORADO,0}};
	initPassengers(sPasajeros, QTY_PASSENGER);
	int idAux = -1;//valor ilogico
	int auxIndex;

	do {


		switch(menu()) {

		case 1:
			if(altaPasajero(sPasajeros, QTY_PASSENGER)==0) {
				idAux = 1;//valor true
			}
			break;

		case 2:
			if(idAux == 1) {
				modificarPasajero(sPasajeros, QTY_PASSENGER);
			}else{
				printf(MENSAJE_ERROR_1);
			}
			system("pause");

			break;

		case 3:
			if(idAux == 1) {
				system("cls");
				printf("    ****   ELIMINAR PASAJERO   ****  \n\n");
				if((utn_getNumero(&idAux, "Ingrese ID : ","Error, id ingresado no es valido", 9999, 0, 3)) == 0)
				{
					if((removePassenger(sPasajeros, QTY_PASSENGER, idAux)) == 0)
					{
						printf("BAJA EXITOSA\n");
					}
					idAux = 1;
				}
			}else{
				printf(MENSAJE_ERROR_1);
			}
			system("pause");

			break;

		case 4:
			if(idAux == 1) {
				printPassengers(sPasajeros, QTY_PASSENGER);
			}else{
				printf(MENSAJE_ERROR_1);
			}
     		system("pause");

			break;

		case 5:

			auxIndex = buscarEspacioLibre(sPasajeros, QTY_PASSENGER);
			if(auxIndex != -1){
				for(int i=0 ; i < LEN_ESTRUCT_HARDCODE;i++){
						EstructuraHardcodeo[i].id = autoIncrementarId();
						sPasajeros[auxIndex]=EstructuraHardcodeo[i];
						auxIndex++;

				}
				idAux=1;
				printf("CARGA EXITOSA\n");
			}else{
				printf("Hubo error en la carga\n");
			}
			system("pause");
			break;

		default:
			break;

		}

	}while(1);


	return EXIT_SUCCESS;
}
