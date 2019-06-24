#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_string.h"
#include "ArrayEmployees.h"
#define CANT 10

int main()
{
    int opcion=0;
    int control=0;
    int id=0;
    int suma=0;
    int prom=0;
    Employee empleados[CANT];
    inicializarEmployees(empleados,CANT);
    Harcodeo(empleados);
    do
    {
        printf("1-alta de empleados\n2-modificar empleado\n3-baja empleados\n4-listar empleados\n5-Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            control=CargarEmployee(empleados,CANT);
            if(control==0)
            {
                printf("El empleado se cargo correctamente\n");
            }else{
            printf("no se pudo cargar al empleado\n");
            }
                break;
        case 2:
            ModificarEmployee(empleados,CANT);
                break;
        case 3:
            printEmployees(empleados,CANT);
            do
            {
                control=getInt(&id,"ingrese el id del empleado a eliminar","No es un numero de id valido",1,CANT);
            }
            while(control !=0);
            id=findEmployeeById(empleados,CANT,id);
            system("cls");
            removeEmployee(empleados,CANT,id);
            system("cls");
            break;
        case 4:
                system("cls");
            do
            {
                do{
                control=getInt(&opcion,"1-Empleados por apellido y sector\n2-suma de salarios , salario promedio y los empleados que lo superan\n3-Salir\n","el numero ingresado no es correcto",1,3);
                }while(control != 0);

                switch(opcion)
                {
                case 1:
                    system("cls");
                 printEmployees(empleados,CANT);
                    break;
                case 2:
                    system("cls");
                    suma=0;
                    prom=0;
                    prom=promedio(empleados,CANT,&suma);
                    printf("suma de los salarios: %d\n",suma);
                    printf("salario promedio: %d\n",prom);
                    printEmployeesMayorAlPromedio(empleados,CANT,prom);
                    break;
                case 3:
                    system("cls");
                    break;
                }
            }
            while(opcion!=3);

            break;
        case 5:
            system("cls");
            ///system("clear");
            break;
        }
    }while(opcion!=5);
}
