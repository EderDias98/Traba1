#ifndef PACIENTES_H
#define PACIENTES_H
#include "paciente.h"
typedef struct pacientes tPacientes;
tPacientes* CriarPacientes();
void CadastrarPacientes(tPacientes *pacientes);
int EhSusUnico(tPacientes *pacientes, char * sus);
void LiberarPacientes(tPacientes *pacientes);
void GerarRelatorio(tPacientes *pacientes,char *path);
int  AcharIndexPacientes(tPacientes * pacientes,char *sus);
void RealizarConsulta(tPacientes * pacientes, char * path);
void RealizarBusca(tPacientes * pacientes, char *path);
float RetornarPorcentagem(int n, int total);
#endif