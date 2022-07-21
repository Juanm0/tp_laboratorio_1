/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Juan Navarro
 Version     : Div 1E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu(s)_tp1.h"
#include "validaciones_tp1.h"
#include "calculos_tp1.h"



int main(void) {
	setbuf(stdout, NULL);

	int opcion;

	int flagKilometros = 0;
	int flagAeroyLatam = 0;
	int flagCalculosOp3 = 0;


	int controlAerolineas;
	int controlLatam;
	//Variables de suma importancia, nos dicen si hay errores

	float kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;

	float aAero;
	float bAero;
	float cAero;
	float dAero;
	float diferenciaPrecios;
	float aLatam;
	float bLatam;
	float cLatam;
	float dLatam;


	do
	{
		opcion = menu(kilometros,precioAerolineas,precioLatam);
		switch(opcion)
	{
	case 1:

		kilometros = validarKilometros();
		flagKilometros = 1;
		break;
	case 2:
		printf("**AEROLINEAS**\n");
		precioAerolineas = validarVuelos();
		printf("**LATAM**\n");
		precioLatam = validarVuelos();

		flagAeroyLatam = 1;

		break;
	case 3:

		if(flagAeroyLatam && flagKilometros) {//Opcion 1 y 2 ingresadas

			controlAerolineas = calculosOpcion_3_TP1(precioAerolineas, 0, 10, 1, 25, kilometros, &aAero, &bAero, &cAero, &dAero);
			if(controlAerolineas == 0) {

				controlLatam = calculosOpcion_3_TP1(precioLatam, 0, 10, 1, 25, kilometros, &aLatam, &bLatam, &cLatam, &dLatam);
				diferenciaPrecios = calcularDiferenciaDePrecios(precioLatam, precioAerolineas);
			}
			if(controlAerolineas != -1 && controlLatam != -1) {
				printf("Los calculos se realizaron exitosamente!!\n");
				flagCalculosOp3 = 1;//FLAG PARA SABER SI SE REALIZARON LOS CALCULOS
			}else{
				printf("Hubo un error en los calculos\n");
			}

		}else{
			printf("Error.. IMPOSIBLE CALCULAR, NO SE HAN INGRESADO LOS DATOS AUN\n");
		}

		break;
	case 4:
		if(flagCalculosOp3) {//SI ES 0(FALSO), ENTONCES TODAVIA NO SE REALIZARON LOS CALCULOS

            printf("Aerolineas: \n");
            mostrarPrecios(aAero, bAero, cAero, dAero);
            printf("Latam: \n");
            mostrarPrecios(aLatam, bLatam, cLatam, dLatam);
            printf("\n         e) La diferencia de precio es: $%.2f\n",diferenciaPrecios);

		}else{
			printf("Todavia no se han realizado los calculos (ingrese opcion 3)\n");
		}

		break;
	case 5:
		system("cls");
		kilometros = 7090;
		flagKilometros = 1;
		precioAerolineas = 162965;
		precioLatam = 159339;
		flagAeroyLatam = 1;

		controlAerolineas = calculosOpcion_3_TP1(precioAerolineas, 0, 10, 1, 25, kilometros, &aAero, &bAero, &cAero, &dAero);
		if(controlAerolineas == 0){

		controlLatam = calculosOpcion_3_TP1(precioLatam, 0, 10, 1, 25, kilometros, &aLatam, &bLatam, &cLatam, &dLatam);
		diferenciaPrecios = calcularDiferenciaDePrecios(precioLatam, precioAerolineas);
		printf(" SE HA REALIZADO LA CARGA FORZADA DE DATOS\n\n");
		}else{
			printf("HUBO UN ERROR EN LA CARGA FORZADA\n");
		}
		system("pause");
		break;
	case 6:
		printf("Adios!!");
		break;
	default:
		printf("Error.. opcion incorrecta\n");
		system("pause");
		break;
	}

	}while(opcion != 6);


	return EXIT_SUCCESS;
}
