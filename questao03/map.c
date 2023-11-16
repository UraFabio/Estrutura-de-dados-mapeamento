#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "map.h"

Map novo(int m, int v ,Map M){
	Map novo = (Map)malloc(sizeof(struct map));
	novo->matricula = m;
	novo->idade = v;
	novo->prox = M;
	return novo;
}

void inserir(int m, int v, Map* M){
	while(*M != NULL && (*M)->matricula < m){
		M = &(*M)->prox;
	}
	if(*M != NULL && (*M)->matricula == m){
		(*M)->idade = v;
	}
	else{
		*M = novo(m, v, *M);
	}
}

int remover(int m, Map *M){
	while(*M != NULL && (*M)->matricula < m){
		M = &(*M)->prox;
	}
	if(*M == NULL || (*M)->matricula > m){
		return 0;
	}else{
		Map aux = *M;
		*M = aux->prox;
		free(aux);
		return 1;
	}
}

int procurar(int m, int *v, Map M){
	while(M != NULL && M->matricula < m){
		M = M->prox;
	}
	if(M != NULL && M->matricula == m){
		*v = M->idade;
		return 1;
	}
	return 0;
}

void listar(Map M){
	printf("[");
	while(M != NULL){
		printf("(%d : %d)",M->matricula, M->idade);
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
