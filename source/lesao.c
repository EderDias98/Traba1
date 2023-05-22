#include "lesao.h"

struct lesao{
    //(L1,L2,...,Ln);
    char rot[10];//rotulos
    char diag[40];//diagnósticos
    char reg_corp[30];//regiao do corpo
    float tam;//tamanhoa em mm da lesao
    int ciru;// enviado para cirurgia
    int crio;//enviado para crioterapia

};

tLesao *CriarELerLesao(){

    //Criar lesao
    tLesao *lesao = (tLesao *) malloc(sizeof(tLesao));
    //Ler lesao
    printf("Digite Rotulo\n");
    scanf("%[^\n]%*c", lesao->rot);
    printf("Digite Diagnostico\n");
    scanf("%[^\n]%*c", lesao->diag);
    printf("Digite Regiao do Corpo\n");
    scanf("%[^\n]%*c", lesao->reg_corp);
    printf("Digite Tamanho\n");
    scanf("%f%*c", &lesao->tam);
    printf("Digite se é necessário cirurgia\n");
    scanf("%d%*c", &lesao->ciru);
    printf("Digite se é necessáio crioterapia\n");
    scanf("%d%*c", &lesao->crio);
    printf("%s\n", lesao->reg_corp);
    return lesao;
}
 char * RetornarLog(tLesao *lesao){
    return lesao->rot;
 }
 int RetornarQtdCiru(tLesao **lesao, int tam){
    int i,cont=0;
    for(i=0; i<tam;i++){
        cont += lesao[i]->ciru;
    }
    return cont;
 }
 int RetornarQtdCrio(tLesao **lesao, int tam){
    int i,cont=0;
    for(i=0; i<tam;i++){
        cont += lesao[i]->crio;
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
    if(lesao->ciru){
        strcpy(str,"- ENVIADA PARA CIRURGIA")
    }else if(lesao->crio){
        strcpy(str, "- ENVIADA PARA CRIOTERAPIA");
    }

    fprintf(file,"%s - %s - %s - %.0fMM %s\n", lesao->rot, lesao->diag, lesao->reg_corp, lesao->tam, str);
 }

 int RetornarTamLesao2(tLesao * lesao){
    return lesao->tam;
 }
int EhCirurgia(tLesao * lesao){
    return lesao->ciru;
}
int EhCrioterapia(tLesao * lesao){
    return lesao->crio;
}
