#ifndef CALIFICACIONES_H_INCLUDED
#define CALIFICACIONES_H_INCLUDED

#include "fichero.h"

void menuCalificaciones();
void mostrarCalificaciones(Alumno*, Materia*);
void añadirCalificaciones(Alumno*, Materia*, int*);
void modificarCalificaciones(Alumno*, Materia*, int*);
void eliminarCalificaciones(Alumno*, Materia*);

#endif // CALIFICACIONES_H_INCLUDED
