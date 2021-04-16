#include "funciones.h"
eParcial* Parcial_new()
{
    eParcial* elParcial=NULL;
    elParcial=(eParcial*)malloc(sizeof(eParcial));
    return elParcial;
}
void llenar(eParcial* elParcial)
{
    char String[]="Juan";
    char elChar='c';
    char intStr[]="12";
    constructorParametrizado(elParcial,String,elChar,intStr);
}
void constructorParametrizado(eParcial* elParcial,char String[],char elChar,char intStr[])
{
    int realInt;
    realInt=atoi(intStr);
    employee_setInt(elParcial,realInt);
    employee_setString(elParcial,String);
    employee_setChar(elParcial,elChar);
    employee_setFloat(elParcial,realInt);
}

//SETTERS
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
int employee_setFloat(eParcial* this,int ingresado)
{
    float resultante;
    int setteo=0;
    if(this!=NULL)
    {
        resultante=(float)ingresado/2;
        this->elFloat=resultante;
        setteo = 1;
    }
    return setteo;
}
// GETTERS
int employee_getString(eParcial* this,char* String)
{
    int getteo=0;
    if(this!=NULL && String!=NULL)
    {
        strcpy(String,this->string);
        getteo = 1;
    }
     return getteo;
}
int employee_getFloat(eParcial* this,float* getFloat)
{
    int getteo=0;
    if(this!=NULL && getFloat!=NULL)
    {
        *getFloat=this->elFloat;
        getteo = 1;
    }
    return getteo;
}
//PUNTO 2
void MostrarDato(eParcial* miParcial,void(*miFunc)(eParcial* parcialBuscado))
{
    miFunc(miParcial);
}
void MostrarCadena(eParcial* miParcial)
{
    char stringIngresado[64];
    employee_getString(miParcial,stringIngresado);

    printf("%s",stringIngresado);
}
void MostrarFloat(eParcial* miParcial)
{
    float floatIngresado;
    employee_getFloat(miParcial,&floatIngresado);

    printf("%.2f",floatIngresado);
}