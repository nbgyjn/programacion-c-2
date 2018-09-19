#include "persona.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void init(EPersona lista[], int len){
    int i;
    for(i=0; i<len; i++){
        lista[i].estado = 1;
    }
}


int obtenerEspacioLibre(EPersona lista[], int len){
    int i;
    int retorno = -1;

    for(i=0; i<len; i++){
        if(lista[i].estado == 1){
            retorno = i;
            break;
        }
    }
    return retorno;
}





int alta(EPersona personas[], int len)
{
    int retorno = 0;
    int i;
    if(len > 0 && personas != NULL)
    {
        i = obtenerEspacioLibre(personas, len);
        if(i >= 0)
        {

            printf("Ingrese nombre: \n");
            fflush(stdin);
            gets(personas[i].nombre);
            printf("Ingrese apellido: \n");
            fflush(stdin);
            gets(personas[i].apellido);
            printf("Ingreso el dni: \n");
            scanf("%ld",&personas[i].dni);
            printf("Ingreso el dia: \n");
            scanf("%d",&personas[i].feNac.dia);
            printf("Ingrese mes: \n");
            scanf("%d",&personas[i].feNac.mes);
            printf("Ingrese año: \n");
            scanf("%d",&personas[i].feNac.anio);
            personas[i].estado = 1;
            retorno = 1;
        }
    }
    return retorno;
}

int baja(EPersona personas[], int len)
{
    int i;
    int retorno = 0;
    int val;
    int dni;
    printf("dni a dar de baja: ");
    scanf("%ld", &dni);
    val = buscarPorDni(personas,dni , tan);
    while(val == 0)
    {
        printf("no se encontro la dni\n");
        printf("dni a dar de baja: ");
        scanf("%d", &matriculab);
        val = buscarPorMatricula(aviones,matriculab , tan);
    }
    aviones[val].estado = 0;
    printf("matricula dada de baja.\n");
    return retorno;
}

int buscarPorMatricula(Eaviones aviones[],int matriculab,int tan)
{

    for(int i=0; i<tan; i++)
    {
        if(aviones[i].estado==1 && aviones[i].matricula==matriculab)
        {
            return i;
        }
    }
    return 0;
}



void mostrarListaPersonas(EPersona persona[], int tan)
{
    int i;

    for(i=0; i<tan; i++)
    {
        if (persona[i].estado==1)
        {
            printf("\n Nombre : %s /Apellido : %s /dni : %ld /ingreso %d -- %d -- %d \n",persona[i].nombre,persona[i].apellido,persona[i].dni,persona[i].feNac.dia,persona[i].feNac.mes,persona[i].feNac.anio);
        }

    }
}
