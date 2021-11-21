/*
 * arcade.h
 *
 *  Created on: 20 nov. 2021
 *      Author: mati_
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#define MAX_LEN 64
#define MONO 1
#define STEREO 2
#include "LinkedList.h"
typedef struct {

	int id;//ok
	int tipoDeSonido;
	int fichasMaxima;
	int cantidadDeJugadores;
	char nacionalidad[MAX_LEN];
	char nombreJuego[MAX_LEN];//ok
	char salonName[MAX_LEN];

}Arcade;
Arcade* arcade_new();
Arcade* arcade_newParametros(char* idStr,char* tipoSonido,char* fichasMaximas, char *cantidadDeJugadores,char * nacionalidad,char* nombreJuego,char* salonName,LinkedList* pArrayList,int * flag);
void arcade_delete(Arcade* this);
int arcade_getId(Arcade* this,int* id);
int arcade_setId(Arcade* this,int id);
int arcade_setIdTxt(Arcade* this, char* idTxt);
int arcade_getIdTxt(Arcade* this, char *idTxt);
int arcade_setNombreJuego(Arcade* this,char* nombre);
int arcade_getNombreJuego(Arcade* this,char* nombre);
int arcade_setNacionalidad(Arcade* this,char* nombre);
int arcade_getNacionalidad(Arcade* this,char* nombre);
int arcade_setSalonGame(Arcade* this,char* nombre);
int arcade_getSalonName(Arcade* this,char* nombre);
int arcade_setTipoDeSonido(Arcade* this,int sonido);
int arcade_getTipoDeSonido(Arcade* this,int* sonido);
int arcade_setFichasMaximas(Arcade* this,int fichas);
int arcade_getFichasMaximas(Arcade* this,int* fichas);
int arcade_setCantidadDeJugadores(Arcade* this,int jugadores);
int arcade_getCantidadDeJugadores(Arcade* this,int* jugadores);
int arcade_setTipoDeSonidoTxt(Arcade* this, char* txt);
int arcade_getTipoDeSonidoTxt(Arcade* this, char *txt);
int arcade_setFichasMaximasTxt(Arcade* this, char* txt);
int arcade_getFichasMaximasTxt(Arcade* this, char *txt);
int arcade_setCantidadDeJugadoresTxt(Arcade* this, char* txt);
int controller_nextId(LinkedList* pArrayList);
int arcade_getCantidadDeJugadoresTxt(Arcade* this, char *txt);
char arcade_reemplazarTipo(int tipo,char *retorno,int len);

#endif /* ARCADE_H_ */
