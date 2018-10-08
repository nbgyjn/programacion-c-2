#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

char getValidChar(char requestMessage[], char errorMessage[], char comparacionA, char comparacionB)
{
    char auxiliar;
    printf("%s",requestMessage);
    fflush(stdin);
    scanf("%c",&auxiliar);
    while(auxiliar!=comparacionA && auxiliar!=comparacionB){
        printf("\n%s",errorMessage);
        printf("\n%s",requestMessage);
        fflush(stdin);
        scanf("\n%c",&auxiliar);

    }
    return auxiliar;
}

char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidIntRango(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d.\n\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }
}

int getValidIntOpcion(char requestMessage[],char errorMessage[], int comparacionA, int comparacionB)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt != comparacionA && auxInt != comparacionB)
        {
            printf ("El numero ingresado debe ser %d o %d.\n\n", comparacionA, comparacionB);
            continue;
        }
        return auxInt;
    }
}

int getValidInt(char requestMessage[],char errorMessage[])
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        return auxInt;
    }
}

void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

void corregirMayusculas(char input[])
{
    int lenght;
    lenght = strlen(input);
    strlwr(input);
    input[0] = toupper(input[0]);
    for(int i=0; i<lenght; i++)
    {
        if(input[i] == ' ')
        {
            input[i+1] = toupper(input[i+1]);
        }
    }
}

int getStringLetrasRango(char mensaje[],char input[], int tamanio)
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        while(strlen(aux)>tamanio)
        {
            printf("\nError, supero la cantidad de caracteres permitidos\n\n");
            getString(mensaje,aux);
            continue;
        }
        corregirMayusculas(aux);
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getValidStringRango(char requestMessage[],char errorMessage[], char input[], int tamanio)
{
    while(1)
    {
        if (!getStringLetrasRango(requestMessage,input, tamanio))
        {
            printf ("%s\n",errorMessage);
            fflush(stdin);
            continue;
        }
        cleanStdin();
        break;
    }
}

float getValidFloat(char requestMessage[],char errorMessage[])
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        break;
    }
    auxFloat = atof(auxStr);
    return auxFloat;
}

float getValidFloatMayor0(char requestMessage[],char errorMessage[])
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr) && auxStr<0)
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        break;
    }
    auxFloat = atof(auxStr);
    return auxFloat;
}
