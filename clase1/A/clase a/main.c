#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro1,nro2,nro3,mayor,menor;

    printf("ingrese nro1 : \n");
    scanf("%d",&nro1);
    printf("ingrese nro2 : \n");
    scanf("%d",&nro2);
    printf("ingrese nro3 : \n");
    scanf("%d",&nro3);

    mayor=nro1;
    menor=nro1;

    if (nro2>mayor)
    {
        mayor=nro2;
    }
    if (nro3>mayor)
    {
        mayor=nro3;
    }
    if (nro2<menor)
    {
        menor=nro2;
    }
    if (nro3<menor)
    {
        menor=nro3;
    }

    printf("es numero mayor es : %d \n",mayor);
    printf("es numero menor es: %d",menor);

    return 0;
}

