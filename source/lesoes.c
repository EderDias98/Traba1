#include "lesoes.h"


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

tLesoes *LerLesoes(tLesoes *lesoes){
    lesoes->vet = CriarVetorLesoes();
    lesoes->tam++;
}