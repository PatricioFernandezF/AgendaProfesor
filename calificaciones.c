#include "calificaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuCalificaciones()
precondici�n: Ser llamado por el usuario.
postcondici�n: Mostrar menu.*/

void menuCalificaciones(){
    int op;

    do{
        printf("Introduzca la operaci�n a realizar:\n 1.- Mostrar Calificaciones.\n 2.- A�adir Calificaciones.\n 3.- Modificar Calificaciones.\n 4.- Eliminar Calificaciones.\n 5.- Salir del Programa.\n");
        scanf("%d", &op);
        if(op==1) modificarCalificaciones(alumno, materia);
        if(op==2)
}
}
