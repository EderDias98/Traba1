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