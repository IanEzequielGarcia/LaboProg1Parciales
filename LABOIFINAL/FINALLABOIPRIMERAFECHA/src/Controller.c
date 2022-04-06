#include "Controller.h"
int controller_loadFromText(char* path, LinkedList* laLinkedLIst)
{
    int sePudo=0;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");

    if(pArchivo!=NULL)
    {
        if(parser_FromText(pArchivo, laLinkedLIst))
        {
           sePudo=1;
        }
    }

    return sePudo;
}
int controller_loadFromBinary(char* path, LinkedList* laLinkedLIst)
{
    int sePudo=0;
    FILE* pArchivo;
    pArchivo=fopen(path,"rb");
    if(pArchivo!=NULL)
    {
        if(parser_FromBinary(pArchivo, laLinkedLIst))
        {
        	sePudo=1;
        }
    }

    return sePudo;
}

int controller_saveElementoAsText(char* path, eParticipantes* corredor)
{
    FILE* pAux;
    int devolver=0;
    pAux=fopen(path,"w");
    char nombre[64];
    int id;

    int tiempo;
    //int puntajeSR;
    //int promPuntaje;
    char tipo[20];

    if(pAux!=NULL)
    {
    	eParticipantes_getId(corredor,&id);
    	eParticipantes_getNombre(corredor,nombre);
    	eParticipantes_getTipo(corredor,tipo);
    	eParticipantes_getTiempo(corredor,&tiempo);
    	//eParticipantes_getPromedioPuntaje(corredor,&promPuntaje);
        if(!feof(pAux))
        {
            if(corredor!=NULL)
            {
                fprintf(pAux,"%d,%s,%s,%d\n",id,nombre,tipo,tiempo);
                devolver=1;
            }
        }
    }
    fclose(pAux);
    return devolver;
}
int controller_removeeParticipantes(LinkedList* laLinkedLIst)
{
    eParticipantes* aux=NULL;

    int index;
    int id;
    int sePudo=0;

    printf("Quien va a borrar?");
    scanf("%d",&index);
    index--;//hacerlo con getters
    id=index;
    aux=(eParticipantes*)ll_get(laLinkedLIst,index);
    if(eParticipantes_getId(aux,&index))
    {
        ll_remove(laLinkedLIst,id);
        ll_len(laLinkedLIst);
        sePudo=1;
    }
    return sePudo;
}
int controller_ListeParticipantes(LinkedList* laLinkedLIst)
{
    int len=0;
    int sePudo=0;
    eParticipantes* corredor=NULL;
    char nombre[64];
    char tipo[64];
    int id;
    int tiempo;
    float promedio;
    len=ll_len(laLinkedLIst);
    //char lista[4][25]={"BOMBEROS","DEFENSA CIVIL","POLICIA","EMERGENCIA MEDICA"};
    for(int i=0;i<len;i++)
    {
        corredor = (eParticipantes*) ll_get(laLinkedLIst,i);

    	eParticipantes_getId(corredor,&id);
    	eParticipantes_getNombre(corredor,nombre);
    	eParticipantes_getTipo(corredor,tipo);
    	eParticipantes_getTiempo(corredor,&tiempo);
    	eParticipantes_getPromedio(corredor,&promedio);
        printf("(%6d) %20s %30s,%20d,%20.4f\n",id,nombre,tipo,tiempo,promedio);
    }
    printf("\n");
    sePudo=1;

    return sePudo;
}

void SaveParticipantes(void* voidIngresado)
{
    eParticipantes* auxcorredor;
    auxcorredor=voidIngresado;
    int auxInt;
    char id[64],aux[32];

    eParticipantes_getId(auxcorredor,&auxInt);
    strcpy(id,"/home/ian/eclipse-workspace/FINALCFEBRERO/eParticipanteses/");
    sprintf(aux,"%d",auxInt);
    strcat(id,aux);
    strcat(id,".csv");
    controller_saveElementoAsText(id,auxcorredor);

}
void SaveeParticipantesLL(LinkedList* this)
{
	for(int i=0;i<ll_len(this);i++)
	{
	    SaveParticipantes(ll_get(this,i));
	}
}

