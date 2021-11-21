/*
 * juegos.h
 *
 *  Created on: 21 nov. 2021
 *      Author: mati_
 */

#ifndef JUEGOS_H_
#define JUEGOS_H_
#include "LinkedList.h"
#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {


	char nombre[MAX_LEN];
}Juegos;
Juegos *new_juegosParametros(char* name);
int existeJuegosRepetidos(LinkedList * pList,char* pArc);
int juegos_setNombreJuego(Juegos* this,char* nombre);
int juegos_getNombreJuego(Juegos* this,char* nombre);



#endif /* JUEGOS_H_ */
