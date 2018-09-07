#include <stdio.h>
#include <stdlib.h>
#include "pablo.h"


int main()
{
    int edad;
    int min =17;
    int max = 66;
    int val;
    printf("ingrese edad\n");
    scanf("%d",&edad);
    val=edad_laboral(edad,min,max);
    if (val == 1)
    {
        printf("usted puede trabajar\n");
    }
    else
    {
        printf("usted no puede trabajar\n");
    }
    return ;
}


