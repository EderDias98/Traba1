#include "diagnostico.h"
#define TAM_DIAG 50
struct diagnostico{
    char diagnostico[50];
    int total;
    float porcentagem;
};
tDiagnostico *CriarDiagnostico(){
   tDiagnostico* diagnostico = (tDiagnostico*) malloc(sizeof(tDiagnostico)); 
   diagnostico->total = 0;
   diagnostico->porcentagem=0;
}
tDiagnostico ** CriarVetDiagnostico(){
    tDiagnostico **diagnosticos_vet =(tDiagnostico **) malloc(sizeof(tDiagnostico*));
    if(!diagnosticos_vet){
        printf("diagnosticos_vet é NULL");
    }
    return diagnosticos_vet;
}

void LiberarDiagnostico(tDiagnostico *diagnosticos_vet){
    free(diagnostico);
}
tDiagnostico **PreencherDiagnostico(tDiagnosticos* diagnosticos,tDiagnostico **diagnosticos_vet, char *str, int tam){
    int tam_v,idx;
    if((idx=EhUnicoDiagnostico(diagnosticos_vet,str,tam))){
        if(tam==0){
            AumentarTamanhoDiagnosticos(diagnosticos);
            tam_v = RetornarTamanhoDiagnosticos(diagnosticos);
            diagnosticos_vet[tam_v-1] = CriarDiagnostico();
            diagnosticos_vet[tam_v-1]->diagnostico =str;
            diagnosticos_vet[tam_v-1]->total++;
            return diagnosticos_vet;
        }
        AumentarTamanhoDiagnosticos(diagnosticos);
        tam_v = RetornarTamanhoDiagnosticos(diagnosticos);
        diagnosticos_vet = realloc(diagnosticos_vet, sizeof(tDiagnostico *)*tam_v);
        diagnosticos_vet[tam_v]->diagnostico= str;
        diagnosticos_vet[tam_v-1]->total++;
        return diagnosticos_vet;
    }else diagnosticos_vet[idx]->total++;
    return diagnosticos_vet;

}

int NAOEhUnicoDIagnostico(tDiagnostico **diagnosticos_vet, char *str, int tam){
    if(tam==0){
        return -1;
    }
    int i;
    for(i=0; i<tam;i++){
        if(!strcomp(str, diagnosticos_vet[i]->diagnostico)){
            return i;
        }
    }
    return -1;
}