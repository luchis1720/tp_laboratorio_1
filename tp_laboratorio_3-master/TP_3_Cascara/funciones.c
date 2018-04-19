#include "funciones.h"


int menu(char cadenas[])
{
    int choice;
    printf("%s", cadenas);
    choice= getentero("\nElija una opcion: ");
    return choice;
}

void altapelicula(EMovie pelicula, FILE *bin)
{
    int auxid, place, conf;
    char auxtitulo[31];
    char auxgenero[129];
    float auxpuntaje;
    int auxduracion, aux, ask;
    char auxdescripcion[356];
    char auxlinkImagen[251];

    place=getUniqueID(pelicula, bin);
    auxid=(place+1);

    titulo("Ingrese el titulo de la pelicula: ",auxtitulo);
    strupr(auxtitulo);

    genero("Seleccione el Genero de la pelicula: ",auxgenero);
    strcpy(pelicula.genero, auxgenero);
    conf=crOrEsc("\nDesea seleccionar un genero adicional? \n");
    while(conf!=0)
    {
        genero("Seleccione el Genero de la pelicula: ",auxgenero);
        strcat(pelicula.genero, ", ");
        strcat(pelicula.genero, auxgenero);
        conf=crOrEsc("\nDesea seleccionar un genero adicional? \n");
    }

    auxpuntaje= getflotante("ingrese el puntaje de la pelicula: ");
    while(!(auxpuntaje>0 && auxpuntaje<=10))
    {
        auxpuntaje= getflotante("ERROR. ingrese el puntaje de la pelicula(1/10): ");
    }

    auxduracion=getentero("Ingrese la duracion de la pelicula (minutos): ");

    descripcion("Ingrese la breve reseña de la pelicula: ", auxdescripcion);

    link("copie el link de la imagen a continuacion: ", auxlinkImagen);

    pelicula.id=auxid;
    strcpy(pelicula.titulo, auxtitulo);
    pelicula.puntaje = auxpuntaje;
    pelicula.duracion = auxduracion;
    strcpy(pelicula.descripcion, auxdescripcion);
    strcpy(pelicula.linkImagen, auxlinkImagen);

    mostrarestructura(pelicula);
    ask= crOrEsc("Datos cargados, listo para pasarlo al archivo binario?\n");
    if (ask)
    {
        aux= agregarPelicula(pelicula, bin);

        if (aux!=0)
        {
            printf("SE CARGO CON EXITO EL ARCHIVO BINARIO\n\n");
        }
        else
        {
            printf("NO SE CARGO CON EXITO EL ARCHIVO BINARIO\n\n");
        }
    }
    else
    {
        printf("\nACCION CANCELADA POR EL USUARIO. NO SE CARGARON DATOS.\n");
    }
}

void titulo(char cadena[],char *save)
{
    char auxiliar [1024];
    int letras;

    printf("%s",cadena);
    fflush(stdin);
    scanf("%[^\n]", auxiliar);

    letras = strlen(auxiliar);

    while (letras >30)
    {
        printf("ERROR. t%ctulo muy largo... reintente por favor:\n",161);
        printf("%s", cadena);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
        letras = strlen(auxiliar);
    }
    strcpy(save, auxiliar);
}

