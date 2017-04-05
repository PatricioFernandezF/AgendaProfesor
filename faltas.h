#ifndef FALTAS_H_INCLUDED
#define FALTAS_H_INCLUDED

#include "fichero.h"

void menuFaltas();
Falta* mostrarFaltas(Alumno*, Materia*, Falta*);
void anadirFaltas(Alumno*, Falta*);
void modificarFaltas(Alumno*, Falta*);
void borrarFaltas(Alumno*, Falta*);

#endif // FALTAS_H_INCLUDED
