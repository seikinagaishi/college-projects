#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj.h"

//menu
int escolha_arvore() {
    int opcao;

    do {
        printf("Selecione a árvore para medir seu tempo de inserção com amostra de 15.000 elementos\n\n");
        printf("1 - Árvore AVL\n");
        printf("2 - Árvore Rubro Negra\n");
        printf("3 - Relatório\n");
        printf("4 - Sair\n\n");
        printf("Opção: ");

        fflush(stdin);
        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 4) {
            printf("\n\nOpção Inválida!");
            getchar();
            system("cls");
        }
    } while(opcao < 1 || opcao > 4);

    return opcao;
}

int escolha_ordem() {
    int opcao;

    do {
        printf("Selecione o tipo de ordenação para a implementação dos elementos na árvore\n\n");
        printf("1 - Ordenado\n");
        printf("2 - Desordenado\n\n");
        printf("Opção: ");

        fflush(stdin);
        scanf("%d", &opcao);
        if(opcao < 1 || opcao > 2) {
            printf("\n\nOpção Inválida!");
            getchar();
            system("cls");
        }
    } while(opcao < 1 || opcao > 2);

    return opcao;
}

//Ordenação do arquivo .csv com o algoritmo Quick Sort
void ordenarDados(char *fileName) {
    char linha[1024];
    int i = 0;

    Func *p = (Func*) malloc(15000 * sizeof(Func));
    FILE *fDados, *fDadosOrganizados;
    fDados = fopen(fileName, "r");
    fDadosOrganizados = fopen("massaDadosOrdenados.csv", "w");

    while(fgets(linha, 1024, fDados)) {
        p[i].id = atoi(strtok(linha, ";"));
        strcpy(p[i].nome, strtok(NULL, ";"));
        p[i].idade = atoi(strtok(NULL, ";"));
        strcpy(p[i].empresa, strtok(NULL, ";"));
        strcpy(p[i].dpto, strtok(NULL, ";"));
        p[i].sal = atof(strtok(NULL, "\n"));
        i++;
    }

    quick_sort(p, 0, 14999);

    for(int i = 0; i < 15000; i++) {
        fprintf(fDadosOrganizados, "%d;%s;%d;%s;%s;%.2f\n", p[i].id, p[i].nome, p[i].idade, p[i].empresa, p[i].dpto, p[i].sal);
    }

    fclose(fDados);
    fclose(fDadosOrganizados);
    free(p);

    return;
}

void quick_sort(Func *a, int left, int right) {
    int i, j, x;
    Func y;

    i = left;
    j = right;
    x = a[(left + right) / 2].id;
    //Como o dado é uma struct, há pequenas alterações para comparar os IDs

    while(i <= j) {
        while(a[i].id < x && i < right) {
            i++;
        }
        while(a[j].id > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

//Puxar os nomes para a exibição do relatório
char *arvore(opcao) {
    if(opcao == 0)
        return "AVL";
    else
        return "Rubro Negra";
}

char *vetor(opcao) {
    if(opcao == 0)
        return "Ordenado";
    else
        return "Desordenado";
}
