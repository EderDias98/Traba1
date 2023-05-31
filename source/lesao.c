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
   //printf("Digite Rotulo\n");
    ConverterEmMaiusculas(rotulo);
    memset(lesao->rot,'\0',sizeof(lesao->rot));

    strncpy(lesao->rot,rotulo,strlen(rotulo));
    //printf("Digite Diagnostico\n");
    memset(lesao->diag,'\0',sizeof(lesao->diag));
    scanf("%[^\n]%*c", lesao->diag);
    ConverterEmMaiusculas(lesao->diag);
    //printf("Digite Regiao do Corpo\n");
    memset(lesao->reg_corp,'\0',sizeof(lesao->reg_corp));
    scanf("%[^\n]%*c", lesao->reg_corp);
    ConverterEmMaiusculas(lesao->reg_corp);
    //printf("Digite Tamanho\n");
    lesao->tam=0;
    scanf("%f%*c", &lesao->tam);
   // printf("Digite se é necessário cirurgia\n");
    memset(lesao->ciru,'\0',sizeof(lesao->ciru));
    scanf("%[^\n]%*c", lesao->ciru);
    ConverterEmMaiusculas(lesao->ciru);
    //printf("Digite se é necessáio crioterapia\n");
    memset(lesao->crio,'\0',sizeof(lesao->crio));
    scanf("%[^\n]%*c", lesao->crio);
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
        strcpy(str," - ENVIADA PARA CIRURGIA");
    }else if(!strcmp("SIM",lesao->crio)){
        strcpy(str, " - ENVIADA PARA CRIOTERAPIA");
    }
    // printf("@%s@", lesao->rot);
    if(lesao->tam==0){
        fprintf(file,"%s - %s - %s -  MM%s\n", lesao->rot, lesao->diag, lesao->reg_corp, str);
    }else{
        fprintf(file,"%s - %s - %s - %.0fMM%s\n", lesao->rot, lesao->diag, lesao->reg_corp, lesao->tam, str);
    }
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
int EhNumInt(float num) {
    int float_part = (int)num;  

    if (num == float_part) {
        return 1;  
    } else {
        return 0; 
    }
}