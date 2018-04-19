#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion;
    int auxint= CANT;
    int indice,dnibaja;
    Struct1 pers [CANT];

    indexvacio(pers, auxint);

    do
    {
        system("cls");
        opcion=menu("\n*************************************************************\n*\t\t\t\t\t\t\t    *\n*  \t  ========   Trabajo Practico N*2   ========        *\n*\t\t\t\t\t\t\t    *\n*************************************************************\n\n\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por nombre\n4- Imprimir grafico de edades\n\n5- Salir\n");

        switch(opcion)
        {
        case 1:
            indice = obtenerEspacioLibre(pers, auxint);
            if(indice ==CANT)
            {
                printf("\nNO HAY LUGAR DISPONIBLE\n");
            }
            else
            {
                alta (pers, indice);
            }
            break;
        case 2:
            dnibaja= buscarPorDni(pers, auxint);
            if(dnibaja!=-1)
            {
                baja (pers, auxint, dnibaja);
            }
            break;
        case 3:
            ordenarAscendAlfa(pers, auxint);
            mostrar(pers, auxint);
            break;
        case 4:
            graficoEdad(pers, auxint);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("ERROR. Opci%cn invalida\n",162);
        }
        system("pause");
    }
    while(seguir=='s');

    printf("\n*************************************************************\n*\t\t\t\t\t\t\t    *\n*\t=============\t  GRACIAS!!\t=============       *\n*\t\t\t\t\t\t\t    *\n*************************************************************\n");

    return 0;
}
