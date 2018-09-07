#include <stdio.h>
#include <stdlib.h>

void muestra(int x,int y);
void main(void)
{
int x,y;
printf("Ingrese un numero entero");
scanf("%d",&x);
printf("Ingrese un numero entero");
scanf("%d",&y);
muestra(&x,y);
printf("\n-----valores dentro de main----");
printf("\nx vale %d \ny vale %d",x,y);
}
void muestra(int *x,int y)//el asterisco antes me da la direccion de memoria
{
*x=y;
printf("\n-----valores dentro de la funcion----");
printf("\nx vale %d \ny vale %d",x,y);
}

