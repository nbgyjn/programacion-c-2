#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//Retorna valor ingresado - mensaje por parametro

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

//Validacion de datos - string como parametro

int esNumerico(char str[]);
int AlfaNumerico(char str[]);
int esSoloLetras(char str[]);

//Valida string(letras y numeros)

void getString(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);
int getStringNumeros(char mensaje[], char input[], int minimo, int maximo);

#endif // FUNCIONES_H_INCLUDED

