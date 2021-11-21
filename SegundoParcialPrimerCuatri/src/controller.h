/*
 * controller.h
 *
 *  Created on: 20 nov. 2021
 *      Author: mati_
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int controller_listOne(LinkedList* pArrayList,int indice);
int controller_add(LinkedList* pList);
#endif /* CONTROLLER_H_ */
