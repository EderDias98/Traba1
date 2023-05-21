#ifndef PACIENTES_H
#define PACIENTES_H
#include "paciente.h"
typedef struct pacientes tPacientes;
tPacientes* CriarPacientes();
tPacientes *CadastrarPacientes(tPacientes *pacientes);
int EhSusUnico(tPacientes *pacientes, char * sus);
void LiberarPacientes(tPacientes *pacientes);
void GerarRelatorio(tPacientes *pacientes,char *path);
int  AcharIndexPacientes(tPacientes * pacientes,char *sus);
tPacientes * RealizarConsulta(tPacientes * pacientes, char * path);
void RealizarBusca(tPacientes * pacientes, char *path);
#endif