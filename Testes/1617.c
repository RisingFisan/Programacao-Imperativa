#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#define MAXc 3

int limpaEspacos (char t[]) {
    int i = 0;
    while(t[i]) {
        if(t[i] == ' ' && t[i+1] == ' ') {
            for(int j = i; t[j] != '\0'; j++) {
                t[j] = t[j+1];
            }
        }
        else i++;
    }
    return i;
}

void transposta (int N, float m [N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

LInt cloneL(LInt l) {
    if(!l) return NULL;
    LInt new = malloc(sizeof(struct slist));
    new->valor = l->valor;
    new->prox = cloneL(l->prox);
    return new;
}

int nivelV (ABin a, int n, int v[]) {
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    int e = nivelV(a->esq,n-1,v);
    return e + nivelV(a->dir,n-1,v+e);
}

void removeMaiorA (ABin *a) {
    if(!(*a)->dir)
        (*a) = (*a)->esq;
    else {
        ABin prev;
        while((*a)->dir) {
            prev = (*a);
            a = &((*a)->dir);
        }
        prev->dir = (*a)->esq;
    }
}

typedef struct chunk {
    int vs[MAXc];
    struct chunk *prox;
} * CList;

typedef struct stackC {
    CList valores;
    int sp;
} StackC;

int push (StackC *s, int x) {
    if(s->sp >= MAXc) {
        CList new = malloc(sizeof(struct chunk));
        if(!new) return 1;
        new->vs[0] = x;
        new->prox = s->valores;
        s->valores = new;
        s->sp = 1;
    }
    else s->valores->vs[(s->sp)++] = x;
    return 0;
}

int pop (StackC *s, int *x) {
    if(!s || !s->valores) return 1;
    *x = s->valores->vs[--(s->sp)];
    if(s->sp == 0) {
        s->sp = MAXc;
        CList temp = s->valores;
        s->valores = s->valores->prox;
        free(temp);
    }
    return 0;
}

int size(StackC s) {
    if(!s.valores) return 0;
    StackC temp = { .sp = MAXc, .valores = s.valores->prox };
    return s.sp + size(temp);
}

void reverse (StackC *s) {
    StackC temp = {0};
    temp.sp = 0;
    temp.valores = malloc(sizeof(struct chunk));
    temp.valores->prox = NULL;
    int* x = malloc(sizeof(int));
    while(!pop(s,x)) push(&temp,*x);
    (*s) = temp;
}

void reverse2 (StackC *s) {
    int tam = size(*s);
    for(int i = 0; i < tam; i++) {
        
    }
}

void printStack(StackC s) {
    for(int i = 0; i < MAXc; i++) {
        if(i < s.sp) printf("%d ",s.valores->vs[i]);
        else printf("/ ");
    }
    printf("\n");
    if(s.valores->prox) {
        StackC temp = { .sp = MAXc, .valores = s.valores->prox };
        printStack(temp);
    }
}

int main() {
    StackC * stack = malloc(sizeof(struct stackC));
    stack->sp = 0;
    stack->valores = malloc(sizeof(struct chunk));
    stack->valores->prox = NULL;
    StackC * stackR = malloc(sizeof(struct stackC));
    stackR->sp = 0;
    stackR->valores = malloc(sizeof(struct chunk));
    stackR->valores->prox = NULL;
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    printStack(*stack);
    int tam = size(*stack);
    printf("Tamanho: %d\n", tam);
    reverse(stack);
    printf("Reversa:\n");
    printStack(*stack);
    int* x = malloc(sizeof(int));
    pop(stack,x);
    push(stackR,*x);
    printStack(*stack);
    printf("Removido: %d\n", *x);
    tam = size(*stack);
    printf("Tamanho: %d\n", tam);
    pop(stack,x);
    push(stackR,*x);
    printStack(*stack);
    printf("Removido: %d\n", *x);
    tam = size(*stack);
    printf("Tamanho: %d\n", tam);
    return 0;
}