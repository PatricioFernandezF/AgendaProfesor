#include "horarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuHorarios()
precondici�n: Ser llamado por el usuario.
postcondici�n: Mostrar menu.*/

void menuCalificaciones(){
    int op;

    do{
        printf("\n 1.- Anadir Horas.\n 2.- Eliminar Horas.\n 3.- Modificar Horas.\n 4.- Listar Horarios.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operaci�n a realizar:");
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
precondici�n:
postcondici�n: */

void anadirHoras(int){

}

/*cabecera: void eliminarHorarios()
precondici�n:
postcondici�n: */

void eliminarHoras(int){

}

/*cabecera: void modificarHorarios()
precondici�n:
postcondici�n: */

void modificarHoras(int){

}

/*cabecera: void listarHorarios()
precondici�n:
postcondici�n: */

void listarHorarios(horario){

}
