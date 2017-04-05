#include "horarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"


void anadirHorarios(Horario *horario);
void eliminarHorarios(Horario *horario);
void modificarHorarios(Horario *horario);
void listarHorarios(Horario *horario);

int mainHorarios(){

/*cabecera: void menuHorarios()
precondición: Ser llamado por el usuario.
postcondición: Mostrar menu.*/
void menuHorarios(){
    int op;
    Horario* horario;

  //  Horarios *horario=obtenerHorarios();
    do{
        printf("\n 1.- Anadir Horarios.\n 2.- Eliminar Horarios.\n 3.- Modificar Horarios.\n 4.- Listar Horarios.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operación a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: anadirHorarios(horario);
                    break;
            case 2: eliminarHorarios(horario);
                    break;
            case 3: modificarHorarios(horario);
                    break;
            case 4: listarHorarios(horario);
                    break;
        }
    }while(op!=5);
    return;
}

/*cabecera: void anadirHorarios()
precondición:
postcondición: */

void anadirHorarios(Horario* horario){

}

/*cabecera: void eliminarHorarios()
precondición:
postcondición: */

void eliminarHorarios(Horario* horario){

}

/*cabecera: void modificarHorarios()
precondición:
postcondición: */

void modificarHorarios(Horario* horario){

}

/*cabecera: void listarHorarios()
precondición:
postcondición: */

void listarHorarios(Horario* horario){

}
return 0;}
