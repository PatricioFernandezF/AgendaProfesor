#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profesor.h"
#include "fichero.h"

int main()
{
    Usuario L_Usuario[1];
    char login[6], pass[9], perfil[15];
    int elementos, exisUser=0, passOK=0, errorPass=0, i, id;
    
    printf("BIENVENIDO AL CUADERNO DEL PROFESOR\n");
        
    do{
        printf("Introduce nombre de usuario:\n");
        fgets (login, 6, stdin);

        /*Conmrpobamos con el array de usuarios la existencia del usuario, en caso contrario error*/
        i=0;
        while(i<elementos || exisUser==0){
            if(strcmp(login,L_Usuario[i].login)){
                exisUser=1;
                strcpy(L_Usuario[i].perfil,perfil);
            }
        }

        if(exisUser==0){
            printf("\nError el alumno no indicado no existe\n");
        }
    }while(exisUser==0);
    
    do{
        printf("Introduce el password:\n");
        fgets (pass, 9, stdin);
        
        /*Conmrpobamos con el array de usuarios si la contraseña, en caso contrario error*/
        i=0;
        while(i<elementos || passOK==0){
            if(strcmp(pass,L_Usuario[i].pass)){
                passOK=1;
                id=L_Usuario[i].id_usuario;
            }
        }

        if(passOK==0){
            printf("\nError contraseña erronea\n");
            errorPass++;
            printf("Te quedan %d intentos.\n"3-errorPass);
        }
    }while(passOK==0 && errorPass<3);
    
    if(passOK==1 && exisUser==1){
        menu_principal(strcmp(perfil,"administrador"),id);
    }
    
    return 0;
}

// Cabecera: void menu_principal(E entero opc, E entero id)
// Precondicion: Valor 1 para administrados, valor <> 1 para usuario
// Poscondicion:  Accede a los distintos menus de la aplicación, no retorna nada
void menu_principal(int opc, int id)
{
    int x;
    
    if(opc=1){
        do
        {
            printf("Introduzca la opcion que desea\n\n "
                    "1: Menú usuarios\n "
                    "2: Menú alumnos\n "
                    "3: Menú materias\n "
                    "4: Menú horarios\n "
                    "0: salir\n");
            scanf("%d",&x);
            switch (x)
            {
            case 0:
                exit(0);
            case 1:
                alta_usuario(usuario);
                break;
            case 2:
                baja_usuario(usuario);
                break;
            case 3:
                modificar_usuario(usuario);
                break;
            case 4:
                listar_usuario(usuario);
                break;
            default:
                printf("Error al elegir la opcion.\t");
                break;
            }
        }while(x!=0);
    }
    else{
        menu_profesor(id);
    }
}

