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
    LInt new = malloc(sizeof(struct lligada));
    if(b == NULL || a != NULL && a->valor < b->valor) {
        new->valor = a->valor;
        merge(&(new->prox),a->prox,b);
    }
    else {
        new->valor = b->valor;
        merge(&(new->prox),a,b->prox);
    }
    (*r) = new;
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

// Parte 2

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

// 28

int altura(ABin tree) {
    if(tree == NULL) return 0;
    return 1 + (altura(tree->esq) > altura(tree->dir) ? altura(tree->esq) : altura(tree->dir));
}

// 29

ABin cloneAB(ABin tree) {
    if(tree == NULL) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = tree->valor;
    new->esq = cloneAB(tree->esq);
    new->dir = cloneAB(tree->dir);
    return new;
}

// 30

void mirror(ABin * tree) {
    if((*tree)) {
        ABin temp = (*tree)->esq;
        (*tree)->esq = (*tree)->dir;
        (*tree)->dir = temp;
        mirror(&((*tree)->esq));
        mirror(&((*tree)->dir));
    }
}

// 31

void inorder (ABin tree, LInt * list) {
    if(!(tree)) (*list) = NULL;
    else {
        LInt new = malloc(sizeof(struct lligada));
        if(tree->esq) inorder(tree->esq,list);
        new->valor = tree->valor;
        new->prox = NULL;
        if(!(*list)) (*list) = new;
        else {
            LInt temp = (*list);
            while(temp->prox) temp = temp->prox;
            temp->prox = new;
        }
        if(tree->dir) inorder(tree->dir,list);
    }
}

// 32

void preorderaux(ABin a, LInt *l) {
    LInt aux;
    if(a) {
        preorderaux(a->dir,l);
        preorderaux(a->esq,l);

        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
    }
}

void preorder(ABin a, LInt *l){
    *l = NULL;
    preorderaux(a,l);
}

// 33

void posorderaux(ABin tree, LInt * list) {
    if(tree) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = tree->valor;
        new->prox = NULL;
        (*list) = new;
        posorder(tree->dir,list);
        posorder(tree->esq,list);
    }
}

void posorder(ABin tree, LInt * list) {
    *list = NULL;
    posorderaux(tree,list);
}

// 34

int depth_Aux(ABin a, int x, int d) {
    if(!a) return -1;
    if(a->valor == x) return d;
    int esq = depth_Aux(a->esq,x,d+1);
    int dir = depth_Aux(a->dir,x,d+1);
    if(esq <= dir && esq > 0 || dir < 0) return esq;
    else return dir;
    return -1;
}

int depth (ABin a, int x) {
    return depth_Aux(a,x,1);
}

// 35

int freeAB (ABin a) {
    if(!a) return 0;
    int n = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return n;
}

// 36

int pruneAB (ABin *a, int l) {
    int n;
    if(!(*a)) return 0;
    
    if(l == 0) {
        n = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL;
    }
    else n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1);
    
    return n;
}

// 37

int iguaisAB (ABin a, ABin b) {
    if(!a && b || !b && a) return 0;
    if(!a && !b || a == b) return 1;
    return a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
}

// 38

LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}
 
LInt nivelL (ABin a, int n) {
    if(!a || n < 1) return NULL;
    if(n == 1) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
} 

// 39

int nivelV (ABin a, int n, int v[]) {
    if(!a || n < 1) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq,n - 1,v);
        int d = nivelV(a->dir,n - 1,v+e);
        return e + d;
    }
}

// 40

int dumpAbin (ABin a, int v[], int N) {
    int e, d;
    if(a && N) {
        e = dumpAbin(a->esq,v,N);
        if(e < N) {
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else return N;
    }
    else return 0;
}

// 41

ABin somasAcA (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);
    return new;
}

// 42

int max(int a, int b) {return a > b ? a : b; }

int contaFolhas (ABin a) {
    if(!a) return 0;
    return max((a->esq ? contaFolhas(a->esq) : 0) + (a->dir ? contaFolhas(a->dir) : 0),1);
}

// 43

ABin cloneMirror (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);
    return new;
}

// 44

int addOrd (ABin *a, int x) {
    if(!(*a)) {
        ABin new = malloc(sizeof(struct nodo));
        new->valor = x;
        new->esq = new->dir = NULL;
        (*a) = new;
        return 0;
    }
    if((*a)->valor == x) return 1;
    if((*a)->valor > x) return addOrd(&((*a)->esq),x);
    return addOrd(&((*a)->dir),x);
}

// 45

int lookupAB (ABin a, int x) {
    if(!a) return 0;
    return a->valor == x || lookupAB((a->valor > x ? a->esq : a->dir),x);
}

// 46

int depthOrd (ABin a, int x) {
    if(!a) return -1;
    if(a->valor == x) return 1;
    int d = depthOrd((a->valor < x ? a->dir : a->esq),x);
    return d == -1 ? d : 1 + d;
}

// 47

int maiorAB (ABin a) {
    if(a->dir) return maiorAB(a->dir);
    return a->valor; 
}

// 48

void removeMaiorA (ABin *a) {
    if(!(*a)->dir) {
        ABin temp = (*a);
        free(*a);
        (*a) = temp->esq ? temp->esq : NULL;
    }
    else removeMaiorA(&((*a)->dir));
}

// 49

int quantosMaiores (ABin a, int x) {
    if(!a) return 0;
    if(a->valor <= x) return quantosMaiores(a->dir,x);
    else return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}

// 50

void listToBTree (LInt l, ABin *a) {
    if(!l) return;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = l->valor;
    new->esq = new->dir = NULL;
    listToBTree(l->prox,&(new->dir));
    (*a) = new;
}

// 51

int deProcuraAux(ABin a, int x, int maior) {
    if(!a) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq,x,maior) && deProcuraAux(a->dir,x,maior);
}

int deProcura (ABin a) {
    if(!a) return 1;
    int b = deProcuraAux(a->esq,a->valor, 0) && deProcura(a->esq);
    int c = deProcuraAux(a->dir,a->valor, 1) && deProcura(a->dir);
    return b && c;
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

ABin getBTree() {
    ABin new = malloc(sizeof(struct nodo));
    int num;
    printf("Valor central: ");
    scanf("%d",&num);
    new->valor = num;
    printf("(%d) Valor à esquerda? (0 - não ; 1 - sim) ", new->valor);
    scanf("%d",&num);
    if(num) new->esq = getBTree();
    else new->esq = NULL;
    printf("(%d) Valor à direita? (0 - não ; 1 - sim) ", new->valor);
    scanf("%d",&num);
    if(num) new->dir = getBTree();
    else new->dir = NULL;
    return new;
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
        case 31: {
            ABin tree = getBTree();
            list1 = NULL;
            inorder(tree,&list1);
            printLInt(list1);
            break; }
        case 32: {
            ABin tree = getBTree();
            list1 = NULL;
            preorder(tree,&list1);
            printLInt(list1);
            break; }
    }
    printf("\n");
    return 0;
}
