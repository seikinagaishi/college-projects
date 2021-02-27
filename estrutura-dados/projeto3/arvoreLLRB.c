#include <stdio.h>
#include <stdlib.h>
#include "proj.h"

#define RED 1
#define BLACK 0

struct NO2 {
    Func info;
    struct NO2 *esq;
    struct NO2 *dir;
    int cor;
};

arvoreLLRB *cria_arvoreLLRB() {
    arvoreLLRB *raiz = (arvoreLLRB*) malloc(sizeof(arvoreLLRB));
    if(raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

void liberar_arvoreLLRB(arvoreLLRB *raiz) {
    if(raiz == NULL) {
        return;
    }
    libera_NO2(*raiz);
    free(raiz);
}

void libera_NO2(struct NO2 *no) {
    if(no == NULL) {
        return;
    }
    libera_NO2(no->esq);
    libera_NO2(no->dir);
    free(no);
    no = NULL;
}

//funções auxiliares
int cor(struct NO2 *H) {
    if(H == NULL) {
        return BLACK;
    } else {
        return H->cor;
    }
}

void trocaCor(struct NO2 *H) {
    H->cor = !H->cor;
    if(H->esq != NULL) {
        H->esq->cor = !H->esq->cor;
    }
    if(H->dir != NULL) {
        H->dir->cor = !H->dir->cor;
    }
}

struct NO2 *rotacionaEsquerda(struct NO2 *A) {
    struct NO2 *B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO2 *rotacionaDireita(struct NO2 *A) {
    struct NO2 *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO2 *move2EsqRED(struct NO2 *H) {
    trocaCor(H);
    if(cor(H->dir->esq) == RED) {
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct NO2 *move2DirRED(struct NO2 *H) {
    trocaCor(H);
    if(cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct NO2 *balancear(struct NO2 *H) {
    if(cor(H->dir) == RED) {
        H = rotacionaEsquerda(H);
    }
    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED) {
        trocaCor(H);
    }
    return H;
}

struct NO2 *insereNO(struct NO2 *H, Func valor, int *resp) {
    if(H == NULL) {
        struct NO2 *novo;
        novo = (struct NO2*) malloc(sizeof(struct NO2));
        if(novo == NULL) {
            *resp = 0;
            return NULL;
        }
        novo->info = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }
    if(valor.id == H->info.id) {
        *resp = 0;
    } else {
        if(valor.id < H->info.id) {
            H->esq = insereNO(H->esq, valor, resp);
        } else {
            H->dir = insereNO(H->dir, valor, resp);
        }
    }
    if(cor(H->dir) == RED && cor(H->esq) == BLACK) {
       H = rotacionaEsquerda(H);
    }
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED) {
        trocaCor(H);
    }
    return H;
}

int insere_arvoreLLRB(arvoreLLRB *raiz, Func valor) {
    int resp;
    *raiz = insereNO(*raiz, valor, &resp);
    if((*raiz) != NULL) {
        (*raiz)->cor = BLACK;
    }
    return resp;
}

struct NO2 *removeMenor(struct NO2 *H) {
    if(H->esq == NULL) {
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK) {
        H = move2EsqRED(H);
    }
    H->esq = removeMenor(H->esq);
    return balancear(H);
}

struct NO2 *procuraMenor(struct NO2 *atual) {
    struct NO2 *no1 = atual;
    struct NO2 *no2 = atual->esq;
    while(no2 != NULL) {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO2 *removeNO(struct NO2 *H, Func valor) {
    if(valor.id < H->info.id) {
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK) {
            H = move2EsqRED(H);
        }
        H->esq = removeNO(H->esq, valor);
    } else {
        if(cor(H->esq) == RED) {
            H = rotacionaDireita(H);
        }
        if(valor.id == H->info.id && (H->dir == NULL)) {
            free(H);
            return NULL;
        }
        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK) {
            H = move2DirRED(H);
        }
        if(valor.id == H->info.id) {
            struct NO2 *x = procuraMenor(H->dir);
            H->info = x->info;
            H->dir = removeMenor(H->dir);
        } else {
            H->dir = removeNO(H->dir, valor);
        }
    }
    return balancear(H);
}

int remove_arvoreLLRB(arvoreLLRB *raiz, Func valor) {
    if(consulta_arvoreLLRB(raiz, valor)) {
        struct NO2 *H = *raiz;
        *raiz = removeNO(H, valor);
        if(*raiz != NULL) {
            (*raiz)->cor = BLACK;
        }
        return 1;
    } else {
        return 0;
    }
}

int consulta_arvoreLLRB(arvoreLLRB *raiz, Func valor) {
    if(raiz == NULL) {
        return 0;
    }
    struct NO2 *atual = *raiz;
    while(atual != NULL) {
        if(valor.id == atual->info.id) {
            return 1;
        }
        if(valor.id > atual->info.id) {
            atual = atual->dir;
        }
        else {
            atual = atual->esq;
        }
    }
    return 0;
}

//Para debug
void emOrdem_arvoreLLRB(arvoreLLRB *raiz) {
    if(raiz == NULL) {
        return;
    }
    if(*raiz != NULL) {
        emOrdem_arvoreLLRB(&((*raiz)->esq));
        printf("%d;", (*raiz)->info.id);
        printf("%s;", (*raiz)->info.nome);
        printf("%d;", (*raiz)->info.idade);
        printf("%s;", (*raiz)->info.empresa);
        printf("%s;", (*raiz)->info.dpto);
        printf("%.2f\n", (*raiz)->info.sal);
        emOrdem_arvoreLLRB(&((*raiz)->dir));
    }
}
