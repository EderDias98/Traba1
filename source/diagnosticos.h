#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include "diagnostico"
typedef struct diagnosticos tDiagnosticos;
tDiagnosticos * CriarDiagnosticos();

tDiagnosticos * PreencherDiagnosticos3(tDiagnosticos *diagnosticos,char *str);
void AumentarTamanhoDiagnosticos(tDiagnosticos *diagnosticos);
RetornarTamanhoDiagnosticos(tDiagnosticos *diagnosticos);
tDiagnosticos *RetornarDiagnosticosVet(tDiagnosticos *diagnosticos);
void OrdernarDiagnosticos(tDiagnosticos * diagnosticos);
void MudarPorcentagem(tDiagnosticos * diagnosticos,int qtd_l);
ImprimirDisDiagnosticos(tDiagnosticos * diagnosticos, int tam,char path);
#endif