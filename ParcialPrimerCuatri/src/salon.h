/*
 * salon.h
 *
 *  Created on: 16 oct. 2021
 *      Author: mati_
 */

#ifndef SALON_H_
#define SALON_H_
#define OCUPADO 0
#define VACIO 1
#define LOCAL 1
#define SHOPPING 2
typedef struct {

	int tipo;// 1 LOCAL 2 SHOPPING
	int id;
	char nombre[63];
	char direccion[128];
	int flagEmpty;
	int cantidadDeJuegos;
}Salon;

int salon_inicializarArray( Salon lista[],int len);
int salon_alta( Salon lista[],int len);
int salon_buscarLugarLibre(Salon lista[],int len);
int salon_dameIdNuevo(void);
void salon_mostrarStructura(Salon mostrar [],int len);
int salon_buscarId(Salon listado[],int len, int id,int* idCliente);
int salon_menuModificar(Salon lista[],int len,int indice);
int salon_modificar(Salon lista[],int len);
void salon_mostrarUno(Salon lista[],int indice);


void transefrirDatos(Salon listado  [],Salon auxiliarListado  [],int len);
char salon_reemplazarTipo(int tipo,char *retorno,int len);
int salon_ordenarArraySegunCriterio(Salon lista [], int len, int orden);
int salon_altaHardcodeada(Salon lista[],char* nombre,char * direccion,int tipo,int len,int indice);

#endif /* SALON_H_ */
