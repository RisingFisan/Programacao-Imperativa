#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// 1

int length(LInt l) {
    if(l == NULL) return 0;
    else return (1 + length(l->prox));
}

// 2

void freeL(LInt l) {
    LInt temp;
    while(l != NULL) {
        temp = l;
        l = l->prox;
        free(temp);
        temp = NULL;
    }
}

// 3

void imprimeL(LInt l) {
    while(l != NULL) {
        printf("%d\n",l->valor);
        l = l->prox;
    }
}

// 4

LInt reverseL(LInt l) {
    LInt prox = l->prox;
    l->prox = NULL;
    while(prox) {
        LInt temp = prox->prox;
        prox->prox = l;
        l = prox;
        prox = temp;
    }
    return l;
}

// 5

void insertOrd (LInt* l, int x) {
    LInt list = *l;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(list->valor > x) {
        *l = new;
        new->prox = list;
    }
    else {
        while(list->prox) {
            LInt next = list->prox;
            if(next->valor > x) {
                list->prox = new;
                new->prox = next;
                break;
            }
            list = list->prox;
            next = next->prox;
        }
        list->prox = new;
    }
}

// 6

int removeOneOrd(LInt* l, int x) {
    if((*l)->valor == x) {
        (*l) = (*l)->prox;
        return 0;
    }
    LInt prev = (*l);
    while(prev->prox) {
        LInt list = prev->prox;
        if(list->valor == x) {
            prev->prox = list->prox;
            return 0;
        }
        prev = prev->prox;
    }
    return 1;
}

// 7

void merge(LInt* r, LInt a, LInt b) {
    LInt temp = NULL;
    while(a != NULL || b != NULL) {
        LInt new = malloc(sizeof(struct lligada));
        new->prox = NULL;
        if(b == NULL || a != NULL && a->valor < b->valor) {
            new->valor = a->valor;
            a = a->prox;
        }
        else {
            new->valor = b->valor;
            b = b->prox;
        }
        if(temp == NULL) {
            (*r) = new;
            temp = (*r);
        }
        else {
            temp->prox = new;
            temp = temp->prox;
        }
    }
}

// 8

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    (*mx) = (*Mx) = NULL;
    while(l) {
        LInt temp;
        LInt tempX = l->prox;
        l->prox = NULL;
        if(l->valor >= x) {
            if(!(*Mx)) (*Mx) = l;
            else {
                temp = (*Mx);
                while(temp->prox) temp = temp->prox;
                temp->prox = l;
            }
        }
        else {
            if(!(*mx)) (*mx) = l;
            else {
                temp = (*mx);
                while(temp->prox) temp = temp->prox;
                temp->prox = l;
            }
        }
        l = tempX;
    }
}

// 9

LInt parteAmeio(LInt *l) {
    int meio = length(*l) / 2;
    LInt new = malloc(sizeof(struct lligada));
    new = NULL;
    for(int i = 0; i < meio; i++) {
        LInt prox = (*l)->prox;
        (*l)->prox = NULL;
        if(!new) {
            new = (*l);
        }
        else {
            LInt temp = new;
            while(temp->prox) temp = temp->prox;
            temp->prox = (*l);
        }
        (*l) = prox;
    }
    return new;
}

// 10

int removeAll(LInt *l, int x) {
    int rem = 0;
    while((*l)->valor == x) {
        (*l) = (*l)->prox;
        rem++;
        if(!(*l)) return rem;
    }
    LInt prev = (*l);
    LInt next = prev->prox;
    while(next) {
        if(next->valor == x) {
            prev->prox = next->prox;
            next = prev->prox;
            rem++;
            continue;
        }
        prev = prev->prox;
        if(!prev) break;
        next = prev->prox;
    }
    return rem;
}

// 11

int removeDups(LInt *l) {

}

LInt getLInt(int len) {
    if(len == 0) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    printf("Insere um valor: ");
    int num;
    scanf("%d",&num);
    new->valor = num;
    new->prox = getLInt(len - 1);
    return new;
}

void printLInt(LInt l) {
    if(l == NULL) putchar('\n');
    else {
        printf("%d ",l->valor);
        printLInt(l->prox);
    }
}

int main(int argc, char const *argv[]) {
    LInt list1, list2;
    int opcao, len, num, num1, num2, resp, x, y;
    printf("Insere o numero correspondente ao exercicio: ");
    scanf("%d",&opcao);
    while(getchar() != '\n'); // Ao usar o scanf, o caracter '\n' permanece no buffer. Este while vê-se livre do '\n', para não estragar os getLine em baixo.
    switch (opcao) {
        case 1:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            num = length(list1);
            printf("Comprimento da lista: %d",num);
            break;
        case 2:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            printf("Comprimento da lista: %d\n",length(list1));
            freeL(list1);
            printLInt(list1);
            printf("Comprimento da lista: %d\n",length(list1));
            break;
        case 3:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            imprimeL(list1);
            break;
        case 4:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            list1 = reverseL(list1);
            printLInt(list1);
            break;
        case 5:
            printf("Comprimento da lista ordenada: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printf("Elemento a inserir: ");
            scanf("%d",&num);
            printLInt(list1);
            insertOrd(&list1,num);
            printLInt(list1);
            break;
        case 6:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printf("Elemento a remover: ");
            scanf("%d",&num);
            printLInt(list1);
            if(!removeOneOrd(&list1,num)) printLInt(list1);
            else printf("Elemento não encontrado!");
            break;
        case 7:
            printf("Comprimento da lista ordenada 1: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printf("Comprimento da lista ordenada 2: ");
            scanf("%d",&len);
            list2 = getLInt(len);
            LInt* merged = malloc(sizeof(struct lligada));
            merge(merged,list1,list2);
            printLInt(*merged);
            break;
        case 8:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printf("Valor para dividir: ");
            scanf("%d",&num);
            LInt *menores = malloc(sizeof(struct lligada));
            LInt *maiores = malloc(sizeof(struct lligada));
            splitQS(list1,num,menores,maiores);
            printf("Menores: ");
            printLInt(*menores);
            printf("Maiores: ");
            printLInt(*maiores);
            break;
        case 9:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            LInt metade = parteAmeio(&list1);
            printLInt(metade);
            printLInt(list1);
            break;
        case 10:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printf("Elemento a remover: ");
            scanf("%d",&num);
            printLInt(list1);
            removeAll(&list1,num);
            printLInt(list1);
            break;
    }
    printf("\n");
    return 0;
}
