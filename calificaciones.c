#include "calificaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuCalificaciones()
precondición: Ser llamado por el usuario.
postcondición: Mostrar menu.*/

void menuCalificaciones(){
    int op;

    do{
        printf("\n 1.- Mostrar Calificaciones.\n 2.- Anadir Calificaciones.\n 3.- Modificar Calificaciones.\n 4.- Eliminar Calificaciones.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operación a realizar:");
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
precondición:
postcondición: */

void mostrarCalificaciones(alumno, materia){

}

/*cabecera: void anadirCalificaciones()
precondición:
postcondición: */

void anadirCalificaciones(alumno, materia, int){

}

/*cabecera: void modificarCalificaciones()
precondición:
postcondición: */

void modificarCalificaciones(alumno, materia, int){

}

/*cabecera: void aliminarCalificaciones()
precondición:
postcondición: */

void eliminarCalificaciones(alumno, materia){

}
