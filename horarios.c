/*Angel*/
#include "horarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"


void anadirHorarios(Horario *horario, int n);
void eliminarHorarios(Horario *horario, int n);
void modificarHorarios(Horario *horario, int n);
void listarHorarios(Horario *horario, int n);


/*cabecera: void menuHorarios()
precondición: Ser llamado por el usuario.
postcondición: Mostrar menu.*/
void menuHorarios(){
    int op;
    int n;
    Horario *horario=obtenerHorarios(&n);

    do{
        printf("\n 1.- Anadir Horarios.\n 2.- Eliminar Horarios.\n 3.- Modificar Horarios.\n 4.- Listar Horarios.\n 5.- Salir del Programa.\n");

        do{
            printf("Introduzca la operacion a realizar: ");
            scanf("%d", &op);
        }while(op<1 || op>5);

        switch(op){
            case 1: anadirHorarios(horario,n);
                    break;
            case 2: eliminarHorarios(horario,n);
                    break;
            case 3: modificarHorarios(horario,n);
                    break;
            case 4: listarHorarios(horario,n);
                    break;
        }
    }while(op!=5);
}

/*cabecera: void anadirHorarios(Horario *horario, int n)
precondición: Recibe un puntero a horarios y un entero.
postcondición: No devuelve nada. Añade una linea al fichero horarios. */
void anadirHorarios(Horario *horario, int n){
Horario hor;

printf("Introduzca el profesor para esa hora: \n");
fflush(stdin);
fgets(hor.id_profesor, 3, stdin);
printf("Introduzca el dia para esa hora: \n");
fflush(stdin);
fgets(hor.dia, 2, stdin);
printf("Introduzca la hora para esa hora: \n");
fflush(stdin);
fgets(hor.hora, 9, stdin);
printf("Introduzca la materia para esa hora: \n");
fflush(stdin);
fgets(hor.id_materia, 4, stdin);
printf("Introduzca el grupo de clase: \n");
fflush(stdin);
fgets(hor.grupo, 10, stdin);

guardarDatosHorarios();
}

/*cabecera: void eliminarHorarios(Horario *horario, int n)
precondición: Recibe un puntero a horario y un entero n.
postcondición: No devuelve nada. Elimina una linea del fichero horarios. */
void eliminarHorarios(Horario *horario, int n){

    int id,i;
    listarHorarios(&horario, n);
    printf("Introduce el id a eliminar");
    scanf("%i",id);

    Horario aux[n];
    id-=1;

    for(i=0;i<n;i++){
        if(i<id){
            aux[i]=horario[i];
        }
        else if(i==id){}
        else{
            aux[i-1]=horario[i];
        }
    }
    guardarDatosHorarios(aux,n);
}

/*cabecera: void modificarHorarios(Horario *horario, int n)
precondición: Recibe un puntero a horario y un entero n.
postcondición: No devuelve nada. Modifica alguna linea del fichero horarios. */
void modificarHorarios(Horario *horario, int n){
listarHorarios(&horario, n);
}

/*cabecera: void listarHorarios(Horario *horario, int n)
precondición: Puntero a materia y entero con el numero de elementos del vector.
postcondición: No devuelve nada, imprime por pantalla la lista de horarios. */
void listarHorarios(Horario *horario, int n){

int i;
    printf("\nID ID_PROF\tDIA\tHORA\tID_MATERIA\tGRUPO\n\n");

for(i=0;i<n;i++){
    printf("%i %s\t%s\t%s\t%s\t\t%s\t\n",i+1,
           horario[i].id_profesor, horario[i].dia, horario[i].hora, horario[i].id_materia, horario[i].grupo);

}
printf("\n\nFIN DE LISTA\n\n");

}

