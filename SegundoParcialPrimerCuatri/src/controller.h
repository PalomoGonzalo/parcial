/*
 * controller.h
 *
 *  Created on: 20 nov. 2021
 *      Author: mati_
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "arcade.h"

int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int controller_listOne(LinkedList* pArrayList,int indice);
int controller_add(LinkedList* pList);
LinkedList* filtrarJuegos(LinkedList* pLista);
int controller_listJuegos(LinkedList* pArrayList);
int controller_deleteArcade(LinkedList* list);
int controller_menuRemoveArcade(LinkedList* pList,Arcade* pArc,int indiceId);

int controller_menuEditArcade(Arcade* pAux,LinkedList* pArray,int indiceId,LinkedList* pJuegos);
int controller_editArcade(LinkedList* pArray, LinkedList* pJuegos);
int ordenarPorNombre(void* arcadeA, void* arcadeB);
int controller_sortArcade(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArray);
int controller_saveAsTextJuegos(char* path , LinkedList* pArray);
int controller_filtrarJugadores(void *a);
int controller_actualizarFichas(void *a);
#endif /* CONTROLLER_H_ */
