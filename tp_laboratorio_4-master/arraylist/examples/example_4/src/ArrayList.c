#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_DECREMENT      5
#define AL_INITIAL_VALUE  10
//___________________

/** \brief asigna una nueva arrayList con AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Retorna (NULL) si hay error [no asigna memoria] o retorna el puntero  al nuevo arraylist si esta bien
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}

/** \brief Agrega un elemento al final de ArrayList. Verifica que tanto el puntero pList como pElement
 *         sean distintos de NULL
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int  Si falla la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_add(ArrayList* pList, void* pElement)
{
    int returnAux = -1;

    if(pElement!=NULL && pList != NULL && !resizeUp(pList))
    {
        pList->pElements[pList->size]= pElement;
        pList->size ++;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina el ArrayList . Verificando que el puntero pList sea distinto de NULL.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1), si esta vacío (0).
 *
 */
int al_deleteArrayList(ArrayList* pList)
{

    int returnAux = -1;
    if(pList != NULL){
        free(pList->pElements);
        free(pList);


        returnAux= 0;
    }

    return returnAux;
}

/** \brief obtiene la cantidad de elementos del arraylist y lo retorna.
 *
 * \param pList ArrayList* el array list se pasa como parametro.
 * \return int retorna el tamaño del arraylist.
 *
 */
int al_len(ArrayList* plist)
{
    int returnAux = -1;
    if(plist!= NULL){
        returnAux= plist->size;
    }

    return returnAux;
}


/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
 *         puntero pList sea distinto de NULL y que num sea positivo e inferior al tamaño del array.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro
 * \param num int el indice ingresado se pasa como parametro.
 * \return Si falla, la función retorna (NULL) y si tiene éxito retorna el elemento.
 *
 */
void* al_get(ArrayList* pList, int num)

{
    void* ans = NULL;
    if(pList!= NULL && num >= 0 && num < pList->size){
        ans = pList->pElements[num];
    }
    return ans;
}

/** \brief Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
 *         puntero pList como pElement sean distintos de NULL. (es un buscador).
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si falla, retorna (-1), si encuentra el elemento (1) y si no lo encuentra (0).
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int i;
    int returnAux = 0;

    if(pList != NULL && pElement != NULL){
        for(i=0; i<pList->size; i++) {
          if(pList->pElements[i]== pElement){
            returnAux= 1;
            break;
          }

        }
    }
    else {
        returnAux = -1;
    }
    return returnAux;
}

/** \brief Inserta un elemento en el ArrayList, en el índice especificado. Verificando que tanto el puntero
 *         pList como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del array. reescribe si es necesario.
 *
 * \param pList ArrayList* el array list se pasa como parametro
 * \param index int el indice se pasa com parametro
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si falla, retorna (-1) y si tiene éxito (0).
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int returnAux = -1;
    if(pList != NULL && pElement!= NULL){
      if(index >=0 && index < pList->size) {
        pList->pElements[index]= pElement;
        returnAux= 0;
      }
    }
    return returnAux;
}

/** \brief Elimina un elemento del ArrayList, en el índice especificado. Verificando que el puntero pList
 *         sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *
 * \param pList ArrayList* el array list se pasa como parametro.
 * \param index int el indice se pasa como parametro
 * \return int Si falla, la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_remove(ArrayList* pList,int index)
{
    int returnAux = -1;
    if(pList!= NULL && index>=0 && index<pList->size){
        pList->size--;
        resizeDown(pList);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Borra todos los elementos de ArrayList. Verificando que el puntero pList sea distinto de NULL. (solo la informacion, no como el delete que borra todo)
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_clear(ArrayList* pList)
{
    int returnAux = -1;
    int i;

    if(pList != NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            free(pList->pElements[i]);
            pList->size = 0;
        }
        resizeDown(pList);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Retorna un nuevo ArrayList copia del ArrayList original. Verificando que el puntero pList sea distinto de NULL.
 *
 * \param pList ArrayList* el array list se pasa como parametro.
 * \return ArrayList* Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo array.
 *
 */
ArrayList* al_clone(ArrayList* pList)
{
    int i;
    ArrayList *returnAux= NULL;

    if(pList != NULL){
        returnAux = al_newArrayList();
        if(returnAux != NULL){
           for(i=0; i< pList->size; i++){
            al_add(returnAux, pList->pElements[i]);
           }
        }
    }

    return returnAux;
}

/** \brief Desplaza los elementos e inserta en la posición index. Verificando que tanto el puntero pList como pElement sean distintos de NULL
 *         y que index sea positivo e inferior al tamaño del array.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param index int el indice se pasa como parametro
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int returnAux= -1;
    if(pList != NULL && pElement != NULL && index >= 0 && index < pList->reservedSize) {
        pList->size++;
        resizeUp(pList);
        expand(pList,index);
        al_set(pList,index,pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Retorna el índice de la primera aparición de un elemento (element) en el ArrayList. Verificando
 *         que tanto el puntero pList como pElement sean distintos de NULL.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si la verificación falla o no encuentra el elemento la función retorna (-1) y si encuentra el elemento retorna su índice.
 *
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int i;
    int returnAux = -1;

    if(pList != NULL && pElement != NULL){
        for(i=0; i<pList->size; i++) {
          if(pList->pElements[i]== pElement){
            returnAux= i;
          }
        }
    }

    return returnAux;
}

/** \brief Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero pList sea distinto de NULL.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
 *
 */
