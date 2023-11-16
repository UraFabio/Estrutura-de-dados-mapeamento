//INTERFACE

typedef struct map{
	char faculdade[20];
	char nome[30];
	struct map* prox;
} *Map;

Map novo(char m[], char v[], Map M);
void inserir(char m[], char v[], Map* M);
int remover(char m[], Map *M);
int procurar(char m[], char v[], Map M);
void listar(Map M);
void destruir(Map *M);

char menu();
