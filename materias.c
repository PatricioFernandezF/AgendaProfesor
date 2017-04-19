#include "materias.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

void altaMaterias(Materia *materia);
void bajaMaterias(Materia *materia);
void modificarMaterias(Materia *materia);
void listarMaterias(Materia *materia);



/*cabecera: void menuMaterias()
precondicion: Ser llamado por el usuario
postcondicion: Mostrar menu.*/
void menuMaterias(){
int op;
Materia *materia;

do{
    printf("Operaciones disponibles: \n 1.-Alta Materias.\n 2.-Baja Materias.\n 3.-Modificar Materias.\n 4.-Listar Materias.\n 5.-Salir.\n");
    do{
        printf("Introduzca la operacion a realizar: ");
        scanf("%d",&op);
        }while(op<1 || op>5);
        if (op==1) altaMaterias(materia);
        if (op==2) bajaMaterias(materia);
        if (op==3) modificarMaterias(materia);
        if (op==4) listarMaterias(materia);
}while(op=!5);
}


/*cabecera: void altaMaterias()
precondicion:
postcondicion:      */
void altaMaterias(Materia* materia){

Materia mat;
mat.nombre;
mat.abreviatura;

printf("\nIndique el nombre de la materia a dar de alta: ");
    fgets(mat.nombre, 51, stdin);

printf("\nIndique la abreviatura de la materia: \n");
    fgets(mat.abreviatura, 4, stdin);

}

/*cabecera: altaMaterias()
precondicion:
postcondicion:      */
void bajaMaterias(Materia* materia){
Materia mat;
mat.nombre;

listarMaterias(&materia);
printf("\nIndique el nombre de la materia a dar de baja: ");
fgets(mat.nombre, 51, stdin);

}

/*cabecera: bajaMaterias()
precondicion:
postcondicion:      */
void modificarMaterias(Materia* materia){
Materia mat;
mat.nombre;
mat.abreviatura;

listarMaterias(&materia);
printf("\nIndique el nombre de la materia a modificar: ");
    fgets(mat.nombre, 51, stdin);

printf("\nIndique la abreviatura de la materia: ");
    fgets(mat.abreviatura, 4, stdin);
}

/*cabecera: modificarMaterias()
precondicion:
postcondicion:      */
void listarMaterias(Materia* materia){


int i,n;
    printf("\nID\tMATERIA");
for(i=0;i==n;i++){
    printf("%d\t%s\n",materia->id_materia, materia->nombre);
}
printf("\n\nFIN DE LISTA\n\n");

}

