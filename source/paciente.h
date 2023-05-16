#ifndef PACIENTE_H
#define PACIENTE_H
#include "lesoes.h"
#include "data.h"
typedef struct paciente tPaciente;
int RetornarSusPaciente(tPaciente *paciente);
tPaciente *LerECriarPaciente();
#endif