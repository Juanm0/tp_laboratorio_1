/*
 * tp_1.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Juan-PC
 */

#ifndef TP_1_H_
#define TP_1_H_

/**
 * @brief  Muestra el menu original, sin alreraciones, hasta que se le levantan las banderas
 *
 * @param flagX bandera que me sirve para saber si el usuario ingreso los kilometros (No ingresado = 0; si ingresado = 1)
 * @param km cuando la flagX = 1, el menu muestra los kilometros guardados en esta variable
 * @param flagYZ bandera que me sirve para saber que el usuario ingreso correctamente al menos 1 precio de alguna opcion (aerolinea o latam)
 * @param precioY precio de Aerolineas ingresado por el usuario
 * @param precioZ precio de Latam ingresado por el usuario
 * @param flagY bandera que me permite saber que el usuario ingreso Aerolineas (si flagY = 0; aparecera como [NO INGRESADO])
 * @param flagZ bandera que me permite saber que el usuario ingreso Latam (si flagZ = 0; aparecera como [NO INGRESADO])
 * @return int (retorna la opcion que ingresa el usuario)
 */
int menu(int flagX, float km, int flagYZ, float precioY, float precioZ, int flagY, int flagZ);

/**
 * @brief Una vez las banderas levantadas, solamente muestra el programa con las opciones que ingreso el usuario, sin el menu original
 *
 * @param km kilometros ingresados
 * @param flagY bandera para saber si el precio de Aerolineas fue ingresado, de no ser ingresado se pondra [NO INGRESADO]
 * @param flagZ bandera para saber si el precio de Latam fue ingresado, de no ser ingresado se pondra [NO INGRESADO]
 * @param precioY variable que guarda el el precio de Aerolineas para ser mostrado
 * @param precioZ variable que guarda el precio de Latam para ser mostrado
 * @param aeroA Opcion A de Aerolineas (muestra el valor ya calculado)
 * @param aeroB Opcion B de Aerolineas (muestra el valor ya calculado)
 * @param aeroC Opcion C de Aerolineas (muestra el valor ya calculado)
 * @param aeroD Opcion D de Aerolineas (muestra el valor ya calculado)
 * @param aeroE Esta variable solo se muestra cuando ambas flags (flagY y flagZ) valen 1, de no ser asi, no habra diferencia de precios
 * @param latamA Opcion A de Latam (muestra el valor ya calculado)
 * @param latamB Opcion B de Latam (muestra el valor ya calculado)
 * @param latamC Opcion C de Latam (muestra el valor ya calculado)
 * @param latamD Opcion D de Latam (muestra el valor ya calculado)
 * @return int (no retorna una opcion ingresada por el usuario, porque éste subMenu solo muestra los resultados)
 */
int subMenu(float km, int flagY, int flagZ, float precioY, float precioZ, float aeroA, float aeroB, float aeroC, float aeroD, float aeroE, float latamA, float latamB, float latamC, float latamD);

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

#endif /* TP_1_H_ */
