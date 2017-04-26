#ifndef PROFESOR_H_INCLUDED
#define PROFESOR_H_INCLUDED

#include "fichero.h"

void menu_profesor();
char seleccionar_grupos_dia(Horario *lista);
void seleccionar_alumno_grupo(Horario *lista);
int dia_semana();

#endif // PROFESOR_H_INCLUDED


