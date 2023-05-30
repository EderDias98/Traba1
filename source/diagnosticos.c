#include "diagnosticos.h"


struct diagnosticos{
    tDiagnostico **vet;
    int tam;
};

tDiagnosticos * CriarDiagnosticos(){
    tDiagnosticos *diagnosticos =(tDiagnosticos *) malloc(sizeof(tDiagnosticos));
    EhPonteiroNULL(diagnosticos);
    diagnosticos->vet = NULL;
    diagnosticos->tam =0;
    return diagnosticos;
}
void PreencherDiagnosticos_D(tDiagnosticos *diagnosticos,char *str){
    int tam_v,idx;
  
    if(!(idx=EhUnicoDiagnostico(diagnosticos->vet,str,diagnosticos->tam))){
        
        if(diagnosticos->tam==0){
            
            diagnosticos->vet = CriarVetDiagnostico();
           
        if(!diagnosticos->vet){
        printf("diagnosticos_vet é NULL");
        exit(-1);
        }
        AumentarTamanhoDiagnosticos(diagnosticos);
        tam_v = RetornarTamanhoDiagnosticos(diagnosticos);
        diagnosticos->vet[tam_v-1] = CriarDiagnostico();
        PreencherNomeDiagnostico(diagnosticos->vet[tam_v-1], str);
        AumentarDiagnosticos(diagnosticos->vet[tam_v-1]);
        }else{
        
        AumentarTamanhoDiagnosticos(diagnosticos);
            
        tam_v = RetornarTamanhoDiagnosticos(diagnosticos);
        diagnosticos->vet = realloc(diagnosticos->vet, sizeof(tDiagnostico *)*tam_v);
          
        diagnosticos->vet[tam_v-1] = CriarDiagnostico();
        PreencherNomeDiagnostico(diagnosticos->vet[tam_v-1], str);
     
        AumentarDiagnosticos(diagnosticos->vet[tam_v-1]);
         
        }
    }else {
          
        AumentarDiagnosticos(diagnosticos->vet[idx]);
    }
}
void AumentarTamanhoDiagnosticos(tDiagnosticos *diagnosticos){
    diagnosticos->tam++;
}
int RetornarTamanhoDiagnosticos(tDiagnosticos *diagnosticos){
    return diagnosticos->tam;
}

void LiberarDiagnosticos(tDiagnosticos *diagnosticos){
    int i;
    for(i=0;i<diagnosticos->tam;i++){
        if(!diagnosticos->vet){
            break;;
        }
        LiberarDiagnostico(diagnosticos->vet[i]);
    }
    LiberarPonteiro(diagnosticos->vet);
    LiberarPonteiro(diagnosticos);
}
void OrdernarDiagnosticos(tDiagnosticos * diagnosticos){
    OrdernarDiagnosticos_D(diagnosticos->vet, diagnosticos->tam);
}
void MudarPorcentagem(tDiagnosticos * diagnosticos,int qtd_l){
    int i;
    for(i=0; i<diagnosticos->tam;i++){
        MudarPorcentagem_D(diagnosticos->vet[i], qtd_l);
    }
}
void ImprimirDiagnosticos(tDiagnosticos * diagnosticos,char* path){
    ImprimirDiagnosticos_D(diagnosticos->vet,diagnosticos->tam,path);
}