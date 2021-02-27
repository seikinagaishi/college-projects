typedef struct CLIENTE{
    int cod;
    char nome[30], emp[30], dept[30];
    char tel[15], cel[15], email[50];
} cli;

typedef struct elemento* List;

//Criando a Lisa
List *criacao();

//Verificar Lista Vazia
int vazio(List *li);

//Cadastro de Dados de um Novo Cliente
cli dadoscl();

//Inser��o
int inserir(List *li, cli cl);

//Coleta Dados para a Edi��o
cli editarcl(int codig);

//Exibi��o Total
int exibir(List *li);

//Remo��o
int remover(List *li, int codcli);

//Busca por C�digo
int consultacod(List *li, int codcli, cli *cl);

//busca por nome
void consultanome(List *li, char nome[]);

//Calcula o tamanho e salva o arquivo
void tamsave(List *li);

//Verificar Duplicidade
int verif(List *li, int cod);
