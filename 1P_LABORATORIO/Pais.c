#include "Pais.h"
void HardcodearPaises(ePais LosPaises[])
{
    char nombreDePais[][20]={"tailandia","alemania","persia","belgica","argentina"};
    char continente[][20]={"asia","europa","asia","europa","america"};
    char codigoTelefonico[]={66,49,98,32,54};
    int isEmpty[]={0,0,0,0,0};
    int paisID[]={0,1,2,3,4};
    int i;
    for(i=0;i<5;i++)
    {
        strcpy(LosPaises[i].nombreDePais,nombreDePais[i]);
        strcpy(LosPaises[i].continente,continente[i]);
        LosPaises[i].codigoTelefonico=codigoTelefonico[i];
        LosPaises[i].isEmpty=isEmpty[i];
        LosPaises[i].paisID=paisID[i];
    }
}
int MostrarPaises(ePais LosPaises[],int j)
{
    int i;
    int sePudo=0;
    if(LosPaises[j].isEmpty==0)
    {
        printf("%s ",LosPaises[j].nombreDePais);
        sePudo=1;
    }
    return sePudo;
}
