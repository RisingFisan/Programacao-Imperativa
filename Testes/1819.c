#include <stdio.h>
#include <stdlib.h>

// Parte B

typedef struct digito {
    unsigned char val;
    struct digito *prox;
} *Num;

Num fromInt(unsigned int i) {
    int digit = i % 10;
    int rest = i / 10;
    Num num = malloc(sizeof(struct digito));
    num->val = digit + '0';
    num->prox = rest > 0 ? fromInt(rest) : NULL;
    return num;
}

unsigned int toInt(Num n) {
    int digit = n->val - '0';
    if(n->prox) return digit + 10 * toInt(n->prox);
    else return digit;
}

Num addNum(Num a, Num b) {
    if(!a) return b;
    if(!b) return a;
    int result = (a->val - '0') + (b->val - '0');
    int rest = result / 10;
    Num num = malloc(sizeof(struct digito));
    num->val = result - (rest * 10) + '0';
    Num new_a = rest == 0 ? a->prox : addNum(a->prox, fromInt(rest));
    num->prox = addNum(new_a, b->prox);
    return num;
}

Num mulDig(unsigned char dig, Num a) {
    if(dig == '0' || !a) {
        Num num = malloc(sizeof(num));
        num->val = '0';
        num->prox = NULL;
        return num;
    }
    if(dig == 1) return a;
    return addNum(a, mulDig(dig - 1, a));
}

Num mulNum(Num a, Num b) {
    if(!a || !b) return NULL;
    Num aux = malloc(sizeof(struct digito));
    aux->val = '0';
    aux->prox = mulNum(a, b->prox);
    return addNum(mulDig(b->val, a), aux);
}





void printNum(Num num) {
    putchar(num->val);
    if(num->prox != NULL) {
        printf(" -> ");
        printNum(num->prox);
    }
    else puts("");
}

int main(int argc, char const *argv[]) {
    int num = atoi(argv[1]);
    Num numN = fromInt(num);
    printNum(numN);
    printf("%d\n", toInt(numN));
    if(argc > 2) {
        puts("\n");
        int num2 = atoi(argv[2]);
        Num numN2 = fromInt(num2);
        printNum(numN);
        puts("+");
        printNum(numN2);
        puts("=");
        printNum(addNum(numN, numN2));

        if(num < 10) {

            puts("\n");

            printf("%d\n", num);
            puts("*");
            printNum(numN2);
            puts("=");
            printNum(mulDig(num, numN2));

        }
        else {

            puts("\n");

            printNum(numN);
            puts("*");
            printNum(numN2);
            puts("=");
            printNum(mulNum(numN, numN2));
        }
    }
    return 0;
}
