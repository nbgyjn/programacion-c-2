#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3


typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
   //estructura anidada, una stru dentro de otra  (tiene uqe declarase previa a la que se va a usar)

}eEmpleado;

void mostrarEmpleado(eEmpleado employes);
void mostrarEmpleads(eEmpleado lista[], int);
void ordenarEmpleados (eEmpleado lista[]), int tam);

int main()
{
    eEmpleado empleados[]={{1234,"juan",'m',12000},{6541,"marte",'f',5000}};
/*
    for (int i=0;i<TAM;i++){
    printf("Ingrese legajo\n");
    scanf("%d", &empleados[i].legajo);
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(empleados[i].nombre);
    printf("Ingrese sexo\n");
    fflush(stdin);
    scanf("%c", &empleados[i].sexo);
    printf("Ingrese sueldo\n");
    scanf("%f", &empleados[i].sueldo);
    }*/


    mostrarEmpleado(empleados);
    return 0;
}



void mostrarEmpleado(eEmpleado employes)
{
    printf("%d  %s  %c  %.2f   %02d/ %02d / %02d \n\n",employes.legajo , employes.nombre , employes.sexo , employes.sueldo,employes.fechaIngreso.dia,employes.fechaIngreso.mes,employes.fechaIngreso.anio);

}

void mostrarEmpleads(eEmpleado lista[], int tam){
system("clas");
print ("legajo   nombre  sexo  sueldo  \n\n");
    for (int i=0;i<tam;i++){

        mostrarEmpleado(lista[i]);
    }
    printf("\n\n");
}


void ordenarEmpleados (eEmpleado lista[]), int tam){

    eEmpleado auxEmpleado;

    fot (int i=0;i<tam-1;i++){
    for (int j= i+1}
}
