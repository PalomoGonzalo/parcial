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

	int option=0;

	do{
	       printf(" \nMenu:\n");
	         printf("1. imprimir arcades\n");
	         printf("2. Incoroporar Arcade\n");
	         printf("3. Modificar Arcade\n");
	         printf("4. Elimiar Arcade\n");
	         printf("5. Imprimir Arcades Ordenados Por Nombre\n");
	         printf("6. Generar Archivos con Juegos\n");
	         printf("7. Generar Archivos Con Arcades Multijugador (mas de 1 jugador)\n");
	         printf("8. Actualizar cantidad de fichas\n");
	         printf("9. Salir");
	    	utn_getInt(&option, "\ningrese una opcion \n", "error reingre \n", 1, 11, 3);
	        switch(option)
	        {
	            case 1:
	            	controller_List(listaArcade);
	                break;
	            case 2:
	                controller_add(listaArcade);
	                break;
	            	/*  case 3:
	            	controller_addEmployee(listaArcade);
	            	break;
	            case 4:
	            	if(ll_isEmpty(listaArcade)==0)
	            		controller_editEmployee(listaArcade);
	            	else
	            		printf("error cargue algo en la lista\n");
	            	break;
	            case 5:
	            	if(ll_isEmpty(listaArcade)==0)
	            		controller_removeEmployee(listaArcade);
	            	else
	            		printf("error cargue algo a la lista \n");
	            	break;
	            case 6:
	            	if(ll_isEmpty(listaArcade)==0)
	            	{
	            	 controller_ListEmployee(listaArcade);
	            	}
	            	else
	            		printf("no hay existe datos para listar \n");
	            	break;
	            case 7:
	            	if(ll_isEmpty(listaArcade)==0)
	            	{
	            	 controller_sortEmployee(listaArcade);
	            	 controller_ListEmployee(listaArcade);
	            	}
	            	else
	            		printf("no hay existe datos para ordenar \n");
	            	break;
	            case 8:
	            	if(ll_isEmpty(listaArcade)==0)
	            		controller_saveAsText("data.csv", listaArcade);
	            	else
	            		printf("no hay existe datos guardar \n");
	            	break;*/
	            case 9:
	            	ll_deleteLinkedList(listaArcade);
	            	option=9;
	            	puts("saliendo del programa\n");
	            	break;

	        }
	    }while(option != 9);
	return EXIT_SUCCESS;
}
