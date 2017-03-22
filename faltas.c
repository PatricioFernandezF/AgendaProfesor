#include "faltas.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuFaltas()
precondici�n: Ser llamado por el usuario.
postcondici�n: Mostrar menu.*/

void menuFaltas(){
    int op;

    do{
        printf("\n 1.- Mostrar Faltas.\n 2.- Anadir Faltas.\n 3.- Modificar Faltas.\n 4.- Borrar Faltas.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operaci�n a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: mostrarFaltas(alumno);
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

/*cabecera: void mostrarFaltas()
precondici�n:
postcondici�n: */

void mostrarFaltas(alumno){

}

/*cabecera: void anadirFaltas()
precondici�n:
postcondici�n: */

void anadirFaltas(alumno, falta){

}

/*cabecera: void modificarFaltas()
precondici�n:
postcondici�n: */

void modificarFaltas(alumno, falta){

}

/*cabecera: void borrarFaltas()
precondici�n:
postcondici�n: */

void borrarFaltas(alumno, falta){

}
