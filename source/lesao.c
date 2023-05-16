#include "lesao.h"

struct lesao{
    //(L1,L2,...,Ln);
    char rot[3];//rotulos
    char *diag;//diagnósticos
    char *reg_corp;//regiao do corpo
    float tam;//tamanhoa em mm da lesao
    int ciru;// enviado para cirurgia
    int crio;//enviado para crioterapia

};

tLesao *Lesao(){
    //Ler lesao


    //Criar lesao
    tLesao *lesao = (tLesao *) malloc(sizeof(tLesao));
    //Criar rotulos para cada paciente;
    return lesao;
}