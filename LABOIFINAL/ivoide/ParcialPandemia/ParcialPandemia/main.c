#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Countries.h"
#include "Controller.h"
#include "Common.h"
#define TRUE 1
#define FALSE 0
int main()
{
    int cargueDatosPrimero = FALSE;
    int exit = FALSE;
    int option ;
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaFiltrada;

    if(listaPaises == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        return 0;
    }
    option =common_getMenu("1. Cargar archivos\n2. Imprimir lista\n3. Asignar estadisticas\n4. Filtrar por paises exitosos\n5. Filtrar por paises mas perjudicados\n6. Ordenar por nivel de infeccion\n7. Mostrar mas castigado\n8. Salir\n","Opcion invalida. Reingrese",1,8,3);
    char * pathTxt = "C:\\Programacion1\\Archivos\\";

    do
    {
        switch(option)
        {
        case 1:

            if(!controller_LoadFromText(strcat(pathTxt,"pandemia.csv"), listaPaises))
            {
                cargueDatosPrimero = 1;
            }
            break;
        case 2:
            if(cargueDatosPrimero)
            {
                controller_ShowCountries(listaPaises);
            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            break;
        case 3:
            if(cargueDatosPrimero)
            {
                listaPaises = ll_map(listaPaises, set_QttyRecoveries);
                listaPaises = ll_map(listaPaises, set_QttyDead);
                listaPaises = ll_map(listaPaises, set_QttyInfecteds);

                printf("Estadisticas asignadas con exito!\n");
                controller_saveAsText(pathTxt, listaPaises);
            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            break;
        case 4:
            if(cargueDatosPrimero)
            {
                printf("------------------------------------------------\n");
                listaFiltrada =  ll_filter(listaPaises, FilterBySuccessful);
                controller_saveAsText(strcat(pathTxt,"paisesExitosos.csv"), listaFiltrada);
                printf("**** Los paises fueron filtrados por exitosos y guardados en -paisesExitosos.csv- ****\n\n");
                printf("------------------------------------------------\n");

            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            break;
        case 5:
            if(cargueDatosPrimero)
            {
                printf("------------------------------------------------\n");
                listaFiltrada =  ll_filter(listaPaises, FiterByInjured);
                controller_saveAsText(strcat(pathTxt,"paisesPerjudicados.csv"), listaFiltrada);
                printf("**** Los paises fueron filtrados por mas perjudicados y guardados en -paisesPerjudicados.csv- ****\n\n");
                printf("------------------------------------------------\n");
            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            break;
        case 6:
            if(cargueDatosPrimero)
            {
                controller_sortCountries(listaPaises);
            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            break;
        case 7:
            if(cargueDatosPrimero)
            {
                CountriesMorePunisheds(listaPaises);
                controller_ShowCountries(listaPaises);
            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            break;
        case 8:
            printf("El sistema se va a cerrar\n");
            exit = TRUE;
            break;
        }

        if(!exit)
        {
            printf("¿Desea continuar operador? YES 1 NOT 0\n");
            scanf("%d",&exit);
            exit = !exit;
            system("cls");
        }
        if(!exit)
        {
            option =common_getMenu("1. Cargar archivos\n2. Imprimir lista\n3. Asignar estadisticas\n4. Filtrar por paises exitosos\n5. Filtrar por paises mas perjudicados\n6. Ordenar por nivel de infeccion\n7. Mostrar mas castigado\n8. Salir\n","Opcion invalida. Reingrese",1,8,3);
        }

    }
    while(!exit && option != 8 );
    // libero la lista de memoria
    ll_deleteLinkedList(listaPaises);
    ll_deleteLinkedList(listaFiltrada);
    return 0;
}
