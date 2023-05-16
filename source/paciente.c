#include "paciente.h"
#define TAM_MAX_NOME 100


struct paciente{
    char*nome;
    char sus[19];
    char tel[15];
    char gen[10];
    tData *nasc;
    //consulta
    int diab;
    int fuma;
    int aler;
    char *alerg;
    int hist_canc;
    char pele[4];
    //Para poder contar o numeros de pacientes com pelo menos um atendimento;
    int atendimento;
    tLesoes * lesoes;

};
struct data{
  int dia,mes,ano;
};

tPaciente *LerECriarPaciente(){
    tPaciente *paciente = (tPaciente *) malloc(sizeof(tPaciente));
    
    char nome[TAM_MAX_NOME];
    scanf("%s%*c", nome);
    paciente->nome = (char *) malloc(sizeof(char)*(strlen(nome)+1));
    memset(paciente->nome,'\0',strlen(nome)+1);
    strncpy(paciente->nome,nome,strlen(nome));
    
    paciente->nasc = (tData *) malloc(sizeof(tData));
    scanf("%d/%d/%d", &paciente->nasc->dia, &paciente->nasc->mes, &paciente->nasc->ano);
    if(!EhDataCerta(paciente->nasc))
        printf("A data de nascimento do paciente %s está errada!\n",paciente->nome);
    
    scanf("%s%*c", paciente->sus);
    
    scanf("%s%*c", paciente->tel);
    
    scanf("%s%*c",paciente->gen);    
    return paciente;
}
int RetornarSusPaciente(tPaciente *paciente){
    return paciente->sus;
}