/*
 * salon.c
 *
 *  Created on: 16 oct. 2021
 *      Author: mati_
 */

#include "funciones.h"
#include "salon.h"
#include "juegos.h"


int salon_inicializarArray( Salon lista[],int len)
{
	int retorno =-1;
	if(lista != NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].flagEmpty=VACIO;
			lista[i].cantidadDeJuegos=0;
			retorno=1;

		}
	}
	return retorno;

}
int salon_dameIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}
int salon_buscarLugarLibre(Salon lista[],int len)
{

	int i;
	int indice=-1;
	for(i=0; i<len; i++)
	{
		if(lista[i].flagEmpty==VACIO)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
void salon_mostrarStructura(Salon lista [],int len)
{
    int i;
    char auxTipo[38];
    printf("id:\tnombre:\t  direccion:\t tipo:\t");
    for(i=0; i<len; i++)
    {
        if(lista[i].flagEmpty==OCUPADO)
        {
        	salon_reemplazarTipo(lista[i].tipo, auxTipo, sizeof(auxTipo));
        	printf("\n%d\t%s\t%s    \t%s\t",lista[i].id,lista[i].nombre,lista[i].direccion,auxTipo);


        }
    }

}
int salon_buscarId(Salon listado[],int len, int id,int* indice)
{
    int retorno = -1;
    int i;
    if(len > 0 && listado != NULL)
    {
        retorno = -1;
        for(i=0; i<len; i++)
        {
            if(listado[i].flagEmpty == OCUPADO && listado[i].id == id)
            {
                retorno = 0;
                *indice=i;
                break;
            }
        }
    }
    return retorno;
}


int salon_alta( Salon lista[],int len)
{
	int retorno=0;
	int indice;
	if (len!=0&&lista!=NULL)
	{
		indice=salon_buscarLugarLibre(lista, len);
		if(indice>=0)
		{
			getString("ingrese el nombre \n",lista[indice].nombre );
			getString("ingrese la direccion\n",lista[indice].direccion);
			utn_getInt(&lista[indice].tipo, "ingrese tipo\n 1-LOCAl\n 2-SHOPPING\n","error ingrese 1 o 2\n", 1, 2, 100);
			lista[indice].id=salon_dameIdNuevo();
			retorno=1;
			lista[indice].flagEmpty=0;
			printf("se dio de alta el salon:");
			salon_mostrarUno(lista, indice);

		}
	}


	return retorno;
}
void salon_mostrarUno(Salon lista[],int i)
{
	char auxTipo[32];
	salon_reemplazarTipo(lista[i].tipo, auxTipo, sizeof(auxTipo));
	printf("\nid:%d nombre:%s direccion:%s tipo:%s cantidad de arcades que posee %d\n",lista[i].id,lista[i].nombre,lista[i].direccion,auxTipo,lista[i].cantidadDeJuegos);
}



void transefrirDatos(Salon listado  [],Salon auxiliarListado  [],int len)
{
    int i;

    for(i=0;i<len;i++)
    {
       // if(listado[i].isEmpty==OCUPADO)
        {
          /*  listado[i].isEmpty=auxiliarListado[i].isEmpty;
            listado[i].id=auxiliarListado[i].id;
            listado[i].salary=auxiliarListado[i].salary;
            listado[i].sector=auxiliarListado[i].sector;
            strcpy(listado[i].name,auxiliarListado[i].name);
            strcpy(listado[i].lastName,auxiliarListado[i].lastName);*/
        }
    }
}
char salon_reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[20];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"LOCAL",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"SHOPPING",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}
int salon_ordenarArraySegunCriterio(Salon lista [], int len, int orden)
{
	Salon Aux;

	int contador = 0;
	char auxTipo[15];
	char auxTipoDos[15];
	switch (orden)
	{
	case 1:

		for (int i = 0; i < len - 1; i++)
		{
			if (lista[i].flagEmpty == OCUPADO)
			{
				if (stricmp(lista[i].nombre, lista[i + 1].nombre) > 0)// descendente
				{
					Aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = Aux;
					salon_reemplazarTipo(lista[i].id, auxTipo, len);
					salon_reemplazarTipo(lista[i + 1].id, auxTipoDos, len);
					if (stricmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = lista[i];
						lista[i] = lista[i + 1];
						lista[i + 1] = Aux;
					}
				}
			}
		}
		break;

	case 2:

		for (int i = 0; i < len - 1; i++)// ascendente
		{
			if (lista[i].flagEmpty == OCUPADO)
			{
				if (stricmp(lista[i].nombre, lista[i + 1].nombre) < 0)
				{

					Aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = Aux;
					salon_reemplazarTipo(lista[i].id, auxTipo, len);
					salon_reemplazarTipo(lista[i + 1].id, auxTipoDos, len);
					if (stricmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = lista[i];
						lista[i] = lista[i + 1];
						lista[i + 1] = Aux;
					}
				}
			}
		}
		break;
	}


	//falta imprimir array aca
	return contador;

}

/*
 *
 *
 * int type;// 0 lcd 1 plasma
	float price;
	int id;
	char name[128];
	char addres[128];
	int flagEmpty;
 */
int salon_altaHardcodeada(Salon lista[],char* nombre,char * direccion,int tipo,int len,int indice)
{
	int respuesta=-1;
	if(len > 0 && lista != NULL)
	{

		strncpy(lista[indice].nombre,nombre,sizeof(lista->nombre));
		strncpy(lista[indice].direccion,direccion,sizeof(lista->direccion));
		lista[indice].id=salon_dameIdNuevo();
		lista[indice].flagEmpty=OCUPADO;
		lista[indice].tipo=tipo;
		respuesta= 0;

	}

	return respuesta;

}

