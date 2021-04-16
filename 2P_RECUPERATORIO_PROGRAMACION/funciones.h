#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int elInt;
    char string[50];
    char elChar;
    float elFloat;
}eParcial;

eParcial* Parcial_new();
void llenar(eParcial* elParcial);
void constructorParametrizado(eParcial* elParcial,char String[],char elChar,char intStr[]);

int employee_setInt(eParcial* this,int ingresado);
int employee_setString(eParcial* this,char* String);
int employee_setChar(eParcial* this,char ingresado);
int employee_setFloat(eParcial* this,int ingresado);

void MostrarDato(eParcial* miParcial,void(*miFunc)(eParcial* parcialBuscado));
void MostrarCadena(eParcial*);
void MostrarFloat(eParcial* );