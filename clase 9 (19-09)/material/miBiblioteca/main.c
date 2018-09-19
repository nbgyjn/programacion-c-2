#include <stdio.h>
#include <stdlib.h>
#define TAMAVIONES 20
#include "biblioteca.h"


int main()
{
    Eaviones listaDeAviones[TAMAVIONES];
    inicializarAvionesEstado(listaDeAviones,TAMAVIONES);
    inicializarAvionesHardCode(listaDeAviones);



    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar agregar avion!\n");
        printf("2- modificar datos de avion\n");
        printf("3- baja de avion\n");
        printf("4- nuevo vuelo\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(listaDeAviones,TAMAVIONES);
                break;
            case 2:
                modificar(listaDeAviones,TAMAVIONES);
                break;
            case 3:
                baja(listaDeAviones,TAMAVIONES);
                break;
            case 4:
                altaVuelo(listaDeAviones,listaDeAviones,TAMAVIONES);
                break;
            case 5:
                bajavuelos(listaDeAviones,listaDeAviones,TAMAVIONES);
                break;
            case 6:
                mostrarListaAviones(listaDeAviones,TAMAVIONES);
                mostrarListaVuelos(listaDeAviones,TAMAVIONES);
                compara(listaDeAviones,listaDeAviones,TAMAVIONES,TAMAVIONES);
                break;
        }
    }

    return 0;
}
