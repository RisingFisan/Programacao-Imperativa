#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"

// 1

int retiraNeg (int v[], int N) {
    int i = 0;
    while(i < N) {
        if(v[i] < 0) {
            N--;
            for(int j = i; j < N; j++) v[j] = v[j+1];
        }
        else i++;
    }
    return N;
}

// 2

int difConsecutivos (char s[]){
    int answer = 0;
    for(int i = 0; s[i]; i++) {
        int len = 0;
        for(int j = i; s[j]; j++) {
            int in_prev = 0;
            for(int k = i; k < j; k++) {
                if(s[k] == s[j]) in_prev = 1;
            }
            if(!in_prev) len++;
            else break;
        }
        if(len > answer) answer = len;
    }
    return answer;
}

// 3

int maximo (LInt l) { 
    int max = !l->prox ? l->valor : maximo(l->prox);
    return max > l->valor ? max : l->valor;
}

// 4

int removeAll (LInt *l, int x) {
    int n = 0;
    while(*l) {
        if((*l)->valor == x) {
            LInt temp = (*l);
            (*l) = (*l)->prox;
            free(temp);
            n++;
        }
        else l = &((*l)->prox);
    }
    return n;
}

// 5

LInt arrayToList (int v[], int N) {
    if(!N) return NULL;
    LInt new = malloc(sizeof(struct slist));
    new->valor = *v;
    new->prox = arrayToList(v+1,N-1);
    return new;
}

// Parte B

// 1

int minheapOK (ABin a) {
    if(!a) return 1;
    int l = a->esq ? minheapOK(a->esq) && a->valor < a->esq->valor : 1;
    int r = a->dir ? minheapOK(a->dir) && a->valor < a->dir->valor : 1;
    return l && r;
}

// 2

int max(int a, int b) {return a > b ? a : b; }

int maxHeap (ABin a) {
    int l = a->esq ? maxHeap(a->esq) : a->valor;
    int r = a->dir ? maxHeap(a->dir) : a->valor;
    return max(l,r);
}

// 3

void removeMin (ABin *a) {
    if(!(*a)->esq) {
        ABin temp = (*a);
        (*a) = temp->dir;
        free(temp);
    }
    else if(!(*a)->dir) {
        ABin temp = (*a);
        (*a) = temp->esq;
        free(temp);
    }
    else if((*a)->esq->valor < (*a)->dir->valor) {
        (*a)->valor = (*a)->esq->valor;
        removeMin(&((*a)->esq));
    }
    else {
        (*a)->valor = (*a)->dir->valor;
        removeMin(&((*a)->dir));
    }
}

// 4

void add (ABin *a, int x) { //Fds, que função grande 😂 Já percebi porque é que não nos pedem para a definir no teste.
    ABin newTree = malloc(sizeof(struct nodo));
    newTree->valor = x;
    newTree->esq = newTree->dir = NULL;
    if(!(*a)) (*a) = newTree;
    else {
        if(!(*a)->esq) {
            if(x > (*a)->valor) add(&((*a)->esq),x);
            else {
                newTree->esq = (*a);
                newTree->dir = (*a)->dir;
                (*a)->dir = NULL;
                (*a) = newTree;
            }
        }
        else if(!(*a)->dir) {
            if(x > (*a)->valor) add(&((*a)->dir),x);
            else {
                newTree->esq = (*a)->esq;
                (*a)->esq = NULL;
                newTree->dir = (*a);
                (*a) = newTree;
            }
        }
        else {
            if(x > (*a)->dir->valor) add(&((*a)->dir),x);
            else if(x > (*a)->esq->valor) add(&((*a)->esq),x);
            else {
                ABin newTree = malloc(sizeof(struct nodo));
                newTree->valor = x;
                if(x < (*a)->valor) {
                    newTree->esq = (*a);
                    (*a) = newTree;
                }
                else {
                    newTree->esq = (*a)->esq;
                    (*a)->esq = newTree;
                }
                newTree->dir = NULL;
            }
        }
    }
}

void heapSort (int v[], int N) {
    ABin *tree = malloc(sizeof(ABin));
    *tree = NULL;
    for(int i = 0; i < N; i++) add(tree,v[i]);
    for(int i = 0; i < N; i++) {
        v[i] = (*tree)->valor;
        removeMin(tree);
    }
}

// 5

int kMaior (int v[], int N, int k) {
    ABin tree = NULL;
    for(int i = 0; i < N; i++) {
        if(i < k) add(&tree,v[i]);
        else {
            if(v[i] > tree->valor) {
                add(&tree,v[i]);
                removeMin(&tree);
            }
        }
    }
    return tree->valor;
}

int main() {
    int num, n;
    printf("Tamanho da lista: ");
    scanf("%d", &num);
    int array[num];
    getIntArray(array,num);
    printf("K-ésimo maior elemento: ");
    scanf("%d", &n);
    int ans = kMaior(array,num,n);
    printf("Resposta: %d", ans);
    return 0;
}

// int main() {
//     ABin tree = getBTree();
//     printBTree(tree);
//     add(&tree,50);
//     printBTree(tree);
//     return 0;
// }

// int main() {
//     int num;
//     printf("Tamanho da lista: ");
//     scanf("%d",&num);
//     int array[num];
//     getIntArray(array,num);
//     LInt list = arrayToList(array,num);
//     printLInt(list);
//     return 0;
// }

// int main() {
//     int num;
//     printf("Tamanho da lista: ");
//     scanf("%d",&num);
//     LInt list = getLInt(num);
//     printf("Numero a remover: ");
//     scanf("%d",&num);
//     int n = removeAll(&list,num);
//     printLInt(list);
//     printf("Resposta: %d\n", n);
//     return 0;
// }




