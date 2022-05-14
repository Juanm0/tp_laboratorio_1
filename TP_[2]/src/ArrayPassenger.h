/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juan-PC
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define MENSAJE_ERROR_1 "No hay pasajeros cargados\n"
#define MENSAJE_ERROR_2 "No se encontro el ID ingresado\n"
#define QTY_PASSENGER 2000
#define PRIMERA_CLASE 1
#define CLASE_GENERAL 2
#define CLASE_TURISTA 3
#define STATUS_ACTIVO 1
#define STATUS_DEMORADO 2
#define STATUS_CANCELADO 3

//#define CONTENIDO_HARDCODEO {{900, "Juan", "Navarro", 18000, "AAA",PRIMERA_CLASE,STATUS_ACTIVO,0 } ,{901, "Violeta", "Perez", 43536, "AAA",CLASE_GENERAL,STATUS_DEMORADO,0},{902, "Esteban", "Quito", 566500, "BDA",CLASE_TURISTA,STATUS_CANCELADO,0},{903, "Baracko", "Bama", 35367, "FGF",PRIMERA_CLASE,STATUS_ACTIVO,0},{904,"Marcos", "Placido", 24523, "DDD",CLASE_GENERAL,STATUS_ACTIVO,0},{905, "Juan Carlos", "Almeida", 62756, "ZHK",CLASE_TURISTA,STATUS_DEMORADO,0}}

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;//0 es falso (no esta vacio)

}typedef Passenger;
/**
 * @brief Muestra el menu para el ABM de pasajeros
 *
 * @return retorna la opcion seleccionada
 */
int menu(void);
/**
 * @brief Funcion que permite auto incrementar un campo ID
 *
 * @return retorna el ID ya incrementado
 */
int autoIncrementarId();
/**
 * @brief Funcion que me permite realizar el alta de los Pasajeros
 *
 * @param pArray Estructura tipo Passenger
 * @param len tamaño del array
 * @return
 */
int altaPasajero (Passenger pArray[], int len);
/**
 * @brief añade en una lista existente de pasajeros los valores recibidos como parametros
* en la primer posicion libre
 *
 * @param list passenger*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param price float
 * @param typePassenger int
 * @param flycode[]char
 * @return int retorna (-1) si hubo un error (len invalido o puntero NULL o
 *  sin espacio libre) - (0) si salio todo bien
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/**
 * @brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
 *
 * @param list Passenger* Puntero a un array de pasajeros
 * @param len  int Array tamaño
 * @return int retorna (-1) si hubo un error (len invalido o puntero NULL) - (0) si salio todo bien
 */
int initPassengers(Passenger* list, int len);
/**
 * @brief Muestra los pasajeros siempre que no este vacio
 *
 * @param unPasajero estructura tipo Passenger
 */
void mostrarPasajero (Passenger unPasajero);
/**
 * @brief Recorre un array de pasajeros hasta encontrar un espacio vacio
 *
 * @param pArray Estructura tipo Passenger
 * @param len int tamaño del array
 * @return int retorna el indice del espacio que encontro, si no lo encuentra (-1)
 */
int buscarEspacioLibre(Passenger pArray[], int len);
/**
 * @brief Imprime el array de pasajeros de forma encolumnada.
 *
 * @param list Passenger*
 * @param length int
 * @return int retorna (-1) si algo salio mal, y si todo salio bien (0)
 */
int printPassengers(Passenger* list, int length);
/**
 * @brief Busca un pasajero recibiendo como parámetro de búsqueda su Id.
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return Retorna la posicion del indice del pasajero o (-1) si [tamaño invalido o
 * puntero NULL o no encuentra al pasajero]
 */
int findPassengerById (Passenger* list, int len, int id);
/**
 * @brief Modifica los datos de un pasajero
 *
 * @param pArray Estructura tipo Passenger
 * @param len int
 * @return Retorna (0) si el usuario confirma la modificacion y (-1) si [tamaño invalido o
 * puntero NULL o no encuentra al pasajero]
 */
int modificarPasajero (Passenger pArray[], int len);
/**
 * @brief Menu para confirmar los datos que deasea modificar
 *
 * @param sPasajeros Estructura tipo Passenger
 * @param len int
 * @param id int
 * @return Retorna la opcion ingresada por el usuario
 */
int subMenu(Passenger sPasajeros[], int len, int id);
/**
 * @brief Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return Retorna (-1) si [tamaño invalido o puntero NULL o no encuentra un pasajero]
 * - (0) si elimino al pasajero
 */
int removePassenger(Passenger* list, int len, int id);
/**
 * @brief Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
 * desendente
 *
 * @param list Passenger*
 * @param len int
 * @param order int [1] indica orden asendente y [0] desendente
 * @return Retorna (-1) si [tamaño invalido o puntero NULL o no encuentra un pasajero]
 * - (0) si todo bien
 */
int sortPassengers(Passenger* list, int len, int order);
/**
 * @brief Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o
 * desendente
 *
 * @param list Passenger*
 * @param len int
 * @param order int [1] indica orden asendente y [0] desendente
 * @return Retorna (-1) si [tamaño invalido o puntero NULL o no encuentra un pasajero]
 * - (0) si todo bien
 */
int sortPassengersByCode(Passenger* list, int len, int order);

#endif /* ARRAYPASSENGER_H_ */
