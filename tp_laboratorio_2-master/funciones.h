#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define NOMBRE 63
#define DNI 15
#define EDAD 11
#define CANT 20
#define ESC 27


typedef struct
{
    char nombre[NOMBRE];
    int edad;
    int estado;
    long int dni;
} Struct1;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Obtiene el primer indice libre del array.
 * @param lista, el array se pasa como parametro.
 * @param ext, la extension del array.
 * @return el primer indice disponible.
 */
int obtenerEspacioLibre(Struct1 vec[], int ext);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param vec, el array se pasa como parametro.
 * @param ext,es la extension del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int buscarPorDni(Struct1 vec[], int ext);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief inicializa el vector con 0 indicando que su estado es disponible.
 *
 * \param vec, se pasa el array como parametro.
 * \param ext, es la extension del array.
 * \return no retorna datos.
 *
 */
void indexvacio (Struct1 vec[], int ext);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por pantalla las opciones del menu, y te deja seleccionar una.
 *
 * \param cadenas, se pasa el array como parametro.
 * \return retorna un entero con la opcion seleccionada.
 *
 */
int menu(char cadenas[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief permite cargar datos en el array correspondiente.
 *
 * \param vec, se pasa el array como parametro.
 * \param place, es el lugar donde esta libre el array para ser cargado.
 * \return no retorna datos.
 *
 */
void alta(Struct1 vec[], int place);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief realiza la baja de un registro, comparando el codigo ingresado por el usuario y el existente; cambiando su estado de ocupado a libre.
 *
 * \param vec, se pasa el array como parametro.
 * \param ext, es la extencion del array.
 * \param codigo, es el id ingresado por el usuario a comparar con el existente.
 * \return no devuelve datos.
 *
 */
void baja(Struct1 vec[],int ext, long int codigo);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime en la consola lo cargado.
 *
 * \param vec, el array se pasa como parametro.
 * \param ext, la extension del array.
 * \return no devuelve datos.
 *
 */
void mostrar(Struct1 vec[], int ext);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime un grafico de columnas por consola mostrando la estadistica en base a los rangos de edades establecidos,
 *         tambien muestra porcentajes.
 *
 * \param vec, el array se pasa como parametro.
 * \param ext, la extension del array.
 * \return no devuelve datos.
 *
 */
void graficoEdad(Struct1 vec[], int ext);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief ordena alfabeticamente de la A a la Z
 *
 * \param vec, el array se pasa como parametro.
 * \param ext, la extension del array.
 * \return no devuelve datos.
 *
 */

void ordenarAscendAlfa(Struct1 vec[], int ext);

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


#endif // FUNCIONES_H_INCLUDED
