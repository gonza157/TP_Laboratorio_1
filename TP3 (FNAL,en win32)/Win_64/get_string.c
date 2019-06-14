#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{


    float numInput;
    do
    {
        printf("%s\n",message);
        setbuf(stdin,NULL);
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

int getInt(int* input,char* message,char* eMessage, int lowLimit, int hiLimit)
{
    int numInput;
    int retorno=0;
    do{
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
    }while(retorno !=0);
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
    }


    return retorno;

}

int pedirInt(char* enunciado,int* value)
{
    int retorno=-1;
    printf("%s",enunciado);
    scanf("%d",value);
    if(*value!=0)
    {
        retorno= 0;
    }
    return retorno;
}

