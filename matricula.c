#include <stdio.h>
#include "matricula.h"
#include "fichero.h"

void lista_de_materias();
void cambios_de_matricula();
void eliminar_matricula();
void crear_nueva_matricula();

void lista_de_materias()
{
    int i, z=3,a;
    Matricula vector_matricula[z];
    Materia vector_materia[z];
    char c[8], d[6];
    do
    {
        printf("Introduzca el id del alumno\n");
        fgets(c,8,stdin);
        for(i=0; i<z; i++)
        {

            if(strcmp(c,vector_matricula[i].id_alumno)==0)
            {
                strcpy(d,vector_matricula[i].id_materia);
                for(i=0; i<z; i++)
                {
                    if(d==vector_materia[i].id_materia)
                    {
                        printf("%c",vector_materia[i].nombre);
                        a=1;
                    }
                }
            }
            else
            {
                printf("Error al introducir el id del alumno\n");
                a=0;
            }
        }
    }
    while(a!=1);
}

cambios_de_matricula()
{
    int i, z=3,a;
    Matricula vector_matricula[z];
    char c[8];
    do
    {
        printf("Introduzca el id del alumno\n");
        fgets(c,8,stdin);
        for(i=0; i<z; i++)
        {

            if(strcmp(c,vector_matricula[i].id_alumno)==0)
            {
                printf("Introduzca el id de la materia que desea cambiar\n");
                scanf("%s",vector_matricula[i].id_materia);
            }
            else
            {
                printf("Error al introducir el id del alumno\n");
                a=0;
            }
        }
    }
    while(a!=1);

}

eliminar_matricula()
{int N=10,a,i,j;
    Matricula x;
    Matricula z[N];
    do
    {
        listar_alumno();
        printf("Introduzca el id del alumno para eliminar la matricula");
        scanf("%s",x.id_alumno);
        for(i=0; i<N; i++)
        {
            if(x.id_alumno==z[i].id_alumno)
            {
                for(j=i; j<N; j++)
                {
                    z[j]=z[j+1];
                    a=1;
                }
            }
            else
            {
                printf("Error al introducir el id del alumno");
                a=0;
            }
        }
    }
    while(a!=1);

}

void crear_nueva_matricula()
{
    int i, z=3,a;
    int n;
    Matricula vector_matricula[z];
    Matricula x;
    do
    {
        printf("Introduzca el id del alumno\n");
        fgets(x.id_alumno,8,stdin);
        printf("Introduzca el id de la materia\n");
        scanf("%s",x.id_materia);
        for(i=0; i<z; i++)
        {

            if(strcmp(x.id_materia,vector_matricula[i].id_materia)==0)
            {
                printf("El alumno ya esta matriculado de la aisgnatura deseada\n");
            }
            else
            {
                strcpy(vector_matricula[z+1].id_alumno,x.id_alumno);
                strcpy(vector_matricula[z+1].id_materia,x.id_materia);
                printf("Ya se ha matriculado al alumno\n");
                a=1;
            }
        }
    }
    while(a!=1);
}
