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
#include "juegos.h"


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

	printf("\nid:\t nacionalidad:\t tipo:\t cantJug:\t fichasMax:\t salon :\t game :\t ");
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
			printf("\n%d\t%8s\t%6s\t%9d\t%9d\t%9s\t%9s",id,nacionalidad,auxTipo,cantJug,fichasMax,salonGame,game);
		}
	}
   return 1;
}

int controller_listJuegos(LinkedList* pArrayList)
{
	char juegos[MAX_LEN];
	Juegos* pAux;

	if(pArrayList!=NULL)
	{
		puts("LISTA DE JUEGOS NO REPETIDOS\n");
		for(int i=0;i<ll_len(pArrayList);i++)
		{
			pAux=ll_get(pArrayList, i);
			juegos_getNombreJuego(pAux, juegos);

			printf("%s\n",juegos);

		}
	}
	return 1;
}
int controller_listOne(LinkedList* pArrayList,int indice)
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

	printf("\nid:\t nacionalidad:\t tipo:\t cantJug:\t fichasMax:\t salon :\t game :\t ");
	if(pArrayList!=NULL)
	{

			pAux = ll_get(pArrayList,indice);
			arcade_getId(pAux, &id);
			arcade_getNacionalidad(pAux, nacionalidad);
			arcade_getTipoDeSonido(pAux, &tipoSonido);
			arcade_getCantidadDeJugadores(pAux, &cantJug);
			arcade_getFichasMaximas(pAux, &fichasMax);
			arcade_getSalonName(pAux, salonGame);
			arcade_getNombreJuego(pAux, game);
			arcade_reemplazarTipo(tipoSonido, auxTipo, sizeof(auxTipo));
			printf("\n%d\t%8s\t%6s\t%9d\t%9d\t%9s\t%9s",id,nacionalidad,auxTipo,cantJug,fichasMax,salonGame,game);

	}
   return 1;

}

