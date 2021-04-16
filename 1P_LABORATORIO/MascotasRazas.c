#include "MascotasRazas.h"


int ImprimirRazaBuscada(eRazas LasRazas[],eMascota LasMascotas[],int i)
{
    int devuelto=0;
    for(int j=0;j<TAM;j++)
    {
        if((LasMascotas[i].idRazas==LasRazas[j].razaID)&&(LasMascotas[i].isEmpty==0&&LasRazas[j].isEmpty==0))
        {
            printf("%15s ",LasRazas[j].descripcion);
            devuelto=LasRazas[j].paisDeOrigen;
            break;
        }
    }
    return devuelto;
}
int ImprimirMascotaSegunRaza(eRazas LasRazas[],eMascota LasMascotas[],int i)
{
    int devuelto=0;
    for(int j=0;j<TAM;j++)
    {
        if((LasMascotas[i].idRazas==LasRazas[j].razaID)&&(LasMascotas[i].isEmpty==0&&LasRazas[j].isEmpty==0))
        {
            printf("%15s ",LasRazas[i].descripcion);
            devuelto=LasMascotas[i].peso;
            break;
        }
    }
    return devuelto;
}
int ImprimirRaza(eRazas LasRazas[],eMascota LasMascotas[],int i)
{
    int devuelto=0;
    if(LasRazas[i].isEmpty==0)
    {
        printf("%15s",LasRazas[i].descripcion);
        devuelto=1;
    }
    return devuelto;
}
void ImprimirRazasConMascotas(eRazas LasRazas[],eMascota LasMascotas[])
{
    int i;
    printf("%15s","Pertenecientes a la raza\n");
    for(i=0;i<TAM;i++)
    {
        if(LasMascotas[i].isEmpty==0)
        {
            ImprimirRazaBuscada(LasRazas,LasMascotas,i);
            ImprimirMascotas(LasMascotas,i);
            printf("\n");
        }
    }
}

void ModificarMascota(eMascota moMascota[],eRazas LasRazas[])
{
    int i;
    int eleccion;
    int menu;
    char stringIngresado[50];
    int intIngresado;
    printf(" LAS MASCOTAS\n");
    for(i=0;i<TAM;i++)
    {
        if(moMascota[i].isEmpty==0)
        {
            printf("%4d%10s\n",moMascota[i].mascotaID,moMascota[i].nombre);
        }
    }
    printf("Elija el id del animal a modificar\n");
    scanf("%d",&eleccion);
    for(i=0;i<TAM;i++)
    {
        if(moMascota[i].mascotaID==eleccion)
        {
            printf("Que va a modificar?\n1.Nombre\n2.Tipo\n3.Sexo\n4.Peso\n5.Edad\n6.Raza\n");
            scanf("%d",&menu);
            switch(menu)
            {
                case 1:
                    printf("Ingrese el nuevo nombre\n");
                    IngresarString(stringIngresado);
                    strcpy(moMascota[i].nombre,stringIngresado);
                    break;
                case 2:
                    printf("Ingrese el nuevo tipo\n");
                    ValidacionTipo(stringIngresado);
                    strcpy(moMascota[i].tipo,stringIngresado);
                    break;
                case 3:
                    printf("Ingrese el nuevo sexo\n");
                    scanf("%c",&moMascota[i].sexo);
                    break;
                case 4:
                    printf("Ingrese el nuevo peso\n");
                    moMascota[i].peso=IngresarInt(stringIngresado);
                    break;
                case 5:
                    printf("Ingrese la nueva edad\n");
                    moMascota[i].edad=IngresarInt(stringIngresado);
                    break;
                case 6:
                    ImprimirMascotas(moMascota,i);
                    printf("%10d\n",moMascota[i].idRazas);
                    
                    printf("Ingrese la nueva raza\n");
                    for(int i=0;i<TAM;i++)
                    {
                        if(LasRazas[i].isEmpty==0)
                        {
                            printf("%d ",i);
                            ImprimirRazaBuscada(LasRazas,moMascota,i);
                            printf("\n");                            
                        }
                    }
                   __fpurge(stdin);
                    moMascota[i].idRazas=ValidacionRaza(stringIngresado,LasRazas);
                    
                    break;
            }
        }
    }
}

int BorrarRazaYMascotas(eMascota noMascota[],eRazas LasRazas[])
{
    int i;
    int eleccion;
    int bandera = 0;
    //HACER VALIDACIONES SI EXISTE RAZA
    
    printf("Elija el id de la raza a dar de baja ");
    scanf("%d",&eleccion);
    for(i=0;i<TAM;i++)
    {
        if(LasRazas[i].razaID==eleccion)
        {
            bandera=1;
            LasRazas[i].isEmpty=1;
            LasRazas[i].razaID=-1;
        }
        if(noMascota[i].idRazas==eleccion)
        {
            noMascota[i].mascotaID=-1;
            noMascota[i].isEmpty=1;
            noMascota[i].edad=0;                
        }
    }
    return bandera;
}
void aniadirMascotas(eMascota inMascota[],eRazas LasRazas[],int cant)
{
    int i;
    char stringIngresado[50];
    char charIngresado;
    int hayEspacio;
    int intIngresado=0;
    int validacion=0;
    hayEspacio=BuscarLibre(inMascota,cant);
    for(i=0;i<cant;i++)
    {
        if(hayEspacio==i)
        {
            printf("Ingrese el tipo(Gato,Perro,Raro)\n");
            ValidacionTipo(stringIngresado);
            strcpy(inMascota[i].tipo,stringIngresado);
            
            printf("Ingrese el nombre\n");
            IngresarString(stringIngresado);
            strcpy(inMascota[i].nombre,stringIngresado);

            printf("Ingrese el sexo(f o m)\n");
            __fpurge(stdin);
            scanf("%c",&charIngresado);
            while(charIngresado!='f'&&charIngresado!='m')
            {
                printf("REingrese el sexo\n");
                __fpurge(stdin);
                scanf("%c",&charIngresado);
            }
            inMascota[i].sexo=charIngresado;
            
            printf("Ingrese la edad\n");
            intIngresado=IngresarInt(stringIngresado);
            inMascota[i].edad=intIngresado;
            
            printf("Ingrese el peso\n");
            intIngresado=IngresarInt(stringIngresado);
            inMascota[i].peso=intIngresado;
            
            printf("Ingrese su Raza\n");
            
            for(int i=0;i<TAM;i++)
            {
                if(ImprimirRaza(LasRazas,inMascota,i))
                {
                printf("%d",LasRazas[i].razaID);
                printf("\n");                    
                }
            }
            inMascota[i].idRazas=ValidacionRaza(stringIngresado,LasRazas);
            inMascota[i].mascotaID=hayEspacio+1;
            
            break;
        }
        else if(hayEspacio==-1)
        {
            printf("\nNO HAY MAS ESPACIO\n\n");
            break;
        }
    }
}