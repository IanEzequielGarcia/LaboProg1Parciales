#include "Razas.h"
void HardCodearRazas(eRazas LasRazas[])
{
    char descripcion[][20]={"siames","doberman","persa","pastorBelga","dogoArgentino","pastorAle"};
    char tamanio[][20]={"chico","grande","mediano","grande","grande","grande"};
    int paisDeOrigen[]={0,1,2,3,4,1};
    int isEmpty[]={0,0,0,0,0,0};
    int razaID[]={0,1,2,3,4,5};
    /*Pasar estos valores a  un array de mascotas*/
    int i;
    for(i=0;i<6;i++)
    {
        strcpy(LasRazas[i].descripcion,descripcion[i]);
        strcpy(LasRazas[i].tamanio,tamanio[i]);
        LasRazas[i].paisDeOrigen=paisDeOrigen[i];
        LasRazas[i].isEmpty=isEmpty[i];
        LasRazas[i].razaID=razaID[i];
    }
    
}
int BuscarLibreRazas(eRazas LasRazas[],int cant)
{
    int i;
    int haylibre=-1;

    for(i=0;i<cant;i++)
    {
        if(LasRazas[i].isEmpty==1)
        {
            haylibre=i;
            LasRazas[i].isEmpty=0;
            break;
        }
    }
    return haylibre;
}
int ValidacionRaza(char stringIngresado[50],eRazas LasRazas[])
{
    int devuelto=0;
    int bandera=0;
    int intIngresado;
    do
    {
        printf("Ingrese Raza\n");
        intIngresado=IngresarInt(stringIngresado);
        for(int i=0;i<10;i++)
        {
            if(intIngresado==LasRazas[i].razaID)
            {
                bandera=1;
                break;
            }
            else if(bandera==0&&i==9)
            {
                printf("ERROR REINGRESE\n");
            }
            
        }
    }while(bandera==0);
    return intIngresado;
}