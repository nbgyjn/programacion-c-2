#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"




int main()
{
    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    inicializarEmpleados(lista, 10);
    harcodearEmpleados(lista);

    do
    {
        switch(menu1())
        {

        case 1:

            switch(menu2())
            {

            case 1:
                agregarEmpleado(lista, 10, sectores, 5);
                system("pause");
                break;
            case 2:
                eliminarEmpleado(lista, 10, sectores, 5);
                break;
            case 3:
                modificarEmpleado(lista, 10, sectores, 5);
                break;
            case 4:
                mostrarEmpleados(lista, 10, sectores, 5);
                system("pause");
                break;
            case 5:
                listarEmpleadosXSector(lista, 10, sectores, 5);
                system("pause");
                break;
            case 6:
                ordenarXSectorYNombre(lista, 10, sectores, 5);
                system("pause");
                break;
            case 7:
                mostrarEmpleadosMasGanadores(lista, 10, sectores, 5);
                system("pause");
                break;
            case 8:
                mostrarAlmuerzos();
                system("pause");
                //agregar otro almuerzo por elmpleado
                break;
            case 10:
                seguir = 'n';
                break;
                    }
            break;
        case 2:

            break;
        case 3:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

