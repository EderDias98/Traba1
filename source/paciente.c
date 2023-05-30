#include "paciente.h"
#include "data.h"

#define TAM_MAX_NOME 100


struct paciente{
    char nome[TAM_MAX_NOME];
    char sus[20];
    char tel[17];
    char gen[10];
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
    EhPonteiroNULL(paciente);
    scanf("%[^\n]%*c", paciente->nome);
    ConverterEmMaiusculas(paciente->nome);
    // paciente->nome = (char *) malloc(sizeof(char)*(strlen(nome)+1));
    // memset(paciente->nome,'\0',strlen(nome)+1);
    // strncpy(paciente->nome,nome,strlen(nome));
    scanf("%s%*c", paciente->sus);
    paciente->nasc = CriarELerData();
    if(!EhDataCerta(paciente->nasc))
        printf("A data de nascimento do paciente %s está errada!\n",paciente->nome);
    
    scanf("%s%*c", paciente->tel);
    
    scanf("%s%*c",paciente->gen);
     ConverterEmMaiusculas(paciente->gen);
    paciente->atendimento=0;

    return paciente;
}
char * RetornarSusPaciente(tPaciente *paciente){
    return paciente->sus;
}
void LiberarPaciente(tPaciente *paciente){

    LiberarData(paciente->nasc);    
    LiberarLesoes(paciente->lesoes);
    LiberarPonteiro(paciente);
}
tPaciente **CriarVetPacientes(){
    tPaciente **paciente_vet = (tPaciente **) malloc(sizeof(tPaciente *));
    EhPonteiroNULL(paciente_vet);
    return paciente_vet;
}
void EscreverRelatorio(tPaciente *paciente,char *path){
    char path_r[60]; 
    sprintf(path_r,"%s/relatorio/relatorio_final",path);
    FILE *file = fopen(path_r,"a");
    // printf("\n%s\n", path_r);
    if(!file)
        printf("Erro em abrir o arquivo");
    fprintf(file,"%s\n%s\n%s\n",paciente->nome, paciente->sus, paciente->gen);
    fclose(file);
}
void AtenderPaciente(tPaciente *paciente, char *path){
    paciente->atendimento=1;
    printf("O paciente possui diabetes?\n");
    scanf("%s%*c",paciente->diab);
    ConverterEmMaiusculas(paciente->diab);
    printf("O paciente é fumante?\n");
    scanf("%s%*c",paciente->fuma);
    ConverterEmMaiusculas(paciente->fuma);
    printf("O paciente possui alergia a algum medicamento?\n");
    scanf("%s%*c",paciente->alerg);
    ConverterEmMaiusculas(paciente->alerg);
    if(!strcmp(paciente->alerg, "SIM")){
        printf("Quais medicamentos?\n");
        scanf("%s%*c",paciente->nome_alerg);
        ConverterEmMaiusculas(paciente->nome_alerg);
    }
    printf("O paciente possui histórico de câncer?\n");
    scanf("%s%*c",paciente->hist_canc);
    ConverterEmMaiusculas(paciente->hist_canc);
    printf("Qual o tipo de pele do paciente?\n");
    scanf("%s%*c", paciente->pele);
    ConverterEmMaiusculas(paciente->pele);
  
    paciente->lesoes =  CadastrarLesoes(paciente->lesoes);
    
    ArmazenarLogs(paciente->lesoes, paciente->sus,path);
    
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
    fprintf(file,"DATA DE NASCIMENTO: %02d/%02d/%d (%d ANOS)\n",Dia(paciente->nasc),
    Mes(paciente->nasc),Ano(paciente->nasc), idade);
    fprintf(file,"GENERO: %s\n", paciente->gen);
    fprintf(file,"TELEFONE: %s\n",paciente->tel);
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
        if(!strcmp(pacientes_vet[i]->gen,"MASCULINO")){
            soma+=1;
        }
    }
    return (soma/(float)tam)*100;
}
float DistribuicaoFeminina(tPaciente ** pacientes_vet, int tam){
    int soma=0,i;
    for(i=0; i<tam;i++){
        if(!strcmp(pacientes_vet[i]->gen,"FEMININO")){
            soma+=1;
        }
    }
    return (soma/(float)tam)*100;
}
float DistribuicaoOutros(tPaciente ** pacientes_vet, int tam){
    int soma=0,i;
    for(i=0; i<tam;i++){
        if(!strcmp(pacientes_vet[i]->gen,"FEMININO") && !strcmp(pacientes_vet[i]->gen,"MASCULINO")){
            soma+=1;
        }
    }
    return (soma/(float)tam)*100;
}
float TamanhoMedioLesao(tPaciente **paciente_vet, int tam){
    int i,j,soma=0, cont=0,tam_l=0;
    for(i=0; i<tam; i++){
        tam_l =RetornarTamLesoes(paciente_vet[i]->lesoes);
        for(j=0; j<tam_l;j++){
            soma +=RetornarTamLesao1(paciente_vet[i]->lesoes,j);
            cont++;
        }
    }
    if(cont==0){
        return 0;
    }
    return (soma/cont);
}
float DesvioPadraoLesoes(tPaciente **paciente_vet,int tam, int media){
    int i,j,desvio_p=0, cont=0,tam_l=0;
    for(i=0; i<tam; i++){
        tam_l =RetornarTamLesoes(paciente_vet[i]->lesoes);
        for(j=0; j<tam_l;j++){
            desvio_p += pow(RetornarTamLesao1(paciente_vet[i]->lesoes,j) - media,2);
            cont++;
        }
    }
    if(cont==0){
        return cont;
    }
    desvio_p = sqrt(desvio_p/cont);
    return desvio_p;   
}
int RetornarQtdLesoes(tPaciente **paciente_vet,int tam){
    int i,j,cont=0,tam_l=0;
    for(i=0; i<tam; i++){
        tam_l =RetornarTamLesoes(paciente_vet[i]->lesoes);
        for(j=0; j<tam_l;j++){
            cont++;
        }
    }
    return cont;
}
int RetornarQtdCirurgias1(tPaciente **paciente_vet,int tam){
    int i,cont=0;
    for(i=0; i<tam; i++){
        cont+= RetornarQtdCirurgias2(paciente_vet[i]->lesoes);
    }
    return cont;    
}
int RetornarQtdCrioterapias1(tPaciente **paciente_vet,int tam){
    int i,cont=0;
    for(i=0; i<tam; i++){
        cont+= RetornarQtdCrioterapias2(paciente_vet[i]->lesoes);
    }
    return cont;    
}
void PreencherDiagnosticos_P(tDiagnosticos *diagnosticos, tPaciente **pacientes_vet, int tam_p){
    int i;
    
    for(i=0; i<tam_p;i++){
    PreencherDiagnosticos_L(diagnosticos,pacientes_vet[i]->lesoes,RetornarTamLesoes(pacientes_vet[i]->lesoes));
   
    }
}
char *RetornarNomePaciente(tPaciente *paciente){
    return paciente->nome;
}
