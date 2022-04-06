#include <stdlib.h>
#include "SECABA.h"
#include <string.h>
eParticipantes* eParticipantes_new()
{
    eParticipantes* nuevoEmpleado=NULL;
    nuevoEmpleado=(eParticipantes*)malloc(sizeof(eParticipantes));
   return nuevoEmpleado;
}
eParticipantes* eParticipantes_newParametros(char* idStr,char* nombreStr,char* stringStr,char*TiempoStr,char* promedioStr)
{
    eParticipantes* EmpleadoAux;
    EmpleadoAux=eParticipantes_new();
    if(EmpleadoAux!=NULL)
    {
        eParticipantes_setId(EmpleadoAux,atoi(idStr));
        eParticipantes_setNombre(EmpleadoAux,nombreStr);
        eParticipantes_setTipo(EmpleadoAux,stringStr);
        eParticipantes_setTiempo(EmpleadoAux,atoi(TiempoStr));
        eParticipantes_setPromedio(EmpleadoAux,atof(promedioStr));
    }
    return EmpleadoAux;
}
int eParticipantes_getId(eParticipantes* this,int* id)
{
    int getteo=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        getteo = 1;
    }
    return getteo;
}

int eParticipantes_setId(eParticipantes* this,int id)
{
    int setteo=0;
    if(this!=NULL && id!=-1)
    {
        this->id=id;
        setteo = 1;
    }
    return setteo;
}
int eParticipantes_setTipo(eParticipantes* this,char* string)
{
    int setteo=0;
    if(this!=NULL && *string!='\0')
    {
        strcpy(this->tipo,string);
        setteo=1;
    }
    return setteo;
}
int eParticipantes_getTipo(eParticipantes* this,char* string)
{
    int getteo=0;
    if(this!=NULL && string!=NULL)
    {
        strcpy(string,this->tipo);
        getteo = 1;
    }
     return getteo;
}
int eParticipantes_setNombre(eParticipantes* this,char* string)
{
    int setteo=0;
    if(this!=NULL && *string!='\0')
    {
        strcpy(this->nombre,string);
        setteo=1;
    }
    return setteo;
}
int eParticipantes_getNombre(eParticipantes* this,char* string)
{
    int getteo=0;
    if(this!=NULL && string!=NULL)
    {
        strcpy(string,this->nombre);
        getteo = 1;
    }
     return getteo;
}
int eParticipantes_getPromedio(eParticipantes* this,float* ingresado)
{
    int getteo=0;
    if(this!=NULL && ingresado!=NULL)
    {
        *ingresado=this->promedio;
        getteo = 1;
    }
    return getteo;
}

int eParticipantes_setPromedio(eParticipantes* this,float ingresado)
{
    int setteo=0;
    if(this!=NULL && ingresado!=-1)
    {
        this->promedio=ingresado;
        setteo = 1;
    }
    return setteo;
}
int eParticipantes_getTiempo(eParticipantes* this,int* ingresado)
{
    int getteo=0;
    if(this!=NULL && ingresado!=NULL)
    {
        *ingresado=this->tiempo;
        getteo = 1;
    }
    return getteo;
}

int eParticipantes_setTiempo(eParticipantes* this,int ingresado)
{
    int setteo=0;
    if(this!=NULL && ingresado!=-1)
    {
        this->tiempo=ingresado;
        setteo = 1;
    }
    return setteo;
}
