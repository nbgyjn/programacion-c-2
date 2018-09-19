#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "validaciones.h"

#define CANT 2
#define TAM_PROV 3

/** \brief Da opciones a elegir por el usuaio.
 *
 * \return opcion Opcion ingresada por el usuraio.
 *
 */
int menu()
{
    system("cls");
    int opcion;
    printf("Parcial - Alegria Nestor\n\n");
    printf("1- Agregar producto\n");
    printf("2- Modificar producto\n");
    printf("3- Borrar producto\n");
    printf("4- Informes\n");
    printf("ESC- Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);

    opcion = getch();
    return opcion;
}

/** \brief Inicializa todos los estados de las estructuras a 0.
 *
 * \param persona Estructura a crear.
 * \param CANT Cantidad de estructuras a crear.
 *
 */
void inicializarEstados(eProducto producto[], int tamanio)
{
    for(int i=0; i<tamanio; i++)
    {
        producto[i].estado = 0;
    }
}

/** \brief Obtiene el primer lugar libre.
 *
 * \param persona Estructura a crear.
 * \param CANT Cantidad de estructuras a crear.
 * \return -1 si no hay espacios libres de lo contrario indice del espacio libre.
 *
 */
int obtenerEspacioLibre(eProducto producto[], int tamanio)
{
    int indice = -1;
    for(int i=0; i<tamanio; i++)
    {
        if(producto[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Busca usuarios por codigo.
 *
 * \param producto Estructura a crear.
 * \param tamanio Cantidad de estructuras a crear.
 * \return -1 si no existe el producto de lo contrario indice de la posicion del producto.
 *
 */
int buscarPorCodigo(eProducto producto[], int tamanio, int codigo)
{
    int existe = -1;
    for(int i=0; i<tamanio; i++)
    {
        if(producto[i].estado == 1 && producto[i].codigoProducto == codigo)
        {
            existe = i;
            break;
        }
    }
    return existe;
}

/** \brief Muestra usuario.
 *
 * \param persona Estructura utilizada para buscar al usuario, se utiliza un indice para identificarlo.
 */
void mostrarProducto(eProducto producto)
{
    printf("\nCodigo\tDescripcion  \tImporte  \tCantidad\n\n");
    printf("%d\t%s\t\t%.2f  \t\t%d\n\n", producto.codigoProducto, producto.descripcion, producto.importe, producto.cantidad);
}
/*
/** \brief Da de alta a un usuario nuevo.
 *
 * \param persona Estructura a crear.
 * \param CANT Cantidad de estructuras a crear.
 *
 */


/** \brief Ordena usuarios por nombre y en segundo termino por DNI.
 *
 * \param persona Estructura a crear.
 * \param CANT Cantidad de estructuras a crear.
 *
 */
/*void ordenarUsuarios(EPersona persona[], int CANT)
{
    EPersona auxiliar;
    int i;
    int j;
    for(i=0; i<CANT-1; i++)
    {
        for(j=i+1; j<CANT; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                auxiliar = persona[i];
                persona[i] = persona[j];
                persona[j] = auxiliar;
            }
            else
            {
                if(strcmp(persona[i].nombre, persona[j].nombre) == 0)
                {
                    if(persona[i].dni > persona[j].dni)
                    {
                        auxiliar = persona[i];
                        persona[i] = persona[j];
                        persona[j] = auxiliar;
                    }
                }
            }
        }
    }
}*/

/** brief Muestra una lista ordenada utilizando ordenarProducto().
 *
 * \param persona Estructura a crear.
 * \param CANT Cantidad de estructuras a crear.
 *
 */
void mostrarListaOrdenada(eProducto producto[], int tamanio)
{
    system("cls");
    printf("<-- Lista ordenada por codigo -->\n\n");
    printf("Codigo\tDescripcion  \tImporte  \tCantidad\n\n");
    for(int i=0; i<tamanio; i++)
    {
        if(producto[i].estado == 1)
        {
            printf("%d\t%s\t\t%.2f  \t\t%d\n", producto[i].codigoProducto, producto[i].descripcion, producto[i].importe, producto[i].cantidad);
        }
    }
}

/** \brief Da de baja a un producto dado de alta en sistema.
 *
 * \param producto Estructura a crear.
 * \param tamanio Cantidad de estructuras a crear.
 *
 */
void bajaProducto(eProducto producto[], int tamanio)
{
    system("cls");
    int existeCodigo;
    char confirma;
    int codigo;
    int auxiliarRetorno;
    char auxiliar[255];

    printf("<-- Baja de producto -->\n\n");
    auxiliarRetorno = getStringNumeros("Ingrese Codigo: ", auxiliar);
    while(auxiliarRetorno != 1)
    {
        printf("\nError al ingresar codigo, verifique que introdujo un numero valido.\n\n");
        auxiliarRetorno = getStringNumeros("Ingrese codigo: ", auxiliar);
    }
    codigo = atoi(auxiliar);
    existeCodigo = buscarPorCodigo(producto, tamanio, codigo);
    if(existeCodigo == -1)
    {
        printf("\nEl codigo %d no pertenece a un producto en sistema.\n", codigo);
    }
    else
    {
        printf("\nEl producto ingresado se encuentra dado de alta en sistema.\n");
        mostrarProducto(producto[existeCodigo]);
        printf("¿Desea confirmar la baja del producto? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            printf("\nEl producto %s con codigo %d fue borrado con exito.\n", producto[existeCodigo].descripcion, producto[existeCodigo].codigoProducto);
            producto[existeCodigo].estado = 0;
        }
        else
        {
            printf("\nSe ha cancelado la baja del producto.\n");
        }
    }
}

/** \brief Modifica producto
 *
 * \param persona Estructura a crear.
 * \param CANT Cantidad de estructuras a crear.
 *
 */
void modificarProducto(eProducto producto[], int tamanio)
{
    system("cls");
    int opcion;
    int existeCodigo;
    char confirma;
    int codigo;
    int auxiliarRetorno;
    char auxiliar[255];
    float importe;
    int cantidad;

    printf("<-- Modificar producto -->\n\n");
    printf("1- Descripcion\n2- Importe\n3- Cantidad");
    printf("\n\nIngrese la opcion que desee modificar: ");
    opcion = getch();
    switch(opcion)
    {
    case '1':
        system("cls");
        printf("<-- Modificar descripcion -->\n\n");
        auxiliarRetorno = getStringNumeros("Ingrese Codigo: ", auxiliar);
        while(auxiliarRetorno != 1)
        {
            printf("\nError al ingresar codigo, verifique que introdujo un numero valido.\n\n");
            auxiliarRetorno = getStringNumeros("Ingrese codigo: ", auxiliar);
        }
        codigo = atoi(auxiliar);
        existeCodigo = buscarPorCodigo(producto, tamanio, codigo);
        if(existeCodigo == -1)
        {
            printf("\nEl codigo %d no pertenece a un producto en sistema.\n", codigo);
        }
        else
        {
            printf("\nEl codigo ingresado se encuentra dado de alta en sistema.\n");
            mostrarProducto(producto[existeCodigo]);
            auxiliarRetorno = getStringLetras("Ingrese descripcion: ", auxiliar);
            while(auxiliarRetorno != 1) //Valida que sean solo letras y hasta 50 caracteres
            {
                printf("\nError al ingresar descripcion, verifique que solo ingreso letras y que no sobre pasa los 50 caracteres.\n\n");
                auxiliarRetorno = getStringLetras("Ingrese descripcion: ", auxiliar);
            }
            printf("¿Desea confirmar la modificacion de la descripcion? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                strcpy(producto[existeCodigo].descripcion, auxiliar);
                printf("\nLa descripcion fue modificada con exito.\n");
            }
            else
            {
                printf("\nSe ha cancelado la modificacion del producto.\n");
            }
        }
        break;
    case '2':
        system("cls");
        printf("<-- Modificar importe -->\n\n");
        auxiliarRetorno = getStringNumeros("Ingrese Codigo: ", auxiliar);
        while(auxiliarRetorno != 1)
        {
            printf("\nError al ingresar codigo, verifique que introdujo un numero valido.\n\n");
            auxiliarRetorno = getStringNumeros("Ingrese codigo: ", auxiliar);
        }
        codigo = atoi(auxiliar);
        existeCodigo = buscarPorCodigo(producto, tamanio, codigo);
        if(existeCodigo == -1)
        {
            printf("\nEl codigo %d no pertenece a un producto en sistema.\n", codigo);
        }
        else
        {
            printf("\nEl codigo ingresado se encuentra dado de alta en sistema.\n");
            mostrarProducto(producto[existeCodigo]);
            auxiliarRetorno = getStringNumeros("Ingrese importe: ", auxiliar);
            while(auxiliarRetorno != 1) //Valida que sean solo letras y hasta 50 caracteres
            {
                printf("\nError al ingresar importe, verifique que solo ingreso numeros.\n\n");
                auxiliarRetorno = getStringNumeros("Ingrese importe: ", auxiliar);
            }
            importe = atof(auxiliar);
            printf("¿Desea confirmar la modificacion de el importe? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                producto[existeCodigo].importe = importe;
                printf("\El importe fue modificada con exito.\n");
            }
            else
            {
                printf("\nSe ha cancelado la modificacion del producto.\n");
            }
        }
    case '3':
        system("cls");
        printf("<-- Modificar cantidad -->\n\n");
        auxiliarRetorno = getStringNumeros("Ingrese Codigo: ", auxiliar);
        while(auxiliarRetorno != 1)
        {
            printf("\nError al ingresar codigo, verifique que introdujo un numero valido.\n\n");
            auxiliarRetorno = getStringNumeros("Ingrese codigo: ", auxiliar);
        }
        codigo = atoi(auxiliar);
        existeCodigo = buscarPorCodigo(producto, tamanio, codigo);
        if(existeCodigo == -1)
        {
            printf("\nEl codigo %d no pertenece a un producto en sistema.\n", codigo);
        }
        else
        {
            printf("\nEl codigo ingresado se encuentra dado de alta en sistema.\n");
            mostrarProducto(producto[existeCodigo]);
            auxiliarRetorno = getStringNumeros("Ingrese cantidad: ", auxiliar);
            while(auxiliarRetorno != 1) //Valida que sean solo letras y hasta 50 caracteres
            {
                printf("\nError al ingresar la cantidad, verifique que solo ingreso numeros.\n\n");
                auxiliarRetorno = getStringNumeros("Ingrese cantidad: ", auxiliar);
            }
            cantidad = atoi(auxiliar);
            printf("¿Desea confirmar la modificacion de la cantidad? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                producto[existeCodigo].cantidad = cantidad;
                printf("\El cantidad fue modificada con exito.\n");
            }
            else
            {
                printf("\nSe ha cancelado la modificacion del producto.\n");
            }
        }

    }
}


/** \brief Muestra los proveedores
 *
 * \param proveedor Estructura proveedor
 * \param tamanioProveedor cantidad de estructiras
 * \return el proveedor elejido
 *
 */
int mostrarProveedores(eProveedor proveedor[],int tamanioProveedor){
    int opcion;
    printf("\nProveedores.\n");
    for(int i=0;i<tamanioProveedor;i++){
        printf("\n%d- %s", proveedor[i].id,proveedor[i].descripcion);
    }
    printf("\n\nElija un proveedor: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
