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
    LInt list1;
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
    }
    printf("\n");
    return 0;
}
