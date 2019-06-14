#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int* id,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,char* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,char* sueldo);
int employee_IdMenorMayor(void* elemento1,void* elemento2);

int employee_OrdenaEnteroID(void* elementoA, void* elementoB);
int employee_OrdenaEnteroHoras(void* elementoA, void* elementoB);
int employee_OrdenaEnteroSueldo(void* elementoA, void* elementoB);
int employee_OrdenaCadenaNombre(void* elementoA, void* elementoB);
#endif // employee_H_INCLUDED
