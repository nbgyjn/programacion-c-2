#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 200



int main()
{






    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar nombre!\n");
        printf("2- agregar apellido\n");
        printf("3- agregar edad\n");
        printf("4- agregar legajo\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                break;

            case 2:
                break;
            default:
            break;



        }

    }

    return 0;
}

int inicializar()
{

    char nombre[CANT][31],nomaux[31];
    char apellido[CANT][31],apeaux[31];
    int edad[CANT],edadaux;
    int legajo[CANT],legaux;
    int isEmpty[CANT],isEmptyaux;
    int i;
    int j;

    for (i=0;i<CANT-1;i++)
    {
        isEmpty[i]=1;
    }

    for (i=0;i<CANT-1;i++)
    {
        for(j=i++;j<CANT,j++)
        {
            if(strcpy(nombre[i],nombre[j])>0)
            {
                strcpy(nomaux,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],nomaux);
                strcpy(apeaux,apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j],apeaux);
                edadaux=edad[i];
                edad[i]=edad[j];
                edad[j]=edadaux;
                legaux=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=legaux;
                isEmptyaux=isEmpty[i];
                isEmpty[i]=isEmpty[j];
                isEmpty[j]=isEmptyaux;
            }
            //el else es para cuando tengo una persona con el mismo apellido, asi uqe lo ordeno por el nombre
            else{
                if (strcmp(apellido[i],apellido[j])==0)
                {
                    if(strcmp(nombre[i],nombre[j])>0){}
                }

                strcpy(nomaux,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],nomaux);
                edadaux=edad[i];
                edad[i]=edad[j];
                edad[j]=edadaux;
                legaux=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=legaux;
                isEmptyaux=isEmpty[i];
                isEmpty[i]=isEmpty[j];
                isEmpty[j]=isEmptyaux;
            }
        }
    }
return 0;
}
