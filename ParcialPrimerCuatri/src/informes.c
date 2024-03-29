/*
 * informes.c
 *
 *  Created on: 18 oct. 2021
 *      Author: mati_
 */

#include "informes.h"

int salon_baja(Salon lista[],int len,Arcade lista_arcade[],int len_arcade)
{
	int auxId;
	int retorno=0;
	salon_mostrarStructura(lista, len);
	int indice;
	utn_getInt(&auxId, "\ningrese el id que quiere de dar de baja \n", "error ingrese un numero valido\n", 0, len, 4);

	if (len!=0&&lista!=NULL)
	{

		auxId=salon_buscarId(lista, len, auxId,&indice);
			if(auxId!=-1)
			{

			salon_bajaMenu(lista, len, indice,lista_arcade,len_arcade);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int salon_bajaMenu(Salon lista[],int len,int indice,Arcade lista_arcade[],int len_arcade)
{
	int auxBaja;
	int retorno;

	if (len!=0&&lista!=NULL)
	{
		printf("este es el salon que quiere dar de baja:\n");
		verCantidadDeSalonHay(lista_arcade, len_arcade, lista, len);
		salon_mostrarUno(lista, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			lista[indice].flagEmpty=2;
			salonQueTieneArcade(lista, len, lista_arcade, len_arcade, indice);
			retorno=1;
		 }
		 else
		 {
			 printf("no se dio de baja\n");
			 retorno=0;
		 }

	}
	return retorno;
}
int salonQueTieneArcade(Salon lista_salon[], int len_salon, Arcade lista_arcade[],int len_arcade,int indiceId)
{
	int retorno=-1;
	if(lista_salon != NULL && len_salon > 0 && lista_arcade != NULL && len_arcade > 0 )
	{

		for(int i=0;i<len_arcade;i++)
		{
			if(lista_arcade[i].idSalon==lista_salon[indiceId].id)
			{
				lista_arcade[i].flagEmpty=2;
				retorno=0;
			}
		}
	}

	return retorno;
}

int verCantidadDeSalonHay(Arcade lista_arcade[],int len_arcade, Salon lista_salon[],int len_salon)
{
	int retorno=-1;
	iniciarCantidadDeJuegoEnCero(lista_salon, len_salon);
	for (int i=0;i<len_arcade;i++)
		{
			for (int j=0;j<len_salon;j++)
			{
				if(lista_arcade[i].flagEmpty==OCUPADO&&lista_salon[j].flagEmpty==OCUPADO)
				{
					if(lista_arcade[i].idSalon==lista_salon[j].id)
					{
						lista_salon[j].cantidadDeJuegos++;
						retorno=0;
					}
				}
			}
		}
	return retorno;
}
void iniciarCantidadDeJuegoEnCero(Salon lista_salon[],int len_salon)
{
	for(int i=0;i<len_salon;i++)
	{
		lista_salon[i].cantidadDeJuegos=0;
	}

}

void informe_arcadeMasDeCuatro(Salon lista [],int len_salon,Arcade lista_arcade[],int len_arcade)
{
    int i;
    char auxTipo[38];
    printf("\nid:\t     nombre:\t   direccion:\t  tipo:\t     cantidad de juego:\t");
    verCantidadDeSalonHay(lista_arcade, len_arcade, lista, len_salon);
    for(i=0; i<len_salon; i++)
    {
        if(lista[i].flagEmpty==OCUPADO)
        {
        	if(lista[i].cantidadDeJuegos>4)
        	{
        		salon_reemplazarTipo(lista[i].tipo, auxTipo, sizeof(auxTipo));
        		printf("\n%2d\t%10s\t%10s\t%10s\t%2d\t",lista[i].id,lista[i].nombre,lista[i].direccion,auxTipo,lista[i].cantidadDeJuegos);
        	}


        }
    }

}
void informe_arcadeDosJugadores(Arcade lista[],int len_arcade,Salon lista_salon[],int len_salon)
{
		int i;
	    int indice;

	    printf("\n\nid:\tCtd Jugadores :\t nombre del juego:\tnombre del salon:");
	    for(i=0; i<len_arcade; i++)
	    {

	    	salon_buscarId(lista_salon, len_salon, lista[i].idSalon,&indice);
				if(lista[i].flagEmpty==OCUPADO)
				{
					if(lista[i].cantidadDeJugadores>2)
					{

						printf("\n%d\t%10d\t%10s\t%15s\t",lista[i].id,lista[i].cantidadDeJugadores,lista[i].nombreJuego,lista_salon[indice].nombre);
					}
				}
	    }
}
int informe_salonPorId(Salon lista_salon[],int len_salon,Arcade lista_arcade[], int len_arcade)
{
	int retorno=-1;
	int idAux;
	int opcion;
	int indice;
	utn_getInt(&idAux, "\ningrese el id a buscar\n", "error ingrese un numero valido\n", 1, len_salon, 5);
	opcion=salon_buscarId(lista_salon, len_salon, idAux, &indice);
	verCantidadDeSalonHay(lista_arcade, len_arcade, lista_salon, len_salon);
	if(opcion==0)
	{
		salon_mostrarUno(lista_salon, indice);
		retorno=0;
	}
	else
		printf("no existe el id ingresado\n");

	return retorno;

}
void informe_listarArcadePorId(Arcade lista_arcade[],int len_arcade,Salon lista_salon[],int len_salon,int posicionId)
 {
	int i;
	char auxTipo[32];
	int ContArcadeNoExiste=0;
	printf("\n Este salon contiene estos arcades:\n");
	printf("\n\nid:\tnacionalidad:\tipo de sonido:\tcant jugad:\tfichas maximas:\tnombre del juego:");
	for (i = 0; i < len_arcade; i++)
	{
		if (lista_arcade[i].flagEmpty == OCUPADO)
		{
			if (lista_arcade[i].idSalon == lista_salon[posicionId].id)
			{
				arcade_reemplazarTipo(lista_arcade[i].tipoDeSonido, auxTipo,sizeof(auxTipo));
				printf("\n%d\t%10s\t%10s\t%10d\t%10d\t%10s\t",lista_arcade[i].id, lista_arcade[i].nacionalidad,auxTipo, lista_arcade[i].cantidadDeJugadores,lista_arcade[i].capacidadMaxFicha,lista_arcade[i].nombreJuego);
				ContArcadeNoExiste++;
			}
		}
	}
	if(ContArcadeNoExiste==0)
	{
		printf("\n Este salon no tiene ningun arcade cargado \n");
	}

}
void informe_imprimirArcadePorId(Arcade lista_arcade[],int len_arcade, Salon lista_salon[],int len_salon)
{
	int idSalon;
	int posicionIdSalon;
	utn_getInt(&idSalon, "\ningrese el id de salon para buscar los arcades \n","error reingrese \n", 1, len_salon, 7);
	if (salon_buscarId(lista_salon, len_salon, idSalon, &posicionIdSalon)== 0)
	{
		informe_listarUnSoloSalonPoirId(lista_salon, posicionIdSalon);
		informe_listarArcadePorId(lista_arcade, len_arcade, lista_salon,len_salon, posicionIdSalon);
	}
	else
		printf("El id no existe reeingrese \n");



}

void informe_listarUnSoloSalonPoirId(Salon lista[],int indice)
{
	char auxTipo[32];
	salon_reemplazarTipo(lista[indice].tipo, auxTipo, sizeof(auxTipo));
	printf("NOMBRE: %s TIPO DE SALON: %s\n",lista[indice].nombre,auxTipo);


}
void informe_Max(Salon lista_salon[], int len_salon, Arcade lista_arcade[], int len_arcade)
{
	verCantidadDeSalonHay(lista_arcade, len_arcade, lista_salon, len_salon);
	int indiceMax;
	indiceMax=maxSalon(lista_salon, len_salon);
	printf("El salon con mas cantidad es:\n");
	salon_mostrarUno(lista_salon, indiceMax);
	informe_listarArcadePorId(lista_arcade, len_arcade, lista_salon, len_salon, indiceMax);




}
int maxSalon(Salon lista_salon[],int len_salon)
{
	int max;
	int i=0;
	int indice=0;
	max=lista_salon[i].cantidadDeJuegos;
	for(i=1;i<len_salon;i++)
	{
	   if (lista_salon[i].cantidadDeJuegos > max)
	      {
		   max = lista_salon[i].cantidadDeJuegos;
		   indice=i;
	      }
	}
	 return indice;
}

int acumuladorDeFichas(Arcade lista_arcade[],int len_arcade,Salon lista_salon[], int len_salon,int indiceId)
{
	int acumulador=0;
	for(int i=0;i<len_arcade;i++)
	{
		if(lista_arcade[i].flagEmpty==OCUPADO)
		{
			if(lista_arcade[i].idSalon==lista_salon[indiceId].id)
			{
				acumulador=acumulador+lista_arcade[i].capacidadMaxFicha;
			}
		}
	}
	return acumulador;

}
float informe_recaudarPorFicha(Arcade lista_arcade[],int len_arcade,Salon lista_salon[], int len_salon)
{
	int acumulador=0;
	int indiceId;
	int id;
	float precio;
	float resultado;
	utn_getInt(&id, "\ningrese el id de salon para calcular el monto maximo que se puede generar \n", "error reingrese \n", 1, len_salon, 7);

	if(salon_buscarId(lista_salon, len_salon, id, &indiceId)==0)
		{
		verCantidadDeSalonHay(lista_arcade, len_arcade, lista_salon, len_salon);
		salon_mostrarUno(lista_salon, indiceId);
		utn_getFloat(&precio, "\ningrese el precio por ficha\n", "error reingrese \n", 1, 99999, 7);
		acumulador=acumuladorDeFichas(lista_arcade, len_arcade, lista_salon, len_salon, indiceId);
		resultado=(float)acumulador*precio;
		}
	else
		printf("el id no existe\n");

	printf("\n ESTE SALON PUEDE RECAUDAR: %0.2f\n",resultado);
	return resultado;

}
int informe_juegoContadorArcade(Arcade list[],int len_arcade, char juego[],int *contador,int *indice)
{
	int retorno=-1;
	int contadorAux=0;
	int i;
	for (i=0;i<len_arcade;i++)
	{
		if(list[i].flagEmpty==OCUPADO)
		{
			if(strnicmp(list[i].nombreJuego,juego,32)==0)
			{
				retorno=0;
				contadorAux++;
				*indice=i;
			}
		}
	}
	*contador=contadorAux;
	return retorno ;
}


void informe_imprimirContadorArcadePorJuego(Listajuegos lista_juegos[],int len_salon, Arcade lista_arcade[],int len_arcade)
{
	char juego[32];
	int cantidadDeJuegos;
	int indice;
	generListaJuegos(lista_juegos, len_salon, lista_arcade, len_arcade);
	juegos_mostrarStructura(lista_juegos, len_salon);
	getString("INGRESE NOMBRE DEL JUEGO PARA BUSCAR LA CANTIDAD DE ARCADE QUE CONTIENE \n", juego);
	if(informe_juegoContadorArcade(lista_arcade, len_arcade, juego,&cantidadDeJuegos,&indice)==0)
	{
		printf("ESTE JUEGO LO CONTIENEN %d DE ARCADES\n", cantidadDeJuegos);

	}
	else
		printf("el juego no existe\n");

}


int informe_SalonCompleto(Arcade lista_arcade[],int len_arcade,Salon lista_salon[],int len_salon,int*indiceRetorno)
{/*
		int i;
	    int indice;
	    int retorno=-1;
	    verCantidadDeSalonHay(lista_arcade, len_arcade, lista_salon, len_salon);

	  //  printf("\n\nid:\tCtd Jugadores :\t nombre del juego:\tnombre del salon:");
	    for(i=0; i<len_salon; i++)
	    {
	    	for(int j=0;j<len_arcade;j++)
	    	{
	    		if(salon_buscarId(lista_salon, len_salon, lista_arcade[j].idSalon,&indice)==0)
	    		{
	    			if(lista_arcade[j].flagEmpty==OCUPADO&&lista_salon[i].flagEmpty==OCUPADO)
	    							{
	    								if(lista_salon[indice].cantidadDeJuegos>8)
	    								{
	    									if(lista_arcade[i].cantidadDeJugadores>2)
	    									{
	    										retorno=0;
	    										*indiceRetorno=indice;
	    										break;
	    									}

	    								}
	    				    	}

	    		}


	    	}
	    	}
	    return retorno;
	    */

	int estado = -1;
	int i;
	int j;
	int contador=0;

	if(lista_arcade!=NULL && lista_salon!=NULL && len_arcade>0 && len_salon>0)
	{
		for(i=0;i<len_salon;i++)
		{

			if(lista_salon[i].flagEmpty==OCUPADO)
			{
				for(j=0;j<len_arcade;j++)
				{
					if(lista_salon[j].flagEmpty==OCUPADO)
					{

						if(lista_salon[i].id==lista_arcade[j].idSalon)// && lista_arcade[j].cantidadDeJugadores>2)
						{
							printf("sad");
							contador++;
						}
					}
				}
					if(contador>=8)
					{
						salon_mostrarUno(lista_salon, i);
					}
				contador=0;
			}
		}
	estado=0;
	}

return estado;
}
void informe_ImprimirSalonCompleto(Arcade lista_arcade[],int len_arcade,Salon lista_salon[],int len_salon)
{
	int indice;

	for(int i=0;i<len_salon;i++)
	{
		if(informe_SalonCompleto(lista_arcade, len_arcade, lista_salon, len_salon,&indice)==0)
		{

			salon_mostrarUno(lista_salon, indice);

		}
	}



}




