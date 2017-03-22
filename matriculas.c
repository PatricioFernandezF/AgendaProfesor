#include "matriculas.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

int main(){

/*cabecera: void menuMatriculas()
precondicion: Ser llamado por el usuario
postcondicion: Mostrar menu.*/
void menuMatriculas(){
int op;
//Matricula *matricula=obtenerMatriculas();

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

/*cabecera: void obtenerMatriculas()
precondicion:
postcondicion:*/
obtenerMatriculas(){
fflush(stdin);
}

/*cabecera: void listarMatriculas()
precondicion:
postcondicion: */
void listarMatriculas(){
fflush(stdin);
}

/*cabecera: void menuMatriculas()
precondicion: Ser llamado por el usuario
postcondicion: Mostrar menu.*/
void cabioMatriculas(){
fflush(stdin);
}

/*cabecera: void nuevaMatriculas()
precondicion:
postcondicion: */
void nuevaMatriculas(){
fflush(stdin);
}

/*cabecera: void eliminarMatriculas()
precondicion:
postcondicion: */
void eliminarMatriculas(){
fflush(stdin);
}






}
