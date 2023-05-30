
#include "pacientes.h"
#include <ctype.h>

int main(int argc , char *argv[]){
    if(argc<2){
        printf("É preciso informar o diretório de saida dos arquivos gerados pelo trabalho\n");
    }
    char * path = argv[1];
    tPacientes *pacientes = CriarPacientes();
    int cont=0;

    while(1){
        printf("######################### MENU INICIAL ###########################\n");
        printf("- Pre-cadastrar um paciente (P ou p)\n");
        printf("- Iniciar um atendimento (A ou a)\n");
        printf("- Buscar um paciente (B ou b)\n");
        printf("- Gerar relatorio (R ou r)\n");
        printf("- Finalizar programa (F ou f)\n");
        printf("##################################################################\n");
        char opcao;
        int flag=0;
        scanf("%c%*c", &opcao);
        opcao = tolower(opcao);
        switch (opcao){
        case 'p':
            
            CadastrarPacientes(pacientes);
            break;
        case 'a':
        
            RealizarConsulta(pacientes, path);
     
            /* code */
            break;
        case 'r':
            GerarRelatorio(pacientes,path);
            break;
        case 'f':
            flag=1;
            break;
        case 'b':
            RealizarBusca(pacientes,path);
            break;        
        default:
            break;
        }
        if(flag==1)
            break;
        cont++;
    }
    //liberar toda memoria alocada no programa
    LiberarPacientes(pacientes);

    return 0;
}
