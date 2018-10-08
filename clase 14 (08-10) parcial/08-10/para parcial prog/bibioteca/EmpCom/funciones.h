#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}EFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    EFecha ingreso;
    int idSector;
    int isEmpty;
} eEmpleado;



typedef struct
{
    int id;
    char descripcion[52];
    int precio;
    int isEmpty;
} eAlmuerzo;




typedef struct
{
    int id;
    char descripcion[20];
} eSector;






void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);;
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void harcodearEmpleados(eEmpleado x[]);
int menu2();
int menu1();


////////////almuerzo///////////////

void inicializarAlmuerzo( eAlmuerzo x[], int tam);
int buscarLibreAlmuerzo( eAlmuerzo x[], int tam);
int buscarAlmuerzo(eAlmuerzo x[], int tam, int id);
void mostrarAlmuerzo(eAlmuerzo x[], int tan);
int alta(eAlmuerzo almuerzo[],int tan)





#endif // FUNCIONES_H_INCLUDED
