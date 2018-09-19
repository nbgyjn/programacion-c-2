#include "biblioteca.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void inicializarAvionesEstado(Eaviones aviones[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        aviones[i].estado = 0;
    }
}

void inicializarAvionesHardCode(Eaviones aviones[])
{

    char modelo[][50]={"primero","segundo","tercero","cuarto","quinto"};
    char fabricante[][50]={"pablo","Manu","Pablo","Catriel","pablo"};
    int matricula[]={37190429,38165428,39450429,40112423,41780499};
    int capacidad[]={18,20,15,22,21};
    int autonomia[]={10,12,11,3,8};

    int i;

    for(i=0; i<5; i++)
    {

        aviones[i].capacidad=capacidad[i];
        aviones[i].autonomia=autonomia[i];
        aviones[i].matricula=matricula[i];
        aviones[i].estado = 1;
        strcpy(aviones[i].modelo, modelo[i]);
        strcpy(aviones[i].fabricante, fabricante[i]);

    }
}

int buscarLugarLibre(Eaviones aviones[],int tan)
{
    int retorno = -1;
    int i;
    if(tan > 0 && aviones != NULL)
    {
        retorno = -2;
        for(i=0; i<tan; i++)
        {
            if(aviones[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int alta(Eaviones aviones[],int tan)
{
    int retorno = 0;
    int i;
    if(tan > 0 && aviones != NULL)
    {
        i = buscarLugarLibre(aviones,tan);
        if(i >= 0)
        {

            printf("Ingrese fabricante: \n");
            fflush(stdin);
            gets(aviones[i].fabricante);
            printf("Ingrese modelo: \n");
            fflush(stdin);
            gets(aviones[i].modelo);
            printf("Ingrese autonomia: \n");
            scanf("%d",&aviones[i].autonomia);
            printf("Ingrese capacidad: \n");
            scanf("%d",&aviones[i].capacidad);
            printf("Ingrese matricula: \n");
            scanf("%d",&aviones[i].matricula);
            aviones[i].estado = 1;
            retorno = 1;
        }
    }
    return retorno;
}

int baja(Eaviones aviones[],int tan)
{
    int i;
    int retorno = 0;
    int val;
    int matriculab;
    printf("matricula a dar de baja: ");
    scanf("%d", &matriculab);
    val = buscarPorMatricula(aviones,matriculab , tan);
    while(val == 0)
    {
        printf("no se encontro la matricula\n");
        printf("matricula a dar de baja: ");
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

int modificar(Eaviones aviones[],int tan)
{
    int i;
    int retorno = 0;
    int val;
    int matriculab;
    printf("matricula a modificar: ");
    scanf("%d", &matriculab);
    val = buscarPorMatricula(aviones,matriculab , tan);
    while(val == 0)
    {
        printf("no se encontro la matricula\n");
        printf("matricula a a modificar: ");
        scanf("%d", &matriculab);
        val = buscarPorMatricula(aviones,matriculab , tan);
    }
            printf("Ingrese modelo: \n");
            fflush(stdin);
            gets(aviones[val].modelo);
            printf("Ingrese fabricante: \n");
            fflush(stdin);
            gets(aviones[val].fabricante);
            printf("Ingrese autonomia: \n");
            scanf("%d",&aviones[val].autonomia);
            printf("Ingrese capacidad: \n");
            scanf("%d",&aviones[val].capacidad);

            retorno = 1;



    return retorno;
}


void mostrarListaAviones(Eaviones aviones[], int tan)
{
    int i;

    for(i=0; i<tan; i++)
    {
        if (aviones[i].estado==1)
        {
            printf("\n modelo : %s /fabricante : %s /estado : %d /matricula %d \n",aviones[i].modelo,aviones[i].fabricante,aviones[i].estado,aviones[i].matricula);
        }

    }
}


//////////////////////////////////VUELOS !!//////////////////////////////////////////////////////////////////////////////////////

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

int altaVuelo(Evuelos vuelos[],Eaviones aviones[],int tan)
{   int valuno;
    int retorno = 0;
    int i;
    int comparar;
    if(tan > 0 && vuelos != NULL)
    {
        i = buscarLugarLibre(vuelos,tan);
        printf("para dar de alta ingrese matricula del vuelo: ");
        scanf("%d", &valuno);
        comparar=compara(vuelos,aviones,valuno ,tan);
        while(comparar == 0)
        {
        printf("no hubo coincidencia, reingrese\n");
        scanf("%d", &valuno);
        comparar=compara(vuelos,aviones,valuno ,tan);}
        if(i >= 0 && comparar==1)
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
            vuelos[i].matricula=valuno;
            vuelos[i].estado = 1;
            retorno = 1;
        }
    }
    return retorno;
}

void mostrarListaVuelos(Evuelos vuelos[],/*Eaviones aviones[],*/int tan)
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

int compara(Evuelos vuelos[],Eaviones aviones[],int valuno,int tan)
{

    int i;


    for(i=0; i<tan; i++)
    {

            if (valuno==aviones[i].matricula)
            {
                vuelos[i].matricula=valuno;
                valuno=1;
                break;
            }
            else
            {
                valuno=0;
                break;
            }


    }

    return valuno;
}
int bajavuelos(Evuelos vuelos[],Eaviones aviones[],int tan)
{
    int retorno = 0;
    int mat;
    int val;
    int id;
    printf("matricula del vuelo: ");
    scanf("%d", &mat);
    mat=buscarPorMatricula(aviones,mat , tan);
    while(mat == 0)
    {
        printf("no se encontro el matricula. re-ingrese id\n");
        scanf("%d", &id);
        mat= buscarPorMatricula(aviones,mat , tan);
    }
    printf("ID a dar de baja: ");
    scanf("%d", &id);
    val = buscarPorid(vuelos,id , tan);
    while(val == 0)
    {
        printf("no se encontro el ID. re-ingrese id\n");
        scanf("%d", &id);
        val = buscarPorid(vuelos,id , tan);
    }
    return retorno;
}


int buscarPorid(Evuelos vuelos[],int id, int tan)
{
    int i;
    for(i=0; i<tan; i++)
        if(id==vuelos[i].id)
        {
            vuelos[i].estado = 0;
            printf("el ID se dio de baja correctamente.\n");
            return 1;
            break;
        }
        else
        {
            return 0;
            //break;
        }
}

