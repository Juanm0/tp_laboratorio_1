/*
 * calculos_tp1.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Juan-PC
 */


#include <stdio.h>
#include <stdlib.h>



float calcularPorcentajeFloatPositivos(float numero, int tipo, float cantidad){

	float resultado;
	resultado = -1;
	if(tipo == 1 && cantidad > 0 && numero > 0){//Si el tipo es 1, se hace un aumento
		resultado = numero + (numero * cantidad / 100.00);
	}//La cantidad es el valor que tiene ese aumento o descuento
	if(tipo == 0 && cantidad > 0 && numero > 0){//Si el tipo es 0, se hace un descuento
		resultado = numero - (numero * cantidad / 100.00);
	}
	return resultado;//si el resultado es -1 es porque hubo error
}

int calculosOpcion_3_TP1(float precio, int tipoA, float cantidadA, float tipoB, float cantidadB, float km, float* opcionA, float* opcionB, float* opcionC, float* opcionD){

	int retorno;
	retorno = -1;
	if(opcionA != NULL && opcionB != NULL && opcionC != NULL && opcionD != NULL && km >= 0 && precio > 0 &&
		cantidadA > 0 && cantidadB > 0 && (tipoA == 0 || tipoA == 1) && (tipoB == 0 || tipoB == 1)){
//Luego de verificar que todas las opciones esten bien, realiza los calculos solicitados en orden
	*opcionA = calcularPorcentajeFloatPositivos(precio,tipoA,cantidadA);
	*opcionB = calcularPorcentajeFloatPositivos(precio,tipoB,cantidadB);
	*opcionC = precio / 4606954.55;
	if(km == 0) {
		*opcionD = -1;
	}else{
		*opcionD = precio / km;
	}

	if(!(*opcionA == -1 || *opcionB == -1)){//El retorno solo podra ser 0 si no hubo error en los calculos
		retorno = 0;
		}
	}
	return retorno;//Retorno -1 significa que algo salio mal
}

float calcularDiferenciaDePrecios(float precioLatam, float precioAero) {

	float difPrecio;
	difPrecio = (precioLatam - precioAero);
	if(difPrecio < 0){
		difPrecio = difPrecio * -1;
	}

	return difPrecio;
}
