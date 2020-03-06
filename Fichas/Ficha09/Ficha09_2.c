#include <stdio.h>
#include <stdlib.h>

typedef struct abin {
    int valor;
    struct abin *esq,
                *dir;
} * ABin;

typedef struct lista {
    int valor;
    struct lista *prox;
} * LInt;

int length(LInt l) {
    if(!l) return 0;
    return 1 + length(l->prox);
}

ABin fromList(LInt);

LInt fromListN(LInt l, int N, ABin *a) {
    if(!l) return NULL;
    LInt list = NULL;
    for(int i = 0; i < N; i++) {
        LInt new = malloc(sizeof(struct lista));
        new->valor = l->valor;
        new->prox = NULL;
        if(!list) list = new;
        else {
            LInt temp = list;
            while(temp->prox) temp = temp->prox;
            temp->prox = new;
        }
    }
    (*a) = fromList(list);
    return list;
}

ABin fromList (LInt l) {
    if(!l) return NULL;
    ABin new = malloc(sizeof(struct abin));
    int meio = length(l) / 2;
    if(meio > 0) l = fromListN(l,meio,&(new->esq));
    new->valor = l->valor;
    if(l->prox) new->dir = fromList(l->prox);
    return new;
}