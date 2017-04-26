#include "materias.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

void altaMaterias(Materia *materia, int n);
void bajaMaterias(Materia *materia, int n);
void modificarMaterias(Materia *materia, int n);
void listarMaterias(Materia *materia, int n);



/*cabecera: void menuMaterias()
precondicion: Ser llamado por el usuario
postcondicion: Mostrar menu.*/
void menuMaterias(){
int op;
int n;
Materia *materia=obtenerMaterias(&n);

do{
    printf("Operaciones disponibles: \n 1.-Alta Materias.\n 2.-Baja Materias.\n 3.-Modificar Materias.\n 4.-Listar Materias.\n 5.-Salir.\n");
    do{
        printf("Introduzca la operacion a realizar: ");
        scanf("%d",&op);
        }while(op<1 || op>5);
        if (op==1) altaMaterias(materia,n);
        if (op==2) bajaMaterias(materia,n);
        if (op==3) modificarMaterias(materia,n);
        if (op==4) listarMaterias(materia,n);
}while(op=!5);
}


/*cabecera: void altaMaterias()
precondicion:
postcondicion:      */
void altaMaterias(Materia *materia, int n){

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
void bajaMaterias(Materia *materia, int n){
Materia mat;
mat.nombre;

listarMaterias(&materia, n);
printf("\nIndique el nombre de la materia a dar de baja: ");
fgets(mat.nombre, 51, stdin);

}

/*cabecera: bajaMaterias()
precondicion:
postcondicion:      */
void modificarMaterias(Materia *materia, int n){
Materia mat;
mat.nombre;
mat.abreviatura;

listarMaterias(&materia, n);
printf("\nIndique el nombre de la materia a modificar: ");
    fgets(mat.nombre, 51, stdin);

printf("\nIndique la abreviatura de la materia: ");
    fgets(mat.abreviatura, 4, stdin);
}

/*cabecera: modificarMaterias(Materia *materia, int n)
precondicion: Puntero a materia y entero con el numero de elementos del vector.
postcondicion: No devuelve nada, imprime por pantalla la lista de materias. */
void listarMaterias(Materia *materia, int n){

int i;
    printf("\nID\tMATERIA\n\n");

for(i=0;i<n;i++){
    printf("%s\t%s\n",materia[i].id_materia, materia[i].nombre);

}
printf("\n\nFIN DE LISTA\n\n");
}

