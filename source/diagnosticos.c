#include "diagnosticos.h"

struct diagnosticos{
    tDiagnostico **vet;
    int tam;
};

tDiagnosticos * CriarDiagnosticos(){
    tDiagnosticos *diagnosticos = malloc(sizeof(tDiagnosticos));
    if(!diagnosticos){
        printf("diagnosticos é NULLL\n");
    }
    diagnosticos->tam =0;
    return diagnosticos;
}
tDiagnosticos * PreencherDiagnosticos3(tDiagnosticos *diagnosticos,char *str){

    diagnosticos->vet = CriarVetDiagnostico();
    diagnosticos->vet  =PreencherDiagnostico(diagnosticos,diagnosticos->vet,str);
    return diagnosticos;
}
void AumentarTamanhoDiagnosticos(tDiagnosticos *diagnosticos){
    diagnosticos->tam++;
}
RetornarTamanhoDiagnosticos(tDiagnosticos *diagnosticos){
    return diagnosticos->tam;
}
tDiagnosticos *RetornarDiagnosticosVet(tDiagnosticos *diagnosticos){
    return diagnosticos->vet;
}
void LiberarDiagnosticos(tDiagnosticos *diagnosticos){
    int i;
    for(i=0;i<diagnosticos->tam;i++){
        LiberarDiagnostico(diagnosticos->vet[i]);
    }
    free(diagnosticos->vet);
    free(diagnosticos);
}
void OrdernarDiagnosticos(tDiagnosticos * diagnosticos){
    OrdernarDiagnosticos_D(diagnosticos->vet);
}
void MudarPorcentagem(tDiagnosticos * diagnosticos,int qtd_l){
    int i;
    for(i=0; i<diagnosticos->tam;i++){
        MudarPorcentagem_D(diagnosticos->vet[i], qt_l);
    }
}
ImprimirDisDiagnosticos(tDiagnosticos * diagnosticos, int tam,char path){
    ImprimirDisDiagnosticos_D(diagnosticos->vet,path);
}