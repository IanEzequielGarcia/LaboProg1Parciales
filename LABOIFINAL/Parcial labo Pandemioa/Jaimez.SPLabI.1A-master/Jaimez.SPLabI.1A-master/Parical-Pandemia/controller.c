#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "controller.h"
#include <string.h>


int cargarTexto(char* path , LinkedList* pLista)
{
	FILE* pFile;
	int exito = 1;

	pFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

	if(pFile != NULL)
	{
		if(parser_PaisesATexto(pFile, pLista) == 0)
		{
		    //Si todo salio bien cambia a 0
		    exito = 0;
			printf("\nLos datos de los paises en modo texto fueron cargados corretamente\n\n");
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
	}
	else
	{
		printf("Error\n");
	}

	fclose(pFile);

    return exito;
}

//---------------------------------------------------------------------------------------------------

int mostrarPaises(LinkedList* pLista)
{
	int exito = 1;

    ePais* pPais;


	if(pLista != NULL)
	{
	    system("cls");
		printf("\n ID \tNombre \t       Recuperados   \tInfectados \t          Muertos\n\n");
		for(int i = 0; i < ll_len(pLista); i++)
		{
			pPais = ll_get(pLista, i);
			if(pPais != NULL)
            {
                mostrarPais(pLista, i);
                exito = 0;
            }
		}
	}
	else if(exito == 1)
	{
		printf("No hay paises cargados en la lista.\n");
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

int guardarComoTexto(char* path, LinkedList* pLista)
{
	int auxId;
	char auxNombre[128];
	int auxRecuperados;
	int auxInfectados;
	int auxMuertos;
	FILE* pFile;
	int exito = 1;
	ePais* pPais;

	if(pLista != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			exito = 0;
			for(int i = 0; i < ll_len(pLista); i++)
			{
				pPais = ll_get(pLista, i);

                pais_getId(pPais, &auxId);
                pais_getNombre(pPais, auxNombre);
                pais_getRecuperados(pPais, &auxRecuperados);
                pais_getInfectados(pPais, &auxInfectados);
                pais_getMuertos(pPais, &auxMuertos);

                fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxNombre, auxRecuperados, auxInfectados, auxMuertos);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(exito == 1)
        {
            printf("Error\n");
        }
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

int ordenarPaises(LinkedList* pLista)
{

    system("cls");
	int exito = 1;
	LinkedList* pCopiaLista = ll_newLinkedList();


	if((pCopiaLista = ll_clone(pLista)) != NULL)
    {
        system("cls");
        ll_sort(pCopiaLista, ordenarPaisxInfectados, 0);
    }

    printf("***** Listado de Paises *****\n");
    printf("\n ID \tNombre \t       Recuperados   \tInfectados \t          Muertos\n\n");
    mostrarPaises(pCopiaLista);

    ll_deleteLinkedList(pCopiaLista);

    return exito;
}

//---------------------------------------------------------------------------------------------------

LinkedList* paisesMasCatigados(LinkedList* this)
{
    LinkedList* listaMap = NULL;
    int cantMuertos;
    int cantMayor;
    int flag = 0;
    ePais* pElement = NULL;

    if(this != NULL)
    {
        listaMap = ll_newLinkedList();

        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            pais_getMuertos(pElement, &cantMuertos);

            if(!flag || cantMuertos > cantMayor)
            {
                cantMayor = cantMuertos;
                flag = 1;
            }
        }

        pElement = NULL;
        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            pais_getMuertos(pElement, &cantMuertos);

            if(cantMuertos == cantMayor){
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
