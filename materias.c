#include "materias.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuMaterias()
precondicion: Ser llamado por el usuario
postcondicion: Mostrar menu.*/

void menuMaterias(){
int op;
Materia *materia=obtenerMaterias();

do{
    printf("Introduzca la operacion a realizar:\n 1.-Alta Materias.\n 2.-Baja Materias.\n 3.-Modificar Materias.\n 4.-Eliminar Materias.\n 5.-Salir.\n");
    scanf("%d",&op);
    if (op==1) altaMaterias(materia);
    if (op==2) bajaMaterias(materia);
    if (op==3) modificarMatriculas(materia);
    if (op==4) eliminarMatriculas(materia);
}while(op=!5);
return 0;
}

void obtenerMaterias();{
fflush(stdin);
}
