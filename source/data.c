#include "data.h"
#include "stdlib.h"

struct data{
  int dia,mes,ano;
};

tData *CriarELerData(){
    tData *data = (tData *) malloc(sizeof(tData));
    scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);

    return data;
}
void ImprimirData(tData *data){
  printf("%.2d/%.2d/%.2d\n", data->dia, data->mes, data->ano);
}

int EhBissexto(int ano){
    if(!(ano%4) && (ano%100))
        return 1;
    if(!(ano%400))
        return 1;
    return 0;
}

int TipoDeMes(int mes){
    if(mes==2)
        return 1;
    else if( mes == 4 || mes == 6 || mes == 9 ||mes == 11)
        return 2;
    else return 3;
}

 int EhDiaCerto(tData *data){
    if(TipoDeMes(data->mes) == 1){

        if(EhBissexto(data->ano))
            return (data->dia>=1 && data->dia<=29) ? 1: 0;
        else 
            return (data->dia>=1 && data->dia<=28) ? 1: 0;
    }
    if(TipoDeMes(data->mes) == 2)
        return (data->dia >=1 && data->dia<=30) ? 1: 0;
    if( TipoDeMes(data->mes) ==3)
        return (data->dia >=1 && data->dia<=31) ? 1: 0;
    return 0;
 }

 int EhDataCerta(tData *data){
    if(!(1900<data->ano  && data->ano < 2024))
        return 0;
    if(!(data->mes>=1 && data->mes <=12))
        return 0;
    if(!EhDiaCerto(data))
        return 0;
    return 1;
 }
 void LiberaData(tData *data){
    if(data !=NULL)
        free(data);
 }

