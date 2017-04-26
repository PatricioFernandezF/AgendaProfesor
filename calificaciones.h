#ifndef CALIFICACIONES_H_INCLUDED
#define CALIFICACIONES_H_INCLUDED

#include "fichero.h"

void menuCalificaciones();
Calificacion* mostrarCalificaciones(Alumno*, Materia*);
void anadirCalificaciones(Calificacion*);
void modificarCalificaciones(Alumno*, Materia*, Calificacion*);
void eliminarCalificaciones(Alumno*, Materia*, Calificacion*);

#endif // CALIFICACIONES_H_INCLUDED
