#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include "proj.h"

struct timeval {
    long int tv_sec;
    long int tv_usec;
};

int main() {
    setlocale(LC_ALL, "");

    int opcao, listagem;
    char item[1024];
    Func p;

    struct timeval antes, depois;
    double tempo, relatorio[2][2][2] = {0};
    //relatório com 3 parâmetros: árvore, ordenação, informação extra (0 = tempo e 1 = verificar se já foi testado)

    FILE *f;
    f = fopen("massaDadosOrdenados.csv", "r");
    if(f == NULL) {
        ordenarDados("massaDados.csv");
        //caso massaDadosOrdenados não exista, ele será criado
    }
    fclose(f);

    do {
        opcao = escolha_arvore();
        system("cls");

        if(opcao != 4) {
            if(opcao != 3)
                listagem = escolha_ordem();
            system("cls");

            arvAVL *raiz1;
            raiz1 = cria_arvAVL();
            arvoreLLRB *raiz2;
            raiz2 = cria_arvoreLLRB();

            switch(opcao) {
                case 1:
                    if(listagem == 1) {
                        f = fopen("massaDadosOrdenados.csv", "r");

                        gettimeofday(&antes, NULL);
                        while(fgets(item, 1024, f)) {
                            p.id = atoi(strtok(item, ";"));
                            strcpy(p.nome, strtok(NULL, ";"));
                            p.idade = atoi(strtok(NULL, ";"));
                            strcpy(p.empresa, strtok(NULL, ";"));
                            strcpy(p.dpto, strtok(NULL, ";"));
                            p.sal = atof(strtok(NULL, "\n"));
                            insere_arvAVL(raiz1, p);
                        }
                        gettimeofday(&depois, NULL);
                        tempo = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);

                        fclose(f);
                    }
                    else {

                        f = fopen("massaDados.csv", "r");

                        gettimeofday(&antes, NULL);
                        while(fgets(item, 1024, f)) {
                            p.id = atoi(strtok(item, ";"));
                            strcpy(p.nome, strtok(NULL, ";"));
                            p.idade = atoi(strtok(NULL, ";"));
                            strcpy(p.empresa, strtok(NULL, ";"));
                            strcpy(p.dpto, strtok(NULL, ";"));
                            p.sal = atof(strtok(NULL, "\n"));
                            insere_arvAVL(raiz1, p);
                        }
                        gettimeofday(&depois, NULL);
                        tempo = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);

                        fclose(f);
                    }
                    break;
                case 2:
                    if(listagem == 1) {
                        f = fopen("massaDadosOrdenados.csv", "r");

                        gettimeofday(&antes, NULL);
                        while(fgets(item, 1024, f)) {
                            p.id = atoi(strtok(item, ";"));
                            strcpy(p.nome, strtok(NULL, ";"));
                            p.idade = atoi(strtok(NULL, ";"));
                            strcpy(p.empresa, strtok(NULL, ";"));
                            strcpy(p.dpto, strtok(NULL, ";"));
                            p.sal = atof(strtok(NULL, "\n"));
                            insere_arvoreLLRB(raiz2, p);
                        }
                        gettimeofday(&depois, NULL);
                        tempo = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);

                        fclose(f);
                    }
                    else {
                            f = fopen("massaDados.csv", "r");

                            gettimeofday(&antes, NULL);
                            while(fgets(item, 1024, f)) {
                                p.id = atoi(strtok(item, ";"));
                                strcpy(p.nome, strtok(NULL, ";"));
                                p.idade = atoi(strtok(NULL, ";"));
                                strcpy(p.empresa, strtok(NULL, ";"));
                                strcpy(p.dpto, strtok(NULL, ";"));
                                p.sal = atof(strtok(NULL, "\n"));
                                insere_arvoreLLRB(raiz2, p);
                            }
                            gettimeofday(&depois, NULL);
                            tempo = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);

                            fclose(f);
                    }
                    break;
                case 3:
                    printf("Relatório do Tempo de Implementação das Árvores\n");
                    printf("-----------------------------------------------\n\n");
                    for(int i = 0; i < 2; i++) {
                        for(int j = 0; j < 2; j++) {
                            printf("Tempo da Árvore %s com vetor %s\n", arvore(i), vetor(j));
                            if(relatorio[i][j][1] != 0)
                                printf("%.10f segundos\n\n", relatorio[i][j][0]);
                            else
                                printf("Ainda não foi testado!\n\n");
                        }
                    }
                    break;
            }
            if(opcao != 3) {
                relatorio[opcao - 1][listagem - 1][0] = tempo;
                relatorio[opcao - 1][listagem - 1][1] = 1;
                liberar_arvAVL(raiz1);
                liberar_arvoreLLRB(raiz2);
                printf("Processado!\n\n");
            }
            fflush(stdin);
            printf("Pressiona qualquer tecla para continuar.");
            getchar();
            system("cls");
        }
    } while (opcao != 4);
    printf("Programa Encerrado!\n");
    return 0;
}
