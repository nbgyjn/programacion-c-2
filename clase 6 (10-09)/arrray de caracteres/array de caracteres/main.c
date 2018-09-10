#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char nombre[8];
    char cadena2[8]=("jose");
    strcpy(nombre,cadena2);

    printf("%s",nombre);
    return 0;
}
