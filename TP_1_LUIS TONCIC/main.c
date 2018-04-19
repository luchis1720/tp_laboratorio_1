#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    float a, b;
    float resultado;

    do
    {
        system("cls");

        printf("\n=============**CALCULADORA**=============\n");
        printf("  1- Ingresar 1er operando (A=%f)\n", a);
        printf("  2- Ingresar 2do operando (B=%f)\n", b);
        printf("  3- Calcular la suma (A+B)\n");
        printf("  4- Calcular la resta (A-B)\n");
        printf("  5- Calcular la division (A/B)\n");
        printf("  6- Calcular la multiplicacion (A*B)\n");
        printf("  7- Calcular el factorial (A!)\n");
        printf("  8- Calcular todas las operaciones\n");
        printf("  9- Salir\n");
        printf("=========================================\n");

        fflush(stdin);
        scanf("%d",&opcion);

        while(!(opcion >0 && opcion < 10))
        {
            printf("ERROR. ingrese una opcion valida (1 - 9):");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
        case 1:
            printf("ingrese un numero: ");
            scanf("%f", &a);
            break;
        case 2:
            printf("ingrese un numero: ");
            scanf("%f", &b);
            break;
        case 3:
            resultado= suma (a, b);
            printf("____________________\n");
            printf("\nel primer operando es: %f \nel segundo operando es: %f \ny la suma es: %.3f\n",a,b, resultado);
            printf("____________________\n\n");
            break;
        case 4:
            resultado= resta (a, b);
            printf("____________________\n");
            printf("\nel primer operando es: %f \nel segundo operando es: %f \ny su resta es: %.3f\n",a,b, resultado);
            printf("____________________\n\n");
            break;
        case 5:
            resultado= division (a, b);
            if(resultado != 0)
            {
                printf("____________________\n");
                printf("\nel primer operando es: %f \nel segundo operando es: %f \ny su division es: %.3f\n",a,b, resultado);
                printf("____________________\n\n");
            }
            else
            {
                printf("____________________\n");
                printf("\nERROR (no se puede dividir por cero, reintente por favor)");
                printf("\n____________________\n\n");
            }
            break;
        case 6:
            resultado= multiplicacion (a, b);
            printf("____________________\n");
            printf("\nel primer operando es: %f \nel segundo operando es: %f \ny su multiplicacion es: %.3f\n",a,b, resultado);
            printf("____________________\n\n");
            break;
        case 7:
            resultado = factorial (a);
            if (resultado != 0.0)
            {
                resultado= factorial (a);
                printf("____________________\n");
                printf("\nel primer operando es: %f \ny su factorizacion es: %f\n",a, resultado);
                printf("____________________\n\n");
            }
            else
            {
                printf("____________________\n");
                printf("\nENTRADA NO VALIDA (no existe factorial de numero negativo, reintente)");
                printf("\n____________________\n\n");
            }
            break;
        case 8:
            printf("____________________\n");
            resultado= suma (a,b);
            printf("\nel primer operando es: %f \nel segundo operando es: %f \ny la suma es: %f",a,b, resultado);
            printf("\n____________________\n");
            resultado= resta (a, b);
            printf("\nel primer operando es: %f \nel segundo operando es: %f \ny su resta es: %f",a,b, resultado);
            printf("\n____________________\n");
            resultado= division (a, b);
            if(resultado != 0.0)
            {
                printf("\nel primer operando es: %f \nel segundo operando es: %f \ny su division es: %f",a,b, resultado);
            }
            else
            {
                printf("\nERROR (no se puede dividir por cero, reintente por favor)");
            }
            printf("\n____________________\n");
            resultado= multiplicacion (a, b);
            printf("\nel primer operando es: %f \nel segundo operando es: %f \ny su multiplicacion es: %f\n",a,b, resultado);
            printf("\n____________________\n");
            resultado = factorial (a);
            if (resultado != 0)
            {
                resultado= factorial (a);
                printf("\nel primer operando es: %f \ny su factorizacion es: %f",a, resultado);
            }
            else
            {
                printf("\nENTRADA NO VALIDA (no existe factorial de numero negativo, reintente)");
            }
            printf("\n____________________\n\n");
            break;
        }
        system("pause");
    }
    while(opcion != 9 );

    printf("\n=============\n");
    printf("  gracias!! ");
    printf("\n=============\n");
    return 0;
}
