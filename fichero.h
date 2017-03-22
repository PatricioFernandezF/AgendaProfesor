#ifndef FICHERO_H
#define	FICHERO_H

// TIPOS
typedef struct{
    char id_usuario[4];
    char nombre[21];
    char perfil[15];
    char login[6];
    char pass[9];
}Usuario;

typedef struct{
    char id_alumno[7];
    char nombre[21];
    char direccion[31];
    char localidad[31];
    char curso[31];
    char grupo[11];
}Alumno;

typedef struct{
    char id_materia[5];
    char nombre[51];
    char abreviatura[4];
}Materia;

typedef struct{
    char id_materia[5];
    char id_alumno[7];
}Matricula;

typedef struct{
    char fecha[10];
    char descripcion[31];
    char id_materia[5];
    char id_alumno[7];
    int calificacion;
}Calificacion;

typedef struct{
    char fecha[10];
    int hora;
    char descripcion[31];
    char estado_falta[17];
    char id_alumno[7];
}Falta;

typedef struct{
    char id_profesor[4];
    int dia;
    int hora;
    char id_materia[5];
    char grupo[11];
}Horario;


//Funciones

Usuario* obtenerUsuarios();
Alumno* obtenerAlumnos();
Materia* obtenerMaterias();
Matricula* obtenerMatriculas();
Calificacion* obtenerCalificaciones();
Falta* obtenerFaltas();
Horario* obtenerHorarios();
Usuario loguear(char* logUsuario, char* passUsuario);
int nUsuarios();
int nAlumnos();
int nMaterias();
int nMatriculas();
int nCalificaciones();
int nFaltas();


#endif	/* FICHERO_H */
