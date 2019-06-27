#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{


    float numInput;
    do
    {
        printf("%s\n",message);
        //__fpurge(stdin);
        fflush(stdin);
    }
    while(!scanf("%f",&numInput));

    if( (numInput<lowLimit) ||  (numInput>hiLimit) )
    {
        printf("%s\n",eMessage);
        return -1;
    }
    else
    {
        *input = numInput;
        return 0;
    }
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int numInput;
    int retorno=0;

        do
        {
            printf("%s\n",message);
            setbuf(stdin,NULL);
        }
        while(!scanf("%d",&numInput));

        if( (numInput<lowLimit) ||  (numInput>hiLimit) )
        {
            printf("%s\n",eMessage);
            retorno= -1;
        }
    *input = numInput;
    return retorno;

}

/*int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = 0;
    printf("%s", message);
    setbuf(stdin, NULL);
    gets(input);
    int largo;
    largo=strlen(input);

    if (largo >= hiLimit || largo < lowLimit )
    {
        printf("%s",eMessage);
        retorno = -1;
    }
    return retorno;

}*/

void MuestraMenu(char texto[])
{
    printf("%s",texto);
}

int getString(  char *cadena,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno=-1,i=0,flag;
    char bufferStr[4096];
    int Largo=0;
    if(cadena !=NULL)
    {
        do
        {
            printf("%s",msg);
            scanf("%s",bufferStr);
            Largo=strlen(bufferStr);
            //strncpy(cadena,bufferStr,maximo);
            //if(Largo>=minimo && Largo<=maximo)
            for(; bufferStr[i]!='\0'; i++)
            {
                if(bufferStr[i]< '0' || bufferStr[i]>'9')
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }

            }
            if(flag==1 && Largo>=minimo && Largo<=maximo)
            {
                strncpy(cadena,bufferStr,maximo);
                break;
            }
            else
            {
                printf("%s",msgError);
            }
            reintentos--;
        }
        while(reintentos!=0 || flag==1);
        retorno=0;
    }


    return retorno;

}

int getStringNumeros(  char *cadena,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno=-1,i=0,flag;
    char bufferStr[4096];
    int Largo=0;
    if(cadena !=NULL)
    {
        do
        {
            printf("%s",msg);
            scanf("%s",bufferStr);
            Largo=strlen(bufferStr);
            //strncpy(cadena,bufferStr,maximo);
            //if(Largo>=minimo && Largo<=maximo)
            for(; bufferStr[i]!='\0'; i++)
            {
                if(bufferStr[i]> '0' && bufferStr[i]<'9')
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }

            }
            if(flag==1 && Largo>=minimo && Largo<=maximo)
            {
                strncpy(cadena,bufferStr,maximo);
                break;
            }
            else
            {
                printf("%s",msgError);
            }
            reintentos--;
        }
        while(reintentos!=0 || flag==1);
        retorno=0;
    }


    return retorno;

}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiBiblioteca.h"

int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno=-1;
    char bufferStr[4096];
    int Largo=0;
    if(pResultado !=NULL )
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            Largo=strlen(bufferStr);
            if(Largo>=minimo && Largo<=maximo)
            {
                strncpy(pResultado,bufferStr,maximo);
                retorno=0;
                break;

            }else{
                    printf("%s",msgError);
            }
            reintentos--;
        }while(reintentos!=0);
    }


    return retorno;

}*/

/*{
    char bufferStr[4096];

    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';


    return 0;

}*/


/*int isValidIntNumber (char* cadena)
{
    int retorno=1;
    int i=0;
    if(cadena[i] == '-')
    {
        i++;
    }
    for(;cadena[i]!='\0';i++)
    {
        if(cadena[i]< '0' || cadena[i]>'9')
        {
            retorno=0;
            break;
        }

    }

    return retorno;

}*/


/*int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( resultado != NULL &&
        reintentos >= 0) //FALTAN
    {
        if(!getString(bufferStr,msg,msgError,1,6,1) &&
            isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *resultado = bufferInt;
            }
        }
    }
    return retorno;
}*/



