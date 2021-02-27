#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaprojeto.h"

struct elemento{
    cli dados;
    struct elemento *prox;
};

typedef struct elemento elem;

FILE *f;

//Criação da Lista
List *criacao(){
    List *li;
    li=(List*) malloc(sizeof(List));
    if(li!=NULL){
        *li=NULL;
    }
    return li;
}

//Verificar Lista Vazia
int vazio(List *li){
    if(li==NULL){
        return 1;
    }
    if(*li==NULL){
        return 1;
    }
    return 0;
}

//Cadastro dos Dados de um Novo Cliente
cli dadoscl(){
    char r;
    cli cl;
    do{
        printf("Insira os dados do novo contato:\n\nCódigo: ");
        scanf("%d", &cl.cod);

        fflush(stdin);
        printf("Nome: ");
        fgets(cl.nome,30,stdin);
        cl.nome[strlen(cl.nome) - 1] = '\0';

        fflush(stdin);
        printf("Empresa: ");
        fgets(cl.emp,30,stdin);
        cl.emp[strlen(cl.emp) - 1] = '\0';

        fflush(stdin);
        printf("Departamento: ");
        fgets(cl.dept,30,stdin);
        cl.dept[strlen(cl.dept) - 1] = '\0';

        fflush(stdin);
        printf("Telefone: ");
        fgets(cl.tel,15,stdin);
        cl.tel[strlen(cl.tel) - 1] = '\0';

        fflush(stdin);
        printf("Celular: ");
        fgets(cl.cel,15,stdin);
        cl.cel[strlen(cl.cel) - 1] = '\0';

        fflush(stdin);
        printf("E-mail: ");
        fgets(cl.email,30,stdin);
        cl.email[strlen(cl.email) - 1] = '\0';
        do{
            printf("\nTem certeza que deseja criar esse contato? (S/N)\n");
            fflush(stdin);
            scanf("%c", &r);
            r=toupper(r);
            if(r!='S' && r!='N'){
                printf("Opção Inválida!\n");
            }
        } while(r!='S' && r!='N');
        system("cls");
    } while(r!='S');
    return cl;
}

//Inserção
int inserir(List *li, cli cl){
    if(li==NULL){
        return 0;
    }
    elem *no=(elem*) malloc(sizeof(elem));
    if(no==NULL){
        return 0;
    }
    no->dados=cl;
    if(vazio(li)){
        no->prox=(*li);
        *li=no;
        return 1;
    } else{
        elem *ant, *atual = *li;
        while(atual!=NULL && atual->dados.cod<cl.cod){
            ant=atual;
            atual=atual->prox;
        }
        if(atual == *li){
            no->prox=(*li);
            *li=no;
        } else{
            no->prox= ant->prox;
            ant->prox=no;
        }

        return 1;
    }
}

//Coleta Dados para Edição
cli editarcl(int codig){
    cli cl;

    cl.cod=codig;

    fflush(stdin);
    printf("Nome: ");
    fgets(cl.nome,30,stdin);
    cl.nome[strlen(cl.nome) - 1] = '\0';

    fflush(stdin);
    printf("Empresa: ");
    fgets(cl.emp,30,stdin);
    cl.emp[strlen(cl.emp) - 1] = '\0';

    fflush(stdin);
    printf("Departamento: ");
    fgets(cl.dept,30,stdin);
    cl.dept[strlen(cl.dept) - 1] = '\0';

    fflush(stdin);
    printf("Telefone: ");
    fgets(cl.tel,15,stdin);
    cl.tel[strlen(cl.tel) - 1] = '\0';

    fflush(stdin);
    printf("Celular: ");
    fgets(cl.cel,15,stdin);
    cl.cel[strlen(cl.cel) - 1] = '\0';

    fflush(stdin);
    printf("E-mail: ");
    fgets(cl.email,30,stdin);
    cl.email[strlen(cl.email) - 1] = '\0';

    return cl;
}

