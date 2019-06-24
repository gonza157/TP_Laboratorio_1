#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "get_string.h"

int generateid(void)
{
    static int idUnico= 0;
    idUnico++;
    return idUnico;
}

int inicializarEmployees(Employee* lista, int len)
{
    if(lista !=NULL && len >0)
    {
         int i;
    for(i=0;i<len;i++)
    {
        lista[i].isEmpty=1;
    }
    }
 return 0;
}

int BuscarEspacioLibre(Employee* lista, int len)
{
    int i=0;
    int index=0;
    if(lista !=NULL && len >0)
    {
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty ==1)
        {
            index=i;
        }
    }
    }
    return index;
}

int CargarEmployee(Employee* lista,int len)
{
    int retorno=-1;
    int id=0;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int control=-1;
    int control1=-1;
    int control2=-1;
    int control3=-1;
    if(lista !=NULL && len >0)
    {
         id=generateid();
    control=getString(nombre,"ingrese en nombre del empleado\n","nombre no valido\n",1,51,3);
    control1=getString(apellido,"ingrese en apellido del empleado\n","apellido no valido\n",1,51,3);
    do{
        control2=getFloat(&salario,"ingrese el salario\n","El salario no es valido\n",1,99999);
    }while(control2 != 0);
    do{
        control3=getInt(&sector,"Ingrese el sector\n","el sector no es valido\n",1,100);
    }while(control3 != 0);

    if(control ==0 && control1 ==0 && control2 ==0 && control3 ==0)
    {
        retorno=addEmployee(lista,len,id,nombre,apellido,salario,sector);
    }
    }

    return retorno;
}
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
    int retorno=-1;
    int index=0;
    int control=0;
    if(list !=NULL && len >0)
    {
        index=BuscarEspacioLibre(list,len);
    do{
        control=findEmployeeById(list,len,id);
        if(control >0)
        {
            id++;
        }else{
        list[index].id=id;
            }
    }while(control !=-1);
    strncpy(list[index].name,name,sizeof(list[index].name));
    strncpy(list[index].lastName,lastName,sizeof(list[index].lastName));
    list[index].salary=salary;
    list[index].sector=sector;
    list[index].isEmpty=0;
    retorno=0;
    }
    return retorno;
}


int findEmployeeById(Employee* lista, int len,int id)
{
    int i=0;
    int retorno=-1;
    if(lista !=NULL && len >0)
    {
         for(i=0;i<len;i++)
    {
        if(lista[i].id==id)
        {
            id=lista[i].id;
            retorno=i;
        }
    }
    }
 return retorno;
}


int removeEmployee(Employee* lista, int len, int id)
{
    int retorno=-1;
    if(lista !=NULL && len >0)
    {
        lista[id].isEmpty=1;
        retorno=0;
        printf("El empleado fue eliminado con exito\n");
        printf("***********************************\n");
        system("pause");
    }
 return retorno;
}

int sortEmployees(Employee* lista, int len, int order)
{
    int i=0;
    int j=0;
    Employee Auxiliar;
    int retorno=-1;
    if(lista !=NULL && len>0)
    {
        for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(lista[i].isEmpty==0 && lista[j].isEmpty==0)
            {
                if(strcmp(lista[i].lastName,lista[j].lastName)>0 && order == 1)
            {
                Auxiliar=lista[i];
                lista[i]=lista[j];
                lista[j]=Auxiliar;
                retorno=0;
            }
            if( strcmp(lista[i].lastName,lista[j].lastName)==0 && lista[i].sector>lista[j].sector)
            {
                Auxiliar=lista[i];
                lista[i]=lista[j];
                lista[j]=Auxiliar;
            }
            }
        }
    }
    }
    return retorno;
}

int printEmployees(Employee* lista, int len)
{
    int i;
    int retorno=0;
    if(lista !=NULL && len >0)
    {
         sortEmployees(lista,len,1);
    printf("Empleados Ordenados por apellido y sector:\n");
    printf("*****************************************\n");
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0)
        {
            printf("%d%20s %s\t %2.f\t %d\n\n",lista[i].id,lista[i].name,lista[i].lastName,lista[i].salary,lista[i].sector);
            retorno=i;
        }
    }
    }

 return retorno;
}

