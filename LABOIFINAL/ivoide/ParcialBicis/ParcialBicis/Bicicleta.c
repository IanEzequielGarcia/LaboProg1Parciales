#include <stdio.h>
#include <stdlib.h>
#include "Bicicleta.h"
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

eBicicleta* Bicicleta_new()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));

}

eBicicleta* Bicicleta_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
    eBicicleta* pBici = NULL;
    pBici = Bicicleta_new();

    if(idStr != NULL && nombreStr != NULL && tipoStr != NULL && tiempoStr != NULL)
    {

        if(Bicicleta_setIdBike(pBici, atoi(idStr)) == 1 ||
                Bicicleta_setNombreDuenio(pBici, nombreStr) == 1 ||
                Bicicleta_setTiempo(pBici, atoi(tiempoStr)) == 1 ||
                Bicicleta_setTipo(pBici, tipoStr) == 1 )
        {
            free(pBici);
            pBici = NULL;
        }
        else
        {
            Bicicleta_setIdBike(pBici, atoi(idStr));
            Bicicleta_setNombreDuenio(pBici, nombreStr);
            Bicicleta_setTiempo(pBici, atoi(tiempoStr));
            Bicicleta_setTipo(pBici, tipoStr);
        }
    }

    return pBici;
}

int Bicicleta_setIdBike(eBicicleta* this, int id)
{
    int error = 1;

    if(this != NULL && id > 0)
    {
        this->id_bike = id;
        error = 0;
    }

    return error;
}

int Bicicleta_setNombreDuenio(eBicicleta* this, char * nombre)
{
    int error = 1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre, nombre, 128);
        error = 0;
    }

    return error;
}

int Bicicleta_setTipo(eBicicleta* this, char * tipo)
{
    int error = 1;

    if(this != NULL && tipo != NULL && (strcmp(tipo,"bmx") ==0 || strcmp(tipo,"playera") ==0 || strcmp(tipo,"mtb") ==0 || strcmp(tipo,"paseo") ==0 ))
    {
        strncpy(this->tipo, tipo, 128);
        error = 0;
    }

    return error;
}

int Bicicleta_setTiempo(eBicicleta* this, int tiempo)
{
    int error = 1;

    if(this != NULL && tiempo > 0)
    {
        this->tiempo = tiempo;
        error = 0;
    }

    return error;
}

int Bicicleta_getIdBike(eBicicleta* this, int* id)
{
    int error = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id_bike;
        error = 0;
    }

    return error;
}

int Bicicleta_getNombre(eBicicleta* this, char* nombre)
{
    int error = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }

    return error;
}

int Bicicleta_getTipo(eBicicleta* this, char* tipo)
{
    int error = 1;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo,this->tipo);
        error = 0;
    }

    return error;
}

int Bicicleta_getTiempo(eBicicleta* this, int* tiempo)
{
    int error = 1;

    if(this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        error = 0;
    }

    return error;
}

int ShowBici(LinkedList* pList, int index)
{
    int auxId;
    char auxNombre[128];
    char auxTipo[10];
    int auxTiempo;
    int error = TRUE;

    eBicicleta* pBici;

    if(pList != NULL && index >= 0)
    {
        pBici = ll_get(pList, index);

        Bicicleta_getIdBike(pBici, &auxId);
        Bicicleta_getNombre(pBici, auxNombre);
        Bicicleta_getTipo(pBici, auxTipo);
        Bicicleta_getTiempo(pBici, &auxTiempo);

        printf("%-5d \t%-50s %-10s \t%-5d\n", auxId, auxNombre, auxTipo, auxTiempo);

        error = FALSE;
    }
    else if(error)
    {
        printf("Error\n");
    }

    return error;
}


int bicicleta_getTiempoRandom(void)
{
    int aleatorio;
    aleatorio = rand()% 50 + 121;

    return aleatorio;
}

void* bicicleta_setTiempoRandom(void* bici)
{
    eBicicleta* pBici = NULL;

    if(pBici != NULL)
    {
        pBici = (eBicicleta*)bici;
        Bicicleta_setTiempo(bici, bicicleta_getTiempoRandom());
    }

    return bici;
}


LinkedList* Bicicleta_NewListFilterByTipo(LinkedList* this, int (*pFuncFilter)(void*,char *))
{
    void * elemA = NULL;
    char * tipoAFiltrar = NULL;
    LinkedList* filterArray = NULL;
    if(this != NULL && pFuncFilter != NULL)
    {
        filterArray = ll_newLinkedList();
        printf("Ingrese el tipo de bicicleta a filtrar\n");
        gets(tipoAFiltrar);
        if(filterArray != NULL)
        {
            for(int i = 0; i < ll_len(this) ; i++)
            {
                elemA = ll_get(this,i);
                if(pFuncFilter(elemA,tipoAFiltrar))
                {
                    ll_add(filterArray,elemA);
                }
            }
        }
    }
    return filterArray;
}

int bicicleta_filtrarPorTipo(void* bici, char * tipo)
{
    int cumple = FALSE;
    eBicicleta* pBici;

    if(bici != NULL && tipo != NULL)
    {
        pBici = (eBicicleta*) bici;
        cumple = (strcmp(pBici->tipo,tipo) ==0);
    }
    return cumple;
}

int bicicleta_ordenarPorTipoTiempo(void * elemA, void * elemB)
{
    eBicicleta * bici1 = (eBicicleta *) elemA;
    eBicicleta * bici2 = (eBicicleta *) elemB;

    //si el tipo es igual , comparo por tiempo
    if(strcmp(bici1->tipo,bici2->tipo) == 0)
    {
        return bici1->tiempo -bici2->tiempo;
    }
    //comparo por tipo
    return strcmp(bici1->tipo,bici2->tipo);
}
