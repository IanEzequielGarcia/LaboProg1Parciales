#ifndef SECABA_H_
#define SECABA_H_
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 100
typedef struct
{//char* idStr,char* DescripcionStr,char* dniStr,char* fechapresentacionStr,char*temapresentacionStr,char*puntaje
    int id;
    char nombre[50];
    char tipo[25];
    int tiempo;
    float promedio;
}eParticipantes;

eParticipantes* eParticipantes_new();
eParticipantes* eParticipantes_newParametros(char* ,char* ,char*,char* ,char*);
void eParticipantes_delete();

int eParticipantes_setId(eParticipantes* this,int id); //(x)
int eParticipantes_getId(eParticipantes* this,int* id);//(x)

int eParticipantes_setNombre(eParticipantes* this,char* string); //(x)
int eParticipantes_getNombre(eParticipantes* this,char* string); //(x?)

int eParticipantes_setTipo(eParticipantes* this,char* string);
int eParticipantes_getTipo(eParticipantes* this,char* string);

int eParticipantes_getTiempo(eParticipantes* this,int* ingresado);
int eParticipantes_setTiempo(eParticipantes* this,int ingresado);

int eParticipantes_setPromedio(eParticipantes* this,float ingresado);
int eParticipantes_getPromedio(eParticipantes* this,float* ingresado);

int eParticipantes_CompareByName(eParticipantes* e1, eParticipantes* e2); //(x)
int eParticipantes_CompareById(eParticipantes* e1, eParticipantes* e2);   //(x)
int eParticipantes_CompareBySalary(eParticipantes* e1, eParticipantes* e2);//(x)
int eParticipantes_CompareByWorkingHours(eParticipantes* e1, eParticipantes* e2);//(x)

int ValidarInt(char[]); //(x)
int ValidarString(char []); //(x)

int criterioJurado(void*);

int MenosDe10(void* elemento);
void MostrarMayorPuntos(LinkedList* this);

int MayorNumeroLL(void* elemento,void* criterio);
int BuscarTresMayores(LinkedList* LaLista,int Tresmayores,int bandera);
int BuscarMayorNumero(LinkedList* LaLista);

int sorteador(void* elemento,void* elemento2);

int MayorNumeroLL2(void* elemento,void* criterio);
#endif // eParticipantes_H_INCLUDED
