 #include "Mascotas.h"
void InicializarMascotas(eMascota LasMascotas[])
{
    
    char nombre[][20]={"Michi","Bobby","Gatito Bonito","PerroBomba","GatoLoco","Dio","Teo"};
    int edad[]={3,2,4,1,3,5,8};
    char sexo[]={'f','f','m','m','f','m','m'};
    char tipo[][20]={"Gato","Perro","Gato","Perro","Gato","Perro","Perro"};
    int isEmpty[]={0,0,0,0,0,0,0};
    int mascotaID[]={1,2,3,4,5,6,7};
    int idRazas[]={0,1,2,3,0,4,5};
    int peso[]={1,4,3,8,1,20,15};
    /*Pasar estos valores a  un array de mascotas*/
    int i;
    for(i=0;i<7;i++)
    {
        strcpy(LasMascotas[i].nombre,nombre[i]);
        LasMascotas[i].edad=edad[i];
        LasMascotas[i].sexo=sexo[i];
        strcpy(LasMascotas[i].tipo,tipo[i]);
        LasMascotas[i].isEmpty=isEmpty[i];
        LasMascotas[i].mascotaID=mascotaID[i];
        LasMascotas[i].idRazas=idRazas[i];
        LasMascotas[i].peso=peso[i];
    }
}
int BuscarLibre(eMascota LibreMascota[],int cant)
{
    int i;
    int haylibre=-1;

    for(i=1;i<cant;i++)
    {
        if(LibreMascota[i].isEmpty==1)
        {
            haylibre=i;
            LibreMascota[i].isEmpty=0;
            break;
        }
    }
    return haylibre;
}

int BorrarMascota(eMascota noMascota[])
{
    int i;
    int eleccion;
    int bandera = 0;
    //printear
    
    printf("Elija el id del animal a dar de baja ");
    scanf("%d",&eleccion);
    for(i=0;i<TAM;i++)
    {
        if(noMascota[i].mascotaID==eleccion)
        {
            bandera=1;
            noMascota[i].mascotaID=-1;
            noMascota[i].isEmpty=1;
            noMascota[i].edad=0;
        }
    }
    return bandera;
}
void ImprimirMascotas(eMascota LasMascotas[],int i)
{
    if(LasMascotas[i].isEmpty==0)
    {
        printf("%15s ",LasMascotas[i].nombre);
    }
}
void MostrarTipoPeso(eMascota LasMascotas[])
{//crear array con listado de tipos y compararlo por item y mascota, si coincide hacer el contador (ESTANDARIZAR ASI SOLO HAGO UNO PARA TODAS LAS RAZAS)
    int pesoGatos=0;
    int pesoPerros=0;
    int pesoRaro=0;
    
    int cantidadGatos=0;
    int cantidadPerros=0;
    int cantidadRaros=0;
    
    float promedioGatos=0;
    float promedioPerros=0;
    float promedioRaros=0;
    
    int i;
    contadorTipos(LasMascotas,&pesoGatos,&pesoPerros,&pesoRaro,&cantidadGatos,&cantidadPerros,&cantidadRaros);
    if(cantidadRaros==0)
    {
        promedioRaros=0;
    }else{
        promedioRaros=  (float)pesoRaro/cantidadRaros;
    }
    if(cantidadGatos==0)
    {
        promedioGatos=0;
    }else{
        promedioGatos= (float)pesoGatos/cantidadGatos;
    }
    if(cantidadPerros==0)
    {
        promedioPerros=0;
    }else{
        promedioPerros= (float)pesoPerros/cantidadPerros;
    }
    
    printf("%10s peso total%5s cant mascotas\n"," "," ");
    printf("gatos %10d %5s %5d %5s %.2f\n",pesoGatos," ",cantidadGatos," ",promedioGatos);
    printf("perro %10d %5s %5d %5s %.2f\n",pesoPerros," ",cantidadPerros," ",promedioPerros);
    printf("raros %10d %5s %5d %5s %.2f\n",pesoRaro," ",cantidadRaros," ",promedioRaros);

}
int contadorTipos(eMascota LasMascotas[],int* pesoGatos, int* pesoPerros, int* pesoRaro,int* cantidadGatos,int* cantidadPerros,int* cantidadRaros)
{
    int i;
    int sePudo=0;
    for(i=0;i<TAM;i++)
    {
        if(LasMascotas[i].isEmpty==0)
        {
            if((strcmp(LasMascotas[i].tipo,"Gato"))==0)
            {
                *pesoGatos+=LasMascotas[i].peso;
                *cantidadGatos=*cantidadGatos+1;
            }
            else if((strcmp(LasMascotas[i].tipo,"Perro"))==0)
            {
                *pesoPerros+=LasMascotas[i].peso;
                *cantidadPerros=*cantidadPerros+1;
            }
            else
            {
                *pesoRaro+=LasMascotas[i].peso;
                *cantidadRaros=*cantidadRaros+1;
            }            
        }
    }
   
    sePudo=1;
    return sePudo;
}
int OrdenarTipoPeso(eMascota LasMascotas[])
{
    int Gatos[]={0,0,0,0,0,0,0,0,0,0};
    int Perros[]={0,0,0,0,0,0,0,0,0,0};
    //int Raro[]={0,0,0,0,0,0,0,0,0,0};
    int raza=0;
    for(int i=0;i<TAM;i++)
    {
        if((strcmp(LasMascotas[i].tipo,"Gato"))==0)
        {
            Gatos[i]++;
        }
        else if((strcmp(LasMascotas[i].tipo,"Perro"))==0)
        {
            Perros[i]++;
        }
        //else
        //{
        //    Raro[i]++;
        //}         
    }
    for(int i=0;i<TAM;i++)
    {
        if(Gatos[i]>0&&raza==0)
        {
            ImprimirMascotas(LasMascotas,i);
            if(!(Gatos[i+1]>0))
            {
                raza=1;
            }
        }
        else if(Perros[i]>0&&raza==1)
        {
            ImprimirMascotas(LasMascotas,i);
            if(!(Perros[i+1]>0))
            {
                raza=2;
            }
        }
        else
        {
            ImprimirMascotas(LasMascotas,i);
        }
    }
    return 0;
}