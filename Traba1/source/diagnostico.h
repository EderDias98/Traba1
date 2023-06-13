#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include "lesao.h"
typedef struct diagnostico tDiagnostico;
tDiagnostico *CriarDiagnostico();
void LiberarDiagnostico(tDiagnostico *diagnostico);
tDiagnostico ** CriarVetDiagnostico();
void AumentarDiagnosticos(tDiagnostico * diagnostico);
int IdxDoDiagnostico(tDiagnostico **diagnosticos_vet, char *str, int tam);
int Comparar(const void* a, const void* b);
void OrdernarDiagnosticos_D(tDiagnostico **diagnostico_vet, int tam);
void MudarPorcentagem_D(tDiagnostico *diagnostico,int qtd_l);
void ImprimirDiagnosticos_D(tDiagnostico **diagnostico_vet,int tam, char *path);
void PreencherNomeDiagnostico(tDiagnostico *diagnostico, char * str);
#endif