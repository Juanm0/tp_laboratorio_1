/*
 * calculosLib.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Juan-PC
 */


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
