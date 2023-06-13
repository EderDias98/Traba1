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
void AtenderPaciente(tPaciente *paciente, char *path);
int QtdPaciAten(tPaciente ** pacientes_vet, int tam);
int IdadeMedia(tPaciente ** pacientes_vet, int tam);
int DesvioPadraoIdade(tPaciente ** pacientes_vet, int tam, int media);
float DistribuicaoMasculina(tPaciente ** pacientes_vet, int tam);
float DistribuicaoFeminina(tPaciente ** pacientes_vet, int tam);
float DistribuicaoOutros(tPaciente ** pacientes_vet, int tam);
float TamanhoMedioLesao(tPaciente **paciente_vet, int tam);
float DesvioPadraoLesoes(tPaciente **paciente_vet,int tam, int media);
int RetornarQtdLesoes(tPaciente **paciente_vet,int tam);
int RetornarQtdCirurgias1(tPaciente **paciente_vet,int tam);
int RetornarQtdCrioterapias1(tPaciente **paciente_vet,int tam);
void PreencherDiagnosticos_P(tDiagnosticos *diagnosticos, tPaciente **pacientes_vet, int tam_p);
void EscreverPaciente(tPaciente *paciente,char *sus, char *path);
char *RetornarNomePaciente(tPaciente *paciente);
#endif