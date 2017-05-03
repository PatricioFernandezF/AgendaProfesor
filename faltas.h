#ifndef FALTAS_H_INCLUDED
#define FALTAS_H_INCLUDED

#include "fichero.h"

void menuFaltas(char);
void mostrarFaltas(char, Alumno*, Materia*, int);
void anadirFaltas(Falta*, int);
void modificarFaltas(Alumno*, Falta*, int);
void borrarFaltas(Alumno*, Falta*, int);

#endif // FALTAS_H_INCLUDED
