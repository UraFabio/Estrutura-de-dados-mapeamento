#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"


int main() {
	Map meuMap;
	char escolha;
	int matricula;
	char nome[30], v[30];
	
	printf(" - Bem vindo(a) ao meu codigo de mapeamento.\n\n");
	
	do{
		escolha = menu();
		switch(escolha){
			case 'I':
				printf("\nMatricula: ");
				scanf("%d", &matricula);
				printf("Nome: ");
				fflush(stdin);
				gets(nome);
				inserir(matricula, nome, &meuMap);
				printf("\n");
				break;
			case 'R':
				printf("Digite a matricula apra remover: ");
				scanf("%d", &matricula);
				if(remover(matricula, &meuMap)){
					printf("\nElemento removido com sucesso.\n\n");
				}else{
					printf("\nElemento nao encontrado.\n\n");
				}
				break;
			case 'P':
				printf("Digite a matricula a ser procurada: ");
				scanf("%d", &matricula);
				if(procurar(matricula, v, meuMap)){
					printf("\nElemento encontrado:\n\nMatricula: %d\nNome: %s\n\n", matricula, v);
				}else{
					printf("\nElemento nao encontrado.\n\n");
				}
				break;
			case 'L':
				listar(meuMap);
				break;
			case 'D':
				destruir(&meuMap);
				printf("\nMapeamento Destruido com Sucesso.\n\n");
				break;
			case 'S':
				printf("Saindo...\n");
				break;
			default:
				printf("Opcao nao encontrada, digite novamente.\n");
				break;
		}
	}while(escolha != 'S');
	
	
	return 0;
}



