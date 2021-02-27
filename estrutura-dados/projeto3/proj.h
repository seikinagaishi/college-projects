typedef struct funcionario {
	int id, idade;
	char nome[200], empresa[200], dpto[200];
	float sal;
} Func;

void ordenarDados(char *fileName);
char *arvore();
char *vetor();

      /*Árvore AVL*/
typedef struct NO1 *arvAVL;
arvAVL *cria_arvAVL();
int insere_arvAVL(arvAVL *raiz, Func valor);
int remove_arvAVL(arvAVL *raiz, Func valor);
void liberar_arvAVL(arvAVL *raiz);
void emOrdem_arvAVL(arvAVL *raiz);

     /*Árvore LLRB*/
typedef struct NO2 *arvoreLLRB;
arvoreLLRB *cria_arvoreLLRB();
int insere_arvoreLLRB(arvoreLLRB *raiz, Func valor);
int remove_arvoreLLRB(arvoreLLRB *raiz, Func valor);
void liberar_arvoreLLRB(arvoreLLRB *raiz);
void emOrdem_arvoreLLRB(arvoreLLRB *raiz);
