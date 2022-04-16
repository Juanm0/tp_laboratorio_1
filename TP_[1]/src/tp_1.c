/*
 * tp_1.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Juan-PC
 */


#include <stdio.h>
#include <stdlib.h>
#include "calculosLib.h"

int menu(int flagX, float km, int flagYZ, float precioY, float precioZ, int flagY, int flagZ){
	int opcion;
	system("cls");//Limpia la pantalla en .exe
	if(flagX == 0)//Cuando esta flag está en 0 muestra el menu original sin alteraciones
	{
		printf("\n	 1.Ingresar Kilometros: ( km=x)\n\n");
	}
	else
	{
		printf("\n	 1.Ingresar Kilometros: (km=%.1f)\n\n",km);
	}//cuando la flag tiene un 1, nos muestra la opcion kilometros ingresada por el usuario

	if(flagYZ==0)//Cuando esta flag está en 0, se muestra la opcion Aerolineas y Latam, originales, sin alteraciones
	{
		printf( "	 2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)\n\n");
	}
	else//Cuando la flagYZ esta en 1, muestra alguna o todas las opciones que el usuario ya ingreso
	{
			printf( "	 2. Ingresar Precio de Vuelos:\n");
			if(flagY == 0){//Esta bandera sirve para mostrar la opcion Aerolineas (flagY = 1) de haber sido ingresada
				printf(	"	 - Precio vuelo Aerolineas:[NO INGRESADO]\n");
			}else{
				printf(	"	 - Precio vuelo Aerolineas:$%.2f\n",precioY);
			}
			if(flagZ == 0){//Esta bandera sirve para mostrar la opcion Latam (flagZ = 1) de haber sido ingresada
				printf(	"	 - Precio vuelo Latam:[NO INGRESADO]\n\n");
			}else{
				printf(	"	 - Precio vuelo Latam:$%.2f\n\n",precioZ);
			}
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
printf("\nIndique opcion: ");
scanf("%d",&opcion);//Retorna la opcion ingresada por el usuario
return opcion;
}


int subMenu(float km, int flagY, int flagZ, float precioY, float precioZ, float aeroA, float aeroB, float aeroC, float aeroD, float aeroE, float latamA, float latamB, float latamC, float latamD){

	system("cls");//Limpia la pantalla en .exe
		printf("\n	 1.Ingresar Kilometros: (km=%.1f)\n\n",km);
		printf( "	 2. Ingresar Precio de Vuelos:\n");
		if(flagY == 0){//cuando esta flag está en 0, quiere decir que no ha ingresado el precio de Aerolineas
			printf(	"	 - Precio vuelo Aerolineas:[NO INGRESADO]\n");
		}else{
			printf(	"	 - Precio vuelo Aerolineas:$%.2f\n",precioY);
		}
		if(flagZ == 0){//cuando esta flag está en 0, quiere decir que no ha ingresado el precio de Latam
			printf(	"	 - Precio vuelo Latam:[NO INGRESADO]\n\n");
		}else{
			printf(	"	 - Precio vuelo Latam:$%.2f\n\n",precioZ);
		}
		printf(	"	 3. Calcular todos los costos:\n");
		printf(	"	 a) Tarjeta de debito (descuento 10%%)\n");
		printf(	"	 b) Tarjeta de credito (interes 25%%)\n");
		printf(	"	 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
		printf(	"	 d) Mostrar precio por km (precio unitario)\n");
		printf(	"	 e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n\n");
		printf(	"	 4. Informar Resultados\n\n");
		if(flagY == 1 && flagZ == 1){//Muestra todos los resultados cuando todos los precios fueron cargados
			printf("	 Latam:\n");
			printf("	 a) Precio con tarjeta de debito: $%.2f \n",latamA);
			printf("	 b) Precio con tarjeta de credito: $%.2f\n",latamB);
			printf("	 c) Precio pagando con bitcoin : BTC %f\n",latamC);
			printf("	 d) Precio unitario: $%.2f/km\n",latamD);
			printf("	 Aerolineas:\n");
			printf("	 a) Precio con tarjeta de debito: $%.2f\n",aeroA);
			printf("	 b) Precio con tarjeta de credito: $%.2f\n",aeroB);
			printf("	 c) Precio pagando con bitcoin : BTC %f\n",aeroC);
			printf("	 d) Precio unitario: $%.2f/km\n",aeroD);
			printf("	 La diferencia de precio (Latam - Aerolineas) es de :$ %.2f \n\n",aeroE);//Latam MENOS Aerolineas
		}
		if(flagY == 1 && flagZ == 0){//Muestra solo los precios de Aerolineas
			printf("	 Aerolineas:\n");
			printf("	 a) Precio con tarjeta de debito: $%.2f\n",aeroA);
			printf("	 b) Precio con tarjeta de credito: $%.2f\n",aeroB);
			printf("	 c) Precio pagando con bitcoin : BTC %f\n",aeroC);
			printf("	 d) Precio unitario: $%.2f/km\n\n",aeroD);
		}
		if(flagZ == 0 && flagY == 0){//Muestra solo los precios de Latam
			printf("	 Latam:\n");
			printf("	 a) Precio con tarjeta de debito: $%.2f\n",latamA);
			printf("	 b) Precio con tarjeta de credito: $%.2f\n",latamB);
			printf("	 c) Precio pagando con bitcoin : BTC %f\n",latamC);
			printf("	 d) Precio unitario: $%.2f/km\n\n",latamD);
		}
		printf("         5. Carga forzada de datos\n");
		printf("	 6. Salir\n");
		printf("\nIndique opcion:\n");

	return 0;//No retorna ninguna opcion ingresada por el usuario
}

int calculosOpcion_3_TP1(float precio, int tipoA, float cantidadA, float tipoB, float cantidadB, float km, float* opcionA, float* opcionB, float* opcionC, float* opcionD){

	int retorno;
	retorno = -1;
	if(opcionA != NULL && opcionB != NULL && opcionC != NULL && opcionD != NULL && km > 0 && precio > 0 &&
		cantidadA > 0 && cantidadB > 0 && (tipoA == 0 || tipoA == 1) && (tipoB == 0 || tipoB == 1)){
//Luego de verificar que todas las opciones esten bien, realiza los calculos solicitados en orden
	*opcionA = calcularPorcentajeFloatPositivos(precio,tipoA,cantidadA);
	*opcionB = calcularPorcentajeFloatPositivos(precio,tipoB,cantidadB);
	*opcionC = precio / 4606954.55;
	*opcionD = precio / km;
	if(!(*opcionA == -1 || *opcionB == -1)){//El retorno solo podra ser 0 si no hubo error en los calculos
		retorno = 0;
		}
	}
	return retorno;//Retorno -1 significa que algo salio mal
}
