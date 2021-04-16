#define TAM 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"

#ifndef _eMascota
#define _eMascota
typedef struct
{
    char nombre[20];
    int edad;
    char sexo;
    char tipo[20];
    int isEmpty;
    int mascotaID;
    int idRazas;
    int peso;
}eMascota;
#endif
void InicializarMascotas(eMascota []);
void ImprimirMascotas(eMascota[],int);
int BuscarLibre(eMascota [],int);

int BorrarMascota(eMascota []);

int contadorTipos(eMascota [],int* , int* , int* ,int* ,int* ,int* );
void MostrarTipoPeso(eMascota []);

int OrdenarTipoPeso(eMascota []);