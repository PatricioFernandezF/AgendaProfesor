#include<stlib>

void modificar_alumno(Alumno* alumno)
{
    int x;
    Alumno*alumno;
    do
    {
        printf("Introduzca la opcion que desea\n\n 1: Lista de materias\n 2: Cambios de matricula\n 3: eliminar matricula\n 4: Crear una nueva matricula\n 0: salir\n");
        scanf("%d",&x);
        switch (x)
        {
        case 0:
            exit(0);
        case 1:
            lista_de_materias(alumno);
            break;
        case 2:
            cambios_de_matricula(alumno);
            break;
        case 3:
            eliminar_matricula(alumno);
            break;
        case 4:
            crear_nueva_matricula(alumno);
            break;
        default:
            printf("Error al elegir la opcion.\t");
            break;
        }while(x!=0)
    }
}
