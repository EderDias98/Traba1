#include "paciente.h"


#define TAM_MAX_NOME 100


struct paciente{
    char nome[TAM_MAX_NOME];
    char sus[20];
    char tel[15];
    char gen;
    tData *nasc;
    //consulta
    char diab[4];
    char fuma[4];
    char alerg[4];
    char nome_alerg[100];
    char hist_canc[4];
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
    if(!paciente)
        printf("Não foi possível alocar a memória do paciente\n");
    
    scanf("%[^\n]%*c", paciente->nome);
    // paciente->nome = (char *) malloc(sizeof(char)*(strlen(nome)+1));
    // memset(paciente->nome,'\0',strlen(nome)+1);
    // strncpy(paciente->nome,nome,strlen(nome));
    
    paciente->nasc = CriarELerData();
    if(!EhDataCerta(paciente->nasc))
        printf("A data de nascimento do paciente %s está errada!\n",paciente->nome);
    
    scanf("%s%*c", paciente->sus);
    
    // scanf("%s%*c", paciente->tel);
    
    scanf("%c%*c",&paciente->gen);

    return paciente;
}
char * RetornarSusPaciente(tPaciente *paciente){
    return paciente->sus;
}
void LiberarPaciente(tPaciente *paciente){

    if(!paciente->nasc)
        free(paciente->nasc);
    if(!paciente->lesoes)
        LiberarLesoes(paciente->lesoes);
    free(paciente);
}
tPaciente **CriarVetPacientes(){
    tPaciente **vet_paciente = (tPaciente **) malloc(sizeof(tPaciente *));
    if(!vet_paciente)
        printf("vet_paciente é NULL");
    return vet_paciente;
}
void EscreverRelatorio(tPaciente *paciente,char *path){
    char path_r[60]; 
    sprintf(path_r,"%s/relatorio/relatorio_final",path);
    FILE *file = fopen(path_r,"a");
    // printf("\n%s\n", path_r);
    if(!file)
        printf("Erro em abrir o arquivo");
    fprintf(file,"%s\n%s\n%c\n",paciente->nome, paciente->sus, paciente->gen);
    fclose(file);
}
tPaciente * AtenderPaciente(tPaciente *paciente, char *path){
    printf("O paciente possui diabetes?\n");
    scanf("%s%*c",paciente->diab);
    printf("O paciente é fumante?\n");
    scanf("%s%*c",paciente->fuma);
    printf("O paciente possui alergia a algum medicamento?\n");
    scanf("%s%*c",paciente->alerg);
    if(!strcmp(paciente->alerg, "SIM")){
        printf("Quais medicamentos?\n");
        scanf("%s%*c",paciente->nome_alerg);
    }
    printf("O paciente possui histórico de câncer?\n");
    scanf("%s%*c",paciente->hist_canc);
    printf("Qual o tipo de pele do paciente?\n");
    scanf("%s%*c", paciente->pele);
  
    paciente->lesoes  = CadastrarLesoes(paciente->lesoes);
    
    ArmazenarLogs(paciente->lesoes, paciente->sus,path);
    return paciente;
}
 void EscreverPaciente(tPaciente *paciente,char *sus, char *path){
    char path_r[60];
    sprintf(path_r,"%s/buscas/busca_%d",path, sus);
    printf("%s\n",path_r);
     
    FILE *file = fopen(path_r,"w");
    fprintf(file,"NOME: %s\n", paciente->nome);
    int idade = CalcularIdade(paciente->nasc);
    fprintf(file,"DATA DE NASCIMENTO: %d/%d/%d (%d)ANOS\n",Dia(paciente->nasc),
    Mes(paciente->nasc),Ano(paciente->nasc), idade);
    if(paciente->gen =='M'){
        fprintf(file,"GENERO: MASCULINO\n");
    }else{
        fprintf(file,"GENERO: FEMININO\n");

    }
    fprintf(file,"TELEFONE: %s\n\n",paciente->tel);
    fprintf(file,"DIABETES: %s\n",paciente->diab);
    fprintf(file,"FUMANTE: %s\n",paciente->fuma );
    fprintf(file,"ALERGIA A MEDICAMENTO: %s\n", paciente->alerg);
    fprintf(file,"HISTORICO DE CANCER: %s\n", paciente->hist_canc);
    fprintf(file, "TIPO DE PELE: %s\n", paciente->pele);
    
 }
 DIABETES: SIM
FUMANTE: NAO
ALERGIA A MEDICAMENTO: NAO
HISTORICO DE CANCER: NAO
TIPO DE PELE: II