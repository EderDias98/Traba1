#ifndef DIAGNOSTICOS_H
#define DIAGNOSTICOS_H
#include "diagnostico.h"
typedef struct diagnosticos tDiagnosticos;
tDiagnosticos * CriarDiagnosticos();
void LiberarDiagnosticos(tDiagnosticos *diagnosticos);
void PreencherDiagnosticos_D(tDiagnosticos *diagnosticos,char *str);
void AumentarTamanhoDiagnosticos(tDiagnosticos *diagnosticos);
int RetornarTamanhoDiagnosticos(tDiagnosticos *diagnosticos);

void OrdernarDiagnosticos(tDiagnosticos * diagnosticos);
void MudarPorcentagem(tDiagnosticos * diagnosticos,int qtd_l);
void ImprimirDiagnosticos(tDiagnosticos * diagnosticos,char *path);
#endif