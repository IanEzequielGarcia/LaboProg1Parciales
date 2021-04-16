#include "MascotasRazasPaises.h"
void Imprimir(eMascota LasMascotas[],eRazas LasRazas[],ePais LosPaises[])
{
    int i;      //tamaño raza y mascotas) y raza desconocida recorrer mascota y traer raza y llamar funcion que muestre printf
    int j;      //mostrar mascota y raza por parametro
    int raza;   // mostrar llamar a funcion raza y mascota que paso por parametro
    int devuelto;

    printf("\n%10sMASCOTAS %20s ORIGEN\n"," "," ");
    for(i=0;i<TAM;i++)
    {
        raza=LasRazas[i].paisDeOrigen;
        if(LasMascotas[i].isEmpty==0)
        {
            ImprimirMascotas(LasMascotas,i);
            printf("%15s",LasMascotas[i].tipo);
            devuelto=ImprimirRazaBuscada(LasRazas,LasMascotas,i);
            MostrarPaises(LosPaises,devuelto);
            printf("\n");
        }
    }
}
void ImprimirPorPeso(eRazas LasRazas[],eMascota LasMascotas[],ePais LosPaises[])
{
    int i;
    int j;

    for(i=0;i<TAM-1;i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(LasMascotas[i].isEmpty==0&&LasMascotas[j].isEmpty==0)
            {
                if(LasMascotas[i].peso>LasMascotas[j].peso)
                {
                    BubbleSort(LasRazas, LasMascotas,LosPaises,i,j);
                }
            }
        }
    }
    printf("Ordenados por peso\n");
    for(i=0;i<TAM;i++)
    {
        if(LasMascotas[i].isEmpty==0)
        {
           ImprimirMascotas(LasMascotas,i);
           printf(" %15d kilo/s",LasMascotas[i].peso);
           printf("\n");
        }
    }
}
void BubbleSort(eRazas LasRazas[],eMascota LasMascotas[],ePais LosPaises[],int i,int j)
{
    char auxString[64];
    int auxInt;
    char auxChar;
    
    strcpy(auxString,LasMascotas[i].nombre);
    strcpy(LasMascotas[i].nombre,LasMascotas[j].nombre);
    strcpy(LasMascotas[j].nombre,auxString);
    
    strcpy(auxString,LasMascotas[i].tipo);
    strcpy(LasMascotas[i].tipo,LasMascotas[j].tipo);
    strcpy(LasMascotas[j].tipo,auxString);
    
    auxChar=LasMascotas[i].sexo;
    LasMascotas[i].sexo=LasMascotas[j].sexo;
    LasMascotas[j].sexo=auxChar;
    
    auxInt=LasMascotas[i].peso;
    LasMascotas[i].peso=LasMascotas[j].peso;
    LasMascotas[j].peso=auxInt;
    
    auxInt=LasMascotas[i].edad;
    LasMascotas[i].edad=LasMascotas[j].edad;
    LasMascotas[j].edad=auxInt;
    
    auxInt=LasMascotas[i].mascotaID;
    LasMascotas[i].mascotaID=LasMascotas[j].mascotaID;
    LasMascotas[j].mascotaID=auxInt;
    
    auxInt=LasMascotas[i].idRazas;
    LasMascotas[i].idRazas=LasMascotas[j].idRazas;
    LasMascotas[j].idRazas=auxInt;
    
    BubbleSortTelefonos(LasRazas,LasMascotas,LosPaises,i,j);
    
}
int BubbleSortTelefonos(eRazas LasRazas[],eMascota LasMascotas[],ePais LosPaises[],int i,int j)
{
    int sePudo=0;
    char auxString[64];
    int auxInt;
    
    auxInt=LosPaises[i].paisID;
    LosPaises[i].paisID=LosPaises[j].paisID;
    LosPaises[j].paisID=auxInt;
    
    auxInt=LosPaises[i].codigoTelefonico;
    LosPaises[i].codigoTelefonico=LosPaises[j].codigoTelefonico;
    LosPaises[j].codigoTelefonico=auxInt;
    
    strcpy(auxString,LosPaises[i].nombreDePais);
    strcpy(LosPaises[i].nombreDePais,LosPaises[j].nombreDePais);
    strcpy(LosPaises[j].nombreDePais,auxString);
    
    strcpy(auxString,LosPaises[i].continente);
    strcpy(LosPaises[i].continente,LosPaises[j].continente);
    strcpy(LosPaises[j].continente,auxString);
    sePudo=1;
    
    return sePudo;
}
void ImprimirMasMascotas(eRazas LasRazas[],eMascota LasMascotas[],ePais LosPaises[])
{
    int i;
    int j;
    int arrayContador[]={0,0,0,0,0,0,0,0,0,0};
    int maximo=0,bandera=0,indiceMaximo;
    for(j=0;j<TAM;j++)
    {
        if(LasRazas[j].isEmpty==0)
        {
            for(i=0;i<TAM;i++)
            {
                if((LasMascotas[i].idRazas==LasRazas[j].razaID)&&LasMascotas[i].isEmpty==0)
                {
                    arrayContador[j]++;
                }
            }
        }
    }
    for(i=0;i<TAM;i++)
    {
        if(LasMascotas[i].isEmpty==0)
        {
            if(arrayContador[i]>maximo||bandera==0)
            {
                maximo=arrayContador[i];
                indiceMaximo=LasMascotas[i].idRazas;
                bandera=1;
            }            
        }
    }
    printf("Pais con mas mascotas\n");
    printf("%10s",LosPaises[indiceMaximo].nombreDePais);
    printf("\n");
}
void Init(eRazas LasRazas[],eMascota LasMascotas[],ePais LosPaises[])
{
    int i;
    for(i=1;i<TAM;i++)
    {
        LasMascotas[i].isEmpty=1;
        LasRazas[i].isEmpty=1;
        LosPaises[i].isEmpty=1;
    }
}
void ordenarCodigo(eRazas LasRazas[],eMascota LasMascotas[],ePais LosPaises[])
{
    int i;
    int j;

    for(i=0;i<TAM-1;i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(LosPaises[i].isEmpty==0&&LosPaises[j].isEmpty==0)
            {
                if(LosPaises[i].codigoTelefonico<LosPaises[j].codigoTelefonico)
                {
                    BubbleSort(LasRazas, LasMascotas,LosPaises,i,j);
                }
            }
        }
    }
    for(i=0;i<TAM;i++)
    {
        MostrarPaises(LosPaises,i);
        printf(" ");
    }
    printf("\n");
}
void aniadirRazas(eRazas LasRazas[],int cant,ePais LosPaises[])
{
    int i;
    char stringIngresado[50];
    char charIngresado;
    int hayEspacio;
    int HacerInt=0;
    int validacion=0;
    hayEspacio=BuscarLibreRazas(LasRazas,TAM);
    for(i=0;i<cant;i++)
    {
        if(hayEspacio==i)
        {
            printf("Ingrese la descripcion\n");
            IngresarString(stringIngresado);
            strcpy(LasRazas[i].descripcion,stringIngresado);
            
            printf("Ingrese el tamanio\n");
            ValidacionTamanio(stringIngresado);
            strcpy(LasRazas[i].tamanio,stringIngresado);
            
            for(int j=0;j<TAM;j++)
            {
               if(MostrarPaises(LosPaises,j))
               {
                   printf(" %d\n",j);
               }
            }
            printf("Ingrese el pais\n");//verificar que exista
            __fpurge(stdin);
            HacerInt=IngresarInt(stringIngresado);
            
            LasRazas[i].paisDeOrigen=HacerInt;
            LasRazas[i].razaID=hayEspacio;
            LasRazas[i].isEmpty=0;
            break;
        }
        else if(hayEspacio==-1)
        {
            printf("\nNO HAY MAS ESPACIO\n\n");
            break;
        }
    }
}
void MostrarTamPeso(eMascota LasMascotas[],eRazas LasRazas[],ePais LosPaises[])
{
    int tamAnimal=0;
    int devuelto=0;
    int pesoTotalAnimales=0;
    char stringIngresado[50];
    int arrayRazas[]={0,0,0,0,0,0,0,0,0,0};
    ValidacionTamanio(stringIngresado);
    
    contadorTamanio(LasMascotas,LasRazas,&tamAnimal,&pesoTotalAnimales,stringIngresado,arrayRazas);
    
    printf("%10s nombre peso %5s razas  paisDeOrigen\n"," "," ");
    for(int i=0;i<TAM;i++)
    {
        if(arrayRazas[i]>0)
        {
            ImprimirMascotas(LasMascotas,i);
            //devuelto=ImprimirMascotaSegunRaza(LasRazas,LasMascotas,i);
            printf(" %d ",LasMascotas[i].peso);
            devuelto=ImprimirRazaBuscada(LasRazas,LasMascotas,i);
            MostrarPaises(LosPaises,devuelto);
            printf(" \n");
        }
    }
    printf("Suma de peso %d\n",pesoTotalAnimales);
}
int contadorTamanio(eMascota LasMascotas[],eRazas LasRazas[],int* tamAnimal,int* pesoTotalAnimales,char stringIngresado[],int arrayRazas[])
{
    int i;
    int sePudo=0;
    for(i=0;i<TAM;i++)
    {
        if(LasRazas[i].isEmpty==0&&LasMascotas[i].isEmpty==0)
        {
            if((strcmp(LasRazas[i].tamanio,stringIngresado))==0)
            {
                *tamAnimal+=LasMascotas[i].peso;
                arrayRazas[i]++;
            }
        }
    }
    *pesoTotalAnimales=*tamAnimal;
    sePudo=1;
    return sePudo;
}