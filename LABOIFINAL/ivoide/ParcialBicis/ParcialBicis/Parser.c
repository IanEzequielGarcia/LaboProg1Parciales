#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Bicicleta.h"

int parser_BicisFromText(FILE* pFile , LinkedList* pLista)
{

    int allOk = 0;
    char buffer[4][200];
    int cant ;
    if(pFile == NULL && pLista == NULL  )
    {
        printf("No se puede abrir el archivo \n");
        return allOk;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
    while(!feof(pFile))
    {
        eBicicleta * aux;
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant == 4)
        {
            aux = Bicicleta_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
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
