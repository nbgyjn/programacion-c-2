#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero;
    char seguir;
    int suma;
    int aux=0;
    int cont=0;
    float promedio;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);

        suma=aux+numero;
        cont++;

        printf("desea continuar ?? (s-n): ");
        seguir=getch();



    }
    while (seguir != "n");
    promedio=(float)suma/cont;
    printf("la suma de todos los numeros es : %i ",suma);
    printf("el promedio es : %f ",promedio);
    return 0;
}
/*//ejercicio 3
int main()
{
    int num1;
    int num2;
    int producto;
    int cuadrado;


    printf("Ingrese un numero distinto de 0: ");
    scanf("%d",&num1);

    printf("Ingrese otro numero distinto de 0: ");
    scanf("%d",&num2);

        while (num1==0 || num2==0)
        {
            if (num1==0)
            {
            printf(" el valor 1 tiene que ser distinto que 0: ");
            scanf("%d",&num1);
            }
            else
            {
            printf(" el valor 2 tiene que ser distinto que 0: ");
            scanf("%d",&num2);

            }
        }




    producto=num1*num2;
    cuadrado=num1*num1;

    printf("El producto es: %i\n",producto);
    printf("El cuadrado es: %i\n",cuadrado);


    return 0;
}*/


/*
int promedio ()

    {


    int maximo;
    int minimo;
    int acumulador;
    int numero;
    int i;

    // Solicito el primer número el cual por ser el primero sera tanto el
    // maximo como el minimo y el primer numero a ser acumulado
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    maximo = numero;
    minimo = numero;
    acumulador = numero;

    // Solicito el resto de los numeros
    for(i=0;i<4;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        acumulador = acumulador + numero;

        if(numero > maximo)
        {
            maximo = numero;
        }

        if(numero < minimo)
        {
            minimo = numero;
        }
    }

    printf("El maximo es: %i\n",maximo);
    printf("El minimo es: %i\n",minimo);
    printf("El promedio es: %.2f\n", ((float)acumulador) / 5);
    return 0;

}*/


