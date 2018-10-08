#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int menu1()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Empleados\n");
    printf("2- Comidas\n");
    printf("3- salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;
}


//////////////////////////////////////////////////EMPLEADOS///////////////////////////////////////////////////////////////////

int menu2()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- Ordenar empleados por sector y dentro del sector por nombre\n");
    printf("7- Mostrar los datos de o los empleados que mas ganan por sector\n");
    printf("8- Mostrar almuerzo\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



void inicializarEmpleados( eEmpleado x[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d %s %c %.2f %s \n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}



void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta], sectores, tamSector);
        }
        else
        {
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}
/////////////////////////////////////////////////ALMUERZO////////////////////////////////////////////////////////////////

void inicializarAlmuerzo( eAlmuerzo x[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibreAlmuerzo( eAlmuerzo x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarAlmuerzo(eAlmuerzo x[], int tam, int id)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {


        if( x[i].id == id && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarAlmuerzo(eAlmuerzo x[], int tan)
{
    int i;

    for(i=0; i<tan; i++)
    {
        if (x[i].isEmpty==1)
        {
            printf("\n descripcion : %s /estado : %d /precio %d \n",x[i].descripcion,x[i].isEmpty,x[i].precio);
        }

    }
}



/*void agregarAlmuerzo(eAlmuerzo almuerzo[], int tam, eSector sectores[], int tamSector)
{
    eAlmuerzo nuevoalmuerzo;
    int indice;
    int esta;
    int id;

    indice = buscarLibre(almuerzo, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarEmpleado(almuerzo, tam, id);

        if(esta != -1)
        {
            printf("Existe una comida con esa id %d\n", id);
            nuevoalmuerzo( almuerzo[esta], sectores, tamSector);
        }
        else
        {
           nuevoalmuerzo.id = id;

            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets( nuevoalmuerzo.descripcion);


            printf("Ingrese precio: ");
            fflush(stdin);
            scanf("%f", &nuevoalmuerzo.precio);


             nuevoalmuerzo.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}*/

int alta(eAlmuerzo almuerzo[],int tan)
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
