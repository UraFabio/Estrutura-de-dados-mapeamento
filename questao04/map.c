#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "map.h"

Map novo(char m[], char v[], Map M){
	Map novo = (Map)malloc(sizeof(struct map));
	strcpy(novo->faculdade, m);
	strcpy(novo->nome, v);
	novo->prox = M;
	return novo;
}

void inserir(char m[], char v[], Map* M){
	while(*M != NULL && strcmp((*M)->faculdade, m) < 0){
		M = &(*M)->prox;
	}
	if(*M != NULL && strcmp((*M)->faculdade, m) == 0){
		strcpy((*M)->nome, v);
	}
	else{
		*M = novo(m, v, *M);
	}
}

int remover(char m[], Map *M){
	while(*M != NULL && strcmp((*M)->faculdade, m) < 0){
		M = &(*M)->prox;
	}
	if(*M == NULL || strcmp((*M)->faculdade, m) > 0){
		return 0;
	}else{
		Map aux = *M;
		*M = aux->prox;
		free(aux);
		return 1;
	}
}

int procurar(char m[], char v[], Map M){
	while(M != NULL && strcmp(M->faculdade, m) < 0){
		M = M->prox;
	}
	if(M != NULL && strcmp(M->faculdade, m) == 0){
		strcpy(v, M->nome);
		return 1;
	}
	return 0;
}

void listar(Map M){
	printf("[");
	while(M != NULL){
		printf("(%s : %s)",M->faculdade, M->nome);
		if(M->prox != NULL){
			printf(", ");
		}
		M = M->prox;
	}
	printf("]\n");
}

void destruir(Map *M){
	*M = NULL;
}

char menu(){
	fflush(stdin);
	fflush(stdout);
	char escolha;
	printf("===============MENU===============\n\n");
	printf(" - Selecione uma das opcoes abaixo:\n\n");
	printf(" - 'I' para inserir.\n");
	printf(" - 'R' para remover.\n");
	printf(" - 'P' para procurar.\n");
	printf(" - 'L' para listar.\n");
	printf(" - 'D' para destruir.\n");
	printf(" - 'S' para sair.\n\n");
	printf(" >> ");
	scanf("%c", &escolha);
	return toupper(escolha);
}
