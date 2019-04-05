#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float a=0;
    float b=0;
    float resultado=0;
    float resultado1=0;
    float resultado2=0;
    float resultado3=0;
    float resultado4=0;
    float resultado5=0;


    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.0f)\n",a);
        printf("2- Ingresar 2do operando (B=%.0f)\n",b);
        printf("3- Calcular todas las operaciones \n");
        printf("4- Los resultados de los calculos son: \n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            a=tomarvalor();
            break;
        case 2:
            b=tomarvalor();
            break;
        case 3:
            resultado=suma(a,b);
            resultado1=resta(a,b);
            resultado2=multiplicar(a,b);
            resultado3=dividir(a,b);
            if(a>1){
            resultado4=factorial(a);
            }
            if(b>1){
            resultado5=factorial(b);
            }

            break;
        case 4:
            printf("La suma es: %.2f\n",resultado);
            printf("La resta es: %.2f\n",resultado1);
            printf("El producto es: %.2f\n",resultado2);
             if(b !=0)
            {
                printf("la divicion da: %.2f\n",resultado3);

            }
            else
            {
                printf("Error no se puede dividir por 0 \n");
            }
            if(a>1)
            {
                printf("El facorial es: %.2f \n",resultado4);
            }
            else
            {
                if(a==0 || a==1)
                {
                    printf("El factoreal es 1\n");
                }
                else
                {
                    printf("El factoreal no se puede hacer por negativos\n");
                }
            }

            if(b>1)
            {
                printf("El facorial es: %.2f \n",resultado5);
            }
            else
            {
                if(b==0 || b==1)
                {
                    printf("El factoreal es 1\n");
                }
                else
                {
                    printf("El factoreal no se puede hacer por negativos\n");
                }
            }
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }


    return 0;
}
