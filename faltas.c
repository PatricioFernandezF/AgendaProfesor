#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichero.h"
#include "faltas.h"

Falta* mostrarFaltas(Alumno*, Materia*, Falta*);
void anadirFaltas(Alumno*, Falta*);
void modificarFaltas(Alumno*, Falta*);
void borrarFaltas(Alumno*, Falta*);

int principalFa(){

/*cabecera: void menuFaltas()
precondici�n: Ser llamado por el usuario.
postcondici�n: Mostrar menu.*/

void menuFaltas(){
    int op;
    Alumno* alumno;
    Materia* materia;
    Falta* falta;

    do{
        printf("\n 1.- Mostrar Faltas.\n 2.- Anadir Faltas.\n 3.- Modificar Faltas.\n 4.- Borrar Faltas.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operaci�n a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: mostrarFaltas(alumno, materia, falta);
                    break;
            case 2: anadirFaltas(alumno, falta);
                    break;
            case 3: modificarFaltas(alumno, falta);
                    break;
            case 4: eliminarFaltas(alumno, falta);
                    break;
        }
    }while(op!=5);

    fflush(stdin);

    return 0;
}
}

/*cabecera: void mostrarFaltas()
precondici�n:
postcondici�n: */

Falta* mostrarFaltas(Alumno* alumno, Materia* materia, Falta* falta){

}

/*cabecera: void anadirFaltas()
precondici�n:
postcondici�n: */

void anadirFaltas(Alumno* alumno, Falta* falta){

}

/*cabecera: void modificarFaltas()
precondici�n:
postcondici�n: */

void modificarFaltas(Alumno* alumno, Falta* falta){

}

/*cabecera: void borrarFaltas()
precondici�n:
postcondici�n: */

void borrarFaltas(Alumno* alumno, Falta* falta){

}
