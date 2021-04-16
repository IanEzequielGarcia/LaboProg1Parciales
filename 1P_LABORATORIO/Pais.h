#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nombreDePais[20];
    char continente[20];
    int codigoTelefonico;
    int isEmpty;
    int paisID;
}ePais;

void HardcodearPaises(ePais[]);
int MostrarPaises(ePais [],int);