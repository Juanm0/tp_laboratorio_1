/*
 * menu(s)_tp1.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Juan-PC
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menu(float km, float precioY, float precioZ) {
	int opcion;
	system("cls");//Limpia la pantalla en .exe
	if(km == 0)//cuando los km son 0 se muestra una x
	{
		printf("\n	 1.Ingresar Kilometros: ( km=x)\n\n");
	}
	else
	{
		printf("\n	 1.Ingresar Kilometros: (km=%.1f)\n\n",km);
	}

	if(precioY==0 && precioZ == 0)
	{
		printf( "	 2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)\n\n");
	}
	else
	{
			printf( "	 2. Ingresar Precio de Vuelos:\n");
			printf(	"	 - Precio vuelo Aerolineas:$%.2f\n",precioY);
			printf(	"	 - Precio vuelo Latam:$%.2f\n\n",precioZ);
	}
printf(	"	 3. Calcular todos los costos:\n");
printf(	"	 a) Tarjeta de debito (descuento 10%%)\n");
printf(	"	 b) Tarjeta de credito (interes 25%%)\n");
printf(	"	 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
printf(	"	 d) Mostrar precio por km (precio unitario)\n");
printf(	"	 e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n\n");
printf(	"	 4. Informar Resultados\n\n");
printf("	 5. Carga forzada de datos\n");
printf("	 6. Salir\n");
utn_getNumero(&opcion,"Indique opcion: ", "Error..Opcion invalida",6, 1, 3);//Retorna la opcion ingresada por el usuario
return opcion;
}


void mostrarPrecios(float opADebito, float opBCredito, float opCBitcoin, float opDKmUnitario) {



		printf("	 a) Precio con tarjeta de debito: $%.2f\n",opADebito);
		printf("	 b) Precio con tarjeta de credito: $%.2f\n",opBCredito);
		printf("	 c) Precio pagando con bitcoin : BTC %f\n",opCBitcoin);
		if(opDKmUnitario == -1) {
			printf("	 d) Error en la division (imposible dividir por 0)\n");
		}else{
			printf("	 d) Precio unitario: $%.2f/km\n",opDKmUnitario);
		}



}
