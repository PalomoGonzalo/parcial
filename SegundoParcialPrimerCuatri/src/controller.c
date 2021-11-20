/*
 * controller.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mati_
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arcade.h"
#include "parser.h"
#include "Controller.h"
#include "funciones.h"


int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int retorno=-1;

	FILE* pFile=fopen(path,"r");

	if(pFile!=NULL)
	{

		if(path!=NULL && pArrayList!=NULL)
		{

			parser_arcadeFromText(pFile, pArrayList);
			retorno=1;

			printf("\nSe cargo con exito la lista\n");
		}
		else
			printf("no se puedo cargar la lista\n");
	}

	fclose(pFile);

    return retorno;
}
int controller_List(LinkedList* pArrayList)
{
	Arcade * pAux;
	int id;
	char nacionalidad[MAX_LEN];
	int tipoSonido;
	char auxTipo[58];
	int cantJug;
	int fichasMax;
	char salonGame[MAX_LEN];
	char game[MAX_LEN];

	printf("id:\nacionalidad:\t      tipo:\t cantJug:\t fichasMax:\t salon :\t game :\t ");
	if(pArrayList!=NULL)
	{

	   for(int i=0; i<ll_len(pArrayList); i++)
		{

			pAux = ll_get(pArrayList,i);
			arcade_getId(pAux, &id);
			arcade_getNacionalidad(pAux, nacionalidad);
			arcade_getTipoDeSonido(pAux, &tipoSonido);
			arcade_getCantidadDeJugadores(pAux, &cantJug);
			arcade_getFichasMaximas(pAux, &fichasMax);
			arcade_getSalonName(pAux, salonGame);
			arcade_getNombreJuego(pAux, game);
			arcade_reemplazarTipo(tipoSonido, auxTipo, sizeof(auxTipo));
			printf("\n%d\t%8s\t%6s\t%4d\t%4d\t%9s\t%9s",id,nacionalidad,auxTipo,cantJug,fichasMax,salonGame,game);
		}
	}
   return 1;
}


int list(LinkedList* list)
{
	Arcade * pAux;
	int id;
	for(int i=0; i<ll_len(list); i++)
	{
		pAux = ll_get(list,i);
		arcade_getId(pAux, &id);
		printf("%d\n",id);

	}



return 1;

}


/*int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    FILE* pArchivo;
    Arcade* pAux;
    int retorno = -1;
    char nombre[51];
    int id;
    int horasTrabajadas;
    int sueldo;

    pArchivo = fopen(path, "w");
    if(pArchivo != NULL && pArrayList != NULL)
    {
        rewind(pArchivo);
        fprintf(pArchivo, "id,nacionalidad,tipo_sonido,sueldo\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
        	pAux = (Arcade*)ll_get(pArrayList, i);
            employee_getId(pAux,&id);
            employee_getNombre(pAux, nombre);
            employee_getHorasTrabajadas(pAux, &horasTrabajadas);
            employee_getSueldo(pAux, &sueldo);
            fprintf(pArchivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
        }
        printf("\n --> Datos guardados con exito.\n\n");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}
*/
