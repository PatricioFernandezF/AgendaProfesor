#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"

/*Jordi*/

void alta_usuario(Usuario *usuario, int n);
void baja_usuario(Usuario *usuario, int n);
void modificar_usuario(Usuario *usuario, int n);
void listar_usuario(Usuario *usuario, int n);
void menu_usuario();

// Cabecera: void alta_usuario(Usuario *usuario, entero n)
// Precondicion: Recibe un vector con elementos de tipo usuario y el número de elemento del mismo
// Poscondicion: Añade un nuevo elemento al vector
void alta_usuario(Usuario *usuario, int n)
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
// Cabecera: void baja_usuario(Usuario *usuario, entero n)
// Precondicion: Recibe un vector con elementos de tipo usuario y el número de elemento del mismo
// Poscondicion: Elimina un usuario del vector
void baja_usuario(Usuario *usuario, int n)
{
    int num;
    
    listar_usuario(&usuario);
    printf("Indica que usuario desea dar de baja:");
    scanf("%d",&num);
    
}
// Cabecera: void modificar_usuario(Usuario *usuario, entero n)
// Precondicion: Recibe un vector con elementos de tipo usuario y el número de elemento del mismo
// Poscondicion: Modifica los datos de un usuario que se elige 
void modificar_usuario(Usuario *usuario, int n)
{
    int numOpc, opc,i;
    char numUser[4];
    
    listar_usuario(usuario);
    printf("Inidica que usuario desea modificar:");
    fgets (numUser, 4, stdin);
    
    i=0;
    while(i<n || !strcmp(usuario[i].id_usuario,numUser)) i++;
    
    do{
        printf("Injdica que dato desea modificar:"
            "\n1)Nombre\n2)Perfil\n3)Login\n4)Pass");
        scanf("%d",&numOpc);
        switch(numOpc){
            case 1:
                printf("Introduce el nombre del usuario (20 cáracteres):");
                fgets (usuario[i].nombre, 21, stdin);
                break;

            case 2:
                printf("Selecciona el tipo de usuario:\n1)Administrador\n2)Profesor\nPerfil:");
                do{
                    switch(opc){
                        case 1:
                            strcpy("administrador",usuario[i].perfil);
                            break;
                        case 2:
                            strcpy("profesor",usuario[i].perfil);
                            break;
                    }
                }while(opc!=1 || opc!=2);
                break;

            case 3:
                printf("Introduce un nombre de usuario (5 cáracteres):");
                fgets (usuario[i].login, 6, stdin);
                break;

            case 4:
                printf("Introduce una contraseña (8 cáracteres):");
                fgets (usuario[i].pass, 9, stdin);
                break;
            
            default:
                printf("\nOpción no valida\n");
        }
    }while(numOpc<1 || numOpc>4);
    
}
// Cabecera: void listar_usuario(Usuario *usuario, entero n)
// Precondicion: Recibe un vector con elementos de tipo usuario y el número de elemento del mismo
// Poscondicion: Muestra los usuarios que hay en el vector
void listar_usuario(Usuario *usuario, int n)
{
    int i;
    
    printf("ID\tNombre\n");
    
    for(i=0; i<n; i++){
        printf("%d) %s\n",usuario[i].id_usuario,usuario[i].nombre);
    }
    printf("---Fin de lista---");
}
// Cabecera: void menu_usuario()
// Precondicion: No recibe nada
// Poscondicion: Muestra las operaciones a realizar con los usuarios del sistema
void menu_usuario()
{
    int x,n;
    Usuario *usuario=obtenerUsuarios(&n);
    
    do
    {
        printf("Introduzca la opcion que desea\n\n 1: Dar de alta un usuario\n 2: Dar de baja a un usuario\n 3: Modificar un usuario\n 4: Listar un usuario\n 0: salir\n");
        scanf("%d",&x);
        switch (x)
        {
        case 0:
            exit(0);
        case 1:
            alta_usuario(usuario,n);
            menu_usuario();
            break;
        case 2:
            baja_usuario(usuario,n);
            menu_usuario();
            break;
        case 3:
            modificar_usuario(usuario,n);
            menu_usuario();
            break;
        case 4:
            listar_usuario(usuario,n);
            menu_usuario();
            break;
        default:
            printf("Error al elegir la opcion.\t");
            break;
        }
    }while(x!=0);
    
    guardarDatosUsuario(usuario,n);
            
}
