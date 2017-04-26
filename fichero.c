#include "fichero.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


Usuario obtenerUsuario(char *cadena){

    Usuario u;

    char* guard;

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
    char* guard;

    guard=strtok(cadena,"-");
    strcpy(a.id_alumno,guard);
    guard = strtok(NULL, "-");
    strcpy(a.nombre,guard);
    guard = strtok(NULL, "-");
    strcpy(a.direccion,guard);
    guard = strtok(NULL, "-");
    strcpy(a.localidad,guard);
    guard = strtok(NULL, "-");
    strcpy(a.curso,guard);
    guard = strtok(NULL, "-");
    strcpy(a.grupo,guard);

    return a;
}

Materia obtenerMateria(char *cadena){
    Materia m;
    sscanf(cadena,"%s-%s-%s", m.id_materia, m.nombre,m.abreviatura);

    char* guard;

    guard=strtok(cadena,"-");
    strcpy(m.id_materia,guard);
    guard = strtok(NULL, "-");
    strcpy(m.nombre,guard);
    guard = strtok(NULL, "-");
    strcpy(m.abreviatura,guard);

    return m;
}

Matricula obtenerMatricula(char* cadena){
    Matricula m;

    char* guard;
    guard=strtok(cadena,"-");
    strcpy(m.id_materia,guard);
    guard = strtok(NULL, "-");
    strcpy(m.id_alumno,guard);

    return m;
}

Calificacion obtenerCalificacion(char* cadena){
    Calificacion c;
    char* guard;

    guard=strtok(cadena,"-");
    strcpy(c.fecha,guard);
    guard = strtok(NULL, "-");
    strcpy(c.descripcion,guard);
    guard = strtok(NULL, "-");
    strcpy(c.id_materia,guard);
    guard = strtok(NULL, "-");
    strcpy(c.id_alumno,guard);
    guard = strtok(NULL, "-");
    strcpy(c.calificacion,guard);
    return c;
}

Falta obtenerFalta(char* cadena){
    Falta f;
    char* guard;
    guard=strtok(cadena,"-");
    strcpy(f.fecha,guard);
    guard = strtok(NULL, "-");
    strcpy(f.hora,guard);
    guard = strtok(NULL, "-");
    strcpy(f.descripcion,guard);
    guard = strtok(NULL, "-");
    strcpy(f.estado_falta,guard);
    guard = strtok(NULL, "-");
    strcpy(f.id_alumno,guard);
    return f;
}

Horario obtenerHorario(char* cadena){
    Horario h;
    char* guard;
    guard=strtok(cadena,"-");
    strcpy(h.id_profesor,guard);
    guard = strtok(NULL, "-");
    strcpy(h.dia,guard);
    guard = strtok(NULL, "-");
    strcpy(h.hora,guard);
    guard = strtok(NULL, "-");
    strcpy(h.id_materia,guard);
    guard = strtok(NULL, "-");
    strcpy(h.grupo,guard);
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
// Cabecera: Usuario* obtenerUsuarios()
// Precondicion:
// Poscondicion:
Usuario* obtenerUsuarios(int *n){
    FILE *FICHERO_USUARIO;
    *n=0;
    Usuario *e = (Usuario*) calloc(1,sizeof(Usuario));
    if(FICHERO_USUARIO = fopen("usuarios.txt", "r"))
    {
        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_USUARIO, 0, SEEK_END);
        ftam = ftell(FICHERO_USUARIO);
        rewind(FICHERO_USUARIO);

        contenido = (char*) malloc(sizeof(char)* 1000 * ftam);
        fread(contenido, 1, ftam, FICHERO_USUARIO);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux= (char**) malloc(sizeof(char**) * 1);
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char**) * 20000);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Usuario*) realloc(e, *n*sizeof(Usuario));

        while(guard!=NULL)
        {

            guard=strtok(NULL,"\n");
            if(guard!=NULL)
            {

                aux[*n] = (char*) malloc(sizeof(char**) * 20000);
                strcpy(aux[*n],guard);


                ++*n;
            }
        }


        int i;
        for(i=0;i<*n;i++)
        {
            e = (Usuario*) realloc(e, *n*2000*sizeof(Usuario));
            e[i] = obtenerUsuario(aux[i]);
        }

        fclose(FICHERO_USUARIO);
    }

    return e;
}
// Cabecera: Alumno* obtenerAlumnos()
// Precondicion:
// Poscondicion:
Alumno* obtenerAlumnos(int *n){
    FILE *FICHERO_ALUMNO;
    *n=0;
    Alumno *e = (Alumno*) calloc(1,sizeof(Alumno));

    if(FICHERO_ALUMNO = fopen("alumnos.txt", "r"))
    {
        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_ALUMNO, 0, SEEK_END);
        ftam = ftell(FICHERO_ALUMNO);
        rewind(FICHERO_ALUMNO);

        contenido = (char*) malloc(sizeof(char) * ftam);
        fread(contenido, 1, ftam, FICHERO_ALUMNO);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux= (char**) malloc(sizeof(char**) * 1000000);
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char) * 200);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Alumno*) realloc(e, *n*sizeof(Alumno));

        while(guard!=NULL)
        {
            guard=strtok(NULL,"\n");
            if(guard!=NULL)
            {
                aux[*n] = (char*) malloc(sizeof(char) * 200);
                strcpy(aux[*n],guard);
                ++*n;
            }
        }


        int i;
        for(i=0;i<*n;i++)
        {
            e = (Alumno*) realloc(e, *n*sizeof(Alumno));
            e[i] = obtenerAlumno(aux[i]);
        }

        fclose(FICHERO_ALUMNO);
    }


    return e;
}

