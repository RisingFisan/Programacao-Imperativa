#include <stdio.h>
#include <stdlib.h>

// Exercicio 1

typedef struct stack {
    int size;
    int sp;
    int* valores;
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
    s->size = 1;
    s->valores = (int*)malloc(sizeof(int));
}

// b)

int isEmptyS (STACK *s) {
    return s->sp == 0;
}

// c)

int push (STACK *s, int x) {
    if(s->size <= s->sp) {
        s->valores = (int*)realloc(s->valores, 2 * s->size * sizeof(int));
        s->size *= 2;
    }
    int N = s->sp++;
    s->valores[N] = x;
    return 0;
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
    int size;
    int inicio, tamanho;
    int* valores;
} QUEUE;

void printQueue(QUEUE *q) {
    printf("[");
    for(int i = 0; i < q->tamanho; i++) printf("%d%s",q->valores[q->inicio + i],i == q->tamanho - 1 ? "" : ", ");
    printf("] %d - start index\n",q->inicio);
}

// a)

void initQueue (QUEUE *q) {
    q->tamanho = 0;
    q->size = q->inicio;
    q->valores = malloc(q->inicio * sizeof(int));
}

// b)

int isEmptyQ (QUEUE* q) {
    return q->tamanho == 0;
}

// c)

int enqueue (QUEUE* q, int x) {
    if(q->size <= q->inicio + q->tamanho) {
        q->valores = realloc(q->valores,2 * q->size * sizeof(int));
        q->size *= 2;
    }
    q->valores[q->inicio + q->tamanho++] = x;
    return 0;
}

// d)

int dequeue (QUEUE* q, int* x) {
    if(q->tamanho == 0) return 1;
    else {
        *x = q->valores[q->inicio + --(q->tamanho)];
        return 0;
    }    
}

// e)

int front (QUEUE* q, int* x) {
    if(q->tamanho == 0) return 1;
    else {
        *x = q->valores[q->inicio];
        return 0;
    }
}

int main() {
    char numQ, chrA;
    int num;
    int SZ = 10;
    STACK stack1;
    stack1.size = stack1.sp = SZ;
    stack1.valores = (int*)malloc(SZ * sizeof(int));
    for(int i = 0; i < SZ; i++) stack1.valores[i] = i + 1;
    QUEUE queue1;
    queue1.tamanho = SZ;
    queue1.inicio = 2;
    queue1.size = 2 + SZ;
    queue1.valores = malloc(2 + SZ * sizeof(int));
    for(int i = 0; i < SZ; i++) queue1.valores[2+i] = i + 1;    
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
                    push(&stack1,11);
                    printStack(&stack1);
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
            printf("Letra da alinea: ");
            chrA = getchar();
            while(getchar() != '\n');
            switch(chrA) {
                case 'a':
                case 'A':
                    initQueue(&queue1);
                    printQueue(&queue1);
                    break;
                case 'b':
                case 'B':
                    printQueue(&queue1);
                    printf("%s\n",isEmptyQ(&queue1) ? "True" : "False");
                    initQueue(&queue1);
                    printQueue(&queue1);
                    printf("%s\n",isEmptyQ(&queue1) ? "True" : "False");
                    break;
                case 'c':
                case 'C':
                    printQueue(&queue1);
                    enqueue(&queue1,11);
                    printQueue(&queue1);
                    break;
                case 'd':
                case 'D':
                    printQueue(&queue1);
                    if(dequeue(&queue1,&num)) printf("ERRO - QUEUE VAZIA\n");
                    else {printQueue(&queue1); printf("Valor retirado: %d\n",num);}
                    break;
                case 'e':
                case 'E':
                    if(front(&queue1,&num)) printf("ERRO - QUEUE VAZIA");
                    else {printQueue(&queue1); printf("Valor no topo da queue: %d\n",num);}
                    break;
            }
            break;
    }
    return 0;
}