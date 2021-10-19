/*
 * informes.h
 *
 *  Created on: 18 oct. 2021
 *      Author: mati_
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "salon.h"
#include "arcade.h"
#include "funciones.h"
#include "juegos.h"
int verCantidadDeSalonHay(Arcade lista_arcade[],int len_arcade, Salon lista_salon[],int len_salon);
void informe_arcadeMasDeCuatro(Salon lista [],int len_salon,Arcade lista_arcade[],int len_arcade);
void informe_arcadeDosJugadores(Arcade lista[],int len_arcade,Salon lista_salon[],int len_salon);
int informe_salonPorId(Salon lista_salon[],int len_salon,Arcade lista_arcade[], int len_arcade);
void informe_listarArcadePorId(Arcade lista_arcade[],int len_arcade,Salon lista_salon[],int len_salon,int posicionId);
void informe_listarUnSoloSalonPoirId(Salon lista[],int indice);
int maxSalon(Salon lista_salon[],int len_salon);
void informe_Max(Salon lista_salon[], int len_salon, Arcade lista_arcade[], int len_arcade);
#endif /* INFORMES_H_ */