//Exibição Total
int exibir(List *li){
    int check=0, sum=0;
    if(li==NULL){
        return 0;
    }
    cli cl;
    elem *no=*li;

    if(no!=NULL)
        check=1;
    while(no!=NULL){
        cl=no->dados;
        printf("-----------------------------");
        printf("\nCódigo: %d\n", cl.cod);
        printf("\nNome: %s\n", cl.nome);
        printf("\nEmpresa: %s", cl.emp);
        printf("\nDepartamento: %s", cl.dept);
        printf("\nTelefone: %s", cl.tel);
        printf("\nCelular: %s", cl.cel);
        printf("\nE-mail: %s\n", cl.email);
        no=no->prox;
        sum++;
    }
    if(check==1)
        printf("-----------------------------");
    else
        printf("Lista Vazia!");
    printf("\n\n////////////////////////////////\n");
    printf("// Quantidade de Contatos: %d //\n", sum);
    printf("////////////////////////////////");
    printf("\n\n");
    return 0;
}

//Remoção
int remover(List *li, int codcli){
    if(li==NULL){
        return 0;
    }
    elem *ant, *no=*li;
    while(no!=NULL && no->dados.cod!=codcli){
        ant=no;
        no=no->prox;
    }
    if(no==NULL){
        return 0;
    }
    if(no==*li){
        *li=no->prox;
    } else{
    ant->prox=no->prox;
    }
    free(no);
    return 1;
}

//Busca por Código
int consultacod(List *li, int codcli, cli *cl){
    if(li==NULL){
        return 0;
    }
    elem *no=*li;
    while(no!=NULL && no->dados.cod!=codcli){
        no=no->prox;
    }
    if(no==NULL){
        return 0;
    } else{
        *cl=no->dados;
        return 1;
    }
}

//Busca por Nome
void consultanome(List *li, char nome[]){
    if(li==NULL){
        return 0;
    }
    elem *no=*li;
    int cont=0;

    while(no!=NULL){
        if(strncmp(no->dados.nome, nome, 30)==0){
            printf("\nCódigo: %d", no->dados.cod);
            printf("\nNome: %s", no->dados.nome);
            printf("\nEmpresa: %s", no->dados.emp);
            printf("\nDepartamento: %s", no->dados.dept);
            printf("\nTelefone: %s", no->dados.tel);
            printf("\nCelular: %s", no->dados.cel);
            printf("\nE-mail: %s\n\n", no->dados.email);
            cont++;
        }
        no=no->prox;
    }
    if(cont==0){
        printf("\nContato %s não localizado!\n\n", nome);
        return 0;
    }
}

//Verificar Duplicidade
int verif(List *li, int cod){
    if(li==NULL){
        return 0;
    }
    elem *no = *li;
    while(no!=NULL && cod != no->dados.cod){
        no=no->prox;
    }
    if(no==NULL)
        return 1;
    else
        return 0;
}

//Calcular Tamanho e Salvar
void tamsave(List *li){
    if(li==NULL){
        return 0;
    }
    f=fopen("contato.bin", "wb");
    int acum=0;
    cli cl;
    elem *no = *li;
    while(no!=NULL){
        acum++;
        no=no->prox;
    }
    fwrite(&acum, sizeof(int), 1, f); //Primeiro byte salva a quantidade de contatos
    no = *li;
    while(no!=NULL){
        cl=no->dados;
        fwrite(&cl, sizeof(cli), 1, f); //Salva as informações de cada cliente um de cada vez
        no=no->prox;
    }
    fclose(f);
}

//Carregamento de Arquivo
int carregar(List *li){
    int x, i=0;
    cli cl;
    elem *no;
    f=fopen("contato.bin", "rb");
    fread(&x, sizeof(int), 1, f); //Carrega o primeiro byte contendo a qtd de contatos, permitindo rodar o while com a qtd certa
    while(i<x){
        fread(&cl, sizeof(cli), 1, f); //Carrega as informações de cada cliente um de cada vez
        inserir(li, cl);
        i++;
    }
    fclose(f);
}
