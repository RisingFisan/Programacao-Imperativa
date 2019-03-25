#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Exercicio 1

typedef struct stack {
    int sp;
    int valores [MAX];
} STACK;

void printStack(STACK* s) {
    printf("SP = %d\n",s->sp);
    printf("[");
    for(int i = 0; i < s->sp; i++) printf("%d%s", s->valores[i], i == s->sp - 1 ? "" : ", ");
    printf("]\n");
}

// a)

void initStack (STACK *s) {
    s->sp = 0;
}

// b)

int isEmptyS (STACK *s) {
    return s->sp == 0;
}

// c)

int push (STACK *s, int x) {
    int N = s->sp++;
    if(N == MAX) return 1;
    else {
        s->valores[N] = x;
        return 0;
    }
}

// d)

int pop (STACK *s, int *x) {
    int N = --(s->sp);
    if(N == 0) return 1;
    else *x = s->valores[N];
    return 0;
}

// e)

int top (STACK *s, int *x) {
    int N = s->sp;
    if(N == 0) return 1;
    else *x = s->valores[N-1];
    return 0;
}

// Exercicio 2

typedef struct queue {
    int inicio, tamanho;
    int valores [MAX];
} QUEUE;

// a)

void initQueue (QUEUE *q) {
    q->tamanho = 0;
}

// b)



int main() {
    char numQ, chrA;
    int num;
    STACK stack1 = {3,{1,2,3}};
    printf("Número do exercicio: ");
    numQ = getchar();
    while(getchar() != '\n');
    switch(numQ) {
        case '1':
            printf("Letra da alinea: ");
            chrA = getchar();
            while(getchar() != '\n');
            switch(chrA) {
                case 'a':
                case 'A':
                    initStack(&stack1);
                    printStack(&stack1);
                    break;
                case 'b':
                case 'B':
                    printStack(&stack1);
                    printf("%s\n",isEmptyS(&stack1) ? "True" : "False");
                    initStack(&stack1);
                    printStack(&stack1);
                    printf("%s\n",isEmptyS(&stack1) ? "True" : "False");
                    break;
                case 'c':
                case 'C':
                    printStack(&stack1);
                    if(push(&stack1,4)) printf("ERRO - STACK CHEIA\n");
                    else printStack(&stack1);
                    break;
                case 'd':
                case 'D':
                    printStack(&stack1);
                    if(pop(&stack1,&num)) printf("ERRO - STACK VAZIA\n");
                    else {printStack(&stack1); printf("Valor retirado: %d\n",num);}
                    break;
                case 'e':
                case 'E':
                    if(top(&stack1,&num)) printf("ERRO - STACK VAZIA");
                    else {printStack(&stack1); printf("Valor no topo da stack: %d\n",num);}
                    break;
            }
            break;
        case '2':


    }
    return 0;
}