int controller_saveAsText(char* path, LinkedList* laLinkedLIst)
{
    eParticipantes* corredor=NULL;
    FILE* pAux;
    int len;
    int i=0;
    int aux;
    int devolver=0;
    pAux=fopen(path,"w");

    char tipo[35];
    char nombre[64];
    int id;
    int tiempo;

    if(pAux!=NULL)
    {
        len=ll_len(laLinkedLIst);
        aux=len-1;
        while(!feof(pAux))
        {
            corredor=eParticipantes_new();
            if(aux==i)
            {
            	eParticipantes_getId(corredor,&id);
            	eParticipantes_getNombre(corredor,nombre);
            	eParticipantes_getTipo(corredor,tipo);
            	eParticipantes_getTiempo(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d",id,nombre,tipo,tiempo);
                //fprintf(pAux,"%d,%s,%d",id,nombre,puntaje);
                devolver=1;
                break;
            }
            else
            {
                corredor=(eParticipantes*) ll_get(laLinkedLIst,i);
                corredor=(eParticipantes*) ll_get(laLinkedLIst,i);
            	eParticipantes_getId(corredor,&id);
            	eParticipantes_getNombre(corredor,nombre);
            	eParticipantes_getTipo(corredor,tipo);
            	eParticipantes_getTiempo(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d\n",id,nombre,tipo,tiempo);
                i++;
            }
        }
    }
    fclose(pAux);
    return devolver;
}
void FiltradorBicicletas(LinkedList* this)
{
	LinkedList* auxLL;
	char aux[32];
	printf("tipo?(MX1, MX2, MX3, SUPER_ATV)");
	fflush(stdin);
	scanf("%s",aux);
	auxLL=ll_filter(this,(void*)BicicletaFiltro,aux);
	controller_saveAsText("filtrado.csv",auxLL);
}
int BicicletaFiltro(eParticipantes* elemento,char* string)
{
	int devuelto=0;
	char aux[64];
	eParticipantes_getTipo(elemento,aux);
	if(strcmp(aux,string)==0)
	{
		devuelto=1;
	}
	return devuelto;
}
void LL_Mapear(LinkedList* this)
{
	ll_map(this,Mapear);
}
int Mapear(void* elemento)
{
	int retornado=0;
	int aux=0;
	//entre 50 y 120
	//int aux = rand() % 120 + 50;
	eParticipantes_getTiempo(((eParticipantes*)elemento),&aux);
	if(aux<15)
	{
		eParticipantes_setPromedio((eParticipantes*)elemento,(float)6);
	}
	else if(aux>=15&&aux<=20)
	{
		eParticipantes_setPromedio((eParticipantes*)elemento,(float)8);
	}
	else
	{
		eParticipantes_setPromedio((eParticipantes*)elemento,(float)10);
	}
	retornado = 1;
	return retornado;
}
int Punto6Sort(LinkedList* this)
{
	int devuelto=0;
	ll_sort(this,(void*)SortString,1);
	ll_sort(this,(void*)SortInt,1);
	controller_ListeParticipantes(this);
	return devuelto;
}
int SortString(eParticipantes* n1, eParticipantes* n2)
{
	int devuelto=0;
	if(n1!=NULL&&n2!=NULL)
	{
		char aux1[32];
		char aux2[32];
		eParticipantes_getTipo(n1,aux1);
		eParticipantes_getTipo(n2,aux2);
		devuelto=strcmp(aux1,aux2);
	}
	return devuelto;
}
int SortInt(eParticipantes* n1, eParticipantes* n2)
{
	int devuelto=0;
	float aux1,aux2;
	char auxStr1[32];
	char auxStr2[32];
	if(n1!=NULL && n2!=NULL)
	{
		eParticipantes_getTipo(n1,auxStr1);
		eParticipantes_getTipo(n2,auxStr2);
		eParticipantes_getPromedio(n1,&aux1);
		eParticipantes_getPromedio(n2,&aux2);
		if(strcmp(auxStr1,auxStr2)==0)
		{
			if(aux1>aux2)
			{
				devuelto = 1;
			}else if(aux1<aux2)
			{
				devuelto = -1;
			}
		}
	}
	return devuelto;
}
/*int controller_saveAsBinary(char* path, LinkedList* laLinkedLIst)
{
    eParticipantes* corredor=NULL;
    FILE* pAux;
    int len;
    int i=0;
    int aux;
    int devolver=0;
    pAux=fopen(path,"wb");

    char tipo[9];
    char nombre[64];
    int id;
    int tiempo;
    int ;

    if(pAux!=NULL)
    {
        len=ll_len(laLinkedLIst);
        aux=len-1;
        while(!feof(pAux))
        {
            corredor=eParticipantes_new();
            if(aux==i)
            {
                corredor=(eParticipantes*) ll_get(laLinkedLIst,i);
            	eParticipantes_getId(corredor,&id);
            	eParticipantes_getNombre(corredor,nombre);
            	eParticipantes_getDomicilio(corredor,tipo);

            	eParticipantes_getTiempo(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d,%d",id,nombre,tipo,,tiempo);
                //fprintf(pAux,"%d,%s,%d",id,nombre,puntaje);
                devolver=1;
                break;
            }
            else
            {
                corredor=(eParticipantes*) ll_get(laLinkedLIst,i);
                corredor=(eParticipantes*) ll_get(laLinkedLIst,i);
            	eParticipantes_getId(corredor,&id);
            	eParticipantes_getNombre(corredor,nombre);
            	eParticipantes_getDomicilio(corredor,tipo);

            	eParticipantes_getTiempo(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d,%d\n",id,nombre,tipo,,tiempo);
                i++;
            }
        }
    }
    fclose(pAux);
    return devolver;
}
*/
//Punto 7
/*void LlMenorQue10(eParticipantes* this)
{
	int aux=99;
	if(this!=NULL)
	{
		eParticipantes_getPromedio(this,&aux);
		if(aux<10)
		{
			SaveeParticipantes(this);
		}
	}
}*/
//PUNTO 8
/*
int BuscarMayorNumero(LinkedList* LaLista)
{
    eParticipantes* corredorAux=eParticipantes_new();
    int puntajePr=-1;
    int criterio=0;
    int retorno=0;
    int len=ll_len(LaLista);
    if(LaLista!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            corredorAux=(eParticipantes*)ll_get(LaLista,i);
            eParticipantes_getPromedio(corredorAux,&puntajePr);
            if((corredorAux)!=NULL)
            {
                if(puntajePr>=criterio)
                {
                    criterio=puntajePr;
                    retorno = i;
                }
            }
        }
    }
    return retorno;
}*/
/*
int TresMayores(LinkedList* LaLista)
{
    int retorno=0;
    LinkedList* listAux=(LinkedList*) ll_newLinkedList();
    listAux=LaLista;
    listAux=ll_filter(listAux,BuscarMayorNumero);
    controller_ListeParticipantes(listAux);
    SaveeParticipantesLL(listAux);
    retorno = 1;
    free(listAux);
    return retorno;

}
*/
//PUNTO 10, TERMINAR
/*int FinalistasTerceraRonda(LinkedList* LaLista)
{
    int retorno=0;
    LinkedList* listAux=(LinkedList*) ll_newLinkedList();
    listAux=LaLista;
    listAux=ll_filter(listAux,BuscarMayorNumero);
    controller_ListeParticipantes(listAux);
    SaveeParticipantesLL(listAux);
    retorno = 1;
    free(listAux);
    return retorno;

}*/
/*
int controller_addeParticipantes(LinkedList* laLinkedLIst)//hacer funcion
{
    int len,i;
    char nombre[128];
    char anioStr[128];
    char dniStr[128];
    char fechapresentacionStr[128];
    char temaPresentacion[128];
    char horasTrabajadas[64];
    char puntajeStr[64];
    char id[64];
    int sePudo=0;
    eParticipantes* corredor[TAM];
    eParticipantes* aux;

    len=ll_len(laLinkedLIst);
    i=len+1;
    sprintf(id, "%d", i);

    printf("Ingrese fechaNacimiento ");
    scanf("%[^\n]",anioStr);
    fflush(stdin);

    printf("Ingrese nombre ");
    fflush(stdin);
    scanf("%[^\n]",nombre);
    ValidarString(nombre);

    printf("Ingrese dniStr");
    scanf("%s",dniStr);
    ValidarInt(dniStr);

    printf("Ingrese fechapresentacionStr");
    scanf("%s",fechapresentacionStr);
    ValidarInt(fechapresentacionStr);

    printf("Ingrese temapresentacion");
    scanf("%s",temaPresentacion);
    ValidarString(temaPresentacion);

    printf("Ingrese puntajeStr");
    scanf("%s",puntajeStr);
    ValidarInt(puntajeStr);

    aux=eParticipantes_newParametros(id,anioStr,nombre,dniStr,fechapresentacionStr,temaPresentacion,puntajeStr);//(idStr, anioStr,char* nombreStr,char* dniStr,char* fechapresentacionStr,char*temapresentacion,char*puntajeStr)
    corredor[i]=aux;
    ll_add(laLinkedLIst,corredor[i]);
    sePudo=1;
    return sePudo;
}*/
/*
int controller_editeParticipantes(LinkedList* laLinkedLIst)
{
    eParticipantes* aux=NULL;

    int sePudo=1;
    char auxString[64];
    int index;
    int opcion;
    int auxInt;

    printf("Que indice va a modificar? ");
    scanf("%d",&index);//verificar que existe primero
    index--;
    aux=(eParticipantes*)ll_get(laLinkedLIst,index);
    if(eParticipantes_getId(aux,&index))
    {
        printf("Que quiere modificar?\n1.Nombre\n2.Sueldo\n3.Horas Trabajadas\n4.fechaPresentacion\n5.temapresentacion\n");
        scanf("%d",&opcion);

       	    int id;
			int anioNacimiento;
			char nombre[50];
			char dni[9];
			char fechaPresentacion[30];
			char temapresentacion[50];
			int puntajeRonda;
			int puntajeSegundaRonda;
			int Puntaje;
			int puntajeTerceraRonda;

        switch(opcion)
        {
            case 1:
                printf("Ingrese nombre ");
                fflush(stdin);
                scanf("%[^\n]",auxString);
                ValidarString(auxString);
                eParticipantes_setNombre(aux,auxString);
                break;
            case 2:
                printf("Ingrese anio nacimiento ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarInt(auxString);
                auxInt=atoi(auxString);
                eParticipantes_setAnio(aux,auxInt);
                break;
            case 3:
                printf("Ingrese dni ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarInt(auxString);
                auxInt=atoi(auxString);
                eParticipantes_setDni(aux,auxInt);
                break;
            case 4:
                printf("Ingrese fechaPresentacion ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarString(auxString);
                eParticipantes_setFechaPresentacion(aux,auxString);
                break;
            case 5:
                printf("Ingrese TemaPresentacion ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarString(auxString);
                eParticipantes_setTemaPresentacion(aux,auxString);
                break;
        }

    }
    else
    {
        sePudo=0;
    }

    return sePudo;
}*/
/*int controller_sorteParticipantes(LinkedList* laLinkedLIst)
{
    int sePudo=0;//hacerle if a sort
    int opcion;
    printf("De que forma los quiere ordenar?\n1.Nombre(menor a mayor)\n2.id(menor a mayor)\n3.Salario(menor a mayor)\n4.Horas trabajadas(menor a mayor)\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
            if(!(ll_sort(laLinkedLIst,(void*)eParticipantes_CompareByName,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por Nombre\n");
                controller_ListeParticipantes(laLinkedLIst);
                sePudo=1;
            }
            break;
        case 2:

            if(!(ll_sort(laLinkedLIst,(void*)eParticipantes_CompareById,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por id\n");
                controller_ListeParticipantes(laLinkedLIst);
                sePudo=1;
            }
            break;
        case 3:
            if(!(ll_sort(laLinkedLIst,(void*)eParticipantes_CompareBySalary,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por sueldo\n");
                controller_ListeParticipantes(laLinkedLIst);
                sePudo=1;
            }
            break;
        case 4:
            if(!(ll_sort(laLinkedLIst,(void*)eParticipantes_CompareByWorkingHours,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por horas trabajadas\n");
                controller_ListeParticipantes(laLinkedLIst);
                sePudo=1;
            }
            break;
    }
    return sePudo;
}*/


