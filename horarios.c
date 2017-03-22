#include "horarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuHorarios()
precondición: Ser llamado por el usuario.
postcondición: Mostrar menu.*/

void menuCalificaciones(){
    int op;

    do{
        printf("\n 1.- Anadir Horas.\n 2.- Eliminar Horas.\n 3.- Modificar Horas.\n 4.- Listar Horarios.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operación a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: anadirHoras(int);
                    break;
            case 2: eliminarHoras(int);
                    break;
            case 3: modificarHoras(int);
                    break;
            case 4: listarHorarios(horario);
                    break;
        }
    }while(op!=5);

    fflush(stdin);

    return 0;
}

/*cabecera: void anadirHorarios()
precondición:
postcondición: */

void anadirHoras(int){

}

/*cabecera: void eliminarHorarios()
precondición:
postcondición: */

void eliminarHoras(int){

}

/*cabecera: void modificarHorarios()
precondición:
postcondición: */

void modificarHoras(int){

}

/*cabecera: void listarHorarios()
precondición:
postcondición: */

void listarHorarios(horario){

}
