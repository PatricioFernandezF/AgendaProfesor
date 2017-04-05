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
    char hora[10];
    char descripcion[31];
    char estado_falta[17];
    char id_alumno[7];
}Falta;

typedef struct{
    char id_profesor[4];
    char dia[3];
    char hora[10];
    char id_materia[5];
    char grupo[11];
}Horario;


//Funciones

Usuario* obtenerUsuarios(int *n);
Alumno* obtenerAlumnos(int *n);
Materia* obtenerMaterias(int *n);
Matricula* obtenerMatriculas(int *n);
Calificacion* obtenerCalificaciones(int *n);
Falta* obtenerFaltas(int *n);
Horario* obtenerHorarios(int *n);
Usuario loguear(char* logUsuario, char* passUsuario);
void guardarDatosAlumno(Alumno* alumnos, int elementos);
void guardarDatosMateria(Materia* materias, int elementos);
void guardarDatosMatricula(Matricula* matriculas, int elementos);
void guardarDatosCalificaciones(Calificacion* calificaciones, int elementos);
void guardarDatosFaltas(Falta* faltas, int elementos);
void guardarDatosHorarios(Horario* horarios, int elementos);

#endif	/* FICHERO_H */
