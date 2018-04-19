#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "funciones.h"

void indexvacio(Struct1 vec[], int ext)
{
    int i;
    for (i=0; i<ext; i++)
    {
        vec[i].estado = -1;
    }
    /*for (i=0;i<ext;i++)
    {
        printf("%d \n",vec[i].estado);
    }*/
}

int menu(char cadenas[])
{
    int choice, validchoice;
    char opcion[5];
    printf("%s", cadenas);
    printf("\n Elija una opcion: ");
    scanf("%s", opcion);
    //VALIDA
    validchoice= validarnumeros(opcion);
    while(validchoice!=0)
    {
        printf("\n ERROR. Solo se permiten ingresar n%cmeros... Reintente por favor: \n",163);
        scanf("%s", opcion);
        validchoice= validarnumeros(opcion);
    }
    choice= atoi(opcion);
    //printf("%s \n    %d\n", opcion, choice);
    return choice;
}

int obtenerEspacioLibre(Struct1 vec[], int ext)
{
    int i;
    for (i=0; i<ext; i++)
    {
        if(vec[i].estado == -1)
        {
            break;
        }
    }
    //printf("ok %d \t", i);
    return i;
}

void alta(Struct1 vec[], int place)
{
    int i, letras, validn, validap, validid, validage;
    char dni[DNI];
    char edad[EDAD];
    char nombre[41];
    char apellido [41];
    char apellidoynombre[83];
    char auxiliar[300];
    char auxiliar2[300];


    printf("Ingrese un nombre: ");
    fflush(stdin);
    scanf("%[^\n]", auxiliar);
    //VALIDA
    letras = strlen(auxiliar);
    validn = validartexto(auxiliar);
    while (validn!=0 || letras >40)
    {
        printf("ERROR. nombre inv%clido... reintente por favor:\n",160);
        printf("\nIngrese un nombre: ");
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
        letras = strlen(auxiliar);
        validn = validartexto(auxiliar);
    }
    strcpy(nombre, auxiliar);

    printf("Ingrese un apellido: ");
    fflush(stdin);
    scanf("%[^\n]", auxiliar2);
    //VALIDA
    letras = strlen(auxiliar2);
    validap = validartexto(auxiliar2);
    while (validap!=0 || letras >40)
    {
        printf("ERROR. apellido inv%clido... reintente por favor:\n",160);
        printf("\nIngrese un apellido: ");
        fflush(stdin);
        scanf("%[^\n]", auxiliar2);
        letras = strlen(auxiliar2);
        validap = validartexto(auxiliar2);
    }
    strcpy(apellido, auxiliar2);

    strlwr(nombre);
    strlwr(apellido);

    nombre[0]= toupper(nombre[0]);
    apellido[0]= toupper(apellido[0]);

    for (i=0; i<30; i++)
    {
        if(nombre[i]==' ' && nombre [i+1]!= ' ')
        {
            nombre[i+1] = toupper(nombre[i+1]);
        }
    }
    for (i=0; i<30; i++)
    {
        if(apellido[i]==' ' && apellido [i+1]!= ' ')
        {
            apellido[i+1] = toupper(apellido[i+1]);
        }
        strcpy(apellidoynombre, apellido);
        strcat(apellidoynombre, " ");
        strcat(apellidoynombre, nombre);
    }
    strcpy(vec[place].nombre, apellidoynombre);

    //printf("\n\n\n%s", vec[place].nombre);

    printf("Ingrese edad: ");
    scanf("%s",edad);
    //VALIDA
    validage = validarnumeros(edad);
    vec[place].edad= atoi(edad);
    //printf("%d\n", vec[place].edad);
    while (validage!=0 || (vec[place].edad<1 || vec[place].edad>102))
    {
        printf("ERROR. valor de edad inv%clido... reintente por favor\n",160);
        printf("\nIngrese edad: ");
        scanf("%s",edad);
        validage = validarnumeros(edad);
        vec[place].edad= atoi(edad);
    }

    //printf("%d\n%s\n", vec[place].edad, edad);

    printf("Ingrese D.N.I.: ");
    scanf("%s",dni);
    //VALIDA
    validid = validarnumeros(dni);
    vec[place].dni= atoi(dni);
    while (validid!=0)
    {
        printf("ERROR. el D.N.I. no puede contener letras, ni s%cmbolos... reintente por favor\n",161);
        printf("\nIngrese D.N.I: ");
        scanf("%s",dni);
        validid = validarnumeros(dni);
        vec[place].dni= atoi(dni);
    }
    //printf("%d\n%s\n", vec[place].dni, dni);
    vec[place].estado = 0;
}

