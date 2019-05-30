#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auxiliares.h"

typedef struct posicao {
int x, y;
} Posicao;

// 1

char *mystrstr (char s1[], char s2[]) {
    char* ans = s1;
    for(int i = 0; s1[i]; i++) {
        ans = NULL;
        int subS = 1;
        for(int j = 0; s2[j]; j++) {
            if(s1[i + j] != s2[j]) {
                subS = 0;
                break;
            }
        }
        if(subS) return s1 + i;
    }
    return ans;
}

// 2

void truncW (char t[], int n) {
    int i = 0, l = 0;
    while(t[i]) {
        if(t[i] != ' ') l++;
        else l = 0;
        if(l > n) {
            for(int j = i; t[j]; j++) t[j] = t[j+1];
        }
        else i++;
    }
}

// 3

int mannDis(Posicao pos1, Posicao pos2) {return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y); }

int maiscentral (Posicao pos[], int N) {
    int i, ans = 0, disMin = mannDis((Posicao){0,0},pos[0]), dis;
    for(i = 1; i < N; i++) {
        if((dis = mannDis((Posicao){0,0},pos[i])) < disMin) {
            ans = i;
            disMin = dis;
        }
    }
    return ans;
}

// 4

LInt somasAcL (LInt l) {
    LInt ans = NULL;
    int soma = 0;
    for(;l;l = l->prox) {
        soma += l->valor;
        LInt new = malloc(sizeof(struct slist));
        new->valor = soma;
        new->prox = NULL;
        if(!ans) ans = new;
        else {
            LInt temp = ans;
            while(temp->prox) temp = temp->prox;
            temp->prox = new;
        }
    }
    return ans;
}

// 5 

int addOrd (ABin *a, int x) {
    if(!(*a)) {
        (*a) = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;
        return 0;
    }
    if(x == (*a)->valor) return 1;
    if(x > (*a)->valor) addOrd(&((*a)->dir),x);
    else addOrd(&((*a)->esq),x);
}

// Parte B

typedef struct celula {
char *palavra;
int comp;
struct celula *prox;
} *Palavras;

// 1

int daPalavra (char *s, int *e) {
    for((*e) = 0; isspace(s[(*e)]);(*e)++);
    int len;
    for(len = 0; !isspace(s[len + (*e)]) && s[len + (*e)] != '\0';len++);
    return len;
}

// 2

Palavras words (char *texto) {
    if(!texto) return NULL;
    int e, n;
    n = daPalavra(texto,&e);
    if(!n) return NULL;
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = texto + e;
    new->comp = n;
    new->prox = words(texto + e + n);
    return new;
}

// 3

Palavras daLinha (Palavras t, int n) {
    int len = 0;
    Palavras prev;
    for(;len < n && t;t = t->prox) {
        len += t->comp + 1;
        if(len > n) break;
        prev = t;
    }
    t = prev->prox;
    prev->prox = NULL;
    return t;
}

// 4

int tamLinha(Palavras p, int* numP) {
    int len = 0;
    (*numP) = 0;
    while(p) {
        len += p->comp;
        if(p->prox) len++;
        (*numP)++;
        p = p->prox;
    }
    return len;
}

void escreveLinha (Palavras p, int n) {
    int numP;
    int len = tamLinha(p,&numP);
    if(numP == 1) printf("%s\n",p->palavra);
    else {
        int espacos = n - len;
        while(p) {
            for(int i = 0; i < p->comp; i++) putchar(p->palavra[i]);
            numP--;
            if(p->prox) {
                putchar(' ');
                for(;(espacos/numP) > 0; espacos--) putchar(' ');
            }
            p = p->prox;
        }
    }
    printf("\n");
}

// 5

void formata (char texto[], int largura) {
    Palavras pals = words(texto);
    Palavras resto;
    while(resto = daLinha(pals,largura)){
        escreveLinha(pals, largura);
        pals = resto;
    }
    escreveLinha(pals,largura);
}

int main() {
    char line[500];
    printf("Frase: ");
    getLine(line,500);
    formata(line,30);
    return 0;
}