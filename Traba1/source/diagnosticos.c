#include "diagnosticos.h"

struct diagnosticos
{
    tDiagnostico **vet;
    int tam;
};

tDiagnosticos *CriarDiagnosticos()
{
    tDiagnosticos *diagnosticos = (tDiagnosticos *)malloc(sizeof(tDiagnosticos));
    EhPonteiroNULL(diagnosticos);
    diagnosticos->vet = CriarVetDiagnostico();
    EhPonteiroNULL(diagnosticos->vet);
    diagnosticos->tam = 6;
    return diagnosticos;
}
void PreencherDiagnosticos_D(tDiagnosticos *diagnosticos, char *str)
{
    int idx;
    
    if ((idx = IdxDoDiagnostico(diagnosticos->vet, str, diagnosticos->tam)) != -1)
    {

        AumentarDiagnosticos(diagnosticos->vet[idx]);
        
    }
    else
    {
        printf("O nome do Diagnostico está errado\n");
        printf("\n%s\n", str);
    }
}
void AumentarTamanhoDiagnosticos(tDiagnosticos *diagnosticos)
{
    diagnosticos->tam++;
}
int RetornarTamanhoDiagnosticos(tDiagnosticos *diagnosticos)
{
    return diagnosticos->tam;
}

void LiberarDiagnosticos(tDiagnosticos *diagnosticos)
{
    int i;
    for (i = 0; i < diagnosticos->tam; i++)
    {
        if (!diagnosticos->vet)
        {
            break;
            ;
        }
        LiberarDiagnostico(diagnosticos->vet[i]);
    }
    LiberarPonteiro(diagnosticos->vet);
    LiberarPonteiro(diagnosticos);
}
void OrdernarDiagnosticos(tDiagnosticos *diagnosticos)
{
    OrdernarDiagnosticos_D(diagnosticos->vet, diagnosticos->tam);
}
void MudarPorcentagem(tDiagnosticos *diagnosticos, int qtd_l)
{
    int i;
    for (i = 0; i < diagnosticos->tam; i++)
    {
        MudarPorcentagem_D(diagnosticos->vet[i], qtd_l);
    }
}
void ImprimirDiagnosticos(tDiagnosticos *diagnosticos, char *path)
{
    ImprimirDiagnosticos_D(diagnosticos->vet, diagnosticos->tam, path);
}