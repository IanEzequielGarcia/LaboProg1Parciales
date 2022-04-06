#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paises.h"

int parser_PaisesATexto(FILE* pFile , LinkedList* pLista)
{
	int exito = 1;
	ePais* pPais;
	char id[200];
	char nombre[200];
	char recuperados[200];
	char infectados[200];
	char muertos[200];

	if(pFile != NULL && pLista != NULL)
	{
	    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, recuperados, infectados, muertos);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, recuperados, infectados, muertos) == 5)
			{
				pPais = paisesParametros(id, nombre, recuperados, infectados, muertos);

				if(pPais != NULL)//osea si pudo cargar
				{
					ll_add(pLista, pPais);
					exito = 0;
				}
			}
			else //Si es lo contrario
			{
				break;
			}

		}while(feof(pFile) == 0);
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------
