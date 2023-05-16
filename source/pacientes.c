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
    if(EhSusUnico(pacientes, RetornarSusPaciente(paciente))){
        int idx = pacientes->tam++;
        pacientes->vet[idx] = paciente;
    }else{
        printf("Nao e possivel cadastrar esse usuário pois ele já foi cadastrado\n");
    }

    return pacientes;
}

int EhSusUnico(tPacientes *pacientes, int sus){
    int i;
    for(i=0;i<pacientes->tam;i++){
        if(sus == RetornarSusPaciente(pacientes->vet[i]));
            return 0;
    }
    return 1;
}

