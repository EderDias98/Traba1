#include "lesao.h"

struct lesao{
    //(L1,L2,...,Ln);
    char rot[10];//rotulos
    char diag[40];//diagnósticos
    char reg_corp[30];//regiao do corpo
    float tam;//tamanhoa em mm da lesao
    char ciru[4];// enviado para cirurgia
    char crio[4];//enviado para crioterapia

};

tLesao *CriarELerLesao(char *rotulo){

    //Criar lesao
    tLesao *lesao = (tLesao *) malloc(sizeof(tLesao));
    EhPonteiroNULL(lesao);
    //Ler lesao
    printf("Digite Rotulo\n");
    ConverterEmMaiusculas(rotulo);
    strncpy(lesao->rot,rotulo,strlen(rotulo));
    printf("Digite Diagnostico\n");
    scanf("%[^\n]%*c", lesao->diag);
    ConverterEmMaiusculas(lesao->diag);
    printf("Digite Regiao do Corpo\n");
    scanf("%[^\n]%*c", lesao->reg_corp);
    ConverterEmMaiusculas(lesao->reg_corp);
    printf("Digite Tamanho\n");
    scanf("%f%*c", &lesao->tam);
    printf("Digite se é necessário cirurgia\n");
    scanf("%s%*c", lesao->ciru);
    ConverterEmMaiusculas(lesao->ciru);
    printf("Digite se é necessáio crioterapia\n");
    scanf("%s%*c", lesao->crio);
    ConverterEmMaiusculas(lesao->crio);
    return lesao;
}
tLesao **CriarVetLesao(){
  tLesao ** lesao_vet =(tLesao **)  malloc(sizeof(tLesao*));
  EhPonteiroNULL(lesao_vet);
  return lesao_vet;
}
void LiberarLesao(tLesao* lesao){
    LiberarPonteiro(lesao);
}

 int RetornarQtdCiru(tLesao **lesao, int tam){
    int i,cont=0;
    for(i=0; i<tam;i++){
        if(!strcmp("SIM", lesao[i]->ciru)){
            cont++;
        }
    }
    return cont;
 }
 int RetornarQtdCrio(tLesao **lesao, int tam){
    int i,cont=0;
    for(i=0; i<tam;i++){
        if(!strcmp("SIM", lesao[i]->crio)){
            cont++;
        }
    }
    return cont;
 }
 void EscreverLesao(tLesao *lesao,char *path){
    FILE * file= fopen(path,"a");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        exit(-1);
    }
    char str[30];
    memset(str,'\0', sizeof(str));
    if( !strcmp("SIM",lesao->ciru)){
        strcpy(str,"- ENVIADA PARA CIRURGIA");
    }else if(!strcmp("SIM",lesao->crio)){
        strcpy(str, "- ENVIADA PARA CRIOTERAPIA");
    }
    // printf("@%s@", lesao->rot);
    fprintf(file,"%s - %s - %s - %.0fMM %s\n", lesao->rot, lesao->diag, lesao->reg_corp, lesao->tam, str);
 }

 int RetornarTamLesao2(tLesao * lesao){
    return lesao->tam;
 }

char * RetornarNomeDiagnostico_L(tLesao *lesao){
    return  lesao->diag;
}
char *RetornarRotulo(tLesao *lesao){
    return lesao->rot;
}

void EhPonteiroNULL(void *p){
    if(!p){
        printf("O ponteiro é NULL");
        exit(-1);
    }
}
void ConverterEmMaiusculas(char *str){
    int i;
    for(i=0;str[i];i++){
        if(isalpha(str[i])){
            str[i] = toupper(str[i]);
        }
    }
}
void LiberarPonteiro(void *p){
    if(p){
       free(p); 
    }
}