int arcade_findById(LinkedList* pArray,int id, int* indiceDeId)
{
	int retorno=-1;
	Arcade *pAux;
	int idAux;

	if(pArray!=NULL&&indiceDeId!=NULL)
	{
		for(int i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray, i);
			if(pAux!=NULL)
			{
				arcade_getId(pAux, &idAux);
				if(idAux==id)
				{
					*indiceDeId=i;
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;
}


int controller_add(LinkedList* pList)
{
	int retorno=-1;
	char idChar[MAX_LEN];
	char tipoDeSonido[MAX_LEN];
	char fichasMaximas[MAX_LEN];
	char cantidadDeJugadores[MAX_LEN];
	char nacionalidad[MAX_LEN];
	char nombreJuego[MAX_LEN];
	char salonName[MAX_LEN];
	int tipoAux;
	int flag;
	Arcade* aux;

	if(pList!=NULL)
	{
		getString("\nIngrese su nacionalidad\n", nacionalidad);
		utn_getInt(&tipoAux, "\ningrese el tipo de sonido\n1-ESTEREO\n2-MONO\n", "Error ingrese 1 o 2\n", 1, 2, 6);
		arcade_reemplazarTipo(tipoAux, tipoDeSonido, sizeof(tipoDeSonido));

		getIntString("\ningrese capacidad maxima de fichas\n", fichasMaximas);
		getIntString("ingrese cantidad de jugadores\n", cantidadDeJugadores);
		getStringAlfa("\ningrese nombre de salon al que pertence\n", salonName);
		getStringAlfa("\ningrese nombre del juego que contiene \n", nombreJuego);

		aux=arcade_newParametros(idChar, tipoDeSonido, fichasMaximas, cantidadDeJugadores, nacionalidad, nombreJuego, salonName, pList, &flag);

		if(flag==1)
		{

			ll_add(pList, aux);
			retorno=1;
		}
	}
	return retorno;
}



int controller_editArcade(LinkedList* pArray, LinkedList* pJuegos)
{
	int retorno=-1;
	Arcade* pAux=NULL;
	int id;
	int existeId;
	int indiceId;

	if(pArray!=NULL)
	{
		controller_List(pArray);
		utn_getInt(&id, "\ningrese el id que desea modificar\n", "Error reingrese un numero valido \n", 1, 111111, 3);
		existeId=arcade_findById(pArray, id, &indiceId);
		if(existeId==1)
		{
			printf("\neste es el arcade que va a modificar\n");
			controller_listOne(pArray, indiceId);
			controller_menuEditArcade(pAux, pArray, indiceId, pJuegos);
			printf("\nse modifico correctamente\n");
		}
		else
		{

			printf("no existe el id \n");
		}



	}

    return retorno;
}

int controller_menuEditArcade(Arcade* pAux,LinkedList* pArray,int indiceId,LinkedList* pJuegos)
{
	int opcion;
	char auxNombre[32];
	int cantJug;
	printf("\nQue desea modificar\n");
	puts("\n1-CANTIDAD DE JUGADORES \n2-NOMBRE DEL JUEGO\n3-Salir\n ");
	utn_getInt(&opcion, "\ningrese una opcion\n", "error reingrese numeros validos \n", 1, 4, 4);
	pAux=ll_get(pArray, indiceId);
	switch(opcion)
	{
	case 1:
		utn_getInt(&cantJug, "ingrese la nueva cantidad de jugadores \n", "Error ingrese un numero valido", 1, 999, 4);
		arcade_setCantidadDeJugadores(pAux, cantJug);
		break;
	case 2:
		controller_listJuegos(pJuegos);
		getStringAlfa("ingrese nuevo nombre de juego\n", auxNombre);
		arcade_setNombreJuego(pAux, auxNombre);
		break;
	case 3:
		break;

	}
	ll_set(pArray, indiceId, pAux);


	return 1;
}





LinkedList* filtrarJuegos(LinkedList* pLista)
{
	LinkedList* listAux;
	listAux=ll_newLinkedList();

	Arcade * pAux;
	Juegos* pJuegos;
	char nombre[MAX_LEN];
	for(int i=0;i<ll_len(pLista);i++)
	{
		pAux=(Arcade*)ll_get(pLista, i);
		arcade_getNombreJuego(pAux, nombre);
		if(existeJuegosRepetidos(listAux, nombre)==0)
		{
			pJuegos=new_juegosParametros(nombre);
			ll_add(listAux, pJuegos);
		}
	}
return listAux;

}

int controller_deleteArcade(LinkedList* list)
{
	Arcade *pArc=NULL;
	int id;
	int existeId;
	int indiceId;
	if(list!=NULL)
	{
		controller_List(list);
		utn_getInt(&id, "\nIngrese el id que desea borrar", "error reingrese un id valido \n", 1, 111111, 4);
		existeId=arcade_findById(list, id, &indiceId);
		if(existeId==1)
		{
			controller_menuRemoveArcade(list, pArc, indiceId);
		}
		else
		{
			printf("no existe el id \n");
		}

	}


    return 1;
}
int controller_menuRemoveArcade(LinkedList* pList,Arcade* pArc,int indiceId)
{
	int opcion;
	utn_getInt(&opcion, "\nEsta seguro que desea borrar este arcade\n1-Para eliminar\n2-Para cancelar\n", "Error ingrese numeros validos\n", 1, 2, 4);
	if(opcion==1)
	{

		if(pList!=NULL)
		{
			pArc=ll_get(pList, indiceId);
			ll_remove(pList, indiceId);
			arcade_delete(pArc);
			printf("se dio de baja\n");
		}
	}
	else
	{
		printf("la operacion se cancelo \n");
	}
	return 1;
}

int ordenarPorNombre(void* arcadeA, void* arcadeB)
{
    int retorno = 0;
    Arcade* empA=(Arcade*) arcadeA;
    Arcade* empB=(Arcade*) arcadeB;
    if(arcadeA !=NULL && arcadeB !=NULL)
    {
        retorno = stricmp(empB->nombreJuego, empA->nombreJuego);
    }
    return retorno;
}


int controller_sortArcade(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		ll_sort(pArrayListEmployee, ordenarPorNombre, 1);

	}
    return 1;
}

int controller_saveAsText(char* path , LinkedList* pArray)
{
    FILE* pArchivo;
    Arcade* pArcade;
    int retorno = -1;
    char game[MAX_LEN];
    int id;
    int tipoSonido;
    int cantJugadores;
    int fichasMax;
    char nacionalidad[MAX_LEN];
    char salonName[MAX_LEN];

    pArchivo = fopen(path, "w");
    if(pArchivo != NULL && pArray != NULL)
    {
        rewind(pArchivo);
        fprintf(pArchivo, "id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
        for(int i=0; i<ll_len(pArray); i++)
        {
        	pArcade = (Arcade*)ll_get(pArray, i);
            arcade_getId(pArcade, &id);
            arcade_getNacionalidad(pArcade, nacionalidad);
            arcade_getTipoDeSonido(pArcade, &tipoSonido);
            arcade_getCantidadDeJugadores(pArcade, &cantJugadores);
            arcade_getFichasMaximas(pArcade, &fichasMax);
            arcade_getSalonName(pArcade, salonName);
            arcade_getNombreJuego(pArcade, game);
            fprintf(pArchivo, "%d,%s,%d,%d,%d,%s,%s\n", id, nacionalidad, tipoSonido, cantJugadores,fichasMax,salonName,game);
        }
        printf("\n --> Datos guardados con exito.\n\n");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}



int controller_saveAsTextJuegos(char* path , LinkedList* pArray)
{
    FILE* pArchivo;
    Juegos* pJuegos;
    int retorno = -1;
    char game[MAX_LEN];
    pArchivo = fopen(path, "w");
    if(pArchivo != NULL && pArray != NULL)
    {
    	rewind(pArchivo);// PRIMERA POSICION
        fprintf(pArchivo, "LISTA DE JUEGOS SIN REPETIR\n");
        for(int i=0; i<ll_len(pArray); i++)
        {
        	pJuegos = (Juegos*)ll_get(pArray, i);
        	juegos_getNombreJuego(pJuegos, game);
            fprintf(pArchivo, "%s\n" ,game);
        }
        printf("\n --> Datos guardados con exito.\n\n");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}



int controller_filtrarJugadores(void *a)
{
	int retorno=0;
	if(((Arcade*)a)->cantidadDeJugadores>4)
	{
		retorno=1;
	}

	return retorno;
}

int controller_actualizarFichas(void *a)
{
	int nuevasFichas;
	arcade_getFichasMaximas((Arcade*)a, &nuevasFichas);

	arcade_setFichasMaximas((Arcade*)a,nuevasFichas*2 );


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
