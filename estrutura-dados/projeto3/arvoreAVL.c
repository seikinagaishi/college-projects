#include <stdio.h>
#include <stdlib.h>
#include "proj.h"

struct NO1 {
    Func info;
    int alt;
    struct NO1 *esq;
    struct NO1 *dir;
};

arvAVL *cria_arvAVL() {
    arvAVL *raiz = (arvAVL*) malloc(sizeof(arvAVL));
    if(raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

void liberar_arvAVL(arvAVL *raiz) {
    if(raiz == NULL) {
        return;
    }
    libera_NO1(*raiz);
    free(raiz);
}

void libera_NO1(struct NO1 *no) {
    if(no == NULL) {
        return;
    }
    libera_NO1(no->esq);
    libera_NO1(no->dir);
    free(no);
    no = NULL;
}

int alt_no (struct NO1 *no) {
    if(no == NULL) {
        return -1;
    } else {
        return no->alt;
    }
}

int maior(int x, int y) {
    if(x > y) {
        return(x);
    } else {
        return(y);
    }
}

int fatorBalanceamento_NO(struct NO1 *no) {
    return labs(alt_no(no->esq) - alt_no(no->dir));
}

struct NO1 *remove_atual(struct NO1 *atual) {
    struct NO1 *no1, *no2;
    if(atual->esq == NULL) {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while (no2->dir != NULL) {
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
};

//Rotação direita
void rotacaoLL(arvAVL *raiz) {
    struct NO1 *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt + 1);
    *raiz = no;
}

//Rotação esquerda
void rotacaoRR(arvAVL *raiz) {
    struct NO1 *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->dir), (*raiz)->alt) + 1;
    (*raiz) = no;
}

void rotacaoLR(arvAVL *raiz) {
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(arvAVL *raiz) {
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

//Inserção
int insere_arvAVL(arvAVL *raiz, Func valor) {
    int res;
    if(*raiz == NULL) {
        struct NO1 *novo;
        novo = (struct NO1*) malloc(sizeof(struct NO1));
        if(novo == NULL) {
            return 0;
        }
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO1 *atual = *raiz;
    if(valor.id < atual->info.id) {
        if((res = insere_arvAVL(&(atual->esq), valor)) == 1) {
            if(fatorBalanceamento_NO(atual) >= 2) {
                if(valor.id < (*raiz)->esq->info.id) {
                    rotacaoLL(raiz);
                } else {
                    rotacaoLR(raiz);
                }
            }
        }
    } else {
        if(valor.id > atual->info.id) {
            if((res = insere_arvAVL(&(atual->dir), valor)) == 1) {
                if(fatorBalanceamento_NO(atual) >= 2) {
                    if((*raiz)->dir->info.id < valor.id) {
                        rotacaoRR(raiz);
                    } else {
                        rotacaoRL(raiz);
                    }
                }
            }
        } else {
            printf("Valor duplicado!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) + 1;
    return res;
}

//função auxiliar / procura um nó mais a esquerda
struct NO1 *procuramenor(struct NO1 *atual) {
    struct NO1 *no1 = atual;
    struct NO1 *no2 = atual->esq;
    while(no2 != NULL) {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

//remoção
int remove_arvAVL(arvAVL *raiz, Func valor) {
    if(*raiz == NULL) {
        return 0;
    }
    int res;
    if(valor.id < (*raiz)->info.id) {
        if((res = remove_arvAVL(&(*raiz)->esq, valor)) == 1) {
            if(fatorBalanceamento_NO(*raiz) >= 2) {
                if(alt_no((*raiz)->dir->esq) <= alt_no((*raiz)->dir->dir)) {
                    rotacaoRR(raiz);
                } else {
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->info.id < valor.id) {
        if((res = remove_arvAVL(&(*raiz)->dir, valor)) == 1) {
            if(fatorBalanceamento_NO(*raiz) >= 2) {
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)) {
                    rotacaoLL(raiz);
                } else {
                    rotacaoLR(raiz);
                }
            }
        }
    }
    if((*raiz)->info.id == valor.id) {
        if(((*raiz)->esq == NULL) || (*raiz)->dir == NULL) {
            struct NO1 *no_velho = (*raiz);
            if((*raiz)->esq != NULL) {
                *raiz = (*raiz)->esq;
            } else {
                *raiz = (*raiz)->dir;
            }
            free(no_velho);
        } else {
            struct NO1 *temp = procuramenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_arvAVL((*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2) {
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)) {
                    rotacaoLL(raiz);
                } else {
                    rotacaoLR(raiz);
                }
            }
        }
        if(*raiz != NULL) {
            (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
        }
        return 1;
    }
    if(*raiz != NULL) {
        (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    }
    return res;
}

//Para debug
void emOrdem_arvAVL(arvAVL *raiz) {
    if(raiz == NULL) {
        return;
    }
    if(*raiz != NULL) {
        emOrdem_arvAVL(&((*raiz)->esq));
        printf("%d;", (*raiz)->info.id);
        printf("%s;", (*raiz)->info.nome);
        printf("%d;", (*raiz)->info.idade);
        printf("%s;", (*raiz)->info.empresa);
        printf("%s;", (*raiz)->info.dpto);
        printf("%.2f\n", (*raiz)->info.sal);
        emOrdem_arvAVL(&((*raiz)->dir));
    }
}
