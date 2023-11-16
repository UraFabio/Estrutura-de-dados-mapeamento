//INTERFACE

typedef struct map{
	int matricula;
	int idade;
	struct map* prox;
} *Map;

Map novo(int m, int v, Map M);
void inserir(int m, int v, Map* M);
int remover(int m, Map *M);
int procurar(int m, int *v, Map M);
void listar(Map M);
void destruir(Map *M);

char menu();
