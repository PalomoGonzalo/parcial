/*
 * juegos.c
 *
 *  Created on: 21 nov. 2021
 *      Author: mati_
 */

#include "juegos.h"
#include <string.h>

Juegos *new_juegosParametros(char* name)
{
	Juegos* auxJuegos=malloc(sizeof(Juegos));

	if(auxJuegos!=NULL&&name!=NULL)
	{
		juegos_setNombreJuego(auxJuegos, name);

	}
	return auxJuegos;

}

int existeJuegosRepetidos(LinkedList * pList,char* pArc)
{
	Juegos* aux;

	int retorno=0;
	char nombre[MAX_LEN];
	if(pList!=NULL&&pArc!=NULL)
	{

		for(int i=0;i<ll_len(pList);i++)
		{
			aux=(Juegos*)ll_get(pList, i);
			juegos_getNombreJuego(aux, nombre);

			if(aux!=NULL)
			{
				if(strnicmp(nombre,pArc,MAX_LEN)==0)
				{
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;

}
int juegos_setNombreJuego(Juegos* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
			retorno=1;
			strncpy(this->nombre,nombre,MAX_LEN);
	}

	return retorno;
}

int juegos_getNombreJuego(Juegos* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=1;
		strncpy(nombre,this->nombre,MAX_LEN);


	}
	return retorno;
}
