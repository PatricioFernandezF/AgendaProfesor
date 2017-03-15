#ifndef FICHERO_H
#define	FICHERO_H

// TIPOS
typedef struct{
    char id_usuario[3];
    char nombre[20];
    char perfil[14];
    char login[5];
    char pass[8];
}Usuario;

typedef struct{
    char id_alumno[6];
    char nombre[20];
    char direccion[30];
    char localidad[30];
    char curso[30];
    char grupo[10];
}Alumno;

typedef struct{
    char id_materia[4];
    char nombre[50];
    char abreviatura[3];
}Materia;

typedef struct{
    char id_materia[4];
    char id_alumno[6];
}Matricula;

typedef struct{
    char fecha[8];
    char descripcion[30];
    char id_materia[4];
    char id_alumno[6];
    int calificacion;
}Calificacion;

typedef struct{
    char fecha[8];
    int hora;
    char descripcion[30];
    char estado_falta[17];
    char id_alumno[6];
}Falta;

typedef struct{
    char id_profesor[3];
    int dia;
    int hora;
    char id_materia[4];
    char grupo[10];
}Horario;

/*

Equipo* obtenerEquipos();
Jugador* obtenerJugadores();
Usuario* obtenerUsuarios();
Plantilla* obtenerPlantillas();
Jug_plan* obtenerJugadoresPlantillas();
Conf* obtenerConfiguraciones();
void guardarDatosEquipo(Equipo* equipos, int elementos);
void guardarDatosJugadores(Jugador* jugadores, int elementos);
void guardarDatosUsuario(Usuario* usuarios, int elementos);
void guardarDatosPlantilla(Plantilla* plantillas, int elementos);
void guardarDatosJugadorPlantilla(Jug_plan* jug_plan, int elementos);
void guardarDatosConf(Conf* conf, int elementos);
int nUsuarios();
int nEquipos();
int nJugadores();
int nPlantillas();
int nJugPlants();
*/

#endif	/* FICHERO_H */
