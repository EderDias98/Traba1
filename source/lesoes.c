#include "lesoes.h"
#include "paciente.h"

struct lesoes{
    tLesao **vet;
    int tam;
    int qtd_ciru;
    int qtd_crio; 
};

tLesoes *CriarLesoes(){
    tLesoes *lesoes = (tLesoes *) malloc(sizeof(tLesoes));
    EhPonteiroNULL(lesoes);
    lesoes->vet = NULL;
    lesoes->tam=0; 
    lesoes->qtd_ciru=0;
    lesoes->qtd_crio=0;
    return lesoes;
}


tLesoes * PreencherLesoes(tLesoes *lesoes, char *rotulo){
    if(lesoes->tam==0){
        lesoes->tam++;
        lesoes->vet = CriarVetLesao();
        lesoes->vet[lesoes->tam-1] = CriarELerLesao(rotulo);
    }else{
    lesoes->tam++;
    int idx =lesoes->tam-1;
    lesoes->vet = realloc(lesoes->vet, sizeof(tLesao*)*(lesoes->tam));
    lesoes->vet[idx] = CriarELerLesao(rotulo);
    }
    return lesoes;
}
void LiberarLesoes(tLesoes *lesoes){
    int i;
    for(i=0; i<lesoes->tam; i++){
        if(!lesoes->vet){
            break;
        }
       LiberarLesao(lesoes->vet[i]);
    }
    LiberarPonteiro(lesoes->vet);
    LiberarPonteiro(lesoes);
}
tLesoes * CadastrarLesoes(tLesoes *lesoes){
    lesoes = CriarLesoes();
    int i;
    char rotulo[4];
    memset(rotulo, '\0', sizeof(rotulo));
    for(i=0;;i++){ 
        scanf("%[^\n]%*c",rotulo);
        if(!strcmp("E", rotulo)){
            break;
        }
        lesoes = PreencherLesoes(lesoes,rotulo);
       

    }
    lesoes->qtd_ciru = RetornarQtdCiru(lesoes->vet,lesoes->tam);
    lesoes->qtd_crio = RetornarQtdCrio(lesoes->vet,lesoes->tam);
    return lesoes;
 }
void ArmazenarLogs(tLesoes *lesoes,char *sus, char *path){

    char path_r[60];
    static int id=0;
    id++;

    sprintf(path_r,"%s/logs/log_%d",path, id);
    // printf("%s\n",path_r);
    FILE *file = fopen(path_r,"w");
    fprintf(file,"%s\n", sus);
       
    for(int i=0;i<lesoes->tam;i++){
        fprintf(file,"%s\n", RetornarRotulo(lesoes->vet[i]));
    }
    fclose(file);
}
void EscreverLesoes(tLesoes * lesoes, char *path){
    FILE *file = fopen(path,"a");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        exit(-1);
    }
    fprintf(file,"LESOES:\n");
    if(lesoes->tam){
    fprintf(file,"TOTAL: %d\n", lesoes->tam);
    lesoes->qtd_ciru = RetornarQtdCiru(lesoes->vet, lesoes->tam);
    lesoes->qtd_crio = RetornarQtdCrio(lesoes->vet, lesoes->tam);
    fprintf(file,"ENVIADA PARA CIRURGIA: %d\n", lesoes->qtd_ciru);
    fprintf(file,"ENVIADA PARA CRIOTERAPIA: %d\n", lesoes->qtd_crio);
    fprintf(file,"DESCRICAO DAS LESOES:\n");
    int i;
    for(i=lesoes->tam-1; i>=0;i--){
        EscreverLesao(lesoes->vet[i],path);
    }
    }
    fclose(file);
}
int RetornarTamLesoes(tLesoes *lesoes){
    return lesoes->tam;
}
int RetornarTamLesao1(tLesoes *lesoes, int idx){

    return RetornarTamLesao2(lesoes->vet[idx]);
}
int RetornarQtdCirurgias2(tLesoes *lesoes){
    return lesoes->qtd_ciru;
 }
int RetornarQtdCrioterapias2(tLesoes *lesoes){
    return lesoes->qtd_crio;
 }
void PreencherDiagnosticos_L(tDiagnosticos *diagnosticos,tLesoes *lesoes, int tam){
    int i;
    for(i=0; i<tam; i++){
        PreencherDiagnosticos_D(diagnosticos,RetornarNomeDiagnostico_L(lesoes->vet[i]));
       
    }
}