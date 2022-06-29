/*
 * Juan Navarro
 * Div 1E
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu_tp3.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int opcion = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	opcion = menu();
        switch(opcion)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;

            case 2:
            	controller_loadFromBinary("data.bin",listaPasajeros);
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	break;
            case 5:
            	break;
            case 6:
            	break;
            case 7:
            	break;
            case 8:
            	break;
            case 9:
            	break;
            case 10:
            	opcion = 11;
            	break;
        }
    }while(opcion != 11);
    return 0;
}


