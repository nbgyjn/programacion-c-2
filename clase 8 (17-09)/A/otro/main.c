#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;//estructura anidada, una stru dentro de otra  (tiene uqe declarase previa a la que se va a usar)

}eEmpleado;

void mostrarEmpleado(eEmpleado employes);

int main()
{
    eEmpleado unEmpleado;
    eEmpleado hard={2265,"jose",'m',20000.00,(17,09,2018)};

    unEmpleado.legajo = 1234;
    strcpy( unEmpleado.nombre, "juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 1000.5;
    unEmpleado.fechaIngreso.dia = 17;
    unEmpleado.fechaIngreso.mes = 9;
    unEmpleado.fechaIngreso.anio = 18;


    mostrarEmpleado(unEmpleado);

    return 0;
}



void mostrarEmpleado(eEmpleado employes)
{
    printf("%d  %s  %c  %.2f   %02d/ %02d / %02d \n\n",employes.legajo , employes.nombre , employes.sexo , employes.sueldo,employes.fechaIngreso.dia,employes.fechaIngreso.mes,employes.fechaIngreso.anio);

}
