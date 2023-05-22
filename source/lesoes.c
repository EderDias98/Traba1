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
    lesoes->tam=0; 
    lesoes->qtd_ciru=0;
    lesoes->qtd_crio=0;
}


tLesoes *CriarVetorLesoes(tLesoes *lesoes){
    if(lesoes->tam==0){
        lesoes->tam++;
        lesoes->vet = (tLesao **) malloc(sizeof(tLesao*));
        lesoes->vet[lesoes->tam-1] = CriarELerLesao();
        return lesoes;
    }
    lesoes->tam++;
    int idx =lesoes->tam-1;
    lesoes->vet = realloc(lesoes->vet, sizeof(tLesao*)*(lesoes->tam));
    lesoes->vet[idx] = CriarELerLesao();

    return lesoes;
}
void LiberarLesoes(tLesoes *lesoes){
    int i;
    for(i=0; i<lesoes->tam; i++){
        if(!lesoes->vet[i])
            free(lesoes->vet[i]);
    }
    if(!lesoes->vet)
        free(lesoes->vet);
    if(!lesoes)
        free(lesoes);
}
tLesoes * CadastrarLesoes(tLesoes *lesoes){
    lesoes = CriarLesoes();
    printf("Quantidade de lesoes\n");
    int n;
    scanf("%d%*c", &n);
    int i;
    for(i=0;i<n;i++){
        lesoes = CriarVetorLesoes(lesoes);
    }
    for(i=0; i<lesoes->tam;i++){
        if(EhCirurgia(lesoes->vet[i])){
            lesoes->qtd_ciru++;
        }
        if(EhCrioterapia(lesoes->vet[i])){
            lesoes->qtd_crio++;
        }
    }
    return lesoes;
 }
void ArmazenarLogs(tLesoes *lesoes,char *sus, char *path){

    char **log =(char **) malloc(sizeof (char *));
    char path_r[60];
    static int id=0;
    id++;

    sprintf(path_r,"%s/logs/log_%d",path, id);
    printf("%s\n",path_r);
     
    FILE *file = fopen(path_r,"a");
    fprintf(file,"%s\n", sus);
     
    for(int i=0;i<lesoes->tam;i++){
        log[0] = RetornarLog(lesoes->vet[i]);
        
        fprintf(file,"%s\n", log[0]);  

    }
    free(log);
    fclose(file);
}
void EscreverLesoes(tLesoes * lesoes, char *path){
    FILE *file = fopen(path,"a");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        exit(-1);
    }
    fprintf(file,"LESOES:\n");
    fprintf(file,"TOTAL: %d\n", lesoes->tam);
    lesoes->qtd_ciru = RetornarQtdCiru(lesoes->vet, lesoes->tam);
    lesoes->qtd_crio = RetornarQtdCrio(lesoes->vet, lesoes->tam);
    fprintf(file,"ENVIADA PARA CIRURGIA: %d\n", lesoes->qtd_ciru);
    fprintf(file,"ENVIADA PARA CRIOTERAPIA: %d\n\n", lesoes->qtd_crio);
    fprintf(file,"DESCRICAO DAS LESOES:\n");
    int i;
    for(i=0; i<lesoes->tam;i++){
        EscreverLesao(lesoes->vet[i],path);
    }

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
tDiagnosticos *PreencherDiagnosticos2(tDiagnosticos *diagnosticos,tLesoes *lesoes, int tam){
    int i;
    char **str = (char *) malloc(sizeof(char*));
    for(i=0; i<tam; i++){
        str =RetornarDiagnostico(diagnosticos,lesoes->vet[i]);
        diagnosticos = PreencherDiagnosticos3(diagnosticos,*str)
    }
    free(str);
}