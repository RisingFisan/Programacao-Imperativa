#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"

// Apenas uso estas funções para testar as que fiz nos testes, assim não tenho que as definir várias vezes.

void getLine(char str[], int lim) {
    char c;
    int i = 0;
    while((c = getchar()) != '\n' && i < lim) str[i++] = c;
    str[i] = '\0';
}

void getIntArray(int arr[], int lim) {
    for(int i = 0; i < lim; i++) {
        printf("Insere um valor: ");
        scanf("%d", arr + i);
    }
}

void printArray(int arr[], int lim) {
    printf("[");
    for(int i = 0; i < lim; i++) {
        if(i == lim - 1) printf("%d",arr[i]);
        else printf("%d, ",arr[i]);
    }
    printf("]\n");
}

void getIntMatrix(int m, int n, int mat[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Linha %d, coluna %d: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

void printIntMatrix(int m, int n, int mat[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            printf("%6d ",mat[i][j]);
        putchar('\n');
    }
}

LInt getLInt(int len) {
    if(len == 0) return NULL;
    LInt new = malloc(sizeof(struct slist));
    printf("Insere um valor: ");
    int num;
    scanf("%d",&num);
    new->valor = num;
    new->prox = getLInt(len - 1);
    return new;
}

void printLInt(LInt l) {
    if(l == NULL) printf("NULL\n");
    else {
        printf("%d->",l->valor);
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

void printBTreeUtil(ABin root, int space) { 
    if (root == NULL) return; 
  
    space += 3; 
  
    printBTreeUtil(root->dir, space); 

    int i;
    for (i = 3; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->valor); 
  
    printBTreeUtil(root->esq, space); 
} 
  
void printBTree(ABin root) { 
   printBTreeUtil(root, 0); 
} 