void genero (char cadena[],char *save)
{
    char aux [21]="Genero";
    char ingreso[21];
    char genre[][20]= {"Accion","Comedia","Ciencia_Ficcion","Drama","Suspenso","Terror","Thriller","Western"};
    int opcion;

    do
    {
        opcion=menu("Elija el genero: \n1.-ACCION\n2.-COMEDIA\n3.-CIENCIA FICCION\n4.-DRAMA\n5.-SUSPENSO\n6.-TERROR\n7.-THRILLER\n8.-WESTERN\n9.-OTRO\n");
        switch(opcion)
        {
        case 1:
            strcpy(aux,genre[0]);
            break;
        case 2:
            strcpy(aux,genre[1]);
            break;
        case 3:
            strcpy(aux,genre[2]);
            break;
        case 4:
            strcpy(aux,genre[3]);
            break;
        case 5:
            strcpy(aux,genre[4]);
            break;
        case 6:
            strcpy(aux,genre[5]);
            break;
        case 7:
            strcpy(aux,genre[6]);
            break;
        case 8:
            strcpy(aux,genre[7]);
            break;
        case 9:
            gettexto("\nIngrese el Genero: ", ingreso);
            strlwr(ingreso);
            ingreso[0]= toupper(ingreso[0]);
            strcpy(aux,ingreso);
            break;
        default:
            printf("Opci%cn Invalida. Reintente por favor: \n",162);
            getch();
            system("cls");
            opcion=0;
            break;
        }
    }
    while(opcion==0);
    strcpy(save, aux);
}

void descripcion(char cadena[],char *save)
{
    char auxiliar [1024];
    int letras;

    printf("%s",cadena);
    fflush(stdin);
    scanf("%[^\n]", auxiliar);

    letras = strlen(auxiliar);

    while (letras >355)
    {
        printf("ERROR. descripci%cn muy larga... reintente por favor:\n",162);
        printf("%s", cadena);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
        letras = strlen(auxiliar);
    }
    strcpy(save, auxiliar);
}

void link(char cadena[],char *save)
{
    char auxiliar [1024];
    int letras;

    printf("%s",cadena);
    fflush(stdin);
    scanf("%[^\n]", auxiliar);

    letras = strlen(auxiliar);

    while (letras >250)
    {
        printf("ERROR. descripci%cn muy larga... reintente por favor:\n",162);
        printf("%s", cadena);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
        letras = strlen(auxiliar);
    }
    strcpy(save, auxiliar);
}

int agregarPelicula(EMovie pelicula, FILE *bin)
{
    int ans=0;



    if (pelicula.id!=0)
    {
        fseek(bin, 0L,SEEK_END);
        fflush(stdin);
        ans =fwrite(&pelicula, sizeof(pelicula), 1, bin);
    }
    fclose(bin);
    return ans;
}

void mostrarestructura(EMovie pelicula)
{
    printf("\n");
    printf("ID: %d\n",pelicula.id);
    printf("Titulo: %s\n",pelicula.titulo);
    printf("Genero: %s\n",pelicula.genero);
    printf("Puntaje: %.1f\n",pelicula.puntaje);
    printf("Duracion: %d\n",pelicula.duracion);
    printf("Descripcion: %s\n",pelicula.descripcion);
    printf("LINK IMAGEN: %s\n",pelicula.linkImagen);
    printf("--------------------------------------------------\n");
}

void checkbin(FILE *bin, EMovie pelicula)
{
    int cant;
    EMovie aux;

    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(&aux, sizeof(aux), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        pelicula=aux;
        mostrarestructura(pelicula);
    }
    fclose(bin);
}

void borrarpelicula(EMovie pelicula, FILE *bin)
{
    int cant, opcion, ans, conf, find=0;
    char title[31];

    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(&pelicula, sizeof(pelicula), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(pelicula.id!=0)
        {
            mostrarestructura(pelicula);
        }
    }
    opcion=getentero("Elija el ID de la pelicula que desea ELIMINAR: ");

    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(&pelicula, sizeof(pelicula), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }

        if(opcion==pelicula.id)
        {
            find=1;
            system("cls");
            printf("LA PELICULA A ELIMINAR ES: \n");
            mostrarestructura(pelicula);
            strcpy(title,pelicula.titulo);
            conf= crOrEsc("\n");
            if (conf)
            {
                pelicula.id=0;
                //mostrarestructura(pelicula);
                fseek(bin, (-1)*sizeof(pelicula),SEEK_CUR);
                fflush(stdin);
                ans= fwrite(&pelicula, sizeof(pelicula), 1, bin);
                fclose(bin);
                if (ans!=0)
                {
                    printf("Datos de la Pelicula: %s .ELIMINADOS\n",title);
                    break;
                }
                else
                {
                    printf("LOS DATOS NO PUDIERON SER ELIMINADOS");
                }
            }
            else
            {
                printf("ACCION CANCELADA POR EL USUARIO\n\nNo se borraron datos\n\n");
            }
        }
    }
    if(find==0)
        printf("\nPelicula no encontrada\n\n");
}