int buscarPorDni(Struct1 vec[],int ext)
{
    char dni[DNI];
    long int auxdni;
    char conf;
    int i, validid;
    for (i=0; i<ext; i++)
    {
        if (vec[i].estado==0)
        {
            printf("\n=======================================================================\n");
            printf("D.N.I.: %d\tNOMBRE: %s\tEDAD: %d", vec[i].dni, vec[i].nombre, vec[i].edad);
            printf("\n=======================================================================\n");
        }
    }
    printf("Ingrese el D.N.I. que desea eliminar: ");
    scanf("%s",dni);
    validid = validarnumeros(dni);
    auxdni= atoi(dni);
    while (validid!=0)
    {
        printf("ERROR. el D.N.I. no puede contener letras, ni s%cmbolos... reintente por favor\n",161);
        printf("\nIngrese el D.N.I. que desea eliminar: ");
        scanf("%s",dni);
        validid = validarnumeros(dni);
        auxdni= atoi(dni);
    }
    printf("\nel D.N.I. ingresado es: %d\n\n", auxdni);
    printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n\tpresione cualquier tecla para continuar o ESC para cancelar?\n\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n");
    fflush(stdin);
    conf= getch();
    if (conf!= ESC )
    {
        //(printf("if     "));
        return auxdni;
    }
    else
    {
        //printf("else   ");
        printf("\nACCION CANCELADA, NO SE ELIMINARON DATOS\n");
        return -1;
    }
}

void baja(Struct1 vec[], int ext, long int codigo)
{
    int i;
    for (i=0; i<ext; i++)
    {
        if(codigo==vec[i].dni)
        {
            vec[i].estado = -1;
            printf("\nDatos de %s con D.N.I %d ELIMINADOS\n",vec[i].nombre, codigo);
            break;
        }
    }
    if(i==CANT)
    {
        printf("El D.N.I. ingresado no corresponde con la base de datos... Reintente por favor:\n\n");
    }

}

void mostrar(Struct1 vec[], int ext)
{
    int i;
    for (i=0; i<ext; i++)
    {
        if (vec[i].estado==0)
        {
            printf("\n=====================================\n");
            printf("\nNOMBRE: %s\nDNI: %d\nEDAD: %d\n", vec[i].nombre, vec[i].dni, vec[i].edad);
            printf("\n=====================================\n");
        }
    }
}

void graficoEdad(Struct1 vec[], int ext)
{
    int i, rango1=0, rango2=0, rango3=0, flag2=0, maximo;

    for(i=0; i<ext; i++)
    {
        if(vec[i].edad<18 && vec[i].estado==0)
        {
            rango1++;
        }
        if((vec[i].edad>17 && vec[i].edad<36) && vec[i].estado==0)
        {
            rango2++;
        }
        if(vec[i].edad>35 && vec[i].estado==0)
        {
            rango3++;
        }
    }

    if(rango3 >= rango2 && rango3 >= rango1)
    {
        maximo = rango3;
    }
    else
    {
        if(rango2 >= rango1 && rango2 >= rango3)
        {
            maximo = rango2;
        }
        else
        {
            maximo = rango1;
        }
    }

    for(i=maximo; i>0; i--)
    {
        printf("\t  %02d  |",i);

        if(i<= rango1)
        {
            printf("\t    *");
        }
        else
        {
            printf("\t    ");
        }

        if(i<= rango2)
        {
            printf("\t\t     *");
            flag2=1;
        }

        if(i<= rango3)
        {
            if(flag2==0)
            {
                printf("\t\t\t\t    *");
            }

            if(flag2==1)
            {
                printf("\t\t    *");
            }
        }
        printf("\n");
    }
    printf("____________________________________________________________");
    printf("\nRango (a%cos)  | menor a 18\tde 18 a 35\tmayor a 35",164);
    if(rango1==0 && rango2==0 && rango3==0)
    {
        printf("\nporcentajes:  |    %c0\t\t    %c0\t\t   %c0\n\n", '%', '%', '%');
    }
    else
    {
        printf("\nporcentajes:  |    %c%d\t\t    %c%d\t\t   %c%d\n\n", '%',((rango1*100)/(rango1+rango2+rango3)),'%',((rango2*100)/(rango1+rango2+rango3)),'%',((rango3*100)/(rango1+rango2+rango3)));
    }
}

void ordenarAscendAlfa(Struct1 vec[], int ext)
{
    int i, j;
    Struct1 aux;
    for(i=0; i<ext-1; i++)
    {
        for(j=i+1; j<ext; j++)
        {
            if(strcmp(vec[i].nombre, vec[j].nombre)>0)
            {
                aux= vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
}

//VALIDACIONES

int validartexto(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);
    //printf("\n %d \n", max);
    for(i=0; i<max; i++ )
    {
        if((cadena[i] == ' ') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
            //     printf("\n %d \n", i);
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
        //  printf("\n %d \n", i);

    }
    //printf("\n %d \t %d \n", i, ans);
    return ans;
}

int validarnumeros(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);
    //printf("\n %d \n", max);
    for(i=0; i<max; i++ )
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            //     printf("\n %d \n", i);
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
        //  printf("\n %d \n", i);
    }
    //printf("\n %d \t %d \n", i, ans);
    return ans;
}
