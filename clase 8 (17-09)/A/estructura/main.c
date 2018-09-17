#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*struct empleado// e de estructura

{

    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;

    (es otra forma de hacerlo)
};*/



typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;

}eEmpleado;

void mostrarEmpleado(eEmpleado employes);//prototipo siempre despues de la struc

int main()
{
    //struct empleado unEmpleado;

    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    eEmpleado emp3={2265,"jose",'m',20000.00/*si estuviera anidada seria (dia, mes ,anio)*/};
    eEmpleado emp4;
    eEmpleado emp5;

    emp4=emp3;

    unEmpleado.legajo = 1234;
    strcpy( unEmpleado.nombre, "juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 1000.5;

    otroEmpleado.legajo = 1354;
    strcpy( otroEmpleado.nombre, "marta");
    otroEmpleado.sexo = 'f';
    otroEmpleado.sueldo = 1000.5;


    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpleado);
    mostrarEmpleado(emp3);
    mostrarEmpleado(emp4);

    printf("Ingrese legajo\n");
    scanf("%d", &emp5.legajo);
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(emp5.nombre);
    printf("Ingrese sexo\n");
    fflush(stdin);
    scanf("%c", &emp5.sexo);
    printf("Ingrese sueldo\n");
    scanf("%f", &emp5.sueldo);


    mostrarEmpleado(emp5);
    return 0;
}


void mostrarEmpleado(eEmpleado employes)
{
    printf("%d  %s  %c  %.2f  \n\n",employes.legajo , employes.nombre , employes.sexo , employes.sueldo);

}
