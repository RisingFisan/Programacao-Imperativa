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
    if(!(*l)) return 0;
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
    int rem = 0;
    LInt list = (*l);
    while(list) {
        LInt copy = list->prox;
        LInt copyPrev = list;
        while(copy) {
            if(copy->valor == list->valor) {
                rem++;
                copyPrev->prox = copy->prox;
                copy = copy->prox;
                continue;
            }
            copyPrev = copy;
            copy = copy->prox;
        }
        list = list->prox;
    }
    return rem;
}

// 12

int removeMaiorL(LInt *l) {
    LInt list = (*l)->prox;
    LInt prev = (*l);
    int max = (*l)->valor;
    LInt maxL = prev, maxPrev = NULL;
    while(list) {
        if(list->valor > max) {
            max = list->valor;
            maxL = list;
            maxPrev = prev;
        }
        prev = list;
        list = list->prox;
    }
    if(max == (*l)->valor)
        (*l) = maxL->prox;
    else
        maxPrev->prox = maxL->prox;
    return max;
}

// 13

void init (LInt *l) {
    if((*l)->prox == NULL) {
        LInt temp = (*l);
        free(temp);
        (*l) = NULL;
    } 
    else {
        LInt list = (*l)->prox;
        LInt prev = (*l);
        while(list->prox) {
            prev = list;
            list = list->prox;
        }
        free(list);
        prev->prox = NULL;
    }
}

// 14

void appendL (LInt *l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if((*l) == NULL) (*l) = new;
    else {
        LInt list = (*l);
        while(list->prox) list = list->prox;
        list->prox = new;
    }
}

// 15

void concatL (LInt *a, LInt b) {
    if(!(*a)) (*a) = b;
    else {
        LInt list = (*a);
        while(list->prox) list = list->prox;
        list->prox = b;
    }
}

// 16

LInt cloneL (LInt l) {
    LInt list = NULL, temp = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = NULL;
        if(list == NULL) list = temp = new;
        else temp = temp->prox = new;
        l = l->prox;
    }
    return list;
}

// 17

LInt cloneRev (LInt l) {
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
} 

// 18

int maximo (LInt l) {
    int max = l->valor;
    l = l->prox;
    while(l) {
        if(l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}

// 19

int take (int n, LInt *l) {
    int i = 0;
    LInt prev = NULL;
    LInt list = (*l);
    while(i < n && list) {
        prev = list;
        list = list->prox;
        i++;
    }
    if(n == 0) (*l) = NULL;
    if(i == n && list) {
        if(prev) prev->prox = NULL;
        while(list) {
            LInt temp = list;
            list = list->prox;
            free(temp);
        }
    }
    return i;
}

// 20

int drop (int n, LInt *l) {
    int i = 0;
    while(i < n && (*l)) {
        LInt temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
        i++;
    }
    return i;
}

// 21

LInt Nforward (LInt l, int N) {
    for(int i = 0; i < N; i++) {
        l = l->prox;
    }
    return l;
}

// 22

int listToArray (LInt l, int v[], int N) {
    int i = 0;
    while(i < N && l) {
        v[i++] = l->valor;
        l = l->prox;
    }
    return i;
}

// 23

LInt arrayToList (int v[], int N) {
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = (*v);
    new->prox = arrayToList(v + 1, N - 1);
    return new;
}

// 24

LInt somasAcL (LInt l) {
    int sum = 0;
    LInt list = NULL, temp = NULL;
    while(l) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        if(!list) list = temp = new;
        else temp = temp->prox = new;
        l = l->prox;
    }
    return list;
}

// 25

void remreps(LInt l) {
    if(l) {
        while(l->prox) {
            if(l->prox->valor == l->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}

// 26

LInt rotateL (LInt l) {
    if(!l || !(l->prox)) return l;
    LInt temp = l;
    LInt list = l->prox;
    while(temp->prox) temp = temp->prox; 
    temp->prox = l;
    l->prox = NULL;
    return list;
}

// 27

LInt parte (LInt l) {
    LInt list = NULL, temp = NULL;
    while(l && l->prox) {
        if(!list) list = temp = l->prox;
        else temp = temp->prox = l->prox;
        l = l->prox = l->prox->prox;
        temp->prox = NULL;
    }
    return list;
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

LInt getLIntCirc(int len) {
    LInt list = NULL;
    LInt prev = NULL;
    for(int i = 0; i < len; i++) {
        LInt new = malloc(sizeof(struct lligada));
        if(!list) list = new;
        if(prev) prev->prox = new;
        printf("Insere um valor: ");
        int num;
        scanf("%d",&num);
        new->valor = num;
        prev = new;
    }
    prev->prox = list;
    return list;
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
            resp = removeAll(&list1,num);
            printLInt(list1);
            printf("%d elementos removidos.\n",resp);
            break;
        case 11:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            resp = removeDups(&list1);
            printLInt(list1);
            printf("%d elementos removidos.\n",resp);
            break;
        case 12:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            resp = removeMaiorL(&list1);
            printLInt(list1);
            printf("Maior elemento: %d\n",resp);
            break;
        case 13:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            init(&list1);
            printLInt(list1);
            break;
        case 14:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            printf("Elemento a inserir: ");
            scanf("%d",&num);
            appendL(&list1,num);
            printLInt(list1);
            break;
        case 15:
            printf("Comprimento da lista 1: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printf("Comprimento da lista 2: ");
            scanf("%d",&len);
            list2 = getLInt(len);
            printLInt(list1);
            printLInt(list2);
            concatL(&list1,list2);
            printLInt(list1);
            break;
        case 16:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            printf("Endereço: %d\n", list1);
            list2 = cloneL(list1);
            printLInt(list2);
            printf("Endereço: %d\n", list2);
            break;
        case 17:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            printf("Endereço: %d\n", list1);
            list2 = cloneRev(list1);
            printLInt(list2);
            printf("Endereço: %d\n", list2);
            break;
        case 18:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            resp = maximo(list1);
            printf("Máximo: %d", resp);
            break;
        case 19:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            printf("Numero de elementos a manter: ");
            scanf("%d",&num);
            resp = take(num,&list1);
            printLInt(list1);
            printf("Comprimento final da lista: %d", resp);
            break;
        case 21:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLIntCirc(len);
            printf("Numero de elementos a avancar: ");
            scanf("%d",&num);
            list2 = Nforward(list1, num);
            printf("Elemento inicial: %d\nElemento %d posições à frente: %d\n", list1->valor, num, list2->valor);
            break;
        case 25:
            printf("Comprimento da lista ordenada: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            remreps(list1);
            printLInt(list1);
            break;
        case 26:
            printf("Comprimento da lista ordenada: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            list2 = rotateL(list1);
            printLInt(list2);
            break;
        case 27:
            printf("Comprimento da lista: ");
            scanf("%d",&len);
            list1 = getLInt(len);
            printLInt(list1);
            list2 = parte(list1);
            printLInt(list1);
            printLInt(list2);
            break;
    }
    printf("\n");
    return 0;
}
