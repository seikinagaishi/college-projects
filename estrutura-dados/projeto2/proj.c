#include <stdio.h>
#include <time.h>
#include "proj.h"

void bbSort(int *v, int n) {

    int i, continua, aux, fim = n;
    do {

        continua = 0;
        for(i = 0; i < fim-1; i++) {
            if(v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = 1;
            }
        }
        fim--;
    } while(continua != 0);

}

void selSort(int *v, int n) {
    int i, j, menor, troca;
    for(i = 0; i < n; i++) {
        menor = i;
        for(j = i+1; j < n; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            }
        }
        if(i != menor) {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

void insertSort(int *v, int n) {
    int i, j, aux;
    for(i = 1; i < n; i++) {
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--) {
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}

void shellSort(int *v, int n) {
    int i , j , value;

    int h = 1;
    while(h < n) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < n; i++) {
            value = v[i];
            j = i;
            while (j > h-1 && value <= v[j - h]) {
                v[j] = v[j - h];
                j = j - h;
            }
            v[j] = value;
        }
        h = h/3;
    }
}

//MergeSort
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l+(r-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

//QuickSort
int particiona(int vetor[], int ini, int fim) {
    int esq, dir, pivo, aux;

    esq = ini;
    dir = fim;
    pivo = vetor[ini];

    while(esq < dir) {
        while(esq <= fim && vetor[esq] <= pivo) {
            esq++;
        }
        while(dir >= 0 && vetor[dir] > pivo) {
            dir--;
        }
        if(esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[ini] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
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

//heapSort
void CriandoHeap(int *V, int ini, int fim) {
    int filho = 2*ini + 1, aux = V[ini], i;

    while(filho <= fim) {

        if(filho < fim) {
            if(V[filho] < V[filho + 1]) {
                filho += 1;
            }
        }

        if(V[filho] > aux) {
            V[ini] = V[filho];
            ini = filho;
            filho = ini*2 + 1;
        } else {
            filho = fim + 1;
        }
    }
    V[ini] = aux;
}

void heapSort(int *V, int n) {
    int i, aux;

    for(i=(n-1)/2; i>=0; i--) {
        CriandoHeap(V, i, n-1);
    }

    for(i = (n - 1); i > 0; i--) {
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        CriandoHeap(V, 0, i - 1);
    }
}

void counting_sort(int *v, int n) {
    int count[100000] = {0}, i, j, a[n], max, index = 0;

    //calcula o maior valor dentro do vetor
    for(int j = 0; j < n; j++) {
        if(j == 0)
            max = v[j];
        if(v[j] > max)
            max = v[j];
        }

    for(i = 0; i < n; ++i) {
        a[i] = v[i];
        count[a[i]] = count[a[i]] + 1;
        //Calcula quantas vezes 1 mesmo número se repete
    }

    for(i = 0; i <= max; ++i)
        for(j = 1; j <= count[i]; ++j) {
            v[index] = i;
            index++;
        }
}

//timSort
const int run = 25000;

int minimum(int a, int b) {
    if(a<b)
        return a;
    else
        return b;
}

void altInsertionSort(int a[], int beg, int end) {
    int temp, i, j;
    for (i = beg + 1; i <= end; i++)
    {
        temp = a[i];
        j = i - 1;
        while (a[j] > temp && j >= beg)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void timSort(int a[], int n) {
    int i, size, beg, mid, end;
    for (i = 0; i < n; i += run)
        altInsertionSort(a, i, minimum((i + run - i), (n - 1)));

    for (size = run; size < n; size = 2*size) {
        for (beg = 0; beg < n; beg += 2*size) {
            mid = beg + size - 1;
            end = minimum((beg + 2*size - 1), (n - 1));

            merge(a, beg, mid, end);
        }
    }
}

void bead_sort(int *a, int len) {
	int i, j, max, sum;
	unsigned char *beads;
    #define BEAD(i, j) beads[i * max + j]

	for (i = 1, max = a[0]; i < len; i++)
		if (a[i] > max) max = a[i];

	beads = calloc(1, max * len);

	for (i = 0; i < len; i++)
		for (j = 0; j < a[i]; j++) {
			BEAD(i, j) = 1;
		}

	for (j = 0; j < max; j++) {
		for (sum = i = 0; i < len; i++) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
	}
	free(beads);
}

void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior / exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int *v, int n) {
	int i;

	for (i = 0; i < n; i++)
		printf("%d: %d\n ", i, v[i]);
	printf("\n");
}

void criaVetor(int n, int *v) {
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        v[i] = rand() % 1000;
    }
}

//Criação de vetores crescentes e decrescentes para último teste
void melhorSituacao(int *v, int n) {
    for(int i = 0; i < n; i++) {
        if(i <= 999)
            v[i] = i;
        else
            v[i] = 999;
    }
}

void piorSituacao(int *v, int n) {
    int count;

    if(n <= 1000)
        count = n - 1;
    else
        count = 999;

    for(int i = 0; i < n; i++) {

        v[i] = count;
        if(count > 1)
            count--;
    }
}

void mostraMenu() {
        printf("\n\n Desempenho de Algoritmos de Ordenação");
        printf("\n\n -------------------------------------");
        printf("\n\n Algoritimos disponíveis para ser medido o desempenho:");

        printf("\n 1 - Bubble Sort");
        printf("\n 2 - Selection Sort");
        printf("\n 3 - Insertion Sort");
        printf("\n 4 - Merge Sort");
        printf("\n 5 - Quick Sort");
        printf("\n 6 - Heap Sort");
        printf("\n 7 - Counting Sort");
        printf("\n 8 - Tim Sort");
        printf("\n 9 - Shell Sort");
        printf("\n 10 - Bead Sort");
        printf("\n 11 - Radix Sort");
        printf("\n 12 - Mostrar relatório");
        printf("\n 13 - Encerrar o programa");
        printf("\n\n Escolha uma opcão: ");
}

void prepArray(int *num) {
    int escolha;

    do {
        printf("\n\n Desempenho de Algoritmos de Ordenação");
        printf("\n\n -------------------------------------");
        printf("\n\n Quantidade de elementos para realizar o teste:");

        printf("\n 1 - 1000");
        printf("\n 2 - 5000");
        printf("\n 3 - 10000");
        printf("\n 4 - 20000");
        printf("\n 5 - 50000");
        printf("\n 6 - 100000");
        printf("\n\n Opção: ");
        fflush(stdin);
        scanf("%d", &escolha);

        switch(escolha) {
            case 1:
                num[1] = 1000;
                break;
            case 2:
                num[1] = 5000;
                break;
            case 3:
                num[1] = 10000;
                break;
            case 4:
                num[1] = 20000;
                break;
            case 5:
                num[1] = 50000;
                break;
            case 6:
                num[1] = 100000;
                break;
            default:
                printf("\n Opção Inválida!");
        }
        system("cls");
    } while (escolha < 1 || escolha > 6);

    num[0] = escolha - 1;
}

char* metodo(int sort) {
    switch(sort) {
        case 0:
            return "Bubble Sort";
        case 1:
            return "Selection Sort";
        case 2:
            return "Insertion Sort";
        case 3:
            return "Merge Sort";
        case 4:
            return "Quick Sort";
        case 5:
            return "Heap Sort";
        case 6:
            return "Counting Sort";
        case 7:
            return "Tim Sort";
        case 8:
            return "Shell Sort";
        case 9:
            return "Bead Sort";
        case 10:
            return "Radix Sort";
    }
}

int numElements(int option) {
    switch(option) {
        case 0:
            return 1000;
        case 1:
            return 5000;
        case 2:
            return 10000;
        case 3:
            return 20000;
        case 4:
            return 50000;
        case 5:
            return 100000;
    }
}

void mostraRelatorio(double relatorio[11][6][4]){
    int i,j;
    printf(" Relatório de Desempenho:");

    for(i = 0; i < 11; i++) {
        printf("\n\n --------------------------------");
        printf("\n\n Velocidade do algoritmo %s:", metodo(i));

        for(int j = 0; j < 6; j++) {
            printf("\n\n Teste com %d elementos\n", numElements(j));
            if(relatorio[i][j][3]) {
                printf(" Média: %2.10f\n", relatorio[i][j][0]);
                printf(" Natural: %2.10f\n", relatorio[i][j][1]);
                printf(" Pior Caso: %2.10f", relatorio[i][j][2]);
            } else {
                printf(" Algoritmo não testado com a essa quantidade de elementos.");
            }
        }
    }
    printf("\n\n --------------------------------\n\n");
    printf("\n Pressione qualquer tecla para voltar ao menu\n ");
    fflush(stdin);
    getchar();
    system("cls");

}
