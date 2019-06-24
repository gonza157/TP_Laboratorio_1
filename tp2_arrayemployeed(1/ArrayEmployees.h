#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;

int inicializarEmployees(Employee* lista, int len);
int BuscarEspacioLibre(Employee* lista, int len);
int CargarEmployee(Employee* lista,int len);
int addEmployee(Employee* lista, int len, int id, char* name,char* lastName,float salary,int sector);
int findEmployeeById(Employee* lista, int len,int id);
int removeEmployee(Employee* lista, int len, int id);
int sortEmployees(Employee* lista, int len, int order);
int printEmployees(Employee* lista, int len);
int Harcodeo(Employee* lista);
int ModificarEmployee(Employee* lista,int len);
int promedio(Employee* lista,int len,int* total);
int printEmployeesMayorAlPromedio(Employee* lista, int len,int mayor);
int generateid(void);

#endif // ARRAYEMPLOYEES_H_INCLUDED
