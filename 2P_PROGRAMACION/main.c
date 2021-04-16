/******************************************************************************
1. Realizar un párrafo en donde se pueda ver la relación entre los siguientes términos: Memoria dinámica, stack, pila, heap, malloc, free, puntero.
(El texto debe ser coherente y no deberá definir de manera aislada cada término). *


.--------------------------------GARCIA IAN------------------------------------
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    las variables ocupan un espacio en la memoria stack, si las variables son punteros y estos fueron pasado por la funcion malloc,
    entonces dejan de ocupar espacio en la pila y pasan ocupar un espacio en el heap, ademas se puede volver memoria dinámico con un realloc.
    Cuando se este por terminar la ejecución de un programa con punteros malloqueados, es buena practica usar la funcion free(puntero) para liberar el 
    espacio en el heap que estaban ocupando, igualmente cuando se termina el programa el sist. operativo lo hace por nosotros.
*/

/*
    2. Diseñar una estructura con 3 campos (uno entero, uno char y una cadena).
    Realizar un constructor por defecto y uno parametrizado. Respetar las reglas de estilo vistas en la cátedra. *
*/

typedef struct
{
    int elInt;
    char string[50];
    char elChar;
}eParcial;

eParcial* Parcial_new();
int employee_setChar(eParcial* ,char );
void constructorParametrizado(eParcial* ,char [],char ,char []);
int employee_setInt(eParcial* ,int );
int employee_setString(eParcial* ,char* );
void cargarStruct(eParcial* );
int mostrarStruct(eParcial* );

int main()
{
    eParcial* elParcial;
    elParcial=Parcial_new();
    cargarStruct(elParcial);
    mostrarStruct(elParcial);
    return 0;
}

eParcial* Parcial_new()
{
    eParcial* elParcial=NULL;
    elParcial=(eParcial*)malloc(sizeof(eParcial));
    return elParcial;
}
void constructorParametrizado(eParcial* elParcial,char String[],char elChar,char intStr[])
{
    int realInt;
    realInt=atoi(intStr);
    employee_setInt(elParcial,realInt);
    employee_setString(elParcial,String);
    employee_setChar(elParcial,elChar);
}
int employee_setInt(eParcial* this,int ingresado)
{
    int setteo=0;
    if(this!=NULL)
    {
        this->elInt=ingresado;
        setteo = 1;
    }
    return setteo;
}
int employee_setString(eParcial* this,char* String)
{
    int setteo=0;
    if(this!=NULL && *String!='\0')
    {
        strcpy(this->string,String);
        setteo=1;
    }
    return setteo;
}
int employee_setChar(eParcial* this,char ingresado)
{
    int setteo=0;
    if(this!=NULL && ingresado!='\0')
    {
       this->elChar=ingresado;
        setteo=1;
    }
    return setteo;
}
/*
3. Crear dos funciones. Una que permita guardar en un archivo binario, un dato del tipo de la estructura creada en el punto 2.
La otra leerá dicho dato y lo mostrará por pantalla. En todos los casos se utilizará memoria dinámica. Respetar las reglas de estilo vistas en la cátedra. *
*/
void cargarStruct(eParcial* elParcial)
{
    FILE* pArchivo;
    
    char String[50];
    char auxChar[3];
    char elChar;
    char elInt[15];
    
    int cant;
    pArchivo = fopen("nombre.txt", "r");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            cant=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",String,auxChar,elInt);
            if(cant==3)
            {
                elChar=auxChar[0];
                constructorParametrizado(elParcial,String,elChar,elInt);
            }
        }
        
    }
    fclose(pArchivo);    
}
int mostrarStruct(eParcial* elParcial)
{
    int sePudo=0;
    printf("%s %d %c\n",elParcial->string,elParcial->elInt,elParcial->elChar);
    printf("\n");
    sePudo=1;

    return sePudo;
}