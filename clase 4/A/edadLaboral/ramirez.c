#include "pablo.h"


/** \brief comprueba que un valor este en un rango
 *
 * \param valor int valor a vereficar
 * \param min int minimo del rango
 * \param max int maximo del rango
 * \return int true si esta en el rango false si no
 *
 */
int edad_laboral(int edad, int min, int max)
{
    int valido = 0;
    if (edad>min && edad < max)
    {
        valido=1;
    }
    return valido;
}
