#include "faltas.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuFaltas()
precondición: Ser llamado por el usuario.
postcondición: Mostrar menu.*/

void menuFaltas(){
    int op;

    do{
        printf("\n 1.- Mostrar Faltas.\n 2.- Anadir Faltas.\n 3.- Modificar Faltas.\n 4.- Borrar Faltas.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operación a realizar:");
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
precondición:
postcondición: */

void mostrarFaltas(alumno){

}

/*cabecera: void anadirFaltas()
precondición:
postcondición: */

void anadirFaltas(alumno, falta){

}

/*cabecera: void modificarFaltas()
precondición:
postcondición: */

void modificarFaltas(alumno, falta){

}

/*cabecera: void borrarFaltas()
precondición:
postcondición: */

void borrarFaltas(alumno, falta){

}
