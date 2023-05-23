#ifndef LESAO_H
#define LESAO_H
#include <stdio.h>
#include "data.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "diagnosticos.h"

typedef struct lesao tLesao;
tLesao *CriarELerLesao();
char * RetornarLog(tLesao *lesao);
int RetornarQtdCiru(tLesao **lesao, int tam);
int RetornarQtdCrio(tLesao **lesao, int tam);
void EscreverLesao(tLesao *lesao,char *path);
int RetornarTamLesao2(tLesao * lesao);
int EhCirurgia(tLesao * lesao);
int EhCrioterapia(tLesao * lesao);
char * RetornarDiagnostico(tLesao *lesao);

#endif