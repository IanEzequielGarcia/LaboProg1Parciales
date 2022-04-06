#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Countries.h"
#include "Parser.h"
#include "Controller.h"
#include <string.h>
#define TRUE 1
#define FALSE 0
int controller_LoadFromText(char* path , LinkedList* pList)
{
    int todoOk = 0;
    FILE * f = fopen(path,"r");

    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
        return todoOk;
    }
    todoOk = parser_CountriesFromText(f,pList);
    fclose(f);
    printf("Carga de datos exitosa \n");
    return todoOk;
}


int controller_ShowCountries(LinkedList* pList)
{
    int allOk = TRUE;

    ePais* pCountry;


	if(pList != NULL)
	{
	    system("cls");
		printf("\n ID \tNombre \t       Recuperados   \tInfectados \t          Muertos\n\n");
		for(int i = 0; i < ll_len(pList); i++)
		{
			pCountry = ll_get(pList, i);
			if(pCountry != NULL)
            {
                ShowCountrie(pList, i);
                allOk = 0;
            }
		}
	}
	else if(allOk)
	{
		printf("No hay paises cargados en la lista.\n");
	}

    return allOk;
}


/** \brief Guarda los datos de los paises en el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_saveAsText(char* path, LinkedList* pList)
{
    int auxId;
	char auxNombre[128];
	int auxRecuperados;
	int auxInfectados;
	int auxMuertos;
	FILE* pFile;
	int error = TRUE;
	ePais* pCountrie;

	if(pList != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			error = FALSE;
			for(int i = 0; i < ll_len(pList); i++)
			{
				pCountrie = ll_get(pList, i);

                Countries_getId(pCountrie, &auxId);
                Countries_getNombre(pCountrie, auxNombre);
                Countries_getRecuperados(pCountrie, &auxRecuperados);
                Countries_getInfected(pCountrie, &auxInfectados);
                Countries_getDead(pCountrie, &auxMuertos);

                fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxNombre, auxRecuperados, auxInfectados, auxMuertos);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(error)
        {
            printf("Error\n");
        }
	}

    return error;
}


/** \brief Ordena los paises
 *
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_sortCountries(LinkedList* pList)
{
	int error = TRUE;
    if(ll_sort(pList, SortCountriesByInfected, 0))
    {
        error = FALSE;
    }

    printf("***** Listado de Paises *****\n");
    controller_ShowCountries(pList);


    return error;
}


/** \brief Ordena los paises en los mas catigados por la cantidad de muertos
 *
 * \param this LinkedList*
 * \return listaMap LinkedList*
 *
 */
LinkedList* CountriesMorePunisheds(LinkedList* this)
{
    LinkedList* listaMap = NULL;
    int cantMuertos;
    int cantMuertosMayor;
    int flag = FALSE;
    ePais* pElement = NULL;

    if(this != NULL)
    {
        listaMap = ll_newLinkedList();

        //busco el numero de muertos mayor
        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            Countries_getDead(pElement, &cantMuertos);

            if(!flag || cantMuertos > cantMuertosMayor)
            {
                cantMuertosMayor = cantMuertos;
                flag = TRUE;
            }
        }

        pElement = NULL;
        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            Countries_getDead(pElement, &cantMuertos);

            if(cantMuertos == cantMuertosMayor){
                ll_add(listaMap, pElement);
            }
        }
    }
    else
    {
        printf("Error\n");
    }

    return listaMap;
}

