/*
 * juegos.h
 *
 *  Created on: 18 oct. 2021
 *      Author: mati_
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef JUEGOS_H_
#define JUEGOS_H_
	typedef struct {

		char nombreJuego[32];// 0 lcd 1 plasma
		int flagEmpty;
	}Listajuegos;

int juegos_init(Listajuegos lista[],int len);
int juegos_estaEnArcade(Listajuegos list[],int len, char juego[]);

#endif /* JUEGOS_H_ */
