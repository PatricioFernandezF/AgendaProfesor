#include "matriculas.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuMatriculas()
precondicion: Ser llamado por el usuario
postcondicion: Mostrar menu.*/

void menuMatriculas(){
int op;
Matricula *matricula=obtenerMatriculas();

do{
    printf("Introduzca la operacion a realizar:\n 1.-Listar matriculas.\n 2.-Cambiar Matriculas.\n 3.-Nueva Matricula.\n 4.-Eliminar Matricula.\n 5.-Salir.\n");
    scanf("%d",&op);
    if (op==1) listarMatriculas(matricula);
    if (op==2) cambioMatriculas(matricula);
    if (op==3) nuevaMatriculas(matricula);
    if (op==4) eliminarMatriculas(matricula);
}while(op=!5);
return 0;
}

void obtenerMatriculas(){
fflush(stdin);
}
