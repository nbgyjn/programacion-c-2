#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
int ret;
int num;
while(reintentos>0)
{
printf(mensaje);
scanf("%d",&num);
if(num<=maximo && num>=minimo)
break;
reintentos--;
printf(mensajeError);
}
if(reintentos==0)
{
ret=-1;
}
else
{
ret=0;
*pResultado = num;
}
return ret;
}






int main()
{
    int codigo,estado;
    estado=utn_getNumero(&codigo,"ingrese codigo","eror, codigo incorrecto",1,1000,3);3


    printf("%d",codigo);
    return 0;
}
///revisar el archivo de la clase 4, hacer los input!!
