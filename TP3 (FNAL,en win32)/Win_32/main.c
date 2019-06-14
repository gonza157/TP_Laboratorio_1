#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "get_string.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    //Employee* aux;
    //aux=employee_new();
    int option = 0;
    int control=-1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("\t\t/****************************************************\n");
        MuestraMenu("\t\t1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n\t\t2-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n\t\t3-Alta de empleado\n\t\t4-Modificar datos de empleado\n\t\t5-Baja de empleado\n\t\t6-Listar empleados\n\t\t7-Ordenar empleados\n\t\t8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n\t\t9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n\t\t10-Salir\n");

        printf("\t\t/****************************************************\n");
        do{
        control=getInt(&option,"ingrese la opcion que desea realizar","La opcion ingresada no es valida",1,10);
        }while(control!=0);
        switch(option)
        {
        case 1:
            system("cls");
            //system("clear");
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            //parser_EmployeeFromText(NULL,NULL);
            //recibe id
            controller_loadFromBinary("copiaBin.csv",listaEmpleados);
            break;
        case 3:
            system("cls");
            //system("clear");
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            //aux =ll_get(listaEmpleados,2);
            //printf("%d",aux->id);
            break;
            case 5:
            system("cls");
            //system("clear");
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            system("cls");
            //system("clear");
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            system("cls");
            //system("clear");
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            system("cls");
            //system("clear");
            controller_saveAsText("copia.csv",listaEmpleados);
            break;
        case 9:
            system("cls");
            //system("clear");
            controller_saveAsBinary("copiaBin.csv",listaEmpleados);
            break;
        case 10:
            system("cls");
            //system("clear");
            ll_deleteLinkedList(listaEmpleados);
            break;
        }
    }
    while(option != 10);
    return 0;
}
