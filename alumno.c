#include <stdlib.h>
#include "alumno.h"
#include "fichero.h"

void alta_alumno();
void baja_alumno();
void listar_alumno();
void menu_alumno();

// Cabecera: void alta_alumno(Alumno*)
// Precondicion: Recibe una cadena de caracteres de un alumno.
// Poscondicion:
void alta_alumno()
{
    Alumno x;
    char c;
    do
    {
        printf("Introduzca el id del alumno\n");
        gets(x.id_alumno);

        printf("Introduzca el nombre\n");
        gets(x.nombre);

        printf("Introduzca la direccion\n");
        gets(x.direccion);

        printf("Introduzca la localidad\n");
        gets(x.localidad);

        printf("Introduzca el curso\n");
        gets(x.curso);

        printf("Introduzca el grupo\n");
        gets(x.grupo);


        printf("%c\n%c\n%c\n%c\n%c\n%c\n",x.id_alumno,x.nombre,x.direccion,x.localidad,x.curso,x.grupo);
        printf("¿Son correctos los datos? s/n\n");
        scanf("%c",&c);


    }
    while(c!='s');
}

// Cabecera: void baja_usuario(Alumno*)
// Precondicion: Recibe una cadena de caracteres de un alumno.
// Poscondicion:
void baja_alumno()
{
    int N=10,a,i,j;
    Alumno x, y;
    Alumno z[N];
    do
    {
        listar_alumno();
        printf("Introduzca el id del alumno que desea dar de baja");
        gets(y.id_alumno);
        for(i=0; i<N; i++)
        {
            if(x.id_alumno==y.id_alumno)
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


// Cabecera: void listar_usuario(Alumno*)
// Precondicion: Recibe una cadena de caracteres de un alumno.
// Poscondicion:
void listar_alumno()
{
    int i,N=10;
    Alumno x;
    for(i=0; i<N; i++)
    {
        printf("%i : %c\t%c\n",i+1,x.nombre,x.id_alumno);
    }
}

// Cabecera: void menu_alumno()
// Precondicion:
// Poscondicion:
void menu_alumno()
{
    int x;
    Alumno*alumno;
    do
    {
        printf("Introduzca la opcion que desea\n\n 1: Dar de alta un alumno\n 2: Dar de baja a un alumno\n 3: Modificar un alumno\n 4: Listar un alumno\n 0: salir\n");
        scanf("%d",&x);
        switch (x)
        {
        case 0:
            exit(0);
        case 1:
            alta_alumno();
            break;
        case 2:
            baja_alumno();
            break;
        case 3:
            modificar_alumno();
            break;
        case 4:
            listar_alumno();
            break;
        default:
            printf("Error al elegir la opcion.\t");
            break;
        }
    }
    while(x!=0);
}
