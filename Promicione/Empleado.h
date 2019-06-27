#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

/*struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;*/
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float peso;
} Entregas;

int em_calcularCantidad(void* p);
Entregas* entregas_new();
Entregas* entregas_newParametros(int* id,char* tipo,int* cantidad,float* peso);
void entregas_delete();

int entregas_setId(Entregas* this,int id);
int entregas_getId(Entregas* this,int* id);

int entregas_setTipo(Entregas* this,char* tipo);
int entregas_getTipo(Entregas* this,char* tipo);

int entregas_setCantidad(Entregas* this,int cantidad);
int entregas_getCantidad(Entregas* this,int* cantidad);

int entregas_setPeso(Entregas* this,float peso);
int entregas_getPeso(Entregas* this,float* peso);
int em_calcularEntregasPortipoSTD(void* elemento);
int em_calcularPeso(void* elemento);
int em_calcularEntregasPortipoEXP(void* elemento);
int em_calcularEntregasPortipoECO(void* elemento);

#endif // EMPLEADO_H_INCLUDED