int ModificarEmployee(Employee* lista,int len)
{
    int retorno=-1;
    int index=0;
    int id=0;
    int cantidad=0;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int opcion=0;
    int control=-1;
    int control2=-1;
    int control3=-1;
    int control4=-1;
    if(lista !=NULL && len >0)
    {
        cantidad=printEmployees(lista,len);
    do
    {
        control4=getInt(&id,"Ingrese el id del empleado a modificar\n","el id no es valido\n",1,cantidad+1);
    }
    while(control4 != 0);
    index=findEmployeeById(lista,len,id);
    system("cls");
    if(index>=0)
    {
        do
        {
            do
            {
                control=getInt(&opcion,"Ingrese la opcion a realizar\n1-nombre\n2-apellido\n3-salario\n4-sector\n5-Salir","La opcion no es valida\n",1,5);
            }while(control !=0);
                switch(opcion)
                {
            case 1:
                getString(nombre,"ingrse el nuevo nombre\n","el nombre no es valido\n",1,51,3);
                strncpy(lista[index].name,nombre,sizeof(lista[index].name));
                break;
            case 2:
                getString(apellido,"ingrse el nuevo apellido\n","el apellido no es valido\n",1,51,3);
                strncpy(lista[index].lastName,apellido,sizeof(lista[index].lastName));
                break;
            case 3:
                do
                {
                    control2=getFloat(&salario,"ingrese el nuevo salario\n","El salario no es valido\n",1,99999);
                }
                while(control2 != 0);
                lista[index].salary=salario;
                break;
            case 4:
                do
                {
                    control3=getInt(&sector,"Ingrese el nuevo sector\n","el sector no es valido\n",1,100);
                }while(control3 != 0);
                    lista[index].sector=sector;
                    break;
            case 5:
                system("cls");
                break;
                }
            }while(opcion != 5);
    }else
    {
        printf("No se encontro el empleado con ese id\n");
    }
    }
    return retorno;
}

int promedio(Employee* lista,int len,int* total)
{
    int i=0;
    int salarioPromedio=0;
    int cantidad=0;
    if(lista !=NULL && len>0)
    {
        for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            *total=*total+lista[i].salary;
            cantidad++;
        }

    }
    salarioPromedio= *total/cantidad;
    }
    return salarioPromedio;
}

int printEmployeesMayorAlPromedio(Employee* lista, int len,int mayor)
{
    int i;
    if(lista !=NULL && len > 0)
    {
        sortEmployees(lista,len,1);
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0 && lista[i].salary > mayor)
        {
            printf("%d%20s %s\t %2.f\t %d\n\n",lista[i].id,lista[i].name,lista[i].lastName,lista[i].salary,lista[i].sector);
        }
    }
    }
 return 0;
}
int Harcodeo(Employee* lista)
{
    lista[0].isEmpty=0;
    lista[0].id=1;
    lista[0].sector=5;
    lista[0].salary=50;
    strncpy(lista[0].name,"gonza",sizeof(lista[0].name));
    strncpy(lista[0].lastName,"iglesias",sizeof(lista[0].lastName));

    lista[1].isEmpty=0;
    lista[1].id=2;
    lista[1].sector=1;
    lista[1].salary=50;
    strncpy(lista[1].name,"alejandro",sizeof(lista[1].name));
    strncpy(lista[1].lastName,"laborde",sizeof(lista[1].lastName));

    lista[2].isEmpty=0;
    lista[2].id=3;
    lista[2].sector=4;
    lista[2].salary=50;
    strncpy(lista[2].name,"matias",sizeof(lista[2].name));
    strncpy(lista[2].lastName,"palmieri",sizeof(lista[2].lastName));

    lista[3].isEmpty=0;
    lista[3].id=4;
    lista[3].sector=2;
    lista[3].salary=50;
    strncpy(lista[3].name,"juanjo",sizeof(lista[3].name));
    strncpy(lista[3].lastName,"iglesias",sizeof(lista[3].lastName));

    lista[4].isEmpty=0;
    lista[4].id=5;
    lista[4].sector=2;
    lista[4].salary=50;
    strncpy(lista[4].name,"pablo",sizeof(lista[4].name));
    strncpy(lista[4].lastName,"palmieri",sizeof(lista[4].lastName));
    return 0;
}