void modificar(EMovie pelicula, FILE *bin)
{
    char auxtitulo[31];
    char auxgenero[129];
    float auxpuntaje;
    int auxduracion, cant, opcion, modif, ans, conf, flag=0, find=0;
    char auxdescripcion[356];
    char auxlinkImagen[251];
    char seguir='s';

    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(&pelicula, sizeof(pelicula), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(pelicula.id!=0)
        {
            mostrarestructura(pelicula);
        }
    }
    opcion=getentero("Elija el ID de la pelicula que desea MODIFICAR: ");

    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(&pelicula, sizeof(pelicula), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }

        if(opcion==pelicula.id)
        {
            do
            {
                find=1;
                system("cls");
                mostrarestructura(pelicula);
                modif=menu("\n*****MODIFICAR*****\n1.-TITULO\n2.-GENERO\n3.-PUNTAJE\n4.-DURACION\n5.-DESCRIPCION\n6.-LINK IMAGEN\n7.-MENU PRINCIPAL\n");

                switch(modif)
                {
                case 1:
                    titulo("Ingrese el titulo de la pelicula: ",auxtitulo);
                    strupr(auxtitulo);
                    strcpy(pelicula.titulo, auxtitulo);
                    flag=1;
                    system("cls");
                    break;
                case 2:
                    genero("Seleccione el Genero de la pelicula: ",auxgenero);
                    strcpy(pelicula.genero, auxgenero);
                    conf=crOrEsc("\nDesea seleccionar un genero adicional? \n");
                    while(conf!=0)
                    {
                        genero("Seleccione el Genero de la pelicula: ",auxgenero);
                        strcat(pelicula.genero, ", ");
                        strcat(pelicula.genero, auxgenero);
                        conf=crOrEsc("\nDesea seleccionar un genero adicional? \n");
                    }
                    flag=1;
                    system("cls");
                    break;
                case 3:
                    auxpuntaje= getflotante("ingrese el puntaje de la pelicula: ");
                    while(!(auxpuntaje>0 && auxpuntaje<=10))
                    {
                        auxpuntaje= getflotante("ERROR. ingrese el puntaje de la pelicula(1/10): ");
                    }
                    pelicula.puntaje = auxpuntaje;
                    flag=1;
                    system("cls");
                    break;
                case 4:
                    auxduracion=getentero("Ingrese la duracion de la pelicula (minutos): ");
                    pelicula.duracion = auxduracion;
                    system("cls");
                    flag=1;
                    break;
                case 5:
                    descripcion("Ingrese la breve reseña de la pelicula: ", auxdescripcion);
                    strcpy(pelicula.descripcion, auxdescripcion);
                    system("cls");
                    flag=1;
                    break;
                case 6:
                    link("copie el link de la imagen a continuacion: ", auxlinkImagen);
                    strcpy(pelicula.linkImagen, auxlinkImagen);
                    flag=1;
                    system("cls");
                    break;
                case 7:
                    fseek(bin, (-1)*sizeof(pelicula),SEEK_CUR);
                    fflush(stdin);
                    ans= fwrite(&pelicula, sizeof(pelicula), 1, bin);
                    if (ans!=0 && flag!=0)
                    {
                        printf("Datos de la Pelicula: %s .MODIFICADOS\n",pelicula.titulo);
                    }
                    if(flag==0)
                    {
                        printf("\nsin cambios realizados\n");
                    }
                    if(ans==0)
                    {
                        printf("LOS DATOS NO PUDIERON SER MODIFICADOS");
                    }
                    seguir='n';
                    break;
                default:
                    printf("ERROR. Opci%cn inv%clida! ",162,160);
                    break;
                }
            }
            while(seguir=='s');
            break;
        }
    }
    if(find==0)
        printf("\nPelicula no encontrada\n\n");
    fclose(bin);
}

