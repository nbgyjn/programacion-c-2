
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char fabricante[50];
    char modelo[50];
    int capacidad;
    int autonomia;
    int estado;
    int matricula;

}Eaviones;




void inicializarAvionesEstado(Eaviones[], int);
void inicializarAvionesHardCode(Eaviones[]);
int buscarLugarLibre(Eaviones[],int);
int alta(Eaviones[], int);
int baja(Eaviones[], int);
int buscarPorMatricula(Eaviones[],int, int);
int modificar(Eaviones[],int);
void mostrarListaAviones(Eaviones[], int);


/////////////////////////////////////////////////////////////////

typedef struct {

    char origen[50];
    char llegada[50];
    int horario;
    int matricula;
    int estado;
    int id;

}Evuelos;

void inicializarVuelosEstado(Evuelos[], int);
void inicializarVuelosHardCode(Evuelos[]);
int buscarLugarLibreVuelo(Evuelos[],int);
int altaVuelo(Evuelos[],Eaviones[] , int);
void mostrarListaVuelos(Evuelos[],/*Eaviones[] ,*/int);
int compara(Evuelos[],Eaviones[],int ,int);
int buscarPorid(Evuelos[],int, int);
int bajavuelos(Evuelos[],Eaviones[],int);



#endif // FUNCIONES_H_INCLUDED
