#!/bin/bash

#ne=1

cd ~/Traba1/
make all
cd -




i=0
j=1

# Exibir os nomes de arquivos armazenados na array
#set -x
while true;do
((j++))
~/Traba1/trab1 ~/saida < ~/testes/teste_$j/entrada_$j
logs=~/testes/teste_$j/logs/
logss=~/saida/logs/
buscas=~/testes/teste_$j/buscas/
buscass=~/saida/buscas/
relatorio=~/testes/teste_$j/relatorio/
relatorios=~/saida/relatorio/
echo "Testando teste_$j"
i=0
readarray -t arquivos1 < <(find $logss  -type f -printf "%f\n")
readarray -t arquivos2 < <(find $logs  -type f -printf "%f\n")
	for arquivo in "${arquivos1[@]}"; do
		echo "Testando logs$((i+1))"
		diff $logs$arquivo $logss${arquivos2[i]}
		((i++))
	done
i=0
readarray -t arquivos1 < <(find $buscass  -type f -printf "%f\n")
readarray -t arquivos2 < <(find $buscas  -type f -printf "%f\n")
	for arquivo in "${arquivos1[@]}"; do
		echo "Testando buscas$((i+1))"
		diff $buscas$arquivo $buscass${arquivos2[i]}
		((i++))
	done
i=0
readarray -t arquivos1 < <(find $relatorios  -type f -printf "%f\n")
readarray -t arquivos2 < <(find $relatorio  -type f -printf "%f\n")
	for arquivo in "${arquivos1[@]}"; do
		echo "Testando relatorio_final$((i+1))"
		diff $relatorio$arquivo $relatorios${arquivos2[i]}
		((i++))
	done
#rm -rdf $buscass/*
rm -rdf $logss/*
if (($j==2));then
	break;
fi
done