/*
 ============================================================================
 Name        : ParcialPrimerCuatri.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "salon.h"
#include "arcade.h"
#include "juegos.h"
#include "informes.h"
#define LEN_SALON 100
#define LEN_ARCADE 1000

int main(void) {

	setbuf(stdout, NULL);
	char seguir='s';
	int opcion;
	int retornoAdd=1;
	int test;
	int opcionInformar;
	Salon lista_salon[LEN_SALON];
	salon_inicializarArray(lista_salon, LEN_SALON);

	Arcade lista_arcade[LEN_ARCADE];
	arcade_inicializarArray(lista_arcade, LEN_ARCADE);

	Listajuegos lista_juegos[LEN_SALON];

	salon_altaHardcodeada(lista_salon, "matias", "av la plata", 1, LEN_SALON, 0);
	salon_altaHardcodeada(lista_salon, "gonzalo", "av belgrano", 2, LEN_SALON, 1);
	salon_altaHardcodeada(lista_salon, "lucas", "mexico", 2, LEN_SALON, 2);
	salon_altaHardcodeada(lista_salon, "lia", "salta", 1, LEN_SALON, 3);
	salon_altaHardcodeada(lista_salon, "mia", "rosario", 2, LEN_SALON, 4);
	salon_altaHardcodeada(lista_salon, "kira", "venezuela", 1, LEN_SALON, 5);
//                                     nombreJueg nacionalidad,int tipoSonido,int fichas,int idSalon,int cantJugadores,int len,int indice)
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 0);
	arcade_altaHardcodeada(lista_arcade, "APEX", "brasil", 2, 7, 4, 1, LEN_ARCADE, 1);
	arcade_altaHardcodeada(lista_arcade, "HADES", "chile", 1, 2, 5, 1, LEN_ARCADE, 2);
	arcade_altaHardcodeada(lista_arcade, "CSGO", "espa�a", 1, 12, 5, 2, LEN_ARCADE, 3);
	arcade_altaHardcodeada(lista_arcade, "DOOM", "grecia", 1, 12, 5, 2, LEN_ARCADE, 4);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 5, 2, 2, LEN_ARCADE, 5);
	arcade_altaHardcodeada(lista_arcade, "CSGO", "espa�a", 1, 12, 5, 2, LEN_ARCADE, 6);
	arcade_altaHardcodeada(lista_arcade, "t1",  "espa�a", 1, 10, 5, 5, LEN_ARCADE, 7);
	arcade_altaHardcodeada(lista_arcade, "t2",  "argent", 1, 10, 5, 8, LEN_ARCADE, 8);
	arcade_altaHardcodeada(lista_arcade, "t3",  "argent", 1, 10, 5, 4, LEN_ARCADE, 9);
	arcade_altaHardcodeada(lista_arcade, "t4",  "argent", 1, 10, 5, 3, LEN_ARCADE, 10);
	arcade_altaHardcodeada(lista_arcade, "t5",  "argent", 1, 10, 5, 7, LEN_ARCADE, 11);
	arcade_altaHardcodeada(lista_arcade, "t6",  "argent", 1, 10, 5, 7, LEN_ARCADE, 12);
	arcade_altaHardcodeada(lista_arcade, "t7",  "argent", 1, 10, 5, 7, LEN_ARCADE, 13);
	arcade_altaHardcodeada(lista_arcade, "t8",  "argent", 1, 10, 5, 7, LEN_ARCADE, 14);
	arcade_altaHardcodeada(lista_arcade, "t9",  "argent", 1, 10, 5, 7, LEN_ARCADE, 15);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 16);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 17);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 18);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 19);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 20);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 21);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 22);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 23);




	do{
			utn_getInt(&opcion, "\n 1-Alta salon\n 2-baja salon \n 3-Imprimir Salon \n 4-Alta arcade\n 5-Modificar Arcade\n 6-Eliminar Arcade \n 7-Imprimir Arcade\n 8-Imprimir Juegos \n 9-Informes \n 10-Salir\n", "error ingrese numeros validos", 1, 11, 8);
			switch(opcion)
					{
					case 1:
						retornoAdd=salon_alta(lista_salon, LEN_SALON);
						break;
					case 2:
						if(retornoAdd==1)
							salon_baja(lista_salon, LEN_SALON,lista_arcade,LEN_ARCADE);
						else
							printf("no hay datos cargados \n");
						break;
					case 3:
						salon_mostrarStructura(lista_salon, LEN_SALON);
						break;
					case 4:
						if(retornoAdd==1)
							{
							arcade_alta(lista_arcade, LEN_ARCADE, lista_salon, LEN_SALON);
							}
						else
							printf("no hay datos cargados \n");
						break;
					case 5:
							arcade_modificar(lista_arcade, LEN_ARCADE, lista_juegos, LEN_SALON);
						break;

					case 6:
						if(retornoAdd==1)
							{
								arcade_Baja(lista_arcade, LEN_ARCADE);
							}
						else
							{
								printf("no hay datos cargados \n");
							}
						break;
					case 7:
						arcade_mostrarStructura(lista_arcade, LEN_ARCADE);
						break;
					case 8:
						generListaJuegos(lista_juegos, LEN_SALON, lista_arcade, LEN_ARCADE);
						juegos_mostrarStructura(lista_juegos, LEN_SALON);
						break;
					case 9:
						utn_getInt(&opcionInformar, "\n 1-Listar salones con 4 arcades\n 2-Listar Arcades para mas de dos jugadores \n 3-Imprimir Salon por id \n 4-Listar Arcades Por id Salon\n 5-Salon con mas cantidad de Arcades\n 6-monto maximo que puede recuadar el salon \n 7-Imprimir arcades por nombre de juego\n 8-Salon Completo", "error ingrese numeros validos", 1, 11, 8);
						switch(opcionInformar)
						{
							case 1:
								informe_arcadeMasDeCuatro(lista_salon, LEN_SALON, lista_arcade, LEN_ARCADE);
								break;
							case 2:
								informe_arcadeDosJugadores(lista_arcade, LEN_ARCADE, lista_salon, LEN_SALON);
								break;
							case 3:
								informe_salonPorId(lista_salon, LEN_SALON, lista_arcade, LEN_ARCADE);
								break;
							case 4:
								salon_mostrarStructura(lista_salon, LEN_SALON);
								informe_imprimirArcadePorId(lista_arcade, LEN_ARCADE, lista_salon, LEN_SALON);
								break;
							case 5:
								informe_Max(lista_salon, LEN_SALON, lista_arcade, LEN_ARCADE);
								break;
							case 6:
								salon_mostrarStructura(lista_salon, LEN_SALON);
								informe_recaudarPorFicha(lista_arcade, LEN_ARCADE, lista_salon, LEN_SALON);
								break;
							case 7:
								informe_imprimirContadorArcadePorJuego(lista_juegos, LEN_SALON, lista_arcade, LEN_ARCADE);
								break;
							case 8:
								//informe_ImprimirSalonCompleto(lista_arcade, LEN_ARCADE, lista_salon, LEN_SALON);

								informe_SalonCompleto(lista_arcade, LEN_ARCADE, lista_salon, LEN_SALON, &test);
								break;




						}



						break;
					case 10:
						seguir='n';
						break;
					}
		}while(seguir=='s');
	return EXIT_SUCCESS;
}
