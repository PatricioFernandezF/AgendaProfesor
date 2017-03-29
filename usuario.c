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
void alta_usuario(Usuario* usuario)
{
}
// Cabecera: void baja_usuario(Usuario*)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion:
void baja_usuario(Usuario* usuario)
{
}
// Cabecera: void modificar_usuario(Usuario*)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion:
void modificar_usuario(Usuario* usuario)
{
}
// Cabecera: void listar_usuario(Usuario*)
// Precondicion: Recibe una cadena de caracteres de un usuario.
// Poscondicion:
void listar_usuario(Usuario* usuario)
{
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
        }while(x!=0)
    }
}
