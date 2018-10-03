#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bibioteca.h"

int main()
{
    char seguir = 's';
    Employee lista[10];
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
        switch(menu())
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

            system("pause");
            break;
        case 6:

            system("pause");
            break;
        case 7:

            system("pause");
            break;
        case 8:

            system("pause");
            //agregar otro almuerzo por elmpleado
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}
