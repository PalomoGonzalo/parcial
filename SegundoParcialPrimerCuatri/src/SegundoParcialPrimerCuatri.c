/*
 ============================================================================
 Name        : SegundoParcialPrimerCuatri.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "arcade.h"
#include "funciones.h"
#include "parser.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* listaArcade;
	listaArcade=ll_newLinkedList();

	controller_loadFromText("arcades.csv", listaArcade);
	controller_List(listaArcade);
	list(listaArcade);
	printf("asd %d",MONO);
	return EXIT_SUCCESS;
}
