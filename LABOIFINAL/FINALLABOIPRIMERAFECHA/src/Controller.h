/*
 * Controller.h
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "SECABA.h"
#include "parser.h"
int controller_loadFromText(char* path , LinkedList* pArrayListeParticipantes);
int controller_loadFromBinary(char* path , LinkedList* pArrayListeParticipantes);
int controller_addeParticipantes(LinkedList* pArrayListeParticipantes);
int controller_editeParticipantes(LinkedList* pArrayListeParticipantes);
int controller_removeeParticipantes(LinkedList* pArrayListeParticipantes);
int controller_ListeParticipantes(LinkedList* pArrayListeParticipantes);
int controller_sorteParticipantes(LinkedList* pArrayListeParticipantes);
int controller_saveAsText(char* path , LinkedList* pArrayListeParticipantes);
int controller_saveAsBinary(char* path , LinkedList* pArrayListeParticipantes);


int controller_saveElementoAsText(char* path, eParticipantes* empleado);
void SaveParticipantes(void* voidIngresado);
void LlMenorQue10(LinkedList* this);

int BuscarMayorNumero(LinkedList* LaLista);
int TresMayores(LinkedList* LaLista);

void SaveeParticipantesLL(LinkedList* this);

//FINAL MAYO
int OrderByString(eParticipantes* voidUno,eParticipantes* voidDos);

void OrdenarListas(LinkedList* this);

void MostrarParcial(LinkedList* this);

int MayorQue12(eParticipantes* elemento);

void FiltradorBicicletas(LinkedList* this);

int BicicletaFiltro(eParticipantes* elemento,char* string);

int Mapear(void* elemento);

void LL_Mapear(LinkedList* this);

int SortString(eParticipantes* n1, eParticipantes* n2);

int Punto6Sort(LinkedList* this);

int SortInt(eParticipantes* n1, eParticipantes* n2);

int BajaRecurso(eParticipantes* this);

#endif /* CONTROLLER_H_ */
