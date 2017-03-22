#include "calificaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuCalificaciones()
precondici�n: Ser llamado por el usuario.
postcondici�n: Mostrar menu.*/

void menuCalificaciones(){
    int op;

    do{
        printf("\n 1.- Mostrar Calificaciones.\n 2.- Anadir Calificaciones.\n 3.- Modificar Calificaciones.\n 4.- Eliminar Calificaciones.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operaci�n a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: modificarCalificaciones(alumno, materia);
                    break;
            case 2: anadirCalificaciones(alumno, materia, int);
                    break;
            case 3: modificarCalificaciones(alumno, materia, int);
                    break;
            case 4: eliminarCalificaciones(alumno, materia);
                    break;
        }
    }while(op!=5);

    fflush(stdin);

    return 0;
}

/*cabecera: void mostrarCalificaciones()
precondici�n:
postcondici�n: */

void mostrarCalificaciones(alumno, materia){

}

/*cabecera: void anadirCalificaciones()
precondici�n:
postcondici�n: */

void anadirCalificaciones(alumno, materia, int){

}

/*cabecera: void modificarCalificaciones()
precondici�n:
postcondici�n: */

void modificarCalificaciones(alumno, materia, int){

}

/*cabecera: void aliminarCalificaciones()
precondici�n:
postcondici�n: */

void eliminarCalificaciones(alumno, materia){

}
