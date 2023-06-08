#include "pacientes.h"


#define TAM_INICIAL_PACIENTES 10
#define FORMATO_F %.2f
#define FORMATO_D %.0f

struct pacientes{
    tPaciente ** vet;
    int tam;
};

tPacientes* CriarPacientes(){
    tPacientes * pacientes = (tPacientes *) malloc(sizeof(tPacientes));
    EhPonteiroNULL(pacientes);

    pacientes->tam =0;
    return pacientes;
}

void CadastrarPacientes(tPacientes *pacientes){
    
    tPaciente *paciente = LerECriarPaciente();
    int idx=0;
    
    if(EhSusUnico(pacientes, RetornarSusPaciente(paciente))){
        if(pacientes->tam==0){
             pacientes->tam++;
             idx = pacientes->tam -1;
             pacientes->vet = CriarVetPacientes();
             pacientes->vet[idx] = paciente;
        }else{
        pacientes->tam++;
        idx = pacientes->tam -1;
        pacientes->vet = realloc(pacientes->vet, sizeof(tPaciente *)*pacientes->tam);
        pacientes->vet[idx] = paciente;
        // printf("%s",RetornarNomePaciente(pacientes->vet[idx]));
        // if(idx==2){
        //     exit(-1);
        // }
        }
    }else{
        printf("Nao é possivel cadastrar esse usuário pois ele já foi cadastrado\n");
        exit(-1);
    }
    
}

int EhSusUnico(tPacientes *pacientes, char *sus){
    int i;
    for(i=0;i<pacientes->tam;i++){
        if( !strcmp(sus,RetornarSusPaciente(pacientes->vet[i])))
            return 0;
    }
    return 1;
}
void LiberarPacientes(tPacientes *pacientes){
    int i;
     
    for(i=0; i<pacientes->tam;i++){
        if(!pacientes->vet){
            break;
        }
        LiberarPaciente(pacientes->vet[i]);
    }
   
    LiberarPonteiro(pacientes->vet);
    LiberarPonteiro(pacientes);
 }

void GerarRelatorio(tPacientes *pacientes,char *path){
    
    char path_r[60]; 
    sprintf(path_r,"%s/relatorio/relatorio_final",path);
    FILE *file = fopen(path_r,"w");
    // printf("\n%s\n", path_r);
    if(!file){
        printf("Erro em abrir o arquivo");
        exit(-1);
    }
    // Número total de pacientes que possui pelo menos um atendimento
    fprintf(file,"NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n",QtdPaciAten(pacientes->vet, pacientes->tam));
    int media = IdadeMedia(pacientes->vet, pacientes->tam);
   
    
    fprintf(file,"IDADE MEDIA: %d +- %d ANOS\n", media, DesvioPadraoIdade(pacientes->vet,pacientes->tam,media));
    float df,dm,dt;
    df = DistribuicaoFeminina(pacientes->vet,pacientes->tam);
    dm = DistribuicaoMasculina(pacientes->vet,pacientes->tam);
    dt = DistribuicaoOutros(pacientes->vet,pacientes->tam);
    
  
    fprintf(file,"DISTRIBUICAO POR GENERO:\n- FEMININO: %.2f%%\n",df);
    fprintf(file,"- MASCULINO: %.2f%%\n",dm);    
    fprintf(file,"- OUTROS: %.2f%%\n",dt);
    
    media =  TamanhoMedioLesao(pacientes->vet, pacientes->tam);
    fprintf(file,"TAMANHO MEDIO DAS LESOES: %d +- %.0f MM\n",media, DesvioPadraoLesoes(pacientes->vet, pacientes->tam,media));
    int qtd_l = RetornarQtdLesoes(pacientes->vet, pacientes->tam);
    fprintf(file,"NUMERO TOTAL DE LESOES: %d\n",qtd_l );
    int qtd_ci=RetornarQtdCirurgias1(pacientes->vet, pacientes->tam);
    int qtd_cr = RetornarQtdCrioterapias1(pacientes->vet, pacientes->tam);
    float pc=RetornarPorcentagem(qtd_ci,qtd_l);
    float pt = RetornarPorcentagem(qtd_cr,qtd_l);
   
    fprintf(file,"NUMERO TOTAL DE CIRURGIAS: %d (%.2f%%)\n",qtd_ci,pc);

    fprintf(file,"NUMERO TOTAL DE CRIOTERAPIA: %d (%.2f%%)\n",qtd_cr,pt);
    
    fprintf(file,"DISTRIBUICAO POR DIAGNOSTICO:\n");

    tDiagnosticos *diagnosticos= CriarDiagnosticos();
  
    PreencherDiagnosticos_P(diagnosticos, pacientes->vet, pacientes->tam);
   
    OrdernarDiagnosticos(diagnosticos);
 
    MudarPorcentagem(diagnosticos, qtd_l);
    fclose(file);
    ImprimirDiagnosticos(diagnosticos, path_r);
    
    LiberarDiagnosticos(diagnosticos);
 }
 void RealizarConsulta(tPacientes * pacientes, char *path){

    char sus[20];
    scanf("%s%*c", sus);

    int idx;
    if( (idx = AcharIndexPacientes(pacientes,sus)) == -1){
        printf("O paciente precisa estar cadastrado\n");
        exit(-1);
    }
    AtenderPaciente(pacientes->vet[idx], path);
     

 }
int  AcharIndexPacientes(tPacientes * pacientes,char *sus){
    int i;
 
    for(i=0;i<pacientes->tam;i++){
        if( !strcmp(sus,RetornarSusPaciente(pacientes->vet[i])))
            return i;
    }
    return -1;
} 
void RealizarBusca(tPacientes * pacientes, char *path){
    char sus[20];
    scanf("%s%*c", sus);
    // printf("\n%s\n",RetornarNomePaciente(pacientes->vet[0]));
    int idx;
    if( (idx = AcharIndexPacientes(pacientes,sus)) == -1){
        printf("O paciente precisa estar cadastrado\n");
        exit(-1);
    }
    
    EscreverPaciente(pacientes->vet[idx],sus,path);
    
}
float RetornarPorcentagem(int n, int total){
    if(total==0){
        return 0;
    }
    return (n/(float)total)*100;
}