// Cabecera: Usuario* obtenerUsuarios()
// Precondicion:
// Poscondicion:
Materia* obtenerMaterias(int *n){
    FILE *FICHERO_MATERIA;
    *n=0;
    Materia *e = (Materia*) calloc(1,sizeof(Materia));
    if(FICHERO_MATERIA = fopen("materias.txt", "r"))
    {

        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_MATERIA, 0, SEEK_END);
        ftam = ftell(FICHERO_MATERIA);
        rewind(FICHERO_MATERIA);

        contenido = (char*) malloc(sizeof(char) * ftam);
        fread(contenido, 1, ftam, FICHERO_MATERIA);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux= (char**) malloc(sizeof(char**) * 200);
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char) * 200);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Materia*) realloc(e, *n*sizeof(Materia));

        while(guard!=NULL)
        {
            guard=strtok(NULL,"\n");
            if(guard!=NULL)
            {
                aux[*n] = (char*) malloc(sizeof(char) * 200);
                strcpy(aux[*n],guard);
                ++*n;
            }
        }

        int i;
        for(i=0;i<*n;i++)
        {
            e = (Materia*) realloc(e, *n*sizeof(Materia));
            e[i] = obtenerMateria(aux[i]);
        }

        fclose(FICHERO_MATERIA);
    }


    return e;
}
// Cabecera: Plantilla* obtenerMatriculas()
// Precondicion:
// Poscondicion:
Matricula* obtenerMatriculas(int *n){
    FILE *FICHERO_MATRICULA;
    *n=0;
    Matricula *e = (Matricula*) calloc(1,sizeof(Matricula));
    if(FICHERO_MATRICULA = fopen("matriculas.txt", "r"))
    {

        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_MATRICULA, 0, SEEK_END);
        ftam = ftell(FICHERO_MATRICULA);
        rewind(FICHERO_MATRICULA);

        contenido = (char*) malloc(sizeof(char) * ftam);
        fread(contenido, 1, ftam, FICHERO_MATRICULA);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux= (char**) malloc(sizeof(char**) * 200);
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char) * 200);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Matricula*) realloc(e, *n*sizeof(Matricula));

        while(guard!=NULL)
        {
            guard=strtok(NULL,"\n");
            if(guard!=NULL)
            {
                aux[*n] = (char*) malloc(sizeof(char) * 200);
                strcpy(aux[*n],guard);
                ++*n;
            }
        }

        int i;
        for(i=0;i<*n;i++)
        {
            e = (Matricula*) realloc(e, *n*sizeof(Matricula));
            e[i] = obtenerMatricula(aux[i]);
        }

        fclose(FICHERO_MATRICULA);
    }


    return e;
}
// Cabecera: Plantilla* obtenerCalificaciones()
// Precondicion:
// Poscondicion:
Calificacion* obtenerCalificaciones(int *n){
    FILE *FICHERO_CALIFICACIONES;
    *n=0;
    Calificacion *e = (Calificacion*) calloc(1,sizeof(Calificacion));
    if(FICHERO_CALIFICACIONES = fopen("calificaciones.txt", "r"))
    {

        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_CALIFICACIONES, 0, SEEK_END);
        ftam = ftell(FICHERO_CALIFICACIONES);
        rewind(FICHERO_CALIFICACIONES);

        contenido = (char*) malloc(sizeof(char) * ftam);
        fread(contenido, 1, ftam, FICHERO_CALIFICACIONES);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux= (char**) malloc(sizeof(char**) * 200);
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char) * 200);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Calificacion*) realloc(e, *n*sizeof(Calificacion));

        while(guard!=NULL)
        {
            guard=strtok(NULL,"\n");
            if(guard!=NULL)
            {
                aux[*n] = (char*) malloc(sizeof(char) * 200);
                strcpy(aux[*n],guard);
                ++*n;
            }
        }

        int i;
        for(i=0;i<*n;i++)
        {
            e = (Calificacion*) realloc(e, *n*sizeof(Calificacion));
            e[i] = obtenerCalificacion(aux[i]);
        }
        fclose(FICHERO_CALIFICACIONES);
    }
    return e;
}

