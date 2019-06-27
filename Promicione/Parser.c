#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "linkedlist.h"
#include "Parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int id=0;
    char tipo[128];
    int cantidad=0;
    float peso=0;
    int control=0;
    int retorno=-1;
    Entregas* emp;

    if(pFile != NULL)
    {
        ///,%[^\n]
        control=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",tipo,tipo,tipo,tipo);//esta es la lectura fantasma no tien importancia reiterar la variable
        do
        {
            control=fscanf(pFile,"%d,%[^,],%d,%f\n",&id,tipo,&cantidad,&peso);
            printf("%d\n",control);
            if(control==4)
            {
                //printf("%s,%s,%s,%s\n",id,nombre,horas,sueldo);
                /*emp=entregas_new();
                entregas_setId(emp,id);
                entregas_setTipo(emp,tipo);
                entregas_setCantidad(emp,cantidad);
                entregas_setPeso(emp,peso);*/
                emp=entregas_newParametros(&id,tipo,&cantidad,&peso);
                ///printf("%d,%s,%d\n",emp->id,emp->nombre,emp->horasTrabajadas);
                ll_add(pArrayListEmployee,emp);
                ///printf("%d,%s,%d\n",emp->id,emp->nombre,emp->horasTrabajadas);
                retorno=1;
            }
        }while(!feof(pFile));
        printf("%d\n",ll_len(pArrayListEmployee));
        //control=fscanf(pF,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horas,sueldo);

    }

    return retorno;
}

int parser_parseEntregas(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pFile;
    int retorno=-1;
    pFile=fopen(fileName,"r");
    if(pFile !=NULL)
    {
        retorno=parser_EmployeeFromText(pFile,listaEmpleados);

    }
    fclose(pFile);
    return retorno; // OK
}

int controller_ListEntregas(LinkedList* pArrayListEmployee)
{
    int i;
    int id=0;
    char tipo[128];
    int cantidad=0;
    float peso=0;
    Entregas* emp;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            emp=ll_get(pArrayListEmployee,i);
            entregas_getId(emp,&id);
            entregas_getTipo(emp,tipo);
            entregas_getCantidad(emp,&cantidad);
            entregas_getPeso(emp,&peso);
            //retorno=atoi(sueldo);
            printf("%d,%s,%d,%.2f\n",id,tipo,cantidad,peso);
        }
    }
    return 1;
}

int controller_ListEmployee2(LinkedList* pArrayListEmployee)
{
    int i;
    int id=0;
    char tipo[128];
    int cantidad=0;
    float peso=0;
    Entregas* emp;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            emp=ll_get(pArrayListEmployee,i);
            entregas_getId(emp,&id);
            entregas_getTipo(emp,tipo);
            entregas_getCantidad(emp,&cantidad);
            entregas_getPeso(emp,&peso);
            //retorno=atoi(sueldo);
            printf("%d,%s,%d,%.2f\n",id,tipo,cantidad,peso);
        }
    }
    return 1;
}
/*int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* emp;
    int id=0;
    char nombre[128];
    int horas=0;
    int sueldo=0;
    int i=0;
    if(pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"w");
        if(pFile != NULL)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                emp=ll_get(pArrayListEmployee,i);
                entregas_getId(emp,&id);
                entregas_getNombre(emp,nombre);
                entregas_getHorasTrabajadas(emp,&horas);
                entregas_getSueldo(emp,&sueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
            }
        }else
        {
            printf("Problemas al lebantar el archivo");
        }
    }
    fclose(pFile);
    return 1;
}*/
