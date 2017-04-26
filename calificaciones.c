#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichero.h"
#include "calificaciones.h"

void menuCalificaciones(){
    int n;
    int op;
    Alumno*alumno;
    Materia*materia;
    Calificacion* calificaciones=obtenerCalificaciones(&n);

    do{
        printf("\n 1.- Mostrar Calificaciones.\n 2.- Anadir Calificaciones.\n 3.- Modificar Calificaciones.\n 4.- Eliminar Calificaciones.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operaci�n a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1:
                    mostrarCalificaciones(alumno, materia);
                    break;
            case 2:
                    anadirCalificaciones(calificaciones);
                    break;
            case 3:
                    modificarCalificaciones(alumno, materia, calificaciones);
                    break;
            case 4:
                    eliminarCalificaciones(alumno, materia, calificaciones);
                    break;
            case 5:
                    exit(5);
                    break;
            default:
                    printf("Error al elegir la opci�n.\t");
                    break;
        }
    }while(op!=5);

    fflush(stdin);

    return ;
}

/*cabecera: void mostrarCalificaciones()
precondici�n: recibe el id de un alumno y el id de una materia
postcondici�n: mostrar calificaiones de un alumno en una materia*/

Calificacion* mostrarCalificaciones(Alumno* alumno, Materia* materia){
    Alumno al;
    Materia mat;

    printf("Indique el id del alumno del que desea ver sus calificaciones.");
    fgets(al.id_alumno, 7, stdin);
    printf("Indique el id de la asignatura indicada.");
    fgets(mat.id_materia, 5, stdin);

}

/*cabecera: void anadirCalificaciones()
precondici�n: recibe todos los datos correspondientes a la estructura calificaciones
postcondici�n: anadir una calificaci�n a un alumno en una materia*/

void anadirCalificaciones(Calificacion* calificaciones){
    Calificacion cal;

    printf("Indique la fecha de la calificaci�n");
    fgets(cal.fecha, 10, stdin);
    printf("Indique una descripci�n de a calificaci�n");
    fgets(cal.descripcion, 31, stdin);
    printf("Indique el id de la materia calificada");
    fgets(cal.id_materia, 5, stdin);
    printf("Indique el id del alumno calificado");
    fgets(cal.id_alumno, 7, stdin);
    printf("Indique la calificaci�n del alumno");
    fgets(cal.calificacion, 2, stdin);
}

/*cabecera: void modificarCalificaciones()
precondici�n: recibe un entero representando la opcion que desean modificar
postcondici�n: modificar las calificaciones de un alumno en una materia*/

void modificarCalificaciones(Alumno* alumno, Materia* materia, Calificacion* calificaciones){
    Calificacion cal;
    int o;

    do{
        printf("�Qu� desea modificar? 1.- Fecha\n 2.- Descripci�n\n 3.- Id de la materia\n 4.- Id del alumno\n 5.- Calificaci�n\n 6.- Salir del programa\n");
        do{
                printf("Introduzca la operaci�n a realizar:");
                scanf("%d", &o);
        }while(o<1 || o>6);
        switch(o){
            case 1:
                    printf("Indique la fecha de la calificaci�n");
                    fgets(cal.fecha, 10, stdin);
                    break;
            case 2:
                    printf("Indique una descripci�n de a calificaci�n");
                    fgets(cal.descripcion, 31, stdin);
                    break;
            case 3:
                    printf("Indique el id de la materia calificada");
                    fgets(cal.id_materia, 5, stdin);
                    break;
            case 4:
                    printf("Indique el id del alumno calificado");
                    fgets(cal.id_alumno, 7, stdin);
                    break;
            case 5:
                    printf("Indique la calificaci�n del alumno");
                    fgets(cal.calificacion, 2, stdin);
                    break;
            case 6:
                    exit(6);
                    break;
            default:
                    printf("Error al elegir la opci�n.\t");
                    break;
        }
    }while(o!=6);

    fflush(stdin);
}

/*cabecera: void aliminarCalificaciones()
precondici�n:
postcondici�n: borrar las calificaciones de un alumno en una materia*/

void eliminarCalificaciones(Alumno* alumno, Materia* materia, Calificacion* calificaciones){

}
