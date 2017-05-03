/*Ruben*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichero.h"
#include "faltas.h"



void menuFaltas(char x){
    int n;
    int op;
    Alumno *alumno;
    Materia *materia;
    Falta *faltas=obtenerFaltas(&n);

    do{
        printf("\n 1.- Mostrar Faltas.\n 2.- Anadir Faltas.\n 3.- Modificar Faltas.\n 4.- Borrar Faltas.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operación a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: mostrarFaltas(x, alumno, materia, n);
                    break;
            case 2: anadirFaltas(faltas, n);
                    break;
            case 3: modificarFaltas(alumno, faltas, n);
                    break;
            case 4: borrarFaltas(alumno, faltas, n);
                    break;
        }
    }while(op!=5);

    fflush(stdin);

}

/*cabecera: Falta* mostrarFaltas(Alumno* alumno, Materia* materia, int n)
precondición: Recibe un puntero a alumno, puntero a materia y entero que indica el numero de elementos del vector
postcondición: Imprime por pantalla la lista de faltas del alumno indicado, en una materia en concreto*/

void mostrarFaltas(char id_al, Alumno *alumno, Materia *materia, int n){
    Alumno al;
    Materia mat;
    Falta *falta;
    int i;


    for(i=0;i<n;i++){
        if(id_al==alumno[i].id_alumno){
            printf("%s\t%s\t%s\t%s\t%s\n", falta[i].fecha, falta[i].hora, falta[i].descripcion, falta[i].estado_falta, falta[i].id_alumno);
        }
    }
}

/*cabecera: void anadirFaltas(Falta* faltas, int n)
precondición: Recibe un puntero a falta y un entero que indique el numero de elementos del vector
postcondición: Anade una falta a un alumno*/

void anadirFaltas(Falta *faltas, int n){
    Falta fal;

    printf("Indique la fecha de la falta\n");
    fgets(fal.fecha, 10, stdin);
    printf("Indique la hora de la falta\n");
    fgets(fal.hora, 10, stdin);
    printf("Indique la descripción de la falta\n");
    fgets(fal.descripcion, 31, stdin);
    printf("Indique el estado de la falta\n");
    fgets(fal.estado_falta, 17, stdin);
    printf("Indique el id del alumno al que desea poner la falta\n");
    fgets(fal.id_alumno, 7, stdin);


/*    guardarDatosFaltas();*/
}

/*cabecera: void modificarFaltas(Alumno* alumno, Falta* faltas, int n)
precondición: Recibe un puntero a alumno, un puntero a falta y un entero que indique el numero de elementos del vector
postcondición: Permite modificar */

void modificarFaltas(Alumno *alumno, Falta *faltas, int n){
    Falta fal;
    int o;

    do{
        printf("¿Qué desea modificar? 1.- Fecha\n 2.- Hora\n 3.- Descripción\n 4.- Estado de la falta\n 5.- Id del alumno\n 6.- Salir del programa\n");
        do{
                printf("Introduzca la operación a realizar:");
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
                    printf("Indique una descripción de la falta");
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
                    printf("Error al elegir la opción.\t");
                    break;
        }
    }while(o!=6);

    fflush(stdin);
}

/*cabecera: void borrarFaltas(Alumno *alumno, Falta *faltas, int n)
precondición: Recibe un puntero a alumno, un puntero a falta y un entero con el numero de elementos del vector
postcondición: Borra las faltas de un alumno en una materia*/

void borrarFaltas(Alumno *alumno, Falta *faltas, int n){
    int id, i;
    Materia *materia;
    Falta *falta;
    char x;

    mostrarFaltas(x, &alumno, &materia, n);

    Falta aux[i];
    id-=1;

    for(i=0;i<n;i++){
        if(i<id){
            aux[i]=falta[i];
        }else if(i==id){

        }else{
            aux[i-1]=falta[i];
        }
    }
    guardarDatosFaltas(aux, n);
}
