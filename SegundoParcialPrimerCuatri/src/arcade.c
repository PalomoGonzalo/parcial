/*
 * arcade.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mati_
 */

#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "LinkedList.h"




Arcade* arcade_new()
{
	Arcade* pEmployee= malloc(sizeof(Arcade));
	return pEmployee;

}

Arcade* arcade_newParametros(char* idStr,char* tipoSonido,char* fichasMaximas, char *cantidadDeJugadores,char * nacionalidad,char* nombreJuego,char* salonName,LinkedList* pArrayList,int * flag)
{
	Arcade* auxArcade;
	auxArcade=arcade_new();
	*flag=1;
	int idAux;


	if(auxArcade!=NULL && idStr!=NULL && tipoSonido !=NULL && fichasMaximas!=NULL && cantidadDeJugadores!=NULL&& nacionalidad!=NULL && nombreJuego!=NULL&& salonName!=NULL)
	{

		idAux=controller_nextId(pArrayList);
		sprintf(idStr,"%d",idAux);
		if(arcade_setIdTxt(auxArcade, idStr)!=1)
		{
			*flag=0;
		}
		if(arcade_setTipoDeSonidoTxt(auxArcade, tipoSonido)!=1)
		{
			*flag=0;
		}
		if(arcade_setFichasMaximasTxt(auxArcade, fichasMaximas)!=1)
		{
			*flag=0;
		}
		if(arcade_setCantidadDeJugadoresTxt(auxArcade, cantidadDeJugadores)!=1)
		{
			*flag=0;
		}
		if(arcade_setNacionalidad(auxArcade, nacionalidad)!=1)
		{
			*flag=0;
		}
		if(arcade_setNombreJuego(auxArcade, nombreJuego)!=1)
		{
			*flag=0;
		}
		if(arcade_setSalonGame(auxArcade, salonName)!=1)
		{
			*flag=0;
		}



	}

	return auxArcade;


}

void arcade_delete(Arcade* this)
{
	if(this!=NULL)
	{
		free(this);

	}

}



int arcade_setId(Arcade* this,int id)
{
	 int retorno =-1;
	 if(this!=NULL && id>=0)
	 {
		 retorno=1;
		 this->id=id;
	 }

	 return retorno;

}
int arcade_getId(Arcade* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		retorno=1;
		*id=this->id;
	}

	return retorno;

}


int arcade_setIdTxt(Arcade* this, char* idTxt)
{
    int retorno = -1;
    if(this != NULL && idTxt!=NULL)
        if(esNumerico(idTxt))
        {
        	retorno=1;
           this->id=atoi(idTxt);
        }
    return retorno;
}


int arcade_getIdTxt(Arcade* this, char *idTxt)
{
	int retorno=-1;
	if(this!=NULL && idTxt!=NULL)
	{
		retorno=1;
		sprintf(idTxt,"%d",this->id);

	}

	return retorno;

}


int arcade_setNombreJuego(Arcade* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
			retorno=1;
			strncpy(this->nombreJuego,nombre,MAX_LEN);
	}

	return retorno;
}

int arcade_getNombreJuego(Arcade* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=1;
		strncpy(nombre,this->nombreJuego,MAX_LEN);


	}
	return retorno;
}

int arcade_setNacionalidad(Arcade* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(esSoloLetras(nombre))
		{
			retorno=1;
			strncpy(this->nacionalidad,nombre,MAX_LEN);

		}

	}

	return retorno;
}

int arcade_getNacionalidad(Arcade* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=1;
		strncpy(nombre,this->nacionalidad,MAX_LEN);


	}
	return retorno;
}


int arcade_setSalonGame(Arcade* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(esAlfaNumerico(nombre))
		{
			retorno=1;
			strncpy(this->salonName,nombre,MAX_LEN);

		}

	}

	return retorno;
}

int arcade_getSalonName(Arcade* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=1;
		strncpy(nombre,this->salonName,32);


	}
	return retorno;
}


