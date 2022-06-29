/*
 * calculos_tp1.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Juan-PC
 */

#ifndef CALCULOS_TP1_H_
#define CALCULOS_TP1_H_

/**
 * @brief Funcion que permite calcular el porcentaje de un numero float positivo
 *
 * @param numero float positivo mayor a 0
 * @param tipo esta variable nos permite saber si se trata de un descuento o un interes (descuento = 0; interes = 1)
 * @param cantidad  variable que me permite saber que valor tiene ese descuento o interes
 * @return resultado, como solo permite positivos, si el resultado es -1, es porque hubo error
 */
float calcularPorcentajeFloatPositivos(float numero, int tipo, float cantidad);

/**
 * @brief Esta funcion realiza los calculos de la opcion 3 de manera ordenada y simple
 *
 * @param precio le podemos ingresar un precio, ya sea de Latam o Aerolineas
 * @param tipoA variable necesaria para saber que estamos ante un descuento o un interes[opcion a] (descuento = 0; interes = 1)
 * @param cantidadA  variable que me permite saber que valor tiene ese descuento o interes [opcion a]
 * @param tipoB variable necesaria para saber que estamos ante un segundo descuento o interes [opcion b](descuento = 0; interes = 1)
 * @param cantidadB  variable que me permite saber que valor tiene ese descuento o interes [opcion b]
 * @param km variable que guarda los kilometros con los que desea realizar los calculos
 * @param opcionA variable que guarda el dato calculado A en la direccion de memoria que le insertamos
 * @param opcionB variable que guarda el dato calculado B en la direccion de memoria que le insertamos
 * @param opcionC variable que guarda el dato calculado C en la direccion de memoria que le insertamos
 * @param opcionD variable que guarda el dato calculado D en la direccion de memoria que le insertamos
 * @return
 */
int calculosOpcion_3_TP1(float precio, int tipoA, float cantidadA, float tipoB, float cantidadB, float km, float* opcionA, float* opcionB, float* opcionC, float* opcionD);
/**
 * @brief calcula la diferencia de precios
 *
 * @param precioLatam
 * @param precioAero
 * @return retorna la diferencia de precios en positivo
 */
float calcularDiferenciaDePrecios(float precioLatam, float precioAero);

#endif /* CALCULOS_TP1_H_ */
