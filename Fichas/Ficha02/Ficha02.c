#include <stdio.h>

// Exercicio 1

float multInt(int n, float m) {
    float r = 0;
    for(int i = 0; i < n; i++) r += m;
    return r;
}


// Forma (recursiva) mais simples de fazer a mesma função: 

// float multInt (int n, float m) {
//     if (n == 1) return m;
//     else return (m + multInt(n - 1,m));
// }

// Exercicio 2

float multInt2 (int n, float m) {
    float r = 0;
    while(n > 0) {
        m *= 2;
        if((n /= 2) % 2) r += m; 
    }
    return r;
}

// Exercicio 3

int mdc (int a, int b) {
    int temp, ans;
    if(a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    for(int i = 1; i <= b; i++) {
        if(a % i == 0 && b % i == 0) ans = i;
    }
    return ans;
}

// Exercicio 4

int mdc2 (int a, int b) {
    while(a != 0 && b != 0) {
        if(a > b) a -= b;
        else if (b > a) b -= a;
        else return a;
    }
    if(a == 0) return b;
    else return a;
}

// Exercicio 5

int mdc3 (int a, int b) {
    while(a != 0 && b != 0) {
        if(a > b) a %= b;
        else if (b > a) b %= a;
        else return a;
    }
    if(a == 0) return b;
    else return a;
}

// Exercicio 6

int fib (int n) {
    if(n == 1 || n == 2) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int fib2(int n) {
    int temp, acc1 = 1, acc2 = 1;
    for(int i = 3; i <= n; i++) {
        temp = acc2;
        acc2 += acc1;
        acc1 = temp;
    }
    return acc2;
}

int main(int argc, char const *argv[]) {
    int opt, num1, num2;
    float fl1;
    printf("Introduza o número da pergunta: ");
    scanf("%d\n",&opt);
    switch(opt) {
        case 1:
            scanf("%d %f",&num1,&fl1);
            float ans = multInt(num1, fl1);
            printf("Resposta: %f", ans);
            break;
        case 2:
            scanf("%d %f",&num1,&fl1);
            ans = multInt(num1, fl1);
            printf("Resposta: %f", ans);
            break;
        case 3:
            scanf("%d %d",&num1,&num2);
            printf("Resposta: %d", mdc(num1, num2));
            break;
        case 4:
            scanf("%d %d",&num1,&num2);
            printf("Resposta: %d", mdc2(num1, num2));
            break;
        case 5:
            scanf("%d %d",&num1,&num2);
            printf("Resposta: %d", mdc3(num1, num2));
            break;
        case 6:
            scanf("%d",&num1);
            printf("Resposta: %d", fib(num1));
            break;
        case 7:
            scanf("%d",&num1);
            printf("Resposta: %d", fib2(num1));
            break;
        default:
            break;
    }
    return 0;
}
