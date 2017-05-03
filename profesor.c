#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "profesor.h"
#include "fichero.h"

void menu_profesor(int idProf);
void seleccionar_grupos_dia(Horario *lista, int idProf);
void seleccionar_alumno_grupo(Horario *lista);
int dia_semana();

// Cabecera: void menu_profesor(E entero idProf)
// Precondicion:   id del profesor que ha accedido al sistema
// Poscondicion: Muestra el menú de opciones y acceso de un usuario o profesor 
void menu_profesor(int idProf){
    
    char grupoSel[11]="";
    int posGrup,x;
    
    do
        {
            printf("Introduzca la opcion que desea\n\n "
                    "1: Seleccionar grupo\n "
                    "2: Mostrar alumnos del grupo %s\n "
                    "0: salir\n",grupoSel);
            scanf("%d",&x);
            switch (x)
            {
            case 0:
                exit(0);
            case 1:
                strcpy(grupoSel,seleccionar_grupos_dia(lista,idProf));
                menu_profesor(idProf);
                break;
            case 2:
                seleccionar_alumno_grupo(alumnos,grupoSel);
                break;
            default:
                printf("Error al elegir la opcion.\t");
                break;
            }
        }while(x!=0);
}

// Cabecera: void seleccionar_grupos_dia(hrario lista*, caracter idProf)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion: Retorna el nombre del grupo elegido
char seleccionar_grupos_dia(Horario *lista, char idProf){
    
    int i,elementos,dia,posGrup;
    char grupoNom[11],d[3];
    
    dia=dia_semana();
    if(dia<1 || dia>5)
    {
        printf("Descansa, estamos en fin de semana.\n");
    }
    else{
        d=dia+'0';
        printf("Nº\tGrupo\n");
        
        for(i=0; i<elementos;i++){
            if(strcmp(idProf,lista[i].id_profesor) && strcmp(d,lista[i].dia)){
                printf("%d\t%s\n",i,lista.grupo);
            }
        }

        printf("---Fin de lista---\n\n");

        printf("Indica que grupo desea seleccionar:");
        scanf("%d",posGrup);
        
        strcpy(grupoNom,lista[posGrup]);
    }
    
    return grupoNom;
}

// Cabecera: void seleccionar_alumno_grupo(Alumno*, caracter posGrup)
// Precondicion: Recibe la lista de alumnos y el nombre del grupo que se quiere listar.
// Poscondicion:  Muestra por pantalla los alumnos   
void seleccionar_alumno_grupo(Alumno *lista, char posGrup){
    
    int elementos,i;
    char dni[7];
    
    printf("Nº\tDNI\tNombre\n");
        
        for(i=0; i<elementos;i++){
            if(strcmp(posGrup,lista[i].grupo)){
                printf("%d)\t%d\t%s\n",i,lista[i].id_alumno,lista[i].nombre);
            }
        }
        printf("---Fin de lista---\n\n");

        printf("Indica que dni desea seleccionar:");
        fgets (dni, 7, stdin);
        
        
}

// Cabecera: int dia_semana()
// Precondicion: No recibe nada 
// Poscondicion: Retorna el número del día de la semana
int dia_semana(){
    
    //Declaracion de vectores y variables
    int regular[]={0,3,3,6,1,4,6,2,5,0,3,5};
    int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
    int d,m,a;

    int result1,result2,result3,result4,result5;
    
    time_t sisTime; 	//time_t es un typedef, asigno una varible de este tipo (sisTime);
    struct tm *tiempo;	//Creo un puntero a la estructura tm, (ya definida en time.h).

    time(&sisTime);		//time obtiene el tiempo del sistema y se lo pasa a la direccion de sisTime.
    tiempo=localtime(&sisTime);
    //Convierte los valores de sisTime a compatibles con la estructura tm y luego asigno ese valor a tiempo.

    //Una estructura tm, esta compuesta por datos de tipo int (vean la seccion de time.h)

    d=tiempo.tm_mday;		//accedo al valor de dia de la estructura tm y se la asigno a dia
    m=tiempo.tm_mon;		//accedo a mes de la estrutura tm y se la asigno a mes
    a=(tiempo.tm_year)+1900;	//year es un contador a partir de 1900.

    //comprobamos primero si el año es bisiesto o es regular
    //si es bisiesto, asignamos a m la posición del vector bisiesto -1
    //si es regular, asignamos a m la posición del vector regular -1

    if((a%4==0) && !(a%100==0))
    {
        m=bisiesto[m-1];
    }
    else if (a%400==0)
    {
        m=bisiesto[m-1];
    }
    else
    {
        m=regular[m-1];
    }

    //Resolvermos la fórmula poco a poco

    result1=(a-1)%7;
    result2=(a-1)/4;
    result3=(3*(((a-1)/100)+1))/4;
    result4=(result2-result3)%7;
    result5=d%7;
    d=(result1+result4+m+result5)%7;
    
    return d;
}