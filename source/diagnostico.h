#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include "lesao.h"
typedef struct diagnostico tDiagnostico;
typedef struct diagnosticos tDiagnosticos;
tDiagnosticos * CriarDiagnosticos();

tDiagnostico ** CriarVetDiagnostico();
 

void LiberarDiagnostico(tDiagnostico *diagnostico);
 
tDiagnostico **PreencherDiagnostico(tDiagnosticos* diagnosticos,tDiagnostico **diagnosticos_vet, char *str);

int NAOEhUnicoDIagnostico(tDiagnostico **diagnosticos_vet, char *str, int tam);
int Comparar(const void* a, const void* b);
OrdernarDiagnosticos_D(tDiagnostico **diagnostico_vet, int tam);
MudarPorcentagem_D(tDiagnostico *diagnostico,int qt_l);
void ImprimirDisDiagnosticos_D(tDiagnostico **diagnostico_vet,int tam, char *path);

#endif