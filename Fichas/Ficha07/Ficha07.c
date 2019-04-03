#include <stdio.h>
#include <stdlib.h>

// Exercicio 1

typedef struct slist *LInt;

typedef struct slist
{
    int valor;
    LInt prox;
} Nodo;

// b)

// i.

LInt cons (LInt l, int x) {
    LInt new = malloc(sizeof(Nodo));
    new->valor = x;
    new->prox = l;
    return new;
}

// ii.

LInt tail (LInt l) {
    LInt x = l == NULL ? NULL : l->prox;
    free(l);
    return x;
}

// iii.

LInt init(LInt l) {
    if (l == NULL || l->prox == NULL)
        return NULL;
    LInt nextToEnd = l;
    LInt end = l->prox;
    while(end->prox != NULL) {
        nextToEnd = end;
        end = end->prox;
    }
    free(end);
    nextToEnd->prox = NULL;
    return l;
}

// iv.

LInt snoc (LInt l, int x) {
    LInt end = l;
    while(end->prox != NULL) {
        end = end->prox;
    }
    LInt new = malloc(sizeof(Nodo));
    new->valor = x;
    new->prox = NULL;
    end->prox = new;
    return l;
}

// v.

LInt concat (LInt a, LInt b) {
    LInt endA = a;
    while(endA->prox != NULL) endA = endA->prox;
    endA->prox = b;
    return a;
}

LInt reverse(LInt l) {
    LInt new = malloc(sizeof(Nodo));
    new->valor = l->valor;
    LInt end = l->prox;
    while(end != NULL) {
        new = cons(new,end->valor);
        end = end->prox;
    }
    return new;
}

LInt scanLInt(int N) {
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(Nodo));
    int num;
    printf("Insere um elemento: ");
    scanf("%d",&num);
    new->valor = num;
    new->prox = scanLInt(N - 1);
    return new;
}

void printLInt(LInt l) {
    printf("[");
    LInt x = l;
    while(x != NULL) {
        printf("%d%s",x->valor,x->prox == NULL ? "" : ", ");
        x = x->prox;
    }
    printf("]\n");
}

int main() {
    printf("Número do exercicio: ");
    char numP = getchar();
    while(getchar() != '\n');
    if(numP == '1') {
        printf("Alínea: ");
        numP = getchar();
        while(getchar() != '\n');
        LInt a = malloc(sizeof(Nodo));
        a->valor = 10;
        a->prox = malloc(sizeof(Nodo));
        a->prox->valor = 5;
        a->prox->prox = malloc(sizeof(Nodo));
        a->prox->prox->valor = 15;
        a->prox->prox->prox = NULL;
        if(numP == 'a' || numP == 'A') {
            printLInt(a);
        }
        else if(numP == 'b' || numP == 'B') {
            int num;
            printf("Número da função: ");
            numP = getchar();
            while(getchar() != '\n');
            switch(numP) {
                case '1':
                    printf("Número a inserir: ");
                    scanf("%d",&num);
                    a = cons(a,num);
                    printLInt(a);
                    break;
                case '2':
                    a = tail(a);
                    printLInt(a);
                    break;
                case '3':
                    a = init(a);
                    printLInt(a);
                    break;
                case '4':
                    printf("Número a inserir: ");
                    scanf("%d",&num);
                    a = snoc(a,num);
                    printLInt(a);
                    break;
                case '5': {
                    LInt b = scanLInt(3);
                    a = concat(a,b);
                    printLInt(a);
                    a = reverse(a);
                    printLInt(a);
                    break; }
            }
        }

    }    
    return 0;
}