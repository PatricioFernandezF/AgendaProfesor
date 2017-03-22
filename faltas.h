#ifndef FALTAS_H_INCLUDED
#define FALTAS_H_INCLUDED

#include "fichero.h"

void menuFaltas();
void mostrarFaltas(Alumno*);
void anadirFaltas(Alumno*, Falta*);
void modificarFaltas(Alumno*, Falta*);
void borrarFaltas(Alumno*, Falta*);

#endif // FALTAS_H_INCLUDED
