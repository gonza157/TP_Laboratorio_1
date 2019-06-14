#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "get_string.h"
#include "Controller.h"
#include <string.h>

int generateId(LinkedList* this)
{
    int idUnico;
    int i=0;
    Employee* emp;
    if(this != NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            emp=ll_get(this,i);
        }
        idUnico=emp->id;
        idUnico++;
    }
    return idUnico;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pF;
    pF= fopen(path,"r");
    if(pF != NULL)
    {
        parser_EmployeeFromText(pF,pArrayListEmployee);
    }
    fclose(pF);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
     FILE* pF;
    pF= fopen(path,"rb");
    if(pF != NULL)
    {
        parser_EmployeeFromBinary(pF,pArrayListEmployee);
    }
    fclose(pF);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp;
    int id=0;
    char nombre[128];
    char horas[128];
    char sueldo[128];
    int retorno=-1;
    int control2=-1;
    int control3=-1;
    int control4=-1;
    if(pArrayListEmployee !=NULL)
    {
    id=generateId(pArrayListEmployee);
    control2=getString(nombre,"ingrese nombre","No es un nombre valido",1,128,3);
    control3=getStringNumeros(horas,"ingrese horas trabajadas","No son horas valido",1,128,3);
    control4=getStringNumeros(sueldo,"ingrese sueldo","No es un sueldo valido",1,128,3);
    if(control2==0 && control3 ==0 && control4==0)
    {
        emp=employee_newParametros(&id,nombre,horas,sueldo);
        ll_add(pArrayListEmployee,emp);
        retorno=0;
    }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i=0;
    int idCompare=0;
    int retorno=-1;
    int option=0;
    int control=-1;
    char nuevasHoras[128];
    char nuevoSueldo[128];
    char nuevoNombre[128];
    Employee* emp;
    controller_ListEmployee(pArrayListEmployee);
    getInt(&idCompare,"ingrese el id del empleado a modificar","el id no es valido",1,99999);
    if(idCompare <=ll_len(pArrayListEmployee))
    {
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        emp=ll_get(pArrayListEmployee,i);
        if(emp->id==idCompare)
        {
            do{
            printf("*********************************\n");
            MuestraMenu("1-Nombre\n2-Horas Trabajadas\n3-Sueldo\n4-Salir\n");
            printf("*********************************\n");
            do{
            control=getInt(&option,"ingrese la opcion correspondiente al campo que quiere modificar:\n","La opcion marcada no es valida",1,4);
            }while(control!=0);
            switch(option)
            {
            case 1:
                control=getString(nuevoNombre,"ingrese el nuevo nombre","el nombre ingresado no es valido",1,128,3);
                if(control == 0)
                {
                    strncpy(emp->nombre,nuevoNombre,sizeof(emp->nombre));
                }
                break;
            case 2:
                control=getStringNumeros(nuevasHoras,"ingrese las horas trabajadas","Las horas no son validas",1,128,3);
                if(control == 0)
                {
                    strncpy(emp->horasTrabajadas,nuevasHoras,sizeof(emp->horasTrabajadas));
                }
                break;
            case 3:
                control=getStringNumeros(nuevoSueldo,"ingrese el nuevo sueldo","Las sueldo es valido",1,128,3);
                if(control == 0)
                {
                    strncpy(emp->sueldo,nuevoSueldo,sizeof(emp->sueldo));
                }
                break;
            case 4:
                system("cls");
                ///system("clear");
                break;
            }
            }while(option !=4);
            printf("el empleado fue modificado con exito\n");
            retorno=0;
            break;
        }
    }
    }else
    {
        printf("No se encontro el id especificado\n");
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int i=0;
    int idCompare=0;
    int retorno=-1;
    Employee* emp;
    controller_ListEmployee(pArrayListEmployee);
    getInt(&idCompare,"ingrese el id del empleado a eliminar","el id no es valido",1,99999);
    if(idCompare <=ll_len(pArrayListEmployee))
    {
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        emp=ll_get(pArrayListEmployee,i);
        if(emp->id==idCompare)
        {
            ll_remove(pArrayListEmployee,i);
            printf("el empleado fue eliminado con exito\n");
            retorno=0;
            break;
        }
    }
    }else
    {
        printf("No se encontro el id especificado\n");
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int id=0;
    char nombre[128];
    char horas[128];
    char sueldo[128];
    Employee* emp;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            emp=ll_get(pArrayListEmployee,i);
            employee_getId(emp,&id);
            employee_getNombre(emp,nombre);
            employee_getHorasTrabajadas(emp,horas);
            employee_getSueldo(emp,sueldo);
            //retorno=atoi(sueldo);
            printf("%d,%s,%s,%s\n",id,nombre,horas,sueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
int opcion;

    printf("----------Menu de Ordenamientos----------\n\n");

    do{
    printf("Ingrese el criterio de ordenamiento\n");
    printf("1-->ID de menor a mayor\n2-->ID de mayor a menor\n");
    printf("3-->Horas de trabajo de menor a mayor\n4-->Horas de trabajo de mayor a menor\n");
    printf("5-->Sueldo de menor a mayor\n6-->Sueldo de mayor a menor\n");
    printf("7-->Nombre de la A-Z\n8-->Nombre de la Z-A\n9-->Imprimir\n10-->Salir\n");
    scanf("%d",&opcion);
    printf("\n\n");
        switch (opcion){
        case 1:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,1);/// de menor a mayor
            printf("Listado Ordenado\n");
            break;
        case 2:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 3:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,1);/// de menor a mayor este tarda un monton
            printf("Listado Ordenado\n");
            break;
        case 4:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 5:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,1);/// de menor a mayor
            printf("Listado Ordenado\n");
            break;
        case 6:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 7:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,1);/// de menor a mayor
            printf("Listado Ordenado\n");
            break;
        case 8:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 9:
            printf("Imprime listado\n\n");
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 10:
            printf("Salida del menu...\n\n");
            opcion=11;
            break;
        }
    }while(opcion != 11);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* emp;
    int id=0;
    char nombre[128];
    char horas[128];
    char sueldo[128];
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
                employee_getId(emp,&id);
                employee_getNombre(emp,nombre);
                employee_getHorasTrabajadas(emp,horas);
                employee_getSueldo(emp,sueldo);
                fprintf(pFile,"%d,%s,%s,%s\n",id,nombre,horas,sueldo);
            }
        }else
        {
            printf("Problemas al lebantar el archivo");
        }
    }
    fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
        FILE* pFile;
    Employee* emp;

    int i=0;
    if(pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"wb");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                emp=ll_get(pArrayListEmployee,i);
                fwrite(emp,sizeof(Employee),1,pFile);
            }
        }
    }
    fclose(pFile);
    return 1;
}

