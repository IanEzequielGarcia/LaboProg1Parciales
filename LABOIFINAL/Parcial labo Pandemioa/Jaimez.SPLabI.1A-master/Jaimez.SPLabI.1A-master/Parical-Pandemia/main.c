#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "paises.h"
#include "controller.h"

int menu();

int main()
{
    char confirm;
    char seguir = 's';
    int flagTexto = 0;

    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaFiltrada;

    if(listaPaises == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }
    printf("Lista declarada!!!\n");

    do{
        switch(menu())
        {
            case 1:
                if(!cargarTexto("pandemia.csv", listaPaises))
                {
                    flagTexto = 1;
                }
                break;
            case 2:
            	if(flagTexto == 1)
				{
            		mostrarPaises(listaPaises);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 3:
                if(flagTexto == 1)
            	{
            	    listaPaises = ll_map(listaPaises, set_cantRecuperados);
                    listaPaises = ll_map(listaPaises, set_cantMuertos);
                    listaPaises = ll_map(listaPaises, set_cantInfectados);

                    printf("Estadisticas asignadas con exito!\n");
                    guardarComoTexto("pandemia.csv", listaPaises);
            	}
            	else
            	{
            		printf("Error. No hay archivos registrados.\n");
            	}
            	break;
            case 4:
                if(flagTexto == 1)
                {
                    printf("------------------------------------------------\n");
                    listaFiltrada =  ll_filter(listaPaises, filtrarxExitosos);
                    guardarComoTexto("paisesExitosos.csv", listaFiltrada);
                    printf("**** Los paises fueron filtrados por exitosos y guardados en -paisesExitosos.csv- ****\n\n");
                    printf("------------------------------------------------\n");

                }
                else
                {
                    printf("Error. No hay archivos registrados.\n");
                }
            	break;
            case 5:
            	if(flagTexto == 1)
                {
                    printf("------------------------------------------------\n");
                    listaFiltrada =  ll_filter(listaPaises, filtrarxPerjudicados);
                    guardarComoTexto("paisesPerjudicados.csv", listaFiltrada);
                    printf("**** Los paises fueron filtrados por mas perjudicados y guardados en -paisesPerjudicados.csv- ****\n\n");
                    printf("------------------------------------------------\n");
                }
                else
                {
                    printf("Error. No hay archivos registrados.\n");
                }
            	break;
            case 6:
            	if(flagTexto == 1)
				{
            		ordenarPaises(listaPaises);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 7:
                if(flagTexto == 1)
                {
                    paisesMasCatigados(listaPaises);
                    mostrarPaises(listaPaises);
                }
                else
                {
                    printf("Error. No hay archivos registrados.\n");
                }
            	break;
            case 8:
            	printf("Confirma salida? s/n: ");
            	fflush(stdin);
            	scanf("%c", &confirm);
            	if(confirm == 's')
            	{
            		seguir = 'n';
            	}
            	break;
        }

        system("pause");

    }while(seguir == 's');

    return 0;
}

//---------------------------------------------------------------------------------------------------

int menu()
{
    int option;

    system("cls");
    printf("***** Sistema de paises durante la pandemia ******\n\n");
    printf("1. Cargar archivos\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar por paises exitosos\n");
    printf("5. Filtrar por paises mas perjudicados\n");
    printf("6. Ordenar por nivel de infeccion\n");
    printf("7. Mostrar mas castigado\n");
    printf("8. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

//---------------------------------------------------------------------------------------------------

