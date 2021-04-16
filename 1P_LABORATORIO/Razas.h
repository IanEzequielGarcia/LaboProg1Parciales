#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"

#ifndef _eRazas
#define _eRazas
typedef struct
{
    char descripcion[20];
    char tamanio[20];
    int paisDeOrigen;
    int isEmpty;
    int razaID;
}eRazas;
#endif
void HardCodearRazas(eRazas []);
int BuscarLibreRazas(eRazas [],int );

int ValidacionRaza(char [],eRazas []);