#ifndef LESAO_H
#define LESAO_H
#include <stdio.h>
#include "data.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "diagnosticos.h"
#include <ctype.h>

typedef struct lesao tLesao;
tLesao * CriarELerLesao(char *diagnostico);
tLesao **CriarVetLesao();
int RetornarQtdCiru(tLesao **lesao, int tam);
int RetornarQtdCrio(tLesao **lesao, int tam);
void EscreverLesao(tLesao *lesao,char *path);
int RetornarTamLesao2(tLesao * lesao);
char * RetornarNomeDiagnostico_L(tLesao *lesao);
char * RetornarRotulo(tLesao *lesao);
void EhPonteiroNULL(void *p);
void ConverterEmMaiusculas(char *str);
void LiberarLesao(tLesao* lesao);
void LiberarPonteiro(void *p);
int EhNumInt(float num);
#endif