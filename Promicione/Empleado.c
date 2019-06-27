#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "linkedlist.h"
#include "Parser.h"

int em_calcularCantidad(void* elemento)
{
    int retorno = -1;
    Entregas* entregas;
    if(elemento != NULL)
    {
    entregas=(Entregas*)elemento;

    retorno=entregas->cantidad;
    }

    return retorno;
}
int em_calcularPeso(void* elemento)
{
    int retorno = -1;
    Entregas* entregas;
    if(elemento != NULL)
    {
    entregas=(Entregas*)elemento;

    retorno=entregas->peso;
    }

    return retorno;
}

int em_calcularEntregasPortipoSTD(void* elemento)
{
    int retorno = -1;
    Entregas* entregas;
    if(elemento != NULL)
    {
    entregas=(Entregas*)elemento;
    if(strcmp("STD",entregas->tipo) == 0 )
    {
        retorno=1;
    }
    }

    return retorno;
}

int em_calcularEntregasPortipoEXP(void* elemento)
{
    int retorno = -1;
    Entregas* entregas;
    if(elemento != NULL)
    {
    entregas=(Entregas*)elemento;
    if(strcmp("EXP",entregas->tipo) == 0 )
    {
        retorno=1;
    }
    }

    return retorno;
}

int em_calcularEntregasPortipoECO(void* elemento)
{
    int retorno = -1;
    Entregas* entregas;
    if(elemento != NULL)
    {
    entregas=(Entregas*)elemento;
    if(strcmp("ECO",entregas->tipo) == 0 )
    {
        retorno=1;
    }
    }

    return retorno;
}

Entregas* entregas_new()
{
    return (Entregas*) malloc(sizeof(Entregas));
}
Entregas* entregas_newParametros(int* id,char* tipo,int* cantidad,float* peso)
{
    Entregas* this;
    this=entregas_new();
    entregas_setId(this,*id);
    entregas_setTipo(this,tipo);
    entregas_setCantidad(this,*cantidad);
    entregas_setPeso(this,*peso);
    return this;
}
void entregas_delete(Entregas* emp)
{
    if(emp != NULL)
    {
        free(emp);
    }
}

int entregas_setId(Entregas* this,int value)
{
    int retorno=-1;
    if(this != NULL)
    {
        this->id=value;
        retorno=0;
    }
    return retorno;
}
int entregas_getId(Entregas* this,int* value)
{
     int retorno=-1;
    if(this != NULL )
    {
        *value=this->id;
        retorno=0;
    }
    return retorno;
}

int entregas_setTipo(Entregas* this,char* value)
{
     int retorno=-1;
    if(this != NULL )
    {
        strncpy(this->tipo,value,sizeof(this->tipo));
        retorno=0;
    }
    return retorno;
}
int entregas_getTipo(Entregas* this,char* value)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(value,this->tipo);
        retorno=0;
    }
    return retorno;
}

int entregas_setCantidad(Entregas* this,int value)
{
     int retorno=-1;
    if(this != NULL)
    {
        this->cantidad=value;
        retorno=0;
    }
    return retorno;
}
int entregas_getCantidad(Entregas* this,int* value)
{
    int retorno=-1;
    if(this != NULL )
    {
        *value=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int entregas_setPeso(Entregas* this,float value)
{
    int retorno=-1;
    if(this != NULL)
    {
        this->peso=value;
        retorno=0;
    }
    return retorno;
}
int entregas_getPeso(Entregas* this,float* value)
{
    int retorno=-1;
    if(this != NULL )
    {
        *value=this->peso;
        retorno=0;
    }
    return retorno;
}
