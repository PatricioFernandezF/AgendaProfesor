#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichero.h"
#include "calificaciones.h"

Calificacion* mostrarCalificaciones(Alumno*, Materia*);
void anadirCalificaciones(Alumno*, Materia*, int*);
void modificarCalificaciones(Alumno*, Materia*, Calificacion*);
void eliminarCalificaciones(Alumno*, Materia*, Calificacion*);

int principalCa(){

/*cabecera: void menuCalificaciones()
precondición: Ser llamado por el usuario.
postcondición: Mostrar menu.*/

void menuCalificaciones(){
    int op;
    int*nota;
    Alumno*alumno;
    Materia*materia;
    Calificacion*calificacion;

    do{
        printf("\n 1.- Mostrar Calificaciones.\n 2.- Anadir Calificaciones.\n 3.- Modificar Calificaciones.\n 4.- Eliminar Calificaciones.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operación a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: mostrarCalificaciones(alumno, materia);
                    break;
            case 2: anadirCalificaciones(alumno, materia, nota);
                    break;
            case 3: modificarCalificaciones(alumno, materia, calificacion);
                    break;
            case 4: eliminarCalificaciones(alumno, materia, calificacion);
                    break;
        }
    }while(op!=5);

    fflush(stdin);

    return ;
}
}

/*cabecera: void mostrarCalificaciones()
precondición:
postcondición: mostrar calificaiones de un alumno en una materia*/

Calificacion* mostrarCalificaciones(Alumno* alumno, Materia* materia){

}

/*cabecera: void anadirCalificaciones()
precondición:
postcondición: anadir una calificación a un alumno en una materia*/

void anadirCalificaciones(Alumno* alumno, Materia* materia, int* nota){

}

/*cabecera: void modificarCalificaciones()
precondición:
postcondición: modificar las calificaciones de un alumno en una materia*/

void modificarCalificaciones(Alumno* alumno, Materia* materia, Calificacion* calificacion){

}

/*cabecera: void aliminarCalificaciones()
precondición:
postcondición: borrar las calificaciones de un alumno en una materia*/

void eliminarCalificaciones(Alumno* alumno, Materia* materia, Calificacion* calificacion){

}
