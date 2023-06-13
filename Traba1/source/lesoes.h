#ifndef LESOES_H
#define LESOES_H
#include "lesao.h"
typedef struct lesoes tLesoes;
tLesoes *CriarLesoes();
void LiberarLesoes(tLesoes *lesoes);
tLesoes * CadastrarLesoes(tLesoes *lesoes, int atendimento, int *idx_aten);
void ArmazenarLogs(tLesoes *lesoes,char *sus, char *path,int idx_aten);
void EscreverLesoes(tLesoes * lesoes, char *path);
int RetornarTamLesoes(tLesoes *lesoes);
int RetornarTamLesao1(tLesoes *lesoes, int idx);
int RetornarQtdCirurgias2(tLesoes *lesoes);
tLesoes* PreencherLesoes(tLesoes *lesoes, char * rotulo, int *p_num);
int RetornarQtdCrioterapias2(tLesoes *lesoes);
void PreencherDiagnosticos_L(tDiagnosticos *diagnosticos,tLesoes *lesoes, int tam);
int RetornarTemPacienteLesoes(tLesoes *lesoes);
#endif