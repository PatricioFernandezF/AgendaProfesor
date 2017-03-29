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

    char* guard;

    //sscanf(cadena,"%s-%s-%s-%s-%s", u.id_usuario, u.nombre,u.perfil,u.login,u.pass);

    guard=strtok(cadena,"-");
    strcpy(u.id_usuario,guard);
    guard = strtok(NULL, "-");
    strcpy(u.nombre,guard);
    guard = strtok(NULL, "-");
    strcpy(u.perfil,guard);
    guard = strtok(NULL, "-");
    strcpy(u.login,guard);
    guard = strtok(NULL, "-");
    strcpy(u.pass,guard);

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


Usuario loguear(char* logUsuario, char* passUsuario){
    /*
    Usuario *u = obtenerUsuarios();
    Usuario usuario;
    int dimension = nUsuarios();
    int encontrado = 0;
    int cont = 0;
    while(cont < dimension && encontrado == 0){
        if(strcmp(u[cont].login, logUsuario) == 0 && strcmp(u[cont].pass, passUsuario) == 0){
            encontrado = 1;
            usuario = u[cont];
        }
        cont++;
    }
    return usuario;
    */
}


// Cabecera: Usuario* obtenerUsuarios()
// Precondicion:
// Poscondicion:
Usuario* obtenerUsuarios(){
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "r");

    Usuario *e = (Usuario*) calloc(1,sizeof(Usuario));

    char *contenido = NULL;
    int ftam=0;
    fseek(FICHERO_USUARIO, 0, SEEK_END);
    ftam = ftell(FICHERO_USUARIO);
    rewind(FICHERO_USUARIO);

    contenido = (char*) malloc(sizeof(char) * ftam);
    fread(contenido, 1, ftam, FICHERO_USUARIO);

    //AUX ALMACENA TODAS LAS LINEAS
    char** aux= (char**) malloc(sizeof(char**) * 1);
    //Guard almacena una linea
    char* guard;

    guard=strtok(contenido,"\n");
    aux[N_USUARIOS] = (char*) malloc(sizeof(char) * 200);
    strcpy(aux[N_USUARIOS],guard);
    N_USUARIOS++;
    e = (Usuario*) realloc(e, N_USUARIOS*sizeof(Usuario));

    while(guard!=NULL)
    {
         guard=strtok(NULL,"\n");
         if(guard!=NULL)
         {
            aux[N_USUARIOS] = (char*) malloc(sizeof(char) * 200);
            strcpy(aux[N_USUARIOS],guard);
            N_USUARIOS++;
         }
    }

    int i;
    for(i=0;i<N_USUARIOS-1;i++)
    {
        e = (Usuario*) realloc(e, N_USUARIOS*sizeof(Usuario));
        e[i] = obtenerUsuario(aux[i]);
    }

    fclose(FICHERO_USUARIO);
    return e;
}

// Cabecera: Alumno* obtenerAlumnos()
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

// Cabecera: Falta* obtenerFaltas()
// Precondicion:
// Poscondicion:
Falta* obtenerFaltas(){
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

// Cabecera: Horario* obtenerHorarios()
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


void guardarDatosUsuario(Usuario* usuarios, int elementos){
    int i;
    Usuario e;
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "w");
    for(i = 0; i < elementos; i++){
        e = usuarios[i];
        if(i == 0){
            fprintf(FICHERO_USUARIO, "%s-%s-%s-%s-%s", e.id_usuario, e.nombre,e.perfil,e.login,e.pass);
        }else{
            fprintf(FICHERO_USUARIO, "\n%s-%s-%s-%s-%s", e.id_usuario, e.nombre,e.perfil,e.login,e.pass);
        }

    }
    fclose(FICHERO_USUARIO);
}

