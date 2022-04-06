#include <stdio.h>
#include <stdlib.h>
#include "Countries.h"
#include <string.h>
#include <time.h>
/** \brief Guarda espacio en memoria para un pais
 *
 * \return Puntero al espacio guardado
 *
 */
ePais* Countries_new()
{
    return (ePais*) malloc(sizeof(ePais));
}


/** \brief Carga los nuevos parametros de paises
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param recuperadosStr char*
 * \param infectadosStr char*
 * \param muertosStr char*
 * \return nuevo pais
 *
 */
ePais* Countries_newParametros(char* idStr, char* nombreStr, char* recuperadosStr, char* infectadosStr, char* muertosStr)
{
    ePais* pCountry = NULL;
	pCountry = Countries_new();

	if(muertosStr != NULL && idStr != NULL && nombreStr != NULL && recuperadosStr != NULL && infectadosStr != NULL)
	{

		if(Countries_setId(pCountry, atoi(idStr)) == 1 ||
            Countries_setName(pCountry, nombreStr) == 1 ||
            Countries_setRecoveries(pCountry, atoi(recuperadosStr)) == 1 ||
            Countries_setInfected(pCountry, atoi(infectadosStr)) == 1 ||
            Countries_setDeads(pCountry, atoi(muertosStr)) == 1)
		{
			free(pCountry);
			pCountry = NULL;
		}
		else
        {
            Countries_setId(pCountry, atoi(idStr));
            Countries_setName(pCountry, nombreStr);
            Countries_setRecoveries(pCountry, atoi(recuperadosStr));
            Countries_setInfected(pCountry, atoi(infectadosStr));
            Countries_setDeads(pCountry, atoi(muertosStr));
        }
	}

	return pCountry;
}

int Countries_setId(ePais* this, int id)
{
    int error = 1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		error = 0;
	}

	return error;
}

int Countries_setName(ePais* this, char* nombre)
{
    int error = 1;

	if(this != NULL && nombre != NULL)
	{
        strncpy(this->nombre, nombre, 128);
        error = 0;
	}

	return error;
}

int Countries_setRecoveries(ePais* this, int recuperados)
{
    int error = 1;

	if(this != NULL && recuperados >= 0)
	{
		this->recuperados = recuperados;
		error = 0;
	}

	return error;
}

int Countries_setInfected(ePais* this, int infectados)
{
    int error = 1;

	if(this != NULL && infectados >= 0)
	{
		this->infectados = infectados;
		error = 0;
	}

	return error;
}

int Countries_setDeads(ePais* this, int muertos)
{
    int error = 1;

	if(this != NULL && muertos >= 0)
	{
		this->muertos = muertos;
		error = 0;
	}

	return error;
}

int Countries_getId(ePais* this, int* id)
{
    int error = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		error = 0;
	}

	return error;
}

int Countries_getNombre(ePais* this, char* nombre)
{
    int error = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		error = 0;
	}

	return error;
}

int Countries_getRecuperados(ePais* this, int* recuperados)
{
    int error = 1;

	if(this != NULL && recuperados != NULL)
	{
		*recuperados = this->recuperados;
		error = 0;
	}

	return error;
}

int Countries_getInfected(ePais* this, int* infectados)
{
    int error = 1;

	if(this != NULL && infectados != NULL)
	{
		*infectados = this->infectados;
		error = 0;
	}

	return error;
}

int Countries_getDead(ePais* this, int* muertos)
{
    int error = 1;

	if(this != NULL && muertos != NULL)
	{
		*muertos = this->muertos;
		error = 0;
	}

	return error;
}

int ShowCountrie(LinkedList* pList, int index)
{
    int auxId;
	char auxNombre[128];
	int auxRecuperados;
	int auxInfectados;
	int auxMuertos;
	int exito = 1;

	ePais* pCountrie;

	if(pList != NULL && index >= 0)
	{
	    pCountrie = ll_get(pList, index);

		Countries_getId(pCountrie, &auxId);
        Countries_getNombre(pCountrie, auxNombre);
        Countries_getRecuperados(pCountrie, &auxRecuperados);
        Countries_getInfected(pCountrie, &auxInfectados);
        Countries_getDead(pCountrie, &auxMuertos);

        printf("%-5d \t%-30s %-20d \t%-20d \t%-30d \n", auxId, auxNombre, auxRecuperados, auxInfectados, auxMuertos);

        exito = 0;
	}
    else if(exito == 1)
    {
        printf("Error\n");
    }

	return exito;
}

int cantidad_getRecuperados(void)
{
     int aleatorio;
    aleatorio = rand()% 50000 + 950001;

    return aleatorio;
}

int cantidad_getInfectados(void)
{
    int aleatorio;
    aleatorio = rand()% 40000 + 1960001;

    return aleatorio;
}

int cantidad_getMuertos(void)
{
    int aleatorio;
    aleatorio = rand()% 1000 + 49001;

    return aleatorio;
}

void* set_QttyRecoveries(void* country)
{
    ePais* pCountry = NULL;

    if(pCountry != NULL)
    {
        pCountry = (ePais*)country;
        Countries_setRecoveries(country, cantidad_getRecuperados());
    }

    return country;
}

void* set_QttyInfecteds(void* country)
{
    ePais* pCountry = NULL;

    if(pCountry != NULL)
    {
        pCountry = (ePais*)country;
        Countries_setInfected(country, cantidad_getInfectados());
    }

    return country;
}

void* set_QttyDead(void* country)
{
    ePais* pCountry = NULL;

    if(pCountry != NULL)
    {
        pCountry = (ePais*)country;
        Countries_setDeads(country, cantidad_getMuertos());
    }

    return country;
}

int FilterBySuccessful(void* country)
{
    int error = 0;
    ePais* pCountry = NULL;

    if(pCountry != NULL)
    {
        pCountry = (ePais*) country;
        if(pCountry->muertos < 5000)
        {
            error = 1;
        }
    }

    return error;
}


int FiterByInjured(void* country)
{
    int error = 0;
    ePais* pCountry;

    if(country != NULL)
    {
        pCountry = (ePais*) country;
        if(pCountry->infectados >= (pCountry->recuperados * 3))
        {
            error = 1;
        }
    }

    return error;
}


int SortCountriesByInfected(void* country1, void* country2)
{
    int switcheado;
    int infectadosUno;
    int infectadosDos;

    Countries_getInfected(country1, &infectadosUno);
    Countries_getInfected(country2, &infectadosDos);

    if(infectadosUno > infectadosDos)
    {
        switcheado = 1;
    }
    else if(infectadosUno < infectadosDos)
    {
        switcheado = -1;
    }

    return switcheado;
}

