/******************************************************************************
#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas ,pero tengo lugar para 10.
#Tenemos un listado de razas(descripción,tamaño{chico ,mediano o grande},país de
origen)
listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, bélgica
las 5 mascotas están formadas por los siguientes datos:
a- 3 gatos
b- 2 perros
c- los demás datos deben ser hardcodeados por el alumno.
1-Se debe mostrar un listado de mascotas con sus razas y países de origen .
GARCIA IAN
*******************************************************************************/
#include <stdio.h>
#include "MascotasRazasPaises.h"
#include "MascotasRazas.h"

//modularizar
//validaciones ingresarRaza
//valicaionessss
int main()
{
    eMascota LasMascotas[TAM];
    eRazas   LasRazas[TAM];
    ePais   LosPaises[TAM];
    
    Init(LasRazas,LasMascotas,LosPaises);
    InicializarMascotas(LasMascotas);
    HardCodearRazas(LasRazas);
    HardcodearPaises(LosPaises);
    
    int menu;
    int banderaCaseOne=0;
    int segundaEleccion;
    
    do
    {
        printf("1.Añadir\n2.Modificar\n3.Borrar\n4.Mostrar\n10.salir\n");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                    printf("1.Mascotas\n2.Razas");
                    scanf("%d",&segundaEleccion);
                    if(segundaEleccion==1)
                    {
                        aniadirMascotas(LasMascotas,LasRazas,TAM);
                    }
                    else
                    {
                        aniadirRazas(LasRazas,TAM,LosPaises);
                    }
                break;
            case 2:
                    ModificarMascota(LasMascotas,LasRazas);
                break;
            case 3:
                    printf("1.Mascotas\n2.Razas");
                    scanf("%d",&segundaEleccion);
                    switch(segundaEleccion)
                    {
                        case 1:
                           if(BorrarMascota(LasMascotas))
                           {
                               printf("\nBorrado con exito\n");
                           }
                           else{
                               printf("\nError al borrar, reintente\n");
                           }                    
                            break;
                        case 2:
                            if(BorrarRazaYMascotas(LasMascotas,LasRazas))
                           {
                               printf("\nBorrado con exito\n");
                           }
                           else{
                               printf("\nError al borrar, reintente\n");
                           }  
                            break;
                    }
                break;
            case 4:
                    segundaEleccion=0;
                    printf("Que quiere mostrar?\n1.Imprimir MascotasRazasPaises\n2.ImprimirRazasConMascotas\n3.ImprimirPorPeso\n4.ImprimirMasMascotas\n5.ordenarPorCodigoTelefonico\n6.MostrarTipoPeso\n7.MostrarTamPeso\n8.OrdenarTipoPeso\n");
                    scanf("%d",&segundaEleccion);
                    switch(segundaEleccion)
                    {
                        case 1:
                            Imprimir(LasMascotas,LasRazas,LosPaises);
                            printf("\n");
                            break;
                        case 2:    
                            ImprimirRazasConMascotas(LasRazas,LasMascotas);
                            printf("\n");
                            break;
                        case 3:
                            ImprimirPorPeso(LasRazas,LasMascotas,LosPaises);
                            printf("\n");
                            break;
                        case 4:
                            ImprimirMasMascotas(LasRazas,LasMascotas,LosPaises);
                            printf("\n");
                            break;
                        case 5:
                            ordenarCodigo(LasRazas,LasMascotas,LosPaises);
                            printf("\n");
                            break;
                        case 6:
                            MostrarTipoPeso(LasMascotas);
                            printf("\n");
                            break;
                        case 7:
                            MostrarTamPeso(LasMascotas,LasRazas,LosPaises);
                            printf("\n");
                            break;
                        case 8:
                            OrdenarTipoPeso(LasMascotas);
                            printf("\n");
                            break;                            
                    }

                break;
            case 10:
                menu=10;
                printf("Hasta la proxima");
                break;
            default:
                printf("Error! reintente\n");
                break;
        }
    }while(menu!=10);
    
    return 0;
}
