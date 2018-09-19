#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
} eProveedor;

typedef struct
{
    char descripcion[50];
    int codigoProducto;
    float importe;
    int cantidad;
    int estado;
    int idProveedor;
} eProducto;

int menu();
void inicializarEstados(eProducto producto[], int tamanio);
int obtenerEspacioLibre(eProducto producto[], int tamanio);
int buscarPorDni(eProducto producto[], int CANT, int tamanio);
void mostrarUsuario(eProducto producto);
void ordenarUsuarios(eProducto producto[], int tamanio);
void mostrarListaOrdenada(eProducto producto[], int tamanio);
//void altaProducto(eProducto producto[], int tamanio);
void bajaProducto(eProducto producto[], int tamanio);
void modificarProducto(eProducto producto[], int tamanio);
int mostrarProveedores(eProveedor proveedor[],int tamanioProveedor);

#endif // FUNCIONES_H_INCLUDED
