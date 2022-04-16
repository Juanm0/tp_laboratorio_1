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
#include "tp_1.h"

int main(void) {
	setbuf(stdout, NULL);

	int flagKilometros = 0;
	int flagAeroyLatam = 0;
	int flagAero = 0;
	int flagLatam = 0;
	int flagOpcion3 = 0;
	int flagOpcion4 = 0;
	int huboError;//Variable de suma importancia, nos dice si hay errores

	float kilometros;
	float precioAerolineas;
	float precioLatam;

	float aAero;
	float bAero;
	float cAero;
	float dAero;
	float eAero;
	float aLatam;
	float bLatam;
	float cLatam;
	float dLatam;

	char seleccionYoZ;

	char salir='s';
	do
	{

		switch(menu(flagKilometros,kilometros,flagAeroyLatam,precioAerolineas,precioLatam,flagAero,flagLatam))
	{
	case 1:

		printf("Ingrese kilometros: \n");
		scanf("%f",&kilometros);
		while(kilometros <= 0)
		{
			printf("Error.. Ingrese kilometros mayores a 0:\n");
			scanf("%f",&kilometros);
		}
		if(flagOpcion4 == 1){
			flagOpcion3 = 0;
		}
		flagKilometros = 1;
		break;
	case 2:
		printf("Indique de cual opcion desea ingresar el precio (Aerolineas=y, Latam=z):\n");
		fflush(stdin);
		scanf("%c",&seleccionYoZ);
		while(seleccionYoZ != 'y' && seleccionYoZ != 'z')
		{
			printf("Error.. Ingrese \"y\" o \"z\"(Aerolineas=y, Latam=z)\n");
			fflush(stdin);
			scanf("%c",&seleccionYoZ);
		}

		if(seleccionYoZ == 'y')
		{
			printf("Ingrese el precio del vuelo de Aerolineas: \n");
			scanf("%f",&precioAerolineas);
			while(precioAerolineas <= 0)
			{
				printf("Aerolineas no ofrece vuelos gratis, ingrese un precio verdadero o recargue el programa adecuadamente\n");
				printf("Ingrese el precio del vuelo de Aerolineas: \n");
				scanf("%f",&precioAerolineas);
			}
			flagAero = 1;
		}
		else
		{
			printf("Ingrese el precio del vuelo de Latam: \n");
			scanf("%f",&precioLatam);
			while(precioLatam <= 0)
			{
				printf("Latam no ofrece vuelos gratis, ingrese un precio verdadero o recargue el programa adecuadamente\n");
				printf("Ingrese el precio del vuelo de Latam: \n");
				scanf("%f",&precioLatam);
			}
			flagLatam = 1;
		}
		flagAeroyLatam = 1;
		if(flagOpcion4 == 1){
			flagOpcion3 = 0;//Variable de control para que no se pueda usar la opcion 4 indevidamente
		}
		break;
	case 3:

		if(flagAero==1 && flagLatam == 1 && flagKilometros == 1){
			huboError = calculosOpcion_3_TP1(precioAerolineas, 0, 10, 1, 25, kilometros, &aAero, &bAero, &cAero, &dAero);
			if(huboError == 0){
			huboError = calculosOpcion_3_TP1(precioLatam, 0, 10, 1, 25, kilometros, &aLatam, &bLatam, &cLatam, &dLatam);
			eAero = precioLatam - precioAerolineas;
			}

		}else if(flagAero == 1 && flagLatam == 0 ){
			huboError = calculosOpcion_3_TP1(precioAerolineas, 0, 10, 1, 25, kilometros, &aAero, &bAero, &cAero, &dAero);
		}else if (flagAero == 0 && flagLatam == 1){
			huboError = calculosOpcion_3_TP1(precioLatam, 0, 10, 1, 25, kilometros, &aLatam, &bLatam, &cLatam, &dLatam);
		}
		else{
			printf("Error.. IMPOSIBLE CALCULAR, NO SE HAN INGRESADO LOS DATOS AUN\n");
		}
		if( ( flagAero == 1 || flagLatam == 1 )&& flagKilometros == 1 && huboError == 0 ){
		printf("SE HAN REALIZADO LOS CALCULOS\n");
		flagOpcion3 = 1;
		flagOpcion4 = 0;
		}
		else{
			printf("HUBO ERROR EN LOS CALCULOS\n");
		}
		system("pause");
		break;
	case 4:
		if(flagKilometros == 1 && flagAeroyLatam == 1 && flagOpcion3 == 1 && huboError == 0){
			subMenu( kilometros, flagAero, flagLatam, precioAerolineas, precioLatam, aAero, bAero, cAero, dAero, eAero, aLatam, bLatam, cLatam, dLatam);
		}
		else{
			printf("Error.. no se pueden mostrar los datos sin antes calcularlos\n");
		}
		system("pause");
		flagOpcion4 = 1;
		break;
	case 5:
		system("cls");
		kilometros = 7090;
		flagKilometros = 1;
		precioAerolineas = 162965;
		flagAero = 1;
		precioLatam = 159339;
		flagLatam = 1;
		flagAeroyLatam = 1;

		huboError = calculosOpcion_3_TP1(precioAerolineas, 0, 10, 1, 25, kilometros, &aAero, &bAero, &cAero, &dAero);
		if(huboError == 0){
		huboError = calculosOpcion_3_TP1(precioLatam, 0, 10, 1, 25, kilometros, &aLatam, &bLatam, &cLatam, &dLatam);
		eAero = precioLatam - precioAerolineas;
		subMenu(kilometros, flagAero, flagLatam, precioAerolineas, precioLatam, aAero, bAero, cAero, dAero, eAero, aLatam, bLatam, cLatam, dLatam);
		printf(" SE HA REALIZADO LA CARGA FORZADA DE DATOS\n\n");
		}
		else{
			printf("HUBO UN ERROR EN LA CARGA FORZADA\n");
		}


		system("pause");
		break;
	case 6:
		printf("Adios!\n");
		salir = 'n';
		break;

	default:
		printf("Error.. opcion incorrecta\n");
		system("pause");
		fflush(stdin);
		break;
	}

	}while(salir=='s');


	return EXIT_SUCCESS;
}
