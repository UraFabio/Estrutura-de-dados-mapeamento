//INTERFACE

typedef struct map{
	int matricula;
	char nome[30];
	struct map* prox;
} *Map;

Map novo(int m, char v[], Map M);
void inserir(int m, char v[], Map* M);
int remover(int m, Map *M);
int procurar(int m, char v[], Map M);
void listar(Map M);
void destruir(Map *M);

char menu();
