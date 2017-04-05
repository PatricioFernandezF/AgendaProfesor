#include "materias.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

void altaMaterias(Materia *materia);
void bajaMaterias(Materia *materia);
void modificarMaterias(Materia *materia);
void listarMaterias(Materia *materia);

int mainMaterias(){

/*cabecera: void menuMaterias()
precondicion: Ser llamado por el usuario
postcondicion: Mostrar menu.*/
void menuMaterias(){
int op;
Materia *materia;

do{
    printf("Introduzca la operacion a realizar:\n 1.-Alta Materias.\n 2.-Baja Materias.\n 3.-Modificar Materias.\n 4.-Listar Materias.\n 5.-Salir.\n");
    do{
        printf("Introduzca la operacion a realizar: \n");
        scanf("%d",&op);
        }while(op<1 || op>5);
        if (op==1) altaMaterias(materia);
        if (op==2) bajaMaterias(materia);
        if (op==3) modificarMatriculas(materia);
        if (op==4) eliminarMatriculas(materia);
}while(op=!5);
return;
}

/*cabecera: void obtenerMaterias()
precondicion:
postcondicion:      */
void obtenerMaterias(Materia* materia){

/*strcpy(nuevoMateria.id_materia)
Materia nuevoMateria;
nuevoMateria.id_materia="123";
nuevoMateria.nombre="hola";
nuevoMateria.abreviatura="abc";*/
}

/*cabecera: void altaMaterias()
precondicion:
postcondicion:      */
void altaMaterias(Materia* materia){
}

/*cabecera: altaMaterias()
precondicion:
postcondicion:      */
void bajaMaterias(Materia* materia){
}

/*cabecera: bajaMaterias()
precondicion:
postcondicion:      */
void modificarMaterias(Materia* materia){
}

/*cabecera: modificarMaterias()
precondicion:
postcondicion:      */
void listarMaterias(Materia* materia){


}
return 0;}
