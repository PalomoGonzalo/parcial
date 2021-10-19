#include <stdio.h>
#include <stdlib.h>
#include "salon.h"
#include "funciones.h"
#include "arcade.h"


//MENU
/*
	setbuf(stdout, NULL);
	char seguir= 's';
	//Display displaysList[DISPLEYS_LEN];
	//disp_initList(displaysList,DISPLEYS_LEN);
	//char test[20];
	int opcion;
	do{
		utn_getInt(&opcion, " 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja\n 4-Salir\n", "error ingrese numeros validos", 1, 4, 4);
		switch(opcion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			seguir='n';
			break;
		}
	}while(seguir=='s');
 *
 *
 */

int arcade_inicializarArray( Arcade lista[],int len)
{
	int retorno =-1;
	if(lista != NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].flagEmpty=VACIO;
			retorno=1;

		}
	}
	return retorno;

}
int arcade_dameIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}
int arcade_buscarLugarLibre(Arcade displaysList[],int len)
{

	int i;
	int indice=-1;
	for(i=0; i<len; i++)
	{
		if(displaysList[i].flagEmpty==VACIO)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
char arcade_reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[20];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"ESTEREO",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"MONO",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}
void arcade_mostrarStructura(Arcade lista [],int len)
{
	int i;
	    char auxTipo[38];
	    printf("\n\nid:\tnacionalidad:\tipo de sonido:\tcant jugad:\tfichas maximas:\t id salon:\tnombre del juego:");
	    for(i=0; i<len; i++)
	    {
	        if(lista[i].flagEmpty==OCUPADO)
	        {
	        	arcade_reemplazarTipo(lista[i].tipoDeSonido, auxTipo, sizeof(auxTipo));
	        	printf("\n%d\t%10s\t%10s\t%10d\t%10d\t%10d\t%10s\t",lista[i].id,lista[i].nacionalidad,auxTipo,lista[i].cantidadDeJugadores,lista[i].capacidadMaxFicha,lista[i].idSalon,lista[i].nombreJuego);


	        }
	    }

}
int arcade_buscarId(Arcade listado[],int len, int id,int* indice)
{
    int retorno = -1;
    int i;
    if(len > 0 && listado != NULL)
    {
        retorno = -1;
        for(i=0; i<len; i++)
        {
            if(listado[i].flagEmpty == 0 && listado[i].id == id)
            {
                retorno = 0;
                *indice=i;
                break;
            }
        }
    }
    return retorno;
}


int arcade_alta( Arcade lista_arcade[],int len,Salon lista[],int lenSalon)
{
	int retorno=0;
	int indice;
	int idSalon;
	int indiceSalon;
	int retornoOpcion;
	if (len!=0&&lista_arcade!=NULL)
	{
		indice=arcade_buscarLugarLibre(lista_arcade, len);
		if(indice>=0)
		{
			salon_mostrarStructura(lista, lenSalon);
			utn_getInt(&idSalon, "\ningrese el id del salon\n", "error reingrese \n", 0, len, 10);
			retornoOpcion=salon_buscarId(lista, lenSalon, idSalon,&indiceSalon);
			if(retornoOpcion==0)
			{
				lista_arcade[indice].idSalon=idSalon;
				getString("ingrese la nacionalidad \n",lista_arcade[indice].nacionalidad);
				utn_getInt(&lista_arcade[indice].tipoDeSonido, "ingrese el tipo de sonido\n1-ESTEREO\n2-MONO", "error reingrese numeros validos\n", 1, 2, 10);
				utn_getInt(&lista_arcade[indice].cantidadDeJugadores, "ingrese la cantidad de jugadores", "error reingrese\n", 1, 78, 10);
				utn_getInt(&lista_arcade[indice].capacidadMaxFicha, "ingrese la capacidad maxima de ficha", "error reingrese\n", 1, 78, 10);
				getString("ingrese el nombre del juego \n",lista_arcade[indice].nombreJuego);
				lista_arcade[indice].id=arcade_dameIdNuevo();
				lista_arcade[indice].flagEmpty=OCUPADO;
				printf("se cargo correctamente la publicacion: \n");
				arcade_mostrarUno(lista_arcade, indice);
				//lista[indiceCliente].contadorPublicacion=lista[indiceCliente].contadorPublicacion+1;

			}
			else
				printf("el id no existe \n");
		}
	}


	return retorno;
}

void arcade_mostrarUno(Arcade lista[],int i)
{
	char auxTipo[20];
	arcade_reemplazarTipo(lista[i].tipoDeSonido, auxTipo, sizeof(auxTipo));
	printf("\n\nid:\tnacionalidad:\tipo de sonido:\tcant jugad:\tfichas maximas:\t id salon:\tnombre del juego:");
	printf("\n%d\t%10s\t%10s\t%10d\t%10d\t%10d\t%10s\t",lista[i].id,lista[i].nacionalidad,auxTipo,lista[i].cantidadDeJugadores,lista[i].capacidadMaxFicha,lista[i].idSalon,lista[i].nombreJuego);
}
int arcade_modificar(Arcade lista_arcade[],int len, Listajuegos lista_juegos[], int len_juegos)
{
	int idAux;
	int retorno=0;
	int indice;
	int retornoId;
//	int auxContinuar=1;

	arcade_mostrarStructura(lista_arcade, len);
	utn_getInt(&idAux, "\ningrese el id a modidficar \n", "eror ingrese un numero\n", 1, len, 5);
	retornoId=arcade_buscarId(lista_arcade, len, idAux,&indice);
	if (len!=0&&lista_arcade!=NULL)
	{
			if(retornoId!=-1)
			{
				arcade_menuModificar(lista_arcade, len, indice, lista_juegos, len_juegos);
				retorno=1;
			//	indice=-1;
			}
			else
			{
				printf("no se encontro el id\n");
			}
	}
	return retorno;
	}


int generListaJuegos(Listajuegos lista_juegos[],int len_juegos,Arcade lista_arcade[],int len_arcade)
{
	int retorno=-1;
	int i;
	int indiceListaJuegos=0;
	juegos_init(lista_juegos, len_juegos);
	for(i=0;i<len_arcade;i++)
	{
		if(lista_arcade[i].flagEmpty==OCUPADO)
		{
			if(juegos_estaEnArcade(lista_juegos, len_juegos, lista_arcade[i].nombreJuego)==0)
			{
				strncpy(lista_juegos[indiceListaJuegos].nombreJuego,lista_arcade[i].nombreJuego,32);
				lista_juegos[indiceListaJuegos].flagEmpty=0;
				indiceListaJuegos++;
				retorno=0;

			}
		}
	}

	return retorno;
}
void juegos_mostrarStructura(Listajuegos lista [],int len)
{
	int i;
	    printf("\nJUEGOS CARGADOS \n");
	    for(i=0; i<len; i++)
	    {
	        if(lista[i].flagEmpty==OCUPADO)
	        {

	        	printf("%s\n",lista[i].nombreJuego);


	        }
	    }

}

/*int deseaContinuar(void)
{
	int continuar;
	int retorno;
	utn_getInt(&continuar,"desea seguir modificando \n 1-si 2-no\n","error reingrese",1,2,4);
		if(continuar==1)
		{
			retorno=1;
		}
		else
			retorno=-1;
}*/
int arcade_menuModificar(Arcade lista[],int len,int indice,Listajuegos lista_juegos[],int len_juegos)
{
	int retorno=-1;
	int opcion;
	char auxNombre[32];
	int  cantidadJugAux;
	//int continuar;
	utn_getInt(&opcion, " Que desea modificar? \n 1-CANTIDAD DE JUGADORES\n 2-NOMBRE DEL JUEGO\n", "error ingrese un numero valid\n", 1, 2, 5);
	switch(opcion)
	{
	case 1:
		utn_getInt(&cantidadJugAux, "\ningrese nueva cantidad de jugadores \n", "error ingrese numero validos\n", 1, 9999, 3);
		lista[indice].cantidadDeJugadores=cantidadJugAux;
		printf("\n se cambio correctamente \n");

		break;
	case 2:
		juegos_mostrarStructura(lista_juegos, len_juegos);
		getString("\ningrese el nombre que aparece en la lista \n", auxNombre);
		if(juegos_estaEnArcade(lista_juegos, len_juegos,auxNombre)==1)
			{
				strncpy(lista[indice].nombreJuego,auxNombre,sizeof(lista->nombreJuego));
				printf ("se cambio correctamente\n");
			}
		else
		{
			printf("\n no existe ese nombre de juego \n");
		}
		break;
	default:
		printf("no es un numero valido \n");
		break;
	}
return retorno;
}


int arcade_altaHardcodeada(Arcade lista[],char* nombreJuego,char * nacionalidad,int tipoSonido,int fichas,int idSalon,int cantJugadores,int len,int indice)
{
	int respuesta=-1;
	if(len > 0 && lista != NULL)
	{

		strncpy(lista[indice].nombreJuego,nombreJuego,sizeof(lista->nombreJuego));
		strncpy(lista[indice].nacionalidad,nacionalidad,sizeof(lista->nacionalidad));
		lista[indice].id=arcade_dameIdNuevo();
		lista[indice].idSalon=idSalon;
		lista[indice].flagEmpty=OCUPADO;
		lista[indice].tipoDeSonido=tipoSonido;
		lista[indice].capacidadMaxFicha=fichas;
		lista[indice].cantidadDeJugadores=cantJugadores;
		respuesta= 0;

	}

	return respuesta;

}
int arcade_Baja(Arcade list[],int len)
{
	int auxId;
	int retorno=0;
	arcade_mostrarStructura(list, len);
	int indice;
	int auxEncontro;
	utn_getInt(&auxId, "\ningrese el id que quiere de dar de baja \n", "error ingrese un numero valido", 1, len, 4);

	if (len!=0&&list!=NULL)
	{

		auxEncontro=arcade_buscarId(list, len, auxId, &indice);
			if(auxEncontro!=-1)
			{

			arcade_bajaMenu(list, len, indice);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int arcade_bajaMenu(Arcade list[],int len,int indice)
{
	int auxBaja;
	int retorno;

	if (len!=0&&list!=NULL)
	{
		arcade_mostrarUno(list, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			list[indice].flagEmpty=2;
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





