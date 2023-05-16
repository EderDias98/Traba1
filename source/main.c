
#include "pacientes.h"
#include <ctype.h>

int main(int argc , char *argv[]){

    tPacientes *pacientes = CriarPacientes();

    while(1){
        printf("######################### MENU INICIAL ###########################\n");
        printf("- Pre-cadastrar um paciente (P ou p)\n");
        printf("Iniciar um atendimento (A ou a)\n");
        printf("- Gerar relatorio (R ou r)\n");
        printf("- Finalizar programa (F ou f)\n");
        printf("##################################################################\n");
        char opcao;
        int flag=0;
        scanf("%c", &opcao);
        opcao = tolower(opcao);
        switch (opcao){
        case 'p':
            pacientes = CadastrarPacientes(pacientes);
            break;
        case 'a':
            
            /* code */
            break;
        case 'r':
            /* code */
            break;
        case 'f':
            flag=1;
            break;        
        default:
            break;
        }
        if(flag==1)
            break;
    }
    //liberar toda memoria alocada no programa

    return 0;
}
