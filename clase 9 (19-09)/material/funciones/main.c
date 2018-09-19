#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#define CANT 2
#define TAM_PROV 3
#define ESC 27

int altaProducto(eProducto producto[], int tamanio, int codigoProducto);
int contadorIncremental(eProducto producto[], int tamanio);

int main()
{
    eProducto producto[CANT];
    eProveedor proveedor[]= {{1,"Proveedor 1"},{2,"Proveedor 2"},{3,"Proveedor 3"}};
    char seguir='s';
    int codigoProducto = 0;

    inicializarEstados(producto, CANT);

    while(seguir=='s')
    {
        switch(menu())
        {
        case '1':
            system("cls");
            int lugarLibre;
            int auxiliarRetornos;
            char auxiliar[255];
            float importe;
            int cantidad;


            printf("<-- Alta de Producto -->\n\n");
            lugarLibre = obtenerEspacioLibre(producto, CANT);
            if(lugarLibre == -1)
            {
                printf("No queda espacio para agregar nuevo producto.\n\n");
            }
            else
            {
                codigoProducto++;
                producto[lugarLibre].estado = 1;//cambio el estado a ocupado
                producto[lugarLibre].codigoProducto = codigoProducto;
                //Descripcion -->
                auxiliarRetornos = getStringLetras("Ingrese descripcion: ", auxiliar);
                while(auxiliarRetornos != 1) //Valida que sean solo letras y hasta 50 caracteres
                {
                    printf("\nError al ingresar descripcion, verifique que solo ingreso letras y que no sobre pasa los 50 caracteres.\n\n");
                    auxiliarRetornos = getStringLetras("Ingrese descripcion: ", auxiliar);
                }
                strcpy(producto[lugarLibre].descripcion, auxiliar);
                //<-- Descripcion
                //Importe -->
                auxiliarRetornos = getStringNumeros("Ingrese importe: ", auxiliar);
                while(auxiliarRetornos != 1)
                {
                    printf("\nError al ingresar importe, solo se aceptan numeros.\n\n");
                    auxiliarRetornos = getStringNumeros("Ingrese imporet: ", auxiliar);
                }
                importe = atoi(auxiliar);
                producto[lugarLibre].importe = importe;
                //<-- Importe
                //Cantidad -->
                auxiliarRetornos = getStringNumeros("Ingrese cantidad: ", auxiliar);
                while(auxiliarRetornos != 1)
                {
                    printf("\nError al ingresar cantidad, solo se aceptan numeros.\n\n");
                    auxiliarRetornos = getStringNumeros("Ingrese cantidad: ", auxiliar);
                }
                cantidad = atoi(auxiliar);
                producto[lugarLibre].cantidad = cantidad;
                //<-- Cantidad
                producto[lugarLibre].idProveedor = mostrarProveedores(proveedor, TAM_PROV);


                printf("\nDescripcion: %s\n", producto[lugarLibre].descripcion);
                printf("Codigo: %d\n", producto[lugarLibre].codigoProducto);
                printf("Importe: %.2f\n", producto[lugarLibre].importe);
                printf("Cantidad: %d\n", producto[lugarLibre].cantidad);
                for(int i=0; i<TAM_PROV; i++)
                {
                    if(producto[lugarLibre].idProveedor == proveedor[i].id)
                    {
                        printf("Proveedor: %s. \n",proveedor[i].descripcion);
                        break;
                    }

                }
            }

            system("pause");
            break;
        case '2':
            modificarProducto(producto, CANT);
            system("pause");
            break;
        case '3':
            bajaProducto(producto, CANT);
            system("pause");
            break;
        case '4':
            mostrarListaOrdenada(producto, CANT);
            system("pause");
            break;
        }
    }
}

int contadorIncremental(eProducto producto[], int tamanio){
    int i;
    for(i=0; i<tamanio; i++){

    }
}
