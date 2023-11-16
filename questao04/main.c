#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"


int main() {
	Map meuMap;
	char escolha;
	char faculdade[20];
	char nome[30], v[30];
	
	printf(" - Bem vindo(a) ao meu codigo de mapeamento.\n\n");
	
	do{
		escolha = menu();
		switch(escolha){
			case 'I':
				printf("\nFaculdade: ");
				fflush(stdin);
				gets(faculdade);
				printf("Nome: ");
				fflush(stdin);
				gets(nome);
				inserir(faculdade, nome, &meuMap);
				printf("\n");
				break;
			case 'R':
				printf("Digite a faculdade para remover: ");
				fflush(stdin);
				gets(faculdade);
				if(remover(faculdade, &meuMap)){
					printf("\nElemento removido com sucesso.\n\n");
				}else{
					printf("\nElemento nao encontrado.\n\n");
				}
				break;
			case 'P':
				printf("Digite a faculdade a ser procurada: ");
				fflush(stdin);
				gets(faculdade);
				if(procurar(faculdade, v, meuMap)){
					printf("\nElemento encontrado:\n\nFaculdade: %s\nNome: %s\n\n", faculdade, v);
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



