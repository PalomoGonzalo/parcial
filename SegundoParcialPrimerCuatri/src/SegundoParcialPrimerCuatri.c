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

	LinkedList* listaArcade=ll_newLinkedList();

	LinkedList* listaJuegos=ll_newLinkedList();
	LinkedList* listaFiltradaMultijugador=ll_newLinkedList();


	controller_loadFromText("arcades.csv", listaArcade);
	LinkedList* listaParaOrdenar=ll_newLinkedList();
	listaParaOrdenar=ll_clone(listaArcade);
	listaFiltradaMultijugador=ll_clone(listaArcade);

	int option=0;

	do{
			 listaJuegos=filtrarJuegos(listaArcade);
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
	                controller_saveAsText("arcades.csv", listaArcade);
	                break;
	            case 3:

	            	controller_editArcade(listaArcade, listaJuegos);
	            	controller_saveAsText("arcades.csv", listaArcade);
	            	break;
	            case 4:
	            	controller_deleteArcade(listaArcade);
	            	controller_List(listaArcade);
	            	break;
	            case 5:
	            	controller_sortArcade(listaParaOrdenar);
	            	controller_List(listaParaOrdenar);

	            	break;
	           case 6:
	            	controller_listJuegos(listaJuegos);
	            	controller_saveAsTextJuegos("juegos.txt", listaJuegos);
	            	break;
	           case 7:
	            	ll_filter(listaFiltradaMultijugador, controller_filtrarJugadores);
	            	controller_saveAsText("multijugador.csv", listaFiltradaMultijugador);
	            	controller_List(listaFiltradaMultijugador);
	            	break;
	           case 8:
	        	   	  ll_map(listaArcade, controller_actualizarFichas);
	        	   	  controller_List(listaArcade);
	            	break;
	            case 9:
	            	ll_deleteLinkedList(listaArcade);
	            	option=9;
	            	puts("saliendo del programa\n");
	            	break;

	        }
	    }while(option != 9);
	return EXIT_SUCCESS;
}
