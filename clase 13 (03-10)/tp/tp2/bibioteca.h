#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;




/** \brief inicializa los estados de los empleados
 *
 * \param Employee[] nombre de la estructura
 * \param tam int taminio
 * \return void
 *
 */
void inicializarEmpleados( Employee[], int tam);
int buscarLibre( Employee[], int tam);
int buscarEmpleado(Employee[], int tam, int id);
int elegirSector(eSector sectores[], int tam);
void agregarEmpleado(Employee empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(Employee empleados[], int tam, eSector sectores[], int tamSector);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void mostrarEmpleado(Employee emp, eSector sectores[], int tamSector);
void mostrarEmpleados(Employee nomina[], int tam, eSector sectores[], int tamSector);
void harcodearEmpleados(Employee x[]);



int menu();








#endif // FUNCIONES_H_INCLUDED
