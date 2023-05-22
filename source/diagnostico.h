#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include "lesao.h";
typedef struct diagnostico tDiagnostico;
typedef struct diagnosticos tDiagnosticos;
tDiagnosticos * CriarDiagnosticos();

tDiagnostico ** CriarVetDiagnostico();
 

void LiberarDiagnostico(tDiagnostico *diagnosticos_vet);
 
tDiagnostico **PreencherDiagnostico(tDiagnosticos* diagnosticos,tDiagnostico **diagnosticos_vet, char *str, int tam);

int NAOEhUnicoDIagnostico(tDiagnostico **diagnosticos_vet, char *str, int tam);

#endif