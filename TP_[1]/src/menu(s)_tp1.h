/*
 * menu(s)_tp1.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Juan-PC
 */

#ifndef MENU_S__TP1_H_
#define MENU_S__TP1_H_


/**
 * @brief Muestra el menu original, sin alreraciones, hasta que se ingresen datos
 *
 * @param km  los kilometros se guardan en esta variable (cuando es 0, los km son X)
 * @param precioY precio de Aerolineas ingresado por el usuario
 * @param precioZ  precio de Latam ingresado por el usuario
 * @return int (retorna la opcion que ingresa el usuario)
 */
int menu(float km, float precioY, float precioZ);

/**
 * @brief Submenu para mostrar los precios
 *
 * @param opADebito
 * @param opBCredito
 * @param opCBitcoin
 * @param opDKmUnitario
 */
void mostrarPrecios(float opADebito, float opBCredito, float opCBitcoin, float opDKmUnitario);

#endif /* MENU_S__TP1_H_ */