int al_isEmpty(ArrayList* pList)
{
    int returnAux = -1;
    if(pList != NULL)
    {
        if(pList->size == 0)
            returnAux = 1;
        else
            returnAux = 0;
    }
    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina de la lista.
 *         Verificando que el puntero pList sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param index int el indice se pasa como parametro.
 * \return void* Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 *
 */
void* al_pop(ArrayList* pList,int index)
{
    void *retorno = NULL;
    if(pList != NULL && index>=0 && index<pList->size){
        retorno = al_get(pList, index);
        contract(pList, index);
    }
    return retorno;
}

/** \brief Retorna un nuevo ArrayList con el subconjunto de elementos. Verificando que el puntero pList sea distinto
 *         de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño del array.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param from int el valor del indice "desde" donde se empieza a copiar se pasa como parametro.
 * \param to int el valor del indice "hasta" donde se termina de copiar se pasa como parametro.
 * \return ArrayList*  Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo arraylist.
 *
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    int i;
    ArrayList* nuevoArray= NULL;

    if(pList != NULL &&  from >= 0 && from < to && to <= al_len(pList)){
        nuevoArray= al_newArrayList();
        if(nuevoArray != NULL)
        {
            for(i=from; i<to; i++){
                al_add(nuevoArray,al_get(pList,i));
            }
        }
    }
    return nuevoArray;
}

/** \brief Comprueba si los elementos pasados son contenidos por el ArrayList. Verificando que tanto el
 *         puntero pList como pList2 sean distintos de NULL.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param pList2 ArrayList* el segundo arraylist se pasa como parametro.
 * \return int Si la verificación falla o no encuentra el elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna (1).
 *
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int returnAux = -1;
    int i;
    if(pList!=NULL && pList2!=NULL)
    {
        returnAux = 1;
        for(i=0; i<pList2->size; i++)
        {
            if(!al_contains(pList, pList2-> pElements[i]))
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Ordena los elementos del array recibiendo como parámetro la función que sera la encargada de determinar que elemento es mas grande que otro
 *         y si se debe ordenar de manera ascendente o descendente. Verificando que tanto el puntero pList como el puntero a la funcion pFunc sean distintos de NULL.
 *
 * \param plist arraylist* el arraylist se pasa como parametro.
  * \param pFunc (*pFunc) puntero a la funcion para comparar elementos del arraylist.
 * \param order int  [1] indica ASCENDENTE - [0] indica DESCENDENTE
 * \return int  Si la verificación falla (-1) caso contrario retorna (0).
 *
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
int returnAux = -1;
    void* pAux;
    int i, j;

    if(pList != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i=0; i < pList->size-1; i++)
        {
            for(j=i+1; j < pList->size; j++)
            {
                if(pFunc(pList->pElements[i],pList->pElements[j]) == 1 && order == 1)
                {
                    pAux = pList->pElements[i];
                    pList->pElements[i] = pList->pElements[j];
                    pList->pElements[j] = pAux;
                }
                else if(pFunc(pList->pElements[i],pList->pElements[j]) == -1 && order == 0)
                {
                    pAux = pList->pElements[i];
                    pList->pElements[i] = pList->pElements[j];
                    pList->pElements[j] = pAux;
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;
}

/** \brief incrementa elementos (espacio vacios) en AL_INCREMENT elementos. Verificando que el arrayList sea distintos de NULL.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla, retorna (-1), caso contrario retorna (0).
 *
 */
int resizeUp(ArrayList* pList)
{
    int returnAux = -1;
    void* pAux;

    if(pList != NULL)
    {
        if(pList->size == pList->reservedSize)
        {
            pAux = realloc(pList->pElements, sizeof(void*)*(pList->reservedSize + AL_INCREMENT));
            if(pAux != NULL)
            {
                pList->reservedSize = pList->reservedSize + AL_INCREMENT;
                pList->pElements = pAux;
                returnAux = 0;
            }
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief expande array de elementos(agranda).  Verificando que el arrayList sea distintos de NULL.
 *
 * \param pList arrayList* el arraylist se pasa como parametro.
 * \param index int el indice del elemento
 * \return int Si la verificación falla, retorna (-1), caso contrario retorna (0).
 *
 */
int expand(ArrayList* pList,int index)
{
    int i;
    int returnAux = -1;
    if(pList!= NULL && index>=0 && index < pList->size){
        returnAux=0;
        for(i=pList->size; i>index; i--){
            al_set( pList,i+1,pList->pElements[i]);
            }
    }

    return returnAux;


}

/** \brief contrae el array de elementos (minimiza) mueve. Verificando que el arrayList sea distintos de NULL.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \param index int el indice del elemento
 * \return int Si la verificación falla, retorna (-1), caso contrario retorna (0).
 *
 */
int contract(ArrayList* pList,int index)
{
    int i;
    int returnAux = -1;
    if(pList!= NULL && index>=0 && index < pList->size){
        returnAux=0;
        for(i=index; i<pList->size; i++){
                pList->pElements[i] = pList->pElements[i+1];
            al_set( pList,i+1,pList->pElements[i+1]);

        }
        pList->size--;
    }

    return returnAux;
}

/** \brief decrementa el array de elementos. Verificando que el arrayList sea distintos de NULL.
 *
 * \param pList ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificacion falla retorna (-1), caso contrario retorna cero (0).
 *
 */
int resizeDown(ArrayList* pList)

{
    int returnAux = -1;
    void* pAux;

    if(pList != NULL)
    {
        if((pList->reservedSize - pList->size) > AL_INCREMENT)
        {
            pAux = realloc(pList->pElements, sizeof(void*)*(pList->reservedSize - AL_INCREMENT));
            if(pAux != NULL)
            {
                pList->reservedSize = pList->reservedSize - AL_DECREMENT;
                pList->pElements = pAux;
                returnAux = 0;
            }
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;

}
