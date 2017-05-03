#ifndef CALIFICACIONES_H_INCLUDED
#define CALIFICACIONES_H_INCLUDED

#include "fichero.h"

void menuCalificaciones();
void mostrarCalificaciones(Alumno*, Materia*, int);
void anadirCalificaciones(Calificacion*, int);
void modificarCalificaciones(Alumno*, Materia*, Calificacion*, int);
void eliminarCalificaciones(Alumno*, Materia*, Calificacion*, int);

#endif // CALIFICACIONES_H_INCLUDED
