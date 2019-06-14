#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "get_string.h"
#include <string.h>

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(int* id,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;
    this=employee_new();
    employee_setId(this,*id);
    employee_setNombre(this,nombreStr);
    employee_setHorasTrabajadas(this,horasTrabajadasStr);
    employee_setSueldo(this,sueldoStr);
    return this;
}
void employee_delete(Employee* emp)
{
    if(emp != NULL)
    {
        free(emp);
    }
}

int employee_setId(Employee* this,int value)
{
    int retorno=-1;
    if(this != NULL)
    {
        this->id=value;
        retorno=0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* value)
{
     int retorno=-1;
    if(this != NULL )
    {
        *value=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* value)
{
     int retorno=-1;
    if(this != NULL )
    {
        strncpy(this->nombre,value,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* value)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(value,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* value)
{
     int retorno=-1;
    if(this != NULL )
    {
         strncpy(this->horasTrabajadas,value,sizeof(this->horasTrabajadas));
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,char* value)
{
    int retorno=-1;
    if(this != NULL )
    {
        strcpy(value,this->horasTrabajadas);
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,char* value)
{
    int retorno=-1;
    if(this != NULL )
    {
        strncpy(this->sueldo,value,sizeof(this->sueldo));
        retorno=0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,char* value)
{
    int retorno=-1;
    if(this != NULL )
    {
        strcpy(value,this->sueldo);
        retorno=0;
    }
    return retorno;
}


int employee_OrdenaEnteroID(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(empleadoA->id >= empleadoB->id)
    {
        retorno =1 ;
    }
    if(empleadoA->id < empleadoB->id){
        retorno = -1;
    }

return retorno;
}
int employee_OrdenaEnteroHoras(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(strcmp(empleadoA->horasTrabajadas, empleadoB->horasTrabajadas)<0)
    {
        retorno =1 ;
    }
    if(strcmp(empleadoA->horasTrabajadas, empleadoB->horasTrabajadas)>0){
        retorno = -1;
    }

return retorno;
}
int employee_OrdenaEnteroSueldo(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(strcmp(empleadoA->sueldo, empleadoB->sueldo)<0)
    {
        retorno =1 ;
    }
    if(strcmp(empleadoA->sueldo, empleadoB->sueldo)>0){
        retorno = -1;
    }

return retorno;
}
int employee_OrdenaCadenaNombre(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;



    if(strcmp(empleadoA->nombre, empleadoB->nombre)<0)
    {
        retorno =1 ;
    }
    if(strcmp(empleadoA->nombre, empleadoB->nombre)>0){
        retorno = -1;
    }

return retorno;
}
