#include <stdio.h>
#include <stdlib.h>
#include "Bicicleta.h"
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

//Incorporacion de nueva bicicleta

eBicicleta* Bicicleta_new()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));

}

eBicicleta* Bicicleta_newParametros(char* id_bici, char* nombre, char* tipo, char* tiempo) //Agregamos la bici nueva
{
    eBicicleta* pBici = NULL;
    pBici = Bicicleta_new();

    if(id_bici != NULL && nombre != NULL && tipo != NULL && tiempo != NULL)
    {

        if(Bicicleta_setIdBike(pBici, atoi(id_bici)) == -1 || Bicicleta_setNombreDuenio(pBici, nombre) == -1 || Bicicleta_setTipo(pBici, tipo) == -1 || Bicicleta_setTiempo(pBici, atof(tiempo)) == -1)
        {
            Bicicleta_borrar(pBici);
            pBici = NULL;
        }
        else
        {
            Bicicleta_setIdBike(pBici, atoi(id_bici));
            Bicicleta_setNombreDuenio(pBici, nombre);
            Bicicleta_setTipo(pBici, tipo);
            Bicicleta_setTiempo(pBici, atof(tiempo));
        }
    }
    return pBici;
}


void Bicicleta_borrar(eBicicleta* this)
{
    if(this != NULL) //Sistema de borrado de bicileta
    {
        free(this);
    }
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

int Bicicleta_setNombreDuenio(eBicicleta* this, char * nombre) //Ingresamos un nuevo dueño (su nombre)
{
    int error = 1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre, nombre, 128);
        error = 0;
    }

    return error;
}

int Bicicleta_setTipo(eBicicleta* this, char * tipo) //Ingresamos un nuevo dueño(Set tipo)
{
    int error = 1;

    if(this != NULL && tipo != NULL && (strcmp(tipo,"bmx") ==0 || strcmp(tipo,"BMX") ==0 ||strcmp(tipo,"PLAYERA") ==0 ||strcmp(tipo,"playera") ==0|| strcmp(tipo,"MTB") ==0|| strcmp(tipo,"mtb") ==0 || strcmp(tipo,"PASEO") ==0|| strcmp(tipo,"paseo") ==0 ))
    {
        strncpy(this->tipo, tipo, 128);
        error = 0;
    }

    return error;
}

int Bicicleta_setTiempo(eBicicleta* this, int tiempo) //Ingresamos un nuevo dueño(tiempo)
{
    int error = 1;

    if(this != NULL && tiempo >= 0)
    {
        this->tiempo = tiempo;
        error = 0;
    }

    return error;
}

//Cargamos la bicicleta ya anteriormente guardada

int Bicicleta_getIdBike(eBicicleta* this, int* id) //Ingresamos un nuevo dueño(id)
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

int Bicicleta_getTipo(eBicicleta* this, char* tipo) //Ingresamos un nuevo dueño8tipo
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
    aleatorio = rand()%(71)+50;

    return aleatorio;
}

void* bicicleta_setTiempoRandom(void* bici)
{
     eBicicleta * pBici = NULL;
    if(bici != NULL)
    {
        pBici = (eBicicleta*)bici;
        Bicicleta_setTiempo(pBici, bicicleta_getTiempoRandom());
    }

    return pBici;
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
