#include "horarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

int main(){

/*cabecera: void menuHorarios()
precondici�n: Ser llamado por el usuario.
postcondici�n: Mostrar menu.*/
void menuCalificaciones(){
    int op;
  //  Horarios *horario=obtenerHorarios();
    do{
        printf("\n 1.- Anadir Horarios.\n 2.- Eliminar Horarios.\n 3.- Modificar Horarios.\n 4.- Listar Horarios.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operaci�n a realizar:");
            scanf("%d", &op);
        }while(op<1 || op>5);

/*        switch(op){
            case 1: anadirHorarios(horario);
                    break;
            case 2: eliminarHorarios(horario);
                    break;
            case 3: modificarHorarios(horario);
                    break;
            case 4: listarHorarios(horario);
                    break;
        }
    */}while(op!=5);
    return;
}

/*cabecera: void anadirHorarios()
precondici�n:
postcondici�n: */

void anadirHorarios(Horario){

}

/*cabecera: void eliminarHorarios()
precondici�n:
postcondici�n: */

void eliminarHorarios(Horario){

}

/*cabecera: void modificarHorarios()
precondici�n:
postcondici�n: */

void modificarHorarios(Horario){

}

/*cabecera: void listarHorarios()
precondici�n:
postcondici�n: */

void listarHorarios(Horario){

}
}