// Cabecera: Falta* obtenerFaltas()
// Precondicion:
// Poscondicion:
Falta* obtenerFaltas(int *n){
    FILE *FICHERO_FALTAS;
    *n=0;
    Falta *e = (Falta*) calloc(1,sizeof(Falta));
    if(FICHERO_FALTAS = fopen("faltas.txt", "r"))
    {
        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_FALTAS, 0, SEEK_END);
        ftam = ftell(FICHERO_FALTAS);
        rewind(FICHERO_FALTAS);

        contenido = (char*) calloc(ftam,sizeof(char));
        fread(contenido, 1, ftam, FICHERO_FALTAS);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux= (char**) calloc(ftam,sizeof(char**));
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char**) * *n);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Falta*) realloc(e, *n*sizeof(Falta));

        while(guard!=NULL)
        {
            guard=strtok(NULL,"\n");
            if(guard!=NULL)
            {
                aux[*n] = (char*) malloc(sizeof(char**) * ftam);
                strcpy(aux[*n],guard);
                ++*n;
            }
        }

        int i;
        for(i=0;i<*n;i++)
        {
            e = (Falta*) realloc(e, *n*sizeof(Falta));
            e[i] = obtenerFalta(aux[i]);
        }
        fclose(FICHERO_FALTAS);
    }
    return e;
}

// Cabecera: Horario* obtenerHorarios()
// Precondicion:
// Poscondicion:
Horario* obtenerHorarios(int *n){
    FILE *FICHERO_HORARIOS;
    *n=0;
    Horario *e = (Horario*) calloc(1,sizeof(Horario));
    if(FICHERO_HORARIOS = fopen("horarios.txt", "r"))
    {
        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_HORARIOS, 0, SEEK_END);
        ftam = ftell(FICHERO_HORARIOS);
        rewind(FICHERO_HORARIOS);

        contenido = (char*) malloc(sizeof(char) * ftam);
        fread(contenido, 1, ftam, FICHERO_HORARIOS);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux= (char**) calloc(ftam,sizeof(char**));
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char**) * *n);
        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char**) * 200);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Horario*) realloc(e, *n*sizeof(Horario));

        while(guard!=NULL)
        {
            guard=strtok(NULL,"\n");
            if(guard!=NULL)
            {
                aux[*n] = (char*) malloc(sizeof(char**) * ftam);
                strcpy(aux[*n],guard);
                ++*n;
            }
        }

        int i;
        for(i=0;i<*n;i++)
        {
            e = (Horario*) realloc(e, *n*sizeof(Horario));
            e[i] = obtenerHorario(aux[i]);
        }
        fclose(FICHERO_HORARIOS);
    }
    return e;
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


