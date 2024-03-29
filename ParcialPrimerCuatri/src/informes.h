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
void iniciarCantidadDeJuegoEnCero(Salon lista_salon[],int len_salon);
int informe_salonPorId(Salon lista_salon[],int len_salon,Arcade lista_arcade[], int len_arcade);
void informe_listarArcadePorId(Arcade lista_arcade[],int len_arcade,Salon lista_salon[],int len_salon,int posicionId);
void informe_listarUnSoloSalonPoirId(Salon lista[],int indice);
void informe_imprimirArcadePorId(Arcade lista_arcade[],int len_arcade, Salon lista_salon[],int len_salon);
int maxSalon(Salon lista_salon[],int len_salon);
void informe_Max(Salon lista_salon[], int len_salon, Arcade lista_arcade[], int len_arcade);
float informe_recaudarPorFicha(Arcade lista_arcade[],int len_arcade,Salon lista_salon[], int len_salon);
int acumuladorDeFichas(Arcade lista_arcade[],int len_arcade,Salon lista_salon[], int len_salon,int indiceId);
int informe_juegoContadorArcade(Arcade list[],int len_arcade, char juego[],int *contador,int *indice);
void informe_imprimirContadorArcadePorJuego(Listajuegos lista_juegos[],int len_salon, Arcade lista_arcade[],int len_arcade);
int salon_bajaMenu(Salon lista[],int len,int indice,Arcade lista_arcade[],int len_arcade);
int salon_baja(Salon lista[],int len,Arcade lista_arcade[],int len_arcade);
int salonQueTieneArcade(Salon lista_salon[], int len_salon, Arcade lista_arcade[],int len_arcade,int indiceId);
int informe_SalonCompleto(Arcade lista_arcade[],int len_arcade,Salon lista_salon[],int len_salon,int*indiceRetorno);
void informe_ImprimirSalonCompleto(Arcade lista_arcade[],int len_arcade,Salon lista_salon[],int len_salon);
#endif /* INFORMES_H_ */
