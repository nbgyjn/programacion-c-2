/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void inicializarVuelosEstado(Evuelos vuelos[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        vuelos[i].estado = 0;
    }
}

void inicializarVuelosHardCode(Evuelos vuelos[])
{

    char origen[][50]={"primero","segundo","tercero","cuarto","quinto"};
    char llegada[][50]={"pablo","Manu","Pablo","Catriel","pablo"};
    int matricula[]={37190429,38165428,39450429,40112423,41780499};
    int horario[]={18,20,15,22,21};
    int id[]={10,12,11,3,8};

    int i;

    for(i=0; i<5; i++)
    {

        vuelos[i].horario=horario[i];
        vuelos[i].id=id[i];
        vuelos[i].matricula=matricula[i];
        vuelos[i].estado = 1;
        strcpy(vuelos[i].origen, origen[i]);
        strcpy(vuelos[i].llegada, llegada[i]);

    }
}

int buscarLugarLibreVuelo(Evuelos vuelos[],int tan)
{
    int retorno = -1;
    int i;
    if(tan > 0 && vuelos != NULL)
    {
        retorno = -2;
        for(i=0; i<tan; i++)
        {
            if(vuelos[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}





int altaVuelo(Evuelos vuelos[],int tan)
{
    int retorno = 0;
    int i;
    if(tan > 0 && vuelos != NULL)
    {
        i = buscarLugarLibre(vuelos,tan);
        if(i >= 0)
        {

            printf("Ingrese origen: \n");
            fflush(stdin);
            gets(vuelos[i].origen);
            printf("Ingrese llegada: \n");
            fflush(stdin);
            gets(vuelos[i].llegada);
            printf("Ingrese horario: \n");
            scanf("%d",&vuelos[i].horario);
            printf("Ingrese id: \n");
            scanf("%d",&vuelos[i].id);
            printf("Ingrese matricula: \n");
            scanf("%d",&vuelos[i].matricula);
            vuelos[i].estado = 1;
            retorno = 1;
        }
    }
    return retorno;
}

void mostrarListaVuelos(Evuelos vuelos[], int tan)
{
    int i;

    for(i=0; i<tan; i++)
    {
        if (vuelos[i].estado==1)
        {
            printf("\n origen : %s -destino : %s -estado : %d -matricula : %d \n",vuelos[i].origen,vuelos[i].llegada,vuelos[i].estado,vuelos[i].matricula);

        }

    }
}

*/
