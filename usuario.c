#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"

void alta_usuario(Usuario*);
void baja_usuario(Usuario*);
void modificar_usuario(Usuario*);
void listar_usuario(Usuario*);
void menu_usuario();

// Cabecera: void alta_usuario(Usuario*)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion:
void alta_usuario(Usuario *usuario)
{
    int opc=0;
    
    Usuario newUser;
    
    printf("Introduce el nombre del usuario (20 cáracteres):");
    fgets (newUser.nombre, 21, stdin);
     
    do{
        printf("Selecciona el tipo de usuario:\n1)Administrador\n2)Profesor\nPerfil:");
        scanf("%d",&opc);
        
        switch(opc){
            case 1:
                strcpy("administrador",newUser.perfil);
                break;
            case 2:
                strcpy("profesor",newUser.perfil);
                break;
            default:
                printf("\nOpción no valida\n");
        }
    }while(opc!=1 || opc!=2);
    printf("Introduce un nombre de usuario (5 cáracteres):");
    fgets (newUser.login, 6, stdin);
    
    printf("Introduce una contraseña (8 cáracteres):");
    fgets (newUser.pass, 9, stdin);
    
    printf("\n\nDatos intorucidos en la ficha.\nLos datos introducidos son:\n");
    printf("Nombre: %s\n",newUser.nombre);
    printf("Perfil: %s\n",newUser.perfil);
    printf("Login %s\n",newUser.login);
    printf("Pass: %s\n",newUser.pass);
    
    //Priceso para añadir al vector el usuario de nueva creación
    printf("\n\nAñadido a la lista de usuarios.");
    
    
}
// Cabecera: void baja_usuario(Usuario*)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion:
void baja_usuario(Usuario *usuario)
{
    int num;
    
    listar_usuario(&usuario);
    printf("Indica que usuario desea dar de baja:");
    scanf("%d",&num);
    
}
// Cabecera: void modificar_usuario(Usuario*)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion:
void modificar_usuario(Usuario *usuario)
{
    int numUser, numOpc, opc;
    char cadena[50];
    
    listar_usuario(&usuario);
    printf("Inidica que usuario desea modificar:");
    scanf("%d",&numUser);
    
    do{
        printf("Injdica que dato desea modificar:"
            "\n1)Nombre\n2)Perfil\n3)Login\n4)Pass");
        scanf("%d",&numOpc);
        switch(numOpc){
            case 1:
                printf("Introduce el nombre del usuario (20 cáracteres):");
                fgets (newUser.nombre, 21, stdin);
                break;

            case 2:
                printf("Selecciona el tipo de usuario:\n1)Administrador\n2)Profesor\nPerfil:");
                do{
                    switch(opc){
                        case 1:
                            strcpy("administrador",newUser.perfil);
                            break;
                        case 2:
                            strcpy("profesor",newUser.perfil);
                            break;
                    }
                }while(opc!=1 || opc!=2);
                break;

            case 3:
                printf("Introduce un nombre de usuario (5 cáracteres):");
                fgets (newUser.login, 6, stdin);
                break;

            case 4:
                printf("Introduce una contraseña (8 cáracteres):");
                fgets (newUser.pass, 9, stdin);
                break;
            
            default:
                printf("\nOpción no valida\n");
        }
    }while(numOpc<1 || numOpc>4);
    
}
// Cabecera: void listar_usuario(Usuario*)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion:
void listar_usuario(Usuario *usuario)
{
    int i, elemento;
    
    printf("ID\tNombre\n");
    
    for(i=0; i<elemento; i++){
        printf("%d) %s\n",usuario->id_usuario,usuario->nombre);
    }
    printf("---Fin de lista---");
}
// Cabecera: void menu_usuario()
// Precondicion:
// Poscondicion:
void menu_usuario()
{
    int x;
    Usuario*usuario;
    do
    {
        printf("Introduzca la opcion que desea\n\n 1: Dar de alta un usuario\n 2: Dar de baja a un usuario\n 3: Modificar un usuario\n 4: Listar un usuario\n 0: salir\n");
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
