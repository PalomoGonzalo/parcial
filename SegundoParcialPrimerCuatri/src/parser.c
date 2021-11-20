/*
 * parser.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mati_
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arcade.h"
#include "parser.h"
#include "funciones.h"
#include <ctype.h>


int parser_arcadeFromText(FILE* pFile , LinkedList* pArrayList)
{

	int retorno=-1;
	Arcade* pArcadeAux;
	char id[MAX_LEN];
	char tipoDeSonido[MAX_LEN];
	char fichasMaximas[MAX_LEN];
	char cantidadDeJugadores[MAX_LEN];
	char nacionalidad[MAX_LEN];
	char nombreJuego[MAX_LEN];
	char salonName[MAX_LEN];
	int result;
	int flag;


	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,tipoDeSonido,cantidadDeJugadores,fichasMaximas,salonName,nombreJuego); // salteo la 1era
		do
		{
			result=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,tipoDeSonido,cantidadDeJugadores,fichasMaximas,salonName,nombreJuego);
			if(result==7)
			{

				pArcadeAux = arcade_newParametros(id, tipoDeSonido, fichasMaximas, cantidadDeJugadores, nacionalidad, nombreJuego, salonName, pArrayList, &flag);

				if(pArcadeAux!=NULL)
				{

					retorno=1;
					ll_add(pArrayList,pArcadeAux);

				}
			}
			else
			{
				arcade_delete(pArcadeAux);
				break;
			}

		}while( !feof(pFile));
	}
return retorno;
}
