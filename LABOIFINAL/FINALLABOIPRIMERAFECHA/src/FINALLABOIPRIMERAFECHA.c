#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Funciones.h"
#include "SECABA.h"
#include "Controller.h"
int main()
{
    int menu,bandera=0;
    LinkedList* miLista=NULL;
    char path[64];
    do
    {
        printf("Que quiere hacer?\n1.LEERARCHIVO\n"
        		"2.Mostrar\n3.ll_map\n4.FILTRAR\n5.Sort\n6.guardar\n7.salir");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                miLista=(LinkedList*) ll_newLinkedList();
                printf("Que archivo quiere cargar?\n");
                //fflush(stdin);
                //strcpy(path,"/home/ian/eclipse-workspace/OtraPracticaFinal/");
                //scanf("%s",path);
                strcpy(path,"/home/ian/eclipse-workspace/FINALLABOIPRIMERAFECHA/enduro.csv");
                if(!(controller_loadFromText(path, miLista)))
                {
                    printf("\n\nError al leer el archivo\n\n\n");
                }else{
                	bandera=1;
                }
                break;
            case 2:
                if(bandera==0||!(controller_ListeParticipantes(miLista)))
                {
                    printf("No se pudo mostrar la lista\n");
                }
                break;
            case 3:
            		ll_map(miLista,Mapear);
            		controller_ListeParticipantes(miLista);
                break;
            case 4:
            		FiltradorBicicletas(miLista);
				break;
            case 5:
            	Punto6Sort(miLista);

				break;
            case 6:
            		if(bandera==1)
            		{
    					controller_saveAsText("nuevaLista.csv",miLista);
            		}else{
            			printf("Nada que guardar\n");
            		}

					break;
			//case 6:
					//MostrarParcial(miLista);
					//Punto6LL(miLista);
					//break;
			//case 7:
					//LL_Mapear(miLista);
					//break;
        }
    }while(menu!=7);
    return 0;
}
