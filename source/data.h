#ifndef DATA_H
#define DATA_H
#include <stdio.h>


typedef struct data tData;

tData *CriarELerData();
void ImprimirData(tData *data);

//Verifica se o anos é bissexto
int EhBissexto(int ano);
//retorna o tipo de mes:
//1 se for fevereiro
//2 para todos os meses que tem 30 dias
//3 para todos os meses que tem 31 dias
int TipoDeMes(int mes);

//Verifica se o dias está de acordo com os padroes estabelecidos
 int EhDiaCerto(tData *data);
 

//Verifica se a data esta de acordo com os padroes estabelcidos
 int EhDataCerta(tData *data);

 void LiberaData(tData *data);



#endif