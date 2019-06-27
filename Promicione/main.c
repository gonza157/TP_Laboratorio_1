#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "linkedlist.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);
int generarArchivoInformes(char* fileName,LinkedList* listaEmpleados);
Entregas* emp;
int devuelve=0;

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados;

    // Crear lista empledos
    listaEmpleados=ll_newLinkedList();
    //...

    // Leer empleados de archivo data.csv
    if(parser_parseEntregas("data.csv",listaEmpleados)==1)
    {
        controller_ListEntregas(listaEmpleados);
        ///emp=ll_get(listaEmpleados,3);
        ///printf("%d\n",emp->id);
        // Calcular sueldos
        printf("Calculando entregas\n");
        ///al_map(listaEmpleados,em_calcularCantidad);

        // Generar archivo de salida
        if(generarArchivoInformes("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
            ///controller_ListEntregas2(listaEmpleados);
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo entregas\n");


    return 0;
}


int generarArchivoInformes(char* fileName,LinkedList* listaEmpleados)
{
    FILE* pFile;
    //Entregas* emp;
    int cantidad=0;
    int cantidadBultos=0;
    int cantidadMaximaBultos=0;
    int promedioBultos=0;
    int PesoTotal=0;
    int promedioPeso=0;
    int tipoSTD=0;
    int tipoEXP=0;
    int tipoECO=0;
    if(listaEmpleados != NULL)
    {
        pFile=fopen(fileName,"w");
        if(pFile != NULL)
        {
            cantidad=ll_len(listaEmpleados);
            cantidadBultos=al_map(listaEmpleados,em_calcularCantidad);
            cantidadMaximaBultos=al_map2(listaEmpleados,em_calcularCantidad);
            PesoTotal=al_mapPeso(listaEmpleados,em_calcularPeso);

            tipoSTD=ll_maps(listaEmpleados,em_calcularEntregasPortipoSTD);
            tipoEXP=ll_maps(listaEmpleados,em_calcularEntregasPortipoEXP);
            tipoECO=ll_maps(listaEmpleados,em_calcularEntregasPortipoECO);


            fprintf(pFile,"Cantidad de entregas: \n");
            fprintf(pFile,"%d\n",cantidad);

            fprintf(pFile,"Cantidad Maxima de Bultos: \n");
            fprintf(pFile,"%d\n",cantidadMaximaBultos);

            promedioBultos=cantidadBultos / cantidad;
            fprintf(pFile,"Promedio de Bultos por entrega: \n");
            fprintf(pFile,"%d\n",promedioBultos);

             promedioPeso=PesoTotal / cantidad;
            fprintf(pFile,"Promedio de Peso por entrega: \n");
            fprintf(pFile,"%d\n",promedioPeso);


            fprintf(pFile,"Cantidad de entregas por tipo: \n");
            fprintf(pFile,"Tipo STD: \n");
            fprintf(pFile,"%d\n",tipoSTD);

            fprintf(pFile,"Tipo EXP: \n");
            fprintf(pFile,"%d\n",tipoEXP);

            fprintf(pFile,"Tipo ECO: \n");
            fprintf(pFile,"%d\n",tipoECO);

        }
        }else
        {
            printf("Problemas al lebantar el archivo");
        }

    fclose(pFile);
    return 1;
}
int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    FILE* pFile;
    Entregas* emp;
    int id=0;
    char tipo[128];
    int cantidad=0;
    float peso=0;
    int i=0;
    if(listaEmpleados != NULL)
    {
        pFile=fopen(fileName,"w");
        if(pFile != NULL)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<ll_len(listaEmpleados);i++)
            {
                emp=ll_get(listaEmpleados,i);
                entregas_getId(emp,&id);
                entregas_getTipo(emp,tipo);
                entregas_getCantidad(emp,&cantidad);
                entregas_getPeso(emp,&peso);
                fprintf(pFile,"%d,%s,%d,%.2f\n",id,tipo,cantidad,peso);
            }
        }else
        {
            printf("Problemas al lebantar el archivo");
        }
    }
    fclose(pFile);
    return 1;
}
