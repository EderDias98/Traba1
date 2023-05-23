#include "pacientes.h"


#define TAM_INICIAL_PACIENTES 10

struct pacientes{
    tPaciente ** vet;
    int tam;
};

tPacientes* CriarPacientes(){
    tPacientes * pacientes = (tPacientes *) malloc(sizeof(tPacientes));
    pacientes->vet = (tPaciente **) malloc(sizeof(tPaciente *)*TAM_INICIAL_PACIENTES);
    pacientes->tam =0;
    return pacientes;
}

tPacientes *CadastrarPacientes(tPacientes *pacientes){
    
    tPaciente *paciente = LerECriarPaciente();
    int idx=0;
    if(EhSusUnico(pacientes, RetornarSusPaciente(paciente))){
        if(pacientes->tam==0){
             pacientes->tam++;
             idx = pacientes->tam -1;
             pacientes->vet = CriarVetPacientes();
             pacientes->vet[idx] = paciente;
             return pacientes;
        }
        pacientes->tam++;
        idx = pacientes->tam -1;
        pacientes->vet = realloc(pacientes->vet, sizeof(tPaciente *)*pacientes->tam);
        pacientes->vet[idx] = paciente;
    }else{
        printf("Nao é possivel cadastrar esse usuário pois ele já foi cadastrado\n");
    }

    return pacientes;
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
        if(!pacientes->vet[i])
            LiberarPaciente(pacientes->vet[i]);
    }
    free(pacientes);
 }

void GerarRelatorio(tPacientes *pacientes,char *path){
    char path_r[60]; 
    sprintf(path_r,"%s/relatorio/relatorio_final",path);
    FILE *file = fopen(path_r,"w");
    // printf("\n%s\n", path_r);
    if(!file)
        printf("Erro em abrir o arquivo");
 
    // Número total de pacientes que possui pelo menos um atendimento
    fprintf(file,"NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n",QtdPaciAten(pacientes->vet, pacientes->tam));
    int media = IdadeMedia(pacientes->vet, pacientes->tam);
    fprintf(file,"IDADE MEDIA: %d +- %d ANOS\n", media, DesvioPadraoIdade(pacientes->vet,pacientes->tam,media));
    fprintf(file,"DISTRIBUICAO POR GENERO:\n - FEMININO: %.2f\n- MASCULINO: %.2f\n- OUTROS: %.2f\n",
    DistribuicaoFeminina(pacientes->vet,pacientes->tam),DistribuicaoMasculina(pacientes->vet,pacientes->tam),DistribuicaoOutros(pacientes->vet,pacientes->tam));
    media =  TamanhoMedioLesao(pacientes->vet, pacientes->tam);
    fprintf(file,"TAMANHO MEDIO DAS LESOES: 18 +- 5 MM\n",media, DesvioPadraoLesoes(pacientes->vet, pacientes->tam,media));
    int qtd_l = RetornarQtdLesoes(pacientes->vet, pacientes->tam);
    fprintf(file,"NUMERO TOTAL DE LESOES: %d",qtd_l );
    int qtd_ci=RetornarQtdCirurgias1(pacientes->vet, pacientes->tam);
    int qtd_cr = RetornarQtdCrioterapias1(pacientes->vet, pacientes->tam);
    fprintf(file,"NUMERO TOTAL DE CIRURGIAS: %d (%.2f%%)\n",qtd_ci, (qtd_ci/(float)qtd_l));
    fprintf(file,"NUMERO TOTAL DE CRIOTERAPIAS: %d (%.2f%%)\n",qtd_cr, (qtd_cr/(float)qtd_l));
    fprintf(file,"DISTRIBUICAO POR DIAGNOSTICO:\n");
    tDiagnosticos *diagnosticos= CriarDiagnosticos();
    diagnosticos = PreencherDiagnosticos1(diagnosticos, RetornarDiagnosticosVet(diagnosticos), pacientes->tam);
    OrdernarDiagnosticos(diagnosticos);
    MudarPorcentagem(diagnosticos, qtd_l);
    ImprimirDisDiagnosticos(diagnosticos,RetornarTamanhoDiagnosticos(diagnosticos), path);
    

 }
 tPacientes * RealizarConsulta(tPacientes * pacientes, char *path){

    char sus[20];
    scanf("%s%*c", sus);

    int idx;
    if( (idx = AcharIndexPacientes(pacientes,sus)) == -1){
        printf("O paciente precisa estar cadastrado\n");
        exit(-1);
    }
    pacientes->vet[idx] = AtenderPaciente(pacientes->vet[idx], path);
    return pacientes;
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

    int idx;
    if( (idx = AcharIndexPacientes(pacientes,sus)) == -1){
        printf("O paciente precisa estar cadastrado\n");
        exit(-1);
    }
    EscreverPaciente(pacientes->vet[idx],path);
}
