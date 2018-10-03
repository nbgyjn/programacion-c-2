#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bibioteca.h"

int menu()
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
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados( Employee x[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}


int buscarLibre( Employee x[], int tam)
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

int buscarEmpleado(Employee x[], int tam, int id)
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

int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    printf("\nSectores\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void agregarEmpleado(Employee empleados[], int tam, eSector sectores[], int tamSector)
{
    Employee nuevoEmpleado;
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
            nuevoEmpleado.id = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.name);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.lastName);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.salary);

            nuevoEmpleado.sector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}

void eliminarEmpleado(Employee empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char borrar;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            empleados[indice].isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(Employee empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        switch()
        {

        case 1:


            break;

        }

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            empleados[indice].sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
    }

}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{

    for(int i=0; i < tamSector; i++)
    {
        if( sectores[i].id == idSector)
        {

            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }


}


void mostrarEmpleado(Employee emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.sector, descripcion);

    printf("%d %s %s %.2f %s \n\n", emp.id, emp.name, emp.lastName, emp.salary, descripcion);

}

void harcodearEmpleados(Employee x[])
{

    Employee y[]=
    {
        {1111, "ana", "ramriez", 15000, 5, 1},
        {3333, "luis", "gil", 25000, 4, 1},
        {4444, "alberto", "gil", 10000, 5, 1},
        {5555, "julia", "flores", 30000, 1, 1},
        {2222, "julieta", "ramriez", 23000, 2, 1},
        {5555, "andrea", "flores", 31000, 5, 1},
        {3232, "mauro", "ramriez", 27000, 5, 1},
    };

    for(int i=0; i<7; i++)
    {
        x[i] = y[i];
    }

}


void mostrarEmpleados(Employee nomina[], int tam, eSector sectores[], int tamSector)
{
    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}
