#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "SECABA.h"
#include "parser.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayListeParticipantes)
{
    int cant;
    char aux[5][64];
    /*char id[12];
    char descripcion[32];
    char domicilio[32];
    char recursos[12];
    char rubroId[12];*/
    int sePudo=0;
    eParticipantes* eParticipantesAux;
    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",aux[0],aux[1],aux[2],aux[3],aux[4]);
        if(cant==5)
        {
           if(!(eParticipantesAux=eParticipantes_new()))
            {
                printf("No hay espacio!");
                break;
            }
            else
            {
                eParticipantesAux=eParticipantes_newParametros(aux[0],aux[1],aux[2],aux[3],aux[4]);
                if(eParticipantesAux!=NULL)
                {
                    ll_add(pArrayListeParticipantes,eParticipantesAux);
                    sePudo=1;
                }
            }
        }
    }while(!feof(pFile));
    fclose(pFile);
    return sePudo;

}

int parser_FromBinary(FILE* pFile, LinkedList* pArrayListeParticipantes)
{
    int cant;
    char aux[3][64];
    /*char id[10];
    char descripcion[50];
    char domicilio[20];
    char recursos[25];
    char rubroId[25];*/
    int sePudo=0;
    eParticipantes* eParticipantesAux;
    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",aux[0],aux[1],aux[2],aux[3],aux[4]);
        if(cant==5)
        {
           if(!(eParticipantesAux=eParticipantes_new()))
            {
                printf("No hay espacio!");
                break;
            }
            else
            {//(char* idStr,char* anioStr,char* descripcionStr,char* dniStr,char* fechapresentacionStr,char*temapresentacion,char*puntajeStr)
                /*for(i=7;i<sizeof(dni);i++)
                {
                    dni[i]='\0';
                }*/
                eParticipantesAux=eParticipantes_newParametros(aux[0],aux[1],aux[2],aux[3],aux[4]);
                ll_add(pArrayListeParticipantes,eParticipantesAux);
                sePudo=1;
            }
        }
    }while(!feof(pFile));
    fclose(pFile);
    return sePudo;

}


