#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int resizeDown(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
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
            this->filter = al_filter;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }
    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int flag=0;
    if(this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {
            flag = resizeUp(this);
        }
        if(flag == 0)
        {
            //this->pElements[this->size] = pElement;
            *(this->pElements + this->size) = pElement;
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        free(this->pElements);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Devuelve cant. de elementos ocupados en el arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL)
    {
        if(index > this->size || index < 0)
        {
            return returnAux;
        }
        returnAux = this->pElements[index];
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this != NULL && pElement != NULL)
    {
        returnAux = 0;
        for(i=0; i<=this->size; i++)
        {
            if(this->pElements[i] == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL)
    {
        if(index >= 0 && index <= this->size)
        {
            if(index == this->size)
            {
                al_add(this, pElement);
            }
            else
            {
                *(this->pElements+index) = pElement;
            }
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = contract(this, index);
        if(returnAux == 0)
        {
            this->size--;
        }
    }
    return returnAux;
}

/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this) //9
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->reservedSize != AL_INITIAL_VALUE)
        {
            returnAux = resizeDown(this); //realocar el reservedSize a 10
        }
        else if(this->reservedSize == AL_INITIAL_VALUE || returnAux==0)
        {
            this->size=0;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    int i;
    ArrayList* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = al_newArrayList();
        if(returnAux != NULL)
        {
            for(i=0; i<=this->size; i++)
            {
                al_add(returnAux, al_get(this, i));
            }
        }
    }
    return returnAux;
}

/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement) //alt: agregar al final,y luego swapear al indice deseado.
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL)
    {
        if(index >= 0 && index <= this->size)
        {
            if(index == this->size)
            {
                al_add(this, pElement);
            }
            else if(index < this->size)
            {
                returnAux = expand(this, index);
                if(returnAux == 0)
                {
                    *(this->pElements+index) = pElement;
                }
            }
        }
    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this != NULL && pElement != NULL)
    {
        for(i=0; i<=this->size; i++)
        {
            if(*(this->pElements+i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->len(this) > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }

    }
    return returnAux;
}


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = al_get(this, index);
        if(returnAux != NULL)
        {
            al_remove(this, index);
        }
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this, int from, int to)
{
    void* returnAux = NULL;
    int i;
    if(this != NULL)
    {
        if(from < to && from >= 0 && from < this->size && to > 0 && to <= this->size)
        {
            returnAux = al_newArrayList();
            if(returnAux != NULL)
            {
                for(i=from; i<to; i++)
                {
                    al_add(returnAux, al_get(this, i));
                }
            }
        }
    }
    return returnAux;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int i;
    int returnAux = -1;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;
        //if(this->size < this2->size) //cambiar a llamados de funcion len, desde la estructura.
        if(this->len(this) < this->len(this2))
        {
            return returnAux;
        }
        else
        {
            for(i=0; i<=this2->size; i++)
            {
                if(al_contains(this, *(this2->pElements+i)) != 1)
                {
                    return returnAux;
                }
                returnAux = 1;
            }
        }
    }
    return returnAux;
}


/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int i;
    int j;
    void* aux = NULL;
    void* comp1 = NULL;
    void* comp2 = NULL;
    int returnAux = -1;
    if(this != NULL && pFunc != NULL && order >= 0 && order < 2)
    {
        for(i=0; i<this->size-1;i++)
        {
            for(j=i+1; j<this->size;j++)
            {
                comp1 = al_get(this,i);
                comp2 = al_get(this,j);
                if(order == 0)
                {
                    if(pFunc(comp1,comp2) < 0)
                    {
                        aux = *(this->pElements+i);
                        *(this->pElements+i) = *(this->pElements+j);
                        *(this->pElements+j) = aux;
                    }
                }
                else
                {
                    if(pFunc(comp1,comp2) > 0)
                    {
                        aux = *(this->pElements+i);
                        *(this->pElements+i) = *(this->pElements+j);
                        *(this->pElements+j) = aux;
                    }
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** aux;
    aux = (void**) realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT)); //void (4byes) por, lo que hab�a + lo nuevo que necesito.
    if(aux!=NULL)
    {
        this->pElements = aux;
        this->reservedSize = this->reservedSize + AL_INCREMENT;
        returnAux = 0;
    }
    return returnAux;
}

int resizeDown(ArrayList* this)
{
    int returnAux = -1;
    void** aux;
    aux = (void**) realloc(this->pElements, sizeof(void*)*AL_INITIAL_VALUE);
    if(aux!=NULL)
    {
        this->pElements = aux;
        this->reservedSize=AL_INITIAL_VALUE;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int i;
    int returnAux = -1;
    if(this != NULL)
    {
        if(index >= 0 && index <= this->size)
        {
            if(this->size == this->reservedSize) //Que compruebe por fuera.
            {
                returnAux = resizeUp(this);
            }
            else if(this->size < this->reservedSize || returnAux == 0)
            {
                this->size++;
                for(i=this->size; i>index; i--)
                {
                    *(this->pElements+i) = *(this->pElements+(i-1));
                }
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int i;
    int returnAux = -1;
    if(this != NULL)
    {
        if(index >= 0 && index <= this->size)
        {
            for(i=index; i<=this->size; i++)
            {
                *(this->pElements+i) = *(this->pElements+(i+1));
            }
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Genera un nuevo arraylist filtrando segun criterio.
 *
 * \param ArrayList* arraylist a filtrar
 * \param void* funcion de criterio
 * \return ArrayList* al_filter(ArrayList* listIn , int
 *
 */
ArrayList* al_filter(ArrayList* listIn , int (*functionFilter)(void*))
{
    ArrayList* returnAux = NULL;
    int i;
    void* elemento = NULL;
    if(listIn != NULL && functionFilter != NULL)
    {
        returnAux = al_newArrayList();
        for(i=0; i<listIn->len(listIn); i++)
        {
            elemento = listIn->get(listIn , i);
            if(functionFilter(elemento))
            {
                returnAux->add(returnAux, elemento);
            }

        }
    }
    return returnAux;
}