int arcade_setTipoDeSonido(Arcade* this,int sonido)
{
	 int retorno =-1;
	 if(this!=NULL)
	 {
		 retorno=1;
		 this->tipoDeSonido=sonido;
	 }

	 return retorno;

}
int arcade_getTipoDeSonido(Arcade* this,int* sonido)
{
	int retorno=-1;
	if(this!=NULL && sonido!=NULL)
	{
		retorno=1;
		*sonido=this->tipoDeSonido;
	}

	return retorno;

}

int arcade_setFichasMaximas(Arcade* this,int fichas)
{
	 int retorno =-1;
	 if(this!=NULL&&fichas>0)
	 {
		 retorno=1;
		 this->fichasMaxima=fichas;
	 }

	 return retorno;

}
int arcade_getFichasMaximas(Arcade* this,int* fichas)
{
	int retorno=-1;
	if(this!=NULL && fichas!=NULL)
	{
		retorno=1;
		*fichas=this->fichasMaxima;
	}

	return retorno;

}

int arcade_setCantidadDeJugadores(Arcade* this,int jugadores)
{
	 int retorno =-1;
	 if(this!=NULL&&jugadores>0)
	 {
		 retorno=1;
		 this->cantidadDeJugadores=jugadores;
	 }

	 return retorno;

}
int arcade_getCantidadDeJugadores(Arcade* this,int* jugadores)
{
	int retorno=-1;
	if(this!=NULL && jugadores!=NULL)
	{
		retorno=1;
		*jugadores=this->cantidadDeJugadores;
	}

	return retorno;

}

int arcade_setTipoDeSonidoTxt(Arcade* this, char* txt)
{
    int retorno = -1;
    int tipo;
    if(this != NULL && txt!=NULL)
    {
        if(strnicmp("MONO",txt,MAX_LEN)==0)
        {
        	tipo=2;
           this->tipoDeSonido=tipo;
           retorno=1;
		}
		if(strnicmp("STEREO",txt,MAX_LEN)==0)
		{
			tipo=1;
		   this->tipoDeSonido=tipo;
		   retorno=1;
		}
    }
    return retorno;
}


int arcade_getTipoDeSonidoTxt(Arcade* this, char *txt)
{
	int retorno=-1;
	if(this!=NULL && txt!=NULL)
	{
		retorno=1;
		sprintf(txt,"%d",this->tipoDeSonido);

	}

	return retorno;

}

int arcade_setFichasMaximasTxt(Arcade* this, char* txt)
{
    int retorno = -1;
    if(this != NULL && txt!=NULL)
        if(esNumerico(txt))
        {
        	retorno=1;
           this->fichasMaxima=atoi(txt);
        }
    return retorno;
}


int arcade_getFichasMaximasTxt(Arcade* this, char *txt)
{
	int retorno=-1;
	if(this!=NULL && txt!=NULL)
	{
		retorno=1;
		sprintf(txt,"%d",this->fichasMaxima);

	}

	return retorno;

}

int arcade_setCantidadDeJugadoresTxt(Arcade* this, char* txt)
{
    int retorno = -1;
    if(this != NULL && txt!=NULL)
        if(esNumerico(txt))
        {
        	retorno=1;
           this->cantidadDeJugadores=atoi(txt);
        }
    return retorno;
}


int arcade_getCantidadDeJugadoresTxt(Arcade* this, char *txt)
{
	int retorno=-1;
	if(this!=NULL && txt!=NULL)
	{
		retorno=1;
		sprintf(txt,"%d",this->cantidadDeJugadores);

	}

	return retorno;

}
int controller_nextId(LinkedList* pArrayList)
{
    int retorno = -1;
    int i;
    int idAux;
    int idMax=0;
    Arcade *pAux;
    if(pArrayList != NULL)
    {
        for(i=0;i<ll_len(pArrayList);i++)
        {
            pAux = ll_get(pArrayList, i);
            if(i == 0)
            {
                arcade_getId(pAux, &idMax);
            }
            else
            {
                arcade_getId(pAux, &idAux);
                if(idAux > idMax)
                {
                    idMax = idAux;
                }
            }
        }
        retorno = idMax+1;
    }
    return retorno;

}
char arcade_reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[MAX_LEN];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"STEREO",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"MONO",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}
