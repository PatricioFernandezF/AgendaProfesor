#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alumno.h"
#include "fichero.h"

void alta_alumno(Alumno*);
void baja_alumno(Alumno*);
void listar_alumno(Alumno*);
void menu_alumno();

// Cabecera: void alta_alumno(Alumno*)
// Precondicion: Recibe una cadena de caracteres de un alumno.
// Poscondicion:
void alta_alumno(Alumno* alumno)
{
    
}
// Cabecera: void baja_usuario(Alumno*)
// Precondicion: Recibe una cadena de caracteres de un alumno.
// Poscondicion:
void baja_alumno(Alumno* alumno)
{
}


// Cabecera: void listar_usuario(Alumno*)
// Precondicion: Recibe una cadena de caracteres de un alumno.
// Poscondicion:
    void listar_alumno(Alumno* alumno)
    {
    }

// Cabecera: void menu_alumno()
// Precondicion:
// Poscondicion:
    void menu_alumno()
    {
        int x;
        Alumno *alumno;
        do{
            printf("Introduzca la opcion que desea\n\n 1: Dar de alta un alumno\n 2: Dar de baja a un alumno\n 3: Modificar un alumno\n 4: Listar un alumno\n 0: salir\n");
            scanf("%d",&x);
            switch (x)
            {
            case 0:
                exit(0);
            case 1:
                alta_alumno(alumno);
                break;
            case 2:
                baja_alumno(alumno);
                break;
            case 3:
                modificar_alumno(alumno);
                break;
            case 4:
                listar_alumno(alumno);
                break;
            default:
                printf("Error al elegir la opcion.\t");
                break;
            }
        }while(x!=0);
    }
