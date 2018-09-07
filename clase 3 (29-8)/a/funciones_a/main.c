#include <stdio.h>
#include <stdlib.h>

int suma (int,int);//prototipo, va siempre arrriba para que ya lo tenga llamado

int main()
{
    int num1,num2,resultado;
    printf("ingrese un numero :");
    scanf("%d",&num1);
    printf("ingrese otro numero :");
    scanf("%d",&num2);
    resultado=suma(num1,num2);
    system("cls");//te borra de la pantalla lo que tenias antes
    printf("resultado de la suma es %d",resultado);


    return 0;
}

int suma(int num1,int num2)
{
    int resultado;
    resultado=num1+num2;
    return resultado;
}
