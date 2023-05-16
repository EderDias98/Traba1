#ifndef PACIENTES_H
#define PACIENTES_H
#include "paciente.h"
typedef struct pacientes tPacientes;
tPacientes* CriarPacientes();
tPacientes *CadastrarPacientes(tPacientes *pacientes);
int EhSusUnico(tPacientes *pacientes, int sus);

#endif