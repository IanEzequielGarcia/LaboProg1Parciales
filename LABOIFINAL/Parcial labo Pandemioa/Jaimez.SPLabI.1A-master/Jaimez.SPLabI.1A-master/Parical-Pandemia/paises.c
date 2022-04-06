#include <stdio.h>
#include <stdlib.h>
#include "paises.h"
#include <string.h>
#include <time.h>


ePais* nuevo_Pais()
{
	return (ePais*) malloc(sizeof(ePais));
}

//---------------------------------------------------------------------------------------------------

ePais* paisesParametros(char* idStr, char* nombreStr, char* recuperadosStr, char* infectadosStr, char* muertosStr)
{
	ePais* nPais = NULL;
	nPais = nuevo_Pais();

	if(muertosStr != NULL && idStr != NULL && nombreStr != NULL && recuperadosStr != NULL && infectadosStr != NULL)
	{

		if(pais_setId(nPais, atoi(idStr)) == -1 ||
            pais_setNombre(nPais, nombreStr) == -1 ||
            pais_setRecuperados(nPais, atoi(recuperadosStr)) == -1 ||
            pais_setInfectados(nPais, atoi(infectadosStr)) == -1 ||
            pais_setMuertos(nPais, atoi(muertosStr)) == -1)
		{
			borrar_pais(nPais);
			nPais = NULL;
		}
		else
        {
            pais_setId(nPais, atoi(idStr));
            pais_setNombre(nPais, nombreStr);
            pais_setRecuperados(nPais, atoi(recuperadosStr));
            pais_setInfectados(nPais, atoi(infectadosStr));
            pais_setMuertos(nPais, atoi(muertosStr));
        }
	}

	return nPais;
}

//---------------------------------------------------------------------------------------------------

int borrar_pais(ePais* this)
{
	int exito = 1;

	if(this != NULL)
	{
		free(this);
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------
//------------------------------------------ SETTERS ------------------------------------------------

int pais_setId(ePais* this, int id)
{
	int exito = 1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_setNombre(ePais* this, char* nombre)
{
	int exito = 1;

	if(this != NULL && nombre != NULL)
	{
        strncpy(this->nombre, nombre, 128);
        exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_setRecuperados(ePais* this, int recuperados)
{
	int exito = 1;

	if(this != NULL && recuperados >= 0)
	{
		this->recuperados = recuperados;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_setInfectados(ePais* this, int infectados)
{
	int exito = 1;

	if(this != NULL && infectados >= 0)
	{
		this->infectados = infectados;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_setMuertos(ePais* this, int muertos)
{
	int exito = 1;

	if(this != NULL && muertos >= 0)
	{
		this->muertos = muertos;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------
//------------------------------------------ GETTERS ------------------------------------------------

int pais_getId(ePais* this, int* id)
{
	int exito = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_getNombre(ePais* this, char* nombre)
{
	int exito = 1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, 128);
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_getRecuperados(ePais* this, int* recuperados)
{
	int exito = 1;

	if(this != NULL && recuperados != NULL)
	{
		*recuperados = this->recuperados;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_getInfectados(ePais* this, int* infectados)
{
	int exito = 1;

	if(this != NULL && infectados != NULL)
	{
		*infectados = this->infectados;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int pais_getMuertos(ePais* this, int* muertos)
{
	int exito = 1;

	if(this != NULL && muertos != NULL)
	{
		*muertos = this->muertos;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int mostrarPais(LinkedList* pLista, int indice)
{
	int auxId;
	char auxNombre[128];
	int auxRecuperados;
	int auxInfectados;
	int auxMuertos;
	int exito = 1;

	ePais* pPais;

	if(pLista != NULL && indice >= 0)
	{
	    pPais = ll_get(pLista, indice);

		pais_getId(pPais, &auxId);
        pais_getNombre(pPais, auxNombre);
        pais_getRecuperados(pPais, &auxRecuperados);
        pais_getInfectados(pPais, &auxInfectados);
        pais_getMuertos(pPais, &auxMuertos);

        printf("%-5d \t%-30s %-20d \t%-20d \t%-30d \n", auxId, auxNombre, auxRecuperados, auxInfectados, auxMuertos);

        exito = 0;
	}
    else if(exito == 1)
    {
        printf("Error\n");
    }

	return exito;

}

//---------------------------------------------------------------------------------------------------
//------------------------------------------ GETTERS ------------------------------------------------

int cantidad_getRecuperados(void)
{
    int aleatorio;
    aleatorio = rand()% 50000 + 950001;

    return aleatorio;
}
//---------------------------------------------------------------------------------------------------

int cantidad_getInfectados(void)
{
    int aleatorio;
    aleatorio = rand()% 40000 + 1960001;

    return aleatorio;
}

//---------------------------------------------------------------------------------------------------

int cantidad_getMuertos(void)
{
    int aleatorio;
    aleatorio = rand()% 1000 + 49001;

    return aleatorio;
}

//---------------------------------------------------------------------------------------------------
//------------------------------------------ SETTERS ------------------------------------------------

void* set_cantRecuperados(void* recuperados)
{
    ePais* recuperado = NULL;

    if(recuperados != NULL)
    {
        recuperado = (ePais*)recuperados;
        pais_setRecuperados(recuperado, cantidad_getRecuperados());
    }

    return recuperado;
}

//---------------------------------------------------------------------------------------------------

void* set_cantInfectados(void* infectados)
{
    ePais* infectado = NULL;

    if(infectados != NULL)
    {
        infectado = (ePais*)infectados;
        pais_setInfectados(infectado, cantidad_getInfectados());
    }

    return infectado;
}

//---------------------------------------------------------------------------------------------------

void* set_cantMuertos(void* muertos)
{
    ePais* muerto = NULL;

    if(muertos != NULL)
    {
        muerto = (ePais*)muertos;
        pais_setMuertos(muerto, cantidad_getMuertos());
    }

    return muerto;
}

//---------------------------------------------------------------------------------------------------

int filtrarxExitosos(void* paisExitoso)
{
    int auxReturn = 0;
    ePais* x;

    if(paisExitoso != NULL)
    {
        x = (ePais*) paisExitoso;
        if(x->muertos < 5000)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

//---------------------------------------------------------------------------------------------------

int filtrarxPerjudicados(void* paisPerjudicado)
{
    int auxReturn = 0;
    ePais* x;

    if(paisPerjudicado != NULL)
    {
        x = (ePais*) paisPerjudicado;
        if(x->infectados >= (x->recuperados * 3))
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

//---------------------------------------------------------------------------------------------------

int ordenarPaisxInfectados(void* x, void* y)
{
    int cambio;
    int infectadosUno;
    int infectadosDos;

    pais_getInfectados(x, &infectadosUno);
    pais_getInfectados(y, &infectadosDos);

    if(infectadosUno > infectadosDos)
    {
        cambio = 1;
    }
    else if(infectadosUno < infectadosDos)
    {
        cambio = -1;
    }

    return cambio;
}
