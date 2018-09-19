#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}EFecha;

typedef struct {
    char apellido[31];
    char nombre[31];
    long int dni;
    EFecha feNac;
    int estado;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int len);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], long int dni);

void mostrarListaPersonas(EPersona[], int tan);

int alta(EPersona[], int);
int baja(EPersona[], int);
int buscarPorMatricula(Eaviones[],int, int);
int modificar(Eaviones[],int);
#endif // PERSONA_H_INCLUDED
