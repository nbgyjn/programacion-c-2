#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "tools.h"
#include "ArrayList.h"


int main()
{
    ArrayList* listadoCompleto = al_newArrayList();
    ArrayList* listadoRepetidos = al_newArrayList();
    ArrayList* listadoSinRepetidos = al_newArrayList();
    if(listadoCompleto != NULL)
    {
        lecturaDeDatos(listadoCompleto);
    }
    criterioRepetidos(listadoCompleto, listadoRepetidos, listadoSinRepetidos);
    int opcion;
    int auxiliar;

    do
    {
        opcion = menuSwitch("1-Listado Completo\n2-Listar repetidos con todas sus ocurrencias (descendente) .\n3-Listar no repetidos (ascendente).\n4-Generar Archivos de salida\n5-Salir.\n\n", 1, 5);
        switch(opcion)
        {
        case 1:
            printf("IN NUM NOMBRE                P IM PR\n");
            mostrarLista(listadoCompleto, "");
            //printf("%d\n", al_len(listadoCompleto));
            //mensajeRetorno(auxiliar, "", "", "");
            break;
        case 2:
            printf("IN NUM NOMBRE                P IM PR\n");
            al_sort(listadoRepetidos, compararEntero, 0);

            mostrarLista(listadoRepetidos, "");
            //mensajeRetorno(auxiliar, "", "", "");
            break;
        case 3:
            printf("IN NUM NOMBRE                P IM PR\n");
            al_sort(listadoSinRepetidos, compararEntero, 1);

            mostrarLista(listadoSinRepetidos, "");
            //mensajeRetorno(auxiliar, "", "", "");
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }
    while(opcion != 5);
    return 0;
}
