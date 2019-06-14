#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int id=0;
    char nombre[128];
    char horas[128];
    char sueldo[128];
    int control=0;
    int retorno=-1;
    Employee* emp;

    if(pFile != NULL)
    {
        control=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",nombre,nombre,nombre,nombre);//esta es la lectura fantasma no tien importancia reiterar la variable
        do
        {
            control=fscanf(pFile,"%d,%[^,],%[^,],%[^\n]",&id,nombre,horas,sueldo);
            if(control==4)
            {
                //printf("%s,%s,%s,%s\n",id,nombre,horas,sueldo);
                /*employee_setId(emp,id);
                employee_setNombre(emp,nombre);
                employee_setHorasTrabajadas(emp,horas);
                employee_setSueldo(emp,sueldo);*/
                emp=employee_newParametros(&id,nombre,horas,sueldo);
                ///printf("%s,%s,%s,%s",id,nombre,horas,sueldo);
                ll_add(pArrayListEmployee,emp);
                retorno=1;
            }
        }while(!feof(pFile));
        printf("%d",ll_len(pArrayListEmployee));
        //control=fscanf(pF,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horas,sueldo);

    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
     Employee emp;
     Employee* emp1;
     int control=0;
     int retorno=-1;

    if(pFile != NULL)
    {
        ///control=fread(&emp,sizeof(Employee),1,pFile);//esta es la lectura fantasma no tien importancia reiterar la variable
        do
        {
            control=fread(&emp,sizeof(Employee),1,pFile);
            if(control==1)
            {
                emp1=employee_newParametros(&emp.id,emp.nombre,emp.horasTrabajadas,emp.sueldo);
                ///printf("%s,%s,%s,%s",id,nombre,horas,sueldo);
                ll_add(pArrayListEmployee,emp1);
                retorno=0;
            }
        }while(!feof(pFile));
        printf("%d",ll_len(pArrayListEmployee));
    }

    return retorno;
}