void guardarDatosAlumno(Alumno* alumnos, int elementos){
    int i;
    Alumno e;
    FILE *FICHERO_ALUMNO = fopen("alumnos.txt", "w");
    for(i = 0; i < elementos; i++){
        e = alumnos[i];
        if(i == 0){
            fprintf(FICHERO_ALUMNO, "%s-%s-%s-%s-%s-%s", e.id_alumno, e.nombre,e.direccion,e.localidad,e.curso,e.grupo);
        }else{
            fprintf(FICHERO_ALUMNO, "\n%s-%s-%s-%s-%s-%s", e.id_alumno, e.nombre,e.direccion,e.localidad,e.curso,e.grupo);
        }

    }
    fclose(FICHERO_ALUMNO);
}

void guardarDatosMateria(Materia* materias, int elementos){
    int i;
    Materia e;
    FILE *FICHERO_MATERIA = fopen("materias.txt", "w");
    for(i = 0; i < elementos; i++){
        e = materias[i];
        if(i == 0){
            fprintf(FICHERO_MATERIA, "%s-%s-%s", e.id_materia,e.nombre,e.abreviatura);
        }else{
            fprintf(FICHERO_MATERIA, "\n%s-%s-%s", e.id_materia,e.nombre,e.abreviatura);
        }
    }
    fclose(FICHERO_MATERIA);
}

void guardarDatosMatricula(Matricula* matriculas, int elementos){
    int i;
    Matricula e;
    FILE *FICHERO_MATRICULA = fopen("matriculas.txt", "w");
    for(i = 0; i < elementos; i++){
        e = matriculas[i];
        if(i == 0){
            fprintf(FICHERO_MATRICULA, "%s-%s", e.id_materia,e.id_alumno);
        }else{
            fprintf(FICHERO_MATRICULA, "\n%s-%s", e.id_materia,e.id_alumno);
        }
    }
    fclose(FICHERO_MATRICULA);
}

void guardarDatosCalificaciones(Calificacion* calificaciones, int elementos){
    int i;
    Calificacion e;
    FILE *FICHERO_CALIFICACION = fopen("calificaciones.txt", "w");
    for(i = 0; i < elementos; i++){
        e = calificaciones[i];
        if(i == 0){
            fprintf(FICHERO_CALIFICACION, "%s-%s-%s-%s-%d", e.fecha,e.descripcion,e.id_materia,e.id_alumno,e.calificacion);
        }else{
            fprintf(FICHERO_CALIFICACION, "\n%s-%s-%s-%s-%d", e.fecha,e.descripcion,e.id_materia,e.id_alumno,e.calificacion);
        }
    }
    fclose(FICHERO_CALIFICACION);
}

void guardarDatosFaltas(Falta* faltas, int elementos){
    int i;
    Falta e;
    FILE *FICHERO_FALTA = fopen("faltas.txt", "w");
    for(i = 0; i < elementos; i++){
        e = faltas[i];
        if(i == 0){
            fprintf(FICHERO_FALTA, "%s-%d-%s-%s-%s", e.fecha,e.hora,e.descripcion,e.estado_falta,e.id_alumno);
        }else{
            fprintf(FICHERO_FALTA, "\n%s-%d-%s-%s-%s",e.fecha,e.hora,e.descripcion,e.estado_falta,e.id_alumno);
        }
    }
    fclose(FICHERO_FALTA);
}

void guardarDatosHorarios(Horario* horarios, int elementos){
    int i;
    Horario e;
    FILE *FICHERO_HORARIO = fopen("horarios.txt", "w");
    for(i = 0; i < elementos; i++){
        e = horarios[i];
        if(i == 0){
            fprintf(FICHERO_HORARIO, "%s-%d-%d-%s-%s", e.id_profesor,e.dia,e.hora,e.id_materia,e.grupo);
        }else{
            fprintf(FICHERO_HORARIO, "\n%s-%d-%d-%s-%s",e.id_profesor,e.dia,e.hora,e.id_materia,e.grupo);
        }
    }
    fclose(FICHERO_HORARIO);
}

int nUsuarios(){
    return N_USUARIOS;
}

int nAlumnos(){
    return N_ALUMNOS;
}

int nMaterias(){
    return N_MATERIAS;
}

int nMatriculas(){
    return N_MATRICULAS;
}

int nCalificaciones(){
    return N_CALIFICACIONES;
}

int nFaltas(){
    return N_FALTAS;
}
