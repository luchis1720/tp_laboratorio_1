#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <ctype.h>
#define PATH ".\\file\\bin.dat"
#define PATHTML ".\\file\\MovieTP3.html"
#define LIBRE 0
#define OCUPADO 1

typedef struct{
    int id;
    char titulo[31];
    char genero[129];
    float puntaje;
    int duracion;
    char descripcion[356];
    char linkImagen[251];
}EMovie;

/**
 *  \brief Agrega una pelicula al archivo binario.
 *  @param movie la estructura a ser agregada al archivo.
 *  @param bin el archivo binario se pasa como parametro.
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no.
 */
int agregarPelicula(EMovie, FILE *bin);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 * \param ECarga* la lista de peliculas a ser agregadas en el archivo.
 * \param nombre[] char el nombre para el archivo.
 * \return void no retorna datos.
 *
 */
void generarPagina(EMovie, FILE *bin, char nombre[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por pantalla las opciones del menu, y te deja seleccionar una.
 *
 * \param cadenas[] char se pasa el array como parametro.
 * \return int retorna la opcion seleccionada.
 *
 */
int menu(char cadenas[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief revisa si el archivo binario tiene registros cargados, no dados de baja, y los cuenta.
 *
 * \param EMovie la estructura se pasa como parametro.
 * \param bin FILE* el archivo binario se pasa como parametro.
 * \return int devuelve al cantidad de registros contados.
 *
 */
int checkFile(EMovie, FILE *bin);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief carga la estructura con los datos solicitados, y se los pasa al archivo binario.
 *
 * \param EMovie la estructura se pasa como parametro.
 * \param *bin el archivo binario se pasa como parametro.
 * \return void no retorna datos.
 *
 */
void altapelicula(EMovie, FILE *bin);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief revisa si el archivo binario tiene registros cargados, y los cuenta.
 *
 * \param EMovie la estructura se pasa como parametro.
 * \param bin FILE* el archivo binario se pasa como parametro.
 * \return int devuelve al cantidad de registros contados.
 *
 */
int getUniqueID(EMovie pelicula, FILE *bin);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Solicita un titulo al usuario y lo devuelve.
 *
 * \param cadena[] char es el mensaje a ser mostrado.
 * \param *save array donde se guarda el texto.
 * \return void no devuelve datos.
 *
 */
void titulo(char cadena[],char *save);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Solicita un enlace al usuario y lo devuelve.
 *
 * \param cadena[] char es el mensaje a ser mostrado.
 * \param *save array donde se guarda el texto.
 * \return void no devuelve datos.
 *
 */
void link(char cadena[],char *save);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Solicita una descripcion al usuario y lo devuelve.
 *
 * \param cadena[] char es el mensaje a ser mostrado.
 * \param *save array donde se guarda el texto.
 * \return void no devuelve datos.
 *
 */
void descripcion(char cadena[],char *save);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Solicita un texto al usuario y lo devuelve.
 *
 * \param cadena[] char es el mensaje a ser mostrado.
 * \param *save array donde se guarda el texto.
 * \return void no devuelve datos.
 *
 */
void genero(char cadena[],char *save);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief realiza la baja logica de una pelicula
 *
 * \param EMovie la estructura se pasa como parametro.
 * \param bin FILE* el archivo se pasa como parametro.
 * \return void no retorna datos
 *
 */
void borrarpelicula(EMovie, FILE *bin);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief muestra los datos cargados en la estructura.
 *
 * \param EMovie la estructura se pasa como parametro.
 * \return void no devuelve datos.
 *
 */
void mostrarestructura(EMovie);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief muestra por pantalla, lo cargado en el archivo binario.
 *
 * \param FILE* el archivo se pasa como parametro.
 * \param Emovie la estructura se pasa com parametro.
 * \return void no devuelve datos.
 *
 */
void checkbin(FILE*, EMovie);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief permite buscar en el archivo, y modificar los parametros de un registro.
 *
 * \param Emovie la estructura se pasa como parametro
 * \param bin FILE* el archivo se pasa como parametro.
 * \return void no retorna datos.
 *
 */
void modificar(EMovie, FILE *bin);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param cadena, es el mensaje a ser mostrado
 * \return el caracter ingresado por el usuario
 *
 */
char getchara(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero entero al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 */
int getentero (char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero entero largo al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 */
long int getenterolargo (char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero flotante al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 */
float getflotante (char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un texto al usuario y lo devuelve.
 * \param cadena, es el mensaje a ser mostrado.
 * \param save,  array donde se guarda el texto.
 * \return no devuelve datos.
 */
void gettexto(char cadena[],char save[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief pregunta al usuario si desea continuar o cancelar.
 *
 * \param cadena, es el msj a ser mostrado.
 * \return devuelve 1 si desea continuar, o 0 si cancelo.
 *
 */
int crOrEsc (char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//VALIDACIONES

/** \brief valida si una cadena de texto solo tiene caracteres y no numeros.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo letras o 1 si tiene numeros.
 *
 */

int validartexto(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida si una de texto solo tiene numeros y no letras ni signos.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo numeros o 1 si tiene letras y/o signos.
 *
 */
int validarnumeros(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida si una cadena de texto solo tiene numeros y no letras ni signos, a excepcion del punto (coma).
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo numeros o 1 si tiene letras y/o signos.
 *
 */
int validarflotantes(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief cuenta simbolos en una cadena de texto.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si hay un solo simbolo, o 1 si tiene mas de uno.
 *
 */

int contadorcadena(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // FUNCIONES_H_INCLUDED
