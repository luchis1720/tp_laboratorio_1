#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    FILE  *bin;
    EMovie pelicula;
    char seguir='s';
    int opcion=0, flag;

    do
    {
        if ((bin = fopen(PATH,"rb+"))==NULL)
        {
            if ((bin = fopen(PATH,"wb+"))==NULL)
            {
                printf("No se pudo abrir el archivo en ruta ->.\\file\\bin.dat");
                exit(1);
            }
        }
        system("cls");
        opcion= menu ("1.-Agregar pelicula\n2.-Borrar pelicula\n3.-Modificar pelicula\n4.-Generar pagina web\n5.-Salir\n");

        switch(opcion)
        {
        case 1:
            altapelicula(pelicula, bin);
            break;
        case 2:
            flag=checkFile(pelicula, bin);
            if(flag!=0)
            {
                borrarpelicula(pelicula, bin);
            }
            else
            {
                printf("DEBE HABER INGRESADO UN ALTA PARA PODER DAR UNA BAJA\n");
            }
            break;
        case 3:
            flag=checkFile(pelicula, bin);
            if(flag!=0)
            {
                modificar(pelicula, bin);
            }
            else
            {
                printf("DEBE HABER INGRESADO UN ALTA PARA PODER HACER MODIFICACIONES\n");
            }
            break;
        case 4:
            flag=checkFile(pelicula, bin);
            if (flag!=0)
            {
                 generarPagina(pelicula, bin, "MovieTP3.html");
            }
            else
            {
                 printf("DEBE HABER INGRESADO UN ALTA PARA PODER GENERAR EL ARCHIVO HTML\n");
            }
            break;
        case 5:
            seguir = 'n';
            fclose(bin);
            break;
        case 1720:       //opcion oculta para control del programa...
            checkbin(bin, pelicula);
            break;
        default:
            printf("ERROR. Opci%cn inv%clida! ",162,160);
            break;
        }
        system("pause");
    }
    while(seguir=='s');

    printf("\n*************************************************************\n*\t\t\t\t\t\t\t    *\n*\t=============\t  GRACIAS!!\t=============       *\n*\t\t\t\t\t\t\t    *\n*************************************************************\n");


    return 0;
}
