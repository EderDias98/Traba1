#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include "diagnostico"
typedef struct diagnosticos tDiagnosticos;
tDiagnosticos * CriarDiagnosticos();

tDiagnosticos * PreencherDiagnosticos3(tDiagnosticos *diagnosticos,char *str);
void AumentarTamanhoDiagnosticos(tDiagnosticos *diagnosticos);
RetornarTamanhoDiagnosticos(tDiagnosticos *diagnosticos);
tDiagnosticos *RetornatDiagnosticosVet(tDiagnosticos *diagnosticos);
#endif