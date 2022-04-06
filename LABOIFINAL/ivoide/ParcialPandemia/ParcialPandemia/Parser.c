#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Countries.h"

int parser_CountriesFromText(FILE* pFile , LinkedList* pLista)
{

    int allOk = 0;
    char buffer[5][200];
    int cant ;
    if(pFile == NULL && pLista == NULL  )
    {
        printf("No se puede abrir el archivo \n");
        return allOk;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
    while(!feof(pFile))
    {
        ePais * aux;
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        if(cant == 4)
        {
            aux = Countries_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(aux != NULL)
            {
               allOk= ll_add(pLista,aux);
            }
            //free(aux);
        }
        else
        {
            break;
        }
    }

    return allOk;


}
