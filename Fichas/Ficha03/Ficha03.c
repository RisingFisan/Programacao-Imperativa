#include <stdio.h>
#include <stdlib.h>

// Exercicio 1
/* 
a) 
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12

b) 13
*/

// Exercicio 2

void swapM (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Exercicio 3

void swap (int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Exercicio 4

int soma (int v[], int N) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += v[i];
    }
    return sum;
}

// Exercicio 5

int maximum (int v[], int N, int *m) {
    if(N < 1) return 1;
    else {
        *m = v[0];
        for(int i = 0; i < N; i++) {
            if(v[i] > *m) {
                *m = v[i];
            }
        }
        return 0;
    }
}

// Exercicio 6

void quadrados (int q[], int N) {
    for(int i = 0; i < N; i++) {
        q[i] = (i+1)*(i+1);
    }
}

// Exercicio 7

void pascal (int v[], int N) {
    if(N == 1) v[0] = 1;
    else {
        int prevLine[N - 1];
        pascal(prevLine,N-1);
        v[0] = 1;
        v[N - 1] = 1;
        for(int i = 1; i < N - 1; i++) {
            v[i] = prevLine[i - 1] + prevLine[i];
        }
    }
}

void createArray();
void printArray();

int main() {
    char c;
    char buffer[100];
    int num1, num2, len, ans;
    printf("Introduz o número da pergunta: ");
    char opt = getchar();
    fflush(stdin);
    switch (opt) {
        case '2':
            printf("Introduz dois números: ");
            scanf("%d %d",&num1,&num2);
            swapM(&num1,&num2);
            printf("Trocados: %d %d",num1,num2);
            break;
        case '3': {
            printf("Tamanho do vetor: ");
            scanf("%d",&len);
            int nums[len];
            createArray(nums,len);
            printf("Índices dos valores a trocar: ");
            scanf("%d %d",&num1,&num2);
            swap(nums,num1,num2);
            printArray(nums,len);
            break; }
        case '4': {
            printf("Tamanho do vetor: ");
            scanf("%d",&len);
            int nums[len];
            createArray(nums,len);
            ans = soma(nums,len);
            printArray(nums,len);
            printf("Soma = %d",ans);
            break; }
        case '5': {
            printf("Tamanho do vetor: ");
            scanf("%d",&len);
            int nums[len];
            createArray(nums,len);
            int max;
            ans = maximum(nums,len,&max);
            printArray(nums,len);
            if(ans) printf("ERRO");
            else printf("Valor máximo = %d",max);
            break; }
        case '6': {
            printf("Limite: ");
            scanf("%d",&len);
            int nums[len];
            quadrados(nums,len);
            printf("Quadrados dos %d primeiros números naturais:\n", len);
            printArray(nums,len);
            break; }
        case '7': {
            printf("Linha do triângulo de Pascal: ");
            scanf("%d",&len);
            int nums[len];
            pascal(nums,len);
            printArray(nums,len);
            break; }
        default:
            putchar('X');
            break;
    }
    return 0;
}

void createArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        printf("Introduz um valor: ");
        scanf("%d", arr + i);
    }
}

void printArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    putchar('\n');
}