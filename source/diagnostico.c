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

void LiberarDiagnostico(tDiagnostico *diagnostico){
    if(!diagnostico){
        free(diagnostico);
    }
}
tDiagnostico **PreencherDiagnostico(tDiagnosticos* diagnosticos,tDiagnostico **diagnosticos_vet, char *str){
    int tam_v,idx;
    if((idx=EhUnicoDiagnostico(diagnosticos_vet,str,RetornarTamanhoDiagnosticos(diagnosticos)))){
        if(RetornarTamanhoDiagnosticos(diagnosticos)==0){
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
OrdernarDiagnosticos_D(tDiagnostico **diagnostico_vet, int tam){
        
        qsort(diagnostico_vet,tam, sizeof(tDiagnostico *), Comparar)
}
int Comparar(const void* a, const void* b) {
    const tDiagnostico* diag1 = *(const tDiagnostico**)a;
    const tDiagnostico* diag2 = *(const tDiagnostico**)b;
    int vl1 = abs(diag1->valor);
    int vl2 = abs(diag2->valor);

    if (vl1 > vl2)
        return -1;
    else if (vl1 < vl2)
        return 1;
    else {
        return strcmp(diag1->diagnostico, diag2->diagnostico);
    }
}
void MudarPorcentagem_D(tDiagnostico *diagnostico,int qt_l){
    diagnostico->porcentagem = diagnostico->total/(float)qt_l;
}

void ImprimirDisDiagnosticos_D(tDiagnostico **diagnostico_vet,int tam, char *path){
    FILE * file = fopen(path, "a");
    if(!file){
        printf("Erro ao abrir o arquivo");
    }
    int i;
    for(i=0; i<tam;i++){
        fprintf(file,"- %s: %d (%.2f%%)\n", diagnostico_vet[i]->diagnostico, diagnostico_vet[i]->total, diagnostico_vet[i]->porcentagem);
    }
    
}