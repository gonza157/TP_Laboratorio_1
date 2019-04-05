#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include "funciones.h"

/** \brief solicita un numero y lo retorna
 * \return numero ingresado por el usuario
 *
 */

float tomarvalor()//comienza funcion tomarvalor
{
    float retorno;
    printf("ingrese valor: \n");
    scanf("%f",&retorno);
    return retorno;
}//fin funcion tomarvalor

/** \brief Calcula la suma de dos numero
 * \param numero1 primer operando
 * \param numero2 segundo operando
 * \return resultado de la suma
 *
 */

float suma(float numero1,float numero2) //comienza funcion suma
{
    float res;
    res=numero1+numero2;
    return res;
}//fin suma

/** \brief Calcula la resta de dos numero
 * \param numero1 primer operando
 * \param numero2 segundo operando
 * \return resultado de la resta
 *
 */

float resta(float numero1, float numero2)//comienza funcion resta
{
    float retorno;
    retorno=numero1-numero2;
    return retorno;
}//fin resta


/** \brief Caulcula la divicion entre dos numero
 * \param numero1 primer operando
 * \param numero2 segundo operando
 * \return resultado de la divicion
 *
 */
float dividir(float numero1, float numero2)//comienza funcion dividir
{
    if(numero2 !=0)
    {
        float retorno;
        retorno=numero1/numero2;
        return retorno;
    }else
        {
            printf("Error no se puede dividir por 0");
            return 0;
        }

}//fin dividir

/** \brief Calcula la multiplicacion de dos numeros
 * \param numero1 primer operando
 * \param numero2 segundo operando
 * \return resultado de la multiplicacion
 *
 */



float multiplicar(float numero1, float numero2)//comienza funcion multiplicar
{
    float retorno;
    retorno=numero1*numero2;
    return retorno;
}//fin multiplicar

/** \brief Calcula el factorial de un numero
 * \param numero1 primer operando
 * \return resultado del factoreo del numero
 *
 */


float factorial (int numero1)//funcion factorial del primer operando
{
    float i,retorno=1;
    for(i=numero1;i>0;i--){

            retorno=retorno*i;
    }
    return retorno;
}//fin factoreal del primer operando


#endif // FUNCIONES_H_INCLUDED

