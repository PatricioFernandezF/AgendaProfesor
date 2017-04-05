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
}
return 0;}

/*cabecera: void altaMaterias()
precondicion:
postcondicion:      */
void altaMaterias(Materia* materia){

Materia mat;
mat.nombre;
mat.abreviatura;

printf("Indique el nombre de la materia a dar de alta: \n");
    fgets(mat.id_mat, 51, stdin);

printf("Indique la abreviatura de la materia: \n");
    fgets(mat.abreviatura, 4, stdin);

}

/*cabecera: altaMaterias()
precondicion:
postcondicion:      */
void bajaMaterias(Materia* materia){
Materia mat;
mat.nombre;

listarMaterias();
printf("Indique el nombre de la materia a dar de baja: \n");
fgets(mat.id_mat, 51, stdin);

}

/*cabecera: bajaMaterias()
precondicion:
postcondicion:      */
void modificarMaterias(Materia* materia){
Materia mat;
mat.nombre;
mat.abreviatura;

listarMaterias();
printf("Indique el nombre de la materia a modificar: \n");
    fgets(mat.id_mat, 51, stdin);

printf("Indique la abreviatura de la materia: \n");
    fgets(mat.abreviatura, 4, stdin);
}

/*cabecera: modificarMaterias()
precondicion:
postcondicion:      */
void listarMaterias(Materia* materia){
Materia mat;
mat.nombre;
mat.abreviatura;



}

