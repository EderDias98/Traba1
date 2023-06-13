#include "diagnostico.h"
#define TAM_DIAG 50
#define TIPOS_DIAGNOSTICOS 6

struct diagnostico{
    char diagnostico[50];
    int total;
    float porcentagem;
};

tDiagnostico *CriarDiagnostico(){
   tDiagnostico* diagnostico = (tDiagnostico*) malloc(sizeof(tDiagnostico));
   EhPonteiroNULL(diagnostico); 
   diagnostico->total = 0;
   diagnostico->porcentagem=0;
   memset(diagnostico->diagnostico,'\0',sizeof(diagnostico->diagnostico));
   return diagnostico;
}

void LiberarDiagnostico(tDiagnostico *diagnostico){
   LiberarPonteiro(diagnostico);
}
void AumentarDiagnosticos(tDiagnostico * diagnostico){
    diagnostico->total++;
}

int IdxDoDiagnostico(tDiagnostico **diagnosticos_vet, char *str, int tam){
     
    int i;
    for(i=0; i<tam;i++){
     
        if(!strcmp(str, diagnosticos_vet[i]->diagnostico)){
            return i;
            
        }
        
    }
    
    return -1;
}
void OrdernarDiagnosticos_D(tDiagnostico **diagnostico_vet, int tam){
        
        qsort(diagnostico_vet,tam, sizeof(tDiagnostico *), Comparar);
}
int Comparar(const void* a, const void* b) {
    const tDiagnostico* diag1 = *(const tDiagnostico**)a;
    const tDiagnostico* diag2 = *(const tDiagnostico**)b;
    int vl1 = abs(diag1->total);
    int vl2 = abs(diag2->total);

    if (vl1 > vl2)
        return -1;
    else if (vl1 < vl2)
        return 1;
    else {
        return strcmp(diag1->diagnostico, diag2->diagnostico);
    }
}
void MudarPorcentagem_D(tDiagnostico *diagnostico,int qtd_l){
    if(qtd_l==0){
        diagnostico->porcentagem=0;
    }else{
    diagnostico->porcentagem = (diagnostico->total/(float)qtd_l)*100;
    }
}

void ImprimirDiagnosticos_D(tDiagnostico **diagnostico_vet,int tam, char *path){
    FILE * file = fopen(path, "a");
    
    if(!file){
        printf("Erro ao abrir o arquivo");
    }
    int i;
    for(i=0; i<tam;i++){
      
        fprintf(file,"- %s: %d (%.2f%%)\n", diagnostico_vet[i]->diagnostico, diagnostico_vet[i]->total, diagnostico_vet[i]->porcentagem);
        
    }
    fprintf(file,"\n");
    fclose(file);
    
}

tDiagnostico ** CriarVetDiagnostico(){
    tDiagnostico ** diagnostico_vet = (tDiagnostico **) malloc(sizeof(tDiagnostico*)*TIPOS_DIAGNOSTICOS);
    EhPonteiroNULL(diagnostico_vet);
    int pos=0;
    diagnostico_vet[pos] = CriarDiagnostico();
    strcpy(diagnostico_vet[pos]->diagnostico,"CARCINOMA ESPINOCELULAR");
    pos++;
    diagnostico_vet[pos] = CriarDiagnostico();
    strcpy(diagnostico_vet[pos]->diagnostico,"CERATOSE ACTINICA");
    pos++;
    diagnostico_vet[pos] = CriarDiagnostico();
     strcpy(diagnostico_vet[pos]->diagnostico,"CERATOSE SEBORREICA");
    pos++;
    diagnostico_vet[pos] = CriarDiagnostico();
      strcpy(diagnostico_vet[pos]->diagnostico,"CARCINOMA BASOCELULAR");

    pos++;
    diagnostico_vet[pos] = CriarDiagnostico();
    strcpy(diagnostico_vet[pos]->diagnostico,"MELANOMA");
  
    pos++;
    diagnostico_vet[pos] = CriarDiagnostico();
    strcpy(diagnostico_vet[pos]->diagnostico,"NEVO");
    
    return diagnostico_vet;
}
void PreencherNomeDiagnostico(tDiagnostico *diagnostico, char * str){
    strncpy(diagnostico->diagnostico,str,strlen(str));
}