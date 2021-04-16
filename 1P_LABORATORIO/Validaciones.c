#include "Validaciones.h"
int ValidarInt(char NumeroIngresado[])
{
    int i;
    int longitud;
    int resultado;
    longitud=strlen(NumeroIngresado);
    for(i=0;i<longitud;i++)
    {
       if(isdigit(NumeroIngresado[i])!=0)
       {
           resultado=1;
       }
       else
       {
           do
           {
            printf("REingrese numero ingresado\n");
            scanf("%s",NumeroIngresado);
            resultado=ValidarInt(NumeroIngresado);
           }while(resultado!=1);
           break;
       }
    }
    return resultado;
}
int ValidarString(char StringIngresado[])
{
    int i;
    int longitud;
    int resultado;
    longitud=strlen(StringIngresado);
    for(i=0;i<longitud;i++)
    {
       if(isalpha(StringIngresado[i])!=0)
       {
           resultado=1;
       }
       else
       {
            do
            {
                printf("ReIngrese la palabra\n");
                fflush(stdin);
                scanf("%s",StringIngresado);
                resultado=ValidarString(StringIngresado);
            }while(resultado!=1);
       }
    }
    return resultado;
}
char IngresarString(char stringIngresado[50])
{
    __fpurge(stdin);
    scanf("%s",stringIngresado);
    ValidarString(stringIngresado);
    return stringIngresado[50];
    
}
int IngresarInt(char stringIngresado[50])
{
    int HacerInt=-1;
    __fpurge(stdin);
    scanf("%s",stringIngresado);
    ValidarInt(stringIngresado);
    HacerInt=atoi(stringIngresado);
    while(HacerInt<0)
    {
        printf("Error al cargar el numero, REingrese");
        HacerInt=IngresarInt(stringIngresado);
    }
    return HacerInt;
    
}
void ValidacionTipo(char stringIngresado[50])
{
    int devuelto=0;
    do
    {
        printf("Ingrese el tipo ");
        IngresarString(stringIngresado);
        if((strcmp(stringIngresado,"Gato"))==0)
        {
            devuelto==1;
            break;
        }
        else if((strcmp(stringIngresado,"Perro"))==0)
        {
            devuelto==1;
            break;
        }
        else if((strcmp(stringIngresado,"Raro"))==0)
        {
            devuelto==1;
            break;
        }
    }while(devuelto==0);
}
void ValidacionTamanio(char stringIngresado[50])
{
    int devuelto=0;
    do
    {
        printf("Ingrese el tamanio (chico,mediano,grande)");
        IngresarString(stringIngresado);
        if((strcmp(stringIngresado,"chico"))==0)
        {
            devuelto==1;
            break;
        }
        else if((strcmp(stringIngresado,"mediano"))==0)
        {
            devuelto==1;
            break;
        }
        else if((strcmp(stringIngresado,"grande"))==0)
        {
            devuelto==1;
            break;
        }
    }while(devuelto==0);
}