void generarPagina(EMovie pelicula, FILE *bin, char nombre[])
{
    FILE *MovieTP3;
    int cant;
    int flag=0;
    char head[]= {"<html>\n<head>\n<body>\n"};


    if((MovieTP3=fopen(PATHTML,"w"))==NULL)
    {
        printf("No se pudo abrir el archivo HTML");
        system("pause");
    }
    else
    {
        fprintf(MovieTP3,"%s",head);

        rewind(bin);
        while(!feof(bin))
        {
            cant=fread(&pelicula,sizeof(pelicula),1,bin);
            if(cant!=1)
            {
                if(feof(bin))
                {
                    break;
                }
                else
                {
                    printf("No se puede leer el archivo");
                    break;
                }
            }
            if(pelicula.id!=0)
            {
                fprintf(MovieTP3,"<article class='col-md-4 article-intro'>\n");
                fprintf(MovieTP3," <a href='#'>\n");
                fprintf(MovieTP3,"<img src='%s' alt='' >\n",pelicula.linkImagen);
                fprintf(MovieTP3,"</a>\n");
                fprintf(MovieTP3,"<h3>\n");
                fprintf(MovieTP3,"<a href='#'> %s </a>\n",pelicula.titulo);
                fprintf(MovieTP3,"</h3>\n");
                fprintf(MovieTP3,"<ul>");
                fprintf(MovieTP3,"<li>Género: %s </li>\n",pelicula.genero);
                fprintf(MovieTP3,"<li>Puntaje:%.1f</li>\n",pelicula.puntaje);
                fprintf(MovieTP3,"<li>Duración:%d</li>\n",pelicula.duracion);
                fprintf(MovieTP3,"<li>Descripcion: %s </li>\n",pelicula.descripcion);
                fprintf(MovieTP3,"</article>\n");
                flag=1;
            }
        }
        if(flag==0)
        {
            fprintf(MovieTP3,"No hay peliculas cargadas.\n");
        }
        fprintf(MovieTP3,"</div>\n");
        fprintf(MovieTP3,"<!-- /.row -->\n");
        fprintf(MovieTP3,"</div>\n");
        fprintf(MovieTP3,"<!-- /.container -->\n");
        fprintf(MovieTP3,"<!-- jQuery -->\n");
        fprintf(MovieTP3,"<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(MovieTP3,"<!-- Bootstrap Core JavaScript -->\n");
        fprintf(MovieTP3,"<script src='js/bootstrap.min.js'></script>\n");
        fprintf(MovieTP3,"<!-- IE10 viewport bug workaround -->\n");
        fprintf(MovieTP3,"<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(MovieTP3,"<!-- Placeholder Images -->\n");
        fprintf(MovieTP3,"<script src='js/holder.min.js'></script>\n");
        fprintf(MovieTP3,"</body>\n");
        fprintf(MovieTP3,"</html>");

        printf("PAGINA HTML GENERADA CON EXITO\n\n");
        fclose(MovieTP3);
        fclose(bin);
    }
}

int checkFile(EMovie pelicula, FILE *bin)
{
    int cant, ans=0;
    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(&pelicula, sizeof(pelicula), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(pelicula.id!=0)
        {
            ans++;
        }
    }
    rewind(bin);
    return ans;
}

int getUniqueID(EMovie pelicula, FILE *bin)
{
    int cant, ans=0;
    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(&pelicula, sizeof(pelicula), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        ans++;
    }
    rewind(bin);
    return ans;
}

char getchara(char cadena[])
{
    char chara;
    printf("%s",cadena);
    fflush(stdin);
    scanf("%c",&chara);
    return chara;
}

int getentero(char cadena[])
{
    int validint, entero, letras;
    char auxiliar[128];
    char numero[5];
    printf("%s", cadena);
    scanf("%s", auxiliar);

    validint = validarnumeros(auxiliar);
    letras= strlen(auxiliar);

    while (validint!=0 || letras>5)
    {
        printf("ERROR. n%cmero inv%clido... reintente por favor\n",163,160);
        printf("%s", cadena);
        scanf("%s",auxiliar);
        validint = validarnumeros(auxiliar);
        letras= strlen(auxiliar);
    }
    strcpy(numero, auxiliar);
    entero= atoi(numero);

    return entero;
}

long int getenterolargo(char cadena[])
{
    long int validint, entero, letras;
    char auxiliar[128];
    char numero[5];
    printf("%s", cadena);
    scanf("%s", auxiliar);

    validint = validarnumeros(auxiliar);
    letras= strlen(auxiliar);

    while (validint!=0 || letras>10)
    {
        printf("ERROR. n%cmero inv%clido... reintente por favor\n",163,160);
        printf("%s", cadena);
        scanf("%s",auxiliar);
        validint = validarnumeros(auxiliar);
        letras= strlen(auxiliar);
    }
    strcpy(numero, auxiliar);
    entero= atol(numero);

    return entero;
}

float getflotante (char cadena[])
{
    int validf, letras;
    float flotante;
    char numero[21];

    printf("%s", cadena);
    scanf("%s", numero);
    letras = strlen(numero);

    validf = validarflotantes(numero);

    while (validf!=0 || letras>20)
    {
        printf("ERROR. el numero no puede contener letras, ni s%cmbolos a excepci%cn del punto (coma)... reintente por favor\n",161, 162);
        printf("%s", cadena);
        scanf("%s",numero);
        validf = validarflotantes(numero);
    }
    flotante = atof(numero);

    return flotante;
}

void gettexto(char cadena[],char save[])
{
    char auxiliar [1024];
    int letras, validtext;

    printf("%s",cadena);
    fflush(stdin);
    scanf("%[^\n]", auxiliar);

    letras = strlen(auxiliar);
    validtext = validartexto(auxiliar);

    while (validtext!=0 || letras >50)
    {
        printf("ERROR. descripci%cn muy larga... reintente por favor:\n",162);
        printf("%s", cadena);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
        letras = strlen(auxiliar);
        validtext = validartexto(auxiliar);
    }
    strcpy(save, auxiliar);
}

int crOrEsc (char cadena[])
{
    char conf;

    printf("%s", cadena);
    printf("\npresione ENTER para continuar o ESC para cancelar\n\n");
    fflush(stdin);
    conf= getch();
    while (!(conf==27 || conf==13))
    {
        printf("\nERROR. presione ENTER para continuar o ESC para cancelar\n\n");
        fflush(stdin);
        conf= getch();
    }
    if (conf!= 27 )
    {
        return 1;
    }
    else
    {
        printf("\nACCION CANCELADA POR EL USUARIO\n\n");
        return 0;
    }
}

//VALIDACIONES

int validartexto(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if((cadena[i] == ' ') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
    }
    return ans;
}

int validarnumeros(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
    }
    return ans;
}

int validarflotantes(char cadena[])
{
    int i, max, ans;
    int contpuntos;

    contpuntos = contadorcadena(cadena);
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if ((contpuntos==0) && ((cadena[i]=='.')||(cadena[i] >= '0' && cadena[i] <= '9')))
        {
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
    }
    return ans;
}

int contadorcadena(char cadena[])
{
    int i, max, ans;
    int contadorpuntos=0;

    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if(cadena[i]=='.')
        {
            contadorpuntos++;
        }
        if(contadorpuntos==1 || contadorpuntos==0)
        {
            ans=0;
        }
        else
        {
            ans=1;
        }
    }
    return ans;
}
