#include "diagnosticos.h"

struct diagnosticos{
    tDiagnostico **vet;
    int tam;
};

tDiagnosticos * CriarDiagnosticos(){
    tDiagnosticos *diagnosticos = malloc(sizeof(tDiagnosticos));
    diagnosticos->tam =0;
    return diagnosticos;
}
tDiagnosticos * PreencherDiagnosticos3(tDiagnosticos *diagnosticos,char *str){

    diagnosticos->vet = CriarVetDiagnostico();
    diagnosticos->vet  =PreencherDiagnostico(diagnosticos->vet, char *str, diagnosticos->tam);
    return diagnosticos;
}
void AumentarTamanhoDiagnosticos(tDiagnosticos *diagnosticos){
    diagnosticos->tam++;
}
RetornarTamanhoDiagnosticos(tDiagnosticos *diagnosticos){
    return diagnosticos->tam;
}
tDiagnosticos *RetornartDiagnosticosVet(tDiagnosticos *diagnosticos){
    return diagnosticos->vet;
}