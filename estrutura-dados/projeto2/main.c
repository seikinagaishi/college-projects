#include <stdio.h>
#include <stdlib.h>
#include "proj.h"
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>

struct timeval {
    long int tv_sec;
    long int tv_usec;
};

int main() {

    setlocale(LC_ALL, "");

    struct timeval antes, depois;
    double bestCase, worstCase, media = 0, relatorio[11][6][4] = {0};
    int escolha = 0, optionArSize[2], i, *array, arraySize;

    do {

        do {
            mostraMenu();
            fflush(stdin);
            scanf("%d", &escolha);

            if(escolha < 1 || escolha > 13) {
                printf("\n Opção Inválida!");
                printf("\n Pressione qualquer tecla para voltar ao menu\n ");
                fflush(stdin);
                getchar();
            }
            system("cls");
        } while (escolha < 1 || escolha > 13);

        if(escolha != 12 && escolha != 13) {
            prepArray(optionArSize);
            arraySize = optionArSize[1];
            printf(" Processando...");
        }

        switch (escolha) {
            case 1:
                for(i = 0; i < 10; i++){
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    bbSort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                bbSort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                bbSort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 2:
                for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    selSort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                selSort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                selSort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 3:
                for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    insertSort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                insertSort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                insertSort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 4:
                for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    mergeSort(array, 0, arraySize - 1);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                mergeSort(array, 0, arraySize - 1);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                mergeSort(array, 0, arraySize - 1);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 5:
                for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    quick_sort(array, 0, arraySize - 1);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                quick_sort(array, 0, arraySize - 1);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array,arraySize);

                gettimeofday(&antes, NULL);
                quick_sort(array, 0, arraySize - 1);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 6:
                for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    heapSort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                heapSort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                heapSort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 7:
                for(i=0;i<10;i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    counting_sort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                counting_sort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase=(depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                counting_sort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase=(depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 8:
                 for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize,array);

                    gettimeofday(&antes, NULL);
                    timSort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array,arraySize);

                gettimeofday(&antes, NULL);
                timSort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array,arraySize);

                gettimeofday(&antes, NULL);
                timSort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 9:
                 for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    shellSort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                shellSort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                shellSort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 10:
                for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    bead_sort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                bead_sort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                bead_sort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 11:
                for(i = 0; i < 10; i++) {
                    array = (int*) malloc(arraySize * sizeof(int));
                    criaVetor(arraySize, array);

                    gettimeofday(&antes, NULL);
                    radixsort(array, arraySize);
                    gettimeofday(&depois, NULL);

                    media += (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                    free(array);
                }
                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem crescente e retorna o tamanho para a variável
                melhorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                radixsort(array, arraySize);
                gettimeofday(&depois, NULL);

                bestCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);

                array = (int*) malloc(arraySize * sizeof(int));
                //Aloca a memória, preenche o array em ordem decrescente e retorna o tamanho para a variável
                piorSituacao(array, arraySize);

                gettimeofday(&antes, NULL);
                radixsort(array, arraySize);
                gettimeofday(&depois, NULL);

                worstCase = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec + antes.tv_usec/1000000.0);
                free(array);
                break;

            case 12:
                mostraRelatorio(relatorio);
                break;

            case 13:
                printf("O Programa foi encerrado.");
        }

        if(escolha > 0 && escolha < 12) {
            relatorio[escolha - 1][optionArSize[0]][0] = media / 10;
            relatorio[escolha - 1][optionArSize[0]][1] = bestCase;
            relatorio[escolha - 1][optionArSize[0]][2] = worstCase;
            relatorio[escolha - 1][optionArSize[0]][3] = 1;
            media = 0;

            printf("\n Processado!");
            printf("\n\n Os dados já estão disponíveis na seção RELATÓRIO.");
            printf("\n Pressione qualquer tecla para voltar ao menu\n ");
            fflush(stdin);
            getchar();
            system("cls");
        }
    } while (escolha != 13);
    return 0;
}
