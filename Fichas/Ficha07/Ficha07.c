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

// Exercicio 2

// a)

typedef struct Aluno{
    char nome[60];
    int numero;
    double nota;
} Aluno;

typedef struct Turma{
    Aluno aluno;
    struct Turma* resto;
} Turma;

// b)

int acrescentaAluno (Turma *t, Aluno a) {
    Turma* new = malloc(sizeof(struct Turma));
    new->aluno = a;
    new->resto = NULL;
    if(t == NULL) t = new;
    else {
        Turma* temp = t;
        while(temp->resto != NULL) {
            temp = temp->resto;
        }
        temp->resto = new;
    }
    return 0;
}

// c)

Aluno *procura (Turma t, int numero) {
    Turma* atual = &t;
    while(atual) {
        if(atual->aluno.numero == numero) {
            return &(atual->aluno);
        }
        atual = atual->resto;
    }
    return NULL;
}

void printTurma(Turma* t) {
    while(t) {
        printf("Nome: %s - num: %d - nota: %lf\n",t->aluno.nome, t->aluno.numero, t->aluno.nota);
        t = t->resto;
    }
}

int main() {
    int num;
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
    else if(numP == '2') {
        printf("Alínea: ");
        numP = getchar();
        while(getchar() != '\n');
        Turma* t = malloc(sizeof(struct Turma));
        t->aluno = (Aluno){"Sara",12,8};
        t->resto = NULL;
        if(numP == 'b' || numP == 'B') {
            Aluno a1 = {"Sofia",89615,20.0};
            acrescentaAluno(t,a1);
            acrescentaAluno(t,(Aluno){"Filipa",69,16.0});
            acrescentaAluno(t,(Aluno){"Santejo",420,15.5});
            printTurma(t);
        }
        if(numP == 'c' || numP == 'C') {
            Aluno a1 = {"Sofia",89615,20.0};
            acrescentaAluno(t,a1);
            acrescentaAluno(t,(Aluno){"Filipa",69,16.0});
            acrescentaAluno(t,(Aluno){"Santejo",420,15.5});
            printf("Número a procurar: ");
            scanf("%d",&num);
            Aluno ax = *procura(*t,num);
            Turma tx = {ax,NULL};
            printTurma(&tx);
        }
    }
    return 0;
}