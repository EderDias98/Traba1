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
    paciente->atendimento=0;

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
    paciente->atendimento=1;
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
    sprintf(path_r,"%s/buscas/busca_%s",path, sus);
    FILE *file = fopen(path_r,"w");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        exit(-1);
    }

    fprintf(file,"NOME: %s\n", paciente->nome);
    int idade = CalcularIdade(paciente->nasc);
    fprintf(file,"DATA DE NASCIMENTO: %d/%d/%d (%d)ANOS\n",Dia(paciente->nasc),
    Mes(paciente->nasc),Ano(paciente->nasc), idade);
    if(paciente->gen =='M'){
        fprintf(file,"GENERO: MASCULINO\n");
    }else if(paciente->gen=='F'){
        fprintf(file,"GENERO: FEMININO\n");
    }else {
        fprintf(file,"GENERO: OUTROS\n");
    }
    fprintf(file,"TELEFONE: %s\n\n",paciente->tel);
    fprintf(file,"DIABETES: %s\n",paciente->diab);
    fprintf(file,"FUMANTE: %s\n",paciente->fuma );
    fprintf(file,"ALERGIA A MEDICAMENTO: %s\n", paciente->alerg);
    fprintf(file,"HISTORICO DE CANCER: %s\n", paciente->hist_canc);
    fprintf(file,"TIPO DE PELE: %s\n", paciente->pele);
    fclose(file);
    EscreverLesoes(paciente->lesoes, path_r);
    
 }
int QtdPaciAten(tPaciente ** pacientes_vet, int tam){
    int i,cont=0;
    for(i=0 ;i<tam;i++){
        cont +=pacientes_vet[i]->atendimento;
    }
    return cont;
}
int IdadeMedia(tPaciente ** pacientes_vet, int tam){
    int i,cont=0;
    for(i=0 ;i<tam;i++){
        cont += CalcularIdade(pacientes_vet[i]->nasc);
    }
    return (cont/tam);
}
int DesvioPadraoIdade(tPaciente ** pacientes_vet, int tam, int media){
    int i,desvio_p=0;
    for(i=0; i<tam;i++){
        desvio_p += pow(CalcularIdade(pacientes_vet[i]->nasc) - media, 2); 
    }
    desvio_p = sqrt(desvio_p/tam);
    return desvio_p;
}
float DistribuicaoMasculina(tPaciente ** pacientes_vet, int tam){
    int soma=0,i;
    for(i=0; i<tam;i++){
        if(pacientes_vet[i]->gen == 'M'){
            soma+=1;
        }
    }
    return (soma/(float)tam);
}
float DistribuicaoFeminina(tPaciente ** pacientes_vet, int tam){
    int soma=0,i;
    for(i=0; i<tam;i++){
        if(pacientes_vet[i]->gen == 'F'){
            soma+=1;
        }
    }
    return (soma/(float)tam);
}
float DistribuicaoOutros(tPaciente ** pacientes_vet, int tam){
    int soma=0,i;
    for(i=0; i<tam;i++){
        if(!(pacientes_vet[i]->gen == 'F') && !(pacientes_vet[i]->gen == 'M')){
            soma+=1;
        }
    }
    return (soma/(float)tam);
}
float TamanhoMedioLesao(tPaciente **paciente_vet, int tam){
    int i,j,soma=0, cont=0;
    for(i=0; i<tam; i++){
        for(j=0; j<RetornarTamLesoes(paciente_vet[i]->lesoes);j++){
            soma +=RetornarTamLesao1(paciente_vet[i]->lesoes,j);
            cont++;
        }
    }
    return (soma/cont);
}
float DesvioPadraoLesoes(tPaciente **paciente_vet,int tam, int media){
    int i,j,desvio_p=0, cont=0;
    for(i=0; i<tam; i++){
        for(j=0; j<RetornarTamLesoes(paciente_vet[i]->lesoes);j++){
            desvio_p += pow(RetornarTamLesao1(paciente_vet[i]->lesoes,j) - media,2);
            cont++;
        }
    }
    desvio_p = sqrt(desvio_p/cont);
    return desvio_p;   
}
int RetornarQtdLesoes(tPaciente **paciente_vet,int tam){
    int i,j,cont=0;
    for(i=0; i<tam; i++){
        for(j=0; j<RetornarTamLesoes(paciente_vet[i]->lesoes);j++){
            cont++;
        }
    }
    return cont;
}
int RetornarQtdCirurgias1(tPaciente **paciente_vet,int tam){
    int i,j,cont=0;
    for(i=0; i<tam; i++){
        cont+= RetornarQtdCirurgias2(paciente_vet[i]->lesoes);
    }
    return cont;    
}
int RetornarQtdCrioterapias1(tPaciente **paciente_vet,int tam){
    int i,j,cont=0;
    for(i=0; i<tam; i++){
        cont+= RetornarQtdCrioterapias2(paciente_vet[i]->lesoes);
    }
    return cont;    
}
tDiagnosticos * PreencherDiagnosticos1(tDiagnosticos *diagnosticos, tPaciente **pacientes_vet, int tam_p){
    int i;
    for(i=0; i<tam;i++){
        PreencherDiagnosticos2(diagnosticos,pacientes_vet[i]->lesoes);
    }
}