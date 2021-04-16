/******************************************************************************
1) Diseñar una estructura con 4 campos (uno entero, uno char y una cadena,un float).
Realizar un constructor por defecto y uno parametrizado solo con tres parámetros. Respetar
las reglas de estilo vistas en la cátedra .el segundo constructor carga el dato float con el
entero dividido por 2.
    GARCIA IAN
*******************************************************************************/
#include <stdio.h>
#include "funciones.h"
int main()
{
    eParcial* elParcial;
    elParcial=Parcial_new();
    llenar(elParcial);
    MostrarDato(elParcial,MostrarCadena);
    printf("\n");
    MostrarDato(elParcial,MostrarFloat);
    return 0;
}
/*
2)Crear una función mostrarDato que recibe un puntero a función( y todo lo que sea
necesario) y dentro de la función mostrarDato invocar a la función necesaria.
las dos funciones que vamos a pasar por parámetros son estas:

a-hacer la función mostrar cadena que recibe una estructura y muestra su cadena.
b-hacer la función mostrar float que recibe una estructura y muestra su float.

*/