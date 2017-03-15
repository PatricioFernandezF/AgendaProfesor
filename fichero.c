#include "fichero.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// CONSTANTES
int N_USUARIOS = 0;
int N_ALUMNOS = 0;
int N_MATERIAS = 0;
int N_MATRICULAS = 0;
int N_CALIFICACIONES = 0;
int N_FALTAS = 0;
int N_HORARIOS = 0;

Usuario obtenerUsuario(char *cadena){
    Usuario u;
    sscanf(cadena,"%s-%s-%s-%s-%s", u.id_usuario, u.nombre,u.perfil,u.login,u.pass);
    return u;
}

Alumno obtenerAlumno(char *cadena){
    Alumno a;
    sscanf(cadena,"%s-%s-%s-%s-%s-%s", a.id_alumno,a.nombre,a.direccion,a.localidad,a.curso,a.grupo);
    return a;
}

Materia obtenerMateria(char *cadena){
    Materia m;
    sscanf(cadena,"%s-%s-%s", m.id_materia, m.nombre,m.abreviatura);
    return m;
}

Matricula obtenerMatricula(char* cadena){
    Matricula m;
    sscanf(cadena,"%s-%s", m.id_materia,m.id_alumno);
    return m;
}

Calificacion obtenerCalificacion(char* cadena){
    Calificacion c;
    sscanf(cadena,"%s-%s-%s-%s-%s", c.fecha,c.descripcion,c.id_materia,c.id_alumno,c.calificacion);
    return c;
}

Falta obtenerFalta(char* cadena){
    Falta f;
    sscanf(cadena,"%s-%d-%s-%s-%s", f.fecha,&f.hora,f.descripcion,f.estado_falta,f.id_alumno);
    return f;
}

Horario obtenerHorario(char* cadena){
    Horario h;
    sscanf(cadena,"%s-%d-%d-%s-%s", h.id_profesor,&h.dia,&h.hora,h.id_materia,h.grupo);
    return h;
}
// FUNCIONES PUBLICAS


// Cabecera: Usuario* obtenerUsuarios()
// Precondicion:
// Poscondicion:
Usuario* obtenerUsuarios(){
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "r");
    char c;
    char *cadena = (char*) calloc(1,sizeof(char));
    int contadorChar = 0;
    Usuario *e = (Usuario*) calloc(1,sizeof(Usuario));
    while((c = fgetc(FICHERO_USUARIO))!=EOF){
        if(c == '\n'){
            N_USUARIOS++;
            e = (Usuario*) realloc(e, N_USUARIOS*sizeof(Usuario));
            cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
            cadena[contadorChar] = '\0';
            e[N_USUARIOS-1] = obtenerUsuario(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_USUARIOS++;
    e = (Usuario*) realloc(e, N_USUARIOS*sizeof(Usuario));
    cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
    cadena[contadorChar] = '\0';
    e[N_USUARIOS-1] = obtenerUsuario(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_USUARIO);
    return e;
}

// Cabecera: Jugador* obtenerJugadores()
// Precondicion:
// Poscondicion:
Alumno* obtenerAlumnos(){
    FILE *FICHERO_ALUMNO = fopen("alumnos.txt", "r");
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Alumno *j = (Alumno*) malloc(sizeof(Alumno));
    while((c = fgetc(FICHERO_ALUMNO))!=EOF){
        if(c == '\n'){
            N_ALUMNOS++;
            j = (Alumno*) realloc(j, N_ALUMNOS*sizeof(Alumno));
            j[N_ALUMNOS-1] = obtenerAlumno(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_ALUMNOS++;
    j = (Alumno*) realloc(j, N_ALUMNOS*sizeof(Alumno));
    j[N_ALUMNOS-1] = obtenerAlumno(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_ALUMNO);
    return j;
}

// Cabecera: Usuario* obtenerUsuarios()
// Precondicion:
// Poscondicion:
Materia* obtenerMaterias(){
    FILE *FICHERO_MATERIA = fopen("materias.txt", "r");
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Materia *u = (Materia*) malloc(sizeof(Materia));
    while((c = fgetc(FICHERO_MATERIA))!=EOF){
        if(c == '\n'){
            N_MATERIAS++;
            u = (Materia*) realloc(u, N_MATERIAS*sizeof(Materia));
            u[N_MATERIAS-1] = obtenerMateria(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_MATERIAS++;
    u = (Materia*) realloc(u, N_MATERIAS*sizeof(Materia));
    u[N_MATERIAS-1] = obtenerMateria(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_MATERIA);
    return u;
}

// Cabecera: Plantilla* obtenerPlantillas()
// Precondicion:
// Poscondicion:
Matricula* obtenerMatriculas(){
    FILE *FICHERO_MATRICULA = fopen("matriculas.txt", "r");
    char c;
    char *cadena = (char*) calloc(1,sizeof(char));
    int contadorChar = 0;
    Matricula *p = (Matricula*) calloc(1,sizeof(Matricula));
    while((c = fgetc(FICHERO_MATRICULA))!=EOF){
        if(c == '\n'){
            N_MATRICULAS++;
            p = (Matricula*) realloc(p, N_MATRICULAS*sizeof(Matricula));
            cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
            cadena[contadorChar] = '\0';
            p[N_MATRICULAS-1] = obtenerMatricula(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_MATRICULAS++;
    p = (Materia*) realloc(p, N_MATRICULAS*sizeof(Matricula));
    cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
    cadena[contadorChar] = '\0';
    p[N_MATRICULAS-1] = obtenerMatricula(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_MATRICULA);
    return p;
}

// Cabecera: Plantilla* obtenerPlantillas()
// Precondicion:
// Poscondicion:
Calificacion* obtenerCalificaciones(){
    FILE *FICHERO_CALIFICACIONES = fopen("calificaciones.txt", "r");
    char c;
    char *cadena = (char*) calloc(1,sizeof(char));
    int contadorChar = 0;
    Calificacion *p = (Calificacion*) calloc(1,sizeof(Calificacion));
    while((c = fgetc(FICHERO_CALIFICACIONES))!=EOF){
        if(c == '\n'){
            N_CALIFICACIONES++;
            p = (Calificacion*) realloc(p, N_CALIFICACIONES*sizeof(Calificacion));
            cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
            cadena[contadorChar] = '\0';
            p[N_CALIFICACIONES-1] = obtenerCalificacion(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_CALIFICACIONES++;
    p = (Calificacion*) realloc(p, N_CALIFICACIONES*sizeof(Calificacion));
    cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
    cadena[contadorChar] = '\0';
    p[N_CALIFICACIONES-1] = obtenerCalificacion(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_CALIFICACIONES);
    return p;
}

// Cabecera: Plantilla* obtenerPlantillas()
// Precondicion:
// Poscondicion:
Calificacion* obtenerFaltas(){
    FILE *FICHERO_FALTAS = fopen("faltas.txt", "r");
    char c;
    char *cadena = (char*) calloc(1,sizeof(char));
    int contadorChar = 0;
    Falta *p = (Falta*) calloc(1,sizeof(Falta));
    while((c = fgetc(FICHERO_FALTAS))!=EOF){
        if(c == '\n'){
            N_FALTAS++;
            p = (Falta*) realloc(p, N_FALTAS*sizeof(Falta));
            cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
            cadena[contadorChar] = '\0';
            p[N_FALTAS-1] = obtenerFalta(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_FALTAS++;
    p = (Falta*) realloc(p, N_FALTAS*sizeof(Falta));
    cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
    cadena[contadorChar] = '\0';
    p[N_FALTAS-1] = obtenerFalta(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_FALTAS);
    return p;
}

// Cabecera: Plantilla* obtenerPlantillas()
// Precondicion:
// Poscondicion:
Horario* obtenerHorarios(){
    FILE *FICHERO_HORARIO = fopen("horarios.txt", "r");
    char c;
    char *cadena = (char*) calloc(1,sizeof(char));
    int contadorChar = 0;
    Horario *p = (Horario*) calloc(1,sizeof(Horario));
    while((c = fgetc(FICHERO_HORARIO))!=EOF){
        if(c == '\n'){
            N_HORARIOS++;
            p = (Horario*) realloc(p, N_HORARIOS*sizeof(Horario));
            cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
            cadena[contadorChar] = '\0';
            p[N_HORARIOS-1] = obtenerHorario(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_HORARIOS++;
    p = (Horario*) realloc(p, N_HORARIOS*sizeof(Horario));
    cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
    cadena[contadorChar] = '\0';
    p[N_HORARIOS-1] = obtenerHorario(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_HORARIO);
    return p;
}
// Cabecera: Jug_plan* obtenerJugadoresPlantillas()
// Precondicion:
// Poscondicion:
Jug_plan* obtenerJugadoresPlantillas(){
    FILE *FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "r");
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Jug_plan *p = (Jug_plan*) malloc(sizeof(Jug_plan));
    while((c = fgetc(FICHERO_JUG_PLAN))!=EOF){
        if(c == '\n'){
            N_JUG_PLANT++;
            p = (Jug_plan*) realloc(p, N_JUG_PLANT*sizeof(Jug_plan));
            p[N_JUG_PLANT-1] = obtenerJugPlan(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_JUG_PLANT++;
    p = (Jug_plan*) realloc(p, N_JUG_PLANT*sizeof(Jug_plan));
    p[N_JUG_PLANT-1] = obtenerJugPlan(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_JUG_PLAN);
    return p;
}

Conf* obtenerConfiguraciones(){
    FILE *FICHERO_CONF = fopen("configuracion.txt", "r");
    char c;
    int n = 0;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Conf *p = (Conf*) malloc(sizeof(Conf));
    while((c = fgetc(FICHERO_CONF))!=EOF){
        if(c == '\n'){
            n++;
            p = (Conf*) realloc(p, n*sizeof(Conf));
            p[n-1] = obtenerConfiguracion(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    n++;
    p = (Conf*) realloc(p, n*sizeof(Conf));
    p[n-1] = obtenerConfiguracion(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_CONF);
    return p;
}

void guardarDatosEquipo(Equipo* equipos, int elementos){
    int i;
    Equipo e;
    FILE *FICHERO_EQUIPO = fopen("equipos.txt", "w");
    for(i = 0; i < elementos; i++){
        e = equipos[i];
        if(i == 0){
            fprintf(FICHERO_EQUIPO, "%s %s", e.codigo, e.nombre);
        }else{
            fprintf(FICHERO_EQUIPO, "\n%s %s", e.codigo, e.nombre);
        }

    }
    fclose(FICHERO_EQUIPO);
}

void guardarDatosJugador(Jugador* jugadores, int elementos){
    int i;
    Jugador j;
    FILE *FICHERO_JUGADOR = fopen("futbolistas.txt", "w");
    for(i = 0; i < elementos; i++){
        j = jugadores[i];
        if(i == 0){
            fprintf(FICHERO_JUGADOR, "%s %s %s %d %d", j.codigo, j.codigo_equipo, j.nombre, j.precio, j.valoracion);
        }else{
            fprintf(FICHERO_JUGADOR, "\n%s %s %s %d %d", j.codigo, j.codigo_equipo, j.nombre, j.precio, j.valoracion);
        }
    }
    fclose(FICHERO_JUGADOR);
}

void guardarDatosUsuario(Usuario* usuarios, int elementos){
    int i;
    Usuario u;
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "w");
    for(i = 0; i < elementos; i++){
        u = usuarios[i];
        if(i == 0){
            fprintf(FICHERO_USUARIO, "%s %s %s %s %s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
        }else{
            fprintf(FICHERO_USUARIO, "\n%s %s %s %s %s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
        }
    }
    fclose(FICHERO_USUARIO);
}

void guardarDatosPlantilla(Plantilla* plantillas, int elementos){
    int i;
    Plantilla p;
    FILE *FICHERO_PLANTILLA = fopen("plantillas.txt", "w");
    for(i = 0; i < elementos; i++){
        p = plantillas[i];
        if(i == 0){
            fprintf(FICHERO_PLANTILLA, "%s %s %s %d %d", p.codigo_usuario, p.codigo, p.nombre, p.presupuesto, p.puntuacion);
        }else{
            fprintf(FICHERO_PLANTILLA, "\n%s %s %s %d %d", p.codigo_usuario, p.codigo, p.nombre, p.presupuesto, p.puntuacion);
        }
    }
    fclose(FICHERO_PLANTILLA);
}

void guardarDatosJugadorPlantilla(Jug_plan* jug_plan, int elementos){
    int i;
    Jug_plan p;
    FILE *FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "w");
    for(i = 0; i < elementos; i++){
        p = jug_plan[i];
        if(i == 0){
            fprintf(FICHERO_JUG_PLAN, "%s %s", p.codigo_jugador, p.codigo_plantilla);
        }else{
            fprintf(FICHERO_JUG_PLAN, "\n%s %s", p.codigo_jugador, p.codigo_plantilla);
        }
    }
    fclose(FICHERO_JUG_PLAN);
}

void guardarDatosConf(Conf* conf, int elementos){
    int i;
    Conf p;
    FILE *FICHERO_CONF = fopen("configuracion.txt", "w");
    for(i = 0; i < elementos; i++){
        p = conf[i];
        if(i == 0){
            fprintf(FICHERO_CONF, "%s %s", p.campo, p.valor);
        }else{
            fprintf(FICHERO_CONF, "\n%s %s", p.campo, p.valor);
        }
    }
    fclose(FICHERO_CONF);
}

int nUsuarios(){
    return N_USUARIO;
}

int nEquipos(){
    return N_EQUIPO;
}

int nJugadores(){
    return N_JUGADOR;
}

int nPlantillas(){
    return N_PLANTILLA;
}

int nJugPlants(){
    return N_JUG_PLANT;
}
