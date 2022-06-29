/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Juan Navarro
 Version     : Div 1E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style


 El menu esta dentro de un bucle infinito que no tiene la opcion de salir (error grave).LISTO
No se comprende la logica aplicada en las funciones "altaPasajero" y "addPassenger" ya la segunda
pisa los valores asignados por la primera en la misma posicion del array. LISTO
El ordenar por doble criterio no es coherente ya que ordena comparando el valor numerico y estos
no coindicen alfabeticamente con la descripcion.LISTO
El ordenar por codigo y estado Activo muestra los vuelos que estan demorados/cancelados, solo
deberia mostrar los activos.LISTO
Todos los metodos de ordenamiento se pueden simplificar.LISTO
Al editar el nombre o cualquier tipo de dato string seria bueno aplicarle el modificador de formato
ya que si se ponen todas minusculas quedan de esa forma.LISTO
Antes de pedir el id del pasajero, ya sea para modificar o dar de baja, seria bueno ver la lista
completa para poder elegir.LISTO
El resto de la logica esta bien aplicada.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "utn.h"
#include "string.h"
#include "menu_tp2.h"

#define LEN_ESTRUCT_HARDCODE 6



int main(void) {


	setbuf(stdout, NULL);

	int opcion;

	Passenger sPasajeros[QTY_PASSENGER];


	Passenger EstructuraHardcodeo[LEN_ESTRUCT_HARDCODE] = {{000, "Juan", "Navarro", 18000, "AAA",PRIMERA_CLASE,STATUS_CANCELADO,0 } ,
							{000, "Violeta", "Perez", 43536, "AAA",CLASE_GENERAL,STATUS_ACTIVO,0},
							{000, "Esteban", "Quito", 566500, "BDA",CLASE_TURISTA,STATUS_CANCELADO,0},
							{000, "Baracko", "Bama", 35367, "FGF",PRIMERA_CLASE,STATUS_ACTIVO,0},
							{000,"Marcos", "Perez", 24523, "DDD",PRIMERA_CLASE,STATUS_ACTIVO,0},
							{000, "Juan Carlos", "Almeida", 62756, "ZHK",CLASE_TURISTA,STATUS_DEMORADO,0}};
	initPassengers(sPasajeros, QTY_PASSENGER);


	int idAux = -1;//valor ilogico
	int auxIndex;

	do {

		opcion = menu();
		switch(opcion) {

		case 1:

			if(altaPasajero(sPasajeros,QTY_PASSENGER) != -1) {

				printf("Alta exitosa\n");
			}else{
				printf("Hubo error en el alta\n");
			}
			break;

		case 2:
			if(listaVacia(sPasajeros, QTY_PASSENGER)!=1) {

				modificarPasajero(sPasajeros, QTY_PASSENGER);
			}else{
				printf(MENSAJE_ERROR_1);
			}
			system("pause");

			break;

		case 3:
			if(listaVacia(sPasajeros, QTY_PASSENGER)!=1) {
				system("cls");
				printf("    ****   ELIMINAR PASAJERO   ****  \n\n");
				listarPasajeros(sPasajeros, QTY_PASSENGER);
				if((utn_getNumero(&idAux, "Ingrese ID : ","Error, id ingresado no es valido", 9999, 0, 3)) == 0)
				{
					if((removePassenger(sPasajeros, QTY_PASSENGER, idAux)) == 0)
					{
						printf("BAJA EXITOSA\n");
					}
				}
			}else{
				printf(MENSAJE_ERROR_1);
			}
			system("pause");

			break;

		case 4:
			if(listaVacia(sPasajeros, QTY_PASSENGER)!=1) {
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
				printf("CARGA EXITOSA\n");
			}else{
				printf("Hubo error en la carga\n");
			}
			system("pause");
			break;

		case 6:
			printf("Adios!!");
			break;
		default:
			printf("Error..Opcion invalida");
			break;

		}

	}while(opcion != 6);


	return EXIT_SUCCESS;
}
