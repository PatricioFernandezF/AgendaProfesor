#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "faltas.h"

int principalFa(){

/*cabecera: void menuFaltas()
precondici�n: Ser llamado por el usuario.
postcondici�n: Mostrar menu.*/

void a(){

}

void menuFaltas(){
    int n;
    int op;
    Alumno* alumno;
    Materia* materia;
    Falta* faltas=obtenerFaltas(&n);

    do{
        printf("\n 1.- Mostrar Faltas.\n 2.- Anadir Faltas.\n 3.- Modificar Faltas.\n 4.- Borrar Faltas.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operaci�n a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: mostrarFaltas(alumno, materia);
                    break;
            case 2: anadirFaltas(faltas);
                    break;
            case 3: modificarFaltas(alumno, faltas);
                    break;
            case 4: eliminarFaltas(alumno, faltas);
                    break;
        }
    }while(op!=5);

    fflush(stdin);

}
}

/*cabecera: void mostrarFaltas()
precondici�n:
postcondici�n: */

Falta* mostrarFaltas(Alumno* alumno, Materia* materia){
    Alumno al;
    Materia mat;

    printf("Indique el id del alumno del que desea ver sus faltas.");
    fgets(al.id_alumno, 7, stdin);
    printf("Indique el id de la asignatura indicada.");
    fgets(mat.id_materia, 5, stdin);
}

/*cabecera: void anadirFaltas()
precondici�n:
postcondici�n: */

void anadirFaltas(Falta* falta){
    Falta fal;

    printf("Indique la fecha de la falta");
    fgets(fal.fecha, 10, stdin);
    printf("Indique la hora de la falta");
    fgets(fal.hora, 10, stdin);
    printf("Indique la descripci�n de la falta");
    fgets(fal.descripcion, 1, stdin);
    printf("Indique el estado de la falta");
    fgets(fal.estado_falta, 17, stdin);
    printf("Indique el id del alumno al que desea poner la falta");
    fgets(fal.id_alumno, 7, stdin);
}

/*cabecera: void modificarFaltas()
precondici�n:
postcondici�n: */

void modificarFaltas(Alumno* alumno, Falta* falta){
    Falta fal;
    int o;

    do{
        printf("�Qu� desea modificar? 1.- Fecha\n 2.- Hora\n 3.- Descripci�n\n 4.- Estado de la falta\n 5.- Id del alumno\n 6.- Salir del programa\n");
        do{
                printf("Introduzca la operaci�n a realizar:");
                scanf("%d", &o);
        }while(o<1 || o>6);
        switch(o){
            case 1:
                    printf("Indique la fecha de la falta");
                    fgets(fal.fecha, 10, stdin);
                    break;
            case 2:
                    printf("Indique la hora de la falta");
                    fgets(fal.hora, 1, stdin);
                    break;
            case 3:
                    printf("Indique una descripci�n de la falta");
                    fgets(fal.descripcion, 31, stdin);
                    break;
            case 4:
                    printf("Indique el estado de la falta");
                    fgets(fal.estado_falta, 17, stdin);
                    break;
            case 5:
                    printf("Indique el id del alumno");
                    fgets(fal.id_alumno, 7, stdin);
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

/*cabecera: void borrarFaltas()
precondici�n:
postcondici�n: */

void borrarFaltas(Alumno* alumno, Falta* falta){

}
