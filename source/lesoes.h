#ifndef LESOES_H
#define LESOES_H
#include "lesao.h"
typedef struct lesoes tLesoes;
void LiberarLesoes(tLesoes *lesoes);
tLesoes * CadastrarLesoes(tLesoes *lesoes);
void ArmazenarLogs(tLesoes *lesoes,char *sus, char *path);
void EscreverLesoes(tLesoes * lesoes, char *path);
#endif