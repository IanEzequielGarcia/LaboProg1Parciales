#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Bicicleta.h"

int parser_BicicletaFromText(FILE* miFile, LinkedList* pMiLista)
{
    eBicicleta* pBici;
    int retorno = 0;
	char id[200];
	char nombre[200];
	char tipo[200];
	char tiempo[200];

	if(miFile != NULL && pMiLista != NULL)
	{
	    fscanf(miFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo);
		do
		{
			if(fscanf(miFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo) == 4) //Declaracion de los archivos
			{
				pBici = Bicicleta_newParametros(id, nombre, tipo, tiempo);

				if(pBici != NULL)
				{
					ll_add(pMiLista, pBici);
					retorno = 1;
				}
			}
			else
			{
				break;
			}

		}while(feof(miFile) == 0);
	}
return retorno;
}
