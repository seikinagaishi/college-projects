#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj.h"

//menu
int escolha_arvore() {
    int opcao;

    do {
        printf("Selecione a �rvore para medir seu tempo de inser��o com amostra de 15.000 elementos\n\n");
        printf("1 - �rvore AVL\n");
        printf("2 - �rvore Rubro Negra\n");
        printf("3 - Relat�rio\n");
        printf("4 - Sair\n\n");
        printf("Op��o: ");

        fflush(stdin);
        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 4) {
            printf("\n\nOp��o Inv�lida!");
            getchar();
            system("cls");
        }
    } while(opcao < 1 || opcao > 4);

    return opcao;
}

int escolha_ordem() {
    int opcao;

    do {
        printf("Selecione o tipo de ordena��o para a implementa��o dos elementos na �rvore\n\n");
        printf("1 - Ordenado\n");
        printf("2 - Desordenado\n\n");
        printf("Op��o: ");

        fflush(stdin);
        scanf("%d", &opcao);
        if(opcao < 1 || opcao > 2) {
            printf("\n\nOp��o Inv�lida!");
            getchar();
            system("cls");
        }
    } while(opcao < 1 || opcao > 2);

    return opcao;
}

//Ordena��o do arquivo .csv com o algoritmo Quick Sort
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
    //Como o dado � uma struct, h� pequenas altera��es para comparar os IDs

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

//Puxar os nomes para a exibi��o do relat�rio
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
