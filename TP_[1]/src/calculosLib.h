/*
 * calculosLib.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Juan-PC
 */

#ifndef CALCULOSLIB_H_
#define CALCULOSLIB_H_

/**
 * @brief Funcion que permite calcular el porcentaje de un numero float positivo
 *
 * @param numero float positivo mayor a 0
 * @param tipo esta variable nos permite saber si se trata de un descuento o un interes (descuento = 0; interes = 1)
 * @param cantidad  variable que me permite saber que valor tiene ese descuento o interes
 * @return resultado, como solo permite positivos, si el resultado es -1, es porque hubo error
 */
float calcularPorcentajeFloatPositivos(float numero, int tipo, float cantidad);

#endif /* CALCULOSLIB_H_ */
