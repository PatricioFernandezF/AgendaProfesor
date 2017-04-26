#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fichero.h"
#include "usuario.h"
#include "fichas.h"

void menuFaltas();
    int n, id;
    char o;
    bool r = true;

    printf("Indica el id del alumno del que desea ver la ficha:");
    scanf("%d", &id);
    Alumno* mostrarFicha(alumno);

    do{
        printf("¿Desea modificar sus datos? s/n");
        scanf("%s", &o);
        if (o == 's'){
            void modificarFicha (alumno);
        }else{
            r == false;
        }
    }while (o!='s' || o!='n');


Alumno* mostrarFicha(Alumno* alumno){
    Alumno al;

    listar_alumno(&alumno);
    printf("Indica el alumno del que desea modificar los datos:");
    scanf("%s", &al.id_alumno);

}
