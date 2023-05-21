#ifndef PACIENTE_H
#define PACIENTE_H
#include "lesoes.h"
#include "data.h"
typedef struct paciente tPaciente;
char * RetornarSusPaciente(tPaciente *paciente);
tPaciente *LerECriarPaciente();
void LiberarPaciente(tPaciente *paciente);
tPaciente **CriarVetPacientes();
void EscreverRelatorio(tPaciente *paciente,char *path);
tPaciente * AtenderPaciente(tPaciente *paciente, char *path);
#endif