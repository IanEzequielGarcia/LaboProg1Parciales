/******************************************************************************
Crear una función que reciba como parámetro un número entero.
La misma deberá retornar si dicho número es par o no. Probar la función desde el main *

Crear una función que reciba una cadena de caracteres, y realice las siguientes operaciones:
Contar la cantidad de vocales (cuantas a, e, i, o, u) hay en la cadena y retornar el valor máximo de esas cantidades.
Crear la función y probarla desde el main.

 Crear un párrafo en donde se pueda ver la relación entre los siguientes términos:
 Vector, dirección de memoria, referencia y función.
 El párrafo deberá demostrar coherencia entre los términos solicitados.
*******************************************************************************/
#include <stdio.h>
#include <string.h>
int NumeroPar();
int CadenaCaracteres();
int main()
{
    int nuemeroParMain;
    int maximoCadenas;
    
    nuemeroParMain=NumeroPar();
    if(nuemeroParMain)
    {
        printf("par\n");
    }
    else
    {
        printf("impar\n");
    }
    maximoCadenas=CadenaCaracteres();
    printf("%d", maximoCadenas);
    return 0;
}
int NumeroPar()
{
    int numero;
    int numeroPar;
    printf("n° entero\n");
    scanf("%d",&numero);
    if(numero%2==0)
    {
        numeroPar=1;
    }
    return numeroPar;
}
int CadenaCaracteres()
{
    char cadena[20];
    int i;
    char letraAux[1];
    char a[1]={"a"};
    char e[1]={"e"};
    char I[1]={"i"};
    char o[1]={"o"};
    char u[1]={"u"};
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;
    int largo=0;
    int retornar;
    printf("Ingrese cadena\n");
    __fpurge(stdin);
    scanf("%[^\n]",&cadena[0]);
    largo=(strlen(cadena));//pos parcial
    for(i=0;i<largo;i++)//puse 10 en el parcial
    {
        if(cadena[i]=='a'||cadena[i]=='A')
        {
            contadorA++;
        }
        if(cadena[i]=='e'||cadena[i]=='E')
        {
            contadorE++;
        }
        if(cadena[i]=='i'||cadena[i]=='I')
        {
            contadorI++;
        }
        if(cadena[i]=='o'||cadena[i]=='O')
        {
            contadorO++;
        }
        if(cadena[i]=='u'||cadena[i]=='U')
        {
            contadorU++;
        }
    }
    if(contadorA>contadorE>contadorI>contadorO>contadorU)
    {
        retornar=contadorA;
    }
    else
    {
        if(contadorE>contadorI>contadorO>contadorU)
        {
            retornar=contadorE;
        }
        else
        {
            if(contadorI>contadorO>contadorU)
            {
                retornar=contadorI;
            }
            else
            {
                if(contadorO>contadorU)
                {
                    retornar=contadorO;
                }
                else
                {
                    retornar=contadorU;
                }
            }
        }
    }
    return retornar;
}
/*int Vector(int vectores[])
{
    
